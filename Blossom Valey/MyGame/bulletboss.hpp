#ifndef BULLETBOSS_HPP
#define BULLETBOSS_HPP

//#include <QGraphicsRectItem>
#include<QGraphicsPixmapItem>
#include <QObject>

class BulletBoss: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    BulletBoss(QGraphicsItem * parent=0);

public slots:
    void move();
};

#endif // BULLETBOSS_HPP
