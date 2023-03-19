#include "SB.h"
#include "../Disks/DiskFunctions.h"



SB::SB(ParticionesMontadas mounted) {
    this->mounted = mounted;
}

std::string SB::getReport() {
    std::string grafo = getBaseHeader();
    FILE *file = fopen(mounted.path.c_str(), "rb");

    /* Lectura del superbloque */
    Superbloque super_bloque;
    fseek(file, startByteSuperBloque(mounted), SEEK_SET);
    fread(&super_bloque, sizeof(Superbloque), 1, file);
    fclose(file);
    file = NULL;
    std::string s_mtime = ctime(&super_bloque.s_mtime);
    std::string s_umtime = ctime(&super_bloque.s_umtime);
    // std::cout << s_umtime.substr(s_umtime.length() - 5) << std::endl;
    if (s_umtime.substr(s_umtime.length() - 5) == "1969\n")
        s_umtime = "-";
    std::string dot =
            std::string("\"SB Report\" [ margin=\"1\" label = <\n") +
            "<TABLE BGCOLOR=\"white\" BORDER=\"2\" COLOR=\"BLACK\" CELLBORDER=\"1\" CELLSPACING=\"0\">\n" +
            "<TR>\n" +
            "<TD BGCOLOR=\"#d03939\" COLSPAN=\"2\">REPORTE DE SUPERBLOQUE</TD>\n" +
            "</TR>\n\n" +

            "<TR>\n" +
            "<TD WIDTH=\"150\" BGCOLOR=\"#ff4660\"><B>Nombre</B></TD>\n" +
            "<TD BGCOLOR=\"#ff4660\"><B>Valor</B></TD>\n" +
            "</TR>\n\n" +

            "<TR>\n" +
            "<TD ALIGN=\"left\">s_filesystem_type</TD>\n" +
            "<TD>" + std::to_string(super_bloque.s_filesystem_type) + "</TD>\n" +
            "</TR>\n\n" +

            "<TR>\n" +
            "<TD ALIGN=\"left\">s_inodes_count</TD>\n" +
            "<TD>" + std::to_string(super_bloque.s_inodes_count) + "</TD>\n" +
            "</TR>\n\n" +

            "<TR>\n" +
            "<TD ALIGN=\"left\">s_blocks_count</TD>\n" +
            "<TD>" + std::to_string(super_bloque.s_blocks_count) + "</TD>\n" +
            "</TR>\n\n" +

            "<TR>\n" +
            "<TD ALIGN=\"left\">s_free_inodes_count</TD>\n" +
            "<TD>" + std::to_string(super_bloque.s_free_inodes_count) + "</TD>\n" +
            "</TR>\n\n" +

            "<TR>\n" +
            "<TD ALIGN=\"left\">s_free_blocks_count</TD>\n" +
            "<TD>" + std::to_string(super_bloque.s_free_blocks_count) + "</TD>\n" +
            "</TR>\n\n" +

            "<TR>\n" +
            "<TD ALIGN=\"left\">s_mtime</TD>\n" +
            "<TD>" + s_mtime + "</TD>\n" +
            "</TR>\n\n" +

            "<TR>\n" +
            "<TD ALIGN=\"left\">s_umtime</TD>\n" +
            "<TD>" + s_umtime + "</TD>\n" +
            "</TR>\n\n" +

            "<TR>\n" +
            "<TD ALIGN=\"left\">s_mnt_count</TD>\n" +
            "<TD>" + std::to_string(super_bloque.s_mnt_count) + "</TD>\n" +
            "</TR>\n\n" +

            "<TR>\n" +
            "<TD ALIGN=\"left\">s_magic</TD>\n" +
            "<TD>" + std::to_string(super_bloque.s_magic) + "</TD>\n" +
            "</TR>\n\n" +

            "<TR>\n" +
            "<TD ALIGN=\"left\">s_inode_size</TD>\n" +
            "<TD>" + std::to_string(super_bloque.s_inode_s) + "</TD>\n" +
            "</TR>\n\n" +

            "<TR>\n" +
            "<TD ALIGN=\"left\">s_block_size</TD>\n" +
            "<TD>" + std::to_string(super_bloque.s_block_s) + "</TD>\n" +
            "</TR>\n\n" +

            "<TR>\n" +
            "<TD ALIGN=\"left\">s_first_ino</TD>\n" +
            "<TD>" + std::to_string(super_bloque.s_first_ino) + "</TD>\n" +
            "</TR>\n\n" +

            "<TR>\n" +
            "<TD ALIGN=\"left\">s_first_blo</TD>\n" +
            "<TD>" + std::to_string(super_bloque.s_first_blo) + "</TD>\n" +
            "</TR>\n\n" +

            "<TR>\n" +
            "<TD ALIGN=\"left\">s_bm_inode_start</TD>\n" +
            "<TD>" + std::to_string(super_bloque.s_bm_inode_start) + "</TD>\n" +
            "</TR>\n\n" +

            "<TR>\n" +
            "<TD ALIGN=\"left\">s_bm_block_start</TD>\n" +
            "<TD>" + std::to_string(super_bloque.s_bm_block_start) + "</TD>\n" +
            "</TR>\n\n" +

            "<TR>\n" +
            "<TD ALIGN=\"left\">s_inode_start</TD>\n" +
            "<TD>" + std::to_string(super_bloque.s_inode_start) + "</TD>\n" +
            "</TR>\n\n" +

            "<TR>\n" +
            "<TD ALIGN=\"left\">s_block_start</TD>\n" +
            "<TD>" + std::to_string(super_bloque.s_block_start) + "</TD>\n" +
            "</TR>\n\n" +

            "</TABLE>>];\n\n}";

    grafo += dot;
    return grafo;
}

