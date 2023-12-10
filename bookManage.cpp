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

bool Judgement(unsigned char c)
{
    if(c>0x80)
        return true;
    else
        return false;
}

bool comparison(string sentence1,string sentence2)
{
    char* p=&sentence1[0];
    int a=-1;
    int i=0;
    int times=0;
    bool flag=true;
    bool compare=true;
    if(sentence1=="\0") return true;
    else
    {
        for(i=0;sentence1[i]!='\0';i++)
        {
            flag=Judgement(sentence1[i]);
            if(flag==true)
            {
                string str=sentence1.substr(i,2);
                a=sentence2.find(str);
                if(a==-1)
                {
                    compare=false;
                }
                i++;
            }
            else
            {
                a=sentence2.find(sentence1[i]);
                if(a==-1)
                {
                    compare=false;
                }
            }
        }
        return compare;
    }
}
Book *insertfindbook (string name1,string author1,string publisher1,string categoryNumber1)
{
    string name=name1;
    string author=author1;
    string publisher=publisher1;
    string categoryNumber=categoryNumber1;
    int i=0;
    int k=0;
    bool flag=false;
    for(i=0;i<books.size();i++)
    {
        if(comparison(name,books[i].name)==true) k++;
        if(comparison(author,books[i].author)==true) k++;
        if(comparison(publisher,books[i].publisher)==true) k++;
        if(comparison(categoryNumber,books[i].categoryNumber)==true) k++;
        if(k==4)
           {
                k=0;
                return &books[i];
           }
        else k=0;
    }
    return nullptr;
}
int insertfind (string name1,string author1,string publisher1,string categoryNumber1)
{
    string name=name1;
    string author=author1;
    string publisher=publisher1;
    string categoryNumber=categoryNumber1;
    int i=0;
    int k=0;
    bool flag=false;
    for(i=0;i<books.size();i++)
    {
        if(comparison(name,books[i].name)==true) k++;
        if(comparison(author,books[i].author)==true) k++;
        if(comparison(publisher,books[i].publisher)==true) k++;
        if(comparison(categoryNumber,books[i].categoryNumber)==true) k++;
        if(k==4)
           {
                k=0;
                return i;
           }
        else k=0;
    }
    return -1;
}
bool insertjudgebook(string name1,string author1,string publisher1,string categoryNumber1){
    string name=name1;
    string author=author1;
    string publisher=publisher1;
    string categoryNumber=categoryNumber1;
    int i=0;
    int k=0;
    bool flag=false;
    for(i=0;i<books.size();i++)
    {
        if(comparison(name,books[i].name)==true) k++;
        if(comparison(author,books[i].author)==true) k++;
        if(comparison(publisher,books[i].publisher)==true) k++;
        if(comparison(categoryNumber,books[i].categoryNumber)==true) k++;
        if(k==4)
           {
                k=0;
                flag=true;
                break;
           }
        else k=0;
    }
    return flag;
}


int Lib::addBook(std::string name,std::string author,std::string publisher,int num){//增加书籍
    if(insertjudgebook(name,author,publisher,"")==0){//新书，查找不到的
    Book book;
    string cnum;
    cnum=name+author+publisher;
    book.name=name;
    book.author=author;
    book.publisher=publisher;
    book.remaining=num;
    book.categoryNumber=to_string(hash<string>()(cnum));
    books.push_back(book);
    return 1;
    }
    else{//老书
    Book *book=insertfindbook(name,"","","");
    book->remaining+=num;
        return 1;
    }
    
    return -1;
    
}

vector<Book> Lib::dispAll(){//显示全部书籍
    return books;
};


int Lib::borrowBook(string categoryNumber1,int numBook) {
       Book *book=insertfindbook("","","",categoryNumber1);
       if(numBook>(book->remaining)){
        return 0;//借书数量超过上限，借书失败
       }
       else{
        return 1;//借书成功！
       }
    return -1;

}

int Lib::returnBook(string name,int numBook) {
    if(insertjudgebook(name,"","","")!=1){
        return 0;//查无此书！
    }
    else{
        Book *book=insertfindbook(name,"","","");
        book->remaining+=numBook;
        return 1;//还书成功！
    }
    return -1;
}

int Lib::deleteBook(std::string categoryNumber1) {
     
         if(insertjudgebook("","","",categoryNumber1)==1){
            int k=insertfind("","","",categoryNumber1);
            books.erase(books.begin()+k);
            return 1;
        }
        else{
            cout<<"Error!"<<endl;
            return 0;
        }
     
     return -1;

}
