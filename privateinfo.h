#ifndef PRIVATEINFO_H
#define PRIVATEINFO_H
#include <string>
#include <QDir>

using namespace std;

class PrivateInfo
{
public:
    PrivateInfo();
    string getOS();
    string getHomeDirectory();

};

#endif // PRIVATEINFO_H
