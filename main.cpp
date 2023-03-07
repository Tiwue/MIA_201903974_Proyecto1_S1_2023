#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <thread>
#include "Analyzer/driver.h"
#include <bits/stdc++.h>
#include "Utils/Variables.h"
#include <boost/algorithm/string.hpp>


void executeCommand(std::string path);
void executeAnalyzer(std::string fileName);

int main() {
    number_id = 2;
    system("clear");
    std::string input, output;
    std::string filename = "command.txt";
    while (true) {
        std::cout<< "INICIO "<<std::endl;
        std::cout<<">> ";

        getline(std::cin, input);

        if (strstr(input.c_str(), std::string("execute").c_str())) {
            int size1 = input.length();
            int size2 = input.size();
            std::string path = input.substr(input.find(">path=") + 6);
            boost::trim(path);
            if(path[0]=='"'){
                path = path.substr(1,path.length()-2);
            }

            executeCommand(path);
            continue;
        }
        if (input == "exit" || input == "quit")
            return 0;
        if (input == "cls" || input == "clear") {
            system("clear");
            continue;
        }
        if (input == "")
            continue;

        std::ofstream MyFile(filename);
        MyFile << input;
        MyFile.close();

        executeAnalyzer(filename);
    }
}


void executeAnalyzer(std::string filename){
    parser_driver driver;
    std::cout << "\033[1;32mLLamada analizador\033[0m\n";
    if (driver.parse(filename))
        std::cout << "\033[1;32mSuccessfully\033[0m\n";
}


void executeCommand(std::string _path) {
    std::ifstream file(_path);
    std::cout << _path<<std::endl;
    std::string line;
    std::string filename = "exec.txt";
    while (std::getline(file, line)) {
        if (line != "" && line[0] != '#') {
            std::cout << std::endl;
            std::cout << ">> " + line << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(350));
            std::ofstream MyFile(filename);
            MyFile << line;
            MyFile.close();
            executeAnalyzer(filename);
        }
    }
}
//execute >path="/home/steven/Escritorio/Protecto1_2023/MIA_201903974_Proyecto1_S1_2023/Script.eea"