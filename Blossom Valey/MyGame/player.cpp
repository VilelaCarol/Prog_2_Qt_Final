#include <QGraphicsScene>
#include <QObject>
#include <QGraphicsItem>
#include <QDebug>
#include <QKeyEvent>
#include "bullet.hpp"
#include "specialBullet.hpp"
#include "player.hpp"
#include"enemy.hpp"
#include"boss.hpp"


Player::Player(QGraphicsItem*parent): QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/Imagens/Pantalho.png"));
    setScale(.25);
}

void Player :: keyPressEvent (QKeyEvent*event){
    //mensageminformandoqueocorreuusodoteclado
    //qDebug()<<"Keypressdetected";

    if(event->key()==Qt::Key_Up){
        setPos(x(),y()-10);
    }
    else if(event->key()==Qt::Key_Down){
        setPos(x(),y()+10);
    }

    //criartiro(bullet)
    else if(event->key()==Qt::Key_Space)
    {
        //testeviaDebug
        //qDebug()<<"Bulletcreated";

        if(bulletBuff == 0){
            Bullet * bullet=new Bullet();
            bullet->setPos(x()+200,y()+25);
            scene()->addItem(bullet);
        }
        else if(bulletBuff == 1){
            Bullet * bullet=new Bullet();
            bullet->setPos(x()+200,y()+25);
            scene()->addItem(bullet);
        }
        else if(bulletBuff == 2){
            Bullet * bullet1=new Bullet();
            Bullet * bullet2=new Bullet();
            bullet1->setPos(x()+200,y());
            bullet2->setPos(x()+200,y()+70);
            scene()->addItem(bullet1);
            scene()->addItem(bullet2);
        }
    }
}

void Player::spawn()
{
    //criainimigo
    Enemy*enemy=new Enemy();
    scene()->addItem(enemy);
}

void Player::spawnBoss()
{
    //criainimigo
    Boss*boss=new Boss();
    scene()->addItem(boss);
}
