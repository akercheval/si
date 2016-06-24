# Makefile for si (in c++)
CC=g++
CFLAGS=-g -Wall -std=c++11
NAME=si

all:
	$(CC) $(CFLAGS) si.cpp word.cpp -o $(NAME)

clean:
	rm $(NAME)