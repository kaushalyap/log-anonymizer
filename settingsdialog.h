#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>
#include <settingsmodel.h>

namespace Ui {
class SettingsDialog;
}

class SettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsDialog(QWidget *parent = nullptr);
    ~SettingsDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::SettingsDialog *ui;
    void SaveSettings();
    void LoadSettings();
    void setupCheckboxesUsingSavedSettings();
    SettingsModel *settingsModel;

};

#endif // SETTINGSDIALOG_H
