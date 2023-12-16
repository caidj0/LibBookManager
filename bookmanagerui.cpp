#include "bookmanagerui.h"
#include "./ui_bookmanagerui.h"
#include "user.h"
#include"fileIO.h"
#include"bookManage.h"
#include"Searchbook.h"
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
    connect(ui->pb_search,SIGNAL(clicked(bool)),this,SLOT(search_book()));
    connect(ui->lv_info,SIGNAL(clicked(QModelIndex)),this,SLOT(show_details(QModelIndex)));
    connect(ui->pb_borrow,SIGNAL(clicked(bool)),this,SLOT(borrow_book()));
    connect(ui->pb_return,SIGNAL(clicked(bool)),this,SLOT(return_book()));
    connect(ui->pb_showall,SIGNAL(clicked(bool)),this,SLOT(show_all()));
    connect(ui->pb_teacher,SIGNAL(clicked(bool)),this,SLOT(show_teacher()));
    connect(ui->pb_addbook,SIGNAL(clicked(bool)),this,SLOT(add_book()));
    connect(ui->pb_deletebook,SIGNAL(clicked(bool)),this,SLOT(delete_book()));
    //按钮相关在上边
}

bookmanagerui::~bookmanagerui()
{
    delete ui;
}

void bookmanagerui::aboutus()
{
    QMessageBox::information(this, "关于我们", "图书管理系统");
    QMessageBox::information(this, "关于我们", "107studio出品");
    QMessageBox::information(this, "关于我们", "作品地址：https://github.com/caidj0/LibBookManager");
    QMessageBox::information(this, "关于我们", "文件操作和用户管理by万钊源");
    QMessageBox::information(this, "关于我们", "书籍查询by卢冠宇");
    QMessageBox::information(this, "关于我们", "书籍管理by李卓恒");
    QMessageBox::information(this, "关于我们", "ui设计和实现by孙晨尧");
    QMessageBox::information(this, "关于我们", "感谢使用和支持");
    QMessageBox::information(this, "关于我们", "老师，菜菜，捞捞555~");
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
    ui->pb_borrow->show();
    ui->pb_addbook->hide();
    ui->pb_return->show();
    ui->pb_deletebook->hide();
    ui->lv_info->setEditTriggers(QListView::NoEditTriggers);
    ui->te_details->setReadOnly(1);
    ui->te_details->setTextInteractionFlags(Qt::NoTextInteraction);
    std::vector<Book>booklist=Lib::dispAll();
    show_info(booklist);
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

void bookmanagerui::show_details(QModelIndex index)
{
    if(choosenow==index.row()){
        choosenow=-1;
        ui->te_details->clear();
        return;
    }
    std::vector<Book>booklist=Lib::dispNow();
    if(!booklist.empty()){
        choosenow=index.row();
        std::string details="书名："+booklist[index.row()].name+'\n'+"作者："+booklist[index.row()].author+'\n'+"出版社："
                          +booklist[index.row()].publisher+'\n'+"数量："+std::to_string(booklist[index.row()].remaining)+'\n'+
                          "书籍类别号："+booklist[index.row()].categoryNumber;
        ui->te_details->setText(QString::fromStdString(details));
    }
    else{
        choosenow=-1;
        ui->te_details->setText(QString("暂时还没有书籍哦，快去添加吧！"));
    }
}

void bookmanagerui::search_book(){
    if(firstsearch){
        QMessageBox::information(this, "使用说明", "查询功能支持单索引/多索引查询，支持部分关键字搜索，请按提示搜索，搜索结果将显示在左栏");
        firstsearch=0;
        ui->pb_search->setText(QString("查询"));
        //return;
    }
    bool next=0;
    std::wstring name= QInputDialog::getText(this, "书籍管理系统","请输入您想查询的书名",QLineEdit::Normal,"",&next).toStdWString();
    if(!next)return;
    std::wstring author= QInputDialog::getText(this, "书籍管理系统","请输入您想查询的作者",QLineEdit::Normal,"",&next).toStdWString();
    if(!next)return;
    std::wstring publisher= QInputDialog::getText(this, "书籍管理系统","请输入您想查询的出版社",QLineEdit::Normal,"",&next).toStdWString();
    if(!next)return;
    std::wstring categoryNumber= QInputDialog::getText(this, "书籍管理系统","请输入您想查询的序列号",QLineEdit::Normal,"",&next).toStdWString();
    if(!next)return;
    //ui->te_details->setText(QString::fromStdString(author+'\n'+name+'\n'+publisher));
    if(!(name.empty()&&author.empty()&&publisher.empty()&&categoryNumber.empty())){
        std::vector<Book>booklist=Lib::findbook(name,author,publisher,categoryNumber);
        if(booklist.empty()){
            QMessageBox::information(this, "提示", "没有找到相关书籍！");
        }
        else{
            QMessageBox::information(this, "提示", "查找成功！已将所有结果显示到左边栏");
            ui->te_details->clear();
            choosenow=-1;
            show_info(booklist);
        }
    }
    else{
        QMessageBox::warning(this, "警告", "输入不能为空！");
    }
}

void bookmanagerui::show_info(std::vector<Book>&booklist){
    ui->lv_info->clearPropertyFlags();
    QStringList q_booklist;
    if(!booklist.empty())
    {
        for(auto book:booklist){
            q_booklist.append(QString::fromStdString(book.name+" "+book.author));
        }
    }
    else{
        q_booklist.append(QString("暂时还没有书籍哦，快去添加吧！"));
    }
    QStandardItemModel *ItemModel;
    ItemModel = new QStandardItemModel(this);
    for(int i=0;i<q_booklist.size();i++){
        QString string = static_cast<QString>(q_booklist.at(i));
        QStandardItem *item = new QStandardItem(string);
        ItemModel->appendRow(item);
    }
    ui->lv_info->setModel(ItemModel);
}

void bookmanagerui::borrow_book(){
    if(borrowfirst){
        QMessageBox::information(this, "使用说明", "请先使用查询功能查找您想借的书，查找完毕后在左侧边栏选中后点击借书按钮方可借书");
        borrowfirst=0;
        ui->pb_borrow->setText(QString("借书"));
        //return;
    }
    if(choosenow==-1){
        QMessageBox::warning(this,"提示","请先选中书籍！");
    }
    else{
        std::vector<Book> booklist=Lib::dispNow();
        bool isempty=0;
        std::string num_s= QInputDialog::getText(this, "书籍管理系统","请输入您想借阅的数量",QLineEdit::Normal,"",&isempty).toStdString();
        if(!isempty)return;
        if(num_s.length()>9){
            QMessageBox::warning(this,"警告","数据过大！");
            return;
        }
        int num=atoi(num_s.c_str());
        int state=Lib::borrowBook(Lib::String2Wstring(booklist[choosenow].name),Lib::String2Wstring(booklist[choosenow].author),Lib::String2Wstring(booklist[choosenow].publisher),num);
        if(state==0){
            QMessageBox::warning(this,"提示","查无此书！");
        }
        else if(state==2){
            QMessageBox::warning(this,"提示","借书数量超过上限！");
        }
        else if(num<=0){
            QMessageBox::warning(this,"警告","请输入有效数字！");
            return;
        }
        else{
            QMessageBox::information(this,"提示","借阅成功！");
            booklist[choosenow].remaining-=num;
            std::string details="书名："+booklist[choosenow].name+'\n'+"作者："+booklist[choosenow].author+'\n'+"出版社："
                                  +booklist[choosenow].publisher+'\n'+"数量："+std::to_string(booklist[choosenow].remaining)+'\n'+
                                  "书籍类别号："+booklist[choosenow].categoryNumber;
            ui->te_details->setText(QString::fromStdString(details));
            Lib::Synchronize();
        }
    }
}

void bookmanagerui::return_book(){
    if(returnfirst){
        QMessageBox::information(this, "使用说明", "请先使用查询功能查找您想还的书，查找完毕后在左侧边栏选中后点击还书按钮方可还书");
        returnfirst=0;
        ui->pb_return->setText(QString("还书"));
        //return;
    }
    if(choosenow==-1){
        QMessageBox::warning(this,"提示","请先选中书籍！");
    }
    else{
        std::vector<Book> booklist=Lib::dispNow();
        bool isempty=0;
        std::string num_s= QInputDialog::getText(this, "书籍管理系统","请输入您想还书的数量",QLineEdit::Normal,"",&isempty).toStdString();
        if(!isempty)return;
        if(num_s.length()>9){
            QMessageBox::warning(this,"警告","数据过大！");
            return;
        }
        int num=atoi(num_s.c_str());
        int state=Lib::returnBook(Lib::String2Wstring(booklist[choosenow].name),Lib::String2Wstring(booklist[choosenow].author),Lib::String2Wstring(booklist[choosenow].publisher),num);
        if(state==0){
            QMessageBox::warning(this,"提示","查无此书！");
        }
        else if(num<=0){
            QMessageBox::warning(this,"警告","请输入有效数字！");
            return;
        }
        else{
            QMessageBox::information(this,"提示","还书成功！");
            booklist[choosenow].remaining+=num;
            std::string details="书名："+booklist[choosenow].name+'\n'+"作者："+booklist[choosenow].author+'\n'+"出版社："
                                  +booklist[choosenow].publisher+'\n'+"数量："+std::to_string(booklist[choosenow].remaining)+'\n'+
                                  "书籍类别号："+booklist[choosenow].categoryNumber;
            ui->te_details->setText(QString::fromStdString(details));
            Lib::Synchronize();
        }
    }
}

void bookmanagerui::show_all(){
    std::vector<Book>booklist=Lib::dispAll();
    choosenow=-1;
    ui->te_details->clear();
    show_info(booklist);
}

void bookmanagerui::show_teacher(){
    if(nowpage==0){
    ui->pb_borrow->hide();
    ui->pb_addbook->show();
    ui->pb_return->hide();
    ui->pb_deletebook->show();
    nowpage=1;
    ui->pb_teacher->setText(QString("返回"));
    }
    else{
        ui->pb_borrow->show();
        ui->pb_addbook->hide();
        ui->pb_return->show();
        ui->pb_deletebook->hide();
        nowpage=0;
        ui->pb_teacher->setText(QString("教师界面"));
    }
}

void bookmanagerui::add_book(){
    if(addfirst){
        QMessageBox::information(this,"提示","您可以通过搜索功能查找现有书籍，直接增加选定书籍的数量，也可以手动添加新书籍");
        addfirst=0;
    }
    if (choosenow!=-1){
        QMessageBox msgBox;
        msgBox.setWindowTitle("图书管理系统");
        msgBox.setWindowIcon(QIcon("./pics/bookmanager.ico"));
        msgBox.setText("提示");
        msgBox.setInformativeText("您确定添加这本书吗?");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::No);
        int ret=msgBox.exec();
        if(ret==QMessageBox::Yes){
            std::vector<Book> booklist=Lib::dispNow();
            std::string num_s= QInputDialog::getText(this, "书籍管理系统","请输入您想添加的数量",QLineEdit::Normal).toStdString();
            if(num_s.length()>9){
                QMessageBox::warning(this,"警告","数据过大！");
                return;
            }
            int num=atoi(num_s.c_str());
            if(num<=0){
                QMessageBox::warning(this,"警告","请输入有效数字！");
                return;
            }
            int state=Lib::addBook(booklist[choosenow].name,booklist[choosenow].author,booklist[choosenow].publisher,num);
            if(state==-1){
                QMessageBox::warning(this,"警告","操作出错！");
            }
            else{
                QMessageBox::information(this,"提示","操作成功！");
            }
            booklist[choosenow].remaining+=num;
            std::string details="书名："+booklist[choosenow].name+'\n'+"作者："+booklist[choosenow].author+'\n'+"出版社："
                                  +booklist[choosenow].publisher+'\n'+"数量："+std::to_string(booklist[choosenow].remaining)+'\n'+
                                  "书籍类别号："+booklist[choosenow].categoryNumber;
            ui->te_details->setText(QString::fromStdString(details));
            Lib::Synchronize();
            return;
        }
    }
    bool next=0;
    std::string name= QInputDialog::getText(this, "书籍管理系统","请输入您想添加的书名",QLineEdit::Normal,"",&next).toStdString();
    if(!next)return;
    std::string author= QInputDialog::getText(this, "书籍管理系统","请输入您想添加书的作者",QLineEdit::Normal,"",&next).toStdString();
    if(!next)return;
    std::string publisher= QInputDialog::getText(this, "书籍管理系统","请输入您想添加书的出版社",QLineEdit::Normal,"",&next).toStdString();
    if(!next)return;
    std::string num_s= QInputDialog::getText(this, "书籍管理系统","请输入您想添加的数量",QLineEdit::Normal).toStdString();
    if(num_s.length()>9){
        QMessageBox::warning(this,"警告","数据过大！");
        return;
    }
    if(!(!name.empty()&&!author.empty()&&!publisher.empty())){
        QMessageBox::warning(this,"警告","无效输入！");
        return;
    }
    int num=atoi(num_s.c_str());
    if(num<=0){
        QMessageBox::warning(this,"警告","请输入有效数字！");
        return;
    }
    int state=Lib::addBook(name,author,publisher,num);
    if(state==-1){
        QMessageBox::warning(this,"警告","操作出错！");
    }
    else if(state==0){
        QMessageBox::information(this,"提示","该书籍已存在,已在现有书籍上增加！");
    }
    else{
        QMessageBox::information(this,"提示","操作成功！");
        Lib::Synchronize();
    }
    show_all();
}

