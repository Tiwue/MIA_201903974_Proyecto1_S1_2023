#ifndef MIA_PROYECTO1_MKDISK_H
#define MIA_PROYECTO1_MKDISK_H

#include <string>
#include "../Utils/Structures.h"

class MkDisk{
public:
    MkDisk(std::string path, std::string size, std::string fit, std::string unit);

    std::string size;
    std::string path;
    std::string fit;
    std::string unit;

    int _size;
    char _fit;
    char _unit;
    std::string _path;

    void executeDisk();
    void createDisk();
};


#endif //MIA_PROYECTO1_MKDISK_H
