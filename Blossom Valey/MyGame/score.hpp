
#ifndef SCORE_HPP
#define SCORE_HPP

#include<QGraphicsTextItem>
#include <QMediaPlayer>//sudoapt-getinstallqtmultimedia5-dev

class Score : public QGraphicsTextItem
{
public:
    Score(QGraphicsItem*parent=0);
    void increase();
    int getScore();
    void setScore();
    QMediaPlayer*music1;
private:
    int score;
};

#endif // SCORE_HPP
