#include "MkGrp.h"

#include <iostream>
#include <string.h>
#include "../Utils/Functions.h"
#include "../Disks/DiskFunctions.h"
#include "../Utils/Variables.h"



MkGrp::MkGrp(std::string name) {
    this->name = name;
    executeMkGrp();
}


void MkGrp::executeMkGrp() {
    if (name == "")
        return coutError("Error: faltan parámetros obligatorios.", NULL);

    if (_user_logged.logged_in == false || _user_logged.nombre != "root")
        return coutError("Error: solamente se puede ejecutar el comando mkgrp con el usuario root.", NULL);

    Group group_to_create;
    group_to_create.nombre = name;

    FILE *file = fopen((_user_logged.mounted.path).c_str(), "rb");
    Group group_tmp;
    /* Lectura del superbloque */
    Superbloque super_bloque;
    fseek(file, startByteSuperBloque(_user_logged.mounted), SEEK_SET);
    fread(&super_bloque, sizeof(Superbloque), 1, file);

    /* Lectura del inodo de usuarios */
    InodosTable users_inode;
    fseek(file, super_bloque.s_inode_start, SEEK_SET); // Mover el puntero al inicio de la tabla de inodos
    fseek(file, sizeof(InodosTable),
          SEEK_CUR);        // Mover el puntero al segundo inodo que corresponde al archivo de users.txt
    fread(&users_inode, sizeof(InodosTable), 1, file); // Leer el inodo
    fclose(file);
    file = NULL;

    //Obtener todo el archivo concatenado
    std::string content_file = GetAllFile(users_inode, super_bloque.s_block_start, _user_logged.mounted.path);
    file = fopen((_user_logged.mounted.path).c_str(), "rb+");

    ArchivosBlock users_file; // Obtener el último bloque de archivo
    int seek_last_file_block = ByteLastFileBlock(users_inode);
    fseek(file, super_bloque.s_block_start, SEEK_SET);
    fseek(file, seek_last_file_block, SEEK_CUR);
    fread(&users_file, sizeof(ArchivosBlock), 1, file);

    /* LEER LÍNEA POR LÍNEA EL ARCHIVO USERS.TXT */
    // std::cout << content_file";
    std::istringstream f(content_file);
    std::string line;
    int gid = 1;
    while (getline(f, line)) {
        int count = 0;
        for (int i = 0; (i = line.find(',', i)) != std::string::npos; i++)
            count++;
        switch (count) {
            case 2:
                gid++;
                group_tmp.GID = std::stoi(line.substr(0, line.find_first_of(',')));
                line = line.substr(line.find_first_of(',') + 1);

                group_tmp.tipo = line.substr(0, line.find_first_of(','))[0];
                line = line.substr(line.find_first_of(',') + 1);

                group_tmp.nombre = line.substr(0, line.find_first_of('\n'));

                if (group_tmp.nombre == group_to_create.nombre && group_tmp.GID != 0)
                    return coutError("Error: El nombre del grupo ya existe.", file);
                break;
            default:
                break;
        }
    }
    std::string tmp = std::to_string(gid) + ",G," + group_to_create.nombre + "\n"; //content_file +
    users_inode.i_s = std::string(users_file.b_content).length() + tmp.length();
    users_inode.i_mtime = getCurrentTime();
    std::string extra = "-";
    if (std::string(users_file.b_content).length() + tmp.length() > 64) {
        tmp = std::string(users_file.b_content) + tmp;
        extra = tmp.substr(64);
        tmp = tmp.substr(0, 64);
    } else {
        tmp = std::string(users_file.b_content) + tmp;
    }
    strcpy(users_file.b_content, tmp.c_str());

    /* ESCRITURA */
    fseek(file, super_bloque.s_inode_start, SEEK_SET);
    fseek(file, sizeof(InodosTable), SEEK_CUR);
    fwrite(&users_inode, sizeof(InodosTable), 1, file);

    fseek(file, super_bloque.s_block_start, SEEK_SET);
    fseek(file, seek_last_file_block, SEEK_CUR);
    fwrite(&users_file, sizeof(ArchivosBlock), 1, file);
    fclose(file);
    file = NULL;
    //si excede el tamaño se crean mas bloques de contenido
    if (extra != "-"){
        writeBlocks(extra, 1);
    }
}