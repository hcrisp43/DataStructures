/*
*@file: QuadraticProbing.cpp
*@author: Hunter Crisp
*@date: 7 October 2018
*/

#include "QuadraticProbing.h"

//Constructor
QuadraticProbing::QuadraticProbing()
{
  numElements = 0;
}


//Returns the hashed index value of the key
int QuadraticProbing::hash(int key)
{
  int index = (key % size) % size;
  if(table[index].getValue() == -1 && !table[index].getFlag())
  {
    return index;
  }
  else if(table[index].getValue() == key)
  {
    return -1;
  }
  else
  {
    int k = 1;
    while(k < 20)
    {
      index = ((key % size)+(k*k)) % size;
      if(table[index].getValue() == key)
      {
        return -1;
      }
      if(table[index].getValue() == -1 && !table[index].getFlag())
      {
        return index;
      }
      k++;
    }
  }

  return -1;
}

//Return true if the value was inserted into the list
void QuadraticProbing::insert(int key)
{

  int index = hash(key);

  if(index != -1)
  {
    table[index].setValue(key);
    numElements++;
  }
}

//Return true if the value was deleted from the list
bool QuadraticProbing::deleteNode(int key)
{
  if(find(key))
  {
    int i = find(key);
    table[i].setValue(-1);
    table[i].setFlag(true);
    numElements--;
    return true;
  }
  return false;
}

//Print the value of each node in the list
void QuadraticProbing::print()
{
  cout << endl << "Hash table with quadratic probing: " << endl;
  for(int i = 0; i < size; i++)
  {
    if(table[i].getValue() != -1)
    {
      cout << i << ": " << table[i].getValue() << endl;
      cout << endl;
    }
  }
}

//Return the index to the node if found in the list
int QuadraticProbing::find(int key)
{
  for(int i = 0; i < size; i++)
  {
    if(table[i].getValue() == key)
    {
      return i;
    }
  }

  return 0;
}
