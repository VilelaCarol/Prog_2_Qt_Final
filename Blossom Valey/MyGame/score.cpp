#include "score.hpp"
#include "Redbird.hpp"
#include <QFont>
#include <QGraphicsScene>

#include "game.hpp"
#include "gamewon.hpp"
extern Game* game;

Score::Score(QGraphicsItem*parent):QGraphicsTextItem(parent)
{
    score=-1;
    setPlainText(QString("Score:")+QString::number(score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
    music1=new QMediaPlayer(this);
}

void Score::increase()
{
    score++;
    setPlainText(QString("Score:")+QString::number(score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));


    if(score == 0){
        //adicionarsomdefundo
        music1->setMedia(QUrl("qrc:/music/battleThemeA.mp3"));
        music1->play();
    }
    if(score == 10){
            music1->stop();
            Redbird*Redbird=new class Redbird();
            scene()->addItem(Redbird);

            //adicionarsomdefundo
            QMediaPlayer*music2=new QMediaPlayer(this);
            music2->setMedia(QUrl("qrc:/music/Battlesong.mp3"));

            music2->play();
    }
    if (score >= 200)
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

void Score::setScore(){
    score = 200;
}
