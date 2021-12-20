#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "./settingsdialog.h"
#include "./aboutdialog.h"
#include <string>
#include "./ClipboardXX.hpp"
#include <iostream>
#include <QDebug>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnAnonymize_clicked()
{
    ui -> pTxtEditOutput -> setPlainText("something cool");
    // anonymize text from input text field
}


void MainWindow::on_btnCopyToClipboard_clicked()
{
    CClipboardXX clipboard;

    QString anonymizedLogText = ui -> pTxtEditOutput -> toPlainText();
    string stdString = anonymizedLogText.toStdString();
    clipboard << stdString;
    qDebug("Following annonymized log were copied to the clipboard : \n %s", stdString.c_str());
}

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

}

void MainWindow::on_actionClear_triggered()
{

    ui -> pTxtEditInput -> clear();

}

void MainWindow::on_actionCopy_to_Clipboard_triggered()
{
    CClipboardXX clipboard;

    QString anonymizedLogText = ui -> pTxtEditOutput -> toPlainText();
    string stdString = anonymizedLogText.toStdString();
    clipboard << stdString;
    qDebug("Following annonymized log were copied to the clipboard : \n %s", stdString.c_str());
}

void MainWindow::on_actionAbout_triggered()
{
    AboutDialog aboutDialog;
    aboutDialog.setModal(true);
    aboutDialog.exec();
}







