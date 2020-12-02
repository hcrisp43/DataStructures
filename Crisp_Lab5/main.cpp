/*
*@file: main.cpp
*@Author: Hunter Crisp
*@date: 16 October 2018
*/

#include "BinarySearchTree.h"
#include "Node.h"
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  int temp = 0;
  int choice = 0;
  int choice2 = 0;
  ifstream dataFile;
  BinarySearchTree bst;
  cout << "data.txt elements: ";
  dataFile.open("data.txt");
  while(dataFile >> temp)
  {
    bst.insert(temp);
    cout << " " << temp;
  }
  dataFile.close();
  cout << endl;
  while(choice != 10)
  {
    cout << "\nPlease choose one of the following commands: \n"
    << "1- Insert\n"
    << "2- DeleteMin\n"
    << "3- DeleteMax\n"
    << "4- Delete\n"
    << "5- FindMin\n"
    << "6- FindMax\n"
    << "7- Preorder print\n"
    << "8- Inorder print\n"
    << "9- Postorder print\n"
    << "10- Exit\n" << ">";
    cin >> choice;
    switch (choice)
    {
      case 1:
      {
        cout << "\nPlease give the number you would like to insert:\n";
        cin >> choice2;
        bst.insert(choice2);
        cout << choice2 << " has been inserted." << endl;
        break;
      }

      case 2:
      {
        bst.deleteMin();
        break;
      }

      case 3:
      {
        bst.deleteMax();
        break;
      }

      case 4:
      {
        cout << "\nPlease give the number you would like to remove:\n";
        cin >> choice2;
        bst.remove(choice2);
        break;
      }

      case 5:
      {
        if(bst.findMin(bst.root) != nullptr)
        {
          cout << bst.findMin(bst.root)->getValue() << " is the smallest element." << endl;
        }
        else
        {
          cout << "Could not find smallest element." << endl;
        }
        break;
      }

      case 6:
      {
        if(bst.findMax(bst.root) != nullptr)
        {
          cout << bst.findMax(bst.root)->getValue() << " is the largest element." << endl;
        }
        else
        {
          cout << "Could not find the largest element." << endl;
        }
        break;
      }

      case 7:
      bst.preOrder();
      break;

      case 8:
      bst.inOrder();
      break;

      case 9:
      bst.postOrder();
      break;

      case 10:
      break;

      default:
      cout << "Invalid choice." << endl;
      break;
    }
 }

  return 0;
}
