
#include "Mount.h"

#include <iostream>

#include "../Utils/Functions.h"
#include "../Disks/DiskFunctions.h"

Mount::Mount(std::string path, std::string name) {
    this->name = name;
    this->path = path;
    executeMount();
}


void Mount::executeMount() {
    if (path == "" || name == "") {
        return coutError("Error: faltan parámetros obligatorios.", nullptr);
    }
    path = getPath(path);
    if (!isDir(path)) {
        return coutError("Error: el disco no existe.", nullptr);
    }
    mountPartition();
}


void Mount::mountPartition() {
    FILE *_file = fopen(path.c_str(), "rb+");

    MBR mbr;
    fseek(_file, 0, SEEK_SET);
    fread(&mbr, sizeof(MBR), 1, _file);

    char tipo = existPartition(mbr, name, _file);
    int test = particiones_montadas.size();
    ParticionesMontadas _mounted;
    _mounted.id = assignID();
    _mounted.type = tipo;
    _mounted.path = path;

    int _part_start;

    if (tipo == 'P' || tipo == 'E') {
        partition _particion = getPartition(mbr, name, _file);
        _part_start = _particion.part_start;
        _mounted.particion = _particion;
    } else if (tipo == 'L') {
        int i = existeExtendida(mbr);
        partition _extendida = {};
        if(i==0){
            _extendida = mbr.mbr_partition_1;
        }else if(i==1){
            _extendida = mbr.mbr_partition_2;
        }else if(i==2){
            _extendida = mbr.mbr_partition_3;
        }else if(i==3){
            _extendida = mbr.mbr_partition_4;
        }


        EBR _ebr_to_mount, _ebr_initial;
        fseek(_file, _extendida.part_start, SEEK_SET);
        fread(&_ebr_initial, sizeof(EBR), 1, _file);
        _ebr_to_mount = getLogicPartition(_ebr_initial, name, _file);
        _part_start = _ebr_to_mount.part_start + sizeof(EBR);

        _mounted.logica = _ebr_to_mount;
    } else {
        return coutError("No se encuentra ninguna partición con ese nombre asignado.", _file);
    }

    particiones_montadas.push_back(_mounted);

    std::vector<ParticionesMontadas> pm = particiones_montadas;
    int tam = number_id;

    if (tipo != 'E') {
        Superbloque sb;
        fseek(_file, _part_start, SEEK_SET);
        fread(&sb, sizeof(Superbloque), 1, _file);
        if (sb.s_mnt_count > 0) {
            sb.s_mtime = getCurrentTime();
            sb.s_mnt_count++;
            fseek(_file, _part_start, SEEK_SET);
            fwrite(&sb, sizeof(Superbloque), 1, _file);
        }
    }

    fclose(_file);
    _file = nullptr;
    return printMOUNTED();
}



DiskId Mount::assignID() {
    int tam = particiones_montadas.size();
    ParticionesMontadas mounted;
    struct DiskId tmp {};
    std::string nameTemp = path.substr(path.find_last_of('/') + 1);

    std::string cleanName = nameTemp.substr(0,nameTemp.size()-4);

    tmp._disk_name_id = cleanName;

    for (int i = particiones_montadas.size() - 1; i >= 0; i--) {
        mounted = particiones_montadas[i];
        if (mounted.path == path) {
            tmp._number_id = mounted.id._number_id;
            tmp._number_id += 1;
            return tmp;
        }
    }
    tmp._number_id = 1;
    return tmp;
}


void Mount::printMOUNTED() {
    for (int i = 0; i < particiones_montadas.size(); i++) {
        ParticionesMontadas _mounted = particiones_montadas[i];
        std::string tmp = _mounted.id._carnet + std::to_string(_mounted.id._number_id) + _mounted.id._disk_name_id;
        std::string name = (_mounted.type == 'L') ? _mounted.logica.part_name : _mounted.particion.part_name;
        std::cout << "\033[1;33m" + _mounted.path + "|" + name + "|" + tmp + "\033[0m\n";
    }
}
