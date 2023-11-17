CC= g++
CFLAGS = -c -pedantic -Wall -Werror

all:client

client: client.o hw3.o
	${CC} client.o hw3.o -o client

client.o:client.cpp
	${CC} ${CFLAGS} client.cpp

hw3.o:hw3.cpp hw3.h
	${CC} ${CFLAGS} hw3.cpp hw3.h

clean:
	rm -rf *.o client