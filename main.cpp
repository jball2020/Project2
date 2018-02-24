#include <iostream>
//#include "huffman_tree.h"
#include "min_heap.h"
#include <string>
using namespace std;

int main(int argc, char** argv) {
  // Create a HuffmanTree object and read the input messages into the
  // HuffmanTree construct function. Next, print the encoded message.
  // Finally, destruct the huffman tree and move on to the next test case.
	MinHeap<string> heap;
	heap.insert("Hello", 1);
	heap.insert("My", 2);
	heap.insert("name", 3);

	heap.print();

	return(0);
}
