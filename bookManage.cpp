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


int Lib::addBook(User::UserType type,std::string name,std::string author,std::string publisher,int num,bool judge){//增加书籍
    if(judge==1){//新书
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

void Lib::disp(int i){//显示某种书籍
    cout<<books[i].name<<" "<<books[i].author<<" "<<books[i].publisher<<" "<<books[i].remaining<<" "<<books[i].categoryNumber<<endl;
}

void Lib::borrowBook(string name1,int numBook) {
    string name=name1;
    string author="\0";
    string publisher="\0";
    string categoryNumber="\0";
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
                disp(i);
                break;
           }
        else k=0;
    }
    if(flag==false){
        cout<<"查无此书"<<endl;
    }
    else{
        string cnum;
        cin>>cnum;
        Book *book=insertfindbook("","","",cnum);
        book->remaining=(numBook<book->remaining?(book->remaining-numBook):0);//如果借书的数量超过所剩的书数量，则只允许借出最多的书
        cout<<"借书成功！"<<endl;
    }

    

}

void Lib::returnBook(string name,int numBook) {
    if(insertjudgebook(name,"","","")!=1){
        cout<<"查无此书"<<endl;
    }
    else{
        Book *book=insertfindbook(name,"","","");
        book->remaining+=numBook;
        cout<<"还书成功！"<<endl;
    }
    
}

int Lib::deleteBook(User user, std::string categoryNumber1) {
     if(user.type==User::UserType::Teacher){
         if(insertjudgebook("","","",categoryNumber1)==1){
            int k=insertfind("","","",categoryNumber1);
            books.erase(books.begin()+k);
            return 1;
        }
        else{
            cout<<"Error!"<<endl;
            return 0;
        }
     }
     else{
        cout<<"您没有权限！"<<endl;
        return 1;
     }
     return -1;

}
