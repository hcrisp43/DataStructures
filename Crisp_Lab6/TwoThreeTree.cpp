/*
*@file: TwoThreeTree.cpp
*@author: Hunter Crisp
*@date: 30 October 2018
*/

#include "TwoThreeTree.h"

TwoThreeTree::TwoThreeTree()
{
  root = nullptr;
}

TwoThreeTree::~TwoThreeTree()
{
  emptyTree(root);
}

//Recursively delete every node in the tree
void TwoThreeTree::emptyTree(Node* T)
{
  if(T != nullptr)
  {
    emptyTree(T->getFirst());
    emptyTree(T->getSecond());
    emptyTree(T->getThird());
    delete T;
  }
}

//Return node if the node is in the tree, otherwise return nullptr
Node* TwoThreeTree::find(int x, Node* T)
{
  if(T != nullptr)
  {
    if(T->getTag() == 1 && T->getKey() == x)
    {
      return T;
    }
    else
    {
      if(x < T->getMinSecond())
      {
        return find(x, T->getFirst());
      }
      else if(T->getMinThird() != -1 && x >= T->getMinThird())
      {
        return find(x, T->getThird());
      }
      else
      {
        return find(x, T->getSecond());
      }
    }
  }
  return nullptr;
}

//Insert the node into the tree if it does not already exist
void TwoThreeTree::insert(int x, Node* T)
{
  if(find(x, root) != nullptr)
  {
    cout << "Cannot add duplicate elements." << endl;
  }
  else
  {
    Node* temp = new Node(x);
    //If tree is empty
    if(T == nullptr && T == root)
    {
      T = new Node();
      T->setFirst(temp);
      temp->setParent(T);
      root = T;
    }
    //If tree has one node
    else if(T->getFirst() != nullptr && T->getSecond() == nullptr && T->getThird() == nullptr)

    {
      //If child is interior node, insert a leaf node into the tree
      if(T->getFirst()->getTag() == 0 && T->getSecond()->getTag() == 0)
      {
        insert(temp, T);
      }
      //Otherwise, determine whether to set temp as first or second child
      else
      {
        if(temp->getKey() > T->getFirst()->getKey())
        {
          T->setSecond(temp);
          temp->setParent(T);
          T->setMinSecond(temp->getKey());
        }
        else
        {
          T->setSecond(T->getFirst());
          T->setFirst(temp);
          temp->setParent(T);
          updateTree(T);
        }
      }
    }
    //Root has more than one child
    else
    {
      insert(temp, T);
    }
  }

}

//Update the Minimum second and third values of subTree T
void TwoThreeTree::updateTree(Node* T)
{
  if(T->getSecond() != nullptr)
  {
    if(T->getSecond()->getTag() == 1)
    {
      T->setMinSecond(T->getSecond()->getKey());
    }
    else
    {
      Node* temp = T->getSecond();
      while(temp->getTag() != 1)
      {
        temp = temp->getFirst();
      }
      T->setMinSecond(temp->getKey());
    }
  }
  else
  {
    T->setMinSecond(-1);
  }

  if(T->getThird() != nullptr)
  {
    if(T->getThird()->getTag() == 1)
    {
      T->setMinThird(T->getThird()->getKey());
    }
    else
    {
      Node* temp = T->getThird();
      while(temp->getTag() != 1)
      {
        temp = temp->getFirst();
      }
      T->setMinThird(temp->getKey());
    }
  }
  else
  {
    T->setMinThird(-1);
  }

  //Recursively update through tree
  if(T->getParent() != nullptr)
  {
    updateTree(T->getParent());
  }
}

