/********************************************************************************
** Form generated from reading UI file 'bookmanagerui.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOKMANAGERUI_H
#define UI_BOOKMANAGERUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_bookmanagerui
{
public:
    QWidget *widget_main;
    QStackedWidget *stackedWidget;
    QWidget *welcome;
    QLabel *lb_title1;
    QLabel *lb_title2;
    QLabel *lb_107;
    QPushButton *pb_2regist;
    QPushButton *pb_2login;
    QPushButton *pb_aboutus;
    QWidget *regist;
    QPushButton *pb_regist_back;
    QLabel *lb_regist;
    QLineEdit *le_username;
    QLineEdit *le_account;
    QLineEdit *le_password;
    QCheckBox *cb_isteacher;
    QPushButton *pb_regist;
    QWidget *login;
    QPushButton *pb_login_back;
    QLabel *lb_login;
    QLineEdit *le_login_account;
    QLineEdit *le_login_password;
    QPushButton *pb_login;
    QWidget *settings;
    QPushButton *pb_settings_back;
    QLineEdit *le_change_username;
    QLabel *lb_change_username;
    QLabel *lb_change_password;
    QLineEdit *le_change_password;
    QPushButton *pb_change_username;
    QPushButton *pb_change_password;
    QPushButton *pb_logout;
    QPushButton *pb_delete_user;
    QLabel *lb_settings;
    QWidget *operate;
    QListView *lv_info;
    QLabel *lb_operate;
    QPushButton *pb_borrow;
    QLabel *lb_welcomeuser;
    QPushButton *pb_return;
    QPushButton *pb_search;
    QPushButton *pb_teacher;
    QPushButton *pb_setting;
    QTextEdit *textEdit;

    void setupUi(QMainWindow *bookmanagerui)
    {
        if (bookmanagerui->objectName().isEmpty())
            bookmanagerui->setObjectName("bookmanagerui");
        bookmanagerui->resize(800, 484);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(bookmanagerui->sizePolicy().hasHeightForWidth());
        bookmanagerui->setSizePolicy(sizePolicy);
        bookmanagerui->setBaseSize(QSize(7, 0));
        QFont font;
        font.setFamilies({QString::fromUtf8("Rockwell")});
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(true);
        bookmanagerui->setFont(font);
        widget_main = new QWidget(bookmanagerui);
        widget_main->setObjectName("widget_main");
        sizePolicy.setHeightForWidth(widget_main->sizePolicy().hasHeightForWidth());
        widget_main->setSizePolicy(sizePolicy);
        stackedWidget = new QStackedWidget(widget_main);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 0, 800, 484));
        sizePolicy.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Rockwell")});
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setItalic(false);
        stackedWidget->setFont(font1);
        welcome = new QWidget();
        welcome->setObjectName("welcome");
        lb_title1 = new QLabel(welcome);
        lb_title1->setObjectName("lb_title1");
        lb_title1->setGeometry(QRect(190, 50, 441, 101));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Rockwell")});
        font2.setPointSize(35);
        font2.setBold(true);
        font2.setItalic(false);
        lb_title1->setFont(font2);
        lb_title1->setAlignment(Qt::AlignCenter);
        lb_title2 = new QLabel(welcome);
        lb_title2->setObjectName("lb_title2");
        lb_title2->setGeometry(QRect(600, 170, 101, 31));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Rockwell")});
        font3.setPointSize(20);
        font3.setBold(true);
        font3.setItalic(true);
        lb_title2->setFont(font3);
        lb_107 = new QLabel(welcome);
        lb_107->setObjectName("lb_107");
        lb_107->setGeometry(QRect(250, 230, 291, 61));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Rockwell")});
        font4.setPointSize(25);
        font4.setBold(true);
        font4.setItalic(true);
        lb_107->setFont(font4);
        lb_107->setAlignment(Qt::AlignCenter);
        pb_2regist = new QPushButton(welcome);
        pb_2regist->setObjectName("pb_2regist");
        pb_2regist->setGeometry(QRect(70, 350, 101, 61));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Microsoft Tai Le")});
        font5.setPointSize(15);
        font5.setBold(false);
        font5.setItalic(false);
        pb_2regist->setFont(font5);
        pb_2login = new QPushButton(welcome);
        pb_2login->setObjectName("pb_2login");
        pb_2login->setGeometry(QRect(350, 350, 101, 61));
        pb_2login->setFont(font5);
        pb_aboutus = new QPushButton(welcome);
        pb_aboutus->setObjectName("pb_aboutus");
        pb_aboutus->setGeometry(QRect(630, 350, 101, 61));
        pb_aboutus->setFont(font5);
        stackedWidget->addWidget(welcome);
        regist = new QWidget();
        regist->setObjectName("regist");
        pb_regist_back = new QPushButton(regist);
        pb_regist_back->setObjectName("pb_regist_back");
        pb_regist_back->setGeometry(QRect(30, 30, 91, 41));
        lb_regist = new QLabel(regist);
        lb_regist->setObjectName("lb_regist");
        lb_regist->setGeometry(QRect(230, 10, 279, 71));
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Rockwell")});
        font6.setPointSize(25);
        font6.setBold(true);
        font6.setItalic(false);
        lb_regist->setFont(font6);
        lb_regist->setAlignment(Qt::AlignCenter);
        le_username = new QLineEdit(regist);
        le_username->setObjectName("le_username");
        le_username->setGeometry(QRect(120, 120, 491, 31));
        le_account = new QLineEdit(regist);
        le_account->setObjectName("le_account");
        le_account->setGeometry(QRect(120, 200, 491, 31));
        le_password = new QLineEdit(regist);
        le_password->setObjectName("le_password");
        le_password->setGeometry(QRect(120, 290, 491, 31));
        cb_isteacher = new QCheckBox(regist);
        cb_isteacher->setObjectName("cb_isteacher");
        cb_isteacher->setGeometry(QRect(120, 350, 471, 31));
        QFont font7;
        font7.setFamilies({QString::fromUtf8("Rockwell")});
        font7.setPointSize(15);
        font7.setBold(true);
        font7.setItalic(false);
        cb_isteacher->setFont(font7);
        pb_regist = new QPushButton(regist);
        pb_regist->setObjectName("pb_regist");
        pb_regist->setGeometry(QRect(250, 400, 221, 71));
        QFont font8;
        font8.setFamilies({QString::fromUtf8("Rockwell")});
        font8.setPointSize(20);
        font8.setBold(true);
        font8.setItalic(false);
        pb_regist->setFont(font8);
        stackedWidget->addWidget(regist);
        login = new QWidget();
        login->setObjectName("login");
        pb_login_back = new QPushButton(login);
        pb_login_back->setObjectName("pb_login_back");
        pb_login_back->setGeometry(QRect(20, 20, 81, 41));
        lb_login = new QLabel(login);
        lb_login->setObjectName("lb_login");
        lb_login->setGeometry(QRect(250, 50, 331, 51));
        QFont font9;
        font9.setFamilies({QString::fromUtf8("Microsoft YaHei UI")});
        font9.setPointSize(30);
        font9.setBold(true);
        font9.setItalic(false);
        lb_login->setFont(font9);
        lb_login->setAlignment(Qt::AlignCenter);
        le_login_account = new QLineEdit(login);
        le_login_account->setObjectName("le_login_account");
        le_login_account->setGeometry(QRect(150, 140, 521, 41));
        le_login_password = new QLineEdit(login);
        le_login_password->setObjectName("le_login_password");
        le_login_password->setGeometry(QRect(150, 270, 521, 41));
        pb_login = new QPushButton(login);
        pb_login->setObjectName("pb_login");
        pb_login->setGeometry(QRect(340, 370, 161, 71));
        QFont font10;
        font10.setFamilies({QString::fromUtf8("Rockwell")});
        font10.setPointSize(20);
        font10.setBold(false);
        font10.setItalic(false);
        pb_login->setFont(font10);
        stackedWidget->addWidget(login);
        settings = new QWidget();
        settings->setObjectName("settings");
        pb_settings_back = new QPushButton(settings);
        pb_settings_back->setObjectName("pb_settings_back");
        pb_settings_back->setGeometry(QRect(20, 20, 91, 51));
        le_change_username = new QLineEdit(settings);
        le_change_username->setObjectName("le_change_username");
        le_change_username->setGeometry(QRect(180, 120, 401, 31));
        lb_change_username = new QLabel(settings);
        lb_change_username->setObjectName("lb_change_username");
        lb_change_username->setGeometry(QRect(30, 120, 131, 31));
        lb_change_username->setFont(font1);
        lb_change_password = new QLabel(settings);
        lb_change_password->setObjectName("lb_change_password");
        lb_change_password->setGeometry(QRect(30, 230, 141, 31));
        lb_change_password->setFont(font1);
        le_change_password = new QLineEdit(settings);
        le_change_password->setObjectName("le_change_password");
        le_change_password->setGeometry(QRect(180, 230, 401, 31));
        pb_change_username = new QPushButton(settings);
        pb_change_username->setObjectName("pb_change_username");
        pb_change_username->setGeometry(QRect(650, 110, 80, 41));
        pb_change_password = new QPushButton(settings);
        pb_change_password->setObjectName("pb_change_password");
        pb_change_password->setGeometry(QRect(650, 220, 80, 41));
        pb_logout = new QPushButton(settings);
        pb_logout->setObjectName("pb_logout");
        pb_logout->setGeometry(QRect(140, 350, 111, 61));
        pb_logout->setFont(font7);
        pb_delete_user = new QPushButton(settings);
        pb_delete_user->setObjectName("pb_delete_user");
        pb_delete_user->setGeometry(QRect(490, 350, 111, 61));
        pb_delete_user->setFont(font7);
        lb_settings = new QLabel(settings);
        lb_settings->setObjectName("lb_settings");
        lb_settings->setGeometry(QRect(190, 30, 391, 41));
        lb_settings->setFont(font6);
        lb_settings->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(settings);
        operate = new QWidget();
        operate->setObjectName("operate");
        lv_info = new QListView(operate);
        lv_info->setObjectName("lv_info");
        lv_info->setGeometry(QRect(10, 80, 251, 391));
        lb_operate = new QLabel(operate);
        lb_operate->setObjectName("lb_operate");
        lb_operate->setGeometry(QRect(260, 20, 291, 41));
        QFont font11;
        font11.setFamilies({QString::fromUtf8("Microsoft YaHei UI")});
        font11.setPointSize(20);
        font11.setBold(true);
        font11.setItalic(false);
        lb_operate->setFont(font11);
        lb_operate->setAlignment(Qt::AlignCenter);
        pb_borrow = new QPushButton(operate);
        pb_borrow->setObjectName("pb_borrow");
        pb_borrow->setGeometry(QRect(330, 240, 121, 66));
        QFont font12;
        font12.setFamilies({QString::fromUtf8("Rockwell")});
        font12.setPointSize(18);
        font12.setBold(true);
        font12.setItalic(false);
        pb_borrow->setFont(font12);
        lb_welcomeuser = new QLabel(operate);
        lb_welcomeuser->setObjectName("lb_welcomeuser");
        lb_welcomeuser->setGeometry(QRect(30, 20, 261, 31));
        pb_return = new QPushButton(operate);
        pb_return->setObjectName("pb_return");
        pb_return->setGeometry(QRect(600, 240, 121, 71));
        pb_return->setFont(font12);
        pb_search = new QPushButton(operate);
        pb_search->setObjectName("pb_search");
        pb_search->setGeometry(QRect(330, 380, 121, 71));
        pb_search->setFont(font12);
        pb_teacher = new QPushButton(operate);
        pb_teacher->setObjectName("pb_teacher");
        pb_teacher->setGeometry(QRect(680, 20, 91, 51));
        pb_setting = new QPushButton(operate);
        pb_setting->setObjectName("pb_setting");
        pb_setting->setGeometry(QRect(610, 380, 111, 71));
        pb_setting->setFont(font12);
        textEdit = new QTextEdit(operate);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(330, 90, 391, 141));
        stackedWidget->addWidget(operate);
        bookmanagerui->setCentralWidget(widget_main);

        retranslateUi(bookmanagerui);

        stackedWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(bookmanagerui);
    } // setupUi

    void retranslateUi(QMainWindow *bookmanagerui)
    {
        bookmanagerui->setWindowTitle(QCoreApplication::translate("bookmanagerui", "bookmanagerui", nullptr));
        lb_title1->setText(QCoreApplication::translate("bookmanagerui", "\345\233\276\344\271\246\351\246\206\344\271\246\347\261\215\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        lb_title2->setText(QCoreApplication::translate("bookmanagerui", "v1.0.0", nullptr));
        lb_107->setText(QCoreApplication::translate("bookmanagerui", "107studio\345\207\272\345\223\201", nullptr));
        pb_2regist->setText(QCoreApplication::translate("bookmanagerui", "\346\263\250\345\206\214\350\264\246\345\217\267", nullptr));
        pb_2login->setText(QCoreApplication::translate("bookmanagerui", "\347\231\273\351\231\206\350\264\246\345\217\267", nullptr));
        pb_aboutus->setText(QCoreApplication::translate("bookmanagerui", "\345\205\263\344\272\216\346\210\221\344\273\254", nullptr));
        pb_regist_back->setText(QCoreApplication::translate("bookmanagerui", "\350\277\224\345\233\236", nullptr));
        lb_regist->setText(QCoreApplication::translate("bookmanagerui", "\346\263\250\345\206\214\346\202\250\347\232\204\350\264\246\345\217\267", nullptr));
        cb_isteacher->setText(QCoreApplication::translate("bookmanagerui", "\344\273\245\350\200\201\345\270\210\350\272\253\344\273\275\346\263\250\345\206\214\357\274\210\351\273\230\350\256\244\344\270\272\345\255\246\347\224\237\350\272\253\344\273\275\357\274\211", nullptr));
        pb_regist->setText(QCoreApplication::translate("bookmanagerui", "\346\263\250\345\206\214\357\274\201", nullptr));
        pb_login_back->setText(QCoreApplication::translate("bookmanagerui", "\350\277\224\345\233\236", nullptr));
        lb_login->setText(QCoreApplication::translate("bookmanagerui", "\347\224\250\346\210\267\347\231\273\345\275\225", nullptr));
        pb_login->setText(QCoreApplication::translate("bookmanagerui", "\347\231\273\345\275\225", nullptr));
        pb_settings_back->setText(QCoreApplication::translate("bookmanagerui", "\350\277\224\345\233\236", nullptr));
        lb_change_username->setText(QCoreApplication::translate("bookmanagerui", "\344\277\256\346\224\271\346\202\250\347\232\204\347\224\250\346\210\267\345\220\215", nullptr));
        lb_change_password->setText(QCoreApplication::translate("bookmanagerui", "\344\277\256\346\224\271\346\202\250\347\232\204\345\257\206\347\240\201", nullptr));
        pb_change_username->setText(QCoreApplication::translate("bookmanagerui", "\344\277\256\346\224\271", nullptr));
        pb_change_password->setText(QCoreApplication::translate("bookmanagerui", "\344\277\256\346\224\271", nullptr));
        pb_logout->setText(QCoreApplication::translate("bookmanagerui", "\351\200\200\345\207\272\347\231\273\345\275\225", nullptr));
        pb_delete_user->setText(QCoreApplication::translate("bookmanagerui", "\346\263\250\351\224\200\347\224\250\346\210\267", nullptr));
        lb_settings->setText(QCoreApplication::translate("bookmanagerui", "\350\256\276\347\275\256", nullptr));
        lb_operate->setText(QCoreApplication::translate("bookmanagerui", "\344\271\246\347\261\215\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        pb_borrow->setText(QCoreApplication::translate("bookmanagerui", "\345\200\237\344\271\246", nullptr));
        lb_welcomeuser->setText(QString());
        pb_return->setText(QCoreApplication::translate("bookmanagerui", "\350\277\230\344\271\246", nullptr));
        pb_search->setText(QCoreApplication::translate("bookmanagerui", "\346\237\245\350\257\242", nullptr));
        pb_teacher->setText(QCoreApplication::translate("bookmanagerui", "\346\225\231\345\270\210\347\225\214\351\235\242", nullptr));
        pb_setting->setText(QCoreApplication::translate("bookmanagerui", "\350\256\276\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class bookmanagerui: public Ui_bookmanagerui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKMANAGERUI_H
