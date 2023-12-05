#include "bookmanagerui.h"
#include "./ui_bookmanagerui.h"
#include "user.h"
#include"fileIO.h"
#include<string>
#include<QCloseEvent>

bookmanagerui::bookmanagerui(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::bookmanagerui)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    //按钮相关在下边
    connect(ui->pb_aboutus,SIGNAL(clicked(bool)),this,SLOT(aboutus()));
    connect(ui->pb_2regist,SIGNAL(clicked(bool)),this,SLOT(showregist()));
    connect(ui->pb_regist,SIGNAL(clicked(bool)),this,SLOT(regist()));
    connect(ui->pb_regist_back,SIGNAL(clicked(bool)),this,SLOT(back_to_homepage()));
    connect(ui->pb_2login,SIGNAL(clicked(bool)),this,SLOT(showlogin()));
    connect(ui->pb_login_back,SIGNAL(clicked(bool)),this,SLOT(back_to_homepage()));
    connect(ui->pb_login,SIGNAL(clicked(bool)),this,SLOT(login()));
    connect(ui->pb_setting,SIGNAL(clicked(bool)),this,SLOT(showsettings()));
    connect(ui->pb_settings_back,SIGNAL(clicked(bool)),this,SLOT(showoperate()));
    connect(ui->pb_logout,SIGNAL(clicked(bool)),this,SLOT(logout()));
    connect(ui->pb_delete_user,SIGNAL(clicked(bool)),this,SLOT(delete_user()));
    connect(ui->pb_change_username,SIGNAL(clicked(bool)),this,SLOT(change_username()));
    connect(ui->pb_change_password,SIGNAL(clicked(bool)),this,SLOT(change_password()));
    //按钮相关在上边
}

bookmanagerui::~bookmanagerui()
{
    delete ui;
}

void bookmanagerui::aboutus()
{
    QMessageBox::information(this, "关于我们", "107studio出品");
}

void bookmanagerui::showregist()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->le_username->setPlaceholderText("请输入您的用户名（可更改）");
    ui->le_username->setText("");
    ui->le_username->setMaxLength(16);
    ui->le_account->setPlaceholderText("请输入您的账号（不可更改！）");
    ui->le_account->setText("");
    ui->le_account->setMaxLength(16);
    ui->le_password->setPlaceholderText("请输入您的密码（可更改）(请使用ASCII字符)");
    ui->le_password->setText("");
    ui->le_password->setMaxLength(16);
    ui->cb_isteacher->setChecked(0);
}

void bookmanagerui::back_to_homepage(){
    ui->stackedWidget->setCurrentIndex(0);
}

void bookmanagerui::regist()
{
    bool ts=ui->cb_isteacher->isChecked();
    std::string username=ui->le_username->text().toStdString();
    std::string account=ui->le_account->text().toStdString();
    std::string password=ui->le_password->text().toStdString();
    if(!username.empty()&&!account.empty()&&!password.empty()){
        int state=-1;
        if(ts) state=Lib::createUser(username,account,password,User::Teacher);
        else state=Lib::createUser(username,account,password,User::Student);
        if(state==1)QMessageBox::warning(this, "警告", "用户已存在！");
        else {
            QMessageBox::information(this, "注册成功", "恭喜您，注册成功！");
            Lib::login(account,password);
            showoperate();
        }
    }
    else{
        QMessageBox::warning(this, "提示", "用户名，账号，密码不能为空！");
    }
}

void bookmanagerui::login()
{
    std::string account=ui->le_login_account->text().toStdString();
    std::string password=ui->le_login_password->text().toStdString();
    if(!account.empty()&&!password.empty()){
        auto usertype=Lib::login(account,password);
        if(usertype==User::Error){
            if(!Lib::exist_user(account))QMessageBox::warning(this, "提示", "用户不存在！");
            else QMessageBox::warning(this, "提示", "密码错误！");
        }
        else if(usertype==User::Student){
            std::string username=Lib::currentUser().name;
            std::string welcome="欢迎你，"+username+"同学！";
            QMessageBox::information(this, "登录成功", QString::fromStdString(welcome));
            showoperate();
        }
        else if(usertype==User::Teacher){
            std::string username=Lib::currentUser().name;
            std::string welcome="欢迎您，"+username+"老师！";
            QMessageBox::information(this, "登录成功", QString::fromStdString(welcome));
            showoperate();
        }
    }
    else{
        QMessageBox::warning(this, "提示", "账号，密码不能为空！");
    }
}

