#ifndef BOOKMANAGE_H
#define BOOKMANAGE_H
#include<string>
#include<vector>
#include "myLibType.h"
/*六类书籍：
1、文学类:L+num
2、社会科学类：S+num
3、自然科学类:N
4、工程技术类：E
5、医药卫生类:M
6、综合类:C
*/
namespace Lib{
    int addBook(User::UserType type,std::string name,std::string author,std::string publisher,int num,bool judge);//增加书籍前，判断是新的还是老的
    void dispAll();//显示所有书籍
    void disp(int i);//显示某种书籍
    void borrowBook(std::string name1,int numBook/*借书的数量*/);//借书
    void returnBook(std::string name,int numBook/*还书的数量*/);
    int deleteBook(User user,std::string categoryNumber1);
}
#endif//BOOKMANAGE_H