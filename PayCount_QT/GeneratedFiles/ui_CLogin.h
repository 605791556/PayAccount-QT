/********************************************************************************
** Form generated from reading UI file 'CLogin.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLOGIN_H
#define UI_CLOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CLogin
{
public:
    QLineEdit *EDIT_PWD;
    QCheckBox *checkBox;
    QPushButton *BTN_SET;
    QPushButton *BTN_LOGIN;
    QLabel *label_msg;
    QPushButton *BTN_MIN;
    QPushButton *BTN_CLOSE;
    QComboBox *comboBox;
    QLabel *label_title;
    QLabel *label_pic;
    QLabel *label_v;

    void setupUi(QWidget *CLogin)
    {
        if (CLogin->objectName().isEmpty())
            CLogin->setObjectName(QStringLiteral("CLogin"));
        CLogin->resize(450, 350);
        EDIT_PWD = new QLineEdit(CLogin);
        EDIT_PWD->setObjectName(QStringLiteral("EDIT_PWD"));
        EDIT_PWD->setGeometry(QRect(130, 220, 210, 31));
        QFont font;
        font.setPointSize(11);
        EDIT_PWD->setFont(font);
        EDIT_PWD->setEchoMode(QLineEdit::Password);
        checkBox = new QCheckBox(CLogin);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(130, 260, 121, 16));
        checkBox->setFont(font);
        BTN_SET = new QPushButton(CLogin);
        BTN_SET->setObjectName(QStringLiteral("BTN_SET"));
        BTN_SET->setGeometry(QRect(370, 295, 22, 22));
        BTN_SET->setCursor(QCursor(Qt::PointingHandCursor));
        BTN_LOGIN = new QPushButton(CLogin);
        BTN_LOGIN->setObjectName(QStringLiteral("BTN_LOGIN"));
        BTN_LOGIN->setEnabled(true);
        BTN_LOGIN->setGeometry(QRect(130, 290, 210, 34));
        BTN_LOGIN->setFont(font);
        label_msg = new QLabel(CLogin);
        label_msg->setObjectName(QStringLiteral("label_msg"));
        label_msg->setGeometry(QRect(0, 330, 181, 21));
        label_msg->setFont(font);
        BTN_MIN = new QPushButton(CLogin);
        BTN_MIN->setObjectName(QStringLiteral("BTN_MIN"));
        BTN_MIN->setGeometry(QRect(390, 0, 26, 26));
        BTN_CLOSE = new QPushButton(CLogin);
        BTN_CLOSE->setObjectName(QStringLiteral("BTN_CLOSE"));
        BTN_CLOSE->setGeometry(QRect(420, 0, 26, 26));
        comboBox = new QComboBox(CLogin);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(130, 160, 210, 31));
        comboBox->setFont(font);
        comboBox->setEditable(true);
        comboBox->setFrame(true);
        label_title = new QLabel(CLogin);
        label_title->setObjectName(QStringLiteral("label_title"));
        label_title->setGeometry(QRect(20, 30, 411, 101));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(24);
        label_title->setFont(font1);
        label_title->setAlignment(Qt::AlignCenter);
        label_pic = new QLabel(CLogin);
        label_pic->setObjectName(QStringLiteral("label_pic"));
        label_pic->setGeometry(QRect(20, 160, 100, 100));
        label_v = new QLabel(CLogin);
        label_v->setObjectName(QStringLiteral("label_v"));
        label_v->setGeometry(QRect(330, 83, 54, 12));
        QWidget::setTabOrder(comboBox, EDIT_PWD);
        QWidget::setTabOrder(EDIT_PWD, checkBox);
        QWidget::setTabOrder(checkBox, BTN_LOGIN);
        QWidget::setTabOrder(BTN_LOGIN, BTN_SET);
        QWidget::setTabOrder(BTN_SET, BTN_CLOSE);
        QWidget::setTabOrder(BTN_CLOSE, BTN_MIN);

        retranslateUi(CLogin);
        QObject::connect(BTN_MIN, SIGNAL(clicked()), CLogin, SLOT(showMinimized()));

        QMetaObject::connectSlotsByName(CLogin);
    } // setupUi

    void retranslateUi(QWidget *CLogin)
    {
        CLogin->setWindowTitle(QString());
        EDIT_PWD->setText(QString());
        EDIT_PWD->setPlaceholderText(QApplication::translate("CLogin", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", 0));
        checkBox->setText(QApplication::translate("CLogin", "\350\256\260\344\275\217\350\264\246\345\217\267", 0));
        BTN_SET->setText(QString());
        BTN_LOGIN->setText(QApplication::translate("CLogin", "\347\231\273    \345\275\225", 0));
        label_msg->setText(QApplication::translate("CLogin", "\346\255\243\345\234\250\350\277\236\346\216\245\346\234\215\345\212\241\345\231\250\357\274\214\350\257\267\347\250\215\347\255\211...", 0));
        BTN_MIN->setText(QString());
        BTN_CLOSE->setText(QString());
        comboBox->setCurrentText(QString());
        label_title->setText(QString());
        label_pic->setText(QString());
        label_v->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CLogin: public Ui_CLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLOGIN_H
