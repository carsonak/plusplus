TARGET := bin/vector
FILES := *.cpp
CC := g++
CXXFLAGS := --std=c++17 -Wall -Wextra -Werror -Og -g3 -MMD -fsanitize=address -fsanitize=undefined

$(TARGET): $(FILES) bin
	$(CC) $(CXXFLAGS) $(FILES) -o $@

bin:
	mkdir -p bin
