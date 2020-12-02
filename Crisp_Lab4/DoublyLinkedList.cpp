/*
Doubly Linked List class functions and constructors
@file: DoublyLinkedList.cpp
@author: Hunter Crisp
@date: 7 October 2018
*/
#include "DoublyLinkedList.h"



//Constructs an empty list
DoublyLinkedList::DoublyLinkedList()
{
  front = nullptr;
  size = 0;
}

//Destructor removes all nodes
DoublyLinkedList::~DoublyLinkedList()
{
  Node* temp;
  while(front)
  {
    temp = front;
    front = front->getNext();
    delete temp;
  }
  delete front;
}

//Returns the front node
Node* DoublyLinkedList::frontNode()
{
  return front;
}

//Inserts a node at the front of a list
void DoublyLinkedList::insert(int newValue)
{
  Node* temp = new Node();
  temp->setValue(newValue);

  if(size == 0)
  {
    //If list is empty, add node and make it the front node
    front = temp;
    size++;
  }
  else
  {
    //Add to the front of the list
    Node* temp2 = front;
    temp->setNext(temp2);
    front = temp;
    size++;
  }

}

//Calls a recursive function to find and remove a node from the list
bool DoublyLinkedList::remove(int deleteValue)
{

  if(size == 0)
  {
    //Returns false if list is empty
    return false;
  }
  else if(deleteValue == front->getValue())
  {
    //Remove front node and return true
    Node* temp = front->getNext();
    delete front;
    front = temp;
    size--;
    return true;
  }
  else if(front->getNext() == nullptr)
  {
    //Return false since the Node is not in the list, and was therefore not removed
    return false;
  }
  else
  {
    Node* temp = front;
    while(temp)
    {
      if(temp->getNext())
      {
        if(temp->getNext()->getValue() == deleteValue)
        {
          Node* temp2 = temp->getNext();
          temp->setNext(temp->getNext()->getNext());
          delete temp2;
          size--;
          return true;
        }
      }
    }
    return false;
  }

}

void DoublyLinkedList::print()
{
  Node* temp = front;
  while(temp)
  {
    cout << " " << temp->getValue();
    temp = temp->getNext();
  }
}
