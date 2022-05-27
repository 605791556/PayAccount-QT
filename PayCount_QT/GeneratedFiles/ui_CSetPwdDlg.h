/********************************************************************************
** Form generated from reading UI file 'CSetPwdDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CSETPWDDLG_H
#define UI_CSETPWDDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_CSetPwdDlg
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *EDIT_OLDPWD;
    QLineEdit *EDIT_NEWPWD;
    QLineEdit *EDIT_NEWPWD2;
    QPushButton *BTN_SAVE;

    void setupUi(QDialog *CSetPwdDlg)
    {
        if (CSetPwdDlg->objectName().isEmpty())
            CSetPwdDlg->setObjectName(QStringLiteral("CSetPwdDlg"));
        CSetPwdDlg->resize(280, 161);
        label = new QLabel(CSetPwdDlg);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(13, 20, 71, 25));
        QFont font;
        font.setPointSize(11);
        label->setFont(font);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_2 = new QLabel(CSetPwdDlg);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(13, 50, 71, 25));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_3 = new QLabel(CSetPwdDlg);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(3, 80, 81, 25));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        EDIT_OLDPWD = new QLineEdit(CSetPwdDlg);
        EDIT_OLDPWD->setObjectName(QStringLiteral("EDIT_OLDPWD"));
        EDIT_OLDPWD->setGeometry(QRect(100, 20, 141, 25));
        EDIT_OLDPWD->setFont(font);
        EDIT_OLDPWD->setEchoMode(QLineEdit::Password);
        EDIT_NEWPWD = new QLineEdit(CSetPwdDlg);
        EDIT_NEWPWD->setObjectName(QStringLiteral("EDIT_NEWPWD"));
        EDIT_NEWPWD->setGeometry(QRect(100, 50, 141, 25));
        EDIT_NEWPWD->setFont(font);
        EDIT_NEWPWD->setEchoMode(QLineEdit::Password);
        EDIT_NEWPWD2 = new QLineEdit(CSetPwdDlg);
        EDIT_NEWPWD2->setObjectName(QStringLiteral("EDIT_NEWPWD2"));
        EDIT_NEWPWD2->setGeometry(QRect(100, 80, 141, 25));
        EDIT_NEWPWD2->setFont(font);
        EDIT_NEWPWD2->setEchoMode(QLineEdit::Password);
        BTN_SAVE = new QPushButton(CSetPwdDlg);
        BTN_SAVE->setObjectName(QStringLiteral("BTN_SAVE"));
        BTN_SAVE->setGeometry(QRect(100, 120, 81, 25));
        BTN_SAVE->setFont(font);

        retranslateUi(CSetPwdDlg);

        QMetaObject::connectSlotsByName(CSetPwdDlg);
    } // setupUi

    void retranslateUi(QDialog *CSetPwdDlg)
    {
        CSetPwdDlg->setWindowTitle(QApplication::translate("CSetPwdDlg", "\344\277\256\346\224\271\345\257\206\347\240\201", 0));
        label->setText(QApplication::translate("CSetPwdDlg", "\345\216\237\345\257\206\347\240\201\357\274\232", 0));
        label_2->setText(QApplication::translate("CSetPwdDlg", "\346\226\260\345\257\206\347\240\201\357\274\232", 0));
        label_3->setText(QApplication::translate("CSetPwdDlg", "\347\241\256\350\256\244\345\257\206\347\240\201\357\274\232", 0));
        BTN_SAVE->setText(QApplication::translate("CSetPwdDlg", "\344\277\235\345\255\230", 0));
    } // retranslateUi

};

namespace Ui {
    class CSetPwdDlg: public Ui_CSetPwdDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CSETPWDDLG_H
