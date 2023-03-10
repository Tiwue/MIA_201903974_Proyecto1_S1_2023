
#include "UnMount.h"

#include <iostream>
#include "../Utils/Structures.h"
#include "../Utils/Functions.h"
#include "../Disks/DiskFunctions.h"
#include "../Utils/Variables.h"

UnMount::UnMount(std::string id) {
    this->id = id;
    executeUnMount();
}

void UnMount::executeUnMount() {
    if (id == "")
        return coutError("Error: faltan parámetros obligatorios.", NULL);
    DiskId _disk_id = buildID(id);
    unMountPartition(_disk_id);
}

void UnMount::unMountPartition(DiskId _disk_id) {
    ParticionesMontadas mounted;
    bool finded = false;
    for (int i = particiones_montadas.size() - 1; i >= 0; i--) {
        mounted = particiones_montadas[i];
        if (mounted.id._carnet == _disk_id._carnet && mounted.id._number_id == _disk_id._number_id &&
            mounted.id._disk_name_id == _disk_id._disk_name_id) {
            particiones_montadas.erase(particiones_montadas.begin() + i);
            finded = true;
            if (mounted.type != 'E') {
                int _part_start = (mounted.type == 'L') ? (mounted.logica.part_start) : (mounted.particion.part_start);
                FILE *file = fopen(mounted.path.c_str(), "rb+");
                Superbloque sb;
                fseek(file, _part_start, SEEK_SET);
                fread(&sb, sizeof(Superbloque), 1, file);
                if (sb.s_mnt_count > 0 && mounted.type != 'E') {
                    sb.s_umtime = getCurrentTime();
                    fseek(file, _part_start, SEEK_SET);
                    fwrite(&sb, sizeof(Superbloque), 1, file);
                }
                fclose(file);
                file = NULL;

            }
            break;
        }
    }
    if(!finded){
        coutError("No se encuentra ninguna partición montada con el id: '" + _disk_id._carnet +
                  std::to_string(_disk_id._number_id) + _disk_id._disk_name_id + "'.", NULL);
    }
}


