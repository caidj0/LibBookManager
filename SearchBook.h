#ifndef SEARCHBOOK_H
#define SEARCHBOOK_H
#include<string>
#include<vector>
#include "myLibType.h"

namespace Lib {

        std::vector<Book> findbook(std::string name,std::string author,std::string publisher,std::string categoryNumber);
        bool comparison(std::string sentence1,std::string sentence2);
        bool Judgement(unsigned char c);
}

#endif // SEARCHBOOK_H
