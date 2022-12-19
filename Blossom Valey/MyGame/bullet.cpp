//#include<QGraphicsRectItem>
#include<QGraphicsScene>
#include<QTimer>
#include<QDebug>
#include<QList>

#include "bullet.hpp"
#include "game.hpp"
#include"enemy.hpp"
#include"boss.hpp"
#include"Redbird.hpp"

extern Game* game;

Bullet::Bullet(QGraphicsItem*parent):QObject(),QGraphicsPixmapItem(parent)
{
    //desenharotiro
    //setRect(0,0,10,50);
    if(game->score->getScore()< 5){
        setPixmap(QPixmap(":/Imagens/foguinho.png"));
        setScale(.08);
    }else{
        setPixmap(QPixmap(":/Imagens/foguinho.png"));
        setScale(.08);
    }
    //conectarotimercomomovimento
    QTimer * timer =new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    //inicializarotimer
    timer->start(50);

}

void Bullet::move(){

    //verificaçãodecolisão:
    //setiroatingiuonimigo
    QList<QGraphicsItem *> colliding_item= collidingItems();

    for(int i=0,n=colliding_item.size();i<n;i++)
    {
        if(typeid(*(colliding_item[i]))==typeid(Enemy))
        {
            game->score->increase();
            if(game->score->getScore() > 5 && game->score->getScore() <= 10){
                game->player->bulletBuff = 1;
            }
            else if(game->score->getScore() > 10){
                game->player->bulletBuff = 2;
            }
            scene()->removeItem(colliding_item[i]);
            scene()->removeItem(this);

            delete colliding_item[i];
            delete this;
            return;
        }

        if(typeid(*(colliding_item[i]))==typeid(Boss) || typeid(*(colliding_item[i]))==typeid(Redbird))
        {
            scene()->removeItem(this);
            delete this;
            return;
        }
    }
    if(game->score->getScore() >= 6){
        speed = 40;
    }else{
        speed = 20;
    }

    //movimentaçãodotiro
    setPos(x()+speed,y());
    if(pos().x()>1800)
    {
        scene()->removeItem(this);
        delete this;
        qDebug()<<"Bullet removed";
    }
}
