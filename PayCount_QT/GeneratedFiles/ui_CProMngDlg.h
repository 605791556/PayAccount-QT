/********************************************************************************
** Form generated from reading UI file 'CProMngDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CPROMNGDLG_H
#define UI_CPROMNGDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CProMngDlg
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *BTN_ADD;
    QPushButton *BTN_SAVE_DEX;
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;
    QLabel *label_load;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *CProMngDlg)
    {
        if (CProMngDlg->objectName().isEmpty())
            CProMngDlg->setObjectName(QStringLiteral("CProMngDlg"));
        CProMngDlg->resize(647, 711);
        verticalLayout_2 = new QVBoxLayout(CProMngDlg);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        BTN_ADD = new QPushButton(CProMngDlg);
        BTN_ADD->setObjectName(QStringLiteral("BTN_ADD"));
        QFont font;
        font.setPointSize(11);
        BTN_ADD->setFont(font);

        horizontalLayout->addWidget(BTN_ADD);

        BTN_SAVE_DEX = new QPushButton(CProMngDlg);
        BTN_SAVE_DEX->setObjectName(QStringLiteral("BTN_SAVE_DEX"));
        BTN_SAVE_DEX->setFont(font);

        horizontalLayout->addWidget(BTN_SAVE_DEX);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tableWidget = new QTableWidget(CProMngDlg);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setFont(font);

        verticalLayout->addWidget(tableWidget);

        label_load = new QLabel(CProMngDlg);
        label_load->setObjectName(QStringLiteral("label_load"));
        label_load->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_load);

        label = new QLabel(CProMngDlg);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        verticalLayout->addWidget(label);

        label_2 = new QLabel(CProMngDlg);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        verticalLayout->addWidget(label_2);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(CProMngDlg);

        QMetaObject::connectSlotsByName(CProMngDlg);
    } // setupUi

    void retranslateUi(QDialog *CProMngDlg)
    {
        CProMngDlg->setWindowTitle(QApplication::translate("CProMngDlg", "\351\241\271\347\233\256\347\256\241\347\220\206", 0));
        BTN_ADD->setText(QApplication::translate("CProMngDlg", "\346\267\273\345\212\240", 0));
        BTN_SAVE_DEX->setText(QApplication::translate("CProMngDlg", "\344\277\235\345\255\230\346\216\222\345\210\227\351\241\272\345\272\217", 0));
        label_load->setText(QApplication::translate("CProMngDlg", "TextLabel", 0));
        label->setText(QApplication::translate("CProMngDlg", "1.\357\274\210\345\260\201\351\235\242\357\274\214\345\215\260\345\210\267\357\274\214\346\212\230\351\241\265\357\274\214\347\202\271\351\241\265\357\274\214\350\203\266\350\256\242\357\274\214\346\211\223\345\214\205\357\274\214\346\240\267\344\271\246\357\274\214\345\205\245\345\272\223\357\274\211\344\270\215\345\217\257\345\210\240\351\231\244", 0));
        label_2->setText(QApplication::translate("CProMngDlg", "2.\345\215\225\345\207\273\346\216\222\345\210\227\351\241\272\345\272\217\350\277\233\350\241\214\347\274\226\350\276\221\357\274\214\347\274\226\350\276\221\345\256\214\345\220\216\350\257\267\344\277\235\345\255\230", 0));
    } // retranslateUi

};

namespace Ui {
    class CProMngDlg: public Ui_CProMngDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CPROMNGDLG_H
