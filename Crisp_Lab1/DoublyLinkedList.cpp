#include "DoublyLinkedList.h"

void DoublyLinkedList::insertRecursive(Node* newValue, Node* currentValue)
{

  if(currentValue->getNext() == nullptr)
  {
    currentValue->setNext(newValue);
    newValue->setPrevious(currentValue);
    size++;
    return;
  }
  else if(newValue == currentValue)
  {
    delete newValue;
    return;
  }
  else
  {
    currentValue = currentValue->getNext();
    insertRecursive(newValue, currentValue);
  }
}

bool DoublyLinkedList::deleteRecursive(Node* deleteValue, Node* currentValue)
{
  if(currentValue == deleteValue)
  {
    Node* temp = currentValue->getPrevious();
    Node* temp2 = currentValue->getNext();
    temp->setNext(temp2);
    temp2->setPrevious(temp);
    delete temp;
    size--;
    return true;
  }
  else if(currentValue->getNext() == nullptr)
  {
    return false;
  }
  else
  {
    currentValue = currentValue->getNext();
    return deleteRecursive(deleteValue, currentValue);
  }

}
DoublyLinkedList::DoublyLinkedList()
{
  front = nullptr;
  size = 0;
}

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

void DoublyLinkedList::print()
{
  Node* temp;
  if(size == 0)
  {
    cout << "List is empty" << endl;
  }
  else
  {
    temp = front;
    while(temp)
    {
      cout << temp->getValue() << endl;
      temp = temp->getNext();
    }
  }
}

void DoublyLinkedList::insert(Node* newValue)
{
  Node* currentValue = front;
  if(size == 0)
  {
    front = newValue;
    size++;
  }
  else if(newValue == currentValue)
  {
    delete newValue;
    return;
  }
  else
  {
    currentValue = currentValue->getNext();
    insertRecursive(newValue, currentValue);
  }

}

void DoublyLinkedList::reverse()
{
  if(size == 0 || size == 1)
  {
    return;
  }

  return;

}

bool DoublyLinkedList::remove(Node* deleteValue)
{
  Node* temp = front;
  if(size == 0)
  {
    cout << "List is empty." << endl;
    return false;
  }
  else if(front == deleteValue)
  {
    deleteValue = front;
    front = front->getNext();
    front->setPrevious(nullptr);
    delete deleteValue;
    size--;
    return true;
  }
  else if(temp->getNext() == nullptr)
  {
    return false;
  }
  else
  {
    temp = temp->getNext();
    return deleteRecursive(deleteValue, temp);
  }

}
