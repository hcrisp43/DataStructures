/*
*@file: HashTable.cpp
*@author: Hunter Crisp
*@date: 18 September 2018
*/

#include "HashTable.h"

//Constructor
HashTable::HashTable()
{
  numElements = 0;
}

HashTable::~HashTable()
{
  for(int i = 0; i < numElements; i++)
  {
    table[i].~DoublyLinkedList();
  }

}

//Returns the hashed index value of the key
int HashTable::hash(int key)
{
  return(key % size);
}

//Return true if the value was inserted into the list
void HashTable::insert(int key)
{
  if(!find(key))
  {
    int index = hash(key);
    table[index].insert(key);
    numElements++;
    //return true;
  }

  //return false;
}

//Return true if the value was deleted from the list
bool HashTable::deleteNode(int key)
{
  if(find(key))
  {
    int index = hash(key);
    table[index].remove(key);
    numElements--;
    return true;
  }
  
  return false;
}


//Return the node if found in the list
bool HashTable::find(int key)
{
  int index = hash(key);
  Node* temp = table[index].frontNode();
  while(temp)
  {
    if(temp->getValue() == key)
    {
      return true;
    }
    temp = temp->getNext();
  }

  return false;
}

//Print each element of the table
void HashTable::print()
{
  cout << "Open Hash Table: " << endl;
  for(int i = 0; i < size; i++)
  {
    if(table[i].frontNode())
    {
      cout << i << ":";
      table[i].print();
      cout << endl;
    }
  }
}
