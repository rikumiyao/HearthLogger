#ifndef GAME_H
#define GAME_H
#include <QString>

class game
{
public:
    game();

private:
    QString yourName;
    QString yourClass;
    QString yourDeck;
    QString yourRank;
    QString opponentName;
    QString opponentClass;
    QString opponentDeck;
    QString opponentRank;
    int time;
    int result;
};

#endif // GAME_H
