#include "Hash.h"

Hash::Hash(int s)
{
  size = s;
  for(int i = 0; i < size; i++)
  {
    addressArray[i] =
  }
}

Hash::~Hash()
{

}

int Hash::hash(int key)
{
  return (key.getValue() % size);
}

void Hash::insert(int key)
{


}

void Hash::delete(int key)
{

}

void Hash::print()
{

}

bool Hash::find(int key)
{
  for (int i = 0; i < size; i++)
  {

  }
}
