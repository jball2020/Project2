/*
* Author: Jordan Ball
* Assignment: Project 2
* Class: CS3610
* Date: 2/25/2018
*
* Description: HuffmanTree class used to compress messages
*
*/

#ifndef HUFFMAN_TREE_H
#define HUFFMAN_TREE_H

#include <string>
#include <map>
using namespace std;

struct HuffmanNode {
  HuffmanNode(char character, int frequency) : 
    character(character), frequency(frequency), 
    left(NULL), right(NULL) {}

  HuffmanNode(int frequency) : 
    character('*'), frequency(frequency), 
    left(NULL), right(NULL) {}

  ~HuffmanNode() {
    delete left;
    delete right;
    left = right = NULL;
  }
  
  char character;
  int frequency;
  HuffmanNode *left, *right;
};

class HuffmanTree {
public:
  HuffmanTree() : root(NULL), message("") {}
  ~HuffmanTree() {delete this->root;}

  void construct(const string message);
  void destruct() {delete this->root; this->root=NULL; message="";}

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
  void print() const;

private:

  HuffmanNode *root;
  string message;

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
  void buildCodes(const HuffmanNode* current, string &code, map<char, string> &codes) const;
};

#endif
