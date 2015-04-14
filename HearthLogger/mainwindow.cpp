#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    configureUI();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::configureUI()
{
    ui->log->setReadOnly(true);
    for(int i=25;i>=1;i--){
        ui->yourRank->addItem(QString::number(i));
        ui->opponentRank->addItem(QString::number(i));
    }
    ui->yourRank->addItem("Legendary");
    ui->yourRank->setStyleSheet("QComboBox { combobox-popup: 0; }");
    ui->yourRank->setMaxVisibleItems(10);
    ui->opponentRank->addItem("Legendary");
    ui->opponentRank->setStyleSheet("QComboBox { combobox-popup: 0; }");
    ui->opponentRank->setMaxVisibleItems(10);

    ui->yourLegend->setMinimum(1);
    ui->yourLegend->setMaximum(10000);
    ui->yourLegend->setAccelerated(true);
    if(ui->yourRank->currentText()=="Legendary"){
        ui->yourLegend->setEnabled(true);
    }
    else{
        ui->yourLegend->setEnabled(false);
    }
    ui->opponentLegend->setMinimum(1);
    ui->opponentLegend->setMaximum(10000);
    ui->opponentLegend->setAccelerated(true);
    if(ui->opponentRank->currentText()=="Legendary"){
        ui->opponentLegend->setEnabled(true);
    }
    else{
        ui->opponentLegend->setEnabled(false);
    }
}
void MainWindow::log(QString text)
{
    QDateTime now = QDateTime::currentDateTime();
    ui->log->appendPlainText(now.toString("[hh:mm:ss]") + text);
}

void MainWindow::on_submitButton_clicked()
{
    log("buttonclicked");
}

void MainWindow::on_yourRank_activated(const QString &rank)
{
    if(rank=="Legendary"){
        ui->yourLegend->setEnabled(true);
    }
    else{
        ui->yourLegend->setEnabled(false);
    }
}


void MainWindow::on_opponentRank_activated(const QString &rank)
{
    if(rank=="Legendary"){
        ui->opponentLegend->setEnabled(true);
    }
    else{
        ui->opponentLegend->setEnabled(false);
    }
}

