
#ifndef MIA_PROYECTO1_201901758_2S2022_REPORTHANDLER_H
#define MIA_PROYECTO1_201901758_2S2022_REPORTHANDLER_H


#include <string>

class ReportHandler {
public:
    ReportHandler(std::string _name, std::string _path, std::string _id, std::string _ruta);

    std::string _name;
    std::string _path;
    std::string _id;
    std::string _ruta;

    void executeReportHandler();

};


#endif //MIA_PROYECTO1_201901758_2S2022_REPORTHANDLER_H
