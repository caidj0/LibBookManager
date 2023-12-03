#include "SearchBook.h"
#include <map>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include "myLibType.h"

using namespace std;

extern vector<Book> books;

SearchBook::SearchBook()
{

}

SearchBook::~SearchBook()
{

}


bool SearchBook::Judgement(unsigned char c)//汉字判断函数，无需调用
{
    if(c>0x80)
        return true;
    else
        return false;
}

bool SearchBook::comparison(string sentence1,string sentence2)//字符比较函数，无需调用
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
                a=sentence2.find(substr(sentence1(i,2));
                if(a==-1)
                {
                    compare=false;break;
                }
            }
            else
            {
                a=sentence2.find(sentence[i]);
                if(a==-1)
                {
                    compare=false;break;
                }
            }
        }
        return compare;
    }
}

vector<Book> SearchBook::findbook(string name,string author,string publisher,string categoryNumber)//关键词搜索书籍函数
{
    vector<Book> findbooks;
    if(name.empty()==1) name="\0";
    if(author.empty()==1) author="\0";
    if(categoryNumber.empty()==1) categoryNumber="\0";
    if(publisher.empty()==1) publisher="\0";
    int i=0;
    int k=0;
    for(i=0;i<books.size();i++)
    {
        if(comparison(name,books[i].name)==true) k++;
        if(comparison(author,books[i].author)==true) k++;
        if(comparison(publisher,books[i].publisher)==true) k++;
        if(comparison(categoryNumber,books[i].categoryNumber)==true) k++;
        if(k==4)
           {
                findbooks.push_back(books[i]);
                k=0;
           }
        else k=0;
    }
    return findbooks;
}