//Insert a leaf node into the tree
void TwoThreeTree::insert(Node* temp, Node* T)
{

  //If T has two children
  if(T->getThird() == nullptr)
  {
    //Recursively traverse until leaf nodes have been found
    if(T->getFirst()->getTag() == 0 && T->getSecond()->getTag() == 0)
    {
      if(temp->getKey() < T->getMinSecond())
      {
        insert(temp, T->getFirst());
      }
      else
      {
        insert(temp, T->getSecond());
      }
    }
    else
    {
      //Insert as first child
      if(temp->getKey() > T->getFirst()->getKey() && temp->getKey() >= T->getSecond()->getKey())
      {
        T->setThird(temp);
        temp->setParent(T);

      }
      //Insert as second child
      else if(temp->getKey() > T->getFirst()->getKey() && temp->getKey() < T->getSecond()->getKey())
      {
        Node* temp2 = T->getSecond();
        temp->setParent(T);
        T->setSecond(temp);
        T->setThird(temp2);

      }
      //Insert as third child
      else
      {
        Node* temp2 = T->getFirst();
        Node* temp3 = T->getSecond();
        temp->setParent(T);
        T->setFirst(temp);
        T->setSecond(temp2);
        T->setThird(temp3);
      }

      updateTree(T);
    }
  }
  //T has 3 children
  else
  {
    //Recursively traverse until leaf nodes have been found
    if(T->getFirst()->getTag() == 0 && T->getSecond()->getTag() == 0 && T->getThird()->getTag() == 0)
    {
      if(temp->getKey() < T->getMinSecond())
      {
        insert(temp, T->getFirst());
      }
      else if(temp->getKey() > T->getMinSecond() && temp->getKey() < T->getMinThird())
      {
        insert(temp, T->getSecond());
      }
      else
      {
        insert(temp, T->getThird());
      }
    }
    else
    {
      if(T == root)
      {
        Node* newRoot = new Node();
        Node* newSecond = new Node();
        Node* temp2 = T->getFirst();
        Node* temp3 = T->getSecond();
        Node* temp4 = T->getThird();

        //Adopt first child and make new parent node and create new root
        if(temp->getKey() < temp2->getKey())
        {
          newSecond->setFirst(temp3);
          newSecond->setSecond(temp4);
          temp3->setParent(newSecond);
          temp4->setParent(newSecond);
          updateTree(newSecond);

          T->setThird(nullptr);
          T->setSecond(temp2);
          T->setFirst(temp);
          temp->setParent(T);
          updateTree(T);

          newRoot->setFirst(T);
          newRoot->setSecond(newSecond);
          T->setParent(newRoot);
          newSecond->setParent(newRoot);
          root = newRoot;
          updateTree(root);
        }
        //Adop first child and make new parent node and create new root
        else if(temp->getKey() > temp2->getKey() && temp->getKey() < temp3->getKey())
        {
          newSecond->setFirst(temp3);
          newSecond->setSecond(temp4);
          temp3->setParent(newSecond);
          temp4->setParent(newSecond);
          updateTree(newSecond);

          T->setThird(nullptr);
          T->setSecond(temp);
          T->setFirst(temp2);
          temp->setParent(T);
          updateTree(T);

          newRoot->setFirst(T);
          newRoot->setSecond(newSecond);
          T->setParent(newRoot);
          newSecond->setParent(newRoot);
          root = newRoot;
          updateTree(root);
        }

        //Adopt third child and make new parent node and create new root
        else if(temp->getKey() > temp3->getKey() && temp->getKey() < temp4->getKey())
        {
          newSecond->setFirst(temp);
          newSecond->setSecond(temp4);
          temp->setParent(newSecond);
          temp4->setParent(newSecond);
          updateTree(newSecond);

          T->setThird(nullptr);
          T->setSecond(temp3);
          T->setFirst(temp2);
          updateTree(T);

          newRoot->setFirst(T);
          newRoot->setSecond(newSecond);
          T->setParent(newRoot);
          newSecond->setParent(newRoot);
          root = newRoot;
          updateTree(root);
        }
        //Adopt third child and create new parent node and create new root
        else
        {
          newSecond->setFirst(temp4);
          newSecond->setSecond(temp);
          temp->setParent(newSecond);
          temp4->setParent(newSecond);
          updateTree(newSecond);

          T->setThird(nullptr);
          T->setSecond(temp3);
          T->setFirst(temp2);
          updateTree(T);

          newRoot->setFirst(T);
          newRoot->setSecond(newSecond);
          T->setParent(newRoot);
          newSecond->setParent(newRoot);
          root = newRoot;
          updateTree(root);
        }
      }

      else
      {
        //If first child has three children and x is larger than the third leaf of the first child, insert x into second child
        if(T->getParent()->getFirst() == T && T->getThird() != nullptr)
        {
          if(temp->getKey() > T->getMinThird())
          {
            insert(temp, T->getParent()->getSecond());
            return;
          }

        }
        //If second child has three children and x is larger than the third leaf of the second child, insert x into the third child
        if(T->getParent()->getSecond() == T && T->getThird() != nullptr)
        {
          if(temp->getKey() > T->getMinThird() && T->getParent()->getThird() != nullptr)
          {
            insert(temp, T->getParent()->getThird());
            return;
          }
        }


        //Insert x into the third child
        //Node* newRoot = new Node();
        Node* oldRoot = T->getParent();
        //Node* newParent = new Node();
        Node* newSecond = new Node();
        Node* temp2 = T->getFirst();
        Node* temp3 = T->getSecond();
        Node* temp4 = T->getThird();

        //If subTree is a first child
        if(oldRoot->getFirst() == T)
        {
          //Determine which child to adopt and insert new parent node into original parent
          if(temp->getKey() < temp2->getKey())
          {
            T->setParent(nullptr);

            newSecond->setFirst(temp3);
            newSecond->setSecond(temp4);
            temp3->setParent(newSecond);
            temp4->setParent(newSecond);
            updateTree(newSecond);
            oldRoot->setFirst(newSecond);
            newSecond->setParent(oldRoot);

            T->setThird(nullptr);
            T->setSecond(temp2);
            T->setFirst(temp);
            temp->setParent(T);
            updateTree(T);
            insertNode(T, oldRoot);


          }
          else if(temp->getKey() > temp2->getKey() && temp->getKey() < temp3->getKey())
          {
            T->setParent(nullptr);

            newSecond->setFirst(temp3);
            newSecond->setSecond(temp4);
            temp3->setParent(newSecond);
            temp4->setParent(newSecond);
            updateTree(newSecond);
            oldRoot->setFirst(newSecond);
            newSecond->setParent(oldRoot);

            T->setThird(nullptr);
            T->setSecond(temp);
            T->setFirst(temp2);

            temp->setParent(T);
            updateTree(T);
            insertNode(T, oldRoot);

          }
          else if(temp->getKey() > temp3->getKey() && temp->getKey() < temp4->getKey())
          {
            newSecond->setFirst(temp);
            newSecond->setSecond(temp4);
            temp->setParent(newSecond);
            temp4->setParent(newSecond);
            updateTree(newSecond);


            T->setThird(nullptr);
            T->setSecond(temp3);
            T->setFirst(temp2);
            updateTree(T);
            oldRoot->setFirst(T);


            insertNode(newSecond, oldRoot);

          }
          else
          {
            newSecond->setFirst(temp4);
            newSecond->setSecond(temp);
            temp->setParent(newSecond);
            temp4->setParent(newSecond);
            updateTree(newSecond);

            T->setThird(nullptr);
            T->setSecond(temp3);
            T->setFirst(temp2);
            updateTree(T);
            oldRoot->setFirst(T);

            insertNode(newSecond, oldRoot);
          }

        }
        //subTree T is a second child
        else if(oldRoot->getSecond() == T)
        {
          //Determine which child to adopt and insert new parent into old parent
          if(temp->getKey() < temp2->getKey())
          {
            T->setParent(nullptr);

            newSecond->setFirst(temp3);
            newSecond->setSecond(temp4);
            temp3->setParent(newSecond);
            temp4->setParent(newSecond);
            oldRoot->setSecond(newSecond);
            newSecond->setParent(oldRoot);
            updateTree(newSecond);

            T->setThird(nullptr);
            T->setSecond(temp2);
            T->setFirst(temp);
            temp->setParent(T);
            updateTree(T);
            insertNode(T, oldRoot);
          }
          else if(temp->getKey() > temp2->getKey() && temp->getKey() < temp3->getKey())
          {
            T->setParent(nullptr);

            newSecond->setFirst(temp3);
            newSecond->setSecond(temp4);
            temp3->setParent(newSecond);
            temp4->setParent(newSecond);
            oldRoot->setSecond(newSecond);
            newSecond->setParent(oldRoot);
            updateTree(newSecond);

            T->setThird(nullptr);
            T->setSecond(temp);
            T->setFirst(temp2);
            temp->setParent(T);
            updateTree(T);
            insertNode(T, oldRoot);

          }
          else if(temp->getKey() > temp3->getKey() && temp->getKey() < temp4->getKey())
          {
            newSecond->setFirst(temp);
            newSecond->setSecond(temp4);
            temp->setParent(newSecond);
            temp4->setParent(newSecond);
            updateTree(newSecond);


            T->setThird(nullptr);
            T->setSecond(temp3);
            T->setFirst(temp2);
            updateTree(T);
            oldRoot->setSecond(T);
            updateTree(oldRoot);
            insertNode(newSecond, oldRoot);
          }
          else
          {
            newSecond->setFirst(temp4);
            newSecond->setSecond(temp);
            temp->setParent(newSecond);
            temp4->setParent(newSecond);
            updateTree(newSecond);

            T->setThird(nullptr);
            T->setSecond(temp3);
            T->setFirst(temp2);
            updateTree(T);
            oldRoot->setSecond(T);
            updateTree(oldRoot);
            insertNode(newSecond, oldRoot);
          }
        }
        //subTree T is a third child
        else
        {
          //Determine which child to adopt and insert new parent into old parent
          if(temp->getKey() < temp2->getKey())
          {
            T->setParent(nullptr);

            newSecond->setFirst(temp3);
            newSecond->setSecond(temp4);
            temp3->setParent(newSecond);
            temp4->setParent(newSecond);
            oldRoot->setThird(newSecond);
            newSecond->setParent(oldRoot);
            updateTree(newSecond);


            T->setThird(nullptr);
            T->setSecond(temp2);
            T->setFirst(temp);
            temp->setParent(T);
            updateTree(T);
            insertNode(T, oldRoot);

          }
          else if(temp->getKey() > temp2->getKey() && temp->getKey() < temp3->getKey())
          {
            T->setParent(nullptr);
            newSecond->setFirst(temp3);
            newSecond->setSecond(temp4);
            temp3->setParent(newSecond);
            temp4->setParent(newSecond);
            oldRoot->setThird(newSecond);
            newSecond->setParent(oldRoot);
            updateTree(newSecond);

            T->setThird(nullptr);
            T->setSecond(temp);
            T->setFirst(temp2);
            temp->setParent(T);
            updateTree(T);
            insertNode(T, oldRoot);

          }
          else if(temp->getKey() > temp3->getKey() && temp->getKey() < temp4->getKey())
          {
            newSecond->setFirst(temp);
            newSecond->setSecond(temp4);
            temp->setParent(newSecond);
            temp4->setParent(newSecond);
            updateTree(newSecond);

            T->setThird(nullptr);
            T->setSecond(temp3);
            T->setFirst(temp2);
            oldRoot->setThird(T);
            updateTree(T);
            insertNode(newSecond, oldRoot);

          }
          else
          {
            newSecond->setFirst(temp4);
            newSecond->setSecond(temp);
            temp->setParent(newSecond);
            temp4->setParent(newSecond);
            updateTree(newSecond);

            T->setThird(nullptr);
            T->setSecond(temp3);
            T->setFirst(temp2);
            oldRoot->setThird(T);
            updateTree(T);
            insertNode(newSecond, oldRoot);
          }
        }

      }
    }
  }
}

