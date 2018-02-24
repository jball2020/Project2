#include "min_heap.h"
#include <algorithm>
#include <cstdlib>
#include <iostream>

using namespace std;

// Input: 
//      data - User data.
//      key  - Key value associated with user data.
//             Use key to organize user data into min
//             heap container.
template <typename T>
void MinHeap<T>::insert(const T data, const int key) {
	if (heap.empty()) {
		heap.push_back(NULL);
		heap.push_back(HeapNode<T>(data, key));
	}
	else {
		heap.push_back(HeapNode<T>(data, key));
		int pos = heap.size() - 1;
		BubbleUp(pos);
	}
}

// Return: User data stored in HeapNode with minimum key value.
template <typename T>
T MinHeap<T>::extract_min() {
	if (heap.empty()) {
		cout << "Empty Heap." << endl;
	}
	else {
		int i = heap.size() - 1;
		HeapNode<T> tmp = heap[1];
		heap[1] = heap[i];
		heap[i] = tmp;
		heap.pop_back();

		BubbleDown(1);
	}
}

// Return: User data stored in HeapNode with minimum key value.
template <typename T>
T MinHeap<T>::peek() const {
	if (heap.empty()) {
		cout << "Empty Heap." << endl;
	}
	else {
		return heap[1];
	}
}

// Return: Size of the min heap.
template <typename T>
int MinHeap<T>::size() const {
	return heap.size();
}

template<typename T>
void MinHeap<T>::BubbleUp(int i) {
	if (heap[i / 2] == NULL || heap[i / 2].key >= heap[i].key) {
		return; //base case
	}
	else {
		HeapNode<T> tmp = heap[i]; //swap
		heap[i] = heap[i / 2];
		heap[i / 2] = tmp;
		i = i / 2;

		BubbleUp(i); //recursive call
	}
}

template<typename T>
void MinHeap<T>::BubbleDown(int i) {
	if (heap[i].key < heap[2i].key && heap[i].key < heap[2i + 1].key) {
		return;
	}
	else {
		int j = heap[2i].key;
		int k = heap[2i + 1].key;
		int min = min(j, k);
		if (j == min) {
			HeapNode<T> tmp = heap[2i];
			heap[2i] = heap[i];
			heap[i] = tmp;

			BubbleDown(2i);
		}
		else {
			HeapNode<T> tmp = heap[2i+1];
			heap[2i+1] = heap[i];
			heap[i] = tmp;

			BubbleDown(2i + 1);
		}
	}
}

template<typename T>
void MinHeap<T>::print() {
	typedef HeapNode<T> heap_node
	vector<heap_node>::iterator it;
	for (it = heap.begin(); it != heap.end(); it++) {
		cout << (*it).data << " ";
	}
}