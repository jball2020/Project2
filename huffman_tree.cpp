/*
* Author: Jordan Ball
* Assignment: Project 2
* Class: CS3610
* Date: 2/25/2018
*
* Description: HuffmanTree class used to compress messages
*
*/

#include <iostream>
#include <string>
#include "huffman_tree.h"
#include "min_heap.h"
using namespace std;

void HuffmanTree::construct(const string message) {
  this->message = message;

  /* Count the frequency of each letter in message
  // e.g. 
  //    message == "aaabbccccdd"
  //    frequencies == {a:3, b:2, c:4, d:2} 
  */
  map<char, int> frequency_map;
  for (unsigned int i = 0; i < message.length(); ++i) {
    if (frequency_map.find(message[i]) != frequency_map.end())
      ++frequency_map[message[i]];
    else
      frequency_map[message[i]] = 1;
  }

  /* Create HuffmanNode for each unique letter in message
  // and organize nodes into a min heap
  // e.g.
  //  heap == 
  //            {b:2}  
  //           /     \
  //        {d:2}   {a:3}
  //        /   \   /    \
  //      {c:4} 
  */
  MinHeap<HuffmanNode*> heap;
  map<char, int>::iterator it = frequency_map.begin();
  for (; it != frequency_map.end(); ++it) {
    HuffmanNode* node = new HuffmanNode(
      it->first, it->second
    );
    heap.insert(node, it->second);
  }

  
  
  /* Combine nodes with smallest frequency and insert
  // back into heap until heap size == 1. Along the way,
  // create binary tree out of combined nodes.
  // e.g.
  //  (1)
  //     {b:2} == heap.extract_min()
  //     {d:2} == heap.extract_min()
  //     parent ==
  //               {*:4}
  //              /     \
  //            {b:2}  {d:2}
  //
  //     heap == 
  //              {a:3}
  //             /     \
  //           {c:4}   {*:4}
  //
  //  (2)
  //     {a:3} == heap.extract_min()
  //     {c:4} == heap.extract_min()
  //     parent ==
  //              {*:7}
  //             /     \
  //          {a:3}   {*:4}
  //    
  //     heap ==
  //            {c:4}
  //           /
  //         {*:7}
  //
  //  (3)
  //     {*:4} == heap.extract_min()
  //     {*:7} == heap.extract_min()
  //     parent ==
  //            {*:11}
  //           /       \
  //      {c:4}        {*:7}
  //                  /     \
  //                {a:3}  {*:4}
  //                       /    \
  //                    {b:2}  {d:2}
  //
  //     heap == {*:11}
  */
  while (heap.size() > 1) {
    HuffmanNode *left, *right;

    left = heap.extract_min();
    right = heap.extract_min();
	

    HuffmanNode *parent = new HuffmanNode(
      left->frequency + right->frequency
    );

    parent->left = left;
    parent->right = right;

    heap.insert(parent, parent->frequency);
  }

  // Get root of huffman tree. e.g. {*:11}
  this->root = heap.peek();
}

/**
* @brief Function that prints out the coded message
* @param none
*
* This function prints out the coded message by first calling buildcodes
* to build a map of the codes and their associated characters, then it
* iterates through the message string and outputs the appropriate code
* for each character
*
* @return void
*/
void HuffmanTree::print() const { // need to implement this function

	string msg = this->message;
	string code;
	map<char, string> codes;

	buildCodes(this->root, code, codes); //build the codes, and load them into the map

	string::iterator it; //iterate through the string and print out corresponding codes
	char ch;
	for (it = msg.begin(); it != msg.end(); it++) {
		ch = *it;
		cout << (codes.find(ch))->second << " ";
	}
}

/**
* @brief Function that recursively traverses through the huffman tree building codes an loading them into the map
* @param const HuffmanNode* current, the current node
* @param string &code, the code that is being built and changed
* @param map<char, string> &codes, the map of codes being loaded
*
* This function recursively traverses throught the huffman tree, appending a 0 to the code if it is moving left
* and a 1 to the code if it is traversing right. When it reaches a character, it loads the code and the character
* into the map. When it goes back up the tree, it erases the last digit in the string and continues to the right.
*
* @return bool, true if i has left child, false if not
*/
void HuffmanTree::buildCodes(const HuffmanNode* current, string &code, map<char, string> &codes) const{
	if (current->left) { //if it has left child, append a 0 and continue
		code.push_back('0');
		buildCodes(current->left, code, codes);
	}
	if (current->right) { //if it has a right child, append a 1 and continue
		code.push_back('1');
		buildCodes(current->right, code, codes);
	}
	if (current->right == NULL && current->left == NULL) { //if it has no children, load character and code into map
		codes.insert(pair<char, string>(current->character, code));
	}
	if (!code.empty()) { //going back up the tree
		code.erase(code.size() - 1);
	}
	
}