//Insert a node into the subTree T
void TwoThreeTree::insertNode(Node* temp, Node* T)
{

  Node* newRoot;
  Node* newParent;
  Node* oldParent = T->getParent();
  Node* first = T->getFirst();
  Node* second = T->getSecond();
  Node* third = T->getThird();


  if(T == root)
  {
    //If root  has no third child
    if(third == nullptr)
    {
      if(temp->getMinSecond() < first->getMinSecond())
      {
        T->setSecond(first);
        T->setThird(second);
        T->setFirst(temp);
        temp->setParent(T);
        updateTree(T);
      }
      else if(temp->getMinSecond() > first->getMinSecond() && temp->getMinSecond() < second->getMinSecond())
      {
        T->setThird(second);
        T->setSecond(temp);
        temp->setParent(T);
        updateTree(T);
      }
      else
      {
        T->setThird(temp);
        temp->setParent(T);
        updateTree(T);
      }
    }
    //Root has three children
    else
    {
      newRoot = new Node();
      newParent = new Node();
      //Determine whcih node to adopt and create a new parent node and a new root
      if(temp->getMinSecond() < first->getMinSecond())
      {
        T->setFirst(second);
        T->setSecond(third);
        T->setThird(nullptr);
        updateTree(T);
        first->setParent(nullptr);

        newParent->setFirst(temp);
        temp->setParent(newParent);
        newParent->setSecond(first);
        first->setParent(newParent);
        updateTree(newParent);

        newRoot->setFirst(newParent);
        newParent->setParent(newRoot);
        newRoot->setSecond(T);
        T->setParent(newRoot);
        root = newRoot;
        updateTree(root);
      }
      else if(temp->getMinSecond() > first->getMinSecond() && temp->getMinSecond() < second->getMinSecond())
      {
        T->setFirst(second);
        T->setSecond(third);
        T->setThird(nullptr);
        updateTree(T);
        first->setParent(nullptr);

        newParent->setFirst(first);
        first->setParent(newParent);
        newParent->setSecond(temp);
        temp->setParent(newParent);
        updateTree(newParent);

        newRoot->setFirst(newParent);
        newParent->setParent(newRoot);
        newRoot->setSecond(T);
        T->setParent(newRoot);
        root = newRoot;
        updateTree(root);
      }
      else if(temp->getMinSecond() > second->getMinSecond() && temp->getMinSecond() < third->getMinSecond())
      {
        T->setThird(nullptr);
        third->setParent(nullptr);
        updateTree(T);

        newParent->setFirst(temp);
        temp->setParent(newParent);
        newParent->setSecond(third);
        third->setParent(newParent);
        updateTree(newParent);

        newRoot->setFirst(T);
        T->setParent(newRoot);
        newRoot->setSecond(newParent);
        newParent->setParent(newRoot);
        root = newRoot;
        updateTree(root);
      }
      else
      {
        T->setThird(nullptr);
        third->setParent(nullptr);
        updateTree(T);

        newParent->setFirst(third);
        third->setParent(newParent);
        newParent->setSecond(temp);
        temp->setParent(newParent);
        updateTree(newParent);


        newRoot->setFirst(T);
        T->setParent(newRoot);
        newRoot->setSecond(newParent);
        newParent->setParent(newRoot);
        root = newRoot;
        updateTree(root);
      }
    }
  }
  //subTree T is not the root
  else
  {
    newParent = new Node();
    //Determine which node to adopt and make a new parent and make a new root
    if(temp->getMinSecond() < first->getMinSecond())
    {
      T->setFirst(second);
      T->setSecond(third);
      T->setThird(nullptr);
      updateTree(T);
      first->setParent(nullptr);

      newParent->setFirst(temp);
      temp->setParent(newParent);


    }
    else if(temp->getMinSecond() > first->getMinSecond() && temp->getMinSecond() < second->getMinSecond())
    {
      T->setFirst(second);
      T->setSecond(third);
      T->setThird(nullptr);
      updateTree(T);
      first->setParent(nullptr);

      newParent->setFirst(first);
      first->setParent(newParent);
      newParent->setSecond(temp);
      temp->setParent(newParent);

    }
    else if(temp->getMinSecond() > second->getMinSecond() && temp->getMinSecond() < third->getMinSecond())
    {
      T->setThird(nullptr);
      updateTree(T);
      third->setParent(nullptr);

      third->setParent(newParent);
      temp->setParent(newParent);
      newParent->setFirst(temp);
      newParent->setThird(third);

    }
    else
    {
      T->setThird(nullptr);
      updateTree(T);
      third->setParent(nullptr);

      third->setParent(newParent);
      temp->setParent(newParent);
      newParent->setFirst(third);
      newParent->setThird(temp);

    }

    updateTree(newParent);
    insertNode(newParent, oldParent);
  }
}

