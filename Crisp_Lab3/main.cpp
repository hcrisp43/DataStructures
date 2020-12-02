/*
*@file: main.cpp
*@author: Hunter Crisp
*@date: 24 September 2018
*/


#include "DoubleHash.h"
#include "QuadraticProbing.h"
#include <string>
#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
using namespace std;

int main(int argc, char* argv[])
{

  int choice = 0;
  int temp;

  DoubleHash dblHash;
  QuadraticProbing quadProbe;

  ifstream dataFile;
  dataFile.open(argv[1]);

  while(dataFile >> temp)
  {
    dblHash.insert(temp);
    quadProbe.insert(temp);
  }

  dataFile.close();

  while (choice != 5)
  {
    cout << "\nPlease choose a command: " << endl
    << "1: Insert" << endl
    << "2: Delete" << endl
    << "3: Find" << endl
    << "4: Print" << endl
    << "5: Exit" << endl
    << endl << "< ";
    cin >> choice;

    switch(choice)
    {
      case 1:
      {
        //Inserts a value into the list at the end

        cout << "Please give a value to insert: ";
        cin >> temp;
        if(quadProbe.insert(temp))
        {
          cout << temp << " was added to the hash table with quadratic probing." << endl;
        }
        else
        {
          cout << temp << " was not added to the hash table with quadratic probing." << endl;
        }

        if(dblHash.insert(temp))
        {
          cout << temp << " was added to the hash table with double hashing." << endl;
        }
        else
        {
          cout << temp << " was not added to the hash table with double hashing" << endl;
        }

        cout << setprecision(2) << "Load factor of the hash table with quadratic probing is: " << quadProbe.numElements / 53.0 << endl;
        cout << setprecision(2) << "Load factor of the hash table with double hashing is: " << dblHash.numElements / 53.0 << endl;

        break;
      }
      case 2:
      {
        //Searches for a value and attempts to remove it from the list

        cout << "Please give a value to delete: ";
        cin >> temp;

        if(quadProbe.deleteNode(temp))
        {
          cout << temp << " was removed from the hash table with quadratic probing." << endl;
        }
        else
        {
          cout << temp << " is not in the hash table with quadratic probing and was not deleted." << endl;
        }

        if(dblHash.deleteNode(temp))
        {
          cout << temp << " was removed from the hash table with double hashing" << endl;
        }
        else
        {
          cout << temp << " is not in the hash table with double hashing and was not deleted." << endl;
        }

        cout << setprecision(2) << "Load factor of the hash table with quadratic probing is: " << quadProbe.numElements / 53.0 << endl;
        cout << setprecision(2) << "Load factor of the hash table with double hashing is: " << dblHash.numElements / 53.0 << endl;
        break;
      }

      case 3:
      {
        //Find the element in the list
        cout << "Please give a value to find: ";
        cin >> temp;

        if(quadProbe.find(temp))
        {
          cout << temp << " is in the hash table with quadratic probing." << endl;
        }
        else
        {
          cout << temp << " is not in the hash table with quadratic probing." << endl;
        }

        if(dblHash.find(temp))
        {
          cout << temp << " is in the hash table with double hashing." << endl;
        }
        else
        {
          cout << temp << " is not in the hash table with double hashing" << endl;
        }
        break;
      }

      case 4:
      {
        //Prints each element in the list

        quadProbe.print();
        dblHash.print();
        break;
      }

      case 5:
      {
        //Closes the program and calls destructor to resolve any memory leaks
        return 0;
      }

      default:
      {
        //Handles wrong user input

        cout << "Please choose a correct value." << endl;
        break;
      }
    }
  cout << endl;
  }

return 0;
}
