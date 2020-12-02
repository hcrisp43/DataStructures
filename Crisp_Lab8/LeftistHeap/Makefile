leftist: main.o LeftistHeap.o Node.o
	g++ -g -std=c++11 -Wall main.o LeftistHeap.o Node.o -o leftist
main.o: main.cpp LeftistHeap.h Node.h
	g++ -g -std=c++11 -Wall -c main.cpp
LeftistHeap.o: LeftistHeap.h LeftistHeap.cpp
	g++ -g -std=c++11 -Wall -c LeftistHeap.cpp
Node.o: Node.h Node.cpp
	g++ -g -std=c++11 -Wall -c Node.cpp
clean:
	rm *.o leftist
	echo clean done
