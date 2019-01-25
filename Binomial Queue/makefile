output: main.o BQ.o
	g++ main.o BQ.o -o output


main.o: main.cpp
	g++ -c main.cpp

BQ.o: BQ.cpp BQ.h
	g++ -c BQ.cpp


clean:
	rm *.o output
