/*
*@file: Node.cpp
*@Author: Hunter Crisp
*@date: 30 October 2018
*/

#include "Node.h"

//Creates an interior node
Node::Node()
{
  parent = nullptr;
  firstChild = nullptr;
  secondChild = nullptr;
  thirdChild = nullptr;
  minSecond = -1;
  minThird = -1;
  tag = 0;
}

//Creates a leaf node with key equal to x
Node::Node(int x)
{
  parent = nullptr;
  firstChild = nullptr;
  secondChild = nullptr;
  thirdChild = nullptr;
  minSecond = -1;
  minThird = -1;
  tag = 1;
  key = x;
}

Node* Node::getFirst()
{
  return firstChild;
}

Node* Node::getSecond()
{
  return secondChild;
}

Node* Node::getThird()
{
  return thirdChild;
}

Node* Node::getParent()
{
  return parent;
}

int Node::getMinSecond()
{
  return minSecond;
}

int Node::getMinThird()
{
  return minThird;
}

int Node::getTag()
{
  return tag;
}

int Node::getKey()
{
  return key;
}

void Node::setFirst(Node* newFirst)
{
  firstChild = newFirst;
}

void Node::setSecond(Node* newSecond)
{
  secondChild = newSecond;
}

void Node::setThird(Node* newThird)
{
  thirdChild = newThird;
}

void Node::setParent(Node* newParent)
{
  parent = newParent;
}

void Node::setMinSecond(int newMinSecond)
{
  minSecond = newMinSecond;
}

void Node::setMinThird(int newMinThird)
{
  minThird = newMinThird;
}

void Node::setTag(int t)
{
  tag = t;
}

void Node::setKey(int newKey)
{
  key = newKey;
}
