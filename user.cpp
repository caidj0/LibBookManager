#include "user.h"
#include "myLibType.h"
#include <map>
#include <vector>
using namespace std;

extern vector<Book> books;
extern map<string, User> users;
string loggingUser;

int Lib::createUser(std::string name, std::string account, std::string pwd, User::UserType type)
{
    if(users.count(account))
        return 1;
    users[account] = User{name,account,BKDRHash(pwd.c_str()),type};
    return 0;
}

User::UserType Lib::login(std::string account, std::string pwd)
{
    if(users.count(account) && users[account].pwd == BKDRHash(pwd.c_str()))
    {
        loggingUser = account;
        return users[account].type;
    }
    return User::UserType::Error;
}

void Lib::modifyName(std::string new_name)
{
    users[loggingUser].name = new_name;
}

void Lib::modifyPwd(std::string new_pwd)
{
    users[loggingUser].pwd = BKDRHash(new_pwd.c_str());
}

void Lib::quit()
{
    loggingUser.clear();
}

void Lib::delUser()
{
    users.erase(loggingUser);
    loggingUser.clear();
}

bool Lib::is_login()
{
    return !loggingUser.empty();
}

const User Lib::currentUser()
{
    if(is_login())
        return users[loggingUser];
    return User{};
}

unsigned int Lib::BKDRHash(const char *str)
{
    unsigned int seed = 131; // 31 131 1313 13131 131313 etc..
    unsigned int hash = 0;
 
    while (*str)
    {
        hash = hash * seed + (*str++);
    }
 
    return (hash & 0x7FFFFFFF);
}