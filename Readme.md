<p align="center">
  <img src="images/snake.svg" alt="Snake Game" width="180"/>
</p>

<h1 align="center">Simple-Snake</h1>

<p align="center">
  <b>🐍基于C的贪吃蛇小游戏 | Classic Snake Game in C</b>
</p>

<p align="center">
  <a href="#-项目简介">简介</a> •
  <a href="#-特色功能">特色功能</a> •
  <a href="#-项目结构">项目结构</a> •
  <a href="#-快速开始">快速开始</a> •
  <a href="#-游戏玩法">游戏玩法</a>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/license-MIT-white.svg" alt="License">
  <img src="https://img.shields.io/badge/language-C-blue.svg" alt="Language">
  <img src="https://img.shields.io/badge/platform-Windows-red.svg" alt="Platform">
  <img src="https://img.shields.io/github/issues/Gnonymous/Simple-Snake.svg" alt="Issues">
  <img src="https://img.shields.io/github/last-commit/Gnonymous/Simple-Snake.svg" alt="Last Commit">
</p>

<div align="center">
  <sub>Created with ❤︎ by
  <a href="https://github.com/Gnonymous">Gnonymous</a>
  </sub>
</div>

---

## 📝 项目简介

该项目是一个使用C语言实现的经典贪吃蛇游戏。通过链表数据结构表示蛇的身体，结合Windows系统函数实现了图形界面和用户交互。项目最初是我在中南大学大一时期的编程练习，后经过结构优化，更加易于理解和扩展。

> [!TIP]
> 这是一个很好的C语言数据结构与算法实践项目，特别适合初学者学习链表操作和游戏开发基础知识。

<div align="center">
  <img src="https://github.com/Gnonymous/Snake-for-programing-task-/assets/105557628/44578a44-c719-411c-9340-6996f7d45748" width="400"/>
</div>

## ✨ 特色功能

### 多种游戏模式
- **经典模式**：传统贪吃蛇玩法
- **闯关模式**：包含障碍物，难度随分数增加
- **穿墙模式**：蛇可以穿过墙壁继续游戏

### 操作方式选择
- 支持WASD键控制
- 支持方向键控制

### 个性化皮肤
- 蓝色、绿色、黄色多种皮肤选择

### 游戏机制
- 支持长按方向键加速（经典模式和穿墙模式）
- 空格键暂停/继续功能
- 闯关模式中随分数增加速度提升

## 🧩 项目结构

```
Simple-Snake/
├── include/              # 头文件目录
│   ├── snake.h           # 蛇相关结构和函数声明
│   ├── food.h            # 食物和障碍物相关
│   ├── ui.h              # 用户界面相关
│   └── utils.h           # 工具函数
├── src/                  # 源代码目录
│   ├── main.c            # 主程序入口
│   ├── snake.c           # 蛇的移动和碰撞检测
│   ├── food.c            # 食物生成和吃食物逻辑
│   ├── ui.c              # 界面显示和交互
│   └── utils.c           # 工具函数实现
└── Makefile              # 编译配置
```

## 🚀 快速开始

### 前置条件

- Windows操作系统
- GCC编译器（推荐MinGW）
- EasyX图形库（[下载地址](https://easyx.cn/)）

### 编译步骤

```bash
# 使用make编译（需要安装make工具）
make

# 或手动编译
gcc -o snake src/*.c -I include -lgraphics -lm
```

### 运行游戏

```bash
./snake
```

> [!NOTE]
> 首次运行前请确保已正确安装EasyX图形库，否则可能导致编译错误。

## 🎮 游戏玩法

<table>
  <tr>
    <td><b>1.</b> 启动游戏后，选择游戏模式、操作方式和皮肤</td>
    <td><b>2.</b> 使用选定的按键（WASD或方向键）控制蛇的移动</td>
  </tr>
  <tr>
    <td><b>3.</b> 吃到食物会增加蛇的长度和得分</td>
    <td><b>4.</b> 根据选择的模式，避免撞墙、碰到自己或障碍物</td>
  </tr>
  <tr>
    <td colspan="2"><b>5.</b> 按空格键可以随时暂停/继续游戏</td>
  </tr>
</table>

## License

> [!CAUTION]
>
> ⚠️该项目仅作学习交流使用，鼓励在此基础上进行二次开发更新，切勿因抄袭导致课程不及格！
>
> ⚠️The project is only for learning and communication use, encourage secondary development and update on the basis of again, do not plagiarism lead to course failure!
