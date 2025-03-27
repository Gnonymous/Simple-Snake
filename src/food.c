#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "../include/snake.h"
#include "../include/food.h"
#include "../include/ui.h"
#include "../include/utils.h"

// 创建食物
void creatfood() {
    bool flag = false;
    
    while (!flag) {
        flag = true;
        
        // 生成随机位置
        srand((int)time(NULL));
        food.y = rand() % (25 - 1 + 1) + 1;
        food.x = rand() % (54 - 2 + 1) + 2;
        
        // 确保x坐标为偶数（控制台字符比例为2:1）
        if (food.x % 2 != 0) {
            food.x = food.x + 1;
        }
        
        // 检查是否与障碍物重合
        if ((food.x == 10 && food.y == 5) || 
            (food.x == 14 && food.y == 8) || 
            (food.x == 25 && food.y == 7) || 
            (food.x == 30 && food.y == 15) || 
            (food.x == 34 && food.y == 20)) {
            flag = false;
            continue;
        }
        
        // 检查是否与蛇身重合
        snake* judge = head;
        while (judge != NULL) {
            if (food.x == judge->x && food.y == judge->y) {
                flag = false;
                break;
            }
            judge = judge->next;
        }
    }
    
    // 显示食物
    color(skin);
    gotoxy(food.x, food.y);
    printf("⊙");
}

// 创建障碍物
void creathinder() {
    gotoxy(10, 5);
    printf("■");
    gotoxy(14, 8);
    printf("■");
    gotoxy(26, 7);
    printf("■");
    gotoxy(30, 15);
    printf("■");
    gotoxy(34, 20);
    printf("■");
}

// 蛇吃到食物的处理
void Eating() {
    if (head->x == food.x && head->y == food.y) {
        // 创建新食物
        creatfood();
        
        // 在蛇尾添加新节点
        snake* _new = (snake*)malloc(sizeof(snake));
        snake* p = head;
        
        // 找到蛇尾
        while (p->next != NULL) {
            p = p->next;
        }
        
        // 添加新节点
        p->next = _new;
        _new->next = NULL;
        
        // 更新分数显示
        score += 10;
        gotoxy(77, 15);
        color(14);
        printf("%d", score);
        
        // 更新难度显示（仅限闯关模式）
        if (mode == 2) {
            color(14);
            gotoxy(86, 10);
            printf("%s", hard);
            gotoxy(96, 10);
            printf("%d", 200 - speed);
        }
    }
}
