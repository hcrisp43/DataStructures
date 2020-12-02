/*
*@file: BinarySearchTree.cpp
*@Author: Hunter Crisp
*@date: 16 October 2018
*/


#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree()
{
  root = nullptr;
}

BinarySearchTree::~BinarySearchTree()
{
  deleteTree(root);
}

//Recursively delete every node in the tree
void BinarySearchTree::deleteTree(Node* subTree)
{
  if(subTree != nullptr)
  {
    deleteTree(subTree->getLeft());
    deleteTree(subTree->getRight());
    delete subTree;
  }
}

//Recursively traverse a subTree to find the value x
Node* BinarySearchTree::search(int x, Node* subTree)
{
  if(isEmpty())
  {
    return nullptr;
  }
  else if(x == subTree->getValue())
  {
    return subTree;
  }

  else if(x < subTree->getValue())
  {
    if(subTree->getLeft() != nullptr)
    {
      return (search(x, subTree->getLeft()));
    }

    else
    {
      return nullptr;
    }
  }
  else if(x > subTree->getValue())
  {
    if(subTree->getRight() != nullptr)
    {
      return (search(x,subTree->getRight()));
    }

    else
    {
      return nullptr;
    }
  }
  return nullptr;

}

//Determine if the tree is empty or not
bool BinarySearchTree::isEmpty()
{
  bool empty = false;
  if(root == nullptr)
  {
    empty = true;
  }

  return empty;

}

//Insert a new node and use recursion when needed
void BinarySearchTree::insert(int x)
{
  Node* temp;
  if(isEmpty())
  {
    temp = new Node();
    temp->setValue(x);
    root = temp;
  }

  else if(x < root->getValue())
  {
    if(root->getLeft() != nullptr)
    {
      insertRecursive(x, root->getLeft());
    }
    else
    {
      temp = new Node();
      temp->setValue(x);
      root->setLeft(temp);
    }
  }
  else if(x > root->getValue() || x == root->getValue())
  {
    if(root->getRight() != nullptr)
    {
      insertRecursive(x, root->getRight());
    }
    else
    {
      temp = new Node();
      temp->setValue(x);
      root->setRight(temp);
    }
  }
}

//Recursively traverse until an empty spot is found and insert the value
void BinarySearchTree::insertRecursive(int x, Node* subTree)
{
  Node* temp;


  if(x < subTree->getValue())
  {
    if(subTree->getLeft() != nullptr)
    {
      insertRecursive(x, subTree->getLeft());
    }
    else
    {
      temp = new Node();
      temp->setValue(x);
      subTree->setLeft(temp);
    }
  }
  else if(x > subTree->getValue() || x == subTree->getValue())
  {
    if(subTree->getRight() != nullptr)
    {
      insertRecursive(x, subTree->getRight());
    }
    else
    {
      temp = new Node();
      temp->setValue(x);
      subTree->setRight(temp);
    }
  }
}

//Search for value and remove if it is in the tree
void BinarySearchTree::remove(int x)
{
  if(!isEmpty())
  {
    if(search(x, root)!= nullptr)
    {      
      removeRecursive(search(x, root));
      cout << x << " has been deleted." << endl;
    }

    else
    {
      cout << x << " was not deleted." << endl;
    }
  }

  else
  {
    cout << "Cannot delete from empty BST." << endl;
  }
  
}

