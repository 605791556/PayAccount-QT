/********************************************************************************
** Form generated from reading UI file 'CTabJdSetDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CTABJDSETDLG_H
#define UI_CTABJDSETDLG_H

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

class Ui_CTabJdSetDlg
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *EDIT_SG_2_5;
    QLineEdit *EDIT_SG_10;
    QLineEdit *EDIT_S_W;
    QLineEdit *EDIT_SG_2;
    QLineEdit *EDIT_SG_W;
    QLineEdit *EDIT_G_2;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_6;
    QLabel *label_3;
    QLabel *label_2;
    QLineEdit *EDIT_SG_18;
    QLabel *label_5;
    QLineEdit *EDIT_G_10;
    QLabel *label_8;
    QLabel *label_10;
    QLineEdit *EDIT_G_2_5;
    QLabel *label_9;
    QLineEdit *EDIT_SG_5_9;
    QLineEdit *EDIT_G_18;
    QLabel *label_7;
    QLineEdit *EDIT_G_5_9;
    QLineEdit *EDIT_S_18;
    QLineEdit *EDIT_S_5_9;
    QLineEdit *EDIT_S_2_5;
    QLineEdit *EDIT_S_10;
    QLineEdit *EDIT_G_W;
    QLineEdit *EDIT_S_2;
    QPushButton *BTN_SAVE;

    void setupUi(QWidget *CTabJdSetDlg)
    {
        if (CTabJdSetDlg->objectName().isEmpty())
            CTabJdSetDlg->setObjectName(QStringLiteral("CTabJdSetDlg"));
        CTabJdSetDlg->resize(814, 505);
        gridLayoutWidget = new QWidget(CTabJdSetDlg);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 811, 341));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        EDIT_SG_2_5 = new QLineEdit(gridLayoutWidget);
        EDIT_SG_2_5->setObjectName(QStringLiteral("EDIT_SG_2_5"));
        EDIT_SG_2_5->setMinimumSize(QSize(0, 20));
        EDIT_SG_2_5->setMaximumSize(QSize(16777215, 20));
        QFont font;
        font.setPointSize(11);
        EDIT_SG_2_5->setFont(font);
        EDIT_SG_2_5->setFrame(false);

        gridLayout->addWidget(EDIT_SG_2_5, 1, 3, 1, 1);

        EDIT_SG_10 = new QLineEdit(gridLayoutWidget);
        EDIT_SG_10->setObjectName(QStringLiteral("EDIT_SG_10"));
        EDIT_SG_10->setMinimumSize(QSize(0, 20));
        EDIT_SG_10->setMaximumSize(QSize(16777215, 20));
        EDIT_SG_10->setFont(font);
        EDIT_SG_10->setFrame(false);

        gridLayout->addWidget(EDIT_SG_10, 1, 5, 1, 1);

        EDIT_S_W = new QLineEdit(gridLayoutWidget);
        EDIT_S_W->setObjectName(QStringLiteral("EDIT_S_W"));
        EDIT_S_W->setMinimumSize(QSize(0, 20));
        EDIT_S_W->setMaximumSize(QSize(16777215, 20));
        EDIT_S_W->setFont(font);
        EDIT_S_W->setFrame(false);

        gridLayout->addWidget(EDIT_S_W, 2, 1, 1, 1);

        EDIT_SG_2 = new QLineEdit(gridLayoutWidget);
        EDIT_SG_2->setObjectName(QStringLiteral("EDIT_SG_2"));
        EDIT_SG_2->setMinimumSize(QSize(0, 20));
        EDIT_SG_2->setMaximumSize(QSize(16777215, 20));
        EDIT_SG_2->setFont(font);
        EDIT_SG_2->setFrame(false);

        gridLayout->addWidget(EDIT_SG_2, 1, 2, 1, 1);

        EDIT_SG_W = new QLineEdit(gridLayoutWidget);
        EDIT_SG_W->setObjectName(QStringLiteral("EDIT_SG_W"));
        EDIT_SG_W->setMinimumSize(QSize(0, 20));
        EDIT_SG_W->setMaximumSize(QSize(16777215, 20));
        EDIT_SG_W->setFont(font);
        EDIT_SG_W->setFrame(false);

        gridLayout->addWidget(EDIT_SG_W, 1, 1, 1, 1);

        EDIT_G_2 = new QLineEdit(gridLayoutWidget);
        EDIT_G_2->setObjectName(QStringLiteral("EDIT_G_2"));
        EDIT_G_2->setMinimumSize(QSize(0, 20));
        EDIT_G_2->setMaximumSize(QSize(16777215, 20));
        EDIT_G_2->setFont(font);
        EDIT_G_2->setFrame(false);

        gridLayout->addWidget(EDIT_G_2, 3, 2, 1, 1);

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

        EDIT_SG_18 = new QLineEdit(gridLayoutWidget);
        EDIT_SG_18->setObjectName(QStringLiteral("EDIT_SG_18"));
        EDIT_SG_18->setMinimumSize(QSize(0, 20));
        EDIT_SG_18->setMaximumSize(QSize(16777215, 20));
        EDIT_SG_18->setFont(font);
        EDIT_SG_18->setFrame(false);

        gridLayout->addWidget(EDIT_SG_18, 1, 6, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(0, 40));
        label_5->setMaximumSize(QSize(16777215, 40));
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        gridLayout->addWidget(label_5, 0, 1, 1, 1);

        EDIT_G_10 = new QLineEdit(gridLayoutWidget);
        EDIT_G_10->setObjectName(QStringLiteral("EDIT_G_10"));
        EDIT_G_10->setMinimumSize(QSize(0, 20));
        EDIT_G_10->setMaximumSize(QSize(16777215, 20));
        EDIT_G_10->setFont(font);
        EDIT_G_10->setFrame(false);

        gridLayout->addWidget(EDIT_G_10, 3, 5, 1, 1);

        label_8 = new QLabel(gridLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font);
        label_8->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        gridLayout->addWidget(label_8, 0, 4, 1, 1);

        label_10 = new QLabel(gridLayoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setFont(font);
        label_10->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        gridLayout->addWidget(label_10, 0, 6, 1, 1);

        EDIT_G_2_5 = new QLineEdit(gridLayoutWidget);
        EDIT_G_2_5->setObjectName(QStringLiteral("EDIT_G_2_5"));
        EDIT_G_2_5->setMinimumSize(QSize(0, 20));
        EDIT_G_2_5->setMaximumSize(QSize(16777215, 20));
        EDIT_G_2_5->setFont(font);
        EDIT_G_2_5->setFrame(false);

        gridLayout->addWidget(EDIT_G_2_5, 3, 3, 1, 1);

        label_9 = new QLabel(gridLayoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font);
        label_9->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        gridLayout->addWidget(label_9, 0, 5, 1, 1);

        EDIT_SG_5_9 = new QLineEdit(gridLayoutWidget);
        EDIT_SG_5_9->setObjectName(QStringLiteral("EDIT_SG_5_9"));
        EDIT_SG_5_9->setMinimumSize(QSize(0, 20));
        EDIT_SG_5_9->setMaximumSize(QSize(16777215, 20));
        EDIT_SG_5_9->setFont(font);
        EDIT_SG_5_9->setFrame(false);

        gridLayout->addWidget(EDIT_SG_5_9, 1, 4, 1, 1);

        EDIT_G_18 = new QLineEdit(gridLayoutWidget);
        EDIT_G_18->setObjectName(QStringLiteral("EDIT_G_18"));
        EDIT_G_18->setMinimumSize(QSize(0, 20));
        EDIT_G_18->setMaximumSize(QSize(16777215, 20));
        EDIT_G_18->setFont(font);
        EDIT_G_18->setFrame(false);

        gridLayout->addWidget(EDIT_G_18, 3, 6, 1, 1);

        label_7 = new QLabel(gridLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font);
        label_7->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        gridLayout->addWidget(label_7, 0, 3, 1, 1);

        EDIT_G_5_9 = new QLineEdit(gridLayoutWidget);
        EDIT_G_5_9->setObjectName(QStringLiteral("EDIT_G_5_9"));
        EDIT_G_5_9->setMinimumSize(QSize(0, 20));
        EDIT_G_5_9->setMaximumSize(QSize(16777215, 20));
        EDIT_G_5_9->setFont(font);
        EDIT_G_5_9->setFrame(false);

        gridLayout->addWidget(EDIT_G_5_9, 3, 4, 1, 1);

        EDIT_S_18 = new QLineEdit(gridLayoutWidget);
        EDIT_S_18->setObjectName(QStringLiteral("EDIT_S_18"));
        EDIT_S_18->setMinimumSize(QSize(0, 20));
        EDIT_S_18->setMaximumSize(QSize(16777215, 20));
        EDIT_S_18->setFont(font);
        EDIT_S_18->setFrame(false);

        gridLayout->addWidget(EDIT_S_18, 2, 6, 1, 1);

        EDIT_S_5_9 = new QLineEdit(gridLayoutWidget);
        EDIT_S_5_9->setObjectName(QStringLiteral("EDIT_S_5_9"));
        EDIT_S_5_9->setMinimumSize(QSize(0, 20));
        EDIT_S_5_9->setMaximumSize(QSize(16777215, 20));
        EDIT_S_5_9->setFont(font);
        EDIT_S_5_9->setFrame(false);

        gridLayout->addWidget(EDIT_S_5_9, 2, 4, 1, 1);

        EDIT_S_2_5 = new QLineEdit(gridLayoutWidget);
        EDIT_S_2_5->setObjectName(QStringLiteral("EDIT_S_2_5"));
        EDIT_S_2_5->setMinimumSize(QSize(0, 20));
        EDIT_S_2_5->setMaximumSize(QSize(16777215, 20));
        EDIT_S_2_5->setFont(font);
        EDIT_S_2_5->setFrame(false);

        gridLayout->addWidget(EDIT_S_2_5, 2, 3, 1, 1);

        EDIT_S_10 = new QLineEdit(gridLayoutWidget);
        EDIT_S_10->setObjectName(QStringLiteral("EDIT_S_10"));
        EDIT_S_10->setMinimumSize(QSize(0, 20));
        EDIT_S_10->setMaximumSize(QSize(16777215, 20));
        EDIT_S_10->setFont(font);
        EDIT_S_10->setFrame(false);

        gridLayout->addWidget(EDIT_S_10, 2, 5, 1, 1);

        EDIT_G_W = new QLineEdit(gridLayoutWidget);
        EDIT_G_W->setObjectName(QStringLiteral("EDIT_G_W"));
        EDIT_G_W->setMinimumSize(QSize(0, 20));
        EDIT_G_W->setMaximumSize(QSize(16777215, 20));
        EDIT_G_W->setFont(font);
        EDIT_G_W->setFrame(false);

        gridLayout->addWidget(EDIT_G_W, 3, 1, 1, 1);

        EDIT_S_2 = new QLineEdit(gridLayoutWidget);
        EDIT_S_2->setObjectName(QStringLiteral("EDIT_S_2"));
        EDIT_S_2->setMinimumSize(QSize(0, 20));
        EDIT_S_2->setMaximumSize(QSize(16777215, 20));
        EDIT_S_2->setFont(font);
        EDIT_S_2->setFrame(false);

        gridLayout->addWidget(EDIT_S_2, 2, 2, 1, 1);

        BTN_SAVE = new QPushButton(CTabJdSetDlg);
        BTN_SAVE->setObjectName(QStringLiteral("BTN_SAVE"));
        BTN_SAVE->setGeometry(QRect(370, 400, 91, 31));

        retranslateUi(CTabJdSetDlg);

        QMetaObject::connectSlotsByName(CTabJdSetDlg);
    } // setupUi

    void retranslateUi(QWidget *CTabJdSetDlg)
    {
        CTabJdSetDlg->setWindowTitle(QApplication::translate("CTabJdSetDlg", "CTabJdSetDlg", 0));
        label->setText(QString());
        label_4->setText(QApplication::translate("CTabJdSetDlg", "\345\267\245\344\272\272\357\274\232", 0));
        label_6->setText(QApplication::translate("CTabJdSetDlg", "2000\344\273\245\344\270\213", 0));
        label_3->setText(QApplication::translate("CTabJdSetDlg", "\345\270\210\345\202\205\357\274\232", 0));
        label_2->setText(QApplication::translate("CTabJdSetDlg", "\345\270\210\345\202\205+\345\267\245\344\272\272\357\274\232", 0));
        label_5->setText(QApplication::translate("CTabJdSetDlg", "\344\270\207\344\273\243\346\225\260\351\207\217", 0));
        label_8->setText(QApplication::translate("CTabJdSetDlg", "5001-9999", 0));
        label_10->setText(QApplication::translate("CTabJdSetDlg", "18\344\273\24310\345\215\260\345\274\240", 0));
        label_9->setText(QApplication::translate("CTabJdSetDlg", "10000\344\273\245\344\270\212", 0));
        label_7->setText(QApplication::translate("CTabJdSetDlg", "2001-5000", 0));
        BTN_SAVE->setText(QApplication::translate("CTabJdSetDlg", "\344\277\235\345\255\230", 0));
    } // retranslateUi

};

namespace Ui {
    class CTabJdSetDlg: public Ui_CTabJdSetDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CTABJDSETDLG_H
