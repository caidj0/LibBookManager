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
Book *insertfindbook (string name1)
{
    string name=name1;
    string author="\0";
    string publisher="\0";
    string categoryNumber="\0";
    int i=0;
    int k=0;
    bool flag=false;
    for(i=0;i<10;i++)
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

}
vector<Book> Lib::addBook(User::UserType type,std::string name,std::string author,std::string publisher,int num,bool judge){//增加书籍
    if(judge==1){
    Book book;
    string cnum;
    cnum=name+author+publisher;
    book.name=name;
    book.author=author;
    book.publisher=publisher;
    book.remaining=num;
    book.categoryNumber=to_string(hash<string>()(cnum));
    books.push_back(book);
    }
    else{
    Book *book=insertfindbook(name);
    book->remaining+=num;
        
    }
}

void Lib::disp(){//显示全部书籍
    for(int i=0;i<books.size();i++){
    cout<<books[i].name<<" "<<books[i].author<<" "<<books[i].publisher<<" "<<books[i].remaining<<" "<<books[i].categoryNumber<<endl;
    }
};