/********************************************************************************
** Form generated from reading UI file 'CLockDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLOCKDLG_H
#define UI_CLOCKDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CLockDlg
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QLabel *label_pic;
    QLineEdit *EDIT_PWD;
    QPushButton *BTN_OK;
    QPushButton *BTN_CANCEL;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_4;

    void setupUi(QDialog *CLockDlg)
    {
        if (CLockDlg->objectName().isEmpty())
            CLockDlg->setObjectName(QStringLiteral("CLockDlg"));
        CLockDlg->resize(610, 287);
        CLockDlg->setModal(false);
        verticalLayout = new QVBoxLayout(CLockDlg);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));

        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        label = new QLabel(CLockDlg);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(11);
        label->setFont(font);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label);

        label_pic = new QLabel(CLockDlg);
        label_pic->setObjectName(QStringLiteral("label_pic"));
        label_pic->setMinimumSize(QSize(16, 18));
        label_pic->setMaximumSize(QSize(16, 18));

        horizontalLayout_3->addWidget(label_pic);

        EDIT_PWD = new QLineEdit(CLockDlg);
        EDIT_PWD->setObjectName(QStringLiteral("EDIT_PWD"));
        EDIT_PWD->setMinimumSize(QSize(200, 20));
        EDIT_PWD->setMaximumSize(QSize(200, 20));
        EDIT_PWD->setFrame(false);
        EDIT_PWD->setEchoMode(QLineEdit::Password);

        horizontalLayout_3->addWidget(EDIT_PWD);

        BTN_OK = new QPushButton(CLockDlg);
        BTN_OK->setObjectName(QStringLiteral("BTN_OK"));
        BTN_OK->setFont(font);

        horizontalLayout_3->addWidget(BTN_OK);

        BTN_CANCEL = new QPushButton(CLockDlg);
        BTN_CANCEL->setObjectName(QStringLiteral("BTN_CANCEL"));
        BTN_CANCEL->setFont(font);

        horizontalLayout_3->addWidget(BTN_CANCEL);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        horizontalLayout_2->addLayout(horizontalLayout_3);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));

        verticalLayout->addLayout(horizontalLayout_4);


        retranslateUi(CLockDlg);

        QMetaObject::connectSlotsByName(CLockDlg);
    } // setupUi

    void retranslateUi(QDialog *CLockDlg)
    {
        CLockDlg->setWindowTitle(QApplication::translate("CLockDlg", "CLockDlg", 0));
        label->setText(QApplication::translate("CLockDlg", "\345\257\206\347\240\201\357\274\232", 0));
        label_pic->setText(QString());
        BTN_OK->setText(QApplication::translate("CLockDlg", "\347\241\256\345\256\232", 0));
        BTN_CANCEL->setText(QApplication::translate("CLockDlg", "\345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class CLockDlg: public Ui_CLockDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLOCKDLG_H
