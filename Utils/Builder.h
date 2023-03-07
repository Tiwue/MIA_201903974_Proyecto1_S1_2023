#ifndef BUILDER
#define BUILDER

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>

using std::string;

struct command {
    string keyword;
    string size;
    string fit;
    string unit;
    string path;
    string type;
    string delet;
    string name;
    string add;
    string id;
    string fs;

    string user;
    string pwd;
    string grp;

    string ugo;
    string r;
    string cont;
    string _stdin;
    std::vector<string> filen;
    string dest;

    string ruta;
    string root;
};

struct parameter {
    string tipo;
    string valor;
};

static struct command newCommand(string _type, std::vector<parameter> _params) {
    struct command parameter;
    parameter.keyword = _type;
    for (size_t i = 0; i < _params.size(); i++) {
        if (_params[i].tipo == "__SIZE")
            parameter.size = _params[i].valor;

        else if (_params[i].tipo == "__FIT")
            parameter.fit = _params[i].valor;

        else if (_params[i].tipo == "__UNIT")
            parameter.unit = _params[i].valor;

        else if (_params[i].tipo == "__PATH")
            parameter.path = _params[i].valor;

        else if (_params[i].tipo == "__TYPE")
            parameter.type = _params[i].valor;

        else if (_params[i].tipo == "__TYPE2")
            parameter.type = _params[i].valor;

        else if (_params[i].tipo == "__DELETE")
            parameter.delet = _params[i].valor;

        else if (_params[i].tipo == "__NAME")
            parameter.name = _params[i].valor;

        else if (_params[i].tipo == "__ADD")
            parameter.add = _params[i].valor;

        else if (_params[i].tipo == "__ID")
            parameter.id = _params[i].valor;

        else if (_params[i].tipo == "__FS")
            parameter.fs = _params[i].valor;

        else if (_params[i].tipo == "__USER")
            parameter.user = _params[i].valor;

        else if (_params[i].tipo == "__PWD")
            parameter.pwd = _params[i].valor;

        else if (_params[i].tipo == "__GRP")
            parameter.grp = _params[i].valor;

        else if (_params[i].tipo == "__RUTA")
            parameter.ruta = _params[i].valor;

        else if (_params[i].tipo == "__ROOT")
            parameter.root = _params[i].valor;

        else if (_params[i].tipo == "__UGO")
            parameter.ugo = _params[i].valor;

        else if (_params[i].tipo == "__R")
            parameter.r = _params[i].valor;

        else if (_params[i].tipo == "__CONT")
            parameter.cont = _params[i].valor;
        else if (_params[i].tipo == "__FILEN")
            parameter.filen.push_back(_params[i].valor);

        else if (_params[i].tipo == "__DEST")
            parameter.dest = _params[i].valor;

        else
            std::cout << "Parámetro no válido: " + _params[i].valor << std::endl;
    }
    return parameter;
}

#endif