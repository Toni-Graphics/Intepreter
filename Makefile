# Compiler
CC = g++
CFLAGS = -Isrc/. -g

# Source files
SRCS = src/err.cpp src/expr.cpp src/lexer.cpp src/main.cpp src/parser.cpp src/runner.cpp src/token.cpp

OBJDIR = bin
OBJS = $(patsubst src/%.cpp,$(OBJDIR)/%.o,$(SRCS))

# Target executable
TARGET = bin/int.exe

all: $(TARGET) clean_objs

$(OBJDIR)/%.o: src/%.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/err.o: src/err.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	@$(CC) $(OBJS) -o $@

clean:
	@rm -f $(OBJS) $(TARGET)
	
clean_objs:
	@rm -f $(OBJS)