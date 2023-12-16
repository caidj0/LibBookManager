#ifndef BOOKMANAGERUI_H
#define BOOKMANAGERUI_H

#include <QMainWindow>
#include<QMessageBox>
#include <QStandardItemModel>
#include<QListView>
#include<QStringConverter>
#include<QInputDialog>
#include<bits/stdc++.h>
#include"myLibType.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class bookmanagerui;
}
QT_END_NAMESPACE

class bookmanagerui : public QMainWindow
{
    Q_OBJECT

public:
    bookmanagerui(QWidget *parent = nullptr);
    void closeEvent(QCloseEvent * event);
    void show_info(std::vector<Book> &booklist);
    ~bookmanagerui();
public slots:
    void aboutus();
    void showregist();
    void regist();
    void back_to_homepage();
    void showlogin();
    void login();
    void showsettings();
    void showoperate();
    void logout();
    void delete_user();
    void change_username();
    void change_password();
    void search_book();
    void borrow_book();
    void return_book();
    void show_all();
    void show_teacher();
    void add_book();
    void delete_book();
    void show_details(QModelIndex index);

private:
    Ui::bookmanagerui *ui;
    bool firstsearch=1,borrowfirst=1,returnfirst=1,addfirst=1,deletefirst=1;
    int choosenow=-1,nowpage=0;
};
#endif // BOOKMANAGERUI_H
