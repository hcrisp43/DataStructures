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
  Node* firstChild;
  Node* secondChild;
  Node* thirdChild;
  Node* parent;
  int minSecond;
  int minThird;
  int tag;
  int key;

  public:

  Node();
  Node(int x);

  /*
  *@pre: Node exists
  *@post: None
  *@return: A pointer to the first child
  */
  Node* getFirst();

  /*
  *@pre: Node exists
  *@post: None
  *@return: A pointer to the second child
  */
  Node* getSecond();

  Node* getThird();

  Node* getParent();

  int getTag();
  int getMinSecond();
  int getMinThird();

  /*
  *@pre: Node exists
  *@post: None
  *@return: The integer value of the node
  */
  int getKey();

  /*
  *@pre: Node exists
  *@post: Left child pointer is set to newLeft
  *@return: None
  */
  void setFirst(Node* newFirst);

  /*
  *@pre: Node exists
  *@post: Right child pointer is set to newRight
  *@return: None
  */
  void setSecond(Node* newSecond);

  void setThird(Node* newThird);
  void setParent(Node* newParent);
  void setMinSecond(int newMinSecond);
  void setMinThird(int newMinThird);
  void setTag(int t);

  /*
  *@pre: Node exists
  *@post: Sets the integer value of the node to newValue
  *@return: None
  */
  void setKey(int newKey);

};

#endif
