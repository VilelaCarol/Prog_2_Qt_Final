#ifndef GAMEWON_HPP
#define GAMEWON_HPP

#include <QDialog>

namespace Ui {
class gamewon;
}

class gamewon : public QDialog
{
    Q_OBJECT

public:
    explicit gamewon(QWidget *parent = nullptr);
    ~gamewon();

private:
    Ui::gamewon *ui;
};

#endif // GAMEWON_HPP
