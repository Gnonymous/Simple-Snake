#ifndef SNAKE_H
#define SNAKE_H

#include <stdbool.h>

// 蛇的结构体定义
typedef struct Snakes {
    int x;
    int y;
    struct Snakes* next;
} snake;

// 全局变量声明
extern snake* head;      // 蛇头指针  
extern char dir;         // 记录方向
extern char click;       // 记录按键
extern int speed;        // 速度（延迟毫秒数）
extern int speed_up;     // 加速值

// 函数声明
void MovingBody();                 // 蛇的移动 
void ChangeBody(int x, int y);     // 蛇的坐标变换
int Judge();                       // 游戏结束判断
int ClickControl();                // 获取键盘信号

#endif // SNAKE_H
