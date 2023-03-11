
#ifndef MIA_PROYECTO1_UNMOUNT_H
#define MIA_PROYECTO1_UNMOUNT_H


#include <string>
#include "../Utils/Structures.h"

class UnMount {
public:
    UnMount(std::string id);
    std::string id;

    void executeUnMount();
    void unMountPartition(DiskId _disk_id);
};


#endif //MIA_PROYECTO1_UNMOUNT_H
