/********************************************************************************
** Form generated from reading UI file 'CAddStaffDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CADDSTAFFDLG_H
#define UI_CADDSTAFFDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CAddStaffDlg
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *EDIT_DAYPAY;
    QLabel *label_9;
    QLabel *label_8;
    QSpacerItem *verticalSpacer_7;
    QLabel *label_4;
    QLabel *label_5;
    QSpacerItem *verticalSpacer_5;
    QLineEdit *EDIT_DEX;
    QLabel *label_7;
    QLineEdit *EDIT_IDCARD;
    QLineEdit *EDIT_TEL;
    QLabel *label_2;
    QLabel *label;
    QLineEdit *EDIT_NAME;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer_6;
    QComboBox *COMBO_TYPE;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_8;
    QComboBox *COMBO_SEX;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *BTN_SAVE;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *CAddStaffDlg)
    {
        if (CAddStaffDlg->objectName().isEmpty())
            CAddStaffDlg->setObjectName(QStringLiteral("CAddStaffDlg"));
        CAddStaffDlg->resize(304, 401);
        verticalLayout = new QVBoxLayout(CAddStaffDlg);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        EDIT_DAYPAY = new QLineEdit(CAddStaffDlg);
        EDIT_DAYPAY->setObjectName(QStringLiteral("EDIT_DAYPAY"));
        QFont font;
        font.setPointSize(11);
        EDIT_DAYPAY->setFont(font);

        horizontalLayout->addWidget(EDIT_DAYPAY);

        label_9 = new QLabel(CAddStaffDlg);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font);

        horizontalLayout->addWidget(label_9);


        gridLayout->addLayout(horizontalLayout, 6, 1, 1, 1);

        label_8 = new QLabel(CAddStaffDlg);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font);
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_8, 6, 0, 1, 1);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_7, 5, 2, 1, 1);

        label_4 = new QLabel(CAddStaffDlg);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        label_5 = new QLabel(CAddStaffDlg);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_5, 3, 0, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_5, 3, 2, 1, 1);

        EDIT_DEX = new QLineEdit(CAddStaffDlg);
        EDIT_DEX->setObjectName(QStringLiteral("EDIT_DEX"));
        EDIT_DEX->setFont(font);

        gridLayout->addWidget(EDIT_DEX, 5, 1, 1, 1);

        label_7 = new QLabel(CAddStaffDlg);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font);
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_7, 5, 0, 1, 1);

        EDIT_IDCARD = new QLineEdit(CAddStaffDlg);
        EDIT_IDCARD->setObjectName(QStringLiteral("EDIT_IDCARD"));
        EDIT_IDCARD->setFont(font);

        gridLayout->addWidget(EDIT_IDCARD, 2, 1, 1, 1);

        EDIT_TEL = new QLineEdit(CAddStaffDlg);
        EDIT_TEL->setObjectName(QStringLiteral("EDIT_TEL"));
        EDIT_TEL->setFont(font);

        gridLayout->addWidget(EDIT_TEL, 3, 1, 1, 1);

        label_2 = new QLabel(CAddStaffDlg);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label = new QLabel(CAddStaffDlg);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        EDIT_NAME = new QLineEdit(CAddStaffDlg);
        EDIT_NAME->setObjectName(QStringLiteral("EDIT_NAME"));
        EDIT_NAME->setFont(font);

        gridLayout->addWidget(EDIT_NAME, 0, 1, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_4, 2, 2, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_6, 4, 2, 1, 1);

        COMBO_TYPE = new QComboBox(CAddStaffDlg);
        COMBO_TYPE->setObjectName(QStringLiteral("COMBO_TYPE"));
        COMBO_TYPE->setFont(font);

        gridLayout->addWidget(COMBO_TYPE, 4, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 1, 2, 1, 1);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_8, 6, 2, 1, 1);

        COMBO_SEX = new QComboBox(CAddStaffDlg);
        COMBO_SEX->setObjectName(QStringLiteral("COMBO_SEX"));
        COMBO_SEX->setFont(font);

        gridLayout->addWidget(COMBO_SEX, 1, 1, 1, 1);

        label_6 = new QLabel(CAddStaffDlg);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_6, 4, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        BTN_SAVE = new QPushButton(CAddStaffDlg);
        BTN_SAVE->setObjectName(QStringLiteral("BTN_SAVE"));
        BTN_SAVE->setFont(font);

        horizontalLayout_2->addWidget(BTN_SAVE);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(CAddStaffDlg);

        QMetaObject::connectSlotsByName(CAddStaffDlg);
    } // setupUi

    void retranslateUi(QDialog *CAddStaffDlg)
    {
        CAddStaffDlg->setWindowTitle(QApplication::translate("CAddStaffDlg", "\346\267\273\345\212\240/\347\274\226\350\276\221", 0));
        label_9->setText(QApplication::translate("CAddStaffDlg", "/\345\244\251", 0));
        label_8->setText(QApplication::translate("CAddStaffDlg", "\346\227\245\345\267\245\350\265\204\357\274\232", 0));
        label_4->setText(QApplication::translate("CAddStaffDlg", "\350\272\253\344\273\275\350\257\201\345\217\267\357\274\232", 0));
        label_5->setText(QApplication::translate("CAddStaffDlg", "\350\201\224\347\263\273\346\226\271\345\274\217\357\274\232", 0));
        label_7->setText(QApplication::translate("CAddStaffDlg", "\346\216\222\345\272\217\345\200\274\357\274\232", 0));
        EDIT_IDCARD->setPlaceholderText(QApplication::translate("CAddStaffDlg", "\345\217\257\344\270\215\345\241\253", 0));
        label_2->setText(QApplication::translate("CAddStaffDlg", "\346\200\247\345\210\253\357\274\232", 0));
        label->setText(QApplication::translate("CAddStaffDlg", "\345\247\223\345\220\215\357\274\232", 0));
        label_6->setText(QApplication::translate("CAddStaffDlg", "\347\261\273\345\236\213\357\274\232", 0));
        BTN_SAVE->setText(QApplication::translate("CAddStaffDlg", "\346\267\273\345\212\240", 0));
    } // retranslateUi

};

namespace Ui {
    class CAddStaffDlg: public Ui_CAddStaffDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CADDSTAFFDLG_H
