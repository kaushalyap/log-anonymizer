#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "./settingsdialog.h"
#include "./aboutdialog.h"
#include <string>
#include "./ClipboardXX.hpp"
#include <iostream>
#include <QDebug>
#include <QMessageBox>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui -> lEditProjectDirName -> setVisible(false);
    initializeDefaultSettings();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete settings;
}

void MainWindow::initializeDefaultSettings(){
    qDebug("settings->loadSettings()[0] : %d\n", settings->loadSettings()[0]);

    // if first run
    if(!settings->loadSettings()[0]){
        settings->saveSettings(true, false, true, true);
        qDebug("Initialized default settings!");
    }
    else{
        qDebug("Default settings already initialized!");
    }
}

// button clicked events

void MainWindow::on_btnAnonymize_clicked()
{
    validateAnonymize();
}

void MainWindow::on_btnCopyToClipboard_clicked()
{
    copyTextToClipboard();
}

// menu action trigger events

void MainWindow::on_actionSettings_triggered()
{
    SettingsDialog settingstDialog;
    settingstDialog.setModal(true);
    settingstDialog.exec();
}

void MainWindow::on_actionExit_triggered()
{
    this -> close();
}

void MainWindow::on_actionAnonymize_triggered()
{
    validateAnonymize();
}

void MainWindow::on_actionClear_triggered()
{
    ui -> pTxtEditInput -> clear();
    ui -> pTxtEditOutput -> clear();
}

void MainWindow::on_actionCopy_to_Clipboard_triggered()
{
    copyTextToClipboard();
}

void MainWindow::on_actionAbout_triggered()

// checkbox state change events
{
    AboutDialog aboutDialog;
    aboutDialog.setModal(true);
    aboutDialog.exec();
}

void MainWindow::on_cbHideProjectName_stateChanged(int cbState)
{
    qDebug("cb state change %d", cbState);
    if(cbState==2){
        ui -> lEditProjectDirName -> setVisible(true);
    }
    else if(cbState == 0){
        ui -> lEditProjectDirName -> setText("");
        ui -> lEditProjectDirName -> setVisible(false);
    }
}

// reusable UI methods

void MainWindow::showProjectNameEmptyErrorMessage(){
    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Critical);
    msgBox.setWindowTitle("Error");
    msgBox.setText("Please fill in the project directory name");
    msgBox.exec();
}

void MainWindow::copyTextToClipboard(){

    CClipboardXX clipboard;

    QString anonymizedLogText = ui -> pTxtEditOutput -> toPlainText();
    string stdString = anonymizedLogText.toStdString();
    clipboard << stdString;
    qDebug("Following annonymized log were copied to the clipboard : \n %s", stdString.c_str());
}

void MainWindow::anonymizeInputDisplayOutput(){
    string input = ui-> pTxtEditInput -> toPlainText().toStdString();
    string projectName = ui -> lEditProjectDirName -> text().toStdString();
    string output = anonymizer.anonymize(input, projectName);
    ui -> pTxtEditOutput -> setPlainText(QString::fromStdString(output));
}

void MainWindow::validateAnonymize(){
    (ui->cbHideProjectName -> isChecked() && ui->lEditProjectDirName -> text().isEmpty())?
        showProjectNameEmptyErrorMessage():
        anonymizeInputDisplayOutput();
}
