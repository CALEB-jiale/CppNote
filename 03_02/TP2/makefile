main: main.o Tree.o
	g++ -o main main.o Tree.o -Wall

main.o: main.cpp
	g++ -c main.cpp -Wall

Tree.o: Tree.cpp Tree.h
	g++ -c Tree.cpp -Wall

clean:
	rm rf *.o main