//Remove x from the subTree T
bool TwoThreeTree::remove(int x, Node* T)
{
  bool r = false;
  if(find(x, root) == nullptr)
  {
    cout << x << " is not in the tree." << endl;
  }
  else if(T == nullptr)
  {
    cout << "Tree is empty." << endl;
  }
  else if(T == root)
  {
    //If first child is a leaf node, determine which node to remove
    if(T->getFirst()->getTag() == 1)
    {

      if(T->getFirst() != nullptr && T->getSecond() == nullptr && T->getThird() == nullptr)
      {
        Node* temp = T->getFirst();
        T->setFirst(nullptr);
        temp->setParent(nullptr);
        delete temp;
        updateTree(root);
        root = nullptr;
        r = true;
      }
      else if(T->getFirst() != nullptr && T->getSecond() != nullptr && T->getThird() == nullptr)
      {
        if(T->getFirst()->getKey() == x)
        {
          Node* temp = T->getFirst();
          T->setFirst(T->getSecond());
          T->setSecond(nullptr);
          temp->setParent(nullptr);
          delete temp;
          updateTree(T);
          r = true;
        }
        else
        {
          Node* temp = T->getSecond();
          T->setSecond(nullptr);
          temp->setParent(nullptr);
          delete temp;
          updateTree(T);
          r = true;
        }
      }
      else
      {
        if(T->getFirst()->getKey() == x)
        {
          Node* temp = T->getFirst();
          T->setFirst(T->getSecond());
          T->setSecond(T->getThird());
          T->setThird(nullptr);
          temp->setParent(nullptr);
          delete temp;
          updateTree(T);
          r = true;
        }
        else if(T->getSecond()->getKey() == x)
        {
          Node* temp = T->getSecond();
          T->setSecond(T->getThird());
          T->setThird(nullptr);
          temp->setParent(nullptr);
          delete temp;
          updateTree(T);
          r = true;
        }
        else
        {
          Node* temp = T->getThird();
          T->setThird(nullptr);
          temp->setParent(nullptr);
          delete temp;
          updateTree(T);
          r = true;
        }
      }
    }
    //Children of root are interior nodes
    else
    {
      r = remove(find(x,root), find(x,root)->getParent());
    }
  }

  //subTree T is not the root
  else
  {
    r = remove(find(x, root), find(x, root)->getParent());
  }

  return r;
}

