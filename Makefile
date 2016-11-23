# Makefile for si (in c++)
CC=g++
CFLAGS=-g -Wall -std=c++11

all:
		$(CC) $(CFLAGS) si.cpp word.cpp -o si
		$(CC) $(CFLAGS) is.cpp word.cpp -o is

si:
		$(CC) $(CFLAGS) si.cpp word.cpp -o si

is:
		$(CC) $(CFLAGS) is.cpp word.cpp -o is

clean:
	rm si is
