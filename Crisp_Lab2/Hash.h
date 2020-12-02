#ifndef HASH_H
#define HASH_H
#include "Node.h"
#include "DoublyLinkedList.h"
using namespace std;

class Hash
{
private:
  int size;
  int* addressArray[] = {};
public:
  Hash(int s);
  ~Hash();
  void insert(int key);
  void delete(int key);
  void print();
  int hash(int key);
  bool find(int key);
};
#endif
