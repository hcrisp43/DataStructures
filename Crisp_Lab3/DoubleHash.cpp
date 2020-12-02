/*
*@file: DoubleHash.cpp
*@author: Hunter Crisp
*@date: 24 September 2018
*/

#include "DoubleHash.h"

//Constructor
DoubleHash::DoubleHash()
{
  numElements = 0;
}


//Returns the hashed index value of the key
int DoubleHash::hash(int key)
{
  int index = (key % size) % size;
  if(table[index].getValue() == -1 && !table[index].getFlag())
  {
    return index;
  }
  else if(table[index].getValue() == key)
  {
    cout << "Cannot add duplicate value of " << key << " to hash table with quadratic probing."<< endl;
    return -1;
  }
  else
  {
    int k = 1;
    while(k < 10)
    {
      index = ((key % size)+(k*(13-(key % 13)))) % size;
      if(table[index].getValue() == key)
      {
        cout << "Cannot add duplicate value of " << key << " to hash table with quadratic probing."<< endl;
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
bool DoubleHash::insert(int key)
{
  
  int index = hash(key);
  
  if(index != -1)
  {
    table[index].setValue(key);
    numElements++;
    return true;
  }
  
  return false;
}

//Return true if the value was deleted from the list
bool DoubleHash::deleteNode(int key)
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
void DoubleHash::print()
{
  cout << endl << "Hash table with double hashing: " << endl;
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
int DoubleHash::find(int key)
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
