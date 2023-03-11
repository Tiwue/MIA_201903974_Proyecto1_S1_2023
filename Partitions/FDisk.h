#ifndef MIA_PROYECTO1_FDISK_H
#define MIA_PROYECTO1_FDISK_H


#include <string>
#include "../Utils/Structures.h"


class FDisk {
public:
    FDisk(std::string size, std::string unit, std::string path, std::string type, std::string fit,
          std::string varDelete, std::string name, std::string add);

    std::string size;
    std::string unit;
    std::string path;
    std::string type;
    std::string fit;
    std::string varDelete;
    std::string name;
    std::string add;

    int _size;
    char _unit;
    std::string completedPath;
    char _type;
    char _fit;

    void executeFDisk();

    void createPartitions();

    void createPrimary(int _nstart, FILE *_file);

    void createExtended(int _nstart, FILE *_file);

    void createLogic(MBR _mbr, int _size, FILE *_file);

    bool validations(MBR _mbr, int _index, int _ini, int sizeByte);

    bool validations2(MBR _mbr, int _index, int _ini, int sizePart, int sizeByte);
    void erasePartition(char deleteChar);

    void manageSpace();

    int getPartitionByFit(int *_options);

    std::vector<EBR> toRunLogicPartitions(EBR _ebr, FILE *_file, int _size, std::vector<EBR> _list);

    EBR getLogicByFit(EBR _ebr_initial, char _fit, FILE *_file, int _size);
};

#endif //MIA_PROYECTO1_FDISK_H
