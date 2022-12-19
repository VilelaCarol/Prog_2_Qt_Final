/********************************************************************************
** Form generated from reading UI file 'gamewon.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEWON_H
#define UI_GAMEWON_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_gamewon
{
public:
    QLabel *label;

    void setupUi(QDialog *gamewon)
    {
        if (gamewon->objectName().isEmpty())
            gamewon->setObjectName(QString::fromUtf8("gamewon"));
        gamewon->resize(400, 300);
        label = new QLabel(gamewon);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(106, 60, 151, 121));

        retranslateUi(gamewon);

        QMetaObject::connectSlotsByName(gamewon);
    } // setupUi

    void retranslateUi(QDialog *gamewon)
    {
        gamewon->setWindowTitle(QCoreApplication::translate("gamewon", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("gamewon", "YOU WON!!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class gamewon: public Ui_gamewon {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWON_H
