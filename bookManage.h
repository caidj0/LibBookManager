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
    std::vector<Book> addBook(User::UserType type,std::string name,std::string author,std::string publisher,int num);
    void disp();
    void borrowBook(std::string name);
    void returnBook(std::string name);
    std::vector<Book> deleteBook(User::UserType type,std::string categoryNumber);
}
#endif//BOOKMANAGE_H