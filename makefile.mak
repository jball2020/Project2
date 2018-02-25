##makefile for HuffmanTree project

all:
	g++ -Wall huffman_tree.cpp main.cpp

clean:
	rm -f *.o *~
