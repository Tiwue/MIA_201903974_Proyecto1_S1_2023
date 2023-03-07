#ifndef MIA_PROYECTO1_DISKFUNCTIONS_H
#define MIA_PROYECTO1_DISKFUNCTIONS_H


#include "../Utils/Structures.h"


bool existLogicPartition(EBR _ebr, std::string _name, FILE *_file);

char existPartition(MBR _mbr, std::string _name, FILE *_file);



EBR getLogicPartition(EBR _ebr, std::string _name, FILE *_file);

EBR getEBRprevious(EBR _ebr, int _n, FILE *_file);

partition getPartition(MBR _mbr, std::string _name, FILE *_file);

int getPartitionIndex(MBR _mbr, std::string _name, FILE *_file);

int particionDisponible(MBR _mbr);

int existeExtendida(MBR _mbr);

EBR getLastEBR(EBR _ebr, FILE *pFile);

bool existeNombreMBR(MBR _mbr, std::string _name);

bool existeNombreEBR(EBR _ebr, std::string _name, FILE *_file);

int getPartitionsSize(MBR _mbr);

int getLogicsSize(EBR _ebr, int _s, FILE *_file);

DiskId buildID(std::string _id);

int existMountedID(DiskId _disk_id);



#endif
