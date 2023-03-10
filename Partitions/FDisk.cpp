#include <iostream>
#include <string.h>
#include "../Utils/Structures.h"
#include "../Utils/Functions.h"
#include "../Disks/DiskFunctions.h"
#include "../Partitions/FDisk.h"

FDisk::FDisk(std::string size, std::string unit, std::string path, std::string type, std::string fit,
             std::string varDelete, std::string name, std::string add) {
    this->size = size;
    this->unit = unit;
    this->path = path;
    this->type = type;
    this->fit = fit;
    this->varDelete = varDelete;
    this->name = name;
    this->add = add;
    executeFDisk();

}


void FDisk::executeFDisk() {
    if (path == "" || name == "")
        return coutError("Error: faltan parámetros obligatorios.", nullptr);

    completedPath = getPath(path);
    if (!isDir(completedPath))
        return coutError("Error: el disco no existe.", NULL);
    if (name.length() > 16)
        return coutError("El nombre de la partición no puede exceder a 16 caracteres.", NULL);

    _unit = getUnit(unit, 'k');
    if (add != "")
        return manageSpace();

    if (varDelete != "") {
        char ans;
        std::cout << "¿Desea eliminar la partición '" + name + "' ubicada en el disco: '" + completedPath + "?' [Y/n] ";
        std::cin >> ans;
        if (ans == 'Y' || ans == 'y')
            return erasePartition(charDelete(varDelete));
        else
            return;
    }

    // casting variables to their types
    _type = charType(type, 'P');
    _fit = getFit(fit, 'W');
    _size = (size != "") ? castSize(size) : castSize("-1");
    return createPartitions();
}


void FDisk::createPartitions() {
    FILE *pFile = fopen(completedPath.c_str(), "rb+");

    MBR mbr;
    fseek(pFile, 0, SEEK_SET);
    fread(&mbr, sizeof(MBR), 1, pFile);

    int tam = getSize(_unit, _size);
    int nstart = sizeof(MBR);
    if (_type == 'L') {
        return createLogic(mbr, tam, pFile);
    } else {
        if (_type == 'E' && existeExtendida(mbr) > -1)
            return coutError("No puede existir más de una partición extendida dentro del disco.", pFile);

        if (existeNombreMBR(mbr, name))
            return coutError("El nombre a asignar ya existe como partición.", pFile);

        int options[] = {-1, -1, -1, -1};


        nstart += mbr.mbr_partition_1.part_s;
        if (mbr.mbr_partition_1.part_status == '0') {
            if (validations(mbr, 0, nstart, tam)){
                if (mbr.mbr_partition_1.part_start != 0)
                    options[0] = mbr.mbr_partition_1.part_start - mbr.mbr_partition_1.part_start - _size;
                else
                    options[0] = 0;

            }
        }
        nstart += mbr.mbr_partition_2.part_s;
        if (mbr.mbr_partition_2.part_status == '0') {
            if (validations(mbr, 1, nstart, tam)){
                if (mbr.mbr_partition_2.part_start != 0)
                    options[1] = mbr.mbr_partition_2.part_start - mbr.mbr_partition_2.part_start - _size;
                else
                    options[1] = 0;

            }

        }
        nstart += mbr.mbr_partition_3.part_s;
        if (mbr.mbr_partition_3.part_status == '0') {
            if (validations(mbr, 2, nstart, tam)){
                if (mbr.mbr_partition_3.part_start != 0)
                    options[2] = mbr.mbr_partition_3.part_start - mbr.mbr_partition_3.part_start - _size;
                else
                    options[2] = 0;

            }
        }

        nstart += mbr.mbr_partition_4.part_s;
        if (mbr.mbr_partition_4.part_status == '0') {
            if (validations(mbr, 3, nstart, tam)){
                if (mbr.mbr_partition_4.part_start != 0)
                    options[3] = mbr.mbr_tamano - mbr.mbr_partition_4.part_start - _size;
                else
                    options[3] = 0;

                }
        }

        int i = getPartitionByFit(options);
        if (i == -1)
            return coutError("No se encontró ningún espacio apto para crear la partición.", pFile);
        //Modificiación del MBR
        if(i==0){
            mbr.mbr_partition_1.part_fit = _fit;
            strcpy(mbr.mbr_partition_1.part_name, name.c_str());
            mbr.mbr_partition_1.part_s = tam;
            mbr.mbr_partition_1.part_start = nstart;
            mbr.mbr_partition_1.part_status = '1';
            mbr.mbr_partition_1.part_type = _type;
        }else if(i==1){
            mbr.mbr_partition_2.part_fit = _fit;
            strcpy(mbr.mbr_partition_2.part_name, name.c_str());
            mbr.mbr_partition_2.part_s = tam;
            mbr.mbr_partition_2.part_start = nstart;
            mbr.mbr_partition_2.part_status = '1';
            mbr.mbr_partition_2.part_type = _type;
        }else if(i==2){
            mbr.mbr_partition_3.part_fit = _fit;
            strcpy(mbr.mbr_partition_3.part_name, name.c_str());
            mbr.mbr_partition_3.part_s = tam;
            mbr.mbr_partition_3.part_start = nstart;
            mbr.mbr_partition_3.part_status = '1';
            mbr.mbr_partition_3.part_type = _type;
        }else if(i==3){
            mbr.mbr_partition_4.part_fit = _fit;
            strcpy(mbr.mbr_partition_4.part_name, name.c_str());
            mbr.mbr_partition_4.part_s = tam;
            mbr.mbr_partition_4.part_start = nstart;
            mbr.mbr_partition_4.part_status = '1';
            mbr.mbr_partition_4.part_type = _type;
        }

        fseek(pFile, 0, SEEK_SET);
        fwrite(&mbr, sizeof(MBR), 1, pFile);

        if (_type == 'P') {
            createPrimary(nstart, pFile);
        } else if (_type == 'E') {
            createExtended(nstart, pFile);
        }
        fclose(pFile);
        pFile = NULL;
        return;
    }
}


