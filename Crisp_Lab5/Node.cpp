/*
*@file: Node.cpp
*@Author: Hunter Crisp
*@date: 16 October 2018
*/

#include "Node.h"

Node::Node()
{
  leftChild = nullptr;
  rightChild = nullptr;
}

Node* Node::getLeft()
{
  return leftChild;
}

Node* Node::getRight()
{
  return rightChild;
}

int Node::getValue()
{
  return value;
}

void Node::setLeft(Node* newLeft)
{
  leftChild = newLeft;
}

void Node::setRight(Node* newRight)
{
  rightChild = newRight;
}

void Node::setValue(int newValue)
{
  value = newValue;
}


