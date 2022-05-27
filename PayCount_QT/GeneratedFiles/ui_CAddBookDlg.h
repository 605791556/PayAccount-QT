/********************************************************************************
** Form generated from reading UI file 'CAddBookDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CADDBOOKDLG_H
#define UI_CADDBOOKDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CAddBookDlg
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *EDIT_CC1;
    QLabel *label_16;
    QLineEdit *EDIT_CC2;
    QLabel *label_5;
    QLabel *label_4;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_12;
    QSpacerItem *horizontalSpacer_11;
    QSpacerItem *horizontalSpacer_10;
    QSpacerItem *horizontalSpacer_13;
    QComboBox *CBX_ZY;
    QLineEdit *EDIT_YZ;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *EDIT_LS;
    QLineEdit *EDIT_BC;
    QLineEdit *EDIT_YS;
    QLineEdit *EDIT_KB;
    QSpacerItem *horizontalSpacer;
    QDateEdit *EDIT_DATE;
    QLineEdit *EDIT_CBS;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *EDIT_NAME;
    QHBoxLayout *horizontalLayout;
    QLineEdit *EDIT_BC1;
    QLabel *label_15;
    QLineEdit *EDIT_BC2;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *RDO_QK;
    QRadioButton *RDO_DK;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QComboBox *CBX_RK;
    QTextEdit *EDIT_BZ;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *horizontalSpacer_14;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *BTN_SAVE;

    void setupUi(QDialog *CAddBookDlg)
    {
        if (CAddBookDlg->objectName().isEmpty())
            CAddBookDlg->setObjectName(QStringLiteral("CAddBookDlg"));
        CAddBookDlg->resize(368, 541);
        verticalLayout = new QVBoxLayout(CAddBookDlg);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        EDIT_CC1 = new QLineEdit(CAddBookDlg);
        EDIT_CC1->setObjectName(QStringLiteral("EDIT_CC1"));
        EDIT_CC1->setMinimumSize(QSize(0, 25));
        EDIT_CC1->setMaximumSize(QSize(16777215, 25));
        QFont font;
        font.setPointSize(11);
        EDIT_CC1->setFont(font);

        horizontalLayout_2->addWidget(EDIT_CC1);

        label_16 = new QLabel(CAddBookDlg);
        label_16->setObjectName(QStringLiteral("label_16"));

        horizontalLayout_2->addWidget(label_16);

        EDIT_CC2 = new QLineEdit(CAddBookDlg);
        EDIT_CC2->setObjectName(QStringLiteral("EDIT_CC2"));
        EDIT_CC2->setMinimumSize(QSize(0, 25));
        EDIT_CC2->setMaximumSize(QSize(16777215, 25));
        EDIT_CC2->setFont(font);

        horizontalLayout_2->addWidget(EDIT_CC2);


        gridLayout->addLayout(horizontalLayout_2, 4, 1, 1, 1);

        label_5 = new QLabel(CAddBookDlg);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        label_4 = new QLabel(CAddBookDlg);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        label_3 = new QLabel(CAddBookDlg);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_12, 11, 2, 1, 1);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_11, 10, 2, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_10, 9, 2, 1, 1);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_13, 12, 2, 1, 1);

        CBX_ZY = new QComboBox(CAddBookDlg);
        CBX_ZY->setObjectName(QStringLiteral("CBX_ZY"));
        CBX_ZY->setMinimumSize(QSize(0, 25));
        CBX_ZY->setMaximumSize(QSize(16777215, 25));
        CBX_ZY->setFont(font);

        gridLayout->addWidget(CBX_ZY, 11, 1, 1, 1);

        EDIT_YZ = new QLineEdit(CAddBookDlg);
        EDIT_YZ->setObjectName(QStringLiteral("EDIT_YZ"));
        EDIT_YZ->setMinimumSize(QSize(0, 25));
        EDIT_YZ->setMaximumSize(QSize(16777215, 25));
        EDIT_YZ->setFont(font);

        gridLayout->addWidget(EDIT_YZ, 6, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 2, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        EDIT_LS = new QLineEdit(CAddBookDlg);
        EDIT_LS->setObjectName(QStringLiteral("EDIT_LS"));
        EDIT_LS->setMinimumSize(QSize(0, 25));
        EDIT_LS->setMaximumSize(QSize(16777215, 25));
        EDIT_LS->setFont(font);

        gridLayout->addWidget(EDIT_LS, 9, 1, 1, 1);

        EDIT_BC = new QLineEdit(CAddBookDlg);
        EDIT_BC->setObjectName(QStringLiteral("EDIT_BC"));
        EDIT_BC->setMinimumSize(QSize(0, 25));
        EDIT_BC->setMaximumSize(QSize(16777215, 25));
        EDIT_BC->setFont(font);

        gridLayout->addWidget(EDIT_BC, 8, 1, 1, 1);

        EDIT_YS = new QLineEdit(CAddBookDlg);
        EDIT_YS->setObjectName(QStringLiteral("EDIT_YS"));
        EDIT_YS->setMinimumSize(QSize(0, 25));
        EDIT_YS->setMaximumSize(QSize(16777215, 25));
        EDIT_YS->setFont(font);

        gridLayout->addWidget(EDIT_YS, 7, 1, 1, 1);

        EDIT_KB = new QLineEdit(CAddBookDlg);
        EDIT_KB->setObjectName(QStringLiteral("EDIT_KB"));
        EDIT_KB->setMinimumSize(QSize(0, 25));
        EDIT_KB->setMaximumSize(QSize(16777215, 25));
        EDIT_KB->setFont(font);

        gridLayout->addWidget(EDIT_KB, 5, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);

        EDIT_DATE = new QDateEdit(CAddBookDlg);
        EDIT_DATE->setObjectName(QStringLiteral("EDIT_DATE"));
        EDIT_DATE->setMinimumSize(QSize(0, 25));
        EDIT_DATE->setMaximumSize(QSize(16777215, 25));
        EDIT_DATE->setFont(font);
        EDIT_DATE->setWrapping(false);
        EDIT_DATE->setFrame(false);
        EDIT_DATE->setReadOnly(false);
        EDIT_DATE->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        EDIT_DATE->setCalendarPopup(true);

        gridLayout->addWidget(EDIT_DATE, 2, 1, 1, 1);

        EDIT_CBS = new QLineEdit(CAddBookDlg);
        EDIT_CBS->setObjectName(QStringLiteral("EDIT_CBS"));
        EDIT_CBS->setMinimumSize(QSize(0, 25));
        EDIT_CBS->setMaximumSize(QSize(16777215, 25));
        EDIT_CBS->setFont(font);

        gridLayout->addWidget(EDIT_CBS, 1, 1, 1, 1);

        label = new QLabel(CAddBookDlg);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(CAddBookDlg);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        EDIT_NAME = new QLineEdit(CAddBookDlg);
        EDIT_NAME->setObjectName(QStringLiteral("EDIT_NAME"));
        EDIT_NAME->setMinimumSize(QSize(0, 25));
        EDIT_NAME->setMaximumSize(QSize(16777215, 25));
        EDIT_NAME->setFont(font);

        gridLayout->addWidget(EDIT_NAME, 0, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        EDIT_BC1 = new QLineEdit(CAddBookDlg);
        EDIT_BC1->setObjectName(QStringLiteral("EDIT_BC1"));
        EDIT_BC1->setMinimumSize(QSize(0, 25));
        EDIT_BC1->setMaximumSize(QSize(16777215, 25));
        EDIT_BC1->setFont(font);

        horizontalLayout->addWidget(EDIT_BC1);

        label_15 = new QLabel(CAddBookDlg);
        label_15->setObjectName(QStringLiteral("label_15"));

        horizontalLayout->addWidget(label_15);

        EDIT_BC2 = new QLineEdit(CAddBookDlg);
        EDIT_BC2->setObjectName(QStringLiteral("EDIT_BC2"));
        EDIT_BC2->setMinimumSize(QSize(0, 25));
        EDIT_BC2->setMaximumSize(QSize(16777215, 25));
        EDIT_BC2->setFont(font);

        horizontalLayout->addWidget(EDIT_BC2);


        gridLayout->addLayout(horizontalLayout, 3, 1, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        RDO_QK = new QRadioButton(CAddBookDlg);
        RDO_QK->setObjectName(QStringLiteral("RDO_QK"));
        RDO_QK->setFont(font);

        horizontalLayout_3->addWidget(RDO_QK);

        RDO_DK = new QRadioButton(CAddBookDlg);
        RDO_DK->setObjectName(QStringLiteral("RDO_DK"));
        RDO_DK->setFont(font);

        horizontalLayout_3->addWidget(RDO_DK);


        gridLayout->addLayout(horizontalLayout_3, 10, 1, 1, 1);

        label_6 = new QLabel(CAddBookDlg);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        label_7 = new QLabel(CAddBookDlg);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font);
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_7, 6, 0, 1, 1);

        label_8 = new QLabel(CAddBookDlg);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font);
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_8, 7, 0, 1, 1);

        label_9 = new QLabel(CAddBookDlg);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font);
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_9, 8, 0, 1, 1);

        label_10 = new QLabel(CAddBookDlg);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setFont(font);
        label_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_10, 9, 0, 1, 1);

        label_11 = new QLabel(CAddBookDlg);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setFont(font);
        label_11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_11, 10, 0, 1, 1);

        label_12 = new QLabel(CAddBookDlg);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setFont(font);
        label_12->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_12, 11, 0, 1, 1);

        label_13 = new QLabel(CAddBookDlg);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setFont(font);
        label_13->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_13, 12, 0, 1, 1);

        label_14 = new QLabel(CAddBookDlg);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setFont(font);
        label_14->setAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);

        gridLayout->addWidget(label_14, 13, 0, 1, 1);

        CBX_RK = new QComboBox(CAddBookDlg);
        CBX_RK->setObjectName(QStringLiteral("CBX_RK"));
        CBX_RK->setMinimumSize(QSize(0, 25));
        CBX_RK->setMaximumSize(QSize(16777215, 25));
        CBX_RK->setFont(font);

        gridLayout->addWidget(CBX_RK, 12, 1, 1, 1);

        EDIT_BZ = new QTextEdit(CAddBookDlg);
        EDIT_BZ->setObjectName(QStringLiteral("EDIT_BZ"));
        EDIT_BZ->setFont(font);

        gridLayout->addWidget(EDIT_BZ, 13, 1, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 5, 2, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_7, 6, 2, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 4, 2, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_8, 7, 2, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 3, 2, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_9, 8, 2, 1, 1);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_14, 13, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        BTN_SAVE = new QPushButton(CAddBookDlg);
        BTN_SAVE->setObjectName(QStringLiteral("BTN_SAVE"));
        BTN_SAVE->setFont(font);

        horizontalLayout_5->addWidget(BTN_SAVE);


        verticalLayout->addLayout(horizontalLayout_5);


        retranslateUi(CAddBookDlg);

        QMetaObject::connectSlotsByName(CAddBookDlg);
    } // setupUi

    void retranslateUi(QDialog *CAddBookDlg)
    {
        CAddBookDlg->setWindowTitle(QApplication::translate("CAddBookDlg", "\346\267\273\345\212\240/\347\274\226\350\276\221", 0));
        label_16->setText(QApplication::translate("CAddBookDlg", "*", 0));
        label_5->setText(QApplication::translate("CAddBookDlg", "\346\210\220\345\223\201\345\260\272\345\257\270\357\274\232", 0));
        label_4->setText(QApplication::translate("CAddBookDlg", "\347\211\210\346\254\241\357\274\232", 0));
        label_3->setText(QApplication::translate("CAddBookDlg", "\344\270\213\345\215\225\346\227\245\346\234\237\357\274\232", 0));
        label->setText(QApplication::translate("CAddBookDlg", "\344\271\246\345\220\215\357\274\232", 0));
        label_2->setText(QApplication::translate("CAddBookDlg", "\345\207\272\347\211\210\347\244\276\357\274\232", 0));
        label_15->setText(QApplication::translate("CAddBookDlg", "--", 0));
        RDO_QK->setText(QApplication::translate("CAddBookDlg", "\345\205\250\345\274\200", 0));
        RDO_DK->setText(QApplication::translate("CAddBookDlg", "\345\257\271\345\274\200", 0));
        label_6->setText(QApplication::translate("CAddBookDlg", "\345\274\200\346\234\254\357\274\232", 0));
        label_7->setText(QApplication::translate("CAddBookDlg", "\345\215\260\345\274\240\357\274\232", 0));
        label_8->setText(QApplication::translate("CAddBookDlg", "\345\215\260\346\225\260\357\274\232", 0));
        label_9->setText(QApplication::translate("CAddBookDlg", "\345\214\205\345\206\214\357\274\232", 0));
        label_10->setText(QApplication::translate("CAddBookDlg", "\344\273\244\346\225\260\357\274\232", 0));
        label_11->setText(QApplication::translate("CAddBookDlg", "\345\215\260\345\274\240\347\261\273\345\236\213\357\274\232", 0));
        label_12->setText(QApplication::translate("CAddBookDlg", "\346\212\230\351\241\265\347\261\273\345\236\213\357\274\232", 0));
        label_13->setText(QApplication::translate("CAddBookDlg", "\345\205\245\345\272\223\357\274\232", 0));
        label_14->setText(QApplication::translate("CAddBookDlg", "\345\244\207\346\263\250\357\274\232", 0));
        BTN_SAVE->setText(QApplication::translate("CAddBookDlg", "\346\267\273\345\212\240", 0));
    } // retranslateUi

};

namespace Ui {
    class CAddBookDlg: public Ui_CAddBookDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CADDBOOKDLG_H
