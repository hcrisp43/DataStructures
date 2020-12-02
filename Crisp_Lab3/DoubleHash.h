/*
*Double Hash Table header file
*@file: DoubleHash.h
*@author: Hunter Crisp
*@date: 24 Septemeber 2018
*/

#ifndef DoubleHash_H
#define DoubleHash_H
#include "Node.h"
using namespace std;

class DoubleHash
{
private:
  int size = 53;
  Node table[53];
public:
  int numElements;
  DoubleHash();
  

  /*
  *@pre: List either contains nodes or is empty
  *@post: Inserts a node at the front of the list
  *@return: True if the node was added, false otherwise
  */
  bool insert(int key);

  /*
  *@pre: List either contains nodes or is empty
  *@post: Deletes a node from the list
  *@return: True if the node was deleted, false otherwise
  */
  bool deleteNode(int key);

  /*
  *@pre: List either contains nodes or is empty
  *@post: None
  *@return: Prints the value of each node in the list
  */
  void print();

  /*
  *@pre: List either contains nodes or is empty
  *@post: None
  *@return: Returns the hashed index value of the key
  */
  int hash(int key);

  /*
  *@pre: List either contains nodes or is empty
  *@post: None
  *@return: Returns the index to the Node if found
  */
  int find(int key);
};
#endif
