#include "settings.h"

Settings::Settings()
{

}

array<bool, 4> Settings::loadSettings(){
    QSettings settings("ExampleCompany", "LogAnonymizer");
    settings.beginGroup("SettingsDialog");
    bool notFirstRun = settings.value(QString::fromStdString(enumToString(FirstRun))).toBool();
    bool hideAbsPaths = settings.value(QString::fromStdString(enumToString(AbsolutePaths))).toBool();
    bool hideIps = settings.value(QString::fromStdString(enumToString(IpAddresses))).toBool();
    bool hideMacs = settings.value(QString::fromStdString(enumToString(MacAddresses))).toBool();
    array<bool, 4> boolSettings;
    boolSettings[0] = notFirstRun;
    boolSettings[1] = hideAbsPaths;
    boolSettings[2] = hideIps;
    boolSettings[3] = hideMacs;
    qDebug("Loading settings:");
    qDebug("Is not first run : %d", notFirstRun);
    qDebug("Annonymize Abs. Paths : %d, IPs %d, MACs : %d \n", hideAbsPaths, hideIps, hideMacs);
    settings.endGroup();
    return boolSettings;
}

void Settings::saveSettings(bool firstRun, bool hideAbsPath, bool hideIps, bool hideMacs){
    QSettings settings("ExampleCompany", "LogAnonymizer");
    settings.beginGroup("SettingsDialog");
    settings.setValue(QString::fromStdString(enumToString(FirstRun)), firstRun);
    settings.setValue(QString::fromStdString(enumToString(AbsolutePaths)), hideAbsPath);
    settings.setValue(QString::fromStdString(enumToString(IpAddresses)), hideIps);
    settings.setValue(QString::fromStdString(enumToString(MacAddresses)), hideMacs);
    qDebug("Saving settings:");
    qDebug("Annonymize Abs. Paths : %d, IPs : %d , MACs : %d \n", hideAbsPath, hideIps, hideMacs);
    settings.endGroup();
}

string Settings::enumToString(SettingKeys key){
    switch(key){
        case FirstRun: return "first-run";
        case AbsolutePaths: return "hide-abs-paths";
        case IpAddresses: return "hide-ip-addresses";
        case MacAddresses: return "hide-mac-addresses";
        default: return "invalid key";
    }
}
