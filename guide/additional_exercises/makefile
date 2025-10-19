CC=g++
CFLAGS=-g -std=c++20 -Wall -Wextra -Wpedantic -Werror

.PHONY: clean

all: LLL.out BST.out

LLL.out: exercises_LLL.cpp
	$(CC) $(CFLAGS) -o $@ $^

BST.out: exercises_BST.cpp
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f *.out *.o
