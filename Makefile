CC := g++
CXXFLAGS := --std=c++17 -Wall -Wextra -Werror -Og -g3 -fsanitize=address -fsanitize=undefined

bin/%: %.cpp bin
	$(CC) $(CXXFLAGS) $< -o $@

bin:
	mkdir -p bin
