#include "MaxMinHeap.h"
#include <array>
using namespace std;

MaxMinHeap::MaxMinHeap(int dataArray[], int m, int s)
{
	lastIndex = s;
	maxSize = m;
	maxMinHeap = dataArray;
	
}

void MaxMinHeap::buildHeap()
{
	for(int j = lastIndex; j >= 1; j--)
	{
		heapify(j);
	}
}


bool MaxMinHeap::isEmpty()
{
	bool empty = false;
	if(lastIndex == 0)
	{
		empty = true;
	}
	
	return empty;
}

void MaxMinHeap::insert(int key)
{
	if(isEmpty())
	{
		maxMinHeap[1] = key;
		lastIndex = 2;
	}
	else if(lastIndex < maxSize)
	{
		int newIndex = lastIndex;
		maxMinHeap[newIndex] = key;
		heapify(newIndex);
		lastIndex++;
	}
}

void MaxMinHeap::heapify(int index)
{
	if((int)floor(log2(index)) % 2 == 0)
	{
		if(findParent(index) && maxMinHeap[index] < maxMinHeap[findParent(index)])
		{
			//If it is the left child of the parent, compare with right child if it exists and swap parent with smallest value
			if(index == findLeft(findParent(index)))
			{
				if(maxMinHeap[findRight(findParent(index))])
				{
					if(maxMinHeap[index] < maxMinHeap[findRight(findParent(index))])
					{
						int temp = maxMinHeap[findParent(index)];
						maxMinHeap[findParent(index)] = maxMinHeap[index];
						maxMinHeap[index] = temp;
						heapifyMin(findParent(index));
						return;
					}
					else
					{
						int temp = maxMinHeap[findParent(index)];
						int tempI = findRight(findParent(index));
						maxMinHeap[findParent(index)] = maxMinHeap[tempI];
						maxMinHeap[tempI] = temp;
						heapifyMin(findParent(index));
						return;
					}
				}
				else
				{
					int temp = maxMinHeap[findParent(index)];
					maxMinHeap[findParent(index)] = maxMinHeap[index];
					maxMinHeap[index] = temp;
					heapifyMin(findParent(index));
					return;
				}
			}
			//It is the right child, compare with the left child if it exists and swap parent with smallest value
			{
				if(maxMinHeap[findLeft(findParent(index))])
				{
					if(maxMinHeap[index] < maxMinHeap[findLeft(findParent(index))])
					{
						int temp = maxMinHeap[findParent(index)];
						maxMinHeap[findParent(index)] = maxMinHeap[index];
						maxMinHeap[index] = temp;
						heapifyMin(findParent(index));
						return;
					}
					else
					{
						int temp = maxMinHeap[findParent(index)];
						int tempI = findLeft(findParent(index));
						maxMinHeap[findParent(index)] = maxMinHeap[tempI];
						maxMinHeap[tempI] = temp;
						heapifyMin(findParent(index));
						return;
					}
				}
				else
				{
					int temp = maxMinHeap[findParent(index)];
					maxMinHeap[findParent(index)] = maxMinHeap[index];
					maxMinHeap[index] = temp;
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
	else
	{
		if(findParent(index) && maxMinHeap[index] > maxMinHeap[findParent(index)])
		{
			//If it is the left child of the parent, compare with right child if it exists and swap parent with largest value
			if(index == findLeft(findParent(index)))
			{
				if(maxMinHeap[findRight(findParent(index))])
				{
					if(maxMinHeap[index] > maxMinHeap[findRight(findParent(index))])
					{
						int temp = maxMinHeap[findParent(index)];
						maxMinHeap[findParent(index)] = maxMinHeap[index];
						maxMinHeap[index] = temp;
						heapifyMax(findParent(index));
						return;
					}
					else
					{
						int temp = maxMinHeap[findParent(index)];
						int tempI = findRight(findParent(index));
						maxMinHeap[findParent(index)] = maxMinHeap[tempI];
						maxMinHeap[tempI] = temp;
						heapifyMax(findParent(index));
						return;
					}
				}
				else
				{
					int temp = maxMinHeap[findParent(index)];
					maxMinHeap[findParent(index)] = maxMinHeap[index];
					maxMinHeap[index] = temp;
					heapifyMax(findParent(index));
					return;
				}
			}
			//It is the right child, compare with the left child if it exists and swap parent with largest value
			{
				if(maxMinHeap[findLeft(findParent(index))])
				{
					if(maxMinHeap[index] > maxMinHeap[findLeft(findParent(index))])
					{
						int temp = maxMinHeap[findParent(index)];
						maxMinHeap[findParent(index)] = maxMinHeap[index];
						maxMinHeap[index] = temp;
						heapifyMax(findParent(index));
						return;
					}
					else
					{
						int temp = maxMinHeap[findParent(index)];
						int tempI = findLeft(findParent(index));
						maxMinHeap[findParent(index)] = maxMinHeap[tempI];
						maxMinHeap[tempI] = temp;
						heapifyMax(findParent(index));
						return;
					}
				}
				else
				{
					int temp = maxMinHeap[findParent(index)];
					maxMinHeap[findParent(index)] = maxMinHeap[index];
					maxMinHeap[index] = temp;
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
}

//Compares index with its grandparent if it exists and swaps them if it is smaller
void MaxMinHeap::heapifyMin(int index)
{
	if(index > 3)
	{
		if(maxMinHeap[findGP(index)])
		{
			if(maxMinHeap[index] < maxMinHeap[findGP(index)])
			{
				int temp = maxMinHeap[findGP(index)];
				maxMinHeap[findGP(index)] = maxMinHeap[index];
				maxMinHeap[index] = temp;
				heapifyMin(findGP(index));
				return;
			}
		}
	}
	
}

//Compares index with its grandparent if it exists and swaps them if it is larger
void MaxMinHeap::heapifyMax(int index)
{
	if(index > 3)
	{
		if(maxMinHeap[findGP(index)])
		{
			if(maxMinHeap[index] > maxMinHeap[findGP(index)])
			{
				int temp = maxMinHeap[findGP(index)];
				maxMinHeap[findGP(index)] = maxMinHeap[index];
				maxMinHeap[index] = temp;
				heapifyMax(findGP(index));
				return;
			}
		}
	}
	
}

void MaxMinHeap::deleteMax()
{
	if(isEmpty())
	{
		cout << "Heap is empty." << endl;
	}

	//Remove last node in heap
	else if(lastIndex == 1)
	{
		maxMinHeap[1] = 0;
		cout << "Heap is now empty." << endl;
		lastIndex--;
	}

	//Make only child new root
	else if(lastIndex == 2)
	{
		maxMinHeap[1] = maxMinHeap[2];
		maxMinHeap[2] = 0;
		lastIndex--;
	}

	//Determine which is the largest child and make it the new root
	else if(lastIndex == 3)
	{
		if(maxMinHeap[2] > maxMinHeap[3])
		{
			maxMinHeap[1] = maxMinHeap[2];
			maxMinHeap[2] = maxMinHeap[3];
			maxMinHeap[3] = 0;
			lastIndex--;
			
		}
		else
		{
			maxMinHeap[1] = maxMinHeap[3];
			maxMinHeap[3] = 0;
			lastIndex--;
		}
	}

	//There are more than 3 elements in the heap
	else
	{
		//Grab the most recently added value
		int x = maxMinHeap[lastIndex];

		//Determine which of the 4 grandchildren of the root if they exist is the largest
		int s = maxMinHeap[4];
		if(maxMinHeap[5] != 0 && maxMinHeap[5] > s)
		{
			s = maxMinHeap[5];
		}
		if(maxMinHeap[6] != 0 && maxMinHeap[6] > s)
		{
			s = maxMinHeap[6];
		}
		if(maxMinHeap[7] != 0 && maxMinHeap[7] > s)
		{
			s = maxMinHeap[7];
		}

		//If the most recent value is greater than the largest grandchild of the root, make x the new root
		if(x >= s)
		{
			maxMinHeap[1] = x;
			maxMinHeap[lastIndex] = 0;
			lastIndex--;
		}

		//If the most recent value is greater than the largest grandchid of the root
		else
		{
			//Make the smallest grandchild value the new root
			maxMinHeap[1] = s;

			//If that grandchild was a left child's child
			if(s == maxMinHeap[4] || s == maxMinHeap[5])
			{
				//If the most recent value is greater than a child of the root, set grandchild value equal to new value
				if(x >= maxMinHeap[2])
				{
					
					maxMinHeap[4] == s ? maxMinHeap[4] = x: maxMinHeap[5] = x;
				}
				else
				{
					int temp = maxMinHeap[2];
					maxMinHeap[2] = x;
					maxMinHeap[4] == s ? maxMinHeap[4] = temp: maxMinHeap[5] = temp;
				}
			}
			//The grandchild was a right child's child
			else
			{
				//If the most recent value is greater than a child of the root, set grandchild value equal to new value
				if(x >= maxMinHeap[3])
				{
					
					maxMinHeap[6] == s ? maxMinHeap[6] = x: maxMinHeap[7] = x;
				}
				else
				{
					int temp = maxMinHeap[3];
					maxMinHeap[3] = x;
					maxMinHeap[6] == s ? maxMinHeap[6] = temp: maxMinHeap[7] = temp;
				}
			}

			//Remove most recent value and update last index
			maxMinHeap[lastIndex] = 0;
			lastIndex--;

			//Make sure heap satisfies conditions
			heapify(lastIndex);
		}
	}
}

void MaxMinHeap::deleteMin()
{
	if(isEmpty())
	{
		cout << "Heap is empty." << endl;
	}
	else if(lastIndex == 1)
	{
		cout << "Heap is now empty." << endl;
		maxMinHeap[1] = 0;
		lastIndex--;
	}
	else if(lastIndex == 2)
	{
		maxMinHeap[2] = 0;
		lastIndex--;
	}
	else if(lastIndex == 3)
	{
		if(maxMinHeap[2] < maxMinHeap[3])
		{
			maxMinHeap[2] = maxMinHeap[3];
			maxMinHeap[3] = 0;
			lastIndex--;
		}
		else
		{
			maxMinHeap[3] = 0;
			lastIndex--;
		}
	}
	else
	{
		int x = maxMinHeap[lastIndex];

		//Determine the smallest value of the heap
		int r = 2;
		if(maxMinHeap[3] < maxMinHeap[2])
		{
			r = 3;
		}

		//Replace smallest value with most recent value, then heapify from smallest child/grandchild
		maxMinHeap[r] = x;
		maxMinHeap[lastIndex] = 0;
		lastIndex--;

		//If there is no right child, heapify from left
		if(maxMinHeap[findLeft(r)])
		{
			int l = findLeft(r);
			if(maxMinHeap[findRight(r)])
			{
				l = findRight(r);
			}

			//If grandchildren exist, find the smallest
			int leftLeft = findLeft(findLeft(r));
			int leftRight = findLeft(findRight(r));
			int rightLeft = findRight(findLeft(r));
			int rightRight = findRight(findRight(r));

			if(maxMinHeap[leftLeft] && maxMinHeap[leftLeft] < maxMinHeap[l])
			{
				l = leftLeft;
			}
			if(maxMinHeap[leftRight] && maxMinHeap[leftRight] < maxMinHeap[l])
			{
				l = leftRight;
			}
			if(maxMinHeap[rightLeft] && maxMinHeap[rightLeft] < maxMinHeap[l])
			{
				l = rightLeft;
			}
			if(maxMinHeap[rightRight] && maxMinHeap[rightRight] < maxMinHeap[l])
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

void MaxMinHeap::levelOrder()
{
	if(!isEmpty())
	{
		cout << endl;
		int j = 1;
		for(int i = 1; i <= lastIndex; i++)
		{
			
			cout << maxMinHeap[i] << " ";
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


int MaxMinHeap::findParent(int x)
{
	return (floor(x/2));
}

int MaxMinHeap::findLeft(int x)
{
	return (2*x);
}

int MaxMinHeap::findRight(int x)
{
	return (2*x + 1);
}

int MaxMinHeap::findGP(int x)
{
	return (floor(x/4));
}

int MaxMinHeap::findMax()
{
	return maxMinHeap[1];
}

int MaxMinHeap::findMin()
{
	return maxMinHeap[2] < maxMinHeap[3] ? maxMinHeap[2]: maxMinHeap[3];
}