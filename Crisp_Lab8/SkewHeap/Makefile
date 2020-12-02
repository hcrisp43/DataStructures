skew: main.o SkewHeap.o Node.o
	g++ -g -std=c++11 -Wall main.o SkewHeap.o Node.o -o skew
main.o: main.cpp SkewHeap.h Node.h
	g++ -g -std=c++11 -Wall -c main.cpp
SkewHeap.o: SkewHeap.h SkewHeap.cpp
	g++ -g -std=c++11 -Wall -c SkewHeap.cpp
Node.o: Node.h Node.cpp
	g++ -g -std=c++11 -Wall -c Node.cpp
clean:
	rm *.o skew
	echo clean done
