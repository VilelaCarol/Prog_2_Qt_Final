#ifndef GAME_HPP
#define GAME_HPP

#include<QGraphicsView>
#include<QWidget>
#include<QGraphicsScene>
#include"player.hpp"
#include"score.hpp"
#include"health.hpp"


class Game: public QGraphicsView
{
public:
    Game(QWidget * parent=0);
    QGraphicsScene * scene;
    Player * player;
    Score*score;
    Health*health;
};

#endif // GAME_HPP
