#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <settings.h>
#include <anonymizer.h>

QT_BEGIN_NAMESPACE

namespace Ui { class MainWindow; }

QT_END_NAMESPACE

/*!
 * \class MainWindow
 * \brief The MainWindow is child of QMainWindow which provides UI for the MainWindow
 * \since v 0.0.1
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    /*!
    \fn void on_btnAnonymize_clicked();
    Uses \fn void validateAnonymize() and
    \fn void anonymizeInputDisplayOutput();
    */
    void on_btnAnonymize_clicked();
    /*!
    \fn void on_btnCopyToClipboard_clicked();
    Uses \fn void copyTextToClipboard();
    */
    void on_btnCopyToClipboard_clicked();

    /*!
    \fn void on_actionExit_triggered();
    Closes the application
    */
    void on_actionExit_triggered();
    /*!
    \fn void on_actionSettings_triggered();
    Opens \class SettingsDialog
    */
    void on_actionSettings_triggered();
    /*!
    \fn void on_actionCopy_to_Clipboard_triggered();
    Copies output text to the clipboard
    uses \fn void copyTextToClipboard();
    */
    void on_actionCopy_to_Clipboard_triggered();
    /*!
    \fn void on_actionAbout_triggered();
    Displays \class AboutDialog
    */
    void on_actionAbout_triggered();
    /*!
    \fn void on_actionAnonymize_triggered();
    Uses \fn void validateAnonymize(); and
    \fn void anonymizeInputDisplayOutput();
    */
    void on_actionAnonymize_triggered();
    /*!
    \fn void on_actionClear_triggered();
    Clears input and output text fields
    */
    void on_actionClear_triggered();
    /*!
    \fn void on_btnAnonymize_clicked();
    Handle visibility of Project Directory Name text field
    depending on the checked state
    */
    void on_cbHideProjectName_stateChanged(int cbState);

private:
    Ui::MainWindow *ui;
    /*!
    Pointer to a instance of \class Settings
    which is used retrieve user settings
    */
    Settings *settings;
    /*!
    Pointer to a instance of \class Anonymizer
    which is used to call anonymize to anonymize  input logs
    */
    Anonymizer anonymizer;
    /*!
      \fn void initializeDefaultSettings()
      Initialized default settings on first run and set the first run flag in settings
      using loadSettings and saveSettings member functions from \class Settings
     */
    void initializeDefaultSettings();
    /*!
      \fn void showProjectNameEmptyErrorMessage()
      Shows error message when hide project directory name checkbox is checked and
      project directory name field is empty
     */
    void showProjectNameEmptyErrorMessage();
    /*!
      \fn void copyTextToClipboard()
      Copy output text to the clipboard in a crossplatform compatible way
      using a third party code borrowed
      from https://github.com/Arian8j2/ClipboardXX/blob/master/include/ClipboardXX.hpp
     */
    void copyTextToClipboard();
    /*!
      \fn void anonymizeInputDisplayOutput()
      Anonymize input text using anonymize function from Anonymizer \class
      and set returned output to the output field
     */
    void anonymizeInputDisplayOutput();
    /*!
      \fn void validateAnonymize()
      Check if the project directory name is empty
      inorder to call anonymize function of \class Anonymize
     */
    void validateAnonymize();
};
#endif // MAINWINDOW_H
