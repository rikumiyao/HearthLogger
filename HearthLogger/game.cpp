#include "game.h"
#include <QStringList>
Game::Game()
{
}

QString Game::toString()const {
    QString s = "";
    s += yourName + ",";
    s += yourRank + ",";
    s += yourClass + ",";
    s += yourDeck + ",";
    s += opponentName +",";
    s += opponentRank + ",";
    s += opponentClass + ",";
    s += opponentDeck + ",";
    switch(result){
    case WIN:
        s += "W,";
        break;
    case LOSS:
        s += "L,";
        break;
    case TIE:
        s += "T,";
        break;
    }
    s += QString::number(time.toTime_t());
    return s;
}

Game Game::fromString(const QString s){
    Game g = Game();
    QStringList list = s.split(",");
    g.yourName = list.at(0);
    g.yourRank = list.at(1);
    g.yourClass = list.at(2);
    g.yourDeck = list.at(3);
    g.opponentName = list.at(4);
    g.opponentRank = list.at(5);
    g.opponentClass = list.at(6);
    g.opponentDeck = list.at(7);
    QString result = list.at(8);
    if(result=="W"){
        g.result = Game::WIN;
    }
    else if(result=="L"){
        g.result = Game::LOSS;
    }
    else if(result=="T"){
        g.result = Game::TIE;
    }
    else{
        //throw an error
    }
    g.time = QDateTime::fromTime_t(list.at(9).toUInt());

    return g;
}

QString Game::getYourName() const
{
    return yourName;
}

void Game::setYourName(const QString &value)
{
    yourName = value;
}
QString Game::getYourClass() const
{
    return yourClass;
}

void Game::setYourClass(const QString &value)
{
    yourClass = value;
}
QString Game::getYourDeck() const
{
    return yourDeck;
}

void Game::setYourDeck(const QString &value)
{
    yourDeck = value;
}
QString Game::getYourRank() const
{
    return yourRank;
}

void Game::setYourRank(const bool isLegend, const int rank)
{
    if(isLegend){
        yourRank = "L"+QString::number(rank);
    }
    else{
        yourRank = QString::number(rank);
    }
}
QString Game::getOpponentName() const
{
    return opponentName;
}

void Game::setOpponentName(const QString &value)
{
    opponentName = value;
}
QString Game::getOpponentClass() const
{
    return opponentClass;
}

void Game::setOpponentClass(const QString &value)
{
    opponentClass = value;
}
QString Game::getOpponentDeck() const
{
    return opponentDeck;
}

void Game::setOpponentDeck(const QString &value)
{
    opponentDeck = value;
}
QString Game::getOpponentRank() const
{
    return opponentRank;
}

void Game::setOpponentRank(const bool isLegend, const int rank)
{
    if(isLegend){
        opponentRank = "L"+QString::number(rank);
    }
    else{
        opponentRank = QString::number(rank);
    }
}
QDateTime Game::getTime() const
{
    return time;
}

void Game::setTime(const QDateTime &value)
{
    time = value;
}
Game::Result Game::getResult() const
{
    return result;
}

void Game::setResult(const Result &value)
{
    result = value;
}









