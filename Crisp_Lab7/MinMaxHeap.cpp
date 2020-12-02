#include "MinMaxHeap.h"
#include <array>
using namespace std;

MinMaxHeap::MinMaxHeap(int dataArray[], int m, int s)
{
	lastIndex = s;
	maxSize = m;
	minMaxHeap = dataArray;
	
}

void MinMaxHeap::buildHeap()
{
	for(int j = lastIndex; j >= 1; j--)
	{
		heapify(j);
	}
}


bool MinMaxHeap::isEmpty()
{
	bool empty = false;
	if(lastIndex == 0)
	{
		empty = true;
	}
	
	return empty;
}

void MinMaxHeap::insert(int key)
{
	if(isEmpty())
	{
		minMaxHeap[1] = key;
		lastIndex = 2;
	}
	else if(lastIndex < maxSize)
	{
		int newIndex = lastIndex;
		minMaxHeap[newIndex] = key;
		heapify(newIndex);
		lastIndex++;
	}
}

void MinMaxHeap::heapify(int index)
{
	if((int)floor(log2(index)) % 2 == 0)
	{
		if(findParent(index) && minMaxHeap[index] > minMaxHeap[findParent(index)])
		{
			//If it is the left child of the parent, compare with right child if it exists and swap parent with largest value
			if(index == findLeft(findParent(index)))
			{
				if(minMaxHeap[findRight(findParent(index))])
				{
					if(minMaxHeap[index] > minMaxHeap[findRight(findParent(index))])
					{
						int temp = minMaxHeap[findParent(index)];
						minMaxHeap[findParent(index)] = minMaxHeap[index];
						minMaxHeap[index] = temp;
						heapifyMax(findParent(index));
						return;
					}
					else
					{
						int temp = minMaxHeap[findParent(index)];
						int tempI = findRight(findParent(index));
						minMaxHeap[findParent(index)] = minMaxHeap[tempI];
						minMaxHeap[tempI] = temp;
						heapifyMax(findParent(index));
						return;
					}
				}
				else
				{
					int temp = minMaxHeap[findParent(index)];
					minMaxHeap[findParent(index)] = minMaxHeap[index];
					minMaxHeap[index] = temp;
					heapifyMax(findParent(index));
					return;
				}
			}
			//It is the right child, compare with the left child if it exists and swap parent with largest value
			{
				if(minMaxHeap[findLeft(findParent(index))])
				{
					if(minMaxHeap[index] > minMaxHeap[findLeft(findParent(index))])
					{
						int temp = minMaxHeap[findParent(index)];
						minMaxHeap[findParent(index)] = minMaxHeap[index];
						minMaxHeap[index] = temp;
						heapifyMax(findParent(index));
						return;
					}
					else
					{
						int temp = minMaxHeap[findParent(index)];
						int tempI = findLeft(findParent(index));
						minMaxHeap[findParent(index)] = minMaxHeap[tempI];
						minMaxHeap[tempI] = temp;
						heapifyMax(findParent(index));
						return;
					}
				}
				else
				{
					int temp = minMaxHeap[findParent(index)];
					minMaxHeap[findParent(index)] = minMaxHeap[index];
					minMaxHeap[index] = temp;
					heapifyMax(findParent(index));
					return;
				}
			}
		}
		else
		{
			heapifyMin(index);
			return;
		}
	}
	else
	{
		if(findParent(index) && minMaxHeap[index] < minMaxHeap[findParent(index)])
		{
			//If it is the left child of the parent, compare with right child if it exists and swap parent with smallest value
			if(index == findLeft(findParent(index)))
			{
				if(minMaxHeap[findRight(findParent(index))])
				{
					if(minMaxHeap[index] < minMaxHeap[findRight(findParent(index))])
					{
						int temp = minMaxHeap[findParent(index)];
						minMaxHeap[findParent(index)] = minMaxHeap[index];
						minMaxHeap[index] = temp;
						heapifyMin(findParent(index));
						return;
					}
					else
					{
						int temp = minMaxHeap[findParent(index)];
						int tempI = findRight(findParent(index));
						minMaxHeap[findParent(index)] = minMaxHeap[tempI];
						minMaxHeap[tempI] = temp;
						heapifyMin(findParent(index));
						return;
					}
				}
				else
				{
					int temp = minMaxHeap[findParent(index)];
					minMaxHeap[findParent(index)] = minMaxHeap[index];
					minMaxHeap[index] = temp;
					heapifyMin(findParent(index));
					return;
				}
			}
			//It is the right child, compare with the left child if it exists and swap parent with smallest value
			{
				if(minMaxHeap[findLeft(findParent(index))])
				{
					if(minMaxHeap[index] < minMaxHeap[findLeft(findParent(index))])
					{
						int temp = minMaxHeap[findParent(index)];
						minMaxHeap[findParent(index)] = minMaxHeap[index];
						minMaxHeap[index] = temp;
						heapifyMin(findParent(index));
						return;
					}
					else
					{
						int temp = minMaxHeap[findParent(index)];
						int tempI = findLeft(findParent(index));
						minMaxHeap[findParent(index)] = minMaxHeap[tempI];
						minMaxHeap[tempI] = temp;
						heapifyMin(findParent(index));
						return;
					}
				}
				else
				{
					int temp = minMaxHeap[findParent(index)];
					minMaxHeap[findParent(index)] = minMaxHeap[index];
					minMaxHeap[index] = temp;
					heapifyMin(findParent(index));
					return;
				}
			}
			
		}
		else
		{
			heapifyMax(index);
			return;
		}
	}
}

