#ifndef ENEMY_HPP
#define ENEMY_HPP

//#include<QGraphicsRectItem>
#include<QGraphicsPixmapItem>
#include<QObject>

class Enemy:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Enemy();
    int animation = 0;
public slots:
    void move();
    void Animator();
};

#endif // ENEMY_HPP