void FDisk::createPrimary(int _nstart, FILE *_file) {
    Superbloque sb;
    fseek(_file, _nstart, SEEK_SET);
    fwrite(&sb, sizeof(Superbloque), 1, _file);
}

void FDisk::createExtended(int _nstart, FILE *_file) {
    EBR ebr;
    ebr.part_fit = _fit;
    strcpy(ebr.part_name, "");
    ebr.part_next = -1;
    ebr.part_s = 0;
    ebr.part_start = _nstart;
    ebr.part_status = '0';
    Superbloque sb;
    fseek(_file, _nstart, SEEK_SET);
    fwrite(&ebr, sizeof(EBR), 1, _file);
    fwrite(&sb, sizeof(Superbloque), 1, _file);
    // fwrite("\0", _size, 1, _file);
}

void FDisk::createLogic(MBR _mbr, int sizeByte, FILE *_file) {
    int index = existeExtendida(_mbr);
    if (index == -1)
        return coutError("No existe una partición extendida para crear la partición lógica.", _file);
    partition extendida={};
    if(index==0){
        extendida = _mbr.mbr_partition_1;
    }else if(index==1){
        extendida = _mbr.mbr_partition_2;
    }else if(index==2){
        extendida = _mbr.mbr_partition_3;
    }else if(index==3){
        extendida = _mbr.mbr_partition_4;
    }

    EBR ebr_inicial;
    fseek(_file, extendida.part_start, SEEK_SET);
    fread(&ebr_inicial, sizeof(EBR), 1, _file);

    if (existeNombreEBR(ebr_inicial, name, _file))
        return coutError("El nombre a asignar ya existe como partición lógica.", _file);

    if (sizeByte + getLogicsSize(ebr_inicial, 0, _file) > extendida.part_s)
        return coutError("El -size requerido de la partición lógica sobrepasa el tamaño de la partición extendida",
                         _file);

    if (ebr_inicial.part_s == 0) // Modifica el EBR inicial si no hay una partición lógica creada
    {
        ebr_inicial.part_fit = _fit;
        strcpy(ebr_inicial.part_name, name.c_str());
        ebr_inicial.part_s = sizeByte;
        ebr_inicial.part_status = '1';
        fseek(_file, extendida.part_start, SEEK_SET);
        fwrite(&ebr_inicial, sizeof(EBR), 1, _file);
        // fwrite("\0", _size, 1, _file);
    } else {
        fseek(_file, extendida.part_start, SEEK_SET);
        EBR ebr_to_update = getLogicByFit(ebr_inicial, _fit, _file, sizeByte); // ebr_to_update
        if (ebr_to_update.part_status == '!')
            return coutError("No se pudo crear la partición lógica.", _file);
        EBR ebr_new;
        ebr_new.part_fit = _fit;
        strcpy(ebr_new.part_name, name.c_str());
        ebr_new.part_next = ebr_to_update.part_next;
        ebr_new.part_s = sizeByte;
        ebr_new.part_start = ebr_to_update.part_start + ebr_to_update.part_s; // + sizeof(EBR)
        ebr_new.part_status = '1';

        ebr_to_update.part_next = ebr_new.part_start;
        Superbloque sb;

        fseek(_file, ebr_to_update.part_start, SEEK_SET);
        fwrite(&ebr_to_update, sizeof(EBR), 1, _file);

        fseek(_file, ebr_new.part_start, SEEK_SET);
        fwrite(&ebr_new, sizeof(EBR), 1, _file);

        fwrite(&sb, sizeof(Superbloque), 1, _file);
    }
    fclose(_file);
    _file = NULL;
    return;
}


