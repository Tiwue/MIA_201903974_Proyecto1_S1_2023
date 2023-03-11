#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include "Functions.h"
#include "Structures.h"
#include <experimental/filesystem>
#include "Variables.h"
#include "AdminStructure.h"


namespace fs = std::experimental::filesystem;


std::string buildPath(std::string _path) {
    std::string np = getPath(_path);
    std::string dir = getDir(np);
    if (!isDir(dir))                 // Check if path exists
        fs::create_directories(dir); // create src folder
    return np;
}
void coutError(std::string err, FILE *_file) {
    if (_file != NULL) {
        fclose(_file);
        _file = NULL;
    }
    std::cout << "\033[1;31m" + err + "\033[0m\n";
    return;
}

void exitIfItFails(std::string err) {
    std::cout << "\033[1;31m" + err + "\033[0m\n";
    exit(EXIT_FAILURE);
}

int castSize(std::string _size) {
    int newSize = std::stoi(_size);
    if (newSize <= 0)
        exitIfItFails("Error: el valor de '-size' debe ser mayor que cero.");
    return newSize;
}

std::string getPath(std::string _path) {

    std::string np = _path;
    if (_path[0] == '\"')
        np = _path.substr(1, _path.size() - 2);
    if (np[0] != '/')
        np = "/" + np;
    np = root + np;
    return np;
}

std::string getDir(std::string np) {
    std::string dir = np.substr(0, np.find_last_of('/'));
    return dir;
}

bool isDir(std::string dir) {
    if (!fs::is_directory(dir) && !fs::exists(dir))
        return false;
    else
        return true;
}


char getFit(std::string _fit, char _default) {
    char nf;
    transform(_fit.begin(), _fit.end(), _fit.begin(), ::toupper);
    if (_fit == "BF") //best
        nf = 'B';
    else if (_fit == "FF") //first
        nf = 'F';
    else if (_fit == "WF") //worst
        nf = 'W';
    else if (_fit == "")
        nf = _default;
    else //err
        exitIfItFails("Error: parámetro -f no válido: " + _fit);
    return nf;
}

char getUnit(std::string _unit, char _default) {
    char nu;
    transform(_unit.begin(), _unit.end(), _unit.begin(), ::tolower);
    if (_unit == "b")
        nu = 'b';
    else if (_unit == "k")
        nu = 'k';
    else if (_unit == "m")
        nu = 'm';
    else if (_unit == "")
        nu = _default;
    else //err
        exitIfItFails("Error: parámetro -u no válido: " + _unit);
    return nu;
}

int getSize(char _unit, int _size) {
    if (_unit == 'b') //bytes
        return _size;
    else if (_unit == 'k') //kb
        return _size * 1000;
    else if (_unit == 'm') //mb
        return _size * 1000 * 1000;
    return -1;
}

char charType(std::string _type, char _default) {
    char ntype;
    transform(_type.begin(), _type.end(), _type.begin(), ::toupper);
    if (_type == "E")
        ntype = 'E';
    else if (_type == "L")
        ntype = 'L';
    else if (_type == "P")
        ntype = 'P';
    else if (_type == "")
        ntype = _default;
    else //err
        exitIfItFails("Error: parámetro -type no válido: " + _type);
    return ntype;
}

char charDelete(std::string _delete) {
    char ndelete;
    transform(_delete.begin(), _delete.end(), _delete.begin(), ::tolower);
    if (_delete == "full")
        ndelete = 'C'; //completa
    else if (_delete == "")
        ndelete = 'N'; //no aplica
    else
        ndelete = 'N'; //no aplica
    return ndelete;
}

time_t getCurrentTime() {
    auto curr_time = std::chrono::system_clock::now();
    std::time_t curr_time_t = std::chrono::system_clock::to_time_t(curr_time);
    return curr_time_t;
}

char charFormat(std::string _format) {
    char nformat = 'N';
    transform(_format.begin(), _format.end(), _format.begin(), ::tolower);
    if (_format == "fast")
        nformat = 'R'; //rápida
    else if (_format == "full" || _format == "")
        nformat = 'C'; //completa
    else
        std::cout << "Error: parámetro -type no válido: " + std::to_string(nformat) << std::endl;
    return nformat;
}

