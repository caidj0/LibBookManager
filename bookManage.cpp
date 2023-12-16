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
extern vector<Book> view_now;

bool Judgement(unsigned char c)
{
    if(c>0x80)
        return true;
    else
        return false;
}


Book *insertfindbook (wstring all)
{
    for(auto &book:books)
    {
        if(all==Lib::String2Wstring(book.name+book.author+book.publisher))
        {
            return &book;
        }
    }
    return nullptr;
}
vector<Book>::iterator insertfindbookbycnum (string cnum)
{
    for(auto it=books.begin();it!=books.end();it++)
    {
        if(cnum==(*it).categoryNumber)
        {
            return it;
        }
    }
    return books.end();
}

int Lib::addBook(std::string name,std::string author,std::string publisher,int num){//增加书籍
    wstring w_name=Lib::String2Wstring(name);
    wstring w_author=Lib::String2Wstring(author);
    wstring w_publisher=Lib::String2Wstring(publisher);
        if(w_name.substr(0,1)!=L"《"){
            w_name=L"《"+w_name;
        }
        if(w_name.substr(w_name.length()-1,1)!=L"》"){
            w_name=w_name+L"》";
        }
    name=Lib::Wstring2String(w_name);
    Book *book=insertfindbook(w_name+w_author+w_publisher);
    if(book==nullptr){
        string cnum;
        cnum=name+author+publisher;
        string h_cnum=to_string(hash<string>()(cnum));
        Book new_book={name,author,publisher,h_cnum,num};
        books.push_back(new_book);
        return 1;
    }
    else{
        book->remaining+=num;
        return 0;
    }
    return -1;
}

vector<Book> Lib::dispAll(){//显示全部书籍
    view_now=books;
    return view_now;
};

vector<Book> Lib::dispNow(){//显示某种书籍
    return view_now;
}
int Lib::borrowBook(wstring name,wstring author,wstring publisher,int numBook) {
    Book *book=insertfindbook(name+author+publisher);
    if(book==nullptr)return 0;
    if(numBook>book->remaining)return 2;
    book->remaining-=numBook;
    return 1;
}

int Lib::returnBook(wstring name,wstring author,wstring publisher,int numBook) {
    Book *book=insertfindbook(name+author+publisher);
    if(book==nullptr)return 0;
    book->remaining+=numBook;
    return 1;
}

int Lib::deleteBook(string cnum) {
    auto book=insertfindbookbycnum(cnum);
    if(book==books.end())return 0;
    else{
    books.erase(book);
    return 1;
    }
    return -1;
}

void Lib::Synchronize(){
    for(auto &vnbook:view_now){
        for(const auto book:books){
            if(vnbook.categoryNumber==book.categoryNumber){
                vnbook=book;
                break;
            }
        }
    }
}
