output: main.o Leftist.o
	g++ main.o Leftist.o -o output


main.o: main.cpp
	g++ -c main.cpp

Leftist.o: Leftist.cpp Leftist.h
	g++ -c Leftist.cpp


clean:
	rm *.o output
