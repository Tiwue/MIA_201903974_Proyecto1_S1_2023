
#ifndef MIA_PROYECTO1_201901758_2S2022_MKUSR_H
#define MIA_PROYECTO1_201901758_2S2022_MKUSR_H


#include <string>

class MkUsr {
public:
    MkUsr(std::string user, std::string pwd, std::string grp);

    std::string user;
    std::string pwd;
    std::string grp;

    void executeMkUsr();


};


#endif //MIA_PROYECTO1_201901758_2S2022_MKUSR_H
