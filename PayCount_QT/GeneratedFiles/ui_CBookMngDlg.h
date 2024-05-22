/********************************************************************************
** Form generated from reading UI file 'CBookMngDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CBOOKMNGDLG_H
#define UI_CBOOKMNGDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
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

class Ui_CBookMngDlg
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *EDIT_KEY;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_2;
    QComboBox *COMBO_RK;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_3;
    QComboBox *COMBO_DATE;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *BTN_FIND;
    QPushButton *BTN_ADD;
    QPushButton *BTN_PL_RK;
    QPushButton *BTN_PL_DEL;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_all;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_dex;
    QLineEdit *EDIT_GO;
    QPushButton *BTN_GO;
    QPushButton *BTN_LAST;
    QPushButton *BTN_NEXT;

    void setupUi(QDialog *CBookMngDlg)
    {
        if (CBookMngDlg->objectName().isEmpty())
            CBookMngDlg->setObjectName(QStringLiteral("CBookMngDlg"));
        CBookMngDlg->setWindowModality(Qt::NonModal);
        CBookMngDlg->resize(1101, 628);
        verticalLayout = new QVBoxLayout(CBookMngDlg);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(CBookMngDlg);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(60, 0));
        label->setMaximumSize(QSize(60, 16777215));
        QFont font;
        font.setPointSize(11);
        label->setFont(font);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label);

        EDIT_KEY = new QLineEdit(CBookMngDlg);
        EDIT_KEY->setObjectName(QStringLiteral("EDIT_KEY"));
        EDIT_KEY->setMinimumSize(QSize(120, 25));
        EDIT_KEY->setMaximumSize(QSize(120, 25));
        EDIT_KEY->setFont(font);

        horizontalLayout->addWidget(EDIT_KEY);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label_2 = new QLabel(CBookMngDlg);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(50, 0));
        label_2->setMaximumSize(QSize(50, 16777215));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_2);

        COMBO_RK = new QComboBox(CBookMngDlg);
        COMBO_RK->setObjectName(QStringLiteral("COMBO_RK"));
        COMBO_RK->setMinimumSize(QSize(70, 25));
        COMBO_RK->setMaximumSize(QSize(70, 25));
        COMBO_RK->setFont(font);

        horizontalLayout->addWidget(COMBO_RK);

        horizontalSpacer_3 = new QSpacerItem(60, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        label_3 = new QLabel(CBookMngDlg);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(70, 0));
        label_3->setMaximumSize(QSize(70, 16777215));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_3);

        COMBO_DATE = new QComboBox(CBookMngDlg);
        COMBO_DATE->setObjectName(QStringLiteral("COMBO_DATE"));
        COMBO_DATE->setMinimumSize(QSize(150, 25));
        COMBO_DATE->setMaximumSize(QSize(150, 25));
        COMBO_DATE->setFont(font);

        horizontalLayout->addWidget(COMBO_DATE);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        BTN_FIND = new QPushButton(CBookMngDlg);
        BTN_FIND->setObjectName(QStringLiteral("BTN_FIND"));
        BTN_FIND->setFont(font);

        horizontalLayout->addWidget(BTN_FIND);

        BTN_ADD = new QPushButton(CBookMngDlg);
        BTN_ADD->setObjectName(QStringLiteral("BTN_ADD"));
        BTN_ADD->setFont(font);

        horizontalLayout->addWidget(BTN_ADD);

        BTN_PL_RK = new QPushButton(CBookMngDlg);
        BTN_PL_RK->setObjectName(QStringLiteral("BTN_PL_RK"));

        horizontalLayout->addWidget(BTN_PL_RK);

        BTN_PL_DEL = new QPushButton(CBookMngDlg);
        BTN_PL_DEL->setObjectName(QStringLiteral("BTN_PL_DEL"));

        horizontalLayout->addWidget(BTN_PL_DEL);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        tableWidget = new QTableWidget(CBookMngDlg);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setFont(font);

        horizontalLayout_2->addWidget(tableWidget);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_all = new QLabel(CBookMngDlg);
        label_all->setObjectName(QStringLiteral("label_all"));
        label_all->setFont(font);

        horizontalLayout_3->addWidget(label_all);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        label_dex = new QLabel(CBookMngDlg);
        label_dex->setObjectName(QStringLiteral("label_dex"));
        label_dex->setFont(font);

        horizontalLayout_3->addWidget(label_dex);

        EDIT_GO = new QLineEdit(CBookMngDlg);
        EDIT_GO->setObjectName(QStringLiteral("EDIT_GO"));
        EDIT_GO->setMinimumSize(QSize(30, 0));
        EDIT_GO->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_3->addWidget(EDIT_GO);

        BTN_GO = new QPushButton(CBookMngDlg);
        BTN_GO->setObjectName(QStringLiteral("BTN_GO"));
        BTN_GO->setMinimumSize(QSize(34, 34));
        BTN_GO->setMaximumSize(QSize(34, 34));
        BTN_GO->setFont(font);

        horizontalLayout_3->addWidget(BTN_GO);

        BTN_LAST = new QPushButton(CBookMngDlg);
        BTN_LAST->setObjectName(QStringLiteral("BTN_LAST"));
        BTN_LAST->setFont(font);

        horizontalLayout_3->addWidget(BTN_LAST);

        BTN_NEXT = new QPushButton(CBookMngDlg);
        BTN_NEXT->setObjectName(QStringLiteral("BTN_NEXT"));
        BTN_NEXT->setFont(font);

        horizontalLayout_3->addWidget(BTN_NEXT);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(CBookMngDlg);

        QMetaObject::connectSlotsByName(CBookMngDlg);
    } // setupUi

    void retranslateUi(QDialog *CBookMngDlg)
    {
        CBookMngDlg->setWindowTitle(QApplication::translate("CBookMngDlg", "\345\233\276\344\271\246\347\256\241\347\220\206", 0));
        label->setText(QApplication::translate("CBookMngDlg", "\345\205\263\351\224\256\350\257\215\357\274\232", 0));
        label_2->setText(QApplication::translate("CBookMngDlg", "\345\205\245\345\272\223\357\274\232", 0));
        label_3->setText(QApplication::translate("CBookMngDlg", "\344\270\213\345\215\225\346\227\245\346\234\237\357\274\232", 0));
        BTN_FIND->setText(QApplication::translate("CBookMngDlg", "\346\237\245\350\257\242", 0));
        BTN_ADD->setText(QApplication::translate("CBookMngDlg", "\346\267\273\345\212\240", 0));
        BTN_PL_RK->setText(QApplication::translate("CBookMngDlg", "\346\211\271\351\207\217\345\205\245\345\272\223", 0));
        BTN_PL_DEL->setText(QApplication::translate("CBookMngDlg", "\346\211\271\351\207\217\345\210\240\351\231\244", 0));
        label_all->setText(QApplication::translate("CBookMngDlg", "\345\205\2610\346\235\241\350\256\260\345\275\225", 0));
        label_dex->setText(QApplication::translate("CBookMngDlg", "\345\205\2610\351\241\265 \347\254\2540\351\241\265", 0));
        BTN_GO->setText(QApplication::translate("CBookMngDlg", "Go", 0));
        BTN_LAST->setText(QApplication::translate("CBookMngDlg", "\344\270\212\344\270\200\351\241\265", 0));
        BTN_NEXT->setText(QApplication::translate("CBookMngDlg", "\344\270\213\344\270\200\351\241\265", 0));
    } // retranslateUi

};

namespace Ui {
    class CBookMngDlg: public Ui_CBookMngDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CBOOKMNGDLG_H
