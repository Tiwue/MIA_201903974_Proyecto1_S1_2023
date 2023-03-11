

#ifndef MIA_PROYECTO1_DISK_H
#define MIA_PROYECTO1_DISK_H

#include <string>
#include "../Utils/Structures.h"
#include "../Utils/Functions.h"
#include "../Disks/DiskFunctions.h"



class DiskReport {
public:
    DiskReport(ParticionesMontadas _mounted);

    ParticionesMontadas _mounted;

    std::string getReport();

    std::string getDotPartitions(MBR _mbr, std::string _path, FILE *_file);

    std::string getDotLogics(EBR _ebr, int _mbr_tamano, FILE *_file, std::string _color, std::string _dot, int _free);

    std::string getPercentage(int _free, int _mbr_tamano);

    int getSizeBeforeFree(partition mbr_partition[4], int _num, int _mbr_tamano);



    };


#endif //MIA_PROYECTO1_sDISK_H
