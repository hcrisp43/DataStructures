/*
*@file: main.cpp
*@author: Hunter Crisp
*@date: 30 October 2018
*/

#include <iostream>
#include <fstream>
#include "TwoThreeTree.h"
#include "Node.h"
using namespace std;


int main()
{
	int newVal = 0;
	int choice = 0;
	TwoThreeTree newTree;

	ifstream dataFile;
	dataFile.open("data.txt");

	while(dataFile >> newVal)
	{
		newTree.insert(newVal, newTree.root);
	}

	dataFile.close();

	while(choice != 9)
	{
		cout << "\nPlease choose one of the following commands: \n"
	    << "1- Insert\n"
	    << "2- DeleteMin\n"
	    << "3- DeleteMax\n"
	    << "4- FindMin\n"
	    << "5- FindMax\n"
	    << "6- Find\n"
	    << "7- Delete\n"
	    << "8- Level Order Print\n"
	    << "9- Exit\n";

	    cin >> choice;

		switch(choice)
		{
			case 1:
			{
				cout << "\nEnter a number to be inserted: " << endl;
				cin >> newVal;
				newTree.insert(newVal, newTree.root);
				break;
			}
			case 2:
			{
				int min = newTree.findMin(newTree.root)->getKey();
				if(newTree.deleteMin())
				{
					cout << min << " was removed from the tree.\n";
				}
				else
				{
					cout << min << " was not removed from the tree.\n";
				}
				break;
			}
			case 3:
			{
				int max = newTree.findMax(newTree.root)->getKey();
				if(newTree.deleteMax())
				{
					cout << max << " was removed from the tree.\n";
				}
				else
				{
					cout << max << " was not removed from the tree.\n";
				}
				break;
			}
			case 4:
			{
				cout << "Minimum value: " << newTree.findMin(newTree.root)->getKey() << endl;
				break;
			}
			case 5:
			{
				cout << "Maximum value: " << newTree.findMax(newTree.root)->getKey()  << endl;
				break;
			}
			case 6:
			{
				cout << "\nEnter a number to be search: " << endl;
				cin >> newVal;
				newTree.find(newVal, newTree.root);
				break;
			}
			case 7:
			{
				cout << "\nEnter a number to be remove: " << endl;
				cin >> newVal;
				newTree.remove(newVal, newTree.root);
				break;
			}
			case 8:
			{
				newTree.levelOrderPrint(newTree.root);
				break;
			}
			case 9:
			{
				break;
			}
		}
	}
	return 0;
}
