#ifndef FOOD_H
#define FOOD_H

// 食物结构体
struct Food {
    int x;
    int y;
};

// 障碍物结构体
struct Hinder {
    int x;
    int y;
};

// 全局变量声明
extern struct Food food;
extern struct Hinder hinder[10];
extern int score;  // 分数

// 函数声明
void creatfood();     // 食物产生
void Eating();        // 蛇吃到东西后的操作
void creathinder();   // 设置障碍物

#endif // FOOD_H
