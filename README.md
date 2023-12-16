# 图书馆书记管理系统
107 组
组员：万钊源 孙晨尧 李卓恒 卢冠宇

c++版本 std14

## 基本要求
### 用户管理（user.*）
- [x] 创建用户 createUser
- [x] 登录（通过提供用户名+密码）返回登录是否成功，用户身份(可用0,1,2表示) login
- [x] 修改用户信息 modifyName modifyPwd
- [x] 注销用户 delUser
- [x] 退出 quit

### 书籍管理（bookManage.*）
- [x] 书籍增加
- [x] 查看书籍
- [x] 借还书
- [x] 删除书籍

### 书籍搜索（SearchBook.*）
- [x] 输入搜索内容，返回Book数组


## 额外要求
### 文件存储（fileIO.*）
- [x] 读取文件，返回一个（或者储存到全局变量）用户列表（vector/数组指针），书籍列表（vector/数组指针存到了main里的book）
- [x] 将用户列表，书籍列表储存到文件 save read

### 图形界面（bookmanagerui.*）
- [x] 使用Qt创建图形界面
