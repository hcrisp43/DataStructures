/*
*@file: TwoThreeTree.h
*@author: Hunter Crisp
*@date: 30 October 2018
*/


#ifndef TWOTHREETREE_H
#define TWOTHREETREE_H

#include <iostream>
#include "Node.h"
using namespace std;

class TwoThreeTree
{
  private:
 

  public:
  Node* root;
  TwoThreeTree();
  ~TwoThreeTree();

  /*
  *@pre: root is not nullptr
  *@post: root is empty
  *@return: none
  */
  void emptyTree(Node* T);

  /*
  *@pre: root is not nullptr
  *@post: none
  *@return: The node if found, nullptr otherwise
  */
  Node* find(int x, Node* T);

  /*
  *@pre: x is not in Tree
  *@post: x is in Tree
  *@return: none
  */
  void insert(int x, Node* T);

  /*
  *@pre: x is not in Tree
  *@post: x is in Tree
  *@return:
  */
  void insert(Node* temp, Node* T);

  /*
  *@pre: root is not nullptr
  *@post: interior node is inserted into tree
  *@return: none
  */
  void insertNode(Node* temp, Node*T);

  /*
  *@pre: root is not nullptr
  *@post: T has its Minimum Second and Third values updated
  *@return: None
  */
  void updateTree(Node* T);

  /*
  *@pre: root is not nullptr, x is in Tree
  *@post: x is removed from tree
  *@return: true if x was removed, false otherwise
  */
  bool remove(int x, Node* T);

  /*
  *@pre: root is not nullptr, x is in the tree
  *@post: x is removed from tree
  *@return: true if x was removed, false otherwise
  */
  bool remove(Node* temp, Node* T);

  /*
  *@pre: root is not nullptr
  *@post: root of subTree T is updated if levels are uneven
  *@return: none
  */
  void collapseTree(Node* T);

  /*
  *@pre: root is not nullptr
  *@post: minimum value x is removed from tree
  *@return: true if x was removed, false otherwise
  */
  bool deleteMin();

  /*
  *@pre: root is not nullptr
  *@post: maximum value x is removed from tree
  *@return: true if x was removed, false otherwise
  */
  bool deleteMax();

  /*
  *@pre: root is not nullptr
  *@post: none
  *@return: node with minimum value of tree T
  */
  Node* findMin(Node* T);

  /*
  *@pre: root is not nullptr
  *@post: none
  *@return: node with maximum value of tree T
  */
  Node* findMax(Node* T);

  /*
  *@pre: root is not nullptr
  *@post: none
  *@return: none
  */
  void levelOrderPrint(Node* T);
};

#endif
