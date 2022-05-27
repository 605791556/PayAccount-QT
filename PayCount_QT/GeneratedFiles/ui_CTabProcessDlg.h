/********************************************************************************
** Form generated from reading UI file 'CTabProcessDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CTABPROCESSDLG_H
#define UI_CTABPROCESSDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CTabProcessDlg
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer_3;
    QComboBox *cbx_rk;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_4;
    QComboBox *cbx_book;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *BTN_UPDATE;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_2;
    QTableWidget *tableWidget;

    void setupUi(QWidget *CTabProcessDlg)
    {
        if (CTabProcessDlg->objectName().isEmpty())
            CTabProcessDlg->setObjectName(QStringLiteral("CTabProcessDlg"));
        CTabProcessDlg->resize(761, 503);
        verticalLayout = new QVBoxLayout(CTabProcessDlg);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(CTabProcessDlg);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(50, 0));
        label->setMaximumSize(QSize(50, 16777215));
        QFont font;
        font.setPointSize(11);
        label->setFont(font);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label);

        horizontalSpacer_3 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        cbx_rk = new QComboBox(CTabProcessDlg);
        cbx_rk->setObjectName(QStringLiteral("cbx_rk"));
        cbx_rk->setMinimumSize(QSize(90, 22));
        cbx_rk->setMaximumSize(QSize(90, 22));
        cbx_rk->setFont(font);

        horizontalLayout->addWidget(cbx_rk);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_2 = new QLabel(CTabProcessDlg);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(50, 0));
        label_2->setMaximumSize(QSize(50, 16777215));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_2);

        horizontalSpacer_4 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        cbx_book = new QComboBox(CTabProcessDlg);
        cbx_book->setObjectName(QStringLiteral("cbx_book"));
        cbx_book->setMinimumSize(QSize(310, 22));
        cbx_book->setMaximumSize(QSize(310, 22));
        cbx_book->setFont(font);

        horizontalLayout->addWidget(cbx_book);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        BTN_UPDATE = new QPushButton(CTabProcessDlg);
        BTN_UPDATE->setObjectName(QStringLiteral("BTN_UPDATE"));
        BTN_UPDATE->setFont(font);

        horizontalLayout->addWidget(BTN_UPDATE);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        tableWidget = new QTableWidget(CTabProcessDlg);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setFont(font);

        horizontalLayout_2->addWidget(tableWidget);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(CTabProcessDlg);

        QMetaObject::connectSlotsByName(CTabProcessDlg);
    } // setupUi

    void retranslateUi(QWidget *CTabProcessDlg)
    {
        CTabProcessDlg->setWindowTitle(QApplication::translate("CTabProcessDlg", "CTabProcessDlg", 0));
        label->setText(QApplication::translate("CTabProcessDlg", "\345\205\245\345\272\223\357\274\232", 0));
        label_2->setText(QApplication::translate("CTabProcessDlg", "\344\271\246\345\220\215\357\274\232", 0));
        BTN_UPDATE->setText(QApplication::translate("CTabProcessDlg", "\345\210\267\346\226\260", 0));
    } // retranslateUi

};

namespace Ui {
    class CTabProcessDlg: public Ui_CTabProcessDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CTABPROCESSDLG_H
