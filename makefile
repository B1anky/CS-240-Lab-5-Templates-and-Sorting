
# Here's the flag for C++11 support and a flag asking to be warned about
# everything. 
FLAGS = -Wall -Wno-sign-compare -std=c++11


all: Lab5 Lab5T

Lab5: Lab5.o Sorter.o Color.o
	g++ $(FLAGS) Lab5.o Sorter.o Color.o -o Lab5

Lab5T: Lab5T.o TSorter.o Color.o
	g++ $(FLAGS) Lab5T.o TSorter.o Color.o  -o Lab5T

Sorter.o: Sorter.cpp Sorter.h
	g++ $(FLAGS) -c Sorter.cpp -o Sorter.o

Lab5.o: Lab5.cpp Sorter.h
	g++ $(FLAGS) -c Lab5.cpp -o Lab5.o

TSorter.o: TSorter.cpp TSorter.h
	g++ $(FLAGS) -c TSorter.cpp -o TSorter.o

Lab5T.o: Lab5T.cpp TSorter.h
	g++ $(FLAGS) -c Lab5T.cpp -o Lab5T.o

Color.o: Color.cpp Color.h
	g++ $(FLAGS) -c Color.cpp -o Color.o

clean:
	rm -f *.o Lab5 TLab5

