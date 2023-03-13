#ifndef HANDLER
#define HANDLER

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <fstream>
#include <cstdlib>
#include <experimental/filesystem>
#include "AdminStructure.h"


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


char charFormat(std::string _format);

int _2_or_3fs(std::string _fs);

int number_inodos(int _part_size, int _ext);

std::string getData(Group _group, User _user);

int startByteSuperBloque(ParticionesMontadas _mounted);

std::string ReadFile(int _index_inode, int _s_inode_start, int _s_block_start, std::string _path);

Group getGroupByName(std::string _name, InodosTable users_inode, int s_block_start, std::string _path);

std::string GetAllFile(InodosTable _inode, int _s_block_start, std::string _path);

int ByteLastFileBlock(InodosTable _inode);

void writeBlocks(std::string _content, int _number_inode);

int writeBlock(int _type, std::string _content, int _block_reference);

void UpdateInode(int _inode_index, int _block_written);

std::vector<std::string> Separate64Chars(std::string _content);
#endif