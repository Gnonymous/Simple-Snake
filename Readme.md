# 贪吃蛇程序开源项目

> [!NOTE]
>
> 先将就看吧，目前还没有时间整理，大一时候的代码了，全都打包在一个C文件内，没有结构，但好在开箱即用！

## 简介

**此项目完全使用C语言实现，具体结构体运用*链表*结构，其中很多巧妙功能的实现都是基于此结合特定*系统函数*实现**

**此项目开源共大家学习使用，希望大家可以pr其中的游戏功能pr，或者issues有时间都会回复。**

## 游戏截图
![image](https://github.com/Gnonymous/Snake-for-programing-task-/assets/105557628/38a81ab7-d28f-47a2-bb23-194301389a5c)
![image](https://github.com/Gnonymous/Snake-for-programing-task-/assets/105557628/44578a44-c719-411c-9340-6996f7d45748)



## 代码部分

```c
#include<stdio.h>                    //主函数的库
#include<string.h>                  //处理字符串的库
#include<windows.h>            //计算机交互操作函数库 
#include<time.h>                    //获取和处理时间日期的函数库
#include<conio.h>                  //关于键盘操作的相关函数库
#include<graphics.h>            //easyx图形库

/***************************运用到的自定义函数**************************/

void welcome();                                   // 开始界面
void Finish();                                       // 结束界面
void close();                                           //退出游戏界面
void chosemode();                                //选择模式页面
void chosekeystyle();                               //选择操作方式页面
void chosecolor();                                  //选择皮肤界面
void newerteach();                                  //新手教程界面
void creatgraph();                               // 围墙打印
void creathinder();                             //设置障碍物
void gotoxy(int x, int y);                     // 光标跳转，横为X 0,1,2..               //没有解决gotoxy函数的具体原理
void gotoprint(int x, int y);                 // 跳转打印
void gotodelete(int x, int y);              // 跳转删除
int color(int c);                                       //设置字体颜色
void creatfood();                                // 食物产生
int ClickControl();                               // 获取键盘信号
int Judge();                                         // 游戏结束判断
void MovingBody();                         // 蛇的移动 
void Eating();                                    // 蛇吃到东西后的操作（伸长）
void ChangeBody(int x, int y);       // 蛇的坐标变换

/****************************对于蛇、食物、障碍物的定义*******************************/

typedef struct Snakes
{
    int x;
    int y;                                  //（用链表来实现??的移动）
    struct Snakes* next;
}snake;

struct Food
{
    int x;
    int y;
}food;

struct Hinder {
    int x;
    int y;
}hinder[10];

/*******************************全局运用到的全局变量声明*****************************/

snake* head;    // 声明蛇头指针  
char name[20];  // 保存用户名 有兴趣可以制作登录系统        （如何制作登录系统）
int  keystyle = 0;    //记录用户选择的方向控制按键模式
int mode;          //用来选择游戏模式
DWORD t1, t2 = 0;//记录时间，用来优化长按加速算法
int score;  // 分数 
char hard[10] = "菜鸟";//难度等级
char click = 1; // 记录敲下的键盘按键 
char dir;       //记录方向，统一出口
int skin = 14;        //用来换皮肤 默认黄色
int speed_up;//用来调整加速的多少
int speed;      // 速度 其实是延迟的毫秒数 （因为我们只能通过计算机的延迟效果来达到蛇体仿佛在移动的现象）

/************************************************************/

int main()
{
    welcome();                          // 欢迎界面 
    chosekeystyle();                //输入用户信息和键盘操作方式
    creatgraph();                      // 创建地图 
    if (mode == 2)
    {
        color(4);
        creathinder();
    }
    creatfood();                         // 新建食物 
    // 捕获鼠标按键 ClickControl
    if (ClickControl() == 0) return 0;
    return 0;
}

/**********************交互界面************************************/
void welcome()
{
    int ret = 0;
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
    int i, j = 1;
    int n;
    gotoxy(43, 18);
    color(11);
    printf("贪 吃 蛇 游 戏");
    color(14);          			//黄色边框
    for (i = 20; i <= 26; i++)   	//输出上下边框┅
    {
        for (j = 27; j <= 74; j++)  //输出左右边框┇
        {
            gotoxy(j, i);
            if (i == 20 || i == 26)
            {
                printf("-");
            }
            else if (j == 27 || j == 74)
            {
                printf("|");
            }
        }
    }
    color(10);
    gotoxy(35, 22);
    printf("1.模式选择");
    gotoxy(55, 22);
    printf("2.新手教程");
    gotoxy(35, 24);
    printf("3.皮肤选择");           //您希望用什么颜色的皮肤
    gotoxy(55, 24);
    printf("4.退出程序");
    gotoxy(40, 27);
    color(3);
    printf("请选择[1 2 3 4]:[ ]\b\b");        //\b为退格，使得光标处于[]中间
    color(14);
    n = _getch() - '0';
    system("cls");
    switch (n)
    {
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
    if (ret == 0)
    {
        welcome();
    }
}

void close()
{
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
    int i, j = 1;
    int n;
    gotoxy(43, 18);
    color(11);
    printf("贪 吃 蛇 游 戏");
    color(14);          			//黄色边框
    for (i = 20; i <= 26; i++)   	//输出上下边框┅
    {
        for (j = 27; j <= 74; j++)  //输出左右边框┇
        {
            gotoxy(j, i);
            if (i == 20 || i == 26)
            {
                printf("-");
            }
            else if (j == 27 || j == 74)
            {
                printf("|");
            }
        }
    }
    color(10);
    gotoxy(40, 23);
    printf(" 谢谢游玩！欢迎下次再来！");
    Sleep(1000);
    exit(1);
}

void Finish()
{
    system("cls");
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
    int i, j = 1;
    int n;
    gotoxy(43, 18);
    color(11);
    printf("贪 吃 蛇 游 戏");
    color(14);          			//黄色边框
    for (i = 20; i <= 26; i++)   	//输出上下边框┅
    {
        for (j = 27; j <= 74; j++)  //输出左右边框┇
        {
            gotoxy(j, i);
            if (i == 20 || i == 26)
            {
                printf("-");
            }
            else if (j == 27 || j == 74)
            {
                printf("|");
            }
        }
    }
    color(10);
    gotoxy(35, 22);
    printf("God Job！您最终的得分为：%d", score);
    gotoxy(35, 23);
    printf("感谢您的游玩，欢迎下次再来哦~");
    gotoxy(35, 24);
    color(14);
    // 释放空间 
    snake* p = head, * q;
    while (p != NULL) {
        q = p->next;
        free(p);
        p = q;
    }
    system("pause");
    /*这里可以再设置重新游戏或者再次选择其他难度的操作*/
}

void chosemode()
{
    int i, j = 1;
    system("cls");
    color(15);
    gotoxy(44, 3);
    printf("模式选择");
    color(2);
    for (i = 6; i <= 22; i++)   //输出上下边框===
    {
        for (j = 20; j <= 76; j++)  //输出左右边框||
        {
            gotoxy(j, i);
            if (i == 6 || i == 22) printf("=");
            else if (j == 20 || j == 75) printf("||");
        }
    }
    color(3);
    gotoxy(30, 8);
    printf("模式1: 经典模式");
    color(10);
    gotoxy(30, 11);
    printf("模式2: 闯关模式");
    color(14);
    gotoxy(30, 14);
    printf("模式3: 穿墙模式");
    color(2);
    gotoxy(30, 17);
    printf("请选择您的游戏模式：【 】\b\b");
    mode = _getch() - '0';
    system("cls");
}

void chosekeystyle()
{
    int i, j = 1;
    system("cls");
    color(2);
    gotoxy(44, 3);
    printf("操作方式选择");
    color(2);
    for (i = 6; i <= 22; i++)   //输出上下边框===
    {
        for (j = 20; j <= 76; j++)  //输出左右边框||
        {
            gotoxy(j, i);
            if (i == 6 || i == 22) printf("=");
            else if (j == 20 || j == 75) printf("||");
        }
    }
    color(3);
    gotoxy(30, 8);
    printf("操作方式1：w a s d来控制蛇体上下左右移动");
    color(10);
    gotoxy(30, 11);
    printf("操作方式2：↑↓← →来控制蛇体上下左右移动");
    color(3);
    gotoxy(30, 14);
    printf("请输入你的姓名：");
    gets_s(name);
    color(2);
    gotoxy(30, 16);
    printf("请选择您的操作方式：【 】\b\b");
    keystyle = _getch() - '0';
    system("cls");
}

void newerteach()
{
    int i, j = 1;
    system("cls");
    color(15);
    gotoxy(44, 3);
    printf("游戏说明");
    color(2);
    for (i = 6; i <= 22; i++)   //输出上下边框===
    {
        for (j = 20; j <= 76; j++)  //输出左右边框||
        {
            gotoxy(j, i);
            if (i == 6 || i == 22) printf("=");
            /* else if (j == 20 || j == 75) printf("||");*/
        }
    }
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
    printf("tip4: 在闯关模式下，会有随机的障碍物出现，并随着分数的增加速度不断增加，难度不断加大");
    color(4);
    gotoxy(20, 20);
    printf("tip5:按空格键暂停游戏，再按空格键继续");
    color(2);
    gotoxy(20, 23);
    printf("按 ESC 退出程序");
    while (1)
    {
        if (_kbhit())
        {
            system("cls");
            return;
        }
    }
}

void chosecolor()
{
    int i, j = 1;
    system("cls");
    color(15);
    gotoxy(44, 3);
    printf("皮肤选择");
    color(2);
    for (i = 6; i <= 22; i++)   //输出上下边框===
    {
        for (j = 20; j <= 76; j++)  //输出左右边框||
        {
            gotoxy(j, i);
            if (i == 6 || i == 22) printf("=");
            else if (j == 20 || j == 75) printf("||");
        }
    }
    color(3);
    gotoxy(30, 8);
    printf("1.蓝色");
    color(10);
    gotoxy(30, 11);
    printf("2.绿色");
    color(14);
    gotoxy(30, 14);
    printf("3.黄色");
    color(2);
    gotoxy(30, 17);
    printf("请选择您的皮肤：【 】\b\b");
    if (_kbhit)
    {
        switch (_getch() - '0')
        {
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

/*************************图形界面*********************************/
void creatgraph() {
    int i;
    /*
    注意这里横坐标是每次+2 因为控制台字符宽高比为1：2                 强调一下一开始认为就是简单的正方形导致图形错乱
    */
    for (i = 0; i < 58; i += 2)
    {
        gotoprint(i, 0);                //打印方块图形■
        gotoprint(i, 26);
    }
    for (i = 1; i < 26; i++)
    {
        gotoprint(0, i);
        gotoprint(56, i);
    }
    gotoxy(63, 5);                                                            //设计图形界面计分板用户信息等
    printf("你好啊 %s,欢迎来玩我的贪吃蛇游戏~", name);
    gotoxy(63, 15);
    printf("你目前的得分是:%d    =￣ω￣= ", score);          //涉及到一个分数刷新的问题
    gotoxy(63, 20);
    printf("温馨提示：按下空格键可暂停游戏，再次按空格继续游戏~");
    gotoxy(63, 25);
    printf("此游戏由 Gnonymous 所有");
    color(14);
    gotoxy(63, 7);
    printf("模式相关信息");
    switch (mode)
    {
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
    /**************************************************************/
    head = (snake*)malloc(sizeof(snake));
    snake* p = (snake*)malloc(sizeof(snake));
    snake* q = (snake*)malloc(sizeof(snake));
    head->x = 16;       //自定义蛇头的位置
    head->y = 15;
    head->next = p;
    p->next = q;
    q->next = NULL;                 //完整创建了一个链表
}



/**********************内部程序操作函数************************************/
int color(int c)
{
    //SetConsoleTextAttribute是API设置控制台窗口字体颜色和背景色的函数
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);        //更改文字颜色
    return 0;
}

void gotoxy(int x, int y)
{
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

/**********************************************************/
void gotoprint(int x, int y)
{
    gotoxy(x, y);
    printf("■");
}

/**********************************************************/
void gotodelete(int x, int y)
{
    gotoxy(x, y);
    printf("  ");             //通过打印空格的方式消除尾部
}

/**********************************************************/
void creatfood()

/*注意事项：
1.最基础的是食物要随机（而且打印的位置要在地图内部）
2.食物不能与蛇体本身重合
3.在调试的过程中发现，要将食物打印出来要注意食物的横坐标要为偶数（控制台字符比例）
*/
{
    // 随机产生一个食物 
    bool flag = false;
    while (!flag)
    {
        flag = true;
        srand((int)time(NULL));
        food.y = rand() % (25 - 1 + 1) + 1;                     //用%来限制了随机数的范围，并且该范围不能包括打印的图形边界
        food.x = rand() % (54 - 2 + 1) + 2;                     //控制台的长宽比例为2：1

        if (food.x % 2 != 0)                                                //一定要控制在控制台上显示的任何东西x都要是偶数，因为控制台字符比例为2：1
        {
            food.x = food.x + 1;
        }
        snake* judge = head;
        if ((food.x == 10 && food.y == 5) || (food.x == 14 && food.y == 8) || (food.x == 25 && food.y == 7) || (food.x == 30 && food.y == 15) || (food.x == 34 && food.y == 20))
        {
            flag = false;
        }
        while (1)                                                                   //遍历排除食物与蛇身重合
        {
            if (judge->next == NULL) break;
            if (food.x == judge->x && food.y == judge->y)
            {
                flag = false;
                break;
            }
            judge = judge->next;
        }
    }
    color(skin);
    gotoxy(food.x, food.y);
    printf("⊙");
}

/************************************************************************************/
void creathinder()
{
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

/*******************************游戏关键算法函数**********************************/

// 捕获按键 游戏主循环 
int ClickControl()
{
    char c;
    switch (mode)
    {
    case 1:         //经典模式和穿墙模式均有加速按钮设置
    case 3:
        while (1)
        {
            if (Judge() == 0)            return 0;                           //游戏结束的出口
            t1 = GetTickCount();
            if (keystyle == 2 && _kbhit())                                                    //检测是否有键盘输入
            {
                t1 = GetTickCount();
                _getch();                           //区分与getchar的区别，_getch()函数不用按下回车键代码会继续自动向下运行，这对我们人机交互和游戏体验都有大幅度的提升
                click = _getch();
                t2 = t1;
            }
            else if (keystyle == 1 && _kbhit())
            {
                t1 = GetTickCount();
                click = _getch();
                t2 = t1;
            }

            //已经获取完毕按键                                              //通过记录相邻两次按键的间隔时间判断是否加速
            if (t1 - t2 < 50)
            {
                speed_up = -80;
                MovingBody();
                Eating();
            }
            else
            {
                speed_up = 0;
                MovingBody();
                Eating();
            }
        }
        break;
    case 2:                         //闯关模式，没有加速按键
        while (1)
        {
            if (Judge() == 0)            return 0;                           //游戏结束的出口
            if (keystyle == 2 && _kbhit())                                                    //检测是否有键盘输入
            {
                _getch();                           //区分与getchar的区别，_getch()函数不用按下回车键代码会继续自动向下运行，这对我们人机交互和游戏体验都有大幅度的提升
                click = _getch();
            }
            else if (keystyle == 1 && _kbhit())
            {
                click = _getch();
            }
            speed_up = 0;
            MovingBody();
            Eating();
        }
        break;
    }
}



/**********************************************************/
void MovingBody() {
    int x = head->x, y = head->y;
    snake* p = head;
    // 通过先清空后打印实现动画效果           如果清空全部屏幕的话游戏体验不佳
    while (p->next != NULL) {
        p = p->next;                    //找到了链表的尾部
    }
    gotodelete(p->x, p->y);         // 消除尾节点    这时候尾巴的图标已经被删除了
    switch (click)
    {
    case 72:
    case 'w':
        if (dir != 's') dir = 'w';
        break;
    case 80:
    case's':
        if (dir != 'w')    dir = 's';
        break;
    case 75:
    case 'a':
        if (dir != 'd')    dir = 'a';
        break;
    case 77:
    case 'd':
        if (dir != 'a')    dir = 'd';
        break;
    default:
        break;
    }
    switch (dir)
    {
    case  'w':
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
    //x是下一个的位置，head-》x是目前蛇头的位置
    if (x != head->x || y != head->y) {
        //游戏最初的时候要打印出蛇头的位置，所以要有 这个 if 的判断
        // 改变坐标时更新 暂停游戏停止更新蛇 
        ChangeBody(x, y);
    }
    p = head;           //此时的head已经是下一个位置的蛇头
    // 打印蛇头
    color(skin);
    gotoprint(p->x, p->y);
    if (mode == 3)
    {
        int i;
        color(2);
        for (i = 0; i < 58; i += 2)
        {
            gotoprint(i, 0);                //打印方块图形■
            gotoprint(i, 26);
        }
        for (i = 1; i < 26; i++)
        {
            gotoprint(0, i);
            gotoprint(56, i);
        }
    }



    /*********************************************************************************************/
    // 蛇速度控制                                                可以通过调节来设置不同的难度

    switch (mode)
    {
    case 1:
    case 3:
        speed = 160;
        break;
    case 2:
        int count = score / 10;
        if (count >= 0 && count <= 5) speed = 160;
        else if (count > 5 && count <= 10)
        {
            speed = 110;
            sprintf_s(hard, "老手");
        }
        else if (count > 10 && count <= 20)
        {
            sprintf_s(hard, "大师");
            speed = 70;
        }
        else
        {
            sprintf_s(hard, "魔鬼");
            speed = 50;
        }
    }
    Sleep(speed + speed_up);           //真正控制速度的方式在于sleep的时间
}

/**********************************************************/
// 吃到食物处理 添加一个尾巴 
void Eating()
{
    if (head->x == food.x && head->y == food.y)     //判断已经吃到食物
    {
        creatfood();
        snake* _new = (snake*)malloc(sizeof(snake));        //新增身体的“结构体”
        snake* p;
        p = head;
        /*当??吃到食物的时候，我们会在尾部再去添加一个??的身体*/
        while (1)
        {
            if (p->next == NULL) break;
            p = p->next;
        }           //先找到链表的尾部，也就是蛇的尾巴
        p->next = _new;
        _new->next = NULL;      //完成链表的封装工作


        /******************刷新得分和难度等级和速度********************/
        score += 10;                //实现分数刷新的原理就是重新打印
        gotoxy(77, 15);
        color(14);
        printf("%d", score);
        if (mode == 2)
        {
            color(14);
            gotoxy(86, 10);
            printf("%s", hard);
            gotoxy(96, 10);
            printf("%d", 200 - speed);
        }
    }
}

/**********************************************************/
// 更新蛇体坐标 只需要消除尾结点 然后把新坐标结点置为头结点即可 
void ChangeBody(int x, int y)
{
    snake* p = head;
    while (p->next->next != NULL)       //找到倒数第二个节点，现在p是倒数第二个节点的蛇体结构体
    {
        p = p->next;
    }
    free(p->next);                                     //删除掉蛇尾的结构体
    p->next = NULL;                              //使倒数第二个节点成为链表的尾节点
    snake* new_head = (snake*)malloc(sizeof(snake));            //生成新的蛇头，确定舌头的位置，并且让他和初始的蛇头连接起来
    new_head->x = x;
    new_head->y = y;
    new_head->next = head;
    head = new_head;                                //让蛇头成为真正的蛇头
}

/**********************************************************/
// 判断是否游戏结束 
int Judge()
{
    if (mode == 2)
    {
        if ((head->x == 10 && head->y == 5) || (head->x == 14 && head->y == 8) || (head->x == 26 && head->y == 7) || (head->x == 30 && head->y == 15) || (head->x == 34 && head->y == 20))
        {
            Finish();
            return 0;
        }
    }
    if ((mode == 1 || mode == 2) && (head->x == 0 || head->x == 56 || head->y == 0 || head->y == 26))             //碰到墙壁的结束条件
    {
        Finish();
        return 0;
    }
    else if (head->x == 0 || head->x == 56 || head->y == 0 || head->y == 26)
    {
        switch (dir)
        {
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
    snake* p = head->next;
    while (1)                                                   //循环遍历蛇身，都要判断一遍是不是蛇头碰到了身体
    {
        if (p == NULL) break;
        if (head->x == p->x && head->y == p->y)                                 //蛇头碰到身体的结束条件
        {
            Finish();
            return 0;
        }
        p = p->next;
    }
    return 1;
}
```
