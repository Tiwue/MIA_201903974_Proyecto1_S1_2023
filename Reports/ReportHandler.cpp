

#include "ReportHandler.h"
#include "../Utils/Functions.h"
#include "ReportFunctions.h"
#include "../Disks/DiskFunctions.h"
#include "MBRReport.h"
#include "DiskReport.h"
#include "../Utils/Variables.h"
#include "Inode.h"
#include "Block.h"
#include "BMBlock.h"
#include "BMInode.h"
#include "SB.h"



ReportHandler::ReportHandler(std::string _name, std::string _path, std::string _id, std::string _ruta) {
    this->_name = _name;
    this->_path = _path;
    this->_id = _id;
    this->_ruta = _ruta;
    executeReportHandler();
}

void ReportHandler::executeReportHandler() {
    if (_name == "" || _path == "" || _id == "") {
        return coutError("Error: faltan parámetros obligatorios.", NULL);
    }
    transform(_name.begin(), _name.end(), _name.begin(), ::tolower);
    std::string dir_output = buildPath(_path);

    DiskId disk_id = buildID(_id);
    std::vector<ParticionesMontadas> pm = particiones_montadas;
    int index = existMountedID(disk_id);
    if (index == -1) {
        return coutError("No se encuentra ninguna partición montada con el id '" + _id + "'.", NULL);
    }
    ParticionesMontadas mounted = particiones_montadas[index];
    std::string grafo = "-";

    if (_name == "mbr") {
        MBRReport *mbr = new MBRReport(mounted);
        grafo = mbr->getReport();
    }
    else if (_name == "disk") {
        DiskReport *disk = new DiskReport(mounted);
        grafo = disk->getReport();
    }else{
        Superbloque sb;
        FILE *file = fopen(mounted.path.c_str(), "rb");
        int part_start = startByteSuperBloque(mounted);
        fseek(file, part_start, SEEK_SET);
        fread(&sb, sizeof(Superbloque), 1, file);
        if (sb.s_magic == -1)
            return coutError("El sistema de archivos se ha corrompido, intente recuperarlo usando Recovery.", file);

        if (_name == "inode") {
            Inode *inode = new Inode(mounted);
            grafo = inode->getReport();
        }else if (_name == "block") {
            Block *block = new Block(mounted);
            grafo = block->getReport();
        }
        else if (_name == "bm_inode") {
            BMInode *bmInode = new BMInode(mounted);
            grafo = bmInode->getReport();
        }
        else if (_name == "bm_bloc") {
            BMBlock *bmBlock = new BMBlock(mounted);
            grafo = bmBlock->getReport();
        }
        else if (_name == "sb") {
            SB *superBlock = new SB(mounted);
            grafo = superBlock->getReport();
        }
        else
            return coutError("El nombre del reporte a generar no es válido: " + _name, NULL);
    }
    if (grafo == "-")
        return;

    writeDot(grafo);
    generateReport(dir_output);
}


