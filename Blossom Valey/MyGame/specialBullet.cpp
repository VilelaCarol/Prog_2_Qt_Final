//#include<QGraphicsRectItem>
#include<QGraphicsScene>
#include<QTimer>
#include<QDebug>
#include<QList>

#include "specialBullet.hpp"
#include "game.hpp"
#include"enemy.hpp"
#include"boss.hpp"

extern Game* game;

SpecialBullet::SpecialBullet(QGraphicsItem*parent):QObject(),QGraphicsPixmapItem(parent)
{
    //desenharotiro
    //setRect(0,0,10,50);
    setPixmap(QPixmap(":/img/laserRed.png"));
    //conectarotimercomomovimento
    QTimer * timer =new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    //inicializarotimer
    timer->start(50);

}

void SpecialBullet::move(){

    //verificaçãodecolisão:
    //setiroatingiuonimigo
    QList<QGraphicsItem *> colliding_item= collidingItems();

    for(int i=0,n=colliding_item.size();i<n;i++)
    {
        if(typeid(*(colliding_item[i]))==typeid(Enemy))
        {
            game->score->increase();
            scene()->removeItem(colliding_item[i]);
            scene()->removeItem(this);

            delete colliding_item[i];
            delete this;
            return;
        }

        if(typeid(*(colliding_item[i]))==typeid(Boss))
        {
            scene()->removeItem(this);
            delete this;
            return;
        }
    }


    //movimentaçãodotiro
    setPos(x()+40,y());
    if(pos().x()>1500)
    {
        scene()->removeItem(this);
        delete this;
        qDebug()<<"Bullet removed";
    }
}
