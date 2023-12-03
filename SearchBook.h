#ifndef SEARCHBOOK_H
#define SEARCHBOOK_H
#include<string>

using namespace std;

class SearchBook
{
    public:
        SearchBook();
        virtual ~SearchBook();
        vector<Book> findbook(string name,string author,string publisher,string categoryNumber)
        bool comparison(string sentence1,string sentence2);
        bool Judgement(unsigned char c);
};

#endif // SEARCHBOOK_H
