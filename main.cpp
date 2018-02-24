#include <iostream>
//#include "huffman_tree.h"
#include "min_heap.h"
#include <string>
using namespace std;

int main(int argc, char** argv) {
  // Create a HuffmanTree object and read the input messages into the
  // HuffmanTree construct function. Next, print the encoded message.
  // Finally, destruct the huffman tree and move on to the next test case.
	MinHeap<int> heap;
	heap.insert(3, 1);
	heap.insert(4, 2);
	heap.insert(5, 3);

	int i = heap.peek();
	cout << "min:" << i << endl;

	heap.print();

	return(0);
}
