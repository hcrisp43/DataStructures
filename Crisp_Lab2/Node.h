#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

class Node
{
  private:
  int value;
  Node* previous;
  Node* next;

  public:
  Node();
  Node* getNext();
  Node* getPrevious();
  int getValue();
  void setValue(int v);
  void setNext(Node* n);
  void setPrevious(Node* p);

};
#endif
