#include"bookManage.h"
#include "SearchBook.h"
#include <map>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include "myLibType.h"
using namespace std;
extern vector<Book> books;

vector<Book> Lib::addBook(User::UserType type,std::string name,std::string author,std::string publisher,int num,bool judge){//增加书籍
    if(judge==1){
    Book book;
    book.name=name;
    book.author=author;
    book.publisher=publisher;
    book.remaining=num;
    books.push_back(book);
    }
    else{
        
    }
}

void Lib::disp(){//显示全部书籍
    for(int i=0;i<books.size();i++){
    cout<<books[i].name<<" "<<books[i].author<<" "<<books[i].publisher<<" "<<books[i].remaining<<" "<<books[i].categoryNumber;
    }
};