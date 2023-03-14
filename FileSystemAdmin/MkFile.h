//
// Created by erick on 3/09/22.
//

#ifndef MIA_PROYECTO1_201901758_2S2022_MKFILE_H
#define MIA_PROYECTO1_201901758_2S2022_MKFILE_H


#include <string>

class MkFile {

public:
    MkFile(std::string path, std::string r, std::string size, std::string cont, std::string _stdin, bool edit);

    std::string path;
    std::string r;
    std::string size;
    std::string cont;
    std::string _stdin;
    bool toEdit;

    int status;

    void executeMkFile();

    void createFile(std::string _path, std::string _name, bool _r, int _size);

    void edit();
};


#endif //MIA_PROYECTO1_201901758_2S2022_MKFILE_H
