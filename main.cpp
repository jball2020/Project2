#include <iostream>
#include "huffman_tree.h"
using namespace std;

int main(int argc, char** argv) {
  // Create a HuffmanTree object and read the input messages into the
  // HuffmanTree construct function. Next, print the encoded message.
  // Finally, destruct the huffman tree and move on to the next test case.

	int num_cases;
	cin >> num_cases;
	string message;
	for (int i = num_cases; i > 0; i--) {
		HuffmanTree mytree;
		getline(cin, message);
		mytree.construct(message);
		mytree.print();
	}

}
