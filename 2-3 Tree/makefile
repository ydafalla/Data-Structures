output: main.o TwoThreeTree.o
				g++ main.o TwoThreeTree.o -o output

main.o: main.cpp
				g++ -c main.cpp

TwoThreeTree.o: TwoThreeTree.cpp TwoThreeTree.h
				g++ -c TwoThreeTree.cpp

clean:
				rm *.o output
