#ifndef SETTINGS_H
#define SETTINGS_H

#include <QSettings>

using namespace std;
/*!
\enum SettingKeys
This type describe all possible setting keys
*/
enum SettingKeys{
    FirstRun,
    AbsolutePaths,
    IpAddresses,
    MacAddresses
};

/*!
 * \class Settings
 * \brief The Settings is consist of member functions that load and save user settings with the help of QSettings
 * \since v 0.0.1
 */
class Settings
{
public:
    /*!
    \fn Settings()
    Default Constructs
    */
    Settings();
    /*!
    \fn void saveSettings(bool firstRun, bool anonymizeAbsolutePath, bool anonymizeIpAddresses, bool macAddresses);
    Saves updated settings using QSettings
    */
    void saveSettings(bool firstRun, bool anonymizeAbsolutePath, bool anonymizeIpAddresses, bool macAddresses);
    /*!
    \fn array<bool, 4> loadSettings()
    Loads saved settings using QSettings
    Returns array<bool, 4>
    */
    array<bool, 4> loadSettings();
    /*!
    \fn string enumToString(SettingKeys key);
    Returns string for each value in \enum SettingKeys
    */
    string enumToString(SettingKeys key);

private:
    /*!
    Boolean member variable that stores whether it if first application run or not
    */
    bool notFirstRun;
    /*!
    Boolean member variable that stores whether to hide absolute paths or not
    */
    bool hideAbsPaths;
    /*!
    Boolean member variable that stores whether to hide IP addresses or not
    */
    bool hideIps;
    /*!
    Boolean member variable that stores whether to hide MAC addresses or not
    */
    bool hideMacs;
    /*!
    Boolean Array member variable that stores all other boolean settings member variables
    */
    array<bool, 4> boolSettings;
};

#endif // SETTINGS_H
