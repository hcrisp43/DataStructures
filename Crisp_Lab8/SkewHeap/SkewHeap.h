#ifndef SKEWHEAP_H
#define SKEWHEAP_H
#include "Node.h"
#include <iostream>
using namespace std;

class SkewHeap
{
	public:


	Node* root;
	SkewHeap();
	~SkewHeap();

	/*
	*@pre: none
	*@post: none
	*@return: Returns true if root is nullptr, false otherwise
	*/
	bool isEmpty();

	/*
	*@pre: Root is not nullptr
	*@post: Deletes the Heap
	*@return: none
	*/
	void removeHeap(Node* subTree);

	/*
	*@pre: None
	*@post: Inserts the new value into the Heap
	*@return: None
	*/
	void insert(int key);

	/*
	*@pre: Root is not nullptr
	*@post: Merges two nodes together
	*@return: The resulting heap
	*/
	Node* merge(Node* h1, Node* h2);

	/*
	*@pre: Root is not nullptr
	*@post: Deletes the root node
	*@return: None
	*/
	void deleteMax();

	/*
	*@pre: Root is not nullptr
	*@post: None
	*@return: None
	*/
	void levelOrder();

	/*
	*@pre: Root is not nullptr
	*@post: None
	*@return: None
	*/
	void preOrder();

	/*
	*@pre: Root is not nullptr
	*@post: None
	*@return: None
	*/
	void preOrderRecursive(Node* subTree);

	/*
	*@pre: Root is not nullptr
	*@post: None
	*@return: None
	*/
	void inOrder();

	/*
	*@pre: Root is not nullptr
	*@post: None
	*@return: None
	*/
	void inOrderRecursive(Node* subTree);

	/*
	*@pre: Root is not nullptr
	*@post: None
	*@return: None
	*/
	void postOrder();

	/*
	*@pre: Root is not nullptr
	*@post: None
	*@return: None
	*/
	void postOrderRecursive(Node* subTree);
};

#endif