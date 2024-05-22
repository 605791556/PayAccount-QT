/********************************************************************************
** Form generated from reading UI file 'paycount_qt.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAYCOUNT_QT_H
#define UI_PAYCOUNT_QT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PayCount_QTClass
{
public:
    QAction *actionCGloble;
    QAction *actionD;
    QAction *actionSuo;
    QAction *actionD_2;
    QAction *actionD_3;
    QAction *actionDd;
    QWidget *centralWidget;
    QPushButton *BTN_MIN;
    QPushButton *BTN_MAX;
    QPushButton *BTN_CLOSE;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_2;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *BTN_INIT;
    QSpacerItem *horizontalSpacer;
    QPushButton *BTN_ACCOUNT;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *BTN_PWD;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *BTN_USER;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *BTN_BOOK;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *BTN_PRO;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *BTN_PAY;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *BTN_LOG;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *BTN_LOCK;

    void setupUi(QMainWindow *PayCount_QTClass)
    {
        if (PayCount_QTClass->objectName().isEmpty())
            PayCount_QTClass->setObjectName(QStringLiteral("PayCount_QTClass"));
        PayCount_QTClass->setWindowModality(Qt::NonModal);
        PayCount_QTClass->setEnabled(true);
        PayCount_QTClass->resize(1188, 707);
        QFont font;
        font.setPointSize(8);
        PayCount_QTClass->setFont(font);
        PayCount_QTClass->setStyleSheet(QStringLiteral(""));
        PayCount_QTClass->setIconSize(QSize(24, 24));
        actionCGloble = new QAction(PayCount_QTClass);
        actionCGloble->setObjectName(QStringLiteral("actionCGloble"));
        actionD = new QAction(PayCount_QTClass);
        actionD->setObjectName(QStringLiteral("actionD"));
        actionSuo = new QAction(PayCount_QTClass);
        actionSuo->setObjectName(QStringLiteral("actionSuo"));
        actionD_2 = new QAction(PayCount_QTClass);
        actionD_2->setObjectName(QStringLiteral("actionD_2"));
        actionD_3 = new QAction(PayCount_QTClass);
        actionD_3->setObjectName(QStringLiteral("actionD_3"));
        actionDd = new QAction(PayCount_QTClass);
        actionDd->setObjectName(QStringLiteral("actionDd"));
        centralWidget = new QWidget(PayCount_QTClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        BTN_MIN = new QPushButton(centralWidget);
        BTN_MIN->setObjectName(QStringLiteral("BTN_MIN"));
        BTN_MIN->setEnabled(true);
        BTN_MIN->setGeometry(QRect(850, 0, 26, 26));
        BTN_MAX = new QPushButton(centralWidget);
        BTN_MAX->setObjectName(QStringLiteral("BTN_MAX"));
        BTN_MAX->setEnabled(true);
        BTN_MAX->setGeometry(QRect(880, 0, 26, 26));
        BTN_CLOSE = new QPushButton(centralWidget);
        BTN_CLOSE->setObjectName(QStringLiteral("BTN_CLOSE"));
        BTN_CLOSE->setEnabled(true);
        BTN_CLOSE->setGeometry(QRect(910, 0, 26, 26));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(720, 590, 211, 16));
        QFont font1;
        font1.setPointSize(9);
        label->setFont(font1);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(670, 40, 261, 20));
        QFont font2;
        font2.setPointSize(10);
        label_2->setFont(font2);
        label_2->setLayoutDirection(Qt::LeftToRight);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 590, 81, 21));
        label_3->setFont(font1);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(80, 590, 61, 20));
        label_4->setFont(font1);
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 130, 941, 461));
        QFont font3;
        font3.setPointSize(11);
        tabWidget->setFont(font3);
        tabWidget->setAutoFillBackground(false);
        tabWidget->setStyleSheet(QString::fromUtf8("\n"
"QTabBar::tab\n"
"{\n"
"	color:#3c3e1e;\n"
"	background:transparent;\n"
"    background-color: #eeefd7;	\n"
"	font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	font-size:15px;	\n"
"	padding-left:1px;\n"
"	padding-right:1px;\n"
"	width:100px;\n"
"	height:25px;\n"
"	margin-left:2px;\n"
"	margin-right:1px;\n"
"} \n"
"QTabBar::tab:selected\n"
"{\n"
"	color:#3c3e1e;\n"
"	background:transparent;\n"
"    background-color: #B5B5B5;\n"
"	font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	font-size:15px;	\n"
"	border-bottom:1px solid #E8E8E8;\n"
"}\n"
"QTabBar::tab:hover\n"
"{\n"
"	color:#3c3e1e;\n"
"	background:transparent;\n"
"    background-color: #CFCFCF;	\n"
"	font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	font-size:15px;	\n"
"}\n"
"QTabWidget::tab-bar\n"
" {\n"
"    alignment: left;  \n"
"	top:0px;\n"
"	left:0px;	\n"
"} \n"
"\n"
"\n"
""));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 0, 681, 74));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout->setContentsMargins(5, 5, 0, 0);
        BTN_INIT = new QPushButton(horizontalLayoutWidget);
        BTN_INIT->setObjectName(QStringLiteral("BTN_INIT"));
        BTN_INIT->setEnabled(true);
        BTN_INIT->setMinimumSize(QSize(5, 5));

        horizontalLayout->addWidget(BTN_INIT);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        BTN_ACCOUNT = new QPushButton(horizontalLayoutWidget);
        BTN_ACCOUNT->setObjectName(QStringLiteral("BTN_ACCOUNT"));
        BTN_ACCOUNT->setEnabled(true);

        horizontalLayout->addWidget(BTN_ACCOUNT);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        BTN_PWD = new QPushButton(horizontalLayoutWidget);
        BTN_PWD->setObjectName(QStringLiteral("BTN_PWD"));
        BTN_PWD->setEnabled(true);

        horizontalLayout->addWidget(BTN_PWD);

        horizontalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        BTN_USER = new QPushButton(horizontalLayoutWidget);
        BTN_USER->setObjectName(QStringLiteral("BTN_USER"));
        BTN_USER->setEnabled(true);
        BTN_USER->setMinimumSize(QSize(48, 68));
        BTN_USER->setMaximumSize(QSize(48, 68));

        horizontalLayout->addWidget(BTN_USER);

        horizontalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        BTN_BOOK = new QPushButton(horizontalLayoutWidget);
        BTN_BOOK->setObjectName(QStringLiteral("BTN_BOOK"));
        BTN_BOOK->setEnabled(true);

        horizontalLayout->addWidget(BTN_BOOK);

        horizontalSpacer_5 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        BTN_PRO = new QPushButton(horizontalLayoutWidget);
        BTN_PRO->setObjectName(QStringLiteral("BTN_PRO"));
        BTN_PRO->setEnabled(true);

        horizontalLayout->addWidget(BTN_PRO);

        horizontalSpacer_6 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);

        BTN_PAY = new QPushButton(horizontalLayoutWidget);
        BTN_PAY->setObjectName(QStringLiteral("BTN_PAY"));
        BTN_PAY->setEnabled(true);

        horizontalLayout->addWidget(BTN_PAY);

        horizontalSpacer_7 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_7);

        BTN_LOG = new QPushButton(horizontalLayoutWidget);
        BTN_LOG->setObjectName(QStringLiteral("BTN_LOG"));
        BTN_LOG->setEnabled(true);

        horizontalLayout->addWidget(BTN_LOG);

        horizontalSpacer_8 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);

        BTN_LOCK = new QPushButton(horizontalLayoutWidget);
        BTN_LOCK->setObjectName(QStringLiteral("BTN_LOCK"));
        BTN_LOCK->setEnabled(true);

        horizontalLayout->addWidget(BTN_LOCK);

        PayCount_QTClass->setCentralWidget(centralWidget);

        retranslateUi(PayCount_QTClass);
        QObject::connect(BTN_MIN, SIGNAL(clicked()), PayCount_QTClass, SLOT(showMinimized()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(PayCount_QTClass);
    } // setupUi

    void retranslateUi(QMainWindow *PayCount_QTClass)
    {
        PayCount_QTClass->setWindowTitle(QApplication::translate("PayCount_QTClass", "PayCount_QT", 0));
        actionCGloble->setText(QApplication::translate("PayCount_QTClass", "\345\210\235\345\247\213\345\214\226", 0));
        actionD->setText(QApplication::translate("PayCount_QTClass", "\350\264\246\345\217\267", 0));
        actionSuo->setText(QApplication::translate("PayCount_QTClass", "\351\224\201\345\256\232", 0));
        actionD_2->setText(QApplication::translate("PayCount_QTClass", "\344\277\256\346\224\271\345\257\206\347\240\201", 0));
        actionD_3->setText(QApplication::translate("PayCount_QTClass", "\346\263\250\351\224\200", 0));
        actionDd->setText(QApplication::translate("PayCount_QTClass", "\351\200\200\345\207\272", 0));
#ifndef QT_NO_TOOLTIP
        BTN_MIN->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        BTN_MIN->setText(QString());
#ifndef QT_NO_TOOLTIP
        BTN_MAX->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        BTN_MAX->setText(QString());
#ifndef QT_NO_TOOLTIP
        BTN_CLOSE->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        BTN_CLOSE->setText(QString());
        label->setText(QApplication::translate("PayCount_QTClass", "<html><head/><body><p><span style=\" font-size:8pt; color:#ffffff;\">LY_PAYCAT v3.0.3</span></p></body></html>", 0));
        label_2->setText(QApplication::translate("PayCount_QTClass", "<html><head/><body><p align=\"right\"><span style=\" color:#ffffff;\">\346\254\242\350\277\216\347\231\273\345\275\225\357\274\232admin\357\274\210\350\266\205\347\272\247\347\256\241\347\220\206\345\221\230\357\274\211</span></p></body></html>", 0));
        label_3->setText(QApplication::translate("PayCount_QTClass", "<html><head/><body><p><span style=\" color:#ffffff;\">\346\234\215\345\212\241\345\231\250\350\277\236\346\216\245\357\274\232</span></p></body></html>", 0));
        label_4->setText(QApplication::translate("PayCount_QTClass", "<html><head/><body><p><span style=\" color:#00ff00;\">\346\255\243\345\270\270</span></p></body></html>", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("PayCount_QTClass", "Tab 1", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("PayCount_QTClass", "Tab 2", 0));
#ifndef QT_NO_TOOLTIP
        BTN_INIT->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        BTN_INIT->setText(QString());
#ifndef QT_NO_TOOLTIP
        BTN_ACCOUNT->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        BTN_ACCOUNT->setText(QString());
#ifndef QT_NO_TOOLTIP
        BTN_PWD->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        BTN_PWD->setText(QString());
#ifndef QT_NO_TOOLTIP
        BTN_USER->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        BTN_USER->setText(QString());
#ifndef QT_NO_TOOLTIP
        BTN_BOOK->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        BTN_BOOK->setText(QString());
#ifndef QT_NO_TOOLTIP
        BTN_PRO->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        BTN_PRO->setText(QString());
#ifndef QT_NO_TOOLTIP
        BTN_PAY->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        BTN_PAY->setText(QString());
#ifndef QT_NO_TOOLTIP
        BTN_LOG->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        BTN_LOG->setText(QString());
#ifndef QT_NO_TOOLTIP
        BTN_LOCK->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        BTN_LOCK->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PayCount_QTClass: public Ui_PayCount_QTClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAYCOUNT_QT_H
