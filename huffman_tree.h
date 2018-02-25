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
  void print() const;

private:

  HuffmanNode *root;
  string message;
  void buildCodes(const HuffmanNode* current, string &code, map<char, string> &codes) const;
};

#endif
