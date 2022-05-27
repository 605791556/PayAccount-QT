/********************************************************************************
** Form generated from reading UI file 'CStaffMngDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CSTAFFMNGDLG_H
#define UI_CSTAFFMNGDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CStaffMngDlg
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer_5;
    QLineEdit *EDIT_KEY;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *BTN_FIND;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *BTN_ADD;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout_2;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_number;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_dex;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *EDIT_DEX;
    QPushButton *BTN_GO;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *BTN_LAST;
    QSpacerItem *horizontalSpacer;
    QPushButton *BTN_NEXT;

    void setupUi(QDialog *CStaffMngDlg)
    {
        if (CStaffMngDlg->objectName().isEmpty())
            CStaffMngDlg->setObjectName(QStringLiteral("CStaffMngDlg"));
        CStaffMngDlg->setWindowModality(Qt::WindowModal);
        CStaffMngDlg->setEnabled(true);
        CStaffMngDlg->resize(1019, 640);
        verticalLayout = new QVBoxLayout(CStaffMngDlg);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(CStaffMngDlg);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(11);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        horizontalSpacer_5 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        EDIT_KEY = new QLineEdit(CStaffMngDlg);
        EDIT_KEY->setObjectName(QStringLiteral("EDIT_KEY"));
        EDIT_KEY->setMinimumSize(QSize(130, 20));
        EDIT_KEY->setMaximumSize(QSize(130, 20));
        EDIT_KEY->setFont(font);

        horizontalLayout->addWidget(EDIT_KEY);

        horizontalSpacer_6 = new QSpacerItem(30, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);

        BTN_FIND = new QPushButton(CStaffMngDlg);
        BTN_FIND->setObjectName(QStringLiteral("BTN_FIND"));
        BTN_FIND->setFont(font);

        horizontalLayout->addWidget(BTN_FIND);

        horizontalSpacer_7 = new QSpacerItem(30, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_7);

        BTN_ADD = new QPushButton(CStaffMngDlg);
        BTN_ADD->setObjectName(QStringLiteral("BTN_ADD"));
        BTN_ADD->setFont(font);

        horizontalLayout->addWidget(BTN_ADD);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        tableWidget = new QTableWidget(CStaffMngDlg);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setFont(font);

        horizontalLayout_2->addWidget(tableWidget);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_number = new QLabel(CStaffMngDlg);
        label_number->setObjectName(QStringLiteral("label_number"));
        label_number->setFont(font);

        horizontalLayout_3->addWidget(label_number);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        label_dex = new QLabel(CStaffMngDlg);
        label_dex->setObjectName(QStringLiteral("label_dex"));
        label_dex->setFont(font);
        label_dex->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_dex);

        horizontalSpacer_3 = new QSpacerItem(15, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        EDIT_DEX = new QLineEdit(CStaffMngDlg);
        EDIT_DEX->setObjectName(QStringLiteral("EDIT_DEX"));
        EDIT_DEX->setMinimumSize(QSize(35, 20));
        EDIT_DEX->setMaximumSize(QSize(35, 20));
        EDIT_DEX->setFont(font);

        horizontalLayout_3->addWidget(EDIT_DEX);

        BTN_GO = new QPushButton(CStaffMngDlg);
        BTN_GO->setObjectName(QStringLiteral("BTN_GO"));
        BTN_GO->setMinimumSize(QSize(34, 34));
        BTN_GO->setMaximumSize(QSize(34, 34));
        BTN_GO->setFont(font);

        horizontalLayout_3->addWidget(BTN_GO);

        horizontalSpacer_2 = new QSpacerItem(15, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        BTN_LAST = new QPushButton(CStaffMngDlg);
        BTN_LAST->setObjectName(QStringLiteral("BTN_LAST"));
        BTN_LAST->setFont(font);

        horizontalLayout_3->addWidget(BTN_LAST);

        horizontalSpacer = new QSpacerItem(8, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        BTN_NEXT = new QPushButton(CStaffMngDlg);
        BTN_NEXT->setObjectName(QStringLiteral("BTN_NEXT"));
        BTN_NEXT->setFont(font);

        horizontalLayout_3->addWidget(BTN_NEXT);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(CStaffMngDlg);

        QMetaObject::connectSlotsByName(CStaffMngDlg);
    } // setupUi

    void retranslateUi(QDialog *CStaffMngDlg)
    {
        CStaffMngDlg->setWindowTitle(QApplication::translate("CStaffMngDlg", "\345\221\230\345\267\245\347\256\241\347\220\206", 0));
        label->setText(QApplication::translate("CStaffMngDlg", "\345\205\263\351\224\256\345\255\227\357\274\232", 0));
        BTN_FIND->setText(QApplication::translate("CStaffMngDlg", "\346\237\245\350\257\242", 0));
        BTN_ADD->setText(QApplication::translate("CStaffMngDlg", "\346\267\273\345\212\240", 0));
        label_number->setText(QApplication::translate("CStaffMngDlg", "\345\205\2610\346\235\241\350\256\260\345\275\225", 0));
        label_dex->setText(QApplication::translate("CStaffMngDlg", "\345\205\2610\351\241\265 \347\254\2540\351\241\265", 0));
        BTN_GO->setText(QApplication::translate("CStaffMngDlg", "Go", 0));
        BTN_LAST->setText(QApplication::translate("CStaffMngDlg", "\344\270\212\344\270\200\351\241\265", 0));
        BTN_NEXT->setText(QApplication::translate("CStaffMngDlg", "\344\270\213\344\270\200\351\241\265", 0));
    } // retranslateUi

};

namespace Ui {
    class CStaffMngDlg: public Ui_CStaffMngDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CSTAFFMNGDLG_H
