#ifndef SETTINGS_H
#define SETTINGS_H

#include <QSettings>

using namespace std;

enum SettingKeys{
    FirstRun,
    AbsolutePaths,
    IpAddresses,
    MacAddresses
};

class Settings
{
public:
    Settings();
    void saveSettings(bool firstRun, bool anonymizeAbsolutePath, bool anonymizeIpAddresses, bool macAddresses);
    array<bool, 4> loadSettings();
    string enumToString(SettingKeys key);
};

#endif // SETTINGS_H
