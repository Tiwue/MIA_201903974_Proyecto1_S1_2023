#include <iostream>
#include <string>
#include "../Utils/Builder.h"

#include "../Disks/MkDisk.h"
#include "../Disks/RmDisk.h"

#include "Functions.h"



int CommandHandler(struct command x) {

    if (x.keyword == "__MKDISK") {
        MkDisk *mkDisk = new MkDisk(x.path, x.size, x.fit, x.unit);
    } else if (x.keyword == "__RMDISK") {
        RmDisk *rmDisk = new RmDisk(x.path);
    }
    return 1;
}