//Remove the node from the tree
void BinarySearchTree::removeRecursive(Node* subTree)
{
  //If it has no children
  if(subTree->getLeft() == nullptr && subTree->getRight() == nullptr)
  {
    if(subTree == root)
    {
      delete root;
      root = nullptr;
    }

    //Look at left side of tree
    else if(subTree->getValue() < root->getValue())
    {
      int minVal = findMin(root)->getValue();

      //Find the parent node and remove the specified node
      for(int i = minVal; i < root->getValue(); i++)
      {
        if(search(i, root) != nullptr)
        {
          if(search(i, root)->getLeft() == subTree)
          {
            Node* temp = search(i,root);
            temp->setLeft(nullptr);
            delete subTree;
            return;
          }
          if(search(i, root)->getRight() == subTree)
          {
            Node* temp = search(i,root);
            temp->setRight(nullptr);
            delete subTree;
            return;
          }
        }
      }
    }

    //Look at right side of tree
    else
    {
      int maxVal = findMax(root)->getValue();

      //Find the parent node and remove the specified node
      for(int i = root->getValue(); i <= maxVal; i++)
      {
        if(search(i, root) != nullptr)
        {
          if(search(i, root)->getLeft() == subTree)
          {
            Node* temp = search(i,root);
            temp->setLeft(nullptr);
            delete subTree;
            return;
          }
          if(search(i, root)->getRight() == subTree)
          {
            Node* temp = search(i,root);
            temp->setRight(nullptr);
            delete subTree;
            return;
          }
        }
      }
    }
  }

  //If it contains a left child and no right child
  else if(subTree->getLeft() != nullptr && subTree->getRight() == nullptr)
  {
    //Look at left side of tree
    if(subTree->getValue() <= root->getValue())
    {
      int minVal = findMin(root)->getValue();

      //Find parent node and set parent left/right node equal to the left chld of the node to be removed 
      for(int i = minVal; i <= root->getValue(); i++)
      {
        if(search(i, root) != nullptr)
        {
          if(search(i, root)->getLeft() == subTree)
          {
            Node* temp = search(i, root);
            temp->setLeft(subTree->getLeft());
            subTree->setLeft(nullptr);
            delete subTree;
            return;
          }
          if(search(i, root)->getRight() == subTree)
          {
            Node* temp = search(i, root);
            temp->setRight(subTree->getLeft());
            subTree->setLeft(nullptr);
            delete subTree;
            return;
          }
        }
      }
    }

    //Look at the right side of the tree
    else
    {
      int maxVal = findMax(root)->getValue();

      //Find the parent node and set parent left/right node equal to the left child of the node to be removed
      for(int i = root->getValue(); i <= maxVal; i++)
      {
        if(search(i, root) != nullptr)
        {
          if(search(i, root)->getLeft() == subTree)
          {
            Node* temp = search(i , root);
            temp->setLeft(subTree->getLeft());
            subTree->setLeft(nullptr);
            delete subTree;
            return;
          }
          if(search(i, root)->getRight() == subTree)
          {
            Node* temp = search(i, root);
            temp->setRight(subTree->getLeft());
            subTree->setLeft(nullptr);
            delete subTree;
            return;
          }
        }
      }
    }
  }

  //If it has a right child and no left child
  else if(subTree->getLeft() == nullptr && subTree->getRight() != nullptr)
  {
    
    //Look at the left side of the tree
    if(subTree->getValue() <= root->getValue())
    {
      
      int minVal = findMin(root)->getValue();

      //Find the parent node and set parent left/right child equal to the right child of the node to be removed
      for(int i = minVal; i <= root->getValue(); i++)
      {
        if(search(i, root) != nullptr)
        {        
          if(search(i,root)->getLeft() == subTree)
          {
            Node* temp = search(i, root);
            temp->setLeft(subTree->getRight());
            subTree->setRight(nullptr);
            delete subTree;
            return;
          }
          if(search(i,root)->getRight() == subTree)
          {
            Node* temp = search(i, root);
            temp->setRight(subTree->getRight());
            subTree->setRight(nullptr);
            delete subTree;
            return;
          }
        }
      }
    }

    //Look at the right side of the tree
    else
    {
      int maxVal = findMax(root)->getValue();

      //Find the parent node and set the parent left/right child equal to the right child of the node to be removed
      for(int i = root->getValue(); i <= maxVal; i++)
      {
        if(search(i, root) != nullptr)
        {
          if(search(i, root)->getLeft() == subTree)
          {
            Node* temp = search(i , root);
            temp->setLeft(subTree->getRight());
            subTree->setRight(nullptr);
            delete subTree;
            return;
          }
          if(search(i, root)->getRight() == subTree)
          {
            Node* temp = search(i, root);
            temp->setRight(subTree->getRight());
            subTree->setRight(nullptr);
            delete subTree;
            return;
          }
        }
      }
    }
  }

  //The node has two children
  else
  {
    //Find the minimum of its right subtree
    Node* temp = findMin(subTree->getRight());

    Node* temp2 = subTree->getRight();

    //Find the parent node of the previously found node
    while(temp2->getLeft())
    {
      if(temp2->getLeft() == temp)
      {
        break;
      }
      temp2 = temp2->getLeft();
    }

    //If it has a right child, set the left point of the parent equal to this right child
    if(temp->getRight() != nullptr)
    {
      temp2->setLeft(temp->getRight());
      temp->setRight(nullptr);
    }
    else
    {
      temp2->setLeft(nullptr);
    }

    //Set value of original node equal to the minimum node found and remove the minimum node
    subTree->setValue(temp->getValue());
    
    delete temp;
    
  }
}

