#ifndef MINMAXHEAP_H
#define MINMAXHEAP_H


#include <iostream>
#include <cmath>
using namespace std;

class MinMaxHeap
{
 
	public:
	int* minMaxHeap;
	int lastIndex;
	int maxSize;
	
	MinMaxHeap(int dataArray[], int m, int s);

	/*
	*@pre: Heap is not empty
	*@post: Builds heap from bottom-up
	*@return: none
	*/
	void buildHeap();

	/*
	*@pre: None
	*@post: Key was inserted into the heap
	*@return: none
	*/
	void insert(int key);

	/*
	*@pre: None
	*@post: None
	*@return: True if heap is empty, false otherwise
	*/
	bool isEmpty();

	/*
	*@pre: Heap is not empty
	*@post: Root of the heap has been removed
	*@return: None
	*/
	void deleteMin();

	/*
	*@pre: Heap is not empty
	*@post: Removes the largest element from the heap
	*@return: None
	*/
	void deleteMax();

	/*
	*@pre: Heap is not empty
	*@post: None
	*@return: None
	*/
	void levelOrder();

	/*
	*@pre: Heap at index exists
	*@post: Heapifies based on node at index
	*@return: None
	*/
	void heapify(int index);

	/*
	*@pre: Heap at index exists
	*@post: Compares/swaps a min node to its grandparent min node
	*@return: None
	*/
	void heapifyMin(int index);

	/*
	*@pre: Heap at index exists
	*@post: Compares/swaps a max node to its grandparent max node
	*@return: None
	*/
	void heapifyMax(int index);

	/*
	*@pre: Index x exists in heap
	*@post: None
	*@return: Index of parent of x
	*/
	int findParent(int x);

	/*
	*@pre: Index x exists in heap
	*@post: None
	*@return: Index of left child of x
	*/
	int findLeft(int x);

	/*
	*@pre: Index x exists in heap
	*@post: None
	*@return: Index of right child of x
	*/
	int findRight(int x);

	/*
	*@pre: Index x exists in heap
	*@post: None
	*@return: Index of the grandparent of x
	*/
	int findGP(int x);

	/*
	*@pre: Heap is not empty
	*@post: None
	*@return: Minimum value of the heap
	*/
	int findMin();

	/*
	*@pre: Heap is not empty
	*@post: None
	*@return: Maximum value of the heap
	*/
	int findMax();
};

#endif
