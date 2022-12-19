#ifndef PLAYER_HPP
#define PLAYER_HPP

//#include<QGraphicsRectItem>
#include<QObject>
#include<QGraphicsItem>
#include<QGraphicsPixmapItem>

class Player:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player(QGraphicsItem*parent=0);
    void keyPressEvent(QKeyEvent*event);
    int bulletBuff = 0;
public slots:
    void spawn();
    void spawnBoss();
};

#endif // PLAYER_HPP