//Remove the value x in temp from the subTree T
bool TwoThreeTree::remove(Node* temp, Node* T)
{
  bool r = false;

  //If subTree has three children
  if(T->getThird() != nullptr)
  {
    if(T->getFirst() == temp)
    {

      T->setFirst(T->getSecond());
      T->setSecond(T->getThird());
      T->setThird(nullptr);
      temp->setParent(nullptr);
      delete temp;
      updateTree(T);
      r = true;
    }
    else if(T->getSecond() == temp)
    {
      T->setSecond(T->getThird());
      T->setThird(nullptr);
      temp->setParent(nullptr);
      delete temp;
      updateTree(T);
      r = true;
    }
    else
    {
      T->setThird(nullptr);
      temp->setParent(nullptr);
      delete temp;
      updateTree(T);
      r = true;
    }
  }
  //T has 2 children
  else
  {
    Node* parent = T->getParent();

    //If the parent has 3 children
    if(parent->getThird() != nullptr)
    {
      //If T is the first child of three
      if(parent->getFirst() == T)
      {
        Node* sibling = parent->getSecond();
        //If sibling has 3 children, adopt first child of sibling
        if(sibling->getThird() != nullptr)
        {
          Node* sibFirst = sibling->getFirst();
          sibling->setFirst(sibling->getSecond());
          sibling->setSecond(sibling->getThird());
          sibling->setThird(nullptr);
          updateTree(sibling);

          //If value to delete is first child of T
          if(T->getFirst() == temp)
          {
            T->setFirst(T->getSecond());
            T->setSecond(sibFirst);
            sibFirst->setParent(T);
            temp->setParent(nullptr);
            delete temp;
            r = true;
            updateTree(T);
          }
          //If value to delete is second child of T
          else
          {
            T->setSecond(sibFirst);
            sibFirst->setParent(T);
            temp->setParent(nullptr);
            delete temp;
            r = true;
            updateTree(T);
          }
        }
        //Sibling only has 2 children
        else
        {
          Node* first = T->getFirst();
          Node* second = T->getSecond();
          Node* sibFirst = sibling->getFirst();
          Node* sibSecond = sibling->getSecond();
          sibling->setSecond(sibFirst);
          sibling->setThird(sibSecond);

          //Give up second child to sibling
          if(temp == first)
          {
            sibling->setFirst(second);
            second->setParent(sibling);
            T->setFirst(nullptr);
            T->setSecond(nullptr);
            temp->setParent(nullptr);
            delete temp;
            r = true;
          }
          //Give up first child to sibling
          else
          {
            sibling->setFirst(first);
            first->setParent(sibling);
            T->setFirst(nullptr);
            T->setSecond(nullptr);
            temp->setParent(nullptr);
            delete temp;
            r = true;
          }

          //Update parent
          parent->setFirst(sibling);
          parent->setSecond(parent->getThird());
          parent->setThird(nullptr);
          T->setParent(nullptr);
          delete T;
          updateTree(sibling);
        }
      }

      //If T is the second child of three
      else if(parent->getSecond() == T)
      {
        Node* first = parent->getFirst();
        Node* third = parent->getThird();

        //First check right sibling if it has 3 children and adopt its first child if it does
        if(third->getThird() != nullptr)
        {
          Node* sibFirst = third->getFirst();
          third->setFirst(third->getSecond());
          third->setSecond(third->getThird());
          third->setThird(nullptr);
          sibFirst->setParent(nullptr);
          updateTree(third);

          //Value to remove is first child
          if(temp == T->getFirst())
          {
            T->setFirst(T->getSecond());
            T->setSecond(sibFirst);
            sibFirst->setParent(T);
            temp->setParent(nullptr);
            delete temp;
            r = true;
            updateTree(T);
          }

          //Value to remove is second child
          else
          {
            T->setSecond(sibFirst);
            sibFirst->setParent(T);
            temp->setParent(nullptr);
            delete temp;
            r = true;
            updateTree(T);
          }
        }

        //Look at left sibling
        else
        {
          //If it has 3 children, adopt its third child
          if(first->getThird() != nullptr)
          {
            Node* sibThird = first->getThird();
            first->setThird(nullptr);
            sibThird->setParent(nullptr);
            updateTree(first);

            if(temp == T->getFirst())
            {
              T->setFirst(sibThird);
              sibThird->setParent(T);
              temp->setParent(nullptr);
              delete temp;
              r = true;
              updateTree(T);
            }
            else
            {
              T->setSecond(T->getFirst());
              T->setFirst(sibThird);
              sibThird->setParent(T);
              temp->setParent(nullptr);
              delete temp;
              r = true;
              updateTree(T);
            }
          }

          //Else, give child up
          else
          {
            Node* giveUp;
            //If value to delete is first child
            if(temp == T->getFirst())
            {
              giveUp = T->getSecond();
              first->setThird(giveUp);
              giveUp->setParent(first);
              T->setFirst(nullptr);
              T->setSecond(nullptr);
              temp->setParent(nullptr);
              delete temp;
            }
            else
            {
              giveUp = T->getFirst();
              first->setThird(giveUp);
              giveUp->setParent(first);
              T->setFirst(nullptr);
              T->setSecond(nullptr);
              temp->setParent(nullptr);
              delete temp;
            }

            //Update parent node and delete this node
            parent->setSecond(parent->getThird());
            parent->setThird(nullptr);
            T->setParent(nullptr);
            delete T;
            updateTree(first);
            r = true;
          }
        }
      }

      //T is the third child of the tree
      else
      {
        Node* sibling = parent->getSecond();

        //If sibling has 3 children, adopt third child
        if(sibling->getThird() != nullptr)
        {
          Node* sibThird = sibling->getThird();
          sibling->setThird(nullptr);
          sibThird->setParent(nullptr);
          updateTree(sibling);

          //If value to delete is first child
          if(temp == T->getFirst())
          {
            T->setFirst(sibThird);
            sibThird->setParent(T);
            temp->setParent(nullptr);
            delete temp;
            r = true;
            updateTree(T);
          }
          else
          {
            T->setSecond(T->getFirst());
            T->setFirst(sibThird);
            sibThird->setParent(T);
            temp->setParent(nullptr);
            delete temp;
            r = true;
            updateTree(T);
          }
        }
        //Sibling has 2 children, give up child
        else
        {
          Node* giveUp;
          if(temp == T->getFirst())
          {
            giveUp = T->getSecond();
            sibling->setThird(giveUp);
            giveUp->setParent(sibling);
            T->setFirst(nullptr);
            T->setSecond(nullptr);
            temp->setParent(nullptr);
            delete temp;
          }
          else
          {
            giveUp = T->getFirst();
            sibling->setThird(giveUp);
            giveUp->setParent(sibling);
            T->setFirst(nullptr);
            T->setSecond(nullptr);
            temp->setParent(nullptr);
            delete temp;
          }

          //Update parent node and remove node
          parent->setThird(nullptr);
          T->setParent(nullptr);
          delete T;
          r = true;
          updateTree(sibling);
        }
      }
    }

    //If the parent has 2 children
    else
    {
      if(parent->getFirst() == T)
      {
        Node* sibling = parent->getSecond();

        //If sibling has 3 children, adopt first child
        if(sibling->getThird() != nullptr)
        {
          Node* sibFirst = sibling->getFirst();
          sibling->setFirst(sibling->getSecond());
          sibling->setSecond(sibling->getThird());
          sibling->setThird(nullptr);
          updateTree(sibling);

          if(temp == T->getFirst())
          {
            T->setFirst(T->getSecond());
            T->setSecond(sibFirst);
            sibFirst->setParent(T);
            temp->setParent(nullptr);
            delete temp;
            r = true;
            updateTree(T);
          }
          else
          {
            T->setSecond(sibFirst);
            sibFirst->setParent(T);
            temp->setParent(temp);
            delete temp;
            r = true;
            updateTree(T);
          }
        }
        //Sibling has 2 children, give up child
        else
        {
          Node* giveUp;
          Node* sibFirst = sibling->getFirst();
          Node* sibSecond = sibling->getSecond();
          sibling->setSecond(sibFirst);
          sibling->setThird(sibSecond);
          if(temp == T->getFirst())
          {
            giveUp = T->getSecond();
            sibling->setFirst(giveUp);
            giveUp->setParent(sibling);
            T->setFirst(nullptr);
            T->setSecond(nullptr);
            delete temp;
          }
          else
          {
            giveUp = T->getFirst();
            sibling->setFirst(giveUp);
            giveUp->setParent(sibling);
            T->setFirst(nullptr);
            T->setSecond(nullptr);
            delete temp;
          }

          //Update root
          T->setParent(nullptr);
          delete T;
          if(parent == root)
          {
            Node* old = root;
            old->setFirst(nullptr);
            old->setSecond(nullptr);
            sibling->setParent(nullptr);
            root = sibling;
            delete old;
            updateTree(sibling);
          }
          else
          {
            parent->setFirst(nullptr);
            parent->setSecond(nullptr);
            //Determine the parent of the original parent
            if(parent->getParent()->getFirst() == parent)
            {
              parent->getParent()->setFirst(sibling);
            }
            else if(parent->getParent()->getSecond() == parent)
            {
              parent->getParent()->setSecond(sibling);
            }
            else
            {
              parent->getParent()->setThird(sibling);
            }

            sibling->setParent(parent->getParent());
            parent->setParent(nullptr);
            delete parent;
            r = true;
            collapseTree(sibling->getParent());
          }
        }
      }
      //T is second child
      else
      {
        Node* sibling = parent->getFirst();

        //If sibling has 3 children, adopt first child
        if(sibling->getThird() != nullptr)
        {
          Node* sibThird = sibling->getThird();
          sibling->setThird(nullptr);
          updateTree(sibling);

          if(temp == T->getFirst())
          {
            T->setFirst(sibThird);
            sibThird->setParent(T);
            temp->setParent(nullptr);
            delete temp;
            r = true;
            updateTree(T);
          }
          else
          {
            T->setSecond(T->getFirst());
            T->setFirst(sibThird);
            sibThird->setParent(T);
            temp->setParent(temp);
            delete temp;
            r = true;
            updateTree(T);
          }
        }
        //Sibling has 2 children, give up child
        else
        {
          Node* giveUp;

          if(temp == T->getFirst())
          {
            giveUp = T->getSecond();
            sibling->setThird(giveUp);
            giveUp->setParent(sibling);
            T->setFirst(nullptr);
            T->setSecond(nullptr);
            delete temp;
          }
          else
          {
            giveUp = T->getFirst();
            sibling->setThird(giveUp);
            giveUp->setParent(sibling);
            T->setFirst(nullptr);
            T->setSecond(nullptr);
            delete temp;
          }


          T->setParent(nullptr);
          delete T;

          //Update root
          if(parent == root)
          {
            Node* old = root;
            old->setFirst(nullptr);
            old->setSecond(nullptr);
            sibling->setParent(nullptr);
            root = sibling;
            updateTree(root);
            delete old;
          }
          else
          {
            //Determine the parent of the original parent
            parent->setFirst(nullptr);
            parent->setSecond(nullptr);

            if(parent->getParent()->getFirst() == parent)
            {
              parent->getParent()->setFirst(sibling);
            }
            else if(parent->getParent()->getSecond() == parent)
            {
              parent->getParent()->setSecond(sibling);
            }
            else
            {
              parent->getParent()->setThird(sibling);
            }

            sibling->setParent(parent->getParent());
            parent->setParent(nullptr);
            delete parent;
            r = true;
            updateTree(sibling);
            collapseTree(sibling->getParent());
          }
        }
      }
    }
  }

  return r;
}

