#ifndef MYUSER
#define MYUSER
#include "myLibType.h"
#include <string>

namespace Lib {


/*
创建用户
返回0表示成功，1表示账号已存在
密码只能用ASCII字符（hash算法的限制）
*/
int createUser(std::string name,std::string account,std::string pwd,User::UserType type);

/*
登录
返回用户类型
*/
User::UserType login(std::string account,std::string pwd);


void modifyName(std::string new_name);

void modifyPwd(std::string new_pwd);


/*退出账户*/
void quit();

/*
注销登录中的账号，并退出登录
*/
void delUser();

/*
是否登录中
*/
bool is_login();


/*
返回当前登录用户
若未登录则返回用户的type为None
*/
const User currentUser();

/*Hash算法，用于hash密码*/
unsigned int BKDRHash(const char *str);

}
#endif