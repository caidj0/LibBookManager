#include "SearchBook.h"
#include<bits/stdc++.h>
#include "myLibType.h"
#include<Qstring>
using namespace std;

extern vector<Book> books;
extern vector<Book> view_now;

bool Lib::Judgement(unsigned char c)
{
    if(c>0x80)
        return true;
    else
        return false;
}

bool Lib::comparison(wstring sentence1,wstring sentence2)
{
    int a=-1;
    bool compare=0;
    if(sentence1.empty()) return true;
    else
    {
        for(auto wc:sentence1)
        {
            a=sentence2.find(wc);
            if(a!=-1)
            {
                compare=1;
                break;
            }
        }
        return compare;
    }
}

vector<Book> Lib::findbook(wstring name,wstring author,wstring publisher,wstring categoryNumber)
{
    vector<Book> findbooks;
    int i=0;
    int k=0;
    for(i=0;i<books.size();i++)
    {
        if(Lib::comparison(name,Lib::String2Wstring(books[i].name))==true) k++;
        if(Lib::comparison(author,Lib::String2Wstring(books[i].author))==true) k++;
        if(Lib::comparison(publisher,Lib::String2Wstring(books[i].publisher))==true) k++;
        if(Lib::comparison(categoryNumber,Lib::String2Wstring(books[i].categoryNumber))==true) k++;
        if(k==4)
           {
                findbooks.push_back(books[i]);
                k=0;
           }
        else k=0;
    }
    view_now=findbooks;
    return view_now;
}

std::wstring Lib::String2Wstring(std::string str)
{
    QString qs=QString::fromStdString(str);
    std::wstring res=qs.toStdWString();
    return res;
}

std::string Lib::Wstring2String(std::wstring wstr){
    QString qs=QString::fromStdWString(wstr);
    std::string res=qs.toStdString();
    return res;
}
