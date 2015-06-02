#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "game.h"
#include <QDateTime>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupDeckNames();
    configureUI();
    setWindowTitle("HearthLogger");
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


void MainWindow::setupDeckNames(){
    QString fileName = ":/DeckNames.txt";
    if (!fileName.isEmpty()) {
            QFile file(fileName);
            if (!file.open(QIODevice::ReadOnly)) {
                log("Error: Could not open file" + fileName);
                return;
            }
            QTextStream in(&file);
            while(!in.atEnd()){
                QString s = in.readLine();
                QString hero = s.section(":",0,0).trimmed();
                if(!hero.isEmpty()){
                    QStringList decks = s.section(":",1,-1).split(",");
                    heroDecks hDecks;
                    hDecks.hero = hero;
                    hDecks.decks = decks;
                    deckLists.append(hDecks);
                    ui->yourClass->addItem(hero);
                    ui->opponentClass->addItem(hero);
                }
            }
            file.close();
        }
}

void MainWindow::on_submitButton_clicked()
{
    //catch for errors
    Game g;
    g.setYourName(ui->yourName->text());
    if(ui->yourRank->currentText()=="Legendary"){
        g.setYourRank(true,ui->yourLegend->value());
    }
    else{
        g.setYourRank(false,ui->yourRank->currentText().toInt());
    }
    g.setYourClass(ui->yourClass->currentText());
    g.setYourDeck(ui->yourDeck->currentText());
    g.setOpponentName(ui->opponentName->text());
    if(ui->opponentRank->currentText()=="Legendary"){
        g.setOpponentRank(true,ui->opponentLegend->value());
    }
    else{
        g.setOpponentRank(false,ui->opponentRank->currentText().toInt());
    }
    g.setOpponentClass(ui->opponentClass->currentText());
    g.setOpponentDeck(ui->opponentDeck->currentText());
    if(ui->winButton->isChecked()){
        g.setResult(Game::WIN);
    }
    else if(ui->lossButton->isChecked()){
        g.setResult(Game::LOSS);
    }
    else if(ui->tieButton->isChecked()){
        g.setResult(Game::TIE);
    }
    else{
        //freak out
    }
    g.setTime(QDateTime::currentDateTime());
    log(g.toString());
    log(Game::fromString(g.toString()).toString());
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

void MainWindow::on_yourClass_currentIndexChanged(const QString &hero)
{
    for(int i=0;i<deckLists.size();i++){
        if(deckLists.at(i).hero==hero){
            while(ui->yourDeck->count()>0)
                ui->yourDeck->removeItem(0);
            ui->yourDeck->addItems(deckLists.at(i).decks);
        }
    }
}

void MainWindow::on_opponentClass_currentIndexChanged(const QString &hero)
{
    for(int i=0;i<deckLists.size();i++){
        if(deckLists.at(i).hero==hero){
            while(ui->opponentDeck->count()>0)
                ui->opponentDeck->removeItem(0);
            ui->opponentDeck->addItems(deckLists.at(i).decks);
        }
    }
}