void FDisk::erasePartition(char deleteChar) {


    char src[completedPath.size() + 1];
    strcpy(src, completedPath.c_str());
    MBR mbr;
    FILE *pFile;
    pFile = fopen(src, "rb+");
    fseek(pFile, 0, SEEK_SET);
    fread(&mbr, sizeof(MBR), 1, pFile);

    if (deleteChar == 'C') {
        char type = existPartition(mbr, name, pFile);
        if (type == '0')
            return coutError("No se encuentra ninguna partición con ese nombre asignado.", pFile);

        if (type == 'P' || type == 'E') {
            int i = getPartitionIndex(mbr, name, pFile);

            if(i==0){
                mbr.mbr_partition_1.part_fit = mbr.dsk_fit;
                strcpy(mbr.mbr_partition_1.part_name, "               ");
                // mbr.mbr_partition_1.part_size = 0;
                mbr.mbr_partition_1.part_status = '0';
                mbr.mbr_partition_1.part_type = 'P';
                fseek(pFile, 0, SEEK_SET);
                fwrite(&mbr, sizeof(MBR), 1, pFile);
                std::cout << "\033[1;32mSe borró particion 1\033[0m\n";
                if (deleteChar == 'C') {
                    fseek(pFile, mbr.mbr_partition_1.part_start, SEEK_SET);
                    fwrite("\0", 1, mbr.mbr_partition_1.part_s, pFile);
                }
            }else if(i==1){
                mbr.mbr_partition_2.part_fit = mbr.dsk_fit;
                strcpy(mbr.mbr_partition_2.part_name, "               ");
                // mbr.mbr_partition[i].part_size = 0;
                mbr.mbr_partition_2.part_status = '0';
                mbr.mbr_partition_2.part_type = 'P';
                fseek(pFile, 0, SEEK_SET);
                fwrite(&mbr, sizeof(MBR), 1, pFile);
                std::cout << "\033[1;32mSe borró particion 2\033[0m\n";
                if (deleteChar == 'C') {
                    fseek(pFile, mbr.mbr_partition_2.part_start, SEEK_SET);
                    fwrite("\0", 1, mbr.mbr_partition_2.part_s, pFile);
                }
            }else if(i==2){
                mbr.mbr_partition_3.part_fit = mbr.dsk_fit;
                strcpy(mbr.mbr_partition_3.part_name, "               ");
                // mbr.mbr_partition_3.part_size = 0;
                mbr.mbr_partition_3.part_status = '0';
                mbr.mbr_partition_3.part_type = 'P';
                fseek(pFile, 0, SEEK_SET);
                fwrite(&mbr, sizeof(MBR), 1, pFile);
                std::cout << "\033[1;32mSe borró particion 3\033[0m\n";
                if (deleteChar == 'C') {
                    fseek(pFile, mbr.mbr_partition_3.part_start, SEEK_SET);
                    fwrite("\0", 1, mbr.mbr_partition_3.part_s, pFile);
                }
            }else if(i==3){
                mbr.mbr_partition_4.part_fit = mbr.dsk_fit;
                strcpy(mbr.mbr_partition_4.part_name, "               ");
                // mbr.mbr_partition_4.part_size = 0;
                mbr.mbr_partition_4.part_status = '0';
                mbr.mbr_partition_4.part_type = 'P';
                fseek(pFile, 0, SEEK_SET);
                fwrite(&mbr, sizeof(MBR), 1, pFile);
                std::cout << "\033[1;32mSe borró particion 4\033[0m\n";
                if (deleteChar == 'C') {
                    fseek(pFile, mbr.mbr_partition_4.part_start, SEEK_SET);
                    fwrite("\0", 1, mbr.mbr_partition_4.part_s, pFile);
                }
            }
        } else if (type == 'L') //borrar referencia del EBR anterior
        {
            int i= existeExtendida(mbr);
            partition extendida = {};
            if(i == 0){
                extendida = mbr.mbr_partition_1;
            }else if(i==1){
                extendida = mbr.mbr_partition_2;
            }else if(i==2){
                extendida = mbr.mbr_partition_3;
            }else if(i==3){
                extendida = mbr.mbr_partition_4;
            }

            EBR _ebr_to_delete, _ebr_initial, _ebr_previous;
            fseek(pFile, extendida.part_start, SEEK_SET);
            fread(&_ebr_initial, sizeof(EBR), 1, pFile);
            _ebr_to_delete = getLogicPartition(_ebr_initial, name, pFile);
            _ebr_previous = getEBRprevious(_ebr_initial, _ebr_to_delete.part_start, pFile);
            _ebr_previous.part_next = _ebr_to_delete.part_next;
            fseek(pFile, _ebr_to_delete.part_start, SEEK_SET);
            fseek(pFile, _ebr_previous.part_start, SEEK_SET);
            fwrite(&_ebr_previous, sizeof(EBR), 1, pFile);
        }
    }else{
        return coutError("Párametro >delete no válido: " + this->varDelete, pFile);
    }


    fclose(pFile);
    pFile = NULL;
    return;
}


