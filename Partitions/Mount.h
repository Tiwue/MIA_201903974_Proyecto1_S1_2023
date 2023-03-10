

#ifndef MIA_PROYECTO1_201901758_2S2022_MOUNT_H
#define MIA_PROYECTO1_201901758_2S2022_MOUNT_H

#include <string>
#include "../Utils/Structures.h"
#include "../Utils/Variables.h"


class Mount {
public:
    Mount(std::string path, std::string );
    std::string name;
    std::string path;

    void executeMount();
    void mountPartition();

    void printMOUNTED();

    DiskId assignID();
};


#endif //MIA_PROYECTO1_201901758_2S2022_MOUNT_H
