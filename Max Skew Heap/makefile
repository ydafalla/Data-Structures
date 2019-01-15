output: main.o SkewHeap.o
	g++ main.o SkewHeap.o -o output


main.o: main.cpp
	g++ -c main.cpp

SkewHeap.o: SkewHeap.cpp SkewHeap.h
	g++ -c SkewHeap.cpp


clean:
	rm *.o output
