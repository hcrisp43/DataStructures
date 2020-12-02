#ifndef LEFTISTHEAP_H
#define LEFTISTHEAP_H
#include "Node.h"
using namespace std;


class LeftistHeap
{
	public:
		
	Node* root;
	LeftistHeap();
	~LeftistHeap();

	/*
	*@pre: none
	*@post: none
	*@return: True if root is nullptr, false otherwise
	*/
	bool isEmpty();

	/*
	*@pre: root is not nullptr
	*@post: Heap is deleted
	*@return: None
	*/
	void removeHeap(Node* subTree);

	/*
	*@pre: none
	*@post: New value is inserted into the heap
	*@return: None
	*/
	void insert(int key);

	/*
	*@pre: root is not nullptr
	*@post: Recursively merge two nodes
	*@return: The root of the newly merged heap
	*/
	Node* merge(Node* h1, Node* h2);

	/*
	*@pre: subTree is not nullptr
	*@post: subTree rank is adjust based on ranks of children
	*@return: none
	*/
	void adjustRank(Node* subTree);

	/*
	*@pre: Tree is not empty
	*@post: The root of the heap is removed
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
	*@pre: Heap is not empty
	*@post: None
	*@return: None
	*/
	void preOrder();

	/*
	*@pre: Heap is not empty
	*@post: None
	*@return: None
	*/
	void preOrderRecursive(Node* subTree);

	/*
	*@pre: Heap is not empty
	*@post: None
	*@return: None
	*/
	void inOrder();

	/*
	*@pre: Heap is not empty
	*@post: None
	*@return: None
	*/
	void inOrderRecursive(Node* subTree);

	/*
	*@pre: Heap is not empty
	*@post: None
	*@return: None
	*/
	void postOrder();

	/*
	*@pre: Heap is not empty
	*@post: None
	*@return: None
	*/
	void postOrderRecursive(Node* subTree);
};

#endif
