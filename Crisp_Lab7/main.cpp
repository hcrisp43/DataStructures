#include "MinMaxHeap.h"
#include "MaxMinHeap.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string.h>
using namespace std;

int main(int argc, char *argv[])
{
	int* dataArray = new int[500];
	
	ifstream dataFile;
	int i = 1;
	int temp = 0;
	int choice = 0;
	int choice2 = 0;
	
	cout << "data.txt elements: ";
	dataFile.open("data.txt");
	while(dataFile >> temp)
	{
		dataArray[i] = temp;
		cout << dataArray[i] << " ";
		i++;
	}
	dataFile.close();

	if(strcmp(argv[1], "minmax") == 0)
	{
		MinMaxHeap minMaxHeap(dataArray, 500, i-1);
		minMaxHeap.buildHeap();
		cout << endl;

		
		while(choice != 7)
		{
			cout << "\nPlease choose one of the following commands: \n"
			<< "1- Insert\n" 
			<< "2- DeleteMin\n"
			<< "3- findMin\n"
			<< "4- findMax\n" 
			<< "5- DeleteMax\n"
			<< "6- LevelOrder print\n" 
			<< "7- Exit\n" 
			<< ">";
			cin >> choice;

			switch (choice)
			{
				case 1: 
				{
					cout << "\nPlease give the number you would like to insert:\n";
					cin >> choice2;
					minMaxHeap.insert(choice2);
					break;
				}
	      
				case 2:
				{
					minMaxHeap.deleteMin();
					break;
				}

				case 3:
				{
					cout << "Min value: " << minMaxHeap.findMin() << endl;
					break;
				}

				case 4:
				{
					cout << "Max value: " << minMaxHeap.findMax() << endl;
					break;
				}
	   
				case 5:
				{
					minMaxHeap.deleteMax();
					break;
				}
	   
				case 6:
				{
					minMaxHeap.levelOrder();
					break;
				}
			}
		}
	}
	else if(strcmp(argv[1], "maxmin") == 0)
	{
		MaxMinHeap maxMinHeap(dataArray, 500, i-1);
		maxMinHeap.buildHeap();
		cout << endl;

		while(choice != 7)
		{
			cout << "\nPlease choose one of the following commands: \n"
			<< "1- Insert\n" 
			<< "2- DeleteMin\n"
			<< "3- findMin\n"
			<< "4- findMax\n" 
			<< "5- DeleteMax\n"
			<< "6- LevelOrder print\n" 
			<< "7- Exit\n" 
			<< ">";
			cin >> choice;

			switch (choice)
			{
				case 1: 
				{
					cout << "\nPlease give the number you would like to insert:\n";
					cin >> choice2;
					maxMinHeap.insert(choice2);
					break;
				}
		  
				case 2:
				{
					maxMinHeap.deleteMin();
					break;
				}

				case 3:
				{
					cout << "Min value: " << maxMinHeap.findMin() << endl;
					break;
				}

				case 4:
				{
					cout << "Max value: " << maxMinHeap.findMax() << endl;
					break;
				}

				case 5:
				{
					maxMinHeap.deleteMax();
					break;
				}

				case 6:
				{
					maxMinHeap.levelOrder();
					break;
				}
			}
		}
	}

	else
	{
		cout << "Incorrect argument." << endl;
	}
	

	delete[] dataArray;
	
	return 0;
}