void bookmanagerui::showlogin()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->le_login_account->setPlaceholderText("请输入您的账号");
    ui->le_login_account->setText("");
    ui->le_login_account->setMaxLength(16);
    ui->le_login_password->setPlaceholderText("请输入您的密码");
    ui->le_login_password->setText("");
    ui->le_login_password->setMaxLength(16);
}

void bookmanagerui::showoperate()
{
    ui->stackedWidget->setCurrentIndex(4);
    std::string username=Lib::currentUser().name;
    auto usertype=Lib::currentUser().type;
    if(usertype==User::Student){
        ui->lb_welcomeuser->setText(QString::fromStdString("欢迎你，"+username+"同学！"));
        ui->pb_teacher->hide();
    }
    else ui->lb_welcomeuser->setText(QString::fromStdString("欢迎您，"+username+"老师！"));

}

void bookmanagerui::showsettings(){
    ui->stackedWidget->setCurrentIndex(3);
    ui->le_change_username->setPlaceholderText("请输入您的新用户名");
    ui->le_change_username->setText("");
    ui->le_change_username->setMaxLength(16);
    ui->le_change_password->setPlaceholderText("请输入您的新密码");
    ui->le_change_password->setText("");
    ui->le_change_password->setMaxLength(16);
}

void bookmanagerui::logout(){
    QMessageBox msgBox;
    msgBox.setWindowTitle("图书管理系统");
    msgBox.setWindowIcon(QIcon("./pics/bookmanager.ico"));
    msgBox.setText("温馨提示");
    msgBox.setInformativeText("您确定退出登录吗？");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    int ret=msgBox.exec();
    if(ret==QMessageBox::Yes)
    {
        Lib::quit();
        ui->stackedWidget->setCurrentIndex(0);
    }
}

void bookmanagerui::delete_user(){
    QMessageBox msgBox;
    msgBox.setWindowTitle("图书管理系统");
    msgBox.setWindowIcon(QIcon("./pics/bookmanager.ico"));
    msgBox.setText("温馨提示");
    msgBox.setInformativeText("您确定注销您的账号吗？(注销后将无法找回！)");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    int ret=msgBox.exec();
    if(ret==QMessageBox::Yes)
    {
        Lib::delUser();
        ui->stackedWidget->setCurrentIndex(0);
    }
}

void bookmanagerui::change_username(){
    std::string new_name=ui->le_change_username->text().toStdString();
    if(new_name.empty())QMessageBox::warning(this, "提示", "新用户名不能为空！");
    else{
        QMessageBox msgBox;
        msgBox.setWindowTitle("图书管理系统");
        msgBox.setWindowIcon(QIcon("./pics/bookmanager.ico"));
        msgBox.setText("温馨提示");
        msgBox.setInformativeText("您确定更改您的用户名吗？");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::No);
        int ret=msgBox.exec();
        if(ret==QMessageBox::Yes)
        {
            if(new_name==Lib::currentUser().name){
                QMessageBox::warning(this, "警告", "不能与原用户名相同！");
                ui->le_change_username->setText("");
            }
            else
            {
                Lib::modifyName(new_name);
                QMessageBox::information(this, "提示", "修改成功！");
                ui->le_change_username->setText("");
            }
        }
    }
}

void bookmanagerui::change_password(){
    std::string new_password=ui->le_change_password->text().toStdString();
    if(new_password.empty())QMessageBox::warning(this, "提示", "新密码不能为空！");
    else{
        QMessageBox msgBox;
        msgBox.setWindowTitle("图书管理系统");
        msgBox.setWindowIcon(QIcon("./pics/bookmanager.ico"));
        msgBox.setText("温馨提示");
        msgBox.setInformativeText("您确定更改您的密码吗？");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::No);
        int ret=msgBox.exec();
        if(ret==QMessageBox::Yes)
        {
            if(Lib::BKDRHash(new_password.c_str())==Lib::currentUser().pwd){
                QMessageBox::warning(this, "警告", "不能与原密码相同！");
                ui->le_change_password->setText("");
            }
            else
            {
                Lib::modifyPwd(new_password);
                QMessageBox::information(this, "提示", "修改成功！");
                ui->le_change_password->setText("");
            }
        }
    }
}

void bookmanagerui::closeEvent(QCloseEvent * event){
    QMessageBox msgBox;
    msgBox.setWindowTitle("图书管理系统");
    msgBox.setWindowIcon(QIcon("./pics/bookmanager.ico"));
    msgBox.setText("温馨提示");
    msgBox.setInformativeText("您确定要退出吗？");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    int ret=msgBox.exec();
    if(ret==QMessageBox::Yes){
        Lib::save();
        event->accept();
    }
    else event->ignore();
}
