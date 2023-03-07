#ifndef HANDLER
#define HANDLER

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <fstream>
#include <cstdlib>
#include <experimental/filesystem>


namespace fs = std::experimental::filesystem;

static std::string root = "/home/steven/home"; // url raíz

void coutError(std::string err, FILE *_file);

void exitIfItFails(std::string err);

int castSize(std::string _size);

std::string getPath(std::string _path);

std::string getDir(std::string np);

bool isDir(std::string dir);

std::string buildPath(std::string _path);

char getFit(std::string _fit, char _default);

char getUnit(std::string _unit, char _default);

int getSize(char _unit, int _size);

char charType(std::string _type, char _default);

char charDelete(std::string _delete);

time_t getCurrentTime();

#endif