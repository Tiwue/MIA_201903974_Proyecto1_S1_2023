

#include "ReportHandler.h"
#include "../Utils/Functions.h"
#include "ReportFunctions.h"
#include "../Disks/DiskFunctions.h"
#include "MBRReport.h"
#include "DiskReport.h"
#include "../Utils/Variables.h"



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
            return coutError("El nombre del reporte a generar no es válido: " + _name, NULL);
    }
    if (grafo == "-")
        return;

    writeDot(grafo);
    generateReport(dir_output);
}


