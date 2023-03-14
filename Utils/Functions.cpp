#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include "Functions.h"
#include "Structures.h"
#include <experimental/filesystem>
#include "Variables.h"
#include "AdminStructure.h"


namespace fs = std::experimental::filesystem;


std::string buildPath(std::string _path) {
    std::string np = getPath(_path);
    std::string dir = getDir(np);
    if (!isDir(dir))                 // Check if path exists
        fs::create_directories(dir); // create src folder
    return np;
}
void coutError(std::string err, FILE *_file) {
    if (_file != NULL) {
        fclose(_file);
        _file = NULL;
    }
    std::cout << "\033[1;31m" + err + "\033[0m\n";
    return;
}

void exitIfItFails(std::string err) {
    std::cout << "\033[1;31m" + err + "\033[0m\n";
    exit(EXIT_FAILURE);
}

int castSize(std::string _size) {
    int newSize = std::stoi(_size);
    if (newSize <= 0)
        exitIfItFails("Error: el valor de '-size' debe ser mayor que cero.");
    return newSize;
}

std::string getPath(std::string _path) {

    std::string np = _path;
    if (_path[0] == '\"')
        np = _path.substr(1, _path.size() - 2);
    if (np[0] != '/')
        np = "/" + np;
    np = root + np;
    return np;
}

std::string getDir(std::string np) {
    std::string dir = np.substr(0, np.find_last_of('/'));
    return dir;
}

bool isDir(std::string dir) {
    if (!fs::is_directory(dir) && !fs::exists(dir))
        return false;
    else
        return true;
}


char getFit(std::string _fit, char _default) {
    char nf;
    transform(_fit.begin(), _fit.end(), _fit.begin(), ::toupper);
    if (_fit == "BF") //best
        nf = 'B';
    else if (_fit == "FF") //first
        nf = 'F';
    else if (_fit == "WF") //worst
        nf = 'W';
    else if (_fit == "")
        nf = _default;
    else //err
        exitIfItFails("Error: parámetro -f no válido: " + _fit);
    return nf;
}

char getUnit(std::string _unit, char _default) {
    char nu;
    transform(_unit.begin(), _unit.end(), _unit.begin(), ::tolower);
    if (_unit == "b")
        nu = 'b';
    else if (_unit == "k")
        nu = 'k';
    else if (_unit == "m")
        nu = 'm';
    else if (_unit == "")
        nu = _default;
    else //err
        exitIfItFails("Error: parámetro -u no válido: " + _unit);
    return nu;
}

int getSize(char _unit, int _size) {
    if (_unit == 'b') //bytes
        return _size;
    else if (_unit == 'k') //kb
        return _size * 1000;
    else if (_unit == 'm') //mb
        return _size * 1000 * 1000;
    return -1;
}

char charType(std::string _type, char _default) {
    char ntype;
    transform(_type.begin(), _type.end(), _type.begin(), ::toupper);
    if (_type == "E")
        ntype = 'E';
    else if (_type == "L")
        ntype = 'L';
    else if (_type == "P")
        ntype = 'P';
    else if (_type == "")
        ntype = _default;
    else //err
        exitIfItFails("Error: parámetro -type no válido: " + _type);
    return ntype;
}

char charDelete(std::string _delete) {
    char ndelete;
    transform(_delete.begin(), _delete.end(), _delete.begin(), ::tolower);
    if (_delete == "full")
        ndelete = 'C'; //completa
    else if (_delete == "")
        ndelete = 'N'; //no aplica
    else
        ndelete = 'N'; //no aplica
    return ndelete;
}

time_t getCurrentTime() {
    auto curr_time = std::chrono::system_clock::now();
    std::time_t curr_time_t = std::chrono::system_clock::to_time_t(curr_time);
    return curr_time_t;
}

char charFormat(std::string _format) {
    char nformat = 'N';
    transform(_format.begin(), _format.end(), _format.begin(), ::tolower);
    if (_format == "fast")
        nformat = 'R'; //rápida
    else if (_format == "full" || _format == "")
        nformat = 'C'; //completa
    else
        std::cout << "Error: parámetro -type no válido: " + std::to_string(nformat) << std::endl;
    return nformat;
}

int _2_or_3fs(std::string _fs) {
    int nfs = 2;
    transform(_fs.begin(), _fs.end(), _fs.begin(), ::tolower);
    if (_fs == "3fs")
        nfs = 3; //ext3
    return nfs;
}