int _2_or_3fs(std::string _fs) {
    int nfs = 2;
    transform(_fs.begin(), _fs.end(), _fs.begin(), ::tolower);
    if (_fs == "3fs")
        nfs = 3; //ext3
    return nfs;
}

int number_inodos(int _part_size, int _ext) {
    switch (_ext) {
        case 2:
            return (int) floor(((_part_size - sizeof(Superbloque)) / (1 + 3 + sizeof(InodosTable) + 3 * 64)));
        case 3:
            return (int) floor(((_part_size - sizeof(Superbloque)) / (1 + 3 + sizeof(Journaling) + sizeof(InodosTable) + 3 * 64)));
        default:
            return 0;
    }
}

std::string getData(Group _group, User _user) {
    std::string data =
            std::to_string(_group.GID) + "," + _group.tipo + "," + _group.nombre + "\n" + std::to_string(_user.UID) +
            "," + _user.tipo + "," + _user.grupo + "," + _user.nombre + "," + _user.contrasena + "\n";
    return data;
}

int startByteSuperBloque(ParticionesMontadas _mounted) {
    int sb_start=0;
    switch (_mounted.type) {
        case 'P':
            sb_start = _mounted.particion.part_start;
            break;
        case 'L':
            sb_start = _mounted.logica.part_start + sizeof(EBR);
            break;
        default:
            break;
    }
    return sb_start;
}

std::string ReadFile(int _index_inode, int _s_inode_start, int _s_block_start, std::string _path) {
    FILE *file = fopen(_path.c_str(), "rb");
    std::string content = "";
    InodosTable inode_current;
    fseek(file, _s_inode_start, SEEK_SET);
    fseek(file, _index_inode * sizeof(InodosTable), SEEK_CUR);
    fread(&inode_current, sizeof(InodosTable), 1, file);
    for (int i = 0; i < 15; i++) //agregar indirectos
    {
        if (inode_current.i_block[i] != -1) {
            ArchivosBlock src;
            fseek(file, _s_block_start + inode_current.i_block[i] * 64, SEEK_SET);
            fread(&src, 64, 1, file);
            content += std::string(src.b_content);
        }
    }
    fclose(file);
    file = NULL;
    return content;
}

Group getGroupByName(std::string _name, InodosTable users_inode, int s_block_start, std::string _path) {

    std::string content_file = GetAllFile(users_inode, s_block_start, _path);
    Group group_tmp;
    /* LEER LÍNEA POR LÍNEA EL ARCHIVO USERS.TXT */
    std::istringstream f(content_file);
    std::string line;
    while (getline(f, line)) {
        int count = 0;
        for (int i = 0; (i = line.find(',', i)) != std::string::npos; i++)
            count++;
        switch (count) {
            case 2:
                group_tmp.GID = std::stoi(line.substr(0, line.find_first_of(',')));
                line = line.substr(line.find_first_of(',') + 1);

                group_tmp.tipo = line.substr(0, line.find_first_of(','))[0];
                line = line.substr(line.find_first_of(',') + 1);

                group_tmp.nombre = line.substr(0, line.find_first_of('\n'));

                if (group_tmp.nombre == _name && group_tmp.GID != 0) {
                    return group_tmp;
                }
                break;
            default:
                break;
        }
    }
    return group_tmp;
}

std::string GetAllFile(InodosTable _inode, int _s_block_start, std::string _path) {
    FILE *_file = fopen(_path.c_str(), "rb");
    std::string content = "";
    for (int i = 0; i < 15; i++) //agregar indirectos
    {
        if (_inode.i_block[i] != -1) {
            ArchivosBlock src;
            fseek(_file, _s_block_start + _inode.i_block[i] * 64, SEEK_SET);
            fread(&src, 64, 1, _file);
            content += std::string(src.b_content);
            // std::cout << _inode.i_block[i] << std::endl;
        }
    }
    fclose(_file);
    _file = NULL;
    return content;
}





