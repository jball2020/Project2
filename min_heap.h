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
  MinHeap() {}
  ~MinHeap() {}

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

  void print();

private:
  vector<HeapNode<T> > heap;

  void BubbleUp(int i);
  void BubbleDown(int i);
};
