#include "settingsdialog.h"
#include "ui_settingsdialog.h"

SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);
    array<bool,2> boolSettings = settingsModel->LoadSettings();
    if(boolSettings[1]== true){

    }
    if(boolSettings[2]== true){
    }
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
    delete settingsModel;
}

void SettingsDialog::on_buttonBox_accepted()
{
    // save settings

}


void setupCheckboxesUsingSavedSettings(){


}
