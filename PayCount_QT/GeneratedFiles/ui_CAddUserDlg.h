/********************************************************************************
** Form generated from reading UI file 'CAddUserDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CADDUSERDLG_H
#define UI_CADDUSERDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_CAddUserDlg
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *EDIT_USER;
    QLineEdit *EDIT_PWD;
    QLineEdit *EDIT_PWD2;
    QRadioButton *RDO_COMMON;
    QRadioButton *RDO_MANAGE;
    QPushButton *BTN_ADD;
    QLabel *label_5;

    void setupUi(QDialog *CAddUserDlg)
    {
        if (CAddUserDlg->objectName().isEmpty())
            CAddUserDlg->setObjectName(QStringLiteral("CAddUserDlg"));
        CAddUserDlg->resize(288, 282);
        label = new QLabel(CAddUserDlg);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(13, 20, 71, 20));
        QFont font;
        font.setPointSize(11);
        label->setFont(font);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_2 = new QLabel(CAddUserDlg);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(13, 60, 71, 20));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_3 = new QLabel(CAddUserDlg);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(3, 100, 81, 20));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_4 = new QLabel(CAddUserDlg);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(13, 135, 71, 20));
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        EDIT_USER = new QLineEdit(CAddUserDlg);
        EDIT_USER->setObjectName(QStringLiteral("EDIT_USER"));
        EDIT_USER->setGeometry(QRect(90, 18, 161, 20));
        EDIT_USER->setFont(font);
        EDIT_PWD = new QLineEdit(CAddUserDlg);
        EDIT_PWD->setObjectName(QStringLiteral("EDIT_PWD"));
        EDIT_PWD->setGeometry(QRect(90, 58, 161, 20));
        EDIT_PWD->setFont(font);
        EDIT_PWD2 = new QLineEdit(CAddUserDlg);
        EDIT_PWD2->setObjectName(QStringLiteral("EDIT_PWD2"));
        EDIT_PWD2->setGeometry(QRect(90, 100, 161, 20));
        EDIT_PWD2->setFont(font);
        RDO_COMMON = new QRadioButton(CAddUserDlg);
        RDO_COMMON->setObjectName(QStringLiteral("RDO_COMMON"));
        RDO_COMMON->setGeometry(QRect(98, 135, 81, 20));
        RDO_COMMON->setFont(font);
        RDO_MANAGE = new QRadioButton(CAddUserDlg);
        RDO_MANAGE->setObjectName(QStringLiteral("RDO_MANAGE"));
        RDO_MANAGE->setGeometry(QRect(200, 135, 81, 20));
        RDO_MANAGE->setFont(font);
        BTN_ADD = new QPushButton(CAddUserDlg);
        BTN_ADD->setObjectName(QStringLiteral("BTN_ADD"));
        BTN_ADD->setGeometry(QRect(110, 180, 81, 31));
        BTN_ADD->setFont(font);
        label_5 = new QLabel(CAddUserDlg);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 220, 371, 71));
        QFont font1;
        font1.setPointSize(9);
        label_5->setFont(font1);

        retranslateUi(CAddUserDlg);

        QMetaObject::connectSlotsByName(CAddUserDlg);
    } // setupUi

    void retranslateUi(QDialog *CAddUserDlg)
    {
        CAddUserDlg->setWindowTitle(QApplication::translate("CAddUserDlg", "\346\267\273\345\212\240\350\264\246\345\217\267", 0));
        label->setText(QApplication::translate("CAddUserDlg", "\350\264\246\345\217\267\357\274\232", 0));
        label_2->setText(QApplication::translate("CAddUserDlg", "\345\257\206\347\240\201\357\274\232", 0));
        label_3->setText(QApplication::translate("CAddUserDlg", "\347\241\256\350\256\244\345\257\206\347\240\201\357\274\232", 0));
        label_4->setText(QApplication::translate("CAddUserDlg", "\346\235\203\351\231\220\357\274\232", 0));
        RDO_COMMON->setText(QApplication::translate("CAddUserDlg", "\346\231\256\351\200\232\347\224\250\346\210\267", 0));
        RDO_MANAGE->setText(QApplication::translate("CAddUserDlg", "\347\256\241\347\220\206\345\221\230", 0));
        BTN_ADD->setText(QApplication::translate("CAddUserDlg", "\346\267\273\345\212\240", 0));
        label_5->setText(QApplication::translate("CAddUserDlg", "<html><head/><body><p>\346\217\220\347\244\272\357\274\232\346\231\256\351\200\232\347\224\250\346\210\267\345\217\252\350\203\275\345\275\225\345\205\245\350\277\233\345\272\246\357\274\214\350\200\214\347\256\241\347\220\206\345\221\230\345\210\231\345\205\267\346\234\211</p><p>\344\277\256\346\224\271\346\225\260\346\215\256\347\232\204\346\235\203\351\231\220\357\274\214\350\257\267\346\263\250\346\204\217\346\235\203\351\231\220\345\210\206\351\205\215\343\200\202</p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class CAddUserDlg: public Ui_CAddUserDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CADDUSERDLG_H
