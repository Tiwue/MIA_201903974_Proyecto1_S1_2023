cmake_minimum_required(VERSION 3.24)
project(MIA_201903974_Proyecto1_S1_2023)

set(CMAKE_CXX_STANDARD 17)
link_libraries(stdc++fs)

add_executable(MIA_201903974_Proyecto1_S1_2023 main.cpp Utils/Builder.h Utils/Variables.h Disks/MkDisk.cpp Disks/DiskFunctions.cpp Disks/RmDisk.cpp Utils/Functions.cpp Analyzer/driver.cpp Analyzer/parser.tab.cc Analyzer/position.hh Analyzer/scanner.cpp Analyzer/stack.hh Utils/Variables.cpp Partitions/FDisk.cpp Reports/DiskReport.cpp Reports/ReportHandler.cpp Reports/ReportFunctions.cpp Reports/MBRReport.cpp Partitions/Mount.cpp Partitions/UnMount.cpp FileSystem/Mkfs.cpp Reports/Inode.cpp FileSystem/Login.cpp FileSystem/Logout.cpp FileSystem/MkGrp.cpp FileSystem/RmGrp.h FileSystem/RmGrp.cpp FileSystem/MkUsr.cpp FileSystem/RmUsr.cpp FileSystemAdmin/MkFile.cpp FileSystemAdmin/MkDir.cpp Reports/Block.cpp Reports/BMBlock.cpp Reports/BMInode.cpp Reports/SB.cpp)
