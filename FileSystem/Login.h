
#ifndef MIA_PROYECTO1_LOGIN_H
#define MIA_PROYECTO1_LOGIN_H


#include <string>

class Login {
public:
    Login(std::string user,std::string pdw, std::string id);

    std::string user;
    std::string pwd;
    std::string id;


    void executeLogin();
};


#endif //MIA_PROYECTO1_LOGIN_H
