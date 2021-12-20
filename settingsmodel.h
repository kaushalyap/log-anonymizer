#ifndef SETTINGSMODEL_H
#define SETTINGSMODEL_H

#include <QSettings>
#include <QtGui>

using namespace std;

enum SettingKeys{
    AbsolutePaths,
    ProjectNames
};

class SettingsModel
{
public:
    SettingsModel();
    void SaveSettings(bool anonymizeAbsolutePath, bool anonymizeProjectNames);
    array<bool, 2> LoadSettings();
    string enum_to_string(SettingKeys key);
private:
    QSettings settings;


};

#endif // SETTINGSMODEL_H
