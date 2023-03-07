#ifndef STRUCTURES
#define STRUCTURES

#include <iostream>
#include <stdio.h>



struct partition {
    char part_status;
    char part_type; // primaria, extendida, logica
    char part_fit;  // las opciones por default
    int part_start;
    int part_s;
    char part_name[16];
};


struct MBR {
    int mbr_tamano;
    time_t mbr_fecha_creacion;
    int mbr_dsk_signature;
    char dsk_fit;
    partition mbr_partition_1;
    partition mbr_partition_2;
    partition mbr_partition_3;
    partition mbr_partition_4;
};


struct EBR {
    char part_status;
    char part_fit; //b,f,w
    int part_start;
    int part_s;
    int part_next; //próximo EBR || -1
    char part_name[16];
};


struct DiskId {
    std::string _carnet = "74";
    int _number_id;
    std::string _disk_name_id;
};


struct ParticionesMontadas {
    std::string path;
    DiskId id;
    char type;
    partition particion;
    EBR logica;
};
#endif