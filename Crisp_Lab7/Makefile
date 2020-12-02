lab7: main.o  MinMaxHeap.o MaxMinHeap.o
	g++ -g -std=c++11 -Wall main.o MinMaxHeap.o MaxMinHeap.o -o lab7
main.o: main.cpp MinMaxHeap.h MaxMinHeap.h
	g++ -g -std=c++11 -Wall -c main.cpp
MinMaxHeap.o: MinMaxHeap.h MinMaxHeap.cpp
	g++ -g -std=c++11 -Wall -c MinMaxHeap.cpp
MaxMinHeap.o: MaxMinHeap.h MaxMinHeap.cpp
	g++ -g -std=c++11 -Wall -c MaxMinHeap.cpp
clean:
	rm *.o lab7
	echo clean done
