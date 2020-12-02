#include "Node.h"
using namespace std;

Node::Node()
{
  next = nullptr;
  previous =  nullptr;
}

Node* Node::getNext()
{
  return next;
}

Node* Node::getPrevious()
{
  return previous;
}

int Node::getValue()
{
  return value;
}

void Node::setValue(int v)
{
  value = v;
}

void Node::setNext(Node* n)
{
  next = n;
}

void Node::setPrevious(Node* p)
{
  previous = p;
}