//Collapses a tree if unbalanced
void TwoThreeTree::collapseTree(Node* T)
{
  //If subTree has 2 children
  if(T->getThird() == nullptr)
  {
    Node* first = T->getFirst();
    Node* second = T->getSecond();

    //If first child is an interior node with leaves
    if(first->getFirst()->getTag() == 1)
    {
      //If second child has 3 children, make new interior node and adopt first child of second node
      if(second->getThird() != nullptr)
      {
        Node* sibFirst = second->getFirst();
        second->setFirst(second->getSecond());
        second->setSecond(second->getThird());
        second->setThird(nullptr);

        Node* newParent = new Node();
        newParent->setFirst(first);
        newParent->setSecond(sibFirst);
        first->setParent(newParent);
        sibFirst->setParent(newParent);
        T->setFirst(newParent);
        newParent->setParent(T);
        updateTree(newParent);
      }
      //If second child has 2 children
      else
      {
        second->setThird(second->getSecond());
        second->setSecond(second->getFirst());
        second->setFirst(first);
        first->setParent(second);

        if(T == root)
        {
          Node* old = root;
          old->setFirst(nullptr);
          old->setSecond(nullptr);
          second->setParent(nullptr);
          root = second;
          delete old;
          updateTree(root);
        }
        else
        {
          T->setFirst(nullptr);
          T->setSecond(nullptr);
          second->setParent(T->getParent());
          if(T->getParent()->getFirst() == T)
          {
            T->getParent()->setFirst(second);
          }
          else if(T->getParent()->getSecond() == T)
          {
            T->getParent()->setSecond(second);
          }
          else
          {
            T->getParent()->setThird(second);
          }

          T->setParent(nullptr);
          delete T;
          updateTree(second);
          collapseTree(second->getParent());
        }
      }
    }
    else
    {

      //If first child has 3 children, make new interior node and adopt third child of first node
      if(first->getThird() != nullptr)
      {
        Node* sibThird = first->getThird();
        first->setThird(nullptr);

        Node* newParent = new Node();
        newParent->setFirst(sibThird);
        newParent->setSecond(second);
        second->setParent(newParent);
        sibThird->setParent(newParent);
        T->setSecond(newParent);
        newParent->setParent(T);
        updateTree(newParent);
      }
      //If first child has 2 children
      else
      {
        first->setThird(second);
        second->setParent(first);

        if(T == root)
        {
          Node* old = root;
          old->setFirst(nullptr);
          old->setSecond(nullptr);
          first->setParent(nullptr);
          root = first;
          delete old;
          updateTree(root);
        }
        else
        {
          T->setFirst(nullptr);
          T->setSecond(nullptr);
          first->setParent(T->getParent());
          if(T->getParent()->getFirst() == T)
          {
            T->getParent()->setFirst(first);
          }
          else if(T->getParent()->getSecond() == T)
          {
            T->getParent()->setSecond(first);
          }
          else
          {
            T->getParent()->setThird(first);
          }

          T->setParent(nullptr);
          delete T;
          updateTree(first);
          collapseTree(first->getParent());
        }
      }
    }
  }
  //If subTree has 3 children, removing one will not change height
  else
  {
    Node* first = T->getFirst();
    Node* second = T->getSecond();
    Node* third = T->getThird();

    //If first child is an interior node with leaves
    if(first->getFirst()->getTag() == 1)
    {
      //If second child has 3 children, make new interior node and adopt first child of second node
      if(second->getThird() != nullptr)
      {
        Node* sibFirst = second->getFirst();
        second->setFirst(second->getSecond());
        second->setSecond(second->getThird());
        second->setThird(nullptr);

        Node* newParent = new Node();
        newParent->setFirst(first);
        newParent->setSecond(sibFirst);
        first->setParent(newParent);
        sibFirst->setParent(newParent);
        T->setFirst(newParent);
        newParent->setParent(T);
        updateTree(newParent);
      }
      //If second child has 2 children
      else
      {
        second->setThird(second->getSecond());
        second->setSecond(second->getFirst());
        second->setFirst(first);
        first->setParent(second);
        T->setFirst(second);
        T->setSecond(third);
        T->setThird(nullptr);
        updateTree(second);
      }
    }
    else if(second->getFirst()->getTag() == 1)
    {

      //If first child has 3 children, make new interior node and adopt third child of first node
      if(first->getThird() != nullptr)
      {
        Node* sibThird = first->getThird();
        first->setThird(nullptr);

        Node* newParent = new Node();
        newParent->setFirst(sibThird);
        newParent->setSecond(second);
        second->setParent(newParent);
        sibThird->setParent(newParent);
        T->setSecond(newParent);
        newParent->setParent(T);
        updateTree(newParent);
      }
      //If first child has 2 children
      else
      {
        first->setThird(second);
        second->setParent(first);
        T->setSecond(third);
        T->setThird(nullptr);
        updateTree(first);
      }
    }
    else
    {
      //If second child has 3 children, make new interior node and adopt third child of second node
      if(second->getThird() != nullptr)
      {
        Node* sibThird = second->getThird();
        second->setThird(nullptr);

        Node* newParent = new Node();
        newParent->setFirst(sibThird);
        newParent->setSecond(third);
        third->setParent(newParent);
        sibThird->setParent(newParent);
        T->setThird(newParent);
        newParent->setParent(T);
        updateTree(newParent);
      }
      //If second child has 2 children
      else
      {
        second->setThird(third);
        third->setParent(second);
        T->setThird(nullptr);
        updateTree(second);
      }
    }
  }
}

