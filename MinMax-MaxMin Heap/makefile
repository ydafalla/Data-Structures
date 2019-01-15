output: main.o MinMax.o MaxMin.o
				g++ main.o MinMax.o MaxMin.o -o output

main.o: main.cpp
				g++ -c main.cpp

MinMax.o: MinMax.cpp MinMax.h
				g++ -c MinMax.cpp

MaxMin.o: MaxMin.cpp MaxMin.h
				g++ -c MaxMin.cpp

clean:
				rm *.o output
