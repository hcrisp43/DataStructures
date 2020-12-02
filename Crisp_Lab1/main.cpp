#include "DoublyLinkedList.h"
#include "Node.h"
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  DoublyLinkedList newList;
  int choice = 0;
  int i = 0;
  int j, temp;
  Node* addValue = nullptr;
  Node* removeValue = nullptr;
  int dataArray[] ={};
  ifstream dataFile;
  dataFile.open("dataFile.txt");
  while(dataFile)
  {
    dataFile >> j;
    cout << j << endl;
    dataArray[i] = j;
    i++;
  }
  dataFile.close();
  for(int n = 0; n < i; n++)
  {
    addValue = new Node();
    addValue->setValue(dataArray[n]);
    newList.insert(addValue);
  }

  while (choice != 5)
  {
    cout << "Please choose a command: " << endl
    << "1: Insert" << endl
    << "2: Delete" << endl
    << "3: Reverse" << endl
    << "4: Print" << endl
    << "5: Exit" << endl;
    cin >> choice;

    switch(choice)
    {
      case 1:
      {
        cout << "Please give a value to insert: ";
        cin >> temp;
        addValue->setValue(temp);
        newList.insert(addValue);
        break;
      }
      case 2:
      {
        cout << "Please give a value to delete: ";
        cin >> temp;
        removeValue->setValue(temp);
        if(newList.remove(removeValue))
        {
          cout << endl << removeValue << " successfully removed." << endl;
        }
        else
        {
          cout << endl << removeValue << " was not removed." << endl;
        }
        break;
      }
      case 3:
      {
        newList.reverse();
        break;
      }
      case 4:
      {
        newList.print();
        break;
      }
      case 5:
      {
        newList.~DoublyLinkedList();
        return 0;
      }

      default:
      {
        cout << "Please choose a correct value." << endl;
        break;
      }
    }

  }
  newList.~DoublyLinkedList();
  return 0;
}