//Delete the minimum value from the tree
bool TwoThreeTree::deleteMin()
{
  return remove(findMin(root)->getKey(), findMin(root)->getParent());
}

//Deleete the maximum value from the tree
bool TwoThreeTree::deleteMax()
{
  return remove(findMax(root)->getKey(), findMax(root)->getParent());
}

//Find the minimum value of the tree recursively
Node* TwoThreeTree::findMin(Node* T)
{
  if(T->getFirst() != nullptr)
  {
    if(T->getFirst()->getTag() == 0)
    {
      return findMin(T->getFirst());
    }
    else
    {
      return T->getFirst();
    }
  }
  else
  {
    return nullptr;
  }
}

//Find the maximum value of the tree recursively
Node* TwoThreeTree::findMax(Node* T)
{
  if(T->getThird() != nullptr)
  {
    if(T->getThird()->getTag() == 0)
    {
      return findMax(T->getThird());
    }
    else
    {
      return T->getThird();
    }
  }
  else
  {
    if(T->getSecond() != nullptr)
    {
      if(T->getSecond()->getTag() == 0)
      {
        return findMax(T->getSecond());
      }
      else
      {
        return T->getSecond();
      }
    }
    else
    {
      return T->getFirst();
    }
  }
}

//Recursively print each leaf node of the tree
void TwoThreeTree::levelOrderPrint(Node* T)
{
  if(T != nullptr)
  {
    if(T->getFirst()->getTag() == 0)
    {
      levelOrderPrint(T->getFirst());
      levelOrderPrint(T->getSecond());
      levelOrderPrint(T->getThird());
    }
    else
    {
      if(T->getSecond() == nullptr)
      {
        cout << T->getFirst()->getKey() << endl;
      }
      else if(T->getThird() == nullptr)
      {
        if(findMax(root) != T->getSecond())
        {
          cout << T->getFirst()->getKey() << " " << T->getSecond()->getKey() << " | ";
        }
        else
        {
          cout << T->getFirst()->getKey() << " " << T->getSecond()->getKey() << endl;
        }
      }
      else
      {
        if(findMax(root) != T->getThird())
        {
          cout << T->getFirst()->getKey() << " " << T->getSecond()->getKey() << " " << T->getThird()->getKey() << " | ";
        }
        else
        {
           cout << T->getFirst()->getKey() << " " << T->getSecond()->getKey() << " " << T->getThird()->getKey() << endl;
        }
      }
    }
  }
}