void FDisk::manageSpace(){
    char src[completedPath.size() + 1];
    strcpy(src, completedPath.c_str());
    MBR mbr;
    FILE *pFile;
    pFile = fopen(src, "rb+");
    fseek(pFile, 0, SEEK_SET);
    fread(&mbr, sizeof(MBR), 1, pFile);

    char type = existPartition(mbr, name, pFile);
    if (type == '0')
        return coutError("No se encuentra ninguna partición con ese nombre asignado.", pFile);

    int size = getSize(_unit, std::stoi(add));
    if (type == 'P' || type == 'E') {

        int i = getPartitionIndex(mbr, name, pFile);
        if(i==0){
            if (!validations2(mbr, i, mbr.mbr_partition_1.part_start, mbr.mbr_partition_1.part_s ,size)) {
                return coutError(
                        "El parámetro '-add' debe dejar espacio positivo y no exceder los límites de la partición.", pFile);
            }
            mbr.mbr_partition_1.part_s = mbr.mbr_partition_1.part_s + size;
            if(mbr.mbr_partition_2.part_status == '0'){
                mbr.mbr_partition_2.part_start = mbr.mbr_partition_1.part_start +mbr.mbr_partition_1.part_s+1;
                mbr.mbr_partition_2.part_s = mbr.mbr_partition_2.part_s + (-1*size);
            }
            fseek(pFile, 0, SEEK_SET);
            fwrite(&mbr, sizeof(MBR), 1, pFile);
        }else if(i==1){
            if (!validations2(mbr, i, mbr.mbr_partition_2.part_start, mbr.mbr_partition_2.part_s, size)) {
                return coutError(
                        "El parámetro '-add' debe dejar espacio positivo y no exceder los límites de la partición.", pFile);
            }
            mbr.mbr_partition_2.part_s = mbr.mbr_partition_2.part_s + size;
            if(mbr.mbr_partition_3.part_status == '0'){
                mbr.mbr_partition_3.part_start = mbr.mbr_partition_2.part_start +mbr.mbr_partition_2.part_s+1;
                mbr.mbr_partition_3.part_s = mbr.mbr_partition_3.part_s + (-1*size);
            }
            fseek(pFile, 0, SEEK_SET);
            fwrite(&mbr, sizeof(MBR), 1, pFile);
        }else if(i==2){
            if (!validations2(mbr, i, mbr.mbr_partition_3.part_start, mbr.mbr_partition_3.part_s, size)) {
                return coutError(
                        "El parámetro '-add' debe dejar espacio positivo y no exceder los límites de la partición.", pFile);
            }
            mbr.mbr_partition_3.part_s = mbr.mbr_partition_3.part_s + size;
            if(mbr.mbr_partition_4.part_status == '0' ){
                mbr.mbr_partition_4.part_start = mbr.mbr_partition_3.part_start +mbr.mbr_partition_3.part_s+1;
                mbr.mbr_partition_4.part_s = mbr.mbr_partition_4.part_s + (-1*size);
            }
            fseek(pFile, 0, SEEK_SET);
            fwrite(&mbr, sizeof(MBR), 1, pFile);
        }else if(i==3){
            if (!validations2(mbr, i, mbr.mbr_partition_4.part_start, mbr.mbr_partition_4.part_s, size)) {
                return coutError(
                        "El parámetro '-add' debe dejar espacio positivo y no exceder los límites de la partición.", pFile);
            }
            mbr.mbr_partition_4.part_s = mbr.mbr_partition_4.part_s + size;
            fseek(pFile, 0, SEEK_SET);
            fwrite(&mbr, sizeof(MBR), 1, pFile);
        }
        // fwrite("\0", _particion.part_size, 1, pFile);
    } else if (type == 'L') {
        int indice = existeExtendida(mbr);
        partition extendida = {};
        if(indice == 0){
            extendida = mbr.mbr_partition_1;
        }else if(indice == 1){
            extendida = mbr.mbr_partition_2;
        }else if(indice == 2){
            extendida = mbr.mbr_partition_3;
        }else if(indice == 3){
            extendida = mbr.mbr_partition_4;
        }

        EBR _ebr_to_update, _ebr_initial;
        fseek(pFile, extendida.part_start, SEEK_SET);
        fread(&_ebr_initial, sizeof(EBR), 1, pFile);
        _ebr_to_update = getLogicPartition(_ebr_initial, name, pFile);
        if(_ebr_to_update.part_next != -1){
            if (_ebr_to_update.part_start + _ebr_to_update.part_s + size >= _ebr_to_update.part_next ||
                _ebr_to_update.part_start + _ebr_to_update.part_s + size < _ebr_to_update.part_start)
                return coutError(
                        "El parámetro '-add' debe sobrar espacio positivo y no exceder los límites de la partición.",
                        pFile);
        }else{
            if (_ebr_to_update.part_start + _ebr_to_update.part_s + size >= extendida.part_start+extendida.part_s ||
                _ebr_to_update.part_start + _ebr_to_update.part_s + size < _ebr_to_update.part_start)
                return coutError(
                        "El parámetro '-add' debe sobrar espacio positivo y no exceder los límites de la partición.",
                        pFile);
        }


        _ebr_to_update.part_s = _ebr_to_update.part_s + size;
        fseek(pFile, _ebr_to_update.part_start, SEEK_SET);
        fwrite(&_ebr_to_update, sizeof(EBR), 1, pFile);
        // fwrite("\0", _ebr_to_update.part_size, 1, pFile);
    }
    fclose(pFile);
    pFile = NULL;
    return;
}


