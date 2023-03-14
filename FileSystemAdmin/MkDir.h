//
// Created by erick on 5/09/22.
//

#ifndef MIA_PROYECTO1_201901758_2S2022_MKDIR_H
#define MIA_PROYECTO1_201901758_2S2022_MKDIR_H

#include <string>

class MkDir {
public:
    MkDir();

    void executeMkDir(std::string path, std::string p);

    bool createDirectory(std::string path, std::string _name, bool _p);

    bool recursiveMkDir(std::string path, std::string p);
};

#endif //MIA_PROYECTO1_201901758_2S2022_MKDIR_H
