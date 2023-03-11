
#include "ReportFunctions.h"
#include <iostream>
#include <fstream>


std::string getBaseHeader() {
    std::string graph =
            std::string("digraph G {\n") +
            +"graph[margin=0]\n" +
            +"rankdir=\"TB\";\n" +
            +"node [shape=plaintext fontname= \"Ubuntu\" fontsize=\"14\"];\n" +
            +"edge [style=\"invis\"];\n\n";
    return graph;
}

void writeDot(std::string _dot) {
    std::ofstream MyFile("./Results/report.dot");
    MyFile << _dot;
    MyFile.close();
}

void generateReport(std::string _path) {
    std::string extension = _path.substr(_path.find_last_of('.') + 1);
    std::string syst = "dot -T" + extension + " " + "./Results/report.dot" + " -o " + _path;
    system(syst.c_str());
}


