output: main.o DLL.o Hash.o
	g++ main.o DLL.o Hash.o -o output


main.o: main.cpp
	g++ -c main.cpp

DLL.o: DLL.cpp DLL.h
	g++ -c DLL.cpp

Hash.o: Hash.cpp Hash.h
	g++ -c Hash.cpp

clean: 
	rm *.o output
