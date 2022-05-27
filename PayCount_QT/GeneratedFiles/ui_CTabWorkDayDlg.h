/********************************************************************************
** Form generated from reading UI file 'CTabWorkDayDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CTABWORKDAYDLG_H
#define UI_CTABWORKDAYDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
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

class Ui_CTabWorkDayDlg
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDateEdit *dateEdit;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_3;
    QLineEdit *edit_keyword;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *BTN_UPDATE;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_3;
    QTableView *tableView;
    QLabel *label_load;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLabel *label_total;

    void setupUi(QWidget *CTabWorkDayDlg)
    {
        if (CTabWorkDayDlg->objectName().isEmpty())
            CTabWorkDayDlg->setObjectName(QStringLiteral("CTabWorkDayDlg"));
        CTabWorkDayDlg->resize(780, 603);
        verticalLayout = new QVBoxLayout(CTabWorkDayDlg);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        label = new QLabel(CTabWorkDayDlg);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(11);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        dateEdit = new QDateEdit(CTabWorkDayDlg);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        QFont font1;
        font1.setPointSize(13);
        dateEdit->setFont(font1);
        dateEdit->setCalendarPopup(true);
        dateEdit->setTimeSpec(Qt::LocalTime);

        horizontalLayout->addWidget(dateEdit);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        label_3 = new QLabel(CTabWorkDayDlg);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        horizontalLayout->addWidget(label_3);

        edit_keyword = new QLineEdit(CTabWorkDayDlg);
        edit_keyword->setObjectName(QStringLiteral("edit_keyword"));
        edit_keyword->setFont(font);

        horizontalLayout->addWidget(edit_keyword);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        BTN_UPDATE = new QPushButton(CTabWorkDayDlg);
        BTN_UPDATE->setObjectName(QStringLiteral("BTN_UPDATE"));
        BTN_UPDATE->setFont(font);

        horizontalLayout->addWidget(BTN_UPDATE);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        tableView = new QTableView(CTabWorkDayDlg);
        tableView->setObjectName(QStringLiteral("tableView"));
        QFont font2;
        font2.setPointSize(11);
        font2.setBold(false);
        font2.setWeight(50);
        tableView->setFont(font2);
        tableView->setStyleSheet(QStringLiteral(""));

        verticalLayout_3->addWidget(tableView);

        label_load = new QLabel(CTabWorkDayDlg);
        label_load->setObjectName(QStringLiteral("label_load"));
        label_load->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_load);


        verticalLayout->addLayout(verticalLayout_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(CTabWorkDayDlg);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        horizontalLayout_3->addWidget(label_2);

        label_total = new QLabel(CTabWorkDayDlg);
        label_total->setObjectName(QStringLiteral("label_total"));
        QFont font3;
        font3.setPointSize(18);
        label_total->setFont(font3);
        label_total->setAlignment(Qt::AlignBottom|Qt::AlignRight|Qt::AlignTrailing);

        horizontalLayout_3->addWidget(label_total);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(CTabWorkDayDlg);

        QMetaObject::connectSlotsByName(CTabWorkDayDlg);
    } // setupUi

    void retranslateUi(QWidget *CTabWorkDayDlg)
    {
        CTabWorkDayDlg->setWindowTitle(QApplication::translate("CTabWorkDayDlg", "CTabWorkDayDlg", 0));
        label->setText(QApplication::translate("CTabWorkDayDlg", "\346\227\245\346\234\237\357\274\232", 0));
        dateEdit->setDisplayFormat(QApplication::translate("CTabWorkDayDlg", "yyyy/M/d", 0));
        label_3->setText(QApplication::translate("CTabWorkDayDlg", "\346\237\245\346\211\276\357\274\232", 0));
        BTN_UPDATE->setText(QApplication::translate("CTabWorkDayDlg", "\345\210\267\346\226\260", 0));
        label_load->setText(QApplication::translate("CTabWorkDayDlg", "TextLabel", 0));
        label_2->setText(QApplication::translate("CTabWorkDayDlg", "\346\217\220\347\244\272\357\274\232\345\217\214\345\207\273\346\237\220\344\270\200\350\241\214\350\277\233\350\241\214\346\240\270\347\256\227", 0));
        label_total->setText(QApplication::translate("CTabWorkDayDlg", "\346\200\273\350\256\241\357\274\232", 0));
    } // retranslateUi

};

namespace Ui {
    class CTabWorkDayDlg: public Ui_CTabWorkDayDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CTABWORKDAYDLG_H
