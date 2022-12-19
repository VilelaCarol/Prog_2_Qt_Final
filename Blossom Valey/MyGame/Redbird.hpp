#ifndef REDBIRD_H
#define REDBIRD_H
//#include<QGraphicsRectItem>
#include<QGraphicsPixmapItem>
#include<QObject>

class Redbird:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    int i = 1;
    int life = 40;
    int animation = 0;
    Redbird();
public slots:
    void move();
    void shot();
    void Animator();
};

#endif // REDBIRD_H

