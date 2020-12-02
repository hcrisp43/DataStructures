#ifndef NODE_H
#define NODE_H
#include <iostream>
 
class Node
{
  private:
  Node* leftChild;
  Node* rightChild;
  int value;
  int rank;


  public:
  Node();
  Node* getLeft();
  Node* getRight();
  int getValue();
  int getRank();
  void setLeft(Node* newLeft);
  void setRight(Node* newRight);
  void setValue(int newValue);
  void setRank(int newRank);

};

#endif
