/********************************************************************************
** Form generated from reading UI file 'CUserMngDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSERMNGDLG_H
#define UI_CUSERMNGDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_CUserMngDlg
{
public:
    QPushButton *BTN_ADD;
    QTableWidget *tableWidget;

    void setupUi(QDialog *CUserMngDlg)
    {
        if (CUserMngDlg->objectName().isEmpty())
            CUserMngDlg->setObjectName(QStringLiteral("CUserMngDlg"));
        CUserMngDlg->resize(436, 257);
        BTN_ADD = new QPushButton(CUserMngDlg);
        BTN_ADD->setObjectName(QStringLiteral("BTN_ADD"));
        BTN_ADD->setGeometry(QRect(350, 10, 75, 25));
        QFont font;
        font.setPointSize(11);
        BTN_ADD->setFont(font);
        tableWidget = new QTableWidget(CUserMngDlg);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(10, 40, 421, 211));
        tableWidget->setFont(font);

        retranslateUi(CUserMngDlg);

        QMetaObject::connectSlotsByName(CUserMngDlg);
    } // setupUi

    void retranslateUi(QDialog *CUserMngDlg)
    {
        CUserMngDlg->setWindowTitle(QApplication::translate("CUserMngDlg", "\350\264\246\345\217\267\347\256\241\347\220\206", 0));
        BTN_ADD->setText(QApplication::translate("CUserMngDlg", "\346\267\273\345\212\240", 0));
    } // retranslateUi

};

namespace Ui {
    class CUserMngDlg: public Ui_CUserMngDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSERMNGDLG_H