int number_inodos(int _part_size, int _ext) {
    switch (_ext) {
        case 2:
            return (int) floor(((_part_size - sizeof(Superbloque)) / (1 + 3 + sizeof(InodosTable) + 3 * 64)));
        case 3:
            return (int) floor(((_part_size - sizeof(Superbloque)) / (1 + 3 + sizeof(Journaling) + sizeof(InodosTable) + 3 * 64)));
        default:
            return 0;
    }
}

std::string getData(Group _group, User _user) {
    std::string data =
            std::to_string(_group.GID) + "," + _group.tipo + "," + _group.nombre + "\n" + std::to_string(_user.UID) +
            "," + _user.tipo + "," + _user.grupo + "," + _user.nombre + "," + _user.contrasena + "\n";
    return data;
}

int startByteSuperBloque(ParticionesMontadas _mounted) {
    int sb_start=0;
    switch (_mounted.type) {
        case 'P':
            sb_start = _mounted.particion.part_start;
            break;
        case 'L':
            sb_start = _mounted.logica.part_start + sizeof(EBR);
            break;
        default:
            break;
    }
    return sb_start;
}

std::string ReadFile(int _index_inode, int _s_inode_start, int _s_block_start, std::string _path) {
    FILE *file = fopen(_path.c_str(), "rb");
    std::string content = "";
    InodosTable inode_current;
    fseek(file, _s_inode_start, SEEK_SET);
    fseek(file, _index_inode * sizeof(InodosTable), SEEK_CUR);
    fread(&inode_current, sizeof(InodosTable), 1, file);
    for (int i = 0; i < 15; i++) //agregar indirectos
    {
        if (inode_current.i_block[i] != -1) {
            ArchivosBlock src;
            fseek(file, _s_block_start + inode_current.i_block[i] * 64, SEEK_SET);
            fread(&src, 64, 1, file);
            content += std::string(src.b_content);
        }
    }
    fclose(file);
    file = NULL;
    return content;
}

Group getGroupByName(std::string _name, InodosTable users_inode, int s_block_start, std::string _path) {

    std::string content_file = GetAllFile(users_inode, s_block_start, _path);
    Group group_tmp;
    /* LEER LÍNEA POR LÍNEA EL ARCHIVO USERS.TXT */
    std::istringstream f(content_file);
    std::string line;
    while (getline(f, line)) {
        int count = 0;
        for (int i = 0; (i = line.find(',', i)) != std::string::npos; i++)
            count++;
        switch (count) {
            case 2:
                group_tmp.GID = std::stoi(line.substr(0, line.find_first_of(',')));
                line = line.substr(line.find_first_of(',') + 1);

                group_tmp.tipo = line.substr(0, line.find_first_of(','))[0];
                line = line.substr(line.find_first_of(',') + 1);

                group_tmp.nombre = line.substr(0, line.find_first_of('\n'));

                if (group_tmp.nombre == _name && group_tmp.GID != 0) {
                    return group_tmp;
                }
                break;
            default:
                break;
        }
    }
    return group_tmp;
}

std::string GetAllFile(InodosTable _inode, int _s_block_start, std::string _path) {
    FILE *_file = fopen(_path.c_str(), "rb");
    std::string content = "";
    for (int i = 0; i < 15; i++) //agregar indirectos
    {
        if (_inode.i_block[i] != -1) {
            ArchivosBlock src;
            fseek(_file, _s_block_start + _inode.i_block[i] * 64, SEEK_SET);
            fread(&src, 64, 1, _file);
            content += std::string(src.b_content);
            // std::cout << _inode.i_block[i] << std::endl;
        }
    }
    fclose(_file);
    _file = NULL;
    return content;
}

int ByteLastFileBlock(InodosTable _inode) {
    for (int i = 0; i < 15; i++) //falta indirecto
    {
        if (_inode.i_block[i] == -1)
            return _inode.i_block[i - 1] * 64;
    }
    return -1;
}

void writeBlocks(std::string _content, int _number_inode) {
    std::vector<std::string> chars = Separate64Chars(_content);
    for (int i = 0; i < chars.size(); i++) // Por cada iteración crear un bloque de contenido
    {
        int block_written = writeBlock(0, chars[i], -1);
        UpdateInode(_number_inode, block_written);
    }
}

std::vector<std::string> Separate64Chars(std::string _content) {
    std::vector<std::string> vector_s;
    while (_content.length() >= 64) {
        std::string tmp = _content.substr(0, 64);
        vector_s.push_back(tmp);
        _content = _content.substr(64);
    }
    if (_content.length() > 0)
        vector_s.push_back(_content);
    return vector_s;
}

