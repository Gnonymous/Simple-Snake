#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <time.h>

#include "../include/snake.h"
#include "../include/food.h"
#include "../include/ui.h"
#include "../include/utils.h"

// 蛇的移动逻辑
void MovingBody() {
    int x = head->x, y = head->y;
    snake* p = head;
    
    // 找到蛇尾，清除旧尾部
    while (p->next != NULL) {
        p = p->next;
    }
    gotodelete(p->x, p->y);
    
    // 根据按键更新方向
    switch (click) {
    case 72:
    case 'w':
        if (dir != 's') dir = 'w';
        break;
    case 80:
    case 's':
        if (dir != 'w') dir = 's';
        break;
    case 75:
    case 'a':
        if (dir != 'd') dir = 'a';
        break;
    case 77:
    case 'd':
        if (dir != 'a') dir = 'd';
        break;
    default:
        break;
    }
    
    // 根据方向更新位置
    switch (dir) {
    case 'w':
        y -= 1;
        break;
    case 's':
        y += 1;
        break;
    case 'a':
        x -= 2;
        break;
    case 'd':
        x += 2;
        break;
    default:
        break;
    }
    
    // 更新蛇的坐标
    if (x != head->x || y != head->y) {
        ChangeBody(x, y);
    }
    
    // 显示蛇头
    p = head;
    color(skin);
    gotoprint(p->x, p->y);
    
    // 穿墙模式下重绘墙壁
    if (mode == 3) {
        int i;
        color(2);
        for (i = 0; i < 58; i += 2) {
            gotoprint(i, 0);
            gotoprint(i, 26);
        }
        for (i = 1; i < 26; i++) {
            gotoprint(0, i);
            gotoprint(56, i);
        }
    }

    // 根据模式调整速度
    switch (mode) {
    case 1:
    case 3:
        speed = 160;
        break;
    case 2:
        int count = score / 10;
        if (count >= 0 && count <= 5) {
            speed = 160;
        } else if (count > 5 && count <= 10) {
            speed = 110;
            strcpy(hard, "老手");
        } else if (count > 10 && count <= 20) {
            strcpy(hard, "大师");
            speed = 70;
        } else {
            strcpy(hard, "魔鬼");
            speed = 50;
        }
    }
    
    Sleep(speed + speed_up);
}

// 更新蛇体坐标
void ChangeBody(int x, int y) {
    snake* p = head;
    
    // 找到倒数第二个节点
    while (p->next->next != NULL) {
        p = p->next;
    }
    
    // 删除尾节点
    free(p->next);
    p->next = NULL;
    
    // 创建新的头节点
    snake* new_head = (snake*)malloc(sizeof(snake));
    new_head->x = x;
    new_head->y = y;
    new_head->next = head;
    head = new_head;
}

// 游戏结束判断
int Judge() {
    // 检查是否撞到障碍物（闯关模式）
    if (mode == 2) {
        if ((head->x == 10 && head->y == 5) || 
            (head->x == 14 && head->y == 8) || 
            (head->x == 26 && head->y == 7) || 
            (head->x == 30 && head->y == 15) || 
            (head->x == 34 && head->y == 20)) {
            Finish();
            return 0;
        }
    }
    
    // 检查是否撞墙（经典和闯关模式）
    if ((mode == 1 || mode == 2) && 
        (head->x == 0 || head->x == 56 || head->y == 0 || head->y == 26)) {
        Finish();
        return 0;
    }
    // 穿墙处理（穿墙模式）
    else if (head->x == 0 || head->x == 56 || head->y == 0 || head->y == 26) {
        switch (dir) {
        case 'w':
            head->y = 26;
            break;
        case 's':
            head->y = 0;
            break;
        case 'a':
            head->x = 56;
            break;
        case 'd':
            head->x = 0;
            break;
        }
    }
    
    // 检查是否撞到自己
    snake* p = head->next;
    while (p != NULL) {
        if (head->x == p->x && head->y == p->y) {
            Finish();
            return 0;
        }
        p = p->next;
    }
    
    return 1;
}

// 获取键盘输入并控制游戏逻辑
int ClickControl() {
    switch (mode) {
    // 经典模式和穿墙模式（支持加速）
    case 1:
    case 3:
        while (1) {
            if (Judge() == 0) return 0;
            
            t1 = GetTickCount();
            
            // 处理键盘输入
            if (keystyle == 2 && _kbhit()) {
                t1 = GetTickCount();
                _getch();
                click = _getch();
                t2 = t1;
            } else if (keystyle == 1 && _kbhit()) {
                t1 = GetTickCount();
                click = _getch();
                t2 = t1;
            }
            
            // 判断是否加速
            if (t1 - t2 < 50) {
                speed_up = -80;
            } else {
                speed_up = 0;
            }
            
            // 移动蛇并检查是否吃到食物
            MovingBody();
            Eating();
        }
        break;
        
    // 闯关模式（不支持加速）
    case 2:
        while (1) {
            if (Judge() == 0) return 0;
            
            // 处理键盘输入
            if (keystyle == 2 && _kbhit()) {
                _getch();
                click = _getch();
            } else if (keystyle == 1 && _kbhit()) {
                click = _getch();
            }
            
            speed_up = 0;
            MovingBody();
            Eating();
        }
        break;
    }
    
    return 0;
}
