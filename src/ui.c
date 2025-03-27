#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include "../include/snake.h"
#include "../include/food.h"
#include "../include/ui.h"
#include "../include/utils.h"

// 欢迎界面
void welcome() {
    int ret = 0;
    
    // 绘制LOGO
    color(2);
    printf("                                                                                         \n");
    printf("                       __________       ___                                              \n");
    printf("                      /          \\     / \\ \\    |____      __\\__                     \n");
    printf("                     /  ________  \\   / ___ \\  _/ __     | |   /                       \n");
    printf("                     |  |      |__|     _/_   |_|  /    [|] |/                           \n");
    printf("                     |  |              | | |      /     _|_ \\__/                        \n");
    printf("                     \\  \\_______        / \\      |___/        ____                    \n");
    printf("                      \\         \\    ____ ____      ____   __ |  |  ___   ______       \n");
    printf("                       \\_______  \\   |  |/    \\    /    \\_/ / |  | /  /  /      \\   \n");
    printf("                               \\  \\  |    ___  \\  / ____   /  |  |/  /  /  ____  \\   \n");
    printf("                     __        |  |  |   /   \\  \\ | |  |  /   |     /  |  /____\\  |   \n");
    printf("                    \\  \\_______|  |  |  |    |  | | |__|  |   |     \\  |  ________/   \n");
    printf("                     \\            /  |  |    |  |  \\       \\  |  |\\  \\  \\  \\____  \n");
    printf("                      \\__________/   |__|    |__|   \\___/\\__\\ |__| \\__\\  \\______/ \n");
    
    // 绘制标题
    int i, j = 1;
    gotoxy(43, 18);
    color(11);
    printf("贪 吃 蛇 游 戏");
    
    // 绘制菜单边框
    color(14);
    for (i = 20; i <= 26; i++) {
        for (j = 27; j <= 74; j++) {
            gotoxy(j, i);
            if (i == 20 || i == 26) {
                printf("-");
            } else if (j == 27 || j == 74) {
                printf("|");
            }
        }
    }
    
    // 菜单选项
    color(10);
    gotoxy(35, 22);
    printf("1.模式选择");
    gotoxy(55, 22);
    printf("2.新手教程");
    gotoxy(35, 24);
    printf("3.皮肤选择");
    gotoxy(55, 24);
    printf("4.退出程序");
    
    // 获取用户选择
    gotoxy(40, 27);
    color(3);
    printf("请选择[1 2 3 4]:[ ]\b\b");
    color(14);
    int n = _getch() - '0';
    system("cls");
    
    // 处理用户选择
    switch (n) {
    case 1:
        chosemode();
        ret = 1;
        break;
    case 2:
        newerteach();
        break;
    case 3:
        chosecolor();
        break;
    case 4:
        close();
        ret = 1;
    }
    
    // 如果没有选择模式，重新显示欢迎界面
    if (ret == 0) {
        welcome();
    }
}

// 退出游戏界面
void close() {
    // 绘制LOGO
    color(2);
    printf("                                                                                         \n");
    printf("                       __________       ___                                              \n");
    printf("                      /          \\     / \\ \\    |____      __\\__                     \n");
    printf("                     /  ________  \\   / ___ \\  _/ __     | |   /                       \n");
    printf("                     |  |      |__|     _/_   |_|  /    [|] |/                           \n");
    printf("                     |  |              | | |      /     _|_ \\__/                        \n");
    printf("                     \\  \\_______        / \\      |___/        ____                    \n");
    printf("                      \\         \\    ____ ____      ____   __ |  |  ___   ______       \n");
    printf("                       \\_______  \\   |  |/    \\    /    \\_/ / |  | /  /  /      \\   \n");
    printf("                               \\  \\  |    ___  \\  / ____   /  |  |/  /  /  ____  \\   \n");
    printf("                     __        |  |  |   /   \\  \\ | |  |  /   |     /  |  /____\\  |   \n");
    printf("                    \\  \\_______|  |  |  |    |  | | |__|  |   |     \\  |  ________/   \n");
    printf("                     \\            /  |  |    |  |  \\       \\  |  |\\  \\  \\  \\____  \n");
    printf("                      \\__________/   |__|    |__|   \\___/\\__\\ |__| \\__\\  \\______/ \n");
    
    // 绘制标题和边框
    int i, j = 1;
    gotoxy(43, 18);
    color(11);
    printf("贪 吃 蛇 游 戏");
    
    color(14);
    for (i = 20; i <= 26; i++) {
        for (j = 27; j <= 74; j++) {
            gotoxy(j, i);
            if (i == 20 || i == 26) {
                printf("-");
            } else if (j == 27 || j == 74) {
                printf("|");
            }
        }
    }
    
    // 显示谢谢信息并退出
    color(10);
    gotoxy(40, 23);
    printf(" 谢谢游玩！欢迎下次再来！");
    Sleep(1000);
    exit(1);
}

