#ifndef PRIVATEINFO_H
#define PRIVATEINFO_H
#include <string>
#include <QDir>

using namespace std;

/*!
 * \class PrivateInfo
 * \brief The PrivateInfo is consist of member functions that retrieve  private information like OS, user home directory
 * \since v 0.0.1
 */
class PrivateInfo
{
public:
    /*!
    \fn PrivateInfo()
    Default Constructs
    */
    PrivateInfo();
    /*!
    \fn string getOS();
    Get OS version with the help of a Q_OS_ macro
    Returns a string
    */
    string getOS();
    /*!
    \fn string getHomeDirectory();
    get home directory path in linux using
    QDir::homePath()
    Returns a string
    */
    string getHomeDirectory();
};

#endif // PRIVATEINFO_H
