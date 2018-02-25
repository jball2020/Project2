#include <iostream>
#include <string>
#include "huffman_tree.h"
using namespace std;

int main(int argc, char** argv) {
  // Create a HuffmanTree object and read the input messages into the
  // HuffmanTree construct function. Next, print the encoded message.
  // Finally, destruct the huffman tree and move on to the next test case.

	int num_cases;
	cin >> num_cases;
	string message;
	for (int i = 1; i <= num_cases; i++) {
		HuffmanTree mytree;
		getline(cin, message);
		mytree.construct(message);
		cout << "Test Case : " << i << endl;
		mytree.print();
		cout << endl;
	}

}
