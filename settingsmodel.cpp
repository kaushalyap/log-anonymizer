#include "settingsmodel.h"

SettingsModel::SettingsModel()
{
    QSettings settings("ExampleCompany", "LogAnonymizer");
    settings.beginGroup("SettingsDialog");
}

array<bool, 2> SettingsModel::LoadSettings(){
    bool anonymizeAbsolutePaths = settings.value(QString::fromStdString(enum_to_string(AbsolutePaths))).toBool();
    bool anonymizeProjectNames = settings.value(QString::fromStdString(enum_to_string(AbsolutePaths))).toBool();
    array<bool, 2> boolSettings;
    boolSettings[0] = anonymizeAbsolutePaths;
    boolSettings[1] = anonymizeProjectNames;
    qDebug("Loading settings: \n");
    qDebug("Annonymize Abs. Paths : %d, Anonymize Project Names %d \n", anonymizeAbsolutePaths, anonymizeProjectNames);
    return boolSettings;
}

void SettingsModel::SaveSettings(bool anonymizeAbsolutePaths, bool anonymizeProjectNames){

    settings.value(QString::fromStdString(enum_to_string(AbsolutePaths)), anonymizeAbsolutePaths);
    settings.value(QString::fromStdString(enum_to_string(ProjectNames)), anonymizeProjectNames);
    qDebug("Saving settings: \n");
    qDebug("Annonymize Abs. Paths : %d, Anonymize Project Names %d \n", anonymizeAbsolutePaths, anonymizeProjectNames);
}

string SettingsModel::enum_to_string(SettingKeys key){
    switch(key){
        case AbsolutePaths: return "anonymize-abs-paths";
        case ProjectNames: return "anonymize-project-names";
        default: return "invalid key";
    }
}
