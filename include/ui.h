#ifndef UI_H
#define UI_H

// 全局变量声明
extern char name[20];    // 用户名
extern int keystyle;     // 操作方式
extern int mode;         // 游戏模式
extern char hard[10];    // 难度等级
extern int skin;         // 皮肤颜色

// 函数声明
void welcome();         // 开始界面
void Finish();          // 结束界面
void close();           // 退出游戏界面
void chosemode();       // 选择模式页面
void chosekeystyle();   // 选择操作方式页面
void chosecolor();      // 选择皮肤界面
void newerteach();      // 新手教程界面
void creatgraph();      // 围墙打印

#endif // UI_H
