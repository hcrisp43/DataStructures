/*
*Hash Table header file
*@file: HashTable.h
*@author: Hunter Crisp
*@date: 18 Septemeber 2018
*/

#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "Node.h"
#include "DoublyLinkedList.h"
using namespace std;

class HashTable
{
private:
  int size = 100003;
  DoublyLinkedList table[100003];
public:
  int numElements;
  HashTable();
  ~HashTable();

  /*
  *@pre: List either contains nodes or is empty
  *@post: Inserts a node at the front of the list
  *@return: True if the node was added, false otherwise
  */
  void insert(int key);

  /*
  *@pre: List either contains nodes or is empty
  *@post: Deletes a node from the list
  *@return: True if the node was deleted, false otherwise
  */
  bool deleteNode (int key);


  /*
  *@pre: List either contains nodes or is empty
  *@post: None
  *@return: Returns the hashed index value of the key
  */
  int hash(int key);

  /*
  *@pre: List either contains nodes or is empty
  *@post: None
  *@return: Returns a pointer to the Node if found
  */
  bool find(int key);

  /*
  *@pre: List either contains nodes or is empty
  *@post: Prints each element of the table
  *@return: None
  */
  void print();
};
#endif
