/*
Node class header file
@file: Node.h
@author: Hunter Crisp
@date: 24 September 2018
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

  public:
  //Constructs a blank node
  Node();

  /*
  *@pre: Pointer to current node exists
  *@post: None
  *@return: Integer Value of current node
  */
  int getValue();

  bool getFlag();

  /*
  *@pre: Node has been constructed
  *@post: Sets value of node to v
  *@return: None
  */
  void setValue(int v);

  void setFlag(bool b);

};
#endif
