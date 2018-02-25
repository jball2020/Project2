/*
* Author: Jordan Ball
* Assignment: Project 2
* Class: CS3610
* Date: 2/25/2018
*
* Description: MinHeap class that is templated to be used with any data type
*
*/

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
	cin.ignore();
	string message = "";
	for (int i = 1; i <= num_cases; i++) {
		HuffmanTree mytree;
		getline(cin, message, '\n');
		mytree.construct(message);
		cout << "Test Case : " << i << endl;
		mytree.print();
		cout << endl;
		mytree.destruct();
	}

}
