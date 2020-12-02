/*
Node class functions and constructor
@file: Node.cpp
@author: Hunter Crisp
@date: 7 October 2018
*/
#include "Node.h"
using namespace std;

Node::Node()
{
  //Constructs a blank node
  isRemoved = false;
  value = -1;
  next = nullptr;
}

int Node::getValue()
{
  //Returns the value of the node
  return value;
}

bool Node::getFlag()
{
  //Returns the value of the flag
  return isRemoved;
}

Node* Node::getNext()
{
  //Return pointer to next node
  return next;
}

void Node::setValue(int v)
{
  //Sets the value of the node
  value = v;
}

void Node::setFlag(bool b)
{
  //Sets the value of the flag
  isRemoved = b;
}

void Node::setNext(Node* temp)
{
  //Sets value of next
  next = temp;
}
