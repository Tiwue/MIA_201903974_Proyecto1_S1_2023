#include <iostream>
#include <fstream>
#include <string.h>
#include "../Utils/Structures.h"
#include "../Utils/Functions.h"
#include "../Disks/DiskFunctions.h"
#include "ReportFunctions.h"
#include "MBRReport.h"

MBRReport::MBRReport(ParticionesMontadas mounted) {
    this->mounted = mounted;
}

std::string MBRReport::getReport() {
    std::string grafo = getBaseHeader();
    FILE *_file = fopen(mounted.path.c_str(), "rb");

    MBR mbr;
    fseek(_file, 0, SEEK_SET);
    fread(&mbr, sizeof(MBR), 1, _file);
    grafo += getDotMBR(mbr, mounted.path);

    int index = existeExtendida(mbr);
    if (index != -1) {
        EBR ebr;
        partition extendida = {};
        if(index == 0){
            extendida = mbr.mbr_partition_1;
        }else if(index ==1){
            extendida = mbr.mbr_partition_2;
        }else if(index ==2){
            extendida = mbr.mbr_partition_3;
        }else if(index ==3){
            extendida = mbr.mbr_partition_4;
        }
        fseek(_file, extendida.part_start, SEEK_SET);
        fread(&ebr, sizeof(EBR), 1, _file);
        if (ebr.part_s != 0)
            grafo += getDotEBR(ebr, 0, "\"MBR Report\"", "", _file);
    }
    grafo += "}";

    fclose(_file);
    _file = NULL;
    return grafo;
}

