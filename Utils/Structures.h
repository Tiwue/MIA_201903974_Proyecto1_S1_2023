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

struct Superbloque {
    int s_filesystem_type;   // Guarda el número que identifica el sistema de archivos utilizado
    int s_inodes_count;      // Guarda el número total de inodos
    int s_blocks_count;      // Guarda el número total de bloques
    int s_free_blocks_count; // Contiene el número de bloques libres
    int s_free_inodes_count; // Contiene el número de inodos libres
    time_t s_mtime;          // Última fecha en el que el sistema fue montado
    time_t s_umtime;         // Última fecha en que el sistema fue desmontado
    int s_mnt_count = 0;     // Indica cuantas veces se ha montado el sistema
    int s_magic;             // Valor que identifica al sistema de archivos, tendrá el valor 0xEF53
    int s_inode_s;        // Tamaño del inodo
    int s_block_s;        // Tamaño del bloque
    int s_first_ino;         // Primer inodo libre
    int s_first_blo;         // Primer bloque libre
    int s_bm_inode_start;    // Guardará el inicio del bitmap de inodos
    int s_bm_block_start;    // Guardará el inicio del bitmap de bloques
    int s_inode_start;       // Guardará el inicio de la tabla de inodos
    int s_block_start;       // Guardará el inicio de la tabla de bloques
};
#endif