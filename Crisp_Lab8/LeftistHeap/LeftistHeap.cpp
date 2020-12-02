#include "LeftistHeap.h"
#include <queue>
using namespace std;

LeftistHeap::LeftistHeap()
{
	root = nullptr;
}

LeftistHeap::~LeftistHeap()
{
	removeHeap(root);
}

bool LeftistHeap::isEmpty()
{
	bool empty = false;
	if(root == nullptr)
	{
		empty = true;
	}
	return empty;
}

void LeftistHeap::removeHeap(Node* subTree)
{
	if(subTree != nullptr)
	{
		removeHeap(subTree->getLeft());
		removeHeap(subTree->getRight());
		delete subTree;
	}
}

//Insert a new value by merging onto the root
void LeftistHeap::insert(int key)
{
	Node* temp = new Node();
	temp->setValue(key);
	root = merge(root, temp);
}

//Delete the root of the heap
void LeftistHeap::deleteMax()
{
	if(!isEmpty())
	{
		Node* temp = root;
		Node* leftTree = root->getLeft();
		Node* rightTree = root->getRight();
		root = merge(leftTree, rightTree);
		delete temp;
	}
	else
	{
		cout << "Heap is empty." << endl;
	}
}

//Merge the two nodes
Node* LeftistHeap::merge(Node* h1, Node* h2)
{
	if(h1 == nullptr)
	{
		return h2;
	}
	else if(h2 == nullptr)
	{
		return h1;
	}
	else if(h1->getValue() < h2->getValue())
	{
		//Swap variables
		Node* temp = h1;
		h1 = h2;
		h2 = temp;
	}

	int leftRank = 0;
	int rightRank= 0;

	//Set right child of h1 the merge of its current right child and h2
	h1->setRight(merge(h1->getRight(), h2));
	adjustRank(h1);

	//Determine the ranks of the children of h1
	if(h1->getLeft() != nullptr)
	{
		leftRank = h1->getLeft()->getRank();
	}
	if(h1->getRight() != nullptr)
	{
		rightRank = h1->getRight()->getRank();
	}

	//If unbalanced, swap children
	if(leftRank < rightRank)
	{
		Node* temp2 = h1->getLeft();
		h1->setLeft(h1->getRight());
		h1->setRight(temp2);
	}

	return h1;

}

//Print level order
void LeftistHeap::levelOrder()
{
	if(!isEmpty())
	{
		queue <Node*> printLevel;
		int nodeKey = 0;
		Node* temp = root;
		
		printLevel.push(root);
		int levelCount = 1;
		int nextCount = 0;

		//Go until queue is empty
		while(!printLevel.empty())
		{
			//Pop the top element off and print its value
			temp = printLevel.front();
			printLevel.pop();
			levelCount--;
			nodeKey = temp->getValue();
			cout << nodeKey << " ";
			
			//Add its children to the queue if they exist and increase count
			if(temp->getLeft() != nullptr)
			{
				printLevel.push(temp->getLeft());
				nextCount++;
			}
			if(temp->getRight() != nullptr)
			{
				printLevel.push(temp->getRight());
				nextCount++;
			}

			//End of level, start a new line
			if(levelCount == 0)
			{
				cout << endl;
				levelCount = nextCount;
				nextCount = 0;
			}
		}
	}

	else
	{
		cout << "Heap is empty." << endl;
	}
	
}


//Print pre order if heap is not empty
void LeftistHeap::preOrder()
{
	if(!isEmpty())
	{
		preOrderRecursive(root);
	}
}


//Print pre order recursively
void LeftistHeap::preOrderRecursive(Node* subTree)
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

//Recursively print in order if Heap is not empty
void LeftistHeap::inOrder()
{
	if(!isEmpty())
	{
		inOrderRecursive(root);
	}
}

//Recursively Print in order
void LeftistHeap::inOrderRecursive(Node* subTree)
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

//Recursively print post order if heap is not empty
void LeftistHeap::postOrder()
{
	if(!isEmpty())
	{
		postOrderRecursive(root);
	}
}

//Recursively Print post order
void LeftistHeap::postOrderRecursive(Node* subTree)
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

//Adjust rank of subTree
void LeftistHeap::adjustRank(Node* subTree)
{
	//Get left and right ranks if they exist
	int leftRank = 0;
	int rightRank = 0;
	if(subTree->getLeft() != nullptr)
	{
		leftRank = subTree->getLeft()->getRank();
	}
	if(subTree->getRight() != nullptr)
	{
		rightRank = subTree->getRight()->getRank();
	}
	

	//Set the rank of subTree equal to the largest + 1
	if(leftRank > rightRank)
	{
		subTree->setRank(leftRank + 1);
	}
	else
	{
		subTree->setRank(rightRank + 1);
	}
	
}
