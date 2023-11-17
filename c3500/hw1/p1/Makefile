all: p1

p1: wgrep.o wzip.o wcat.o wunzip.o

	g++ -o wgrep wgrep.o

	g++ -o wzip wzip.o

	g++ -o wcat wcat.o

	g++ -o wunzip wunzip.o

wgrep.o: wgrep.cpp

	g++ -c wgrep.cpp

wzip.o: wzip.cpp

	g++ -c wzip.cpp

wcat.o: wcat.cpp

	g++ -c wcat.cpp

wunzip.o: wunzip.cpp

	g++ -c wunzip.cpp

clean:

	rm –rf *.o p1