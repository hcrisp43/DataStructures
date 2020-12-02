#include "Node.h"
#include "LeftistHeap.h"
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	int temp = 0;
	int choice = 0;
	int input = 0;
	LeftistHeap maxLeft;
	ifstream dataFile;
	cout << "data.txt elements: ";
	dataFile.open("data.txt");
	while(dataFile >> temp)
	{
		maxLeft.insert(temp);
		cout << temp << " ";
	}
	dataFile.close();
	cout << endl;
	
	
	while(choice != 7)
	{
		cout << "\n\nPlease choose one of the following commands: \n" 
		<< "1- Insert\n" 
		<< "2- deleteMax\n"
		<< "3- Preorder\n" 
		<< "4- InOrder\n"
		<< "5- Postorder\n" 
		<< "6- LevelOrder\n" 
		<< "7- End\n" << "\n> ";
		cin >> choice;
		
		switch(choice)
		{
			case 1: 
				cout << "Please choose a value to input: ";
				cin >> input;
				cout << endl;
				maxLeft.insert(input);
			break;
			
			case 2:
				maxLeft.deleteMax();
			break;
			
			case 3:
				cout << "\nPreOrder: \n";
				maxLeft.preOrder();
			break;
			
			case 4:
				cout << "\nInOrder: \n";
				maxLeft.inOrder();
			break;

			case 5:
				cout << "\nPostorder: \n";
				maxLeft.postOrder();
			break;
			
			case 6:
				cout << "\nLevelOrder: \n";
				maxLeft.levelOrder();
			break;
		}
	}


	return 0;
}
