lab1: main.o DoublyLinkedList.o Node.o
	g++ -g -std=c++11 -Wall main.o DoublyLinkedList.o Node.o -o lab1
main.o: main.cpp DoublyLinkedList.h Node.h
	g++ -g -std=c++11 -Wall -c main.cpp
DoublyLinkedList.o: DoublyLinkedList.h DoublyLinkedList.cpp
	g++ -g -std=c++11 -Wall -c DoublyLinkedList.cpp
Node.o: Node.h Node.cpp
	g++ -g -std=c++11 -Wall -c Node.cpp

clean:
	rm *.o lab1
	echo clean done
