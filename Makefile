# 编译器设置
CC = g++
CFLAGS = -Wall -Wextra -Wimplicit-fallthrough=0
LDFLAGS =

# 目录设置
SRCDIR_T = T-level
SRCDIR_A = A-level
SRCDIR_B = B-level
SRCDIR_TEST = test
OBJDIR = obj
BINDIR = bin
INCDIR = include

# 源文件和目标文件
SRCS = $(wildcard $(SRCDIR_TEST)/*.cpp)
OBJS = $(SRCS:$(SRCDIR_TEST)/%.cpp=$(OBJDIR)/%.o)
TARGET = $(OBJS:$(OBJDIR)/%.o=$(BINDIR)/%)

# 默认目标
all: directories $(TARGET)

# 创建必要的目录
directories:
	@mkdir -p $(OBJDIR) $(BINDIR)

# 链接
$(BINDIR)/%: $(OBJDIR)/%.o
	$(CC) $(LDFLAGS) $< -o $@

# 编译
$(OBJDIR)/%.o: $(SRCDIR_TEST)/%.cpp
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

# 清理
clean:
	rm -rf $(OBJDIR) $(BINDIR)

# 伪目标
.PHONY: all clean directories
