#Author: Jordan Ball
#Made for: HuffmanTree project
#Date: 3/1/2018

CC = g++
CFLAGS = -Wall

all: exe clean

exe: huffman_tree.o main.o
	$(CC) $(CFLAGS) huffman_tree.o main.o

huffman_tree.o: huffman_tree.cpp min_heap.h huffman_tree.h
	$(CC) $(CFLAGS) -c huffman_tree.cpp

main.o: main.cpp min_heap.h huffman_tree.h
	$(CC) $(CFLAGS) -c main.cpp

clean:
	rm -f *.o *~
