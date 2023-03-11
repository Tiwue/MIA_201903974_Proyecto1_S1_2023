//
// Created by erick on 3/09/22.
//

#ifndef MIA_PROYECTO1_ADMINSTRUCTURE_H
#define MIA_PROYECTO1_ADMINSTRUCTURE_H

#include <iostream>
#include <stdio.h>
#include "Structures.h"

struct Group {
    int GID = 1;
    char tipo = 'G';
    std::string nombre = "root";
};

struct User {
    int UID = 1;
    int GID = 1;
    char tipo = 'U';
    std::string grupo = "root";
    std::string nombre = "root";
    std::string contrasena = "123";
    bool logged_in = false;
    ParticionesMontadas mounted;
};



#endif //MIA_PROYECTO1_ADMINSTRUCTURE_H
