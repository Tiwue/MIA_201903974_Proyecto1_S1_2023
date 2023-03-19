
#ifndef MIA_PROYECTO1_BITMAPBLOCK_H
#define MIA_PROYECTO1_BITMAPBLOCK_H

#include "../Utils/Structures.h"
#include "../Utils/Functions.h"
#include "../Disks/DiskFunctions.h"
#include "ReportFunctions.h"
#include <string>


class BMBlock{
public:
    BMBlock(ParticionesMontadas mounted);
    ParticionesMontadas mounted;

    std::string getReport();

};


#endif //MIA_PROYECTO1_BITMAPBLOCK_H
