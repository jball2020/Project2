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

  // Input: 
  //      data - User data.
  //      key  - Key value associated with user data.
  //             Use key to organize user data into min
  //             heap container.
  void insert(const T data, const int key);

  // Return: User data stored in HeapNode with minimum key value.
  T extract_min();

  // Return: User data stored in HeapNode with minimum key value.
  T peek() const;

  // Return: Size of the min heap.
  int size() const;

  //print function to help debugging
  //void print();

private:
  vector<HeapNode<T> > heap;

  //carries out the bubble up procedure when inserting
  void BubbleUp(int i);
  //carries out the bubble down procedure when extracting
  void BubbleDown(int i);
  //returns the index of the right child of i
  int Right(int i);
  //returns the index of the parent of i
  int Parent(int i);
  //returns the index of the left child of i
  int Left(int i);
  //returns true if i has a right child
  bool HasRight(int i);
  //returns true if i has a left child
  bool HasLeft(int i);
};

#include "min_heap.template"

#endif