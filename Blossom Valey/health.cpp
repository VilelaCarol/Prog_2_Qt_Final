#include "health.hpp"
#include<QFont>
#include"game.hpp"
#include "gameover.hpp"
extern Game* game;

Health::Health(QGraphicsItem*parent):QGraphicsTextItem(parent)
{
    health=10;
    setPlainText(QString("Health:")+QString::number(health));
    setDefaultTextColor(Qt::green);
    setFont(QFont("times",16));
}
void Health::decrease()
{
    health--;
    setPlainText(QString("Health:")+QString::number(health));
    setDefaultTextColor(Qt::green);
    setFont(QFont("times",16));

    if (health==0 )
    {
        game->close();

        gameover GameOver;
        GameOver.setModal(true);
        GameOver.exec();

    }
}
int Health::getHealth()
{
    return health;

}
