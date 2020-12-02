/*
*@file: BinarySearchTree.h
*@Author: Hunter Crisp
*@date: 16 October 2018
*/


#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "Node.h"
#include <iostream>
#include <queue>
using namespace std;

class BinarySearchTree
{
  private:
  

  public:
  Node* root;
  BinarySearchTree();
  ~BinarySearchTree();

  /*
  *@pre:The tree is not empty
  *@post:The tree is deleted recursively
  *@return: None
  */
  void deleteTree(Node* subTree);

  /*
  *@pre: The tree exists
  *@post: A value is inserted into the tree
  *@return: None
  */
  void insert(int x);

  /*
  *@pre: The tree exists
  *@post: Recursively add a value to the tree
  *@return: None
  */
  void insertRecursive(int x, Node* subTree);

  /*
  *@pre: The tree is not empty
  *@post: None
  *@return: The node with value of x if found
  */
  Node* search(int x, Node* subTree);

  /*
  *@pre: The tree exists
  *@post: None
  *@return: True if the tree is empty, false otherwise
  */
  bool isEmpty();

  /*
  *@pre: The tree is not empty
  *@post: The value x is removed from the tree
  *@return: None
  */
  void remove(int x);

  /*
  *@pre: The tree is not empty
  *@post: The subTree node is removed
  *@return: None
  */
  void removeRecursive(Node* subTree);

  /*
  *@pre: The tree is not empty
  *@post: None
  *@return: The minimum value in the subTree
  */
  Node* findMin(Node* subTree);

  /*
  *@pre: The tree is not empty
  *@post: None
  *@return:  The maximum value in the subTree
  */
  Node* findMax(Node* subTree);

  /*
  *@pre: The tree is not empty
  *@post: The minimum value is removed from the tree
  *@return: None
  */
  void deleteMin();

  /*
  *@pre: The tree is not empty
  *@post: The maximum value is removed from the tree
  *@return: None
  */
  void deleteMax();

  /*
  *@pre: The tree is not empty
  *@post: None
  *@return: None
  */
  void preOrder();

  /*
  *@pre: The tree is not empty
  *@post: None
  *@return: None
  */
  void preOrderRecursive(Node* subTree);

  /*
  *@pre: The tree is not empty
  *@post: None
  *@return: None
  */
  void inOrder();

  /*
  *@pre: The tree is not empty
  *@post: None
  *@return: None
  */
  void inOrderRecursive(Node* subTree);

  /*
  *@pre: The tree is not empty
  *@post: None
  *@return: None
  */
  void postOrder();

  /*
  *@pre: The tree is not empty
  *@post: None
  *@return: None
  */
  void postOrderRecursive(Node* subTree);

};

#endif