//Compares index with its grandparent if it exists and swaps them if it is smaller
void MinMaxHeap::heapifyMin(int index)
{
	if(index > 3)
	{
		if(minMaxHeap[findGP(index)])
		{
			if(minMaxHeap[index] < minMaxHeap[findGP(index)])
			{
				int temp = minMaxHeap[findGP(index)];
				minMaxHeap[findGP(index)] = minMaxHeap[index];
				minMaxHeap[index] = temp;
				heapifyMin(findGP(index));
				return;
			}
		}
	}
	
}

//Compares index with its grandparent if it exists and swaps them if it is larger
void MinMaxHeap::heapifyMax(int index)
{
	if(index > 3)
	{
		if(minMaxHeap[findGP(index)])
		{
			if(minMaxHeap[index] > minMaxHeap[findGP(index)])
			{
				int temp = minMaxHeap[findGP(index)];
				minMaxHeap[findGP(index)] = minMaxHeap[index];
				minMaxHeap[index] = temp;
				heapifyMax(findGP(index));
				return;
			}
		}
	}
	
}

void MinMaxHeap::deleteMin()
{
	if(isEmpty())
	{
		cout << "Heap is empty." << endl;
	}

	//Remove last node in heap
	else if(lastIndex == 1)
	{
		minMaxHeap[1] = 0;
		cout << "Heap is now empty." << endl;
		lastIndex--;
	}

	//Make only child new root
	else if(lastIndex == 2)
	{
		minMaxHeap[1] = minMaxHeap[2];
		minMaxHeap[2] = 0;
		lastIndex--;
	}

	//Determine which is the smallest child and make it the new root
	else if(lastIndex == 3)
	{
		if(minMaxHeap[2] < minMaxHeap[3])
		{
			minMaxHeap[1] = minMaxHeap[2];
			minMaxHeap[2] = minMaxHeap[3];
			minMaxHeap[3] = 0;
			lastIndex--;
			
		}
		else
		{
			minMaxHeap[1] = minMaxHeap[3];
			minMaxHeap[3] = 0;
			lastIndex--;
		}
	}

	//There are more than 3 elements in the heap
	else
	{
		//Grab the most recently added value
		int x = minMaxHeap[lastIndex];

		//Determine which of the 4 grandchildren of the root if they exist is the smallest
		int s = minMaxHeap[4];
		if(minMaxHeap[5] != 0 && minMaxHeap[5] < s)
		{
			s = minMaxHeap[5];
		}
		if(minMaxHeap[6] != 0 && minMaxHeap[6] < s)
		{
			s = minMaxHeap[6];
		}
		if(minMaxHeap[7] != 0 && minMaxHeap[7] < s)
		{
			s = minMaxHeap[7];
		}

		//If the most recent value is less than the smallest grandchild of the root, make x the new root
		if(x <= s)
		{
			minMaxHeap[1] = x;
			minMaxHeap[lastIndex] = 0;
			lastIndex--;
		}

		//If the most recent value is greater than the smallest grandchid of the root
		else
		{
			//Make the smallest grandchild value the new root
			minMaxHeap[1] = s;

			//If that grandchild was a left child's child
			if(s == minMaxHeap[4] || s == minMaxHeap[5])
			{
				//If the most recent value is less than a child of the root, set grandchild value equal to new value
				if(x <= minMaxHeap[2])
				{
					
					minMaxHeap[4] == s ? minMaxHeap[4] = x: minMaxHeap[5] = x;
				}
				else
				{
					int temp = minMaxHeap[2];
					minMaxHeap[2] = x;
					minMaxHeap[4] == s ? minMaxHeap[4] = temp: minMaxHeap[5] = temp;
				}
			}
			//The grandchild was a right child's child
			else
			{
				//If the most recent value is less than a child of the root, set grandchild value equal to new value
				if(x <= minMaxHeap[3])
				{
					
					minMaxHeap[6] == s ? minMaxHeap[6] = x: minMaxHeap[7] = x;
				}
				else
				{
					int temp = minMaxHeap[3];
					minMaxHeap[3] = x;
					minMaxHeap[6] == s ? minMaxHeap[6] = temp: minMaxHeap[7] = temp;
				}
			}

			//Remove most recent value and update last index
			minMaxHeap[lastIndex] = 0;
			lastIndex--;

			//Make sure heap satisfies conditions
			heapify(lastIndex);
		}
	}
}

