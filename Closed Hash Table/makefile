
output: main.o DoubleHash.o Hash.o
	g++ main.o DoubleHash.o Hash.o -o output

main.o: main.cpp
	g++ -c main.cpp

Hash.o: Hash.cpp Hash.h
	g++ -c Hash.cpp

DoubleHash.o: DoubleHash.cpp DoubleHash.h
	g++ -c DoubleHash.cpp

clean:
	rm *.o output
