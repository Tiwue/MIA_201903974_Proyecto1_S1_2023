#include "../Disks/RmDisk.h"
#include <iostream>
#include <string.h>
#include "../Utils/Functions.h"


RmDisk::RmDisk(std::string path) {
    this->path = path;
    executeRmDisk();
}


void RmDisk::executeRmDisk(){
    if (path == "")
        return coutError("Error: faltan parámetros obligatorios.", NULL);
    std::string _path = getPath(path);
    if (!isDir(_path))
        return coutError("Error: el disco no existe.", NULL);
    char ans;
    std::cout << "¿Desea eliminar el disco ubicado en: '" + _path + "?' [Y/n]" << std::endl;
    std::cin >> ans;
    if (ans == 'Y' || ans == 'y') {
        char src[_path.size() + 1];
        strcpy(src, _path.c_str());
        if (remove(src) != 0) {
            return coutError("Error: no se pudo eliminar el disco.", NULL);
        }
    }
}


