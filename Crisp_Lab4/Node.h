/*
Node class header file
@file: Node.h
@author: Hunter Crisp
@date: 7 October 2018
*/

#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <math.h>
using namespace std;

class Node
{
  private:
  int value;//Value of node
  bool isRemoved;
  Node* next;

  public:
  //Constructs a blank node
  Node();

  /*
  *@pre: Pointer to current node exists
  *@post: None
  *@return: Integer Value of current node
  */
  int getValue();

  /*
  *@pre: Pointer to current node exists
  *@post: None
  *@return: Value of removed flag
  */
  bool getFlag();

  /*
  *@pre: Point to current node exists
  *@post: None
  *@return: Pointer to next node in list
  */
  Node* getNext();

  /*
  *@pre: Node has been constructed
  *@post: Sets value of node to v
  *@return: None
  */
  void setValue(int v);

  /*
  *@pre: Pointer to current node exists
  *@post: Sets isRemoved value equal to parameter b
  *@return: None
  */
  void setFlag(bool b);

  /*
  *@pre: Pointer to current node exists
  *@post: Sets next pointer equal to parameter pointer temp
  *return: None
  */
  void setNext(Node* temp);

};
#endif
