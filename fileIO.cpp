#include "fileIO.h"
#include <fstream>
#include <map>
#include <string>
#include <vector>
using namespace std;


extern vector<Book> books;
extern map<string, User> users;



int Lib::readFrom(string path)
{
    ifstream in;
    in.open(path);
    if(in.is_open())
    {
        try{
            string str;
            int mode = 0;
            while(!in.eof())
            {
                getline(in,str);
                if(!str.empty())
                {
                    if(str == "USER")
                    {
                        mode = 1;
                        continue;
                    }
                    if(str == "BOOK")
                    {
                        mode = 2;
                        continue;
                    }
                    if(mode == 2)
                    {
                        string author,publisher,categoryNumber,remaining;
                        // getline(in,name);
                        getline(in,author);
                        getline(in,publisher);
                        getline(in,categoryNumber);
                        getline(in,remaining);
                        books.emplace_back(str,author,publisher,categoryNumber,stoi(remaining));
                    }
                    if(mode == 1)
                    {
                        string account,pwd,type;
                        // getline(in,name);
                        getline(in,account);
                        getline(in,pwd);
                        getline(in,type);
                        users[account] = User{str,account,stoul(pwd),User::UserType(stoi(type))};
                    }
                }
                
            }
            in.close();
        } catch (...)
        {
            return 2;
        }
    } else return 1;
    return 0;
}

int Lib::read()
{
    return readFrom("data.txt");
}

int Lib::saveTo(string path)
{
    ofstream out;
    out.open(path);
    if(out.is_open())
    {
        try{
            out << "USER" << "\n";
            for(auto x : users)
            {
                out << x.second.name + "\n" + x.second.account + "\n" + to_string(x.second.pwd) + "\n" + to_string(x.second.type) + "\n";
            }
            out << "BOOK" << "\n";
            for(auto x: books)
            {
                out << x.name + "\n" + x.author + "\n" + x.publisher + "\n" + x.categoryNumber + "\n" + to_string(x.remaining) + "\n";
            }
            out.close();
        } catch(...)
        {
            return 2;
        }
    }else return 1;
    return 0;
}

int Lib::save()
{
    return saveTo("data.txt");
}