CC := g++
TARGET := vector
FILES := *.cpp
CXXFLAGS := --std=c++17 -Wall -Wextra -Werror -Og -g3 -fsanitize=address -fsanitize=undefined

all: $(FILES)
	$(CC) $(CXXFLAGS) $^ -o $(TARGET)