std::string MBRReport::getDotMBR(MBR _mbr, std::string _path) {
    std::string mbr_fecha_creacion = ctime(&_mbr.mbr_fecha_creacion);
    std::string dot =
            std::string("\"MBR Report\" [ margin=\"0.5\" label = <\n") +
            "<TABLE BGCOLOR=\"#48D1CC\" BORDER=\"2\" COLOR=\"BLACK\" CELLBORDER=\"1\" CELLSPACING=\"0\">\n" +
            "<TR>\n" +
            "<TD BGCOLOR=\"#d23939\" COLSPAN=\"2\">REPORTE DE MBR</TD>\n" +
            "</TR>\n\n" +

            "<TR>\n" +
            "<TD WIDTH=\"140\" BGCOLOR=\"#ff6363\"><B>Nombre</B></TD>\n" +
            "<TD BGCOLOR=\"#ff6363\"><B>Valor</B></TD>\n" +
            "</TR>\n\n" +

            "<TR>\n" +
            "<TD ALIGN=\"left\">mbr_tamaño</TD>\n" +
            "<TD>" + std::to_string(_mbr.mbr_tamano) + "</TD>\n" +
            "</TR>\n\n" +

            "<TR>\n" +
            "<TD ALIGN=\"left\">mbr_fecha_creacion</TD>\n" +
            "<TD>" + mbr_fecha_creacion + "</TD>\n" +
            "</TR>\n\n" +

            "<TR>\n" +
            "<TD ALIGN=\"left\">mbr_disk_signature</TD>\n" +
            "<TD>" + std::to_string(_mbr.mbr_dsk_signature) + "</TD>\n" +
            "</TR>\n\n" +

            "<TR>\n" +
            "<TD ALIGN=\"left\">disk_fit</TD>\n" +
            "<TD>" + _mbr.dsk_fit + "</TD>\n" +
            "</TR>\n\n" +

            "<TR>\n" +
            "<TD ALIGN=\"left\">disk_path</TD>\n" +
            "<TD>" + _path.substr(root.length()) + "</TD>\n" +
            "</TR>\n\n";

    partition _particion = _mbr.mbr_partition_1;
    if (_particion.part_status == '1') {
        dot +=
                std::string("<TR>\n") +
                "<TD ALIGN=\"left\">part_status</TD>\n" +
                "<TD>" + _particion.part_status + "</TD>\n" +
                "</TR>\n\n" +

                "<TR>\n" +
                "<TD ALIGN=\"left\">part_type</TD>\n" +
                "<TD>" + _particion.part_type + "</TD>\n" +
                "</TR>\n\n" +

                "<TR>\n" +
                "<TD ALIGN=\"left\">part_fit</TD>\n" +
                "<TD>" + _particion.part_fit + "</TD>\n" +
                "</TR>\n\n" +

                "<TR>\n" +
                "<TD ALIGN=\"left\">part_start</TD>\n" +
                "<TD>" + std::to_string(_particion.part_start) + "</TD>\n" +
                "</TR>\n\n" +

                "<TR>\n" +
                "<TD ALIGN=\"left\">part_size</TD>\n" +
                "<TD>" + std::to_string(_particion.part_s) + "</TD>\n" +
                "</TR>\n\n" +

                "<TR>\n" +
                "<TD ALIGN=\"left\">part_name</TD>\n" +
                "<TD>" + _particion.part_name + "</TD>\n" +
                "</TR>\n\n";
    }

    _particion = _mbr.mbr_partition_2;
    if (_particion.part_status == '1') {
        dot +=
                std::string("<TR>\n") +
                "<TD ALIGN=\"left\">part_status</TD>\n" +
                "<TD>" + _particion.part_status + "</TD>\n" +
                "</TR>\n\n" +

                "<TR>\n" +
                "<TD ALIGN=\"left\">part_type</TD>\n" +
                "<TD>" + _particion.part_type + "</TD>\n" +
                "</TR>\n\n" +

                "<TR>\n" +
                "<TD ALIGN=\"left\">part_fit</TD>\n" +
                "<TD>" + _particion.part_fit + "</TD>\n" +
                "</TR>\n\n" +

                "<TR>\n" +
                "<TD ALIGN=\"left\">part_start</TD>\n" +
                "<TD>" + std::to_string(_particion.part_start) + "</TD>\n" +
                "</TR>\n\n" +

                "<TR>\n" +
                "<TD ALIGN=\"left\">part_size</TD>\n" +
                "<TD>" + std::to_string(_particion.part_s) + "</TD>\n" +
                "</TR>\n\n" +

                "<TR>\n" +
                "<TD ALIGN=\"left\">part_name</TD>\n" +
                "<TD>" + _particion.part_name + "</TD>\n" +
                "</TR>\n\n";
    }

    _particion = _mbr.mbr_partition_3;
    if (_particion.part_status == '1') {
        dot +=
                std::string("<TR>\n") +
                "<TD ALIGN=\"left\">part_status</TD>\n" +
                "<TD>" + _particion.part_status + "</TD>\n" +
                "</TR>\n\n" +

                "<TR>\n" +
                "<TD ALIGN=\"left\">part_type</TD>\n" +
                "<TD>" + _particion.part_type + "</TD>\n" +
                "</TR>\n\n" +

                "<TR>\n" +
                "<TD ALIGN=\"left\">part_fit</TD>\n" +
                "<TD>" + _particion.part_fit + "</TD>\n" +
                "</TR>\n\n" +

                "<TR>\n" +
                "<TD ALIGN=\"left\">part_start</TD>\n" +
                "<TD>" + std::to_string(_particion.part_start) + "</TD>\n" +
                "</TR>\n\n" +

                "<TR>\n" +
                "<TD ALIGN=\"left\">part_size</TD>\n" +
                "<TD>" + std::to_string(_particion.part_s) + "</TD>\n" +
                "</TR>\n\n" +

                "<TR>\n" +
                "<TD ALIGN=\"left\">part_name</TD>\n" +
                "<TD>" + _particion.part_name + "</TD>\n" +
                "</TR>\n\n";
    }

    _particion = _mbr.mbr_partition_4;
    if (_particion.part_status == '1') {
        dot +=
                std::string("<TR>\n") +
                "<TD ALIGN=\"left\">part_status</TD>\n" +
                "<TD>" + _particion.part_status + "</TD>\n" +
                "</TR>\n\n" +

                "<TR>\n" +
                "<TD ALIGN=\"left\">part_type</TD>\n" +
                "<TD>" + _particion.part_type + "</TD>\n" +
                "</TR>\n\n" +

                "<TR>\n" +
                "<TD ALIGN=\"left\">part_fit</TD>\n" +
                "<TD>" + _particion.part_fit + "</TD>\n" +
                "</TR>\n\n" +

                "<TR>\n" +
                "<TD ALIGN=\"left\">part_start</TD>\n" +
                "<TD>" + std::to_string(_particion.part_start) + "</TD>\n" +
                "</TR>\n\n" +

                "<TR>\n" +
                "<TD ALIGN=\"left\">part_size</TD>\n" +
                "<TD>" + std::to_string(_particion.part_s) + "</TD>\n" +
                "</TR>\n\n" +

                "<TR>\n" +
                "<TD ALIGN=\"left\">part_name</TD>\n" +
                "<TD>" + _particion.part_name + "</TD>\n" +
                "</TR>\n\n";
    }

    dot += "</TABLE>>];\n";
    return dot;
}

