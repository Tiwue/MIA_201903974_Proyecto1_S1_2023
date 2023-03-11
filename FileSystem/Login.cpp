
#include "Login.h"
#include <iostream>
#include <string.h>
#include "../Utils/Functions.h"
#include "../Disks/DiskFunctions.h"
#include "../Utils/Variables.h"



Login::Login(std::string user, std::string pwd, std::string id) {
    this->user = user;
    this->pwd = pwd;
    this-> id = id;
    executeLogin();
}

void Login::executeLogin() {
    if (id == "" || pwd == "" || id == "") {
        return coutError("Error: faltan parámetros obligatorios.", nullptr);
    }
    if (_user_logged.logged_in) {
        return coutError("Error: debe cerrar la sesión activa.", nullptr);
    }
    DiskId disk_id = buildID(id);

    int index = existMountedID(disk_id);
    if (index == -1) {
        return coutError("No se encuentra ninguna partición montada con el id '" + id + "'.", nullptr);
    }
    ParticionesMontadas mounted = particiones_montadas[index];

    User user_to_login, user_tmp;
    user_to_login.nombre = user;
    user_to_login.contrasena = pwd;

    FILE *file = fopen(mounted.path.c_str(), "rb");
    /* Lectura del superbloque */
    Superbloque super_bloque;
    fseek(file, startByteSuperBloque(mounted), SEEK_SET);
    fread(&super_bloque, sizeof(Superbloque), 1, file);

    InodosTable users_inode;
    fseek(file, super_bloque.s_inode_start, SEEK_SET); // Mover el puntero al inicio de la tabla de inodos
    fseek(file, sizeof(InodosTable),
          SEEK_CUR);        // Mover el puntero al segundo inodo que corresponde al archivo de users.txt
    fread(&users_inode, sizeof(InodosTable), 1, file); // Leer el inodo

    ArchivosBlock users_file;
    fseek(file, super_bloque.s_block_start, SEEK_SET);  // Mover el puntero al inicio de la tabla de bloques
    fseek(file, 64,
          SEEK_CUR);                          // Mover el puntero al segundo bloque que corresponde al archivo de users.txt
    fread(&users_file, sizeof(ArchivosBlock), 1, file); // Leer el bloque
    fclose(file);
    file = NULL;

    /* Obtener string con contenido del archivo*/
    std::string content_file = ReadFile(1, super_bloque.s_inode_start,
                                        super_bloque.s_block_start, mounted.path);

    /* LEER LÍNEA POR LÍNEA EL ARCHIVO USERS.TXT */
    // std::cout << content_file << std::endl;
    std::istringstream f(content_file);
    std::string line;
    while (getline(f, line)) {
        int count = 0;
        for (int i = 0; (i = line.find(',', i)) != std::string::npos; i++)
            count++;
        switch (count) {
            case 4:
                user_tmp.UID = std::stoi(line.substr(0, line.find_first_of(',')));
                line = line.substr(line.find_first_of(',') + 1);

                user_tmp.tipo = line.substr(0, line.find_first_of(','))[0];
                line = line.substr(line.find_first_of(',') + 1);

                user_tmp.grupo = line.substr(0, line.find_first_of(','));
                line = line.substr(line.find_first_of(',') + 1);

                user_tmp.nombre = line.substr(0, line.find_first_of(','));
                line = line.substr(line.find_first_of(',') + 1);

                user_tmp.contrasena = line.substr(0, line.find_first_of('\n'));

                if (user_tmp.nombre == user_to_login.nombre && user_tmp.contrasena == user_to_login.contrasena) {
                    user_tmp.logged_in = true;
                    user_tmp.mounted = mounted;
                    _user_logged = user_tmp;
                    _user_logged.GID = getGroupByName(user_tmp.grupo, users_inode, super_bloque.s_block_start,
                                                      mounted.path).GID;
                    return;
                }
                break;
            default:
                break;
        }
    }
    return coutError("No se encuentra ningún usuario con la contraseña brindada. Intente de nuevo.", nullptr);
}
