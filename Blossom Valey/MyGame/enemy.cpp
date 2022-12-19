#include "enemy.hpp"
#include<QTimer>
#include<QGraphicsScene>
#include<stdlib.h>
#include<QDebug>
#include"game.hpp"
#include "gameover.h"

extern Game*game;

Enemy::Enemy()
{
    //posiçãoaleatoria
    int random_number= 50+rand()%650;
    setPos(1800, random_number);
    //desenharoinimigo
    //setRect(0,0,100,100);
    setPixmap(QPixmap(":/Imagens/corvo_01.png"));
    setScale(.15);
    //movimentação
    QTimer * timer=new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);

    //animação
    QTimer * timer1 =new QTimer();
    connect(timer1,SIGNAL(timeout()),this,SLOT(Animator()));
    timer1->start(200);



}

void Enemy::Animator(){
    if(animation == 0){
        setPixmap(QPixmap(":/Imagens/corvo_01.png"));
    }else if(animation == 1){
        setPixmap(QPixmap(":/Imagens/corvo_02.png"));
    }
    animation++;
    if(animation == 2){
        animation = 0;
    }
}
void Enemy::move()
{
    setPos(x()-10,y());
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
}
