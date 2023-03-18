
#include "Inode.h"

Inode::Inode(ParticionesMontadas mounted) {
    this->mounted = mounted;
}


std::string Inode::getReport() {
    std::string grafo = getBaseHeader();
    FILE *file = fopen(mounted.path.c_str(), "rb+");

    /* Lectura del superbloque */
    int start_byte_sb = startByteSuperBloque(mounted);
    Superbloque super_bloque;
    fseek(file, start_byte_sb, SEEK_SET);
    fread(&super_bloque, sizeof(Superbloque), 1, file);

    grafo += std::string("\"Inodes Report\" [margin=\"0.5\" label = <\n") +
             "<TABLE BGCOLOR=\"white\" BORDER=\"2\" COLOR=\"BLACK\" CELLBORDER=\"1\" CELLSPACING=\"0\">\n" +
             "<TR>\n" +
             "<TD HEIGHT=\"25\" BGCOLOR=\"#B8860B\" COLSPAN=\"2\">REPORTE DE INODOS</TD>\n" +
             "</TR>\n\n";
    int first_inode = 0;
    grafo += getDotInode(file, 0, super_bloque.s_inode_start, super_bloque.s_block_start, "", "");
    grafo += "</TABLE>>];\n}";

    fclose(file);
    file = NULL;
    return grafo;
}


std::string Inode::getDotInode(FILE *_file, int _index_inode, int _start_inodes, int _start_blocks, std::string _dot,
                               std::string _name) {
    /* Leer lo que está dentro de la carpeta */


    InodosTable inode_current;
    fseek(_file, _start_inodes, SEEK_SET);
    fseek(_file, _index_inode * sizeof(InodosTable), SEEK_CUR);
    fread(&inode_current, sizeof(InodosTable), 1, _file);
    /* Agregar al dot */
   // std::string i_atime1 = ctime(&inode_current.i_atime);
    //std::string i_ctime1 = ctime(&inode_current.i_ctime);
    //std::string i_mtime1 = ctime(&inode_current.i_mtime);
    _dot += std::string ("<TR>\n") +
                         "<TD colspan=\"2\" BGCOLOR=\"brown1\" ALIGN=\"center\">Inodo_"+std::to_string(_index_inode)+"</TD>\n" +
                         "</TR>\n\n" +
                        "<TR>\n" +
                        "<TD HEIGHT=\"30\" >i_uid</TD>\n" +
                        "<TD WIDTH=\"100\" >"+std::to_string(inode_current.i_uid)  +"</TD>\n" +
                        "</TR>\n\n" +
                        "<TR>\n" +
                        "<TD HEIGHT=\"30\" >I_gid</TD>\n" +
                        "<TD WIDTH=\"100\" >"+std::to_string(inode_current.i_gid)  +"</TD>\n" +
                        "</TR>\n\n" +
                        "<TR>\n" +
                        "<TD HEIGHT=\"30\" >i_s</TD>\n" +
                        "<TD WIDTH=\"100\" >"+std::to_string(inode_current.i_s)  +"</TD>\n" +
                        "</TR>\n\n" +
                        "<TR>\n" +
                        "<TD HEIGHT=\"30\" >i_atime</TD>\n" +
                        "<TD WIDTH=\"100\" >" +ctime(&inode_current.i_atime) +"</TD>\n" +
                        "</TR>\n\n" +
                        "<TR>\n" +
                        "<TD HEIGHT=\"30\" >i_ctime</TD>\n" +
                        "<TD WIDTH=\"100\" >"+ctime(&inode_current.i_ctime) +"</TD>\n" +
                        "</TR>\n\n" +
                        "<TR>\n" +
                        "<TD HEIGHT=\"30\" >i_mtime</TD>\n" +
                        "<TD WIDTH=\"100\" >"+ctime(&inode_current.i_mtime) +"</TD>\n" +
                        "</TR>\n\n" ;
                        for(int i = 0; i < 15; i++){
                            _dot += std::string ("<TR>\n") +
                                    "<TD>i_block_"+std::to_string(i)+"</TD>\n" +
                                    "<TD>"+std::to_string(inode_current.i_block[i])+"</TD>\n" +
                                    "</TR>\n\n";
                        }
                        _dot += std::string ("<TR>\n") +
                        "<TD>i_type</TD>\n" +
                        "<TD>"+std::to_string(inode_current.i_type)+"</TD>\n" +
                        "</TR>\n\n"+
                        "<TR>\n" +
                        "<TD>i_perm</TD>\n" +
                        "<TD>"+std::to_string(inode_current.i_perm)+"</TD>\n" +
                        "</TR>\n\n";

    if (inode_current.i_type == 0) {
        CarpetasBlock file_block;
        for (int i = 0; i < 15; i++) // falta indirectos
        {
            if (inode_current.i_block[i] !=
                -1) { /* Leer el bloque y redireccionar al inodo y ver si de nuevo es otra carpeta */
                fseek(_file, _start_blocks, SEEK_SET);
                fseek(_file, inode_current.i_block[i] * 64, SEEK_CUR);
                fread(&file_block, 64, 1, _file);
                for (int j = 0; j < 4; j++) {
                    _name = file_block.b_content[j].b_name;
                    if (file_block.b_content[j].b_inodo > 0 && file_block.b_content[j].b_inodo != _index_inode &&
                        std::string(_name) != ".." && std::string(_name) != ".") {
                        // std::cout << _name << std::endl;
                        _index_inode = file_block.b_content[j].b_inodo;
                        _dot = getDotInode(_file, _index_inode, _start_inodes, _start_blocks, _dot, _name);

                    }
                }
            }
        }
    }
    return _dot;
}
