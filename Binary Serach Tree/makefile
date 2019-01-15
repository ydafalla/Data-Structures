output: main.o BST.o
	g++ main.o BST.o -o output


main.o: main.cpp
	g++ -c main.cpp

BST.o: BST.cpp BST.h
	g++ -c BST.cpp


clean:
	rm *.o output
