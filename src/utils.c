#include <stdio.h>
#include <windows.h>

#include "../include/utils.h"

// 设置控制台文字颜色
int color(int c) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
    return 0;
}

// 移动光标到指定位置
void gotoxy(int x, int y) {
    // 更新光标位置
    COORD pos;
    HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(hOutput, pos);
    
    // 隐藏光标
    CONSOLE_CURSOR_INFO cursor;
    cursor.bVisible = FALSE;
    cursor.dwSize = sizeof(cursor);
    SetConsoleCursorInfo(hOutput, &cursor);
}

// 在指定位置打印方块图形
void gotoprint(int x, int y) {
    gotoxy(x, y);
    printf("■");
}

// 在指定位置打印空格（删除效果）
void gotodelete(int x, int y) {
    gotoxy(x, y);
    printf("  ");
}
