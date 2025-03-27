CC = gcc
CFLAGS = -Wall -Wextra -I./include
LDFLAGS = -lgraphics -lm

# 源文件和目标文件
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# 源文件列表
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
TARGET = $(BIN_DIR)/snake.exe

# 创建必要的目录
$(shell mkdir -p $(OBJ_DIR) $(BIN_DIR))

# 默认目标
all: $(TARGET)

# 编译可执行文件
$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

# 编译目标文件
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# 清理生成的文件
clean:
	rm -rf $(OBJ_DIR)/* $(TARGET)

# 运行程序
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
