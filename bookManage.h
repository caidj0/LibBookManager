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
    int addBook(std::string name,std::string author,std::string publisher,int num);//增加书籍前，判断是新的还是老的
    std::vector<Book> dispAll();//显示所有书籍
    std::vector<Book> dispNow();//显示某种书籍
    int borrowBook(std::wstring name,std::wstring author,std::wstring publisher,int numBook);
    int returnBook(std::wstring name,std::wstring author,std::wstring publisher,int numBook);
    int deleteBook(std::string cnum);
    void Synchronize();
}
#endif//BOOKMANAGE_H
