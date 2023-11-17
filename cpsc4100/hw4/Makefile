CC= g++
CFLAGS = -c -pedantic -Wall -Werror

all: rd1 rd2 chain

chain:chain.cpp
	${CC} ${CFLAGS} chain.cpp -o chain

rd2:rubydice2.cpp
	${CC} ${CFLAGS} rubydice2.cpp -o rubydice2

rd1:rubydice1.cpp
	${CC} ${CFLAGS} rubydice1.cpp -o rubydice1

clean:
	rm -rf *.o client