// 游戏结束界面
void Finish() {
    system("cls");
    
    // 绘制LOGO
    color(2);
    printf("                                                                                         \n");
    printf("                       __________       ___                                              \n");
    printf("                      /          \\     / \\ \\    |____      __\\__                     \n");
    printf("                     /  ________  \\   / ___ \\  _/ __     | |   /                       \n");
    printf("                     |  |      |__|     _/_   |_|  /    [|] |/                           \n");
    printf("                     |  |              | | |      /     _|_ \\__/                        \n");
    printf("                     \\  \\_______        / \\      |___/        ____                    \n");
    printf("                      \\         \\    ____ ____      ____   __ |  |  ___   ______       \n");
    printf("                       \\_______  \\   |  |/    \\    /    \\_/ / |  | /  /  /      \\   \n");
    printf("                               \\  \\  |    ___  \\  / ____   /  |  |/  /  /  ____  \\   \n");
    printf("                     __        |  |  |   /   \\  \\ | |  |  /   |     /  |  /____\\  |   \n");
    printf("                    \\  \\_______|  |  |  |    |  | | |__|  |   |     \\  |  ________/   \n");
    printf("                     \\            /  |  |    |  |  \\       \\  |  |\\  \\  \\  \\____  \n");
    printf("                      \\__________/   |__|    |__|   \\___/\\__\\ |__| \\__\\  \\______/ \n");
    
    // 绘制标题和边框
    int i, j = 1;
    gotoxy(43, 18);
    color(11);
    printf("贪 吃 蛇 游 戏");
    
    color(14);
    for (i = 20; i <= 26; i++) {
        for (j = 27; j <= 74; j++) {
            gotoxy(j, i);
            if (i == 20 || i == 26) {
                printf("-");
            } else if (j == 27 || j == 74) {
                printf("|");
            }
        }
    }
    
    // 显示最终分数
    color(10);
    gotoxy(35, 22);
    printf("Good Job！您最终的得分为：%d", score);
    gotoxy(35, 23);
    printf("感谢您的游玩，欢迎下次再来哦~");
    gotoxy(35, 24);
    color(14);
    
    // 释放蛇身链表内存
    snake* p = head, *q;
    while (p != NULL) {
        q = p->next;
        free(p);
        p = q;
    }
    
    system("pause");
}

// 选择游戏模式
void chosemode() {
    int i, j = 1;
    system("cls");
    color(15);
    gotoxy(44, 3);
    printf("模式选择");
    
    // 绘制边框
    color(2);
    for (i = 6; i <= 22; i++) {
        for (j = 20; j <= 76; j++) {
            gotoxy(j, i);
            if (i == 6 || i == 22) printf("=");
            else if (j == 20 || j == 75) printf("||");
        }
    }
    
    // 显示模式选项
    color(3);
    gotoxy(30, 8);
    printf("模式1: 经典模式");
    color(10);
    gotoxy(30, 11);
    printf("模式2: 闯关模式");
    color(14);
    gotoxy(30, 14);
    printf("模式3: 穿墙模式");
    
    // 获取用户选择
    color(2);
    gotoxy(30, 17);
    printf("请选择您的游戏模式：【 】\b\b");
    mode = _getch() - '0';
    system("cls");
}

// 选择操作方式
void chosekeystyle() {
    int i, j = 1;
    system("cls");
    color(2);
    gotoxy(44, 3);
    printf("操作方式选择");
    
    // 绘制边框
    for (i = 6; i <= 22; i++) {
        for (j = 20; j <= 76; j++) {
            gotoxy(j, i);
            if (i == 6 || i == 22) printf("=");
            else if (j == 20 || j == 75) printf("||");
        }
    }
    
    // 显示操作方式选项
    color(3);
    gotoxy(30, 8);
    printf("操作方式1：w a s d来控制蛇体上下左右移动");
    color(10);
    gotoxy(30, 11);
    printf("操作方式2：↑↓← →来控制蛇体上下左右移动");
    
    // 获取用户姓名
    color(3);
    gotoxy(30, 14);
    printf("请输入你的姓名：");
    gets_s(name, 20);
    
    // 获取用户操作方式选择
    color(2);
    gotoxy(30, 16);
    printf("请选择您的操作方式：【 】\b\b");
    keystyle = _getch() - '0';
    system("cls");
}

