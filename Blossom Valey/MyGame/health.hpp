#ifndef HEALTH_HPP
#define HEALTH_HPP
#include <QGraphicsTextItem>
#include<QGraphicsView>
#include <QWidget>

class Health: public QGraphicsTextItem
{
public:
    Health(QGraphicsItem*parent=0);
    void decrease();
    int getHealth();


private:
    int health;
};

#endif // HEALTH_HPP
