#ifndef BOSS_HPP
#define BOSS_HPP
//#include<QGraphicsRectItem>
#include<QGraphicsPixmapItem>
#include<QObject>

class Boss:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    int i = 1;
    int life;
    int animation = 0;
    Boss();
public slots:
    void move();
    void shot();
    void Animator();
};

#endif // BOSS_HPP

