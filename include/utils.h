#ifndef UTILS_H
#define UTILS_H

#include <windows.h>

// 时间相关变量声明
extern DWORD t1, t2;

// 函数声明
void gotoxy(int x, int y);      // 光标跳转
void gotoprint(int x, int y);   // 跳转打印
void gotodelete(int x, int y);  // 跳转删除
int color(int c);               // 设置字体颜色

#endif // UTILS_H
