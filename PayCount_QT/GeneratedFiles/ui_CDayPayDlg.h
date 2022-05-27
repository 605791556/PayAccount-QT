/********************************************************************************
** Form generated from reading UI file 'CDayPayDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CDAYPAYDLG_H
#define UI_CDAYPAYDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CDayPayDlg
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_title;
    QPushButton *BTN_MAX;
    QPushButton *BTN_CLOSE;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_9;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *edit_payday;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *edit_day;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_tpay;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *edit_delpay;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_5;
    QLineEdit *edit_delmsg;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *BTN_ADD;
    QHBoxLayout *horizontalLayout_6;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_jpay;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *BTN_SAVE;
    QSpacerItem *horizontalSpacer_8;
    QLabel *label_all;

    void setupUi(QDialog *CDayPayDlg)
    {
        if (CDayPayDlg->objectName().isEmpty())
            CDayPayDlg->setObjectName(QStringLiteral("CDayPayDlg"));
        CDayPayDlg->setWindowModality(Qt::NonModal);
        CDayPayDlg->resize(1032, 680);
        CDayPayDlg->setSizeGripEnabled(false);
        CDayPayDlg->setModal(false);
        verticalLayout_3 = new QVBoxLayout(CDayPayDlg);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_title = new QLabel(CDayPayDlg);
        label_title->setObjectName(QStringLiteral("label_title"));
        QFont font;
        font.setPointSize(11);
        label_title->setFont(font);

        horizontalLayout_11->addWidget(label_title);

        BTN_MAX = new QPushButton(CDayPayDlg);
        BTN_MAX->setObjectName(QStringLiteral("BTN_MAX"));
        BTN_MAX->setMinimumSize(QSize(25, 25));
        BTN_MAX->setMaximumSize(QSize(25, 25));

        horizontalLayout_11->addWidget(BTN_MAX);

        BTN_CLOSE = new QPushButton(CDayPayDlg);
        BTN_CLOSE->setObjectName(QStringLiteral("BTN_CLOSE"));
        BTN_CLOSE->setMinimumSize(QSize(25, 25));
        BTN_CLOSE->setMaximumSize(QSize(25, 25));

        horizontalLayout_11->addWidget(BTN_CLOSE);


        verticalLayout_3->addLayout(horizontalLayout_11);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        groupBox = new QGroupBox(CDayPayDlg);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayout_9 = new QHBoxLayout(groupBox);
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(-1, -1, -1, 0);
        edit_payday = new QLineEdit(groupBox);
        edit_payday->setObjectName(QStringLiteral("edit_payday"));
        edit_payday->setMinimumSize(QSize(80, 25));
        edit_payday->setMaximumSize(QSize(80, 25));
        edit_payday->setFont(font);
        edit_payday->setFrame(true);

        horizontalLayout_4->addWidget(edit_payday);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        horizontalLayout_4->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        edit_day = new QLineEdit(groupBox);
        edit_day->setObjectName(QStringLiteral("edit_day"));
        edit_day->setMinimumSize(QSize(60, 25));
        edit_day->setMaximumSize(QSize(60, 25));
        edit_day->setFont(font);

        horizontalLayout_4->addWidget(edit_day);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        horizontalLayout_4->addWidget(label_2);

        horizontalSpacer_3 = new QSpacerItem(80, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        label_tpay = new QLabel(groupBox);
        label_tpay->setObjectName(QStringLiteral("label_tpay"));
        label_tpay->setFont(font);

        horizontalLayout_4->addWidget(label_tpay);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);


        horizontalLayout_9->addLayout(horizontalLayout_4);


        horizontalLayout->addWidget(groupBox);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        groupBox_2 = new QGroupBox(CDayPayDlg);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        horizontalLayout_3->addWidget(label_3);

        edit_delpay = new QLineEdit(groupBox_2);
        edit_delpay->setObjectName(QStringLiteral("edit_delpay"));
        edit_delpay->setMinimumSize(QSize(60, 25));
        edit_delpay->setMaximumSize(QSize(80, 25));
        edit_delpay->setFont(font);

        horizontalLayout_3->addWidget(edit_delpay);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        horizontalLayout_3->addWidget(label_4);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        horizontalLayout_3->addWidget(label_5);

        edit_delmsg = new QLineEdit(groupBox_2);
        edit_delmsg->setObjectName(QStringLiteral("edit_delmsg"));
        edit_delmsg->setMinimumSize(QSize(200, 25));
        edit_delmsg->setMaximumSize(QSize(300, 25));
        edit_delmsg->setFont(font);

        horizontalLayout_3->addWidget(edit_delmsg);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout_3);


        horizontalLayout_2->addWidget(groupBox_2);


        verticalLayout_3->addLayout(horizontalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);

        BTN_ADD = new QPushButton(CDayPayDlg);
        BTN_ADD->setObjectName(QStringLiteral("BTN_ADD"));
        BTN_ADD->setMinimumSize(QSize(40, 25));
        BTN_ADD->setMaximumSize(QSize(40, 25));

        horizontalLayout_5->addWidget(BTN_ADD);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        tableWidget = new QTableWidget(CDayPayDlg);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setFont(font);

        horizontalLayout_6->addWidget(tableWidget);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_jpay = new QLabel(CDayPayDlg);
        label_jpay->setObjectName(QStringLiteral("label_jpay"));
        label_jpay->setFont(font);
        label_jpay->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_7->addWidget(label_jpay);


        verticalLayout->addLayout(horizontalLayout_7);


        verticalLayout_3->addLayout(verticalLayout);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_7);

        BTN_SAVE = new QPushButton(CDayPayDlg);
        BTN_SAVE->setObjectName(QStringLiteral("BTN_SAVE"));
        BTN_SAVE->setMinimumSize(QSize(80, 30));
        BTN_SAVE->setMaximumSize(QSize(80, 30));
        BTN_SAVE->setFont(font);
        BTN_SAVE->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_8->addWidget(BTN_SAVE);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_8);

        label_all = new QLabel(CDayPayDlg);
        label_all->setObjectName(QStringLiteral("label_all"));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        label_all->setFont(font1);
        label_all->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_8->addWidget(label_all);


        verticalLayout_3->addLayout(horizontalLayout_8);


        retranslateUi(CDayPayDlg);
        QObject::connect(BTN_CLOSE, SIGNAL(clicked()), CDayPayDlg, SLOT(reject()));

        QMetaObject::connectSlotsByName(CDayPayDlg);
    } // setupUi

    void retranslateUi(QDialog *CDayPayDlg)
    {
        CDayPayDlg->setWindowTitle(QApplication::translate("CDayPayDlg", "CDayPayDlg", 0));
        label_title->setText(QApplication::translate("CDayPayDlg", "title", 0));
        BTN_MAX->setText(QString());
        BTN_CLOSE->setText(QString());
        groupBox->setTitle(QString());
        edit_payday->setPlaceholderText(QString());
        label->setText(QApplication::translate("CDayPayDlg", "\345\205\203/\345\244\251", 0));
        label_2->setText(QApplication::translate("CDayPayDlg", "\345\244\251", 0));
        label_tpay->setText(QApplication::translate("CDayPayDlg", "\351\207\221\351\242\235\357\274\232", 0));
        groupBox_2->setTitle(QString());
        label_3->setText(QApplication::translate("CDayPayDlg", "\346\211\243\351\231\244\357\274\232", 0));
        label_4->setText(QApplication::translate("CDayPayDlg", "\345\205\203", 0));
        label_5->setText(QApplication::translate("CDayPayDlg", "\350\257\264\346\230\216\357\274\232", 0));
        BTN_ADD->setText(QApplication::translate("CDayPayDlg", "\346\267\273\345\212\240", 0));
        label_jpay->setText(QApplication::translate("CDayPayDlg", "\351\207\221\351\242\235\357\274\232", 0));
        BTN_SAVE->setText(QApplication::translate("CDayPayDlg", "\344\277\235\345\255\230", 0));
        label_all->setText(QApplication::translate("CDayPayDlg", "\346\200\273\350\256\241\357\274\232", 0));
    } // retranslateUi

};

namespace Ui {
    class CDayPayDlg: public Ui_CDayPayDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CDAYPAYDLG_H
