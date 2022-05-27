/********************************************************************************
** Form generated from reading UI file 'CTabDySetDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CTABDYSETDLG_H
#define UI_CTABDYSETDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CTabDySetDlg
{
public:
    QPushButton *BTN_SAVE;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *EDIT_W_DOWN;
    QLineEdit *EDIT_W_UP;

    void setupUi(QWidget *CTabDySetDlg)
    {
        if (CTabDySetDlg->objectName().isEmpty())
            CTabDySetDlg->setObjectName(QStringLiteral("CTabDySetDlg"));
        CTabDySetDlg->resize(814, 505);
        BTN_SAVE = new QPushButton(CTabDySetDlg);
        BTN_SAVE->setObjectName(QStringLiteral("BTN_SAVE"));
        BTN_SAVE->setGeometry(QRect(370, 400, 91, 31));
        QFont font;
        font.setPointSize(11);
        BTN_SAVE->setFont(font);
        label = new QLabel(CTabDySetDlg);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(260, 60, 91, 16));
        label->setFont(font);
        label_2 = new QLabel(CTabDySetDlg);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(440, 60, 201, 16));
        label_2->setFont(font);
        EDIT_W_DOWN = new QLineEdit(CTabDySetDlg);
        EDIT_W_DOWN->setObjectName(QStringLiteral("EDIT_W_DOWN"));
        EDIT_W_DOWN->setGeometry(QRect(260, 100, 113, 20));
        EDIT_W_DOWN->setFont(font);
        EDIT_W_UP = new QLineEdit(CTabDySetDlg);
        EDIT_W_UP->setObjectName(QStringLiteral("EDIT_W_UP"));
        EDIT_W_UP->setGeometry(QRect(440, 100, 113, 20));
        EDIT_W_UP->setFont(font);

        retranslateUi(CTabDySetDlg);

        QMetaObject::connectSlotsByName(CTabDySetDlg);
    } // setupUi

    void retranslateUi(QWidget *CTabDySetDlg)
    {
        CTabDySetDlg->setWindowTitle(QApplication::translate("CTabDySetDlg", "CTabDySetDlg", 0));
        BTN_SAVE->setText(QApplication::translate("CTabDySetDlg", "\344\277\235\345\255\230", 0));
        label->setText(QApplication::translate("CTabDySetDlg", "10000\344\273\245\344\270\213", 0));
        label_2->setText(QApplication::translate("CTabDySetDlg", "10000\344\273\245\344\270\212\357\274\210\345\214\205\345\220\25310000\357\274\211", 0));
    } // retranslateUi

};

namespace Ui {
    class CTabDySetDlg: public Ui_CTabDySetDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CTABDYSETDLG_H
