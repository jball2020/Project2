/*
* Author: Jordan Ball
* Assignment: Project 2
* Class: CS3610
* Date: 2/25/2018
*
* Description: MinHeap class that is templated to be used with any data type
*
*/

/*
Time Complexity of Building HuffmanTree:
	With MinHeap:
		-A minheap takes log n time to insert
		-if we have n characters, we have 2n-1 nodes in the huffman tree
		-Thus, building a HuffmanTree with a MinHeap = O(nlog(n))
	W/o MinHeap:
		-Searching for min element will take n^2 time
		-if we have n characters, we have 2n-1 nodes in the huffman tree
		-inserting into huffman tree will take log n
		-Thus, building a HuffmanTree without a MinHeap = o(n^2log(n))

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