//Find the minimum value of a sub tree
Node* BinarySearchTree::findMin(Node* subTree)
{
  
  Node* temp = subTree;
  while(temp->getLeft())
  {
    temp = temp->getLeft();
  }

  if(temp != subTree)
  {
    return temp;
  }

  return subTree;
}

//Find the maximum value of a sub tree
Node* BinarySearchTree::findMax(Node* subTree)
{
  
  Node* temp = subTree;
  while(temp->getRight())
  {
    temp = temp->getRight();
  }

  if(temp != subTree)
  {
    return temp;
  }
  
  return subTree;
}

//Remove the minimum value of the tree
void BinarySearchTree::deleteMin()
{
  if(!isEmpty())
  {
    remove(findMin(root)->getValue());
  }
}

//Remove the maximum value of the tree
void BinarySearchTree::deleteMax()
{
  if(!isEmpty())
  {
    remove(findMax(root)->getValue());
  }
}

//Use recursion to pre order print
void BinarySearchTree::preOrder()
{
  if(!isEmpty())
  {
    preOrderRecursive(root);
  }
  else
  {
    cout << "BST is empty." << endl;
  }
}

void BinarySearchTree::preOrderRecursive(Node* subTree)
{
  if(subTree != nullptr)
  {
    cout << subTree->getValue() << " ";
    if(subTree->getLeft() != nullptr)
    {
      preOrderRecursive(subTree->getLeft());
    }
    if(subTree->getRight() != nullptr)
    {
      preOrderRecursive(subTree->getRight());
    }
  }
}

//use recursion to in order print
void BinarySearchTree::inOrder()
{
  if(!isEmpty())
  {
    inOrderRecursive(root);
  }
  else
  {
    cout << "BST is empty." << endl;
  }
}

void BinarySearchTree::inOrderRecursive(Node* subTree)
{

  if(subTree->getLeft() != nullptr)
  {
    inOrderRecursive(subTree->getLeft());
  }

  cout << subTree->getValue() << " ";

  if(subTree->getRight() != nullptr)
  {
    inOrderRecursive(subTree->getRight());
  }

}

//use recursion to post order print
void BinarySearchTree::postOrder()
{
  if(!isEmpty())
  {
    postOrderRecursive(root);
  }
  else
  {
    cout << "BST is empty." << endl;
  }
}

void BinarySearchTree::postOrderRecursive(Node* subTree)
{

  if(subTree->getLeft() != nullptr)
  {
    postOrderRecursive(subTree->getLeft());
  }

  if(subTree->getRight() != nullptr)
  {
    postOrderRecursive(subTree->getRight());
  }

  cout << subTree->getValue() << " ";
}
