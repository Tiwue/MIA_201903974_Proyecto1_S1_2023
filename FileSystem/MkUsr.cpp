#include "MkUsr.h"

#include <iostream>
#include <string.h>
#include "../Utils/Functions.h"
#include "../Utils/Variables.h"



MkUsr::MkUsr(std::string user, std::string pwd, std::string grp) {
    this->user = user;
    this->pwd = pwd;
    this->grp = grp;
    executeMkUsr();
}
void MkUsr::executeMkUsr() {
    if (user == "" || pwd == "" || grp == "")
        return coutError("Error: faltan parámetros obligatorios.", NULL);

    if (_user_logged.logged_in == false || _user_logged.nombre != "root")
        return coutError("Error: solamente se puede ejecutar el comando mkusr con el usuario root.", NULL);

    if (user.length() > 10 || pwd.length() > 10 || grp.length() > 10)
        return coutError("Error: la longitud de los parámetros no pueden exceder a los 10 caracteres.", NULL);

    User user_to_create;
    user_to_create.nombre = user;
    user_to_create.contrasena = pwd;
    user_to_create.grupo = grp;

    FILE *file = fopen((_user_logged.mounted.path).c_str(), "rb");
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


    std::string content_file = GetAllFile(users_inode, super_bloque.s_block_start, _user_logged.mounted.path);
    file = fopen((_user_logged.mounted.path).c_str(), "rb+");

    ArchivosBlock users_file; // Obtener el último bloque de archivo
    int seek_last_file_block = ByteLastFileBlock(users_inode);
    fseek(file, super_bloque.s_block_start, SEEK_SET);
    fseek(file, seek_last_file_block, SEEK_CUR);
    fread(&users_file, sizeof(ArchivosBlock), 1, file);

    /* LEER LÍNEA POR LÍNEA EL ARCHIVO USERS.TXT */
    std::istringstream f(content_file);
    User user_tmp;
    Group group_tmp;
    std::string line;
    int gid = 1;
    int uid = 1;
    bool existGroup = false;
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
                if (user_to_create.grupo == group_tmp.nombre && group_tmp.GID != 0)
                    existGroup = true;
                break;
            case 4:
                uid++;
                user_tmp.UID = std::stoi(line.substr(0, line.find_first_of(',')));
                line = line.substr(line.find_first_of(',') + 1);

                user_tmp.tipo = line.substr(0, line.find_first_of(','))[0];
                line = line.substr(line.find_first_of(',') + 1);

                user_tmp.grupo = line.substr(0, line.find_first_of(','));
                line = line.substr(line.find_first_of(',') + 1);

                user_tmp.nombre = line.substr(0, line.find_first_of(','));
                line = line.substr(line.find_first_of(',') + 1);

                user_tmp.contrasena = line.substr(0, line.find_first_of('\n'));
                if (user_tmp.nombre == user_to_create.nombre && user_tmp.UID != 0)
                    return coutError("Error: El nombre del usuario ya existe.", file);
                break;
        }
    }
    if (!existGroup)
        return coutError("Error: No existe ningún grupo activo con el nombre: '" + user_to_create.grupo + "'.", file);

    std::string tmp = std::to_string(uid) + ",U," + user_to_create.grupo + "," + user_to_create.nombre + "," +
                 user_to_create.contrasena + "\n";
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

    if (extra != "-") {
        writeBlocks(extra, 1);
    }

}