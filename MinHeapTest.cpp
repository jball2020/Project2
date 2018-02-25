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
	heap.insert("Hello,", 1);
	heap.insert("my", 2);
	heap.insert("name", 3);
	heap.insert("is", 4);
	heap.insert("Jordan", 5);
	heap.insert("Ball", 6);

	string i = heap.peek();
	cout << "min:" << i << endl;

	heap.print();
	cout << endl;

	string e_i = heap.extract_min();
	cout << "emin: " << e_i << endl;

	heap.print();
	cout << endl;


	return(0);
}