std::string MBRReport::getDotEBR(EBR _ebr, int _index, std::string _node, std::string _dot, FILE *_file) {
    _index++;
    std::string new_node = "\"EBR_" + std::to_string(_index) + " Report\"";
    _dot += _node + " -> " + new_node + "\n";
    _dot +=
            std::string(new_node + " [ label = <\n") +
            "<TABLE BGCOLOR=\"#48D1CC\" BORDER=\"2\" COLOR=\"BLACK\" CELLBORDER=\"1\" CELLSPACING=\"0\">\n" +
            "<TR>\n" +
            "<TD BGCOLOR=\"#d23939\" COLSPAN=\"2\">EBR_" + std::to_string(_index) + " REPORT</TD>\n" +
            "</TR>\n\n" +

            "<TR>\n" +
            "<TD WIDTH=\"140\" BGCOLOR=\"#ff6363\"><B>Nombre</B></TD>\n" +
            "<TD BGCOLOR=\"#ff6363\"><B>Valor</B></TD>\n" +
            "</TR>\n\n" +

            "<TR>\n" +
            "<TD ALIGN=\"left\">part_name</TD>\n" +
            "<TD>" + _ebr.part_name + "</TD>\n" +
            "</TR>\n\n" +

            "<TR>\n" +
            "<TD ALIGN=\"left\">part_status</TD>\n" +
            "<TD>" + _ebr.part_status + "</TD>\n" +
            "</TR>\n\n" +

            "<TR>\n" +
            "<TD ALIGN=\"left\">part_fit</TD>\n" +
            "<TD>" + _ebr.part_fit + "</TD>\n" +
            "</TR>\n\n" +

            "<TR>\n" +
            "<TD ALIGN=\"left\">part_start</TD>\n" +
            "<TD>" + std::to_string(_ebr.part_start) + "</TD>\n" +
            "</TR>\n\n" +

            "<TR>\n" +
            "<TD ALIGN=\"left\">part_size</TD>\n" +
            "<TD>" + std::to_string(_ebr.part_s) + "</TD>\n" +
            "</TR>\n\n" +

            "<TR>\n" +
            "<TD ALIGN=\"left\">part_next</TD>\n" +
            "<TD>" + std::to_string(_ebr.part_next) + "</TD>\n" +
            "</TR>\n\n" + "</TABLE>>];\n";

    if (_ebr.part_next != -1) {
        fseek(_file, _ebr.part_next, SEEK_SET);
        fread(&_ebr, sizeof(EBR), 1, _file);
        return getDotEBR(_ebr, _index, new_node, _dot, _file);
    }
    return _dot;
}
