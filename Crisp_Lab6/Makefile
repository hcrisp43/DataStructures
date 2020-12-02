lab6: main.o Node.o TwoThreeTree.o
	g++ -g -std=c++11 -Wall main.o  Node.o TwoThreeTree.o -o lab6
main.o: main.cpp Node.h TwoThreeTree.h
	g++ -g -std=c++11 -Wall -c main.cpp
Node.o: Node.h Node.cpp
	g++ -g -std=c++11 -Wall -c Node.cpp
TwoThreeTree.o: TwoThreeTree.h TwoThreeTree.cpp
	g++ -g -std=c++11 -Wall -c TwoThreeTree.cpp
clean:
	rm *.o lab6
	echo clean done
