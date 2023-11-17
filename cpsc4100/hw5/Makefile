CC= g++
CFLAGS = -c -pedantic -Wall -Werror
DEBUGFLAGS = -g -o

all: islands word path

islands: islands.cpp
	${CC} ${CFLAGS} islands.cpp -o islands

word: word.cpp
	${CC} ${CFLAGS} word.cpp -o word

path: path.cpp
	${CC} ${CFLAGS} path.cpp -o path

debug: islandsDebug wordDebug pathDebug

islandsDebug: islands.cpp
	${CC}  ${DEBUGFLAGS} islands islands.cpp 

wordDebug: word.cpp
	${CC}  ${DEBUGFLAGS} word.cpp word

pathDebug: path.cpp
	${CC}  ${DEBUGFLAGS} path.cpp path