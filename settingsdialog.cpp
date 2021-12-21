#include "settingsdialog.h"
#include "ui_settingsdialog.h"


SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);
    setupCheckboxesUsingSavedSettings();
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}

void SettingsDialog::setupCheckboxesUsingSavedSettings(){
    array<bool,4> boolSettings = settings -> loadSettings();
    if(boolSettings[1]== true){
        ui ->cbHideAbsPaths->setChecked(true);
    }
    if(boolSettings[2]== true){
        ui ->cbHideIpAddresses->setChecked(true);
    }
    if(boolSettings[3]== true){
        ui ->cbHideMac->setChecked(true);
    }
}

void SettingsDialog::on_buttonBox_accepted()
{
    bool hideAbsPaths = ui->cbHideAbsPaths -> isChecked();
    bool hideIps = ui->cbHideIpAddresses ->isChecked();
    bool hideMacs = ui -> cbHideMac -> isChecked();
    settings -> saveSettings(true, hideAbsPaths, hideIps, hideMacs);
}

