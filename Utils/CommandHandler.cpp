#include <iostream>
#include <string>
#include "../Utils/Builder.h"

#include "../Disks/MkDisk.h"
#include "../Disks/RmDisk.h"
#include "../Partitions/FDisk.h"
#include "../Partitions/Mount.h"
#include "../Partitions/UnMount.h"
#include "../FileSystem/Mkfs.h"
#include "../FileSystem/Login.h"
#include "../FileSystem/Logout.h"


#include "../Reports/ReportHandler.h"
#include "Functions.h"



int CommandHandler(struct command x) {

    if (x.keyword == "__MKDISK") {
        MkDisk *mkDisk = new MkDisk(x.path, x.size, x.fit, x.unit);
    } else if (x.keyword == "__RMDISK") {
        RmDisk *rmDisk = new RmDisk(x.path);
    }else if (x.keyword == "__FDISK") {
        FDisk *fdisk = new FDisk(x.size, x.unit, x.path, x.type, x.fit, x.delet,x.name, x.add);
    } else if (x.keyword == "__REP") {
        ReportHandler *rpHandler = new ReportHandler(x.name, x.path, x.id, x.ruta);
    } else if (x.keyword == "__MOUNT") {
        Mount *mount = new Mount(x.path, x.name);
    }else if (x.keyword == "__UMOUNT") {
        UnMount *unMount = new UnMount(x.id);
    }else if (x.keyword == "__MKFS") {
        Mkfs *mkfs = new Mkfs(x.id, x.type, x.fs);
    }else if (x.keyword == "__LOGIN") {
        Login *login = new Login(x.user, x.pwd, x.id);
    } else if (x.keyword == "__LOGOUT") {
        Logout *logout = new Logout();
    }
    return 1;
}


