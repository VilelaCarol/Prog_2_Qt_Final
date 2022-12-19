#ifndef BULLET_HPP
#define BULLET_HPP

//#include <QGraphicsRectItem>
#include<QGraphicsPixmapItem>
#include <QObject>

class Bullet: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bullet(QGraphicsItem * parent=0);
    int speed = 20;

public slots:
    void move();
};

#endif // BULLET_HPP
