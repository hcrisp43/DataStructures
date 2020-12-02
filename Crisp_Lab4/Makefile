lab4: main.o Node.o DoubleHash.o QuadraticProbing.o HashTable.o DoublyLinkedList.o
	g++ -g -std=c++11 -Wall main.o Node.o DoubleHash.o QuadraticProbing.o HashTable.o DoublyLinkedList.o -o lab4
main.o: main.cpp Node.h DoubleHash.h QuadraticProbing.h HashTable.h
	g++ -g -std=c++11 -Wall -c main.cpp
Node.o: Node.h Node.cpp
	g++ -g -std=c++11 -Wall -c Node.cpp
DoubleHash.o: DoubleHash.h DoubleHash.cpp
	g++ -g -std=c++11 -Wall -c DoubleHash.cpp
QuadraticProbing.o: QuadraticProbing.h QuadraticProbing.cpp
	g++ -g -std=c++11 -Wall -c QuadraticProbing.cpp
HashTable.o: HashTable.h HashTable.cpp
	g++ -g -std=c++11 -Wall -c HashTable.cpp
DoublyLinkedList.o: DoublyLinkedList.h DoublyLinkedList.cpp
	g++ -g -std=c++11 -Wall -c DoublyLinkedList.cpp
clean:
	rm *.o lab4
	echo clean done
