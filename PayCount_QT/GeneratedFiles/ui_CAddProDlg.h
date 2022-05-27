/********************************************************************************
** Form generated from reading UI file 'CAddProDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CADDPRODLG_H
#define UI_CADDPRODLG_H

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

class Ui_CAddProDlg
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *EDIT_PRONAME;
    QRadioButton *RDO_ZYS;
    QRadioButton *RDO_ZLS;
    QRadioButton *RDO_YES;
    QRadioButton *RDO_NO;
    QPushButton *BTN_SAVE;

    void setupUi(QDialog *CAddProDlg)
    {
        if (CAddProDlg->objectName().isEmpty())
            CAddProDlg->setObjectName(QStringLiteral("CAddProDlg"));
        CAddProDlg->resize(276, 221);
        label = new QLabel(CAddProDlg);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(17, 20, 54, 12));
        QFont font;
        font.setPointSize(11);
        label->setFont(font);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_2 = new QLabel(CAddProDlg);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(-10, 60, 91, 20));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_3 = new QLabel(CAddProDlg);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(0, 100, 81, 20));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        EDIT_PRONAME = new QLineEdit(CAddProDlg);
        EDIT_PRONAME->setObjectName(QStringLiteral("EDIT_PRONAME"));
        EDIT_PRONAME->setGeometry(QRect(80, 15, 171, 25));
        EDIT_PRONAME->setMinimumSize(QSize(0, 25));
        EDIT_PRONAME->setMaximumSize(QSize(16777215, 25));
        EDIT_PRONAME->setFont(font);
        RDO_ZYS = new QRadioButton(CAddProDlg);
        RDO_ZYS->setObjectName(QStringLiteral("RDO_ZYS"));
        RDO_ZYS->setGeometry(QRect(100, 62, 89, 16));
        RDO_ZYS->setFont(font);
        RDO_ZLS = new QRadioButton(CAddProDlg);
        RDO_ZLS->setObjectName(QStringLiteral("RDO_ZLS"));
        RDO_ZLS->setGeometry(QRect(190, 62, 81, 16));
        RDO_ZLS->setFont(font);
        RDO_YES = new QRadioButton(CAddProDlg);
        RDO_YES->setObjectName(QStringLiteral("RDO_YES"));
        RDO_YES->setGeometry(QRect(100, 102, 89, 16));
        RDO_YES->setFont(font);
        RDO_NO = new QRadioButton(CAddProDlg);
        RDO_NO->setObjectName(QStringLiteral("RDO_NO"));
        RDO_NO->setGeometry(QRect(190, 102, 89, 16));
        RDO_NO->setFont(font);
        BTN_SAVE = new QPushButton(CAddProDlg);
        BTN_SAVE->setObjectName(QStringLiteral("BTN_SAVE"));
        BTN_SAVE->setGeometry(QRect(90, 180, 75, 23));
        BTN_SAVE->setFont(font);

        retranslateUi(CAddProDlg);

        QMetaObject::connectSlotsByName(CAddProDlg);
    } // setupUi

    void retranslateUi(QDialog *CAddProDlg)
    {
        CAddProDlg->setWindowTitle(QApplication::translate("CAddProDlg", "\351\241\271\347\233\256\346\267\273\345\212\240/\347\274\226\350\276\221", 0));
        label->setText(QApplication::translate("CAddProDlg", "\345\220\215\347\247\260\357\274\232", 0));
        label_2->setText(QApplication::translate("CAddProDlg", "\350\214\203\345\233\264\347\261\273\345\236\213\357\274\232", 0));
        label_3->setText(QApplication::translate("CAddProDlg", "\345\267\245\344\272\272\345\241\253\345\205\245\357\274\232", 0));
        RDO_ZYS->setText(QApplication::translate("CAddProDlg", "\346\200\273\345\215\260\346\225\260", 0));
        RDO_ZLS->setText(QApplication::translate("CAddProDlg", "\346\200\273\344\273\244\346\225\260", 0));
        RDO_YES->setText(QApplication::translate("CAddProDlg", "\346\230\257", 0));
        RDO_NO->setText(QApplication::translate("CAddProDlg", "\345\220\246", 0));
        BTN_SAVE->setText(QApplication::translate("CAddProDlg", "\344\277\235\345\255\230", 0));
    } // retranslateUi

};

namespace Ui {
    class CAddProDlg: public Ui_CAddProDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CADDPRODLG_H
