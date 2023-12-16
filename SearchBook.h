#ifndef SEARCHBOOK_H
#define SEARCHBOOK_H
#include<string>
#include<vector>
#include "myLibType.h"

namespace Lib {

std::vector<Book> findbook(std::wstring name,std::wstring author,std::wstring publisher,std::wstring categoryNumber);
        bool comparison(std::wstring sentence1,std::wstring sentence2);
        bool Judgement(unsigned char c);
        std::wstring String2Wstring(std::string str);
        std::string Wstring2String(std::wstring wstr);
}

#endif // SEARCHBOOK_H
