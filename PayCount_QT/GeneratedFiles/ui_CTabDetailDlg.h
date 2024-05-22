/********************************************************************************
** Form generated from reading UI file 'CTabDetailDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CTABDETAILDLG_H
#define UI_CTABDETAILDLG_H

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

class Ui_CTabDetailDlg
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer_3;
    QComboBox *cbx_rk;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_3;
    QComboBox *cbx_xd_time;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_4;
    QComboBox *cbx_book;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *BTN_UPDATE;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_5;
    QLabel *label_all_money;
    QHBoxLayout *horizontalLayout_2;
    QTableWidget *tableWidget;
    QLabel *label_load;

    void setupUi(QWidget *CTabDetailDlg)
    {
        if (CTabDetailDlg->objectName().isEmpty())
            CTabDetailDlg->setObjectName(QStringLiteral("CTabDetailDlg"));
        CTabDetailDlg->resize(1123, 574);
        verticalLayout = new QVBoxLayout(CTabDetailDlg);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(CTabDetailDlg);
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

        cbx_rk = new QComboBox(CTabDetailDlg);
        cbx_rk->setObjectName(QStringLiteral("cbx_rk"));
        cbx_rk->setMinimumSize(QSize(90, 22));
        cbx_rk->setMaximumSize(QSize(90, 22));
        cbx_rk->setFont(font);

        horizontalLayout->addWidget(cbx_rk);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);

        label_3 = new QLabel(CTabDetailDlg);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        cbx_xd_time = new QComboBox(CTabDetailDlg);
        cbx_xd_time->setObjectName(QStringLiteral("cbx_xd_time"));
        cbx_xd_time->setMinimumSize(QSize(150, 0));
        cbx_xd_time->setMaximumSize(QSize(150, 16777215));

        horizontalLayout->addWidget(cbx_xd_time);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_2 = new QLabel(CTabDetailDlg);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(50, 0));
        label_2->setMaximumSize(QSize(50, 16777215));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_2);

        horizontalSpacer_4 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        cbx_book = new QComboBox(CTabDetailDlg);
        cbx_book->setObjectName(QStringLiteral("cbx_book"));
        cbx_book->setMinimumSize(QSize(310, 22));
        cbx_book->setMaximumSize(QSize(310, 22));
        cbx_book->setFont(font);

        horizontalLayout->addWidget(cbx_book);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        BTN_UPDATE = new QPushButton(CTabDetailDlg);
        BTN_UPDATE->setObjectName(QStringLiteral("BTN_UPDATE"));
        BTN_UPDATE->setFont(font);

        horizontalLayout->addWidget(BTN_UPDATE);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        label_5 = new QLabel(CTabDetailDlg);
        label_5->setObjectName(QStringLiteral("label_5"));
        QFont font1;
        font1.setPointSize(20);
        label_5->setFont(font1);

        horizontalLayout->addWidget(label_5);

        label_all_money = new QLabel(CTabDetailDlg);
        label_all_money->setObjectName(QStringLiteral("label_all_money"));
        label_all_money->setFont(font1);

        horizontalLayout->addWidget(label_all_money);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        tableWidget = new QTableWidget(CTabDetailDlg);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setFont(font);

        horizontalLayout_2->addWidget(tableWidget);

        label_load = new QLabel(CTabDetailDlg);
        label_load->setObjectName(QStringLiteral("label_load"));
        label_load->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_load);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(CTabDetailDlg);

        QMetaObject::connectSlotsByName(CTabDetailDlg);
    } // setupUi

    void retranslateUi(QWidget *CTabDetailDlg)
    {
        CTabDetailDlg->setWindowTitle(QApplication::translate("CTabDetailDlg", "CTabDetailDlg", 0));
        label->setText(QApplication::translate("CTabDetailDlg", "\345\205\245\345\272\223\357\274\232", 0));
        label_3->setText(QApplication::translate("CTabDetailDlg", "\344\270\213\345\215\225\346\227\266\351\227\264\357\274\232", 0));
        label_2->setText(QApplication::translate("CTabDetailDlg", "\344\271\246\345\220\215\357\274\232", 0));
        BTN_UPDATE->setText(QApplication::translate("CTabDetailDlg", "\346\237\245\350\257\242", 0));
        label_5->setText(QApplication::translate("CTabDetailDlg", "\346\200\273\351\207\221\351\242\235\357\274\232", 0));
        label_all_money->setText(QString());
        label_load->setText(QApplication::translate("CTabDetailDlg", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class CTabDetailDlg: public Ui_CTabDetailDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CTABDETAILDLG_H
