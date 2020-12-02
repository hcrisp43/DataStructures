lab5: main.o BinarySearchTree.o Node.o
	g++ -g -std=c++11 -Wall main.o BinarySearchTree.o Node.o -o lab5
main.o: main.cpp BinarySearchTree.h Node.h
	g++ -g -std=c++11 -Wall -c main.cpp
BinarySearchTree.o: BinarySearchTree.h BinarySearchTree.cpp
	g++ -g -std=c++11 -Wall -c BinarySearchTree.cpp
Node.o: Node.h Node.cpp
	g++ -g -std=c++11 -Wall -c Node.cpp
clean:
	rm *.o lab5
	echo clean done
