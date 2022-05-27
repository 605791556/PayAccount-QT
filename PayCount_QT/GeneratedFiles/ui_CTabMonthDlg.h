/********************************************************************************
** Form generated from reading UI file 'CTabMonthDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CTABMONTHDLG_H
#define UI_CTABMONTHDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CTabMonthDlg
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QComboBox *CB_YEAR;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QComboBox *CB_MONTH;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_3;
    QLineEdit *EDIT_KEYWORD;
    QPushButton *BTN_UPDATE;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_2;
    QTableView *tableView;
    QLabel *label_load;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label_pay;

    void setupUi(QWidget *CTabMonthDlg)
    {
        if (CTabMonthDlg->objectName().isEmpty())
            CTabMonthDlg->setObjectName(QStringLiteral("CTabMonthDlg"));
        CTabMonthDlg->resize(757, 534);
        verticalLayout = new QVBoxLayout(CTabMonthDlg);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout->setContentsMargins(0, 0, -1, 0);
        CB_YEAR = new QComboBox(CTabMonthDlg);
        CB_YEAR->setObjectName(QStringLiteral("CB_YEAR"));
        CB_YEAR->setMinimumSize(QSize(0, 25));
        CB_YEAR->setMaximumSize(QSize(16777215, 25));
        QFont font;
        font.setPointSize(11);
        CB_YEAR->setFont(font);

        horizontalLayout->addWidget(CB_YEAR);

        label = new QLabel(CTabMonthDlg);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        CB_MONTH = new QComboBox(CTabMonthDlg);
        CB_MONTH->setObjectName(QStringLiteral("CB_MONTH"));
        CB_MONTH->setMinimumSize(QSize(0, 25));
        CB_MONTH->setMaximumSize(QSize(16777215, 25));
        CB_MONTH->setFont(font);

        horizontalLayout->addWidget(CB_MONTH);

        label_2 = new QLabel(CTabMonthDlg);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        horizontalLayout->addWidget(label_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label_3 = new QLabel(CTabMonthDlg);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        horizontalLayout->addWidget(label_3);

        EDIT_KEYWORD = new QLineEdit(CTabMonthDlg);
        EDIT_KEYWORD->setObjectName(QStringLiteral("EDIT_KEYWORD"));
        EDIT_KEYWORD->setMinimumSize(QSize(0, 25));
        EDIT_KEYWORD->setFont(font);

        horizontalLayout->addWidget(EDIT_KEYWORD);

        BTN_UPDATE = new QPushButton(CTabMonthDlg);
        BTN_UPDATE->setObjectName(QStringLiteral("BTN_UPDATE"));
        BTN_UPDATE->setFont(font);

        horizontalLayout->addWidget(BTN_UPDATE);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        tableView = new QTableView(CTabMonthDlg);
        tableView->setObjectName(QStringLiteral("tableView"));
        QFont font1;
        font1.setPointSize(13);
        tableView->setFont(font1);

        horizontalLayout_2->addWidget(tableView);

        label_load = new QLabel(CTabMonthDlg);
        label_load->setObjectName(QStringLiteral("label_load"));
        label_load->setFont(font);
        label_load->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_load);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);

        label_pay = new QLabel(CTabMonthDlg);
        label_pay->setObjectName(QStringLiteral("label_pay"));
        QFont font2;
        font2.setPointSize(21);
        font2.setBold(true);
        font2.setWeight(75);
        label_pay->setFont(font2);
        label_pay->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_pay);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(CTabMonthDlg);

        QMetaObject::connectSlotsByName(CTabMonthDlg);
    } // setupUi

    void retranslateUi(QWidget *CTabMonthDlg)
    {
        CTabMonthDlg->setWindowTitle(QApplication::translate("CTabMonthDlg", "CTabMonthDlg", 0));
        label->setText(QApplication::translate("CTabMonthDlg", "\345\271\264", 0));
        label_2->setText(QApplication::translate("CTabMonthDlg", "\346\234\210", 0));
        label_3->setText(QApplication::translate("CTabMonthDlg", "\346\237\245\346\211\276\357\274\232", 0));
        BTN_UPDATE->setText(QApplication::translate("CTabMonthDlg", "\345\210\267\346\226\260", 0));
        label_load->setText(QApplication::translate("CTabMonthDlg", "TextLabel", 0));
        label_pay->setText(QApplication::translate("CTabMonthDlg", "\346\200\273\346\224\257\345\207\272\357\274\232", 0));
    } // retranslateUi

};

namespace Ui {
    class CTabMonthDlg: public Ui_CTabMonthDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CTABMONTHDLG_H
