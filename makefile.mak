#Author: Jordan Ball
#Made for: HuffmanTree project
#Date: 3/1/2018

CC = g++
CFLAGS = -Wall
HEADERS = "min_heap.h huffman_tree.h"

all: exe clean

exe: huffman_tree.o main.o
	$(CC) $(CFLAGS) -o exe huffman_tree.o main.o

huffman_tree.o: huffman_tree.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c huffman_tree.cpp

main.o: main.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c main.cpp

clean:
	rm -f *.o *~