void UpdateInode(int _inode_index, int _block_written) {
    FILE *file = fopen((_user_logged.mounted.path).c_str(), "rb+");
    InodosTable _inode;
    /* Lectura del superbloque */
    Superbloque super_bloque;
    fseek(file, startByteSuperBloque(_user_logged.mounted), SEEK_SET);
    fread(&super_bloque, sizeof(Superbloque), 1, file);
    /* Lectura del inodo */
    fseek(file, super_bloque.s_inode_start, SEEK_SET);
    fseek(file, _inode_index * sizeof(InodosTable), SEEK_CUR);
    fread(&_inode, sizeof(InodosTable), 1, file);

    bool updated = false;
    for (int i = 0; i < 15 && !updated; i++) // falta indirectos
    {
        if (_inode.i_block[i] == -1) {
            _inode.i_block[i] = _block_written;
            _inode.i_mtime = getCurrentTime();
            updated = true;
            break;
        }
    }
    if (!updated)
        coutError("Error: no se encontró ningún bloque de inodo libre para guardar el contenido.", NULL);
    /* Sobreescribir el inodo */
    fseek(file, super_bloque.s_inode_start, SEEK_SET);
    fseek(file, _inode_index * sizeof(InodosTable), SEEK_CUR);
    fwrite(&_inode, sizeof(InodosTable), 1, file);
    fclose(file);
    file = NULL;
}

int writeBlock(int _type, std::string _content, int _block_reference) {
    FILE *file = fopen((_user_logged.mounted.path).c_str(), "rb+");
    int start_byte_sb = startByteSuperBloque(_user_logged.mounted);
    /* Lectura del superbloque */
    Superbloque super_bloque;
    fseek(file, start_byte_sb, SEEK_SET);
    fread(&super_bloque, sizeof(Superbloque), 1, file);
    /* Lectura del bitmap de bloques */
    char bm_block[3 * super_bloque.s_inodes_count];
    fseek(file, super_bloque.s_bm_block_start, SEEK_SET);
    fread(&bm_block, 3 * super_bloque.s_inodes_count, 1, file);
    /* Posicionarse en el espacio del bloque disponible */
    int block_free = super_bloque.s_first_blo;
    fseek(file, super_bloque.s_block_start, SEEK_SET);
    fseek(file, block_free * 64, SEEK_CUR);
    ArchivosBlock archivo;
    ApuntadoresBlock apuntadores;
    switch (_type) {
        case 0:
            strcpy(archivo.b_content, _content.c_str());
            fwrite(&archivo, 64, 1, file);
            break;
    }
    bm_block[block_free] = '1';
    super_bloque.s_first_blo = block_free + 1;
    super_bloque.s_free_blocks_count--;
    fseek(file, start_byte_sb, SEEK_SET);
    fwrite(&super_bloque, sizeof(Superbloque), 1, file);

    fseek(file, super_bloque.s_bm_block_start, SEEK_SET);
    fwrite(&bm_block, 3 * super_bloque.s_inodes_count, 1, file);

    fclose(file);
    file = NULL;
    return block_free; // Retornamos el número de bloque creado
}

std::vector<std::string> SplitPath(std::string _path) {
    std::vector<std::string> spl;
    size_t pos = 0;
    std::string tmp;
    // spl.push_back("/");
    while ((pos = _path.find("/")) != std::string::npos) {
        tmp = _path.substr(0, pos);
        if (tmp != "")
            spl.push_back(tmp);
        _path.erase(0, pos + 1);
    }
    if (_path != "")
        spl.push_back(_path);
    return spl;
}

