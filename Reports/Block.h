
#ifndef MIA_PROYECTO1_BLOCK_H
#define MIA_PROYECTO1_BLOCK_H

#include "../Utils/Structures.h"
#include "../Utils/Functions.h"
#include "../Disks/DiskFunctions.h"
#include "ReportFunctions.h"
#include <string>

class Block {
public:
    Block(ParticionesMontadas mounted);

    ParticionesMontadas mounted;

    std::string getReport();

    std::string getDotBlock(int _index_inode, int _start_inodes, int _start_blocks, std::string _path);

    std::string getDot_folder_block(int _start_blocks, int _index_block, std::string _path);

    std::string getDot_file_block(int _start_blocks, int _index_block, std::string _path);

    std::string getDot_pointer_block(int _start_blocks, int _index_block, std::string _path);

};


#endif //MIA_PROYECTO1_BLOCK_H
