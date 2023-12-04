#ifndef MYLibType
#define MYLibType
#include <string>

/*
书籍类
name: 书籍名称
author: 作者
publisher: 出版社
categoryNumber: 书籍类别号
remaining: 剩余数量
*/
class Book{
public:
    std::string name;
    std::string author;
    std::string publisher;
    std::string categoryNumber;
    int remaining;
    Book(){};
    Book(std::string name,std::string author,std::string publisher,std::string categoryNumber,int remaining):name(name),author(author),publisher(publisher),categoryNumber(categoryNumber),remaining(remaining){};
    Book(std::string name,std::string author,std::string publisher,long long categoryNumber,int remaining):name(name),author(author),publisher(publisher),categoryNumber(std::to_string(categoryNumber)),remaining(remaining){};
};


/*
用户类
name: 用户名
account: 账号
pwd: 用户密码（加密后的）
type: 用户类型
*/
class User{
public:
    enum UserType{
        None,Student,Teacher,Error //未登录，学生，老师，错误（找不到）
    };
    std::string name;
    std::string account;
    unsigned int pwd;
    UserType type;
    User(){};
    User(std::string name,std::string account,unsigned int pwd,UserType type):name(name),account(account),pwd(pwd),type(type){};
};
#endif