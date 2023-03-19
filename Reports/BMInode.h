
#ifndef MIA_PROYECTO1_BITMAPINODE_H
#define MIA_PROYECTO1_BITMAPINODE_H

#include "../Utils/Structures.h"
#include "../Utils/Functions.h"
#include "../Disks/DiskFunctions.h"
#include "ReportFunctions.h"
#include <string>

class BMInode {
public:
    BMInode(ParticionesMontadas mounted);

    ParticionesMontadas mounted;
    std::string getReport();

};


#endif //MIA_PROYECTO1_BITMAPINODE_H