void MinMaxHeap::deleteMax()
{
	if(isEmpty())
	{
		cout << "Heap is empty." << endl;
	}
	else if(lastIndex == 1)
	{
		cout << "Heap is now empty." << endl;
		minMaxHeap[1] = 0;
		lastIndex--;
	}
	else if(lastIndex == 2)
	{
		minMaxHeap[2] = 0;
		lastIndex--;
	}
	else if(lastIndex == 3)
	{
		if(minMaxHeap[2] > minMaxHeap[3])
		{
			minMaxHeap[2] = minMaxHeap[3];
			minMaxHeap[3] = 0;
			lastIndex--;
		}
		else
		{
			minMaxHeap[3] = 0;
			lastIndex--;
		}
	}
	else
	{
		int x = minMaxHeap[lastIndex];

		//Determine the largest value of the heap
		int r = 2;
		if(minMaxHeap[3] > minMaxHeap[2])
		{
			r = 3;
		}

		//Replace largest value with most recent value, then heapify from largest child/grandchild
		minMaxHeap[r] = x;
		minMaxHeap[lastIndex] = 0;
		lastIndex--;

		//If there is no right child, heapify from left
		if(minMaxHeap[findLeft(r)])
		{
			int l = findLeft(r);
			if(minMaxHeap[findRight(r)])
			{
				l = findRight(r);
			}

			//If grandchildren exist, find the largest
			int leftLeft = findLeft(findLeft(r));
			int leftRight = findLeft(findRight(r));
			int rightLeft = findRight(findLeft(r));
			int rightRight = findRight(findRight(r));

			if(minMaxHeap[leftLeft] && minMaxHeap[leftLeft] > minMaxHeap[l])
			{
				l = leftLeft;
			}
			if(minMaxHeap[leftRight] && minMaxHeap[leftRight] > minMaxHeap[l])
			{
				l = leftRight;
			}
			if(minMaxHeap[rightLeft] && minMaxHeap[rightLeft] > minMaxHeap[l])
			{
				l = rightLeft;
			}
			if(minMaxHeap[rightRight] && minMaxHeap[rightRight] > minMaxHeap[l])
			{
				l = rightRight;
			}

			heapify(l);
		}
		else
		{
			heapify(lastIndex);
		}

	}
}

void MinMaxHeap::levelOrder()
{
	if(!isEmpty())
	{
		cout << endl;
		int j = 1;
		for(int i = 1; i <= lastIndex; i++)
		{
			
			cout << minMaxHeap[i] << " ";
			if(i == pow(2,j)-1)
			{
				cout << endl;
				j++;
			}
			else
			{
				if((i+1)%2 == 0 && i+1 <= lastIndex)
				{
					cout << " | ";
				}
			}
		}

		cout << endl;
	}
	else
	{
		cout << "Heap is empty." << endl;
	}
}


int MinMaxHeap::findParent(int x)
{
	return (floor(x/2));
}

int MinMaxHeap::findLeft(int x)
{
	return (2*x);
}

int MinMaxHeap::findRight(int x)
{
	return (2*x + 1);
}

int MinMaxHeap::findGP(int x)
{
	return (floor(x/4));
}

int MinMaxHeap::findMin()
{
	return minMaxHeap[1];
}

int MinMaxHeap::findMax()
{
	return minMaxHeap[2] > minMaxHeap[3] ? minMaxHeap[2]: minMaxHeap[3];
}