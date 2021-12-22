#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>
#include <settings.h>

using namespace std;

namespace Ui {

class SettingsDialog;
}

/*!
 * \class SettingsDialog
 * \brief The SettingsDialog is child of QDialog which provides UI for the Settings Dialog
 * \since v 0.0.1
 */
class SettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsDialog(QWidget *parent = nullptr);
    ~SettingsDialog();

private slots:
    /*!
     \fn void on_buttonBox_accepted();
     Save updated settings
    */
    void on_buttonBox_accepted();

private:
    Ui::SettingsDialog *ui;
    /*!
     \fn void setupCheckboxesUsingSavedSettings();
     Initialize checkbox check state using saved settings
    */
    void setupCheckboxesUsingSavedSettings();

    /*!
    Pointer to a instance of \class Settings
    which is used retrieve user settings
    in order to intilize checkbox check states
    */
    Settings *settings;

};

#endif // SETTINGSDIALOG_H
