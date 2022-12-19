#include "score.hpp"
#include <QFont>
#include "game.hpp"
#include "gamewon.hpp"
extern Game* game;

Score::Score(QGraphicsItem*parent):QGraphicsTextItem(parent)
{
    score=0;
    setPlainText(QString("Score:")+QString::number(score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
}

void Score::increase()
{
    score++;
    setPlainText(QString("Score:")+QString::number(score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));

    if (score == 20)
    {
        game->close();

        gamewon GameWon;
        GameWon.setModal(true);
        GameWon.exec();
    }
}
int Score::getScore()
{
    return score;
}
