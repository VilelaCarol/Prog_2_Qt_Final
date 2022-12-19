#ifndef SPECIALBULLET_HPP
#define SPECIALBULLET_HPP

//#include <QGraphicsRectItem>
#include<QGraphicsPixmapItem>
#include <QObject>

class SpecialBullet: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    SpecialBullet(QGraphicsItem * parent=0);

public slots:
    void move();
};

#endif // SPECIALBULLET_HPP