int FDisk::getPartitionByFit(int _options[]) {
    int n = _options[0];
    int ret = -1;
    for (int i = 0; i < 4; i++) {
        if (_options[i] != -1) {
            switch (_fit) {
                case 'F':
                    return i;
                case 'W':
                    if (_options[i] > n || ret == -1) {
                        n = _options[i];
                        ret = i;
                    }
                    break;
                case 'B':
                    if (_options[i] < n || ret == -1) {
                        n = _options[i];
                        ret = i;
                    }
                    break;
                default:
                    return -1;
            }
        }
    }
    return ret;
}


EBR FDisk::getLogicByFit(EBR _ebr_initial, char _fit, FILE *_file, int sizeByte) {
    std::vector<EBR> _options = toRunLogicPartitions(_ebr_initial, _file, sizeByte, std::vector<EBR>());
    if (_options.size() == 0)
        return {part_status : '!'};
    int n, aux = -1;
    EBR _ebr, ret = _options[0];
    for (int i = 0; i < _options.size(); i++) {
        _ebr = _options[i];
        aux = (_ebr.part_next == -1) ? 0 : _ebr.part_next - _ebr.part_start - _ebr.part_s;
        switch (_fit) {
            case 'F':
                return _ebr;
            case 'B':
                if (aux < n) {
                    n = aux;
                    ret = _ebr;
                }
                break;
            case 'W':
                if (aux > n) {
                    n = aux;
                    ret = _ebr;
                }
                break;
            default:
                return {part_status : '!'};
        }
    }
    return ret;
}


