/*
*@file: Node.h
*@Author: Hunter Crisp
*@date: 16 October 2018
*/

#ifndef NODE_H
#define NODE_H
#include <iostream>

class Node
{
  private:
  Node* leftChild;
  Node* rightChild;
  int value;

  public:

  Node();

  /*
  *@pre: Node exists
  *@post: None
  *@return: A pointer to the left child
  */
  Node* getLeft();

  /*
  *@pre: Node exists
  *@post: None
  *@return: A pointer to the right child
  */
  Node* getRight();

  /*
  *@pre: Node exists
  *@post: None
  *@return: The integer value of the node
  */
  int getValue();

  /*
  *@pre: Node exists
  *@post: Left child pointer is set to newLeft
  *@return: None
  */
  void setLeft(Node* newLeft);

  /*
  *@pre: Node exists
  *@post: Right child pointer is set to newRight
  *@return: None
  */
  void setRight(Node* newRight);

  /*
  *@pre: Node exists
  *@post: Sets the integer value of the node to newValue
  *@return: None
  */
  void setValue(int newValue);

};

#endif
