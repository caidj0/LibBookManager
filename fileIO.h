#ifndef MYFILE_IO
#define MYFILE_IO

#include <string>
#include "myLibType.h"

namespace Lib {
    /*
    读取/写入文件
    返回0表示成功，1打开文件失败，2其他错误
    */
    int read();
    int readFrom(std::string path);
    int save();
    int saveTo(std::string path);
}
#endif