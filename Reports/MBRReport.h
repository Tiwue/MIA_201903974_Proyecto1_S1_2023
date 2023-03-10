//
// Created by erick on 9/09/22.
//

#ifndef MIA_PROYECTO1_201901758_2S2022_MBR_H
#define MIA_PROYECTO1_201901758_2S2022_MBR_H

#include <string.h>

class MBRReport{
public:
    MBRReport(ParticionesMontadas mounted);
    ParticionesMontadas mounted;

    std::string getReport();

    std::string getDotMBR(MBR _mbr, std::string _path);

    std::string getDotEBR(EBR _ebr, int _index, std::string _node, std::string _dot, FILE *_file);


};

#endif //MIA_PROYECTO1_201901758_2S2022_MBR_H
