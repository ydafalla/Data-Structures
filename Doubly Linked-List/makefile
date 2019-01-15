output: main.o DLL.o
	g++ main.o DLL.o -o output


main.o: main.cpp
	g++ -c main.cpp

DLL.o: DLL.cpp DLL.h
	g++ -c DLL.cpp


clean: 
	rm *.o output
