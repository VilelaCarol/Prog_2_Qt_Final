#include "Redbird.hpp"
#include<QTimer>
#include<QGraphicsScene>
#include<stdlib.h>
#include<QDebug>
#include<QList>
#include"game.hpp"
#include "bulletboss.hpp"
#include "bullet.hpp"
#include "gameover.h"

extern Game*game;

 Redbird::Redbird()
     :life(40)
{
    //posição
    setPos(1800, 400);
    //desenharoinimigo
    //setRect(0,0,100,100);
    setPixmap(QPixmap(":/Imagens/corvo_21.png"));
    setScale(.24);

    //movimentação
    QTimer * timer=new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);

    //shot
    QTimer*timer2=new QTimer();
    QObject::connect(timer2,SIGNAL(timeout()),this,SLOT(shot()));
    timer2->start(2500);

    //animação
    QTimer * timer1 =new QTimer();
    connect(timer1,SIGNAL(timeout()),this,SLOT(Animator()));
    timer1->start(200);

}

void Redbird::Animator(){
    if(animation == 0){
        setPixmap(QPixmap(":/Imagens/corvo_21.png"));
    }else if(animation == 1){
        setPixmap(QPixmap(":/Imagens/corvo_22.png"));
    }
    animation++;
    if(animation == 2){
        animation = 0;
    }
}
void Redbird::move()
{
    QList<QGraphicsItem *> colliding_item= collidingItems();
    for(int i=0,n=colliding_item.size();i<n;i++)
    {
        if(typeid(*(colliding_item[i]))==typeid(Bullet))
        {
            life--;
            if(life <= 0){
                game->score->setScore();
                game->score->increase();
                scene()->removeItem(this);
                delete this;
            }
            return;
        }
    }

    if (pos().x()<200)
    {
        scene()->removeItem(this);
        delete this;
        qDebug()<<"Enemyremoved";

        game->close();
        GameOver GameOver;
        GameOver.setModal(true);
        GameOver.exec();
    }

    if(pos().y()<0){
        i = 1;
    }else if(pos().y()>500){
        i = 0;
    }

    if(i == 1){
        setPos(x()-4,y()+4);
    }else{
        setPos(x()-4,y()-4);
    }
}

void Redbird::shot(){
    BulletBoss * bulletBoss=new BulletBoss();
    bulletBoss->setPos(x(),y());
    scene()->addItem(bulletBoss);

    BulletBoss * bulletBoss2=new BulletBoss();
    bulletBoss2->setPos(x(),y()+200);
    scene()->addItem(bulletBoss2);
}
