#include "privateinfo.h"
#include "qglobal.h"

PrivateInfo::PrivateInfo()
{

}

string PrivateInfo::getOS(){
    #ifdef Q_OS_LINUX
        return "linux";
    #endif
    #ifdef Q_OS_WIN32
        return "windows";
    #endif
    #ifdef Q_OS_MACX
         return "macos";
    #endif
}

string PrivateInfo::getHomeDirectory(){
    return QDir::homePath().toStdString();
}
