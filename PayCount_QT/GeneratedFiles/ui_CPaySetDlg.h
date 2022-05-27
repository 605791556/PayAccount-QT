/********************************************************************************
** Form generated from reading UI file 'CPaySetDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CPAYSETDLG_H
#define UI_CPAYSETDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CPaySetDlg
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QPushButton *BTN_CLOSE;
    QHBoxLayout *horizontalLayout_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_2;

    void setupUi(QDialog *CPaySetDlg)
    {
        if (CPaySetDlg->objectName().isEmpty())
            CPaySetDlg->setObjectName(QStringLiteral("CPaySetDlg"));
        CPaySetDlg->resize(835, 592);
        verticalLayout = new QVBoxLayout(CPaySetDlg);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(CPaySetDlg);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(11);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        font.setStyleStrategy(QFont::PreferDefault);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        BTN_CLOSE = new QPushButton(CPaySetDlg);
        BTN_CLOSE->setObjectName(QStringLiteral("BTN_CLOSE"));
        BTN_CLOSE->setMinimumSize(QSize(26, 26));
        BTN_CLOSE->setMaximumSize(QSize(26, 26));

        horizontalLayout->addWidget(BTN_CLOSE);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        tabWidget = new QTabWidget(CPaySetDlg);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setStyleSheet(QString::fromUtf8("\n"
"QTabBar::tab\n"
"{\n"
"	color:#3c3e1e;\n"
"	background:transparent;\n"
"    background-color: #d5cf81;	\n"
"	font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	font-size:12px;	\n"
"	padding-left:1px;\n"
"	padding-right:1px;\n"
"	width:100px;\n"
"	height:25px;\n"
"	margin-left:2px;\n"
"	margin-right:1px;\n"
"} \n"
"QTabBar::tab:selected\n"
"{\n"
"	color:#FAFAD2;\n"
"	background:transparent;\n"
"    background-color: #BDB76B;\n"
"	font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	font-size:12px;	\n"
"	border-bottom:2px solid #BDB76B;\n"
"}\n"
"QTabBar::tab:hover\n"
"{\n"
"	color:#3c3e1e;\n"
"	background:transparent;\n"
"    background-color: #e0d876;\n"
"	font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	font-size:12px;	\n"
"}\n"
"QTabWidget::tab-bar\n"
" {\n"
"    alignment: left;  \n"
"	top:0px;\n"
"	left:0px;	\n"
"}\n"
"QTabWidget::pane\n"
"{\n"
"    border:none;\n"
"} "));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());

        horizontalLayout_2->addWidget(tabWidget);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(CPaySetDlg);
        QObject::connect(BTN_CLOSE, SIGNAL(clicked()), CPaySetDlg, SLOT(reject()));

        QMetaObject::connectSlotsByName(CPaySetDlg);
    } // setupUi

    void retranslateUi(QDialog *CPaySetDlg)
    {
        CPaySetDlg->setWindowTitle(QApplication::translate("CPaySetDlg", "\345\215\225\344\273\267\350\256\276\347\275\256", 0));
        label->setText(QApplication::translate("CPaySetDlg", "\345\215\225\344\273\267\350\256\276\347\275\256", 0));
        BTN_CLOSE->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("CPaySetDlg", "Tab 1", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("CPaySetDlg", "Tab 2", 0));
    } // retranslateUi

};

namespace Ui {
    class CPaySetDlg: public Ui_CPaySetDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CPAYSETDLG_H
