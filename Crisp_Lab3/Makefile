lab3: main.o Node.o DoubleHash.o QuadraticProbing.o
	g++ -g -std=c++11 -Wall main.o Node.o DoubleHash.o QuadraticProbing.o -o lab3
main.o: main.cpp Node.h DoubleHash.h QuadraticProbing.h
	g++ -g -std=c++11 -Wall -c main.cpp
Node.o: Node.h Node.cpp
	g++ -g -std=c++11 -Wall -c Node.cpp
DoubleHash.o: DoubleHash.h DoubleHash.cpp
	g++ -g -std=c++11 -Wall -c DoubleHash.cpp
QuadraticProbing.o: QuadraticProbing.h QuadraticProbing.cpp
	g++ -g -std=c++11 -Wall -c QuadraticProbing.cpp
clean:
	rm *.o lab3
	echo clean done
