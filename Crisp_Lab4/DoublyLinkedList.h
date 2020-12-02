/*
Doubly Linked List Class head file
@file: DoublyLinkedList.h
@author: Hunter Crisp
@date: 7 October 2018
*/
#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>
#include "Node.h"
using namespace std;

class DoublyLinkedList
{
  private:
  int size; //size of the list
  Node* front; //Node at the front of the list

  public:
  //Constructor
  DoublyLinkedList();

  //Destructor
  ~DoublyLinkedList();

  /*
  *@pre: List either contains nodes or is empty
  *@post: None
  *@return: Returns a pointer to  the Node at the front of the list
  */
  Node* frontNode();

  /*
  *@pre: List does not contain new value or is empty
  *@post: Inserts a node to the front of a list
  *@return: None
  */
  void insert(int newValue);

  /*
  *@pre: List either contains nodes or is empty
  *@post: Removes a node recursively from a list if found
  *@return: True if node was found and removed from the list, false otherwise
  */
  bool remove(int deleteValue);

  /*
  *@pre: currentNode is not equal to nullptr, list is not empty
  *@post: Recursively traverses a list and deletes the node with that value if found
  *@return: True if node with value was removed from list, false otherwise
  */
  bool deleteRecursive(int deleteValue, Node* currentNode);

  /*
  *@pre: List either contains nodes or is empty
  *@post: Prints each value in the list
  *@return: None
  */
  void print();
};
#endif
