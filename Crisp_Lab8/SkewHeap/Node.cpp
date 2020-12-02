#include "Node.h"

Node::Node()
{
  leftChild = nullptr;
  rightChild = nullptr;
  rank = 1;
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

int Node::getRank()
{
  return rank;
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

void Node::setRank(int newRank)
{
  rank = newRank;
}
