/********************************************************************************
** Form generated from reading UI file 'CTabOtherSetDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CTABOTHERSETDLG_H
#define UI_CTABOTHERSETDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CTabOtherSetDlg
{
public:
    QPushButton *BTN_SAVE;
    QLabel *label;
    QComboBox *comboBox;
    QCheckBox *checkBox;
    QLabel *label_2;
    QLineEdit *EDIT_PAY;
    QTableWidget *tableWidget;

    void setupUi(QWidget *CTabOtherSetDlg)
    {
        if (CTabOtherSetDlg->objectName().isEmpty())
            CTabOtherSetDlg->setObjectName(QStringLiteral("CTabOtherSetDlg"));
        CTabOtherSetDlg->resize(814, 505);
        BTN_SAVE = new QPushButton(CTabOtherSetDlg);
        BTN_SAVE->setObjectName(QStringLiteral("BTN_SAVE"));
        BTN_SAVE->setGeometry(QRect(370, 470, 91, 31));
        QFont font;
        font.setPointSize(11);
        BTN_SAVE->setFont(font);
        label = new QLabel(CTabOtherSetDlg);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 54, 22));
        label->setFont(font);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        comboBox = new QComboBox(CTabOtherSetDlg);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(70, 10, 171, 22));
        comboBox->setFont(font);
        checkBox = new QCheckBox(CTabOtherSetDlg);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(440, 10, 81, 22));
        checkBox->setFont(font);
        label_2 = new QLabel(CTabOtherSetDlg);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(530, 10, 54, 22));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        EDIT_PAY = new QLineEdit(CTabOtherSetDlg);
        EDIT_PAY->setObjectName(QStringLiteral("EDIT_PAY"));
        EDIT_PAY->setGeometry(QRect(580, 10, 113, 22));
        EDIT_PAY->setFont(font);
        tableWidget = new QTableWidget(CTabOtherSetDlg);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(30, 40, 411, 421));
        tableWidget->setFont(font);

        retranslateUi(CTabOtherSetDlg);

        QMetaObject::connectSlotsByName(CTabOtherSetDlg);
    } // setupUi

    void retranslateUi(QWidget *CTabOtherSetDlg)
    {
        CTabOtherSetDlg->setWindowTitle(QApplication::translate("CTabOtherSetDlg", "CTabOtherSetDlg", 0));
        BTN_SAVE->setText(QApplication::translate("CTabOtherSetDlg", "\344\277\235\345\255\230", 0));
        label->setText(QApplication::translate("CTabOtherSetDlg", "\351\241\271\347\233\256\357\274\232", 0));
        checkBox->setText(QApplication::translate("CTabOtherSetDlg", "\351\200\202\347\224\250\345\205\250\344\271\246", 0));
        label_2->setText(QApplication::translate("CTabOtherSetDlg", "\345\215\225\344\273\267\357\274\232", 0));
    } // retranslateUi

};

namespace Ui {
    class CTabOtherSetDlg: public Ui_CTabOtherSetDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CTABOTHERSETDLG_H
