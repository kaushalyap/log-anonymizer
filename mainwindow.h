#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <settings.h>
#include <anonymizer.h>

QT_BEGIN_NAMESPACE

namespace Ui { class MainWindow; }

QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnAnonymize_clicked();
    void on_btnCopyToClipboard_clicked();

    void on_actionExit_triggered();
    void on_actionSettings_triggered();
    void on_actionCopy_to_Clipboard_triggered();
    void on_actionAbout_triggered();
    void on_actionAnonymize_triggered();
    void on_actionClear_triggered();

private:
    Ui::MainWindow *ui;
    Settings *settings;
    Anonymizer *anonymizer;
    void initializeDefaultSettings();
};
#endif // MAINWINDOW_H
