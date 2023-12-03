#ifndef SEARCHBOOK_H
#define SEARCHBOOK_H
#include<string>

using namespace std;

class SearchBook
{
    public:
        SearchBook();
        virtual ~SearchBook();
        void findbook();
        bool comparison(string sentence1,string sentence2);
        bool Judgement(unsigned char c);
};

#endif // SEARCHBOOK_H