std::vector<EBR> FDisk::toRunLogicPartitions(EBR _ebr, FILE *_file, int sizeByte, std::vector<EBR> _list) {
    if (_ebr.part_next - _ebr.part_start - _ebr.part_s > sizeByte || _ebr.part_next == -1)
        _list.push_back(_ebr);
    if (_ebr.part_next != -1) {
        fseek(_file, _ebr.part_next, SEEK_SET);
        fread(&_ebr, sizeof(EBR), 1, _file);
        return toRunLogicPartitions(_ebr, _file, sizeByte, _list);
    }
    return _list;
}


bool FDisk::validations(MBR _mbr, int _index, int _ini, int sizeByte) {

    if(_index == 0){
        if (_ini +  sizeByte < 0 || _ini + sizeByte > _mbr.mbr_tamano || _ini + sizeByte < _mbr.mbr_partition_1.part_start)
            return false;
        if (_index < 3 && _mbr.mbr_partition_2.part_start > 0) {
            if (_ini + sizeByte >= _mbr.mbr_partition_2.part_start)
                return false;
        }
    }else if(_index == 1){
        if (_ini + sizeByte < 0 || _ini + sizeByte > _mbr.mbr_tamano || _ini + sizeByte < _mbr.mbr_partition_2.part_start)
            return false;
        if (_index < 3 && _mbr.mbr_partition_3.part_start > 0) {
            if (_ini + sizeByte >= _mbr.mbr_partition_3.part_start)
                return false;
        }
    }else if(_index == 2){
        if (_ini + sizeByte < 0 || _ini + sizeByte > _mbr.mbr_tamano || _ini + sizeByte < _mbr.mbr_partition_3.part_start)
            return false;
        if (_index < 3 && _mbr.mbr_partition_4.part_start > 0) {
            if (_ini + sizeByte >= _mbr.mbr_partition_4.part_start)
                return false;
        }
    }else if(_index == 3){
        if (_ini + sizeByte < 0 || _ini + sizeByte > _mbr.mbr_tamano || _ini + sizeByte < _mbr.mbr_partition_4.part_start)
            return false;
    }

    return true;
}

bool FDisk::validations2(MBR _mbr, int _index, int _ini, int sizePart,  int sizeByte) {

    if(_index == 0){
        if (_ini + sizePart + sizeByte < 0 || _ini + sizePart +sizeByte > _mbr.mbr_tamano || _ini + sizePart + sizeByte < _mbr.mbr_partition_1.part_start)
            return false;
        if (_mbr.mbr_partition_2.part_status == '1' && _mbr.mbr_partition_2.part_start > 0) {
            if (_ini + sizePart + sizeByte >= _mbr.mbr_partition_2.part_start)
                return false;
        }
    }else if(_index == 1){
        if (_ini + sizePart + sizeByte < 0 || _ini + sizePart + sizeByte > _mbr.mbr_tamano || _ini + sizePart + sizeByte < _mbr.mbr_partition_2.part_start)
            return false;
        if (_mbr.mbr_partition_3.part_status == '1'  && _mbr.mbr_partition_3.part_start > 0) {
            if (_ini + sizePart + sizeByte >= _mbr.mbr_partition_3.part_start)
                return false;
        }
    }else if(_index == 2){
        if (_ini + sizePart + sizeByte < 0 || _ini + sizePart + sizeByte > _mbr.mbr_tamano || _ini +  sizePart + sizeByte < _mbr.mbr_partition_3.part_start)
            return false;
        if (_mbr.mbr_partition_4.part_status == '1'  && _mbr.mbr_partition_4.part_start > 0) {
            if (_ini + sizePart + sizeByte >= _mbr.mbr_partition_4.part_start)
                return false;
        }
    }else if(_index == 3){
        if (_ini + sizePart + sizeByte < 0 || _ini + sizePart + sizeByte > _mbr.mbr_tamano || _ini +  sizePart + sizeByte < _mbr.mbr_partition_4.part_start)
            return false;
    }

    return true;
}


