/********************************************************************************
** Form generated from reading UI file 'CSetDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CSETDLG_H
#define UI_CSETDLG_H

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

class Ui_CSetDlg
{
public:
    QLineEdit *EDIT_IP;
    QLineEdit *EDIT_PORT;
    QLineEdit *EDIT_NAME;
    QPushButton *BTN_SAVE;
    QPushButton *BTN_CANCEL;
    QLineEdit *EDIT_TITLE;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;

    void setupUi(QDialog *CSetDlg)
    {
        if (CSetDlg->objectName().isEmpty())
            CSetDlg->setObjectName(QStringLiteral("CSetDlg"));
        CSetDlg->resize(445, 265);
        EDIT_IP = new QLineEdit(CSetDlg);
        EDIT_IP->setObjectName(QStringLiteral("EDIT_IP"));
        EDIT_IP->setGeometry(QRect(100, 10, 211, 31));
        QFont font;
        font.setPointSize(11);
        EDIT_IP->setFont(font);
        EDIT_PORT = new QLineEdit(CSetDlg);
        EDIT_PORT->setObjectName(QStringLiteral("EDIT_PORT"));
        EDIT_PORT->setGeometry(QRect(100, 60, 133, 31));
        EDIT_PORT->setFont(font);
        EDIT_NAME = new QLineEdit(CSetDlg);
        EDIT_NAME->setObjectName(QStringLiteral("EDIT_NAME"));
        EDIT_NAME->setGeometry(QRect(100, 110, 133, 31));
        EDIT_NAME->setFont(font);
        BTN_SAVE = new QPushButton(CSetDlg);
        BTN_SAVE->setObjectName(QStringLiteral("BTN_SAVE"));
        BTN_SAVE->setGeometry(QRect(110, 220, 81, 31));
        BTN_SAVE->setFont(font);
        BTN_CANCEL = new QPushButton(CSetDlg);
        BTN_CANCEL->setObjectName(QStringLiteral("BTN_CANCEL"));
        BTN_CANCEL->setGeometry(QRect(210, 220, 71, 31));
        BTN_CANCEL->setFont(font);
        EDIT_TITLE = new QLineEdit(CSetDlg);
        EDIT_TITLE->setObjectName(QStringLiteral("EDIT_TITLE"));
        EDIT_TITLE->setGeometry(QRect(100, 160, 211, 31));
        EDIT_TITLE->setFont(font);
        label = new QLabel(CSetDlg);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 12, 91, 20));
        label->setFont(font);
        label_2 = new QLabel(CSetDlg);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 67, 54, 20));
        label_2->setFont(font);
        label_3 = new QLabel(CSetDlg);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 115, 54, 20));
        label_3->setFont(font);
        label_4 = new QLabel(CSetDlg);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 165, 81, 20));
        label_4->setFont(font);
        label_5 = new QLabel(CSetDlg);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(240, 110, 91, 25));
        label_5->setFont(font);
        label_6 = new QLabel(CSetDlg);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(310, 162, 121, 25));
        label_6->setFont(font);

        retranslateUi(CSetDlg);

        QMetaObject::connectSlotsByName(CSetDlg);
    } // setupUi

    void retranslateUi(QDialog *CSetDlg)
    {
        CSetDlg->setWindowTitle(QApplication::translate("CSetDlg", "\350\256\276\347\275\256", 0));
        EDIT_IP->setPlaceholderText(QApplication::translate("CSetDlg", "\346\234\215\345\212\241\345\231\250\345\234\260\345\235\200", 0));
        EDIT_PORT->setPlaceholderText(QApplication::translate("CSetDlg", "\347\253\257\345\217\243\345\217\267", 0));
        EDIT_NAME->setPlaceholderText(QApplication::translate("CSetDlg", "\345\220\215\347\247\260 \357\274\210\345\246\202\357\274\232xx\345\216\202\357\274\211", 0));
        BTN_SAVE->setText(QApplication::translate("CSetDlg", "\344\277\235 \345\255\230", 0));
        BTN_CANCEL->setText(QApplication::translate("CSetDlg", "\345\217\226 \346\266\210", 0));
        EDIT_TITLE->setPlaceholderText(QApplication::translate("CSetDlg", "\350\275\257\344\273\266\345\220\215\347\247\260\357\274\210\345\246\202\357\274\232xxxxx\347\263\273\347\273\237\357\274\211", 0));
        label->setText(QApplication::translate("CSetDlg", "\346\234\215\345\212\241\345\231\250\345\234\260\345\235\200\357\274\232", 0));
        label_2->setText(QApplication::translate("CSetDlg", "\347\253\257\345\217\243\345\217\267\357\274\232", 0));
        label_3->setText(QApplication::translate("CSetDlg", "\345\220\215\345\255\227\357\274\232", 0));
        label_4->setText(QApplication::translate("CSetDlg", "\350\275\257\344\273\266\345\220\215\347\247\260\357\274\232", 0));
        label_5->setText(QApplication::translate("CSetDlg", "\357\274\210\345\246\202\357\274\232xx\345\216\202\357\274\211", 0));
        label_6->setText(QApplication::translate("CSetDlg", "\357\274\210\345\246\202\357\274\232XXX\347\263\273\347\273\237\357\274\211", 0));
    } // retranslateUi

};

namespace Ui {
    class CSetDlg: public Ui_CSetDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CSETDLG_H