void bookmanagerui::delete_book(){
    if(deletefirst){
        QMessageBox::information(this,"提示","您可以通过搜索功能查找您想删除的书籍，直接删除选定书籍，也可以通过序列号删除书籍");
        deletefirst=0;
    }
    if (choosenow!=-1){
        QMessageBox msgBox;
        msgBox.setWindowTitle("图书管理系统");
        msgBox.setWindowIcon(QIcon("./pics/bookmanager.ico"));
        msgBox.setText("提示");
        msgBox.setInformativeText("您确定删除当前选定的这本书吗?");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::No);
        int ret=msgBox.exec();
        if(ret==QMessageBox::Yes){
            std::vector<Book> booklist=Lib::dispNow();
            int state=Lib::deleteBook(booklist[choosenow].categoryNumber);
            if(state==-1){
                QMessageBox::warning(this,"警告","操作出错！");
            }
            else if(state==0){
                QMessageBox::warning(this,"警告","查无此书！");
            }
            else{
                QMessageBox::information(this,"提示","操作成功！");
                Lib::Synchronize();
            }
            show_all();
            return;
        }
    }
    bool next=0;
    std::string categoryNumber= QInputDialog::getText(this, "书籍管理系统","请输入您想删除的书的序列号",QLineEdit::Normal,"",&next).toStdString();
    if(!next)return;
    int state=Lib::deleteBook(categoryNumber);
    if(state==-1){
        QMessageBox::warning(this,"警告","操作出错！");
    }
    else if(state==0){
        QMessageBox::warning(this,"警告","查无此书！");
    }
    else{
        QMessageBox::information(this,"提示","操作成功！");
        Lib::Synchronize();
    }
    show_all();
}
