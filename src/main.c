#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <graphics.h>

#include "../include/snake.h"
#include "../include/food.h"
#include "../include/ui.h"
#include "../include/utils.h"

// 全局变量定义
snake* head = NULL;    // 蛇头指针  
char name[20] = {0};   // 用户名
int keystyle = 0;      // 操作方式
int mode;              // 游戏模式
DWORD t1 = 0, t2 = 0;  // 时间记录
int score = 0;         // 分数 
char hard[10] = "菜鸟";// 难度等级
char click = 1;        // 键盘按键
char dir = 0;          // 方向
int skin = 14;         // 皮肤颜色（默认黄色）
int speed_up = 0;      // 加速值
int speed = 160;       // 速度（延迟毫秒）
struct Food food;      // 食物
struct Hinder hinder[10]; // 障碍物

int main() {
    welcome();         // 欢迎界面
    chosekeystyle();   // 输入用户信息和选择操作方式
    creatgraph();      // 创建地图
    
    if (mode == 2) {   // 如果是闯关模式，创建障碍物
        color(4);
        creathinder();
    }
    
    creatfood();       // 生成食物
    
    // 开始游戏主循环
    ClickControl();
    
    return 0;
}
