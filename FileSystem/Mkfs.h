
#ifndef MIA_PROYECTO1_MKFS_H
#define MIA_PROYECTO1_MKFS_H


#include <string>
#include <mntent.h>
#include "../Utils/Structures.h"

class Mkfs {
public:
    Mkfs(std::string id, std::string type, std::string fs);

    std::string id;
    std::string _type;
    std::string _fs;
    int fs;
    char type;

    void executeMkfs();
    void crearSistemaArchivos(ParticionesMontadas _mounted);

};


#endif //MIA_PROYECTO1_MKFS_H
