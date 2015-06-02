#ifndef GAME_H
#define GAME_H
#include <QString>
#include <QDateTime>
class Game
{
public:
    Game();
    QString toString() const;
    static Game fromString(const QString s);
    QString getYourName() const;
    void setYourName(const QString &value);
    QString getYourClass() const;
    void setYourClass(const QString &value);
    QString getYourDeck() const;
    void setYourDeck(const QString &value);
    QString getYourRank() const;
    void setYourRank(const bool isLegend, const int rank);
    QString getOpponentName() const;
    void setOpponentName(const QString &value);
    QString getOpponentClass() const;
    void setOpponentClass(const QString &value);
    QString getOpponentDeck() const;
    void setOpponentDeck(const QString &value);
    QString getOpponentRank() const;
    void setOpponentRank(const bool isLegend, const int rank);
    QDateTime getTime() const;
    void setTime(const QDateTime &value);
    enum Result {WIN,LOSS,TIE};
    Result getResult() const;
    void setResult(const Result &value);

private:
    QString yourName;
    QString yourClass;
    QString yourDeck;
    QString yourRank;
    QString opponentName;
    QString opponentClass;
    QString opponentDeck;
    QString opponentRank;
    QDateTime time;
    Result result;
};

#endif // GAME_H
