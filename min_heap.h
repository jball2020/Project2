/*
* Author: Jordan Ball
* Assignment: Project 2
* Class: CS3610
* Date: 2/25/2018
*
* Description: MinHeap class that is templated to be used with any data type
*
*/
#ifndef MINHEAPH
#define MINHEAPH

#include <vector>
using namespace std;

template <typename T>
struct HeapNode {
  HeapNode(const T data, const int key) : data(data), key(key) {}

  T data;
  int key;
};

template <typename T>
class MinHeap {
public:
  MinHeap(){}
  ~MinHeap(){}

  /**
  * @brief Insersts a new node into a heap
  * @param data - User data.
  * @param key  - Key value associated with user data.
  *				Use key to organize user data into min
  *				heap container.
  *
  * Adds a new node to the end of the heap and then bubbles it up
  * until it is in the right position. This algorithm stops when
  * the key value of the parent is less than or equal to the key value
  * of the inserted node
  *
  * @return Void
  */
  void insert(const T data, const int key);

  /**
  * @brief Extracts the min from the top of the heap and bubbles down the item that replaces it
  * @param None
  *
  * Swaps the last item in the heap with the first item in the heap (min) then deletes the min.
  * Then it bubbles the node at the top down to it's correct position. This algorithm stops bubbling down
  * when the child(ren) of the node that is bubbling down are greater than or equal to the node, or if the moving node,
  * in it's current position, has no child(ren)
  *
  * @return User data stored in HeapNode with minimum key value.
  */
  T extract_min();

  /**
  * @brief This function simply returns the minimum element in the heap
  * @param none
  *
  * @return User data stored in HeapNode with minimum key value.
  */
  T peek() const;

  /**
  * @brief This function simply returns the size of the heap
  * @param none
  *
  * @return int size of the heap
  */
  int size() const;

  //print function to help debugging
  //void print();

private:
  vector<HeapNode<T> > heap;

  /**
  * @brief Function that takes an index i and returns the index that is the right child of i
  * @param int i, an index of a vector
  *
  * @return int r, the right child of i
  */
  int Right(int i);

  /**
  * @brief Function that takes an index i and returns the index that is the parent of i
  * @param int i, an index of a vector
  *
  * @return int p, the parent of i
  */
  int Parent(int i);

  /**
  * @brief Function that takes an index i and returns the index that is the left child of i
  * @param int i, an index of a vector
  *
  * @return int l, the left child of i
  */
  int Left(int i);

  /**
  * @brief Function that returns true if index i of a vector has a right child and false otherwise
  * @param int i, an index of a vecotr
  *
  * @return bool, true if i has right child, false if not
  */
  bool HasRight(int i);

  /**
  * @brief Function that returns true if index i of a vector has a left child and false otherwise
  * @param int i, an index of a vecotr
  *
  * @return bool, true if i has left child, false if not
  */
  bool HasLeft(int i);
};

#include "min_heap.template"

#endif