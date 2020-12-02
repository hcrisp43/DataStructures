#include "SkewHeap.h"
#include <queue>
SkewHeap::SkewHeap()
{
	root = nullptr;
}

SkewHeap::~SkewHeap()
{
	removeHeap(root);
}

void SkewHeap::removeHeap(Node* subTree)
{
	if(subTree)
	{
		removeHeap(subTree->getLeft());
		removeHeap(subTree->getRight());
		delete subTree;
	}
}

bool SkewHeap::isEmpty()
{
	bool empty = false;
	if(root == nullptr)
	{
		empty = true;
	}
	return empty;
}

//Inserts a new value into the heap
void SkewHeap::insert(int key)
{
	Node* temp = new Node();
	temp->setValue(key);
	root = merge(root, temp);
}

//Deletes the root node
void SkewHeap::deleteMax()
{
	if(!isEmpty())
	{
		Node* temp = root;
		Node* leftTree = root->getLeft();
		Node* rightTree = root->getRight();
		root = merge(leftTree, rightTree);
		delete temp;
	}
}

//Merges two nodes together and returns the resulting heap
Node* SkewHeap::merge(Node* h1, Node* h2)
{
	Node* temp = nullptr;
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
		temp = h1;
		h1 = h2;
		h2 = temp;
	}

	if(h1->getRight() !=nullptr)
	{	
		temp = h1->getRight();
		h1->setRight(h1->getLeft());
		h1->setLeft(merge(temp, h2));
	}
	else
	{
		h1->setRight(h1->getLeft());
		h1->setLeft(h2);
	}
	
	return h1;
	
}

//Prints the Heap in level order
void SkewHeap::levelOrder()
{
	if(!isEmpty())
	{
		queue <Node*> printLevel;
		int nodeKey = 0;
		Node* temp = root;
		
		printLevel.push(root);
		int levelCount = 1;
		int nextCount = 0;
		while(!printLevel.empty())
		{
			temp = printLevel.front();
			printLevel.pop();
			levelCount--;
			nodeKey = temp->getValue();
			cout << nodeKey << " ";
			
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

void SkewHeap::preOrder()
{
	if(!isEmpty())
	{
		preOrderRecursive(root);
	}

	else
	{
		cout << "Heap is empty." << endl;
	}
}

void SkewHeap::preOrderRecursive(Node* subTree)
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

void SkewHeap::inOrder()
{
	if(!isEmpty())
	{
		inOrderRecursive(root);
	}

	else
	{
		cout << "Heap is empty." << endl;
	}
}

void SkewHeap::inOrderRecursive(Node* subTree)
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


void SkewHeap::postOrder()
{
	if(!isEmpty())
	{
		postOrderRecursive(root);
	}

	else
	{
		cout << "Heap is empty." << endl;
	}
}

void SkewHeap::postOrderRecursive(Node* subTree)
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