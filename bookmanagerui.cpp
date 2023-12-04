#include "bookmanagerui.h"
#include "./ui_bookmanagerui.h"
#include "user.h"
#include<string>

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
    connect(ui->pb_regist_back,SIGNAL(clicked(bool)),this,SLOT(regist_back()));
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
    ui->le_password->setPlaceholderText("请输入您的密码（不可更改！）(请使用ASCII字符)");
    ui->le_password->setText("");
    ui->le_password->setMaxLength(16);
    ui->cb_isteacher->setChecked(0);
}

void bookmanagerui::regist_back(){
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
            ui->stackedWidget->setCurrentIndex(0);
        }
    }
    else{
        QMessageBox::warning(this, "提示", "用户名，账号，密码不能为空！");
    }

}
