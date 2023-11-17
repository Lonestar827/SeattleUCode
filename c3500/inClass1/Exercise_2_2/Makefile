all: p1

p1: pthread_join.o pthread-data-sharing-mutex-strict-alternation.o pthread-data-sharing-mutex.o

	g++ -o pthread_join pthread_join.o -lpthread

	g++ -o pthread-data-sharing-mutex-strict-alternation pthread-data-sharing-mutex-strict-alternation.o -lpthread

	g++ -o pthread-data-sharing-mutex pthread-data-sharing-mutex.o -lpthread

pthread_join.o: pthread_join.cpp

	g++ -c pthread_join.cpp 

pthread-data-sharing-mutex-strict-alternation.o: pthread-data-sharing-mutex-strict-alternation.cpp

	g++ -c pthread-data-sharing-mutex-strict-alternation.cpp 

pthread-data-sharing-mutex.o: pthread-data-sharing-mutex.cpp

	g++ -c pthread-data-sharing-mutex.cpp 

clean:

	rm -rf *.o Exercise_2_2