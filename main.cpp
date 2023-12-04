#include "bookmanagerui.h"
#include "myLibType.h"
#include<vector>
#include<map>
#include <QApplication>
using namespace std;
/*
书籍列表的全局变量
*/
vector<Book> books;

/*
用户列表的全局变量
*/
map<string, User> users;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    bookmanagerui w;
    w.setWindowTitle("图书管理系统");
    w.show();
    return a.exec();
}
