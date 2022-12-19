#ifndef GAMEOVER_HPP
#define GAMEOVER_HPP

#include <QDialog>

namespace Ui {
class Gameover;
}

class Gameover : public QDialog
{
    Q_OBJECT

public:
    explicit Gameover(QWidget *parent = nullptr);
    ~Gameover();

private:
    Ui::Gameover *ui;
};

#endif // GAMEOVER_HPP