// 选择皮肤颜色
void chosecolor() {
    int i, j = 1;
    system("cls");
    color(15);
    gotoxy(44, 3);
    printf("皮肤选择");
    
    // 绘制边框
    color(2);
    for (i = 6; i <= 22; i++) {
        for (j = 20; j <= 76; j++) {
            gotoxy(j, i);
            if (i == 6 || i == 22) printf("=");
            else if (j == 20 || j == 75) printf("||");
        }
    }
    
    // 显示皮肤选项
    color(3);
    gotoxy(30, 8);
    printf("1.蓝色");
    color(10);
    gotoxy(30, 11);
    printf("2.绿色");
    color(14);
    gotoxy(30, 14);
    printf("3.黄色");
    
    // 获取用户选择
    color(2);
    gotoxy(30, 17);
    printf("请选择您的皮肤：【 】\b\b");
    if (_kbhit()) {
        switch (_getch() - '0') {
        case 1:
            skin = 3;
            break;
        case 2:
            skin = 10;
            break;
        case 3:
            skin = 14;
            break;
        }
    }
    system("cls");
}

// 新手教程界面
void newerteach() {
    int i, j = 1;
    system("cls");
    color(15);
    gotoxy(44, 3);
    printf("游戏说明");
    
    // 绘制边框
    color(2);
    for (i = 6; i <= 22; i++) {
        for (j = 20; j <= 76; j++) {
            gotoxy(j, i);
            if (i == 6 || i == 22) printf("=");
        }
    }
    
    // 显示游戏提示
    color(3);
    gotoxy(20, 8);
    printf("tip1: 不能撞墙，不能咬到自己");
    color(10);
    gotoxy(20, 11);
    printf("tip2: 用 w a s d 或者↑.↓.←.→控制蛇的移动");
    color(14);
    gotoxy(20, 14);
    printf("tip3: 在经典模式和穿墙模式下，长按方向键可进行加速");
    color(11);
    gotoxy(20, 17);
    printf("tip4: 在闯关模式下，会有障碍物，并随着分数增加速度提升");
    color(4);
    gotoxy(20, 20);
    printf("tip5: 按空格键暂停游戏，再按空格键继续");
    color(2);
    gotoxy(20, 23);
    printf("按任意键返回");
    
    // 等待用户按键返回
    while (1) {
        if (_kbhit()) {
            system("cls");
            return;
        }
    }
}

// 创建游戏地图和初始蛇
void creatgraph() {
    int i;
    
    // 绘制边框
    for (i = 0; i < 58; i += 2) {
        gotoprint(i, 0);
        gotoprint(i, 26);
    }
    for (i = 1; i < 26; i++) {
        gotoprint(0, i);
        gotoprint(56, i);
    }
    
    // 显示游戏信息
    gotoxy(63, 5);
    printf("你好啊 %s,欢迎来玩我的贪吃蛇游戏~", name);
    gotoxy(63, 15);
    printf("你目前的得分是:%d    =￣ω￣= ", score);
    gotoxy(63, 20);
    printf("温馨提示：按下空格键可暂停游戏，再次按空格继续游戏~");
    gotoxy(63, 25);
    printf("此游戏由 Gnonymous 所有");
    color(14);
    gotoxy(63, 7);
    printf("模式相关信息");
    
    // 根据模式显示对应信息
    switch (mode) {
    case 2:
        gotoxy(63, 10);
        color(14);
        printf("你目前所处的难度等级为 %s ,配速为%d", hard, speed);
        break;
    case 1:
        color(14);
        gotoxy(63, 10);
        printf("经典模式：长按可以加速哦~");
        break;
    case 3:
        color(14);
        gotoxy(63, 10);
        printf("穿墙模式：您不仅可以长按加速，还可以自由穿墙哦~");
        break;
    }
    
    // 初始化蛇的身体
    head = (snake*)malloc(sizeof(snake));
    snake* p = (snake*)malloc(sizeof(snake));
    snake* q = (snake*)malloc(sizeof(snake));
    
    // 设置蛇的初始位置
    head->x = 16;
    head->y = 15;
    head->next = p;
    
    // 为简单起见，这里没有设置p和q的坐标，实际游戏中应当设置
    p->next = q;
    q->next = NULL;
}
