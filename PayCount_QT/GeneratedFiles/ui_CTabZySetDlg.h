/********************************************************************************
** Form generated from reading UI file 'CTabZySetDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CTABZYSETDLG_H
#define UI_CTABZYSETDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CTabZySetDlg
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *EDIT_SG_D3;
    QLineEdit *EDIT_SG_2;
    QLineEdit *EDIT_S_Q4;
    QLineEdit *EDIT_SG_4;
    QLineEdit *EDIT_SG_Q4;
    QLineEdit *EDIT_G_4;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_6;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label_5;
    QLineEdit *EDIT_G_2;
    QLabel *label_8;
    QLineEdit *EDIT_G_D3;
    QLabel *label_9;
    QLineEdit *EDIT_SG_3;
    QLabel *label_7;
    QLineEdit *EDIT_G_3;
    QLineEdit *EDIT_S_3;
    QLineEdit *EDIT_S_D3;
    QLineEdit *EDIT_S_2;
    QLineEdit *EDIT_G_Q4;
    QLineEdit *EDIT_S_4;
    QPushButton *BTN_SAVE;

    void setupUi(QWidget *CTabZySetDlg)
    {
        if (CTabZySetDlg->objectName().isEmpty())
            CTabZySetDlg->setObjectName(QStringLiteral("CTabZySetDlg"));
        CTabZySetDlg->resize(814, 505);
        gridLayoutWidget = new QWidget(CTabZySetDlg);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 811, 341));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        EDIT_SG_D3 = new QLineEdit(gridLayoutWidget);
        EDIT_SG_D3->setObjectName(QStringLiteral("EDIT_SG_D3"));
        EDIT_SG_D3->setMinimumSize(QSize(0, 20));
        EDIT_SG_D3->setMaximumSize(QSize(16777215, 20));
        QFont font;
        font.setPointSize(11);
        EDIT_SG_D3->setFont(font);
        EDIT_SG_D3->setFrame(false);

        gridLayout->addWidget(EDIT_SG_D3, 1, 3, 1, 1);

        EDIT_SG_2 = new QLineEdit(gridLayoutWidget);
        EDIT_SG_2->setObjectName(QStringLiteral("EDIT_SG_2"));
        EDIT_SG_2->setMinimumSize(QSize(0, 20));
        EDIT_SG_2->setMaximumSize(QSize(16777215, 20));
        EDIT_SG_2->setFont(font);
        EDIT_SG_2->setFrame(false);

        gridLayout->addWidget(EDIT_SG_2, 1, 5, 1, 1);

        EDIT_S_Q4 = new QLineEdit(gridLayoutWidget);
        EDIT_S_Q4->setObjectName(QStringLiteral("EDIT_S_Q4"));
        EDIT_S_Q4->setMinimumSize(QSize(0, 20));
        EDIT_S_Q4->setMaximumSize(QSize(16777215, 20));
        EDIT_S_Q4->setFont(font);
        EDIT_S_Q4->setFrame(false);

        gridLayout->addWidget(EDIT_S_Q4, 2, 1, 1, 1);

        EDIT_SG_4 = new QLineEdit(gridLayoutWidget);
        EDIT_SG_4->setObjectName(QStringLiteral("EDIT_SG_4"));
        EDIT_SG_4->setMinimumSize(QSize(0, 20));
        EDIT_SG_4->setMaximumSize(QSize(16777215, 20));
        EDIT_SG_4->setFont(font);
        EDIT_SG_4->setFrame(false);

        gridLayout->addWidget(EDIT_SG_4, 1, 2, 1, 1);

        EDIT_SG_Q4 = new QLineEdit(gridLayoutWidget);
        EDIT_SG_Q4->setObjectName(QStringLiteral("EDIT_SG_Q4"));
        EDIT_SG_Q4->setMinimumSize(QSize(0, 20));
        EDIT_SG_Q4->setMaximumSize(QSize(16777215, 20));
        EDIT_SG_Q4->setFont(font);
        EDIT_SG_Q4->setFrame(false);

        gridLayout->addWidget(EDIT_SG_Q4, 1, 1, 1, 1);

        EDIT_G_4 = new QLineEdit(gridLayoutWidget);
        EDIT_G_4->setObjectName(QStringLiteral("EDIT_G_4"));
        EDIT_G_4->setMinimumSize(QSize(0, 20));
        EDIT_G_4->setMaximumSize(QSize(16777215, 20));
        EDIT_G_4->setFont(font);
        EDIT_G_4->setFrame(false);

        gridLayout->addWidget(EDIT_G_4, 3, 2, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);
        label_6->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        gridLayout->addWidget(label_6, 0, 2, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(0, 40));
        label_5->setMaximumSize(QSize(16777215, 40));
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        gridLayout->addWidget(label_5, 0, 1, 1, 1);

        EDIT_G_2 = new QLineEdit(gridLayoutWidget);
        EDIT_G_2->setObjectName(QStringLiteral("EDIT_G_2"));
        EDIT_G_2->setMinimumSize(QSize(0, 20));
        EDIT_G_2->setMaximumSize(QSize(16777215, 20));
        EDIT_G_2->setFont(font);
        EDIT_G_2->setFrame(false);

        gridLayout->addWidget(EDIT_G_2, 3, 5, 1, 1);

        label_8 = new QLabel(gridLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font);
        label_8->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        gridLayout->addWidget(label_8, 0, 4, 1, 1);

        EDIT_G_D3 = new QLineEdit(gridLayoutWidget);
        EDIT_G_D3->setObjectName(QStringLiteral("EDIT_G_D3"));
        EDIT_G_D3->setMinimumSize(QSize(0, 20));
        EDIT_G_D3->setMaximumSize(QSize(16777215, 20));
        EDIT_G_D3->setFont(font);
        EDIT_G_D3->setFrame(false);

        gridLayout->addWidget(EDIT_G_D3, 3, 3, 1, 1);

        label_9 = new QLabel(gridLayoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font);
        label_9->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        gridLayout->addWidget(label_9, 0, 5, 1, 1);

        EDIT_SG_3 = new QLineEdit(gridLayoutWidget);
        EDIT_SG_3->setObjectName(QStringLiteral("EDIT_SG_3"));
        EDIT_SG_3->setMinimumSize(QSize(0, 20));
        EDIT_SG_3->setMaximumSize(QSize(16777215, 20));
        EDIT_SG_3->setFont(font);
        EDIT_SG_3->setFrame(false);

        gridLayout->addWidget(EDIT_SG_3, 1, 4, 1, 1);

        label_7 = new QLabel(gridLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font);
        label_7->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        gridLayout->addWidget(label_7, 0, 3, 1, 1);

        EDIT_G_3 = new QLineEdit(gridLayoutWidget);
        EDIT_G_3->setObjectName(QStringLiteral("EDIT_G_3"));
        EDIT_G_3->setMinimumSize(QSize(0, 20));
        EDIT_G_3->setMaximumSize(QSize(16777215, 20));
        EDIT_G_3->setFont(font);
        EDIT_G_3->setFrame(false);

        gridLayout->addWidget(EDIT_G_3, 3, 4, 1, 1);

        EDIT_S_3 = new QLineEdit(gridLayoutWidget);
        EDIT_S_3->setObjectName(QStringLiteral("EDIT_S_3"));
        EDIT_S_3->setMinimumSize(QSize(0, 20));
        EDIT_S_3->setMaximumSize(QSize(16777215, 20));
        EDIT_S_3->setFont(font);
        EDIT_S_3->setFrame(false);

        gridLayout->addWidget(EDIT_S_3, 2, 4, 1, 1);

        EDIT_S_D3 = new QLineEdit(gridLayoutWidget);
        EDIT_S_D3->setObjectName(QStringLiteral("EDIT_S_D3"));
        EDIT_S_D3->setMinimumSize(QSize(0, 20));
        EDIT_S_D3->setMaximumSize(QSize(16777215, 20));
        EDIT_S_D3->setFont(font);
        EDIT_S_D3->setFrame(false);

        gridLayout->addWidget(EDIT_S_D3, 2, 3, 1, 1);

        EDIT_S_2 = new QLineEdit(gridLayoutWidget);
        EDIT_S_2->setObjectName(QStringLiteral("EDIT_S_2"));
        EDIT_S_2->setMinimumSize(QSize(0, 20));
        EDIT_S_2->setMaximumSize(QSize(16777215, 20));
        EDIT_S_2->setFont(font);
        EDIT_S_2->setFrame(false);

        gridLayout->addWidget(EDIT_S_2, 2, 5, 1, 1);

        EDIT_G_Q4 = new QLineEdit(gridLayoutWidget);
        EDIT_G_Q4->setObjectName(QStringLiteral("EDIT_G_Q4"));
        EDIT_G_Q4->setMinimumSize(QSize(0, 20));
        EDIT_G_Q4->setMaximumSize(QSize(16777215, 20));
        EDIT_G_Q4->setFont(font);
        EDIT_G_Q4->setFrame(false);

        gridLayout->addWidget(EDIT_G_Q4, 3, 1, 1, 1);

        EDIT_S_4 = new QLineEdit(gridLayoutWidget);
        EDIT_S_4->setObjectName(QStringLiteral("EDIT_S_4"));
        EDIT_S_4->setMinimumSize(QSize(0, 20));
        EDIT_S_4->setMaximumSize(QSize(16777215, 20));
        EDIT_S_4->setFont(font);
        EDIT_S_4->setFrame(false);

        gridLayout->addWidget(EDIT_S_4, 2, 2, 1, 1);

        BTN_SAVE = new QPushButton(CTabZySetDlg);
        BTN_SAVE->setObjectName(QStringLiteral("BTN_SAVE"));
        BTN_SAVE->setGeometry(QRect(370, 400, 91, 31));
        BTN_SAVE->setFont(font);

        retranslateUi(CTabZySetDlg);

        QMetaObject::connectSlotsByName(CTabZySetDlg);
    } // setupUi

    void retranslateUi(QWidget *CTabZySetDlg)
    {
        CTabZySetDlg->setWindowTitle(QApplication::translate("CTabZySetDlg", "CTabZySetDlg", 0));
        label->setText(QString());
        label_4->setText(QApplication::translate("CTabZySetDlg", "\345\267\245\344\272\272\357\274\232", 0));
        label_6->setText(QApplication::translate("CTabZySetDlg", "\345\233\233\346\212\230\351\241\265", 0));
        label_3->setText(QApplication::translate("CTabZySetDlg", "\345\270\210\345\202\205\357\274\232", 0));
        label_2->setText(QApplication::translate("CTabZySetDlg", "\345\270\210\345\202\205+\345\267\245\344\272\272\357\274\232", 0));
        label_5->setText(QApplication::translate("CTabZySetDlg", "\345\205\250\345\274\200\345\233\233\346\212\230\351\241\265", 0));
        label_8->setText(QApplication::translate("CTabZySetDlg", "\344\270\211\346\212\230\351\241\265", 0));
        label_9->setText(QApplication::translate("CTabZySetDlg", "\344\272\214\346\212\230\351\241\265", 0));
        label_7->setText(QApplication::translate("CTabZySetDlg", "\345\244\247\344\270\211\346\212\230\351\241\265", 0));
        BTN_SAVE->setText(QApplication::translate("CTabZySetDlg", "\344\277\235\345\255\230", 0));
    } // retranslateUi

};

namespace Ui {
    class CTabZySetDlg: public Ui_CTabZySetDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CTABZYSETDLG_H
