
#ifndef MIA_PROYECTO1__SB_H
#define MIA_PROYECTO1__SB_H

#include "../Utils/Structures.h"
#include "../Utils/Functions.h"
#include "../Disks/DiskFunctions.h"
#include "ReportFunctions.h"
#include <string>

class SB {
public:
    SB(ParticionesMontadas mounted);
    ParticionesMontadas mounted;

    std::string getReport();

};


#endif //MIA_PROYECTO1__SB_H
