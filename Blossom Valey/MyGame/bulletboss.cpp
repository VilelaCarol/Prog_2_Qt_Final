//#include<QGraphicsRectItem>
#include<QGraphicsScene>
#include<QTimer>
#include<QDebug>
#include<QList>

#include "bulletboss.hpp"
#include "game.hpp"
#include "player.hpp"

extern Game* game;

BulletBoss::BulletBoss(QGraphicsItem*parent):QObject(),QGraphicsPixmapItem(parent)
{
    //desenharotiro
    //setRect(0,0,10,50);
    setPixmap(QPixmap(":/img/Alpiste.png"));
    setScale(.15);
    //conectarotimercomomovimento
    QTimer * timer =new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    //inicializarotimer
    timer->start(50);


}

void BulletBoss::move(){

    //verificaçãodecolisão:
    //setiroatingiuonimigo
    QList<QGraphicsItem *> colliding_item= collidingItems();

    for(int i=0,n=colliding_item.size();i<n;i++)
    {
        if(typeid(*(colliding_item[i]))==typeid(Player))
        {
            scene()->removeItem(this);
            game->health->decrease();
            delete this;
            return;
        }
    }

    //movimentaçãodotiro
    setPos(x()-20,y());
    if(pos().x()<0)
    {
        scene()->removeItem(this);
        delete this;
        qDebug()<<"Bullet removed";
    }
}