FolderReference getFatherReference(FolderReference _fr, std::string _folder, FILE *_file, int _start_inodes, int _start_blocks) {

    InodosTable inode;
    fseek(_file, _start_inodes, SEEK_SET);
    fseek(_file, _fr.inode * sizeof(InodosTable), SEEK_CUR);
    fread(&inode, sizeof(InodosTable), 1, _file);
    CarpetasBlock folder_block;
    for (int i = 0; i < 15; i++) // falta indirectos
    {
        if (inode.i_block[i] != -1) {
            fseek(_file, _start_blocks, SEEK_SET);
            fseek(_file, inode.i_block[i] * 64, SEEK_CUR);
            fread(&folder_block, 64, 1, _file);
            for (int j = 0; j < 4; j++) {
                if (std::string(folder_block.b_content[j].b_name) == _folder) {
                    _fr.inode = folder_block.b_content[j].b_inodo; // Inodo directo asociado
                    fseek(_file, _start_inodes, SEEK_SET);
                    fseek(_file, folder_block.b_content[j].b_inodo * sizeof(InodosTable), SEEK_CUR);
                    fread(&inode, sizeof(InodosTable), 1, _file);
                    for (int k = 0; k < 15; k++)
                    {
                        if (inode.i_block[k] != -1) {
                            fseek(_file, _start_blocks, SEEK_SET);
                            fseek(_file, inode.i_block[k] * 64, SEEK_CUR);
                            fread(&folder_block, 64, 1, _file);
                            for (int l = 0; l < 4; l++) {
                                if (folder_block.b_content[l].b_inodo == _fr.inode) {
                                    _fr.block = inode.i_block[k]; // Bloque directo de carpeta asociado
                                    return _fr;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    _fr.inode = -1;
    return _fr;
}

bool HasPermission(User _user, InodosTable _inode, int _req) {
    char u;
    /* Usuario root */
    if (_user.nombre == "root")
        return true;
    /* Propietario */
    if (_user.UID == _inode.i_uid)
        u = std::to_string(_inode.i_perm)[0];
        /* Grupo */
    else if (_user.GID == _inode.i_gid)
        u = std::to_string(_inode.i_perm)[1];
        /* Otros */
    else
        u = std::to_string(_inode.i_perm)[2];

    if (u == '7' || u == '0') // Si es permiso 7 siempre será true y 0 siempre será false
        return u == '7';
    switch (_req) {
        case 1: // Ejecución
            return u == '1' || u == '3' || u == '5' || u == '7';
        case 2: // Escritura
            return u == '2' || u == '3' || u == '6' || u == '7';
        case 3: // Escritura y ejecución
            return u == '3' || u == '7';
        case 4: // Lectura
            return u == '4' || u == '5' || u == '6' || u == '7';
        case 5: // Lectura y ejecución
            return u == '5' || u == '7';
        case 6: // Lectura y escritura
            return u == '6' || u == '7';
        case 7: // Escritura, lectura y ejecución
            return u == '7';
        default:
            return false;
    }
}

bool fileExists(InodosTable _inode, std::string _filename, FILE *_file, int _start_blocks) {
    CarpetasBlock file_block;
    for (int i = 0; i < 15; i++) // falta indirectos
    {
        if (_inode.i_block[i] != -1) {
            fseek(_file, _start_blocks, SEEK_SET);
            fseek(_file, _inode.i_block[i] * 64, SEEK_CUR);
            fread(&file_block, 64, 1, _file);
            for (int j = 0; j < 4; j++) {
                if (std::string(file_block.b_content[j].b_name) == _filename)
                    return true;
            }
        }
    }
    return false;
}

void editarArchivo(std::string _path, std::string _name, std::string _content) {
    /* EDICIÓN DE UN ARCHIVO */
    InodosTable tmp_inode;  // Nuevo inodo
    ArchivosBlock tmp_file; // Nuevo bloque de contenido

    FILE *file = fopen((_user_logged.mounted.path).c_str(), "rb+");
    int start_byte_sb = startByteSuperBloque(_user_logged.mounted);

    /* Lectura del superbloque */
    Superbloque super_bloque;
    fseek(file, start_byte_sb, SEEK_SET);
    fread(&super_bloque, sizeof(Superbloque), 1, file);

    int free_block = super_bloque.s_first_blo;

    /* Lectura del bitmap de bloques */
    char bm_blocks[3 * super_bloque.s_inodes_count];
    fseek(file, super_bloque.s_bm_block_start, SEEK_SET);
    fread(&bm_blocks, 3 * super_bloque.s_inodes_count, 1, file);

    /* Lectura del inodo de carpeta raíz */
    InodosTable root_inode;
    fseek(file, super_bloque.s_inode_start, SEEK_SET);
    fread(&root_inode, sizeof(InodosTable), 1, file);

    // std::cout << _content << std::endl;

    /* Lectura de la última carpeta padre */
    FolderReference fr;
    std::vector<std::string> folders = SplitPath(_path);
    for (int i = 0; i < folders.size(); i++) {
        fr = getFatherReference(fr, folders[i], file, super_bloque.s_inode_start, super_bloque.s_block_start);
        if (fr.inode == -1) {
            // std::cout << "Not found: " + folders[i] + "\n";
            coutError("Error: la ruta no existe y no se ha indicado el comando -r.", file);
        }
    }

    /* Lectura del inodo de carpeta padre */
    InodosTable inode_father;
    fseek(file, super_bloque.s_inode_start, SEEK_SET);
    fseek(file, fr.inode * sizeof(InodosTable), SEEK_CUR);
    fread(&inode_father, sizeof(InodosTable), 1, file);
    if (!HasPermission(_user_logged, inode_father, 6))
        return coutError("El usuario no posee los permisos de lectura y escritura sobre la carpeta padre.", file);
    if (!fileExists(inode_father, _name, file, super_bloque.s_block_start))
        return coutError("El archivo '" + _name + "' no se encuentra en la ruta: " + _path + ".", file);

    /* Lectura del bloque de carpeta padre */
    CarpetasBlock file_block_tmp;
    int _index_to_edit_inode = -1;
    bool x = false;
    // falta indirectos
    for (int i = 0; i < 15 && !x; i++) {
        if (inode_father.i_block[i] != -1) {
            fseek(file, super_bloque.s_block_start, SEEK_SET);
            fseek(file, inode_father.i_block[i] * 64, SEEK_CUR);
            fread(&file_block_tmp, 64, 1, file);
            for (int j = 0; j < 4; j++) {
                if (std::string(file_block_tmp.b_content[j].b_name) == _name) {
                    _index_to_edit_inode = file_block_tmp.b_content[j].b_inodo;
                    x = true;
                    break;
                }
            }
        }
    }
    if (!x)
        return coutError("No se halló el inodo del archivo a editar.", file);

    InodosTable inode_current; // Leer el inodo de archivo que sólo posee bloques de contenido
    fseek(file, super_bloque.s_inode_start, SEEK_SET);
    fseek(file, _index_to_edit_inode * sizeof(InodosTable), SEEK_CUR);
    fread(&inode_current, sizeof(InodosTable), 1, file);

    inode_current.i_s = _content.length();
    inode_current.i_mtime = getCurrentTime();
    /* Llenar con la información del archivo */
    ArchivosBlock tmp_content_block;
    std::string tmp = "";
    for (int i = 0; i < 15; i++) //falta indirectos
    {
        if (_content.length() > 64) {
            tmp = _content.substr(0, 64);
            _content = _content.substr(64);
        } else {
            tmp = _content;
            _content = "";
        }
        /* Reutiliza el mismo bloque */
        if (inode_current.i_block[i] != -1 && tmp.length() > 0) {
            strcpy(tmp_content_block.b_content, tmp.c_str());
            fseek(file, super_bloque.s_block_start, SEEK_SET);
            fseek(file, inode_current.i_block[i] * 64, SEEK_CUR);
            fwrite(&tmp_content_block, 64, 1, file);
            /* Crea otro bloque en caso exceda el tamaño anterior */
        } else if (inode_current.i_block[i] == -1 &&
                   tmp.length() > 0) {
            strcpy(tmp_content_block.b_content, tmp.c_str());
            fseek(file, super_bloque.s_block_start, SEEK_SET);
            fseek(file, free_block * 64, SEEK_CUR);
            fwrite(&tmp_content_block, 64, 1, file);
            inode_current.i_block[i] = free_block;
            bm_blocks[free_block] == '1';
            free_block++;
            super_bloque.s_first_blo = free_block;
            super_bloque.s_free_blocks_count--;
            /* El archivo era más grande y se liberan los bloques */
        } else if (inode_current.i_block[i] != -1 &&
                   tmp.length() == 0) {
            strcpy(tmp_content_block.b_content, "");
            fseek(file, super_bloque.s_block_start, SEEK_SET);
            fseek(file, inode_current.i_block[i] * 64, SEEK_CUR);
            fwrite(&tmp_content_block, 64, 1, file);
            bm_blocks[inode_current.i_block[i]] = '0';
            // free_block = inode_current.i_block[i];
            // super_bloque.s_first_blo = free_block;
            super_bloque.s_free_blocks_count++;
            inode_current.i_block[i] = -1;
        }
    }

    /* ESCRITURA */
    fseek(file, start_byte_sb, SEEK_SET);
    fwrite(&super_bloque, sizeof(Superbloque), 1, file);

    fseek(file, super_bloque.s_bm_block_start, SEEK_SET);
    fwrite(&bm_blocks, 3 * super_bloque.s_inodes_count, 1, file);

    fseek(file, super_bloque.s_inode_start, SEEK_SET); // Mover el puntero al inicio de la tabla de inodos
    fseek(file, _index_to_edit_inode * sizeof(InodosTable), SEEK_CUR);
    fwrite(&inode_current, sizeof(InodosTable), 1, file);

    fclose(file);
    file = NULL;
    // std::cout << "Se editó el archivo: " + _path + "/" + _name + "\n";
}





