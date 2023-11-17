all: p3

p3: p3.o grid.o

	g++ -o p3 p3.o grid.o -pthread

p3.o: p3.cpp p3.h

	g++ -c p3.cpp p3.h

grid.o: grid.cpp grid.h

	g++ -c grid.cpp grid.h

debug: p3c.o grid.o

	g++ -g -o p3c p3.o grid.o -pthread

p3c.o: p3.cpp p3.h

	g++ -g -c p3.cpp p3.h

clean:

	rm -rf *.o p3
	rm -rf *.h.gch