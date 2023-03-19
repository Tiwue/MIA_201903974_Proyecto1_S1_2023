

#include "BMBlock.h"

BMBlock::BMBlock(ParticionesMontadas mounted) {
    this->mounted = mounted;
}

std::string BMBlock::getReport() {
    std::string grafo = getBaseHeader();
    FILE *file = fopen(mounted.path.c_str(), "rb");

    /* Lectura del superbloque */
    int start_byte_sb = startByteSuperBloque(mounted);
    Superbloque super_bloque;
    fseek(file, start_byte_sb, SEEK_SET);
    fread(&super_bloque, sizeof(Superbloque), 1, file);
    fclose(file);
    file = NULL;

    grafo += std::string("\"Block BitMap Report\" [margin=\"1\" fontsize=\"18\" label = <\n") +
             "<TABLE BORDER=\"5\" COLOR=\"BLACK\" CELLBORDER=\"1\" CELLSPACING=\"0\">\n" +
             "<TR>\n" +
             "<TD BORDER=\"0\" HEIGHT=\"35\" BGCOLOR=\"#B8860B\">BITMAP DE BLOQUES</TD>\n" +
             "</TR>\n\n" +
             "<TR>\n" +
             "<TD BORDER=\"0\" WIDTH=\"490\" BGCOLOR=\"#708090\"><B>\n<br/>\n    ";

    int total_blocks = 3 * super_bloque.s_inodes_count;
    int used = total_blocks - super_bloque.s_free_blocks_count;

    /* Agregar al dot */
    for (int i = 0; i < total_blocks; i++) {
        if (i < used)
            grafo += "1    ";
        else
            grafo += "0    ";
        if ((i + 1) % 16 == 0)
            grafo += "<br/><br/>\n    ";
    }
    if (total_blocks % 16 != 0)
        grafo += "<br/>      ";
    grafo.erase(grafo.length() - 5);
    grafo += "<br/></B></TD>\n</TR>\n\n</TABLE>>];\n\n}";

    return grafo;
}

