#include "bookmanagerui.h"
#include "myLibType.h"
#include"fileIO.h"
#include<vector>
#include<map>
#include <QApplication>
using namespace std;
/*
书籍列表的全局变量
*/
vector<Book> books;
vector<Book> view_now;
/*
用户列表的全局变量
*/
map<string, User> users;
int main(int argc, char *argv[])
{
    //cout<<'s';
    Lib::read();
    view_now=books;
    QApplication a(argc, argv);
    bookmanagerui w;
    w.setWindowTitle("图书管理系统");
    w.setWindowIcon(QIcon("./pics/bookmanager.ico"));
    w.setFixedSize(800,484);
    w.show();
    return a.exec();
}
