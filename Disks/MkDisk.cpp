#include <iostream>
#include <cstring>
#include "MkDisk.h"
#include "../Utils/Functions.h"
#include "../Utils/Variables.h"
#include <stdlib.h>
#include <string>
#include <stdio.h>
#include <libgen.h>
#include <cstdlib>
#include <cstring>
#include <fstream>




void MkDisk::executeDisk() {
    try {
        //casting  variables
        _size = castSize(this->size);
        _fit = getFit(this->fit, 'F');
        _unit = getUnit(this->unit, 'm');
        _path = buildPath(this->path);
        std::cout << "CREANDO DISCO EN LA RUTA: \"" + _path + "\"" << std::endl;
        createDisk();
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
        return coutError("ERROR!", NULL);
    }
}


void MkDisk::createDisk() {
    char path1[255];
    std::string comando = "sudo mkdir -p \'";
    strcpy(path1,_path.c_str());
    comando += dirname(path1);
    comando += '\'';
    std::cout<<comando<<std::endl;
    system(comando.c_str());
    if (std::string(path1)!="/home" || std::string(path1)!="/" ||std::string(path1)!="/home/steven" ){
        comando = "sudo chmod -R 777 \'";
        comando += dirname(path1);
        comando += '\'';
        system(comando.c_str());
    }

    char charPath[_path.size() + 1];
    strcpy(charPath, _path.c_str());
    FILE *file = NULL;
    file = fopen(charPath, "r");
    if (file != NULL) {
        return coutError("Error: El disco ya existe.", file);
    }
    //Tamaño para distintas unidades que se piden
    int tam = getSize(_unit, _size);
    file = fopen(charPath, "wb");

    fwrite("\0", 1, 1, file);
    fseek(file, tam, SEEK_SET);
    fwrite("\0", 1, 1, file);
    MBR mbr{};
    mbr.mbr_tamano = tam;
    mbr.mbr_fecha_creacion = getCurrentTime();
    mbr.mbr_dsk_signature = rand() % 1000;
    mbr.dsk_fit = _fit;

    mbr.mbr_partition_1.part_status = '0';
    mbr.mbr_partition_1.part_type = 'P';
    mbr.mbr_partition_1.part_fit = _fit;
    mbr.mbr_partition_1.part_start = 0;
    mbr.mbr_partition_1.part_s = 0;
    strcpy(mbr.mbr_partition_1.part_name, "");

    mbr.mbr_partition_2.part_status = '0';
    mbr.mbr_partition_2.part_type = 'P';
    mbr.mbr_partition_2.part_fit = _fit;
    mbr.mbr_partition_2.part_start = 0;
    mbr.mbr_partition_2.part_s = 0;
    strcpy(mbr.mbr_partition_2.part_name, "");

    mbr.mbr_partition_3.part_status = '0';
    mbr.mbr_partition_3.part_type = 'P';
    mbr.mbr_partition_3.part_fit = _fit;
    mbr.mbr_partition_3.part_start = 0;
    mbr.mbr_partition_3.part_s = 0;
    strcpy(mbr.mbr_partition_3.part_name, "");


    mbr.mbr_partition_4.part_status = '0';
    mbr.mbr_partition_4.part_type = 'P';
    mbr.mbr_partition_4.part_fit = _fit;
    mbr.mbr_partition_4.part_start = 0;
    mbr.mbr_partition_4.part_s = 0;
    strcpy(mbr.mbr_partition_4.part_name, "");

    //Escritura del MBR
    fseek(file, 0, SEEK_SET);
    fwrite(&mbr, sizeof(MBR), 1, file);
    fclose(file);
    file = NULL;
}


MkDisk::MkDisk(std::string path, std::string size, std::string fit, std::string unit) {
    this->size = size;
    this->path = path;
    this->fit = fit;
    this->unit = unit;
    executeDisk();

}


