#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>
#include "Node.h"
using namespace std;

class DoublyLinkedList
{
  private:
  int size;
  Node* front;


  public:
  DoublyLinkedList();
  ~DoublyLinkedList();

  
  void insert(Node* newValue);
  bool remove(Node* deleteValue);
  void print();
  void reverse();
  void insertRecursive(Node* newValue, Node* currentValue);
  bool deleteRecursive(Node* deleteValue, Node* currentValue);
};
#endif
