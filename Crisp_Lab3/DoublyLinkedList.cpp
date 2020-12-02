/*
Doubly Linked List class functions and constructors
@file: DoublyLinkedList.cpp
@author: Hunter Crisp
@date: 18 September 2018
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
void DoublyLinkedList::insert(string newValue)
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
    temp2->setPrevious(temp);
    front = temp;
    size++;
  }

}

//Calls a recursive function to find and remove a node from the list
bool DoublyLinkedList::remove(string deleteValue)
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
    //Recursively traverse through list to find Node to remove
    return deleteRecursive(deleteValue, front);
  }

}



//Recursively searches for and deletes a node if found
bool DoublyLinkedList::deleteRecursive(string deleteValue, Node* currentNode)
{
  Node* temp;
  Node* temp2;

  //If value current node is equal to the value to delete, and it is at the end of the list, remove that node
  if(currentNode->getValue() == deleteValue && currentNode->getNext() == nullptr)
  {
    temp = currentNode->getPrevious();
    temp->setNext(nullptr);
    delete currentNode;
    size--;
    return true;
  }

  //Else if value of the current node is equal to the value to delete, delete that node
  else if(currentNode->getValue() == deleteValue)
  {
    temp = currentNode->getPrevious();
    temp2 = currentNode->getNext();
    temp->setNext(temp2);
    temp2->setPrevious(temp);
    delete currentNode;
    size--;
    return true;
  }

  /*Else if at the end of the list and nothing has been found to remove,
  *return false
  */
  else if(currentNode->getNext() == nullptr)
  {
    return false;
  }

   //Continute to traverse through list recursively
  else
  {
    currentNode = currentNode->getNext();
    return deleteRecursive(deleteValue, currentNode);
  }

}

//Prints each element in the list
void DoublyLinkedList::print()
{
  if(size == 0)
  {
    cout << " ";
  }
  else
  {
    Node* temp = front;
    //While pointer to node exists, print Node and get pointer to next node
    while(temp)
    {
      cout << temp->getValue() << " ";
      temp = temp->getNext();
    }
  }
}