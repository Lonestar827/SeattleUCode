/*Author:Jared Callero
 * Program: p2.cpp
 *
 */

#include "p2.h"
using namespace std;

int pthread_sleep(int seconds){
//*pthread_sleep(int seconds)
//
//

	pthread_mutex_t mutex;
	pthread_cond_t conditionvar;
	struct timespec timetoexpire;

	if(pthread_mutex_init(&mutex,NULL)){
	
		return -1;
	
	}
	if(pthread_cond_init(&conditionvar,NULL)){
	
		return -1;
	
	}

	timetoexpire.tv_sec = (unsigned int)time(NULL) + seconds;
	timetoexpire.tv_nsec = 0;

	return pthread_cond_timedwait(&conditionvar, &mutex, &timetoexpire);

}


void *producerN(void* arg){

	while(1)
	{
		printf("ProducerN Running\n");
		fflush(stdout);
		pthread_sleep(1);
		printf("ProducerN exiting\n");
		pthread_exit(NULL);
	}
	return NULL;
}

void *producerS(void* arg){

	while(1)
	{
		printf("ProducerS Running\n");
		fflush(stdout);
		pthread_sleep(1);
		printf("ProducerS exiting\n");
		pthread_exit(NULL);
	}
	return NULL;
}

void *consumer(void* arg){
	
	while(1)
	{
		printf("Consumer Running\n");
		fflush(stdout);
		pthread_sleep(1);
		printf("Consumer exiting\n");
		pthread_exit(NULL);
	}
	return NULL;
}

void *car(void* arg){

	return NULL;

}

int main(int argc, char** argv){

	//start each thread

	pthread_t producerN_t_id, producerS_t_id, consumer_t_id;
	int statusN, statusS;

	sem_init(&emptyN, 0, 10);
	sem_init(&emptyS, 0, 10);
	sem_init(&fullN, 0, 10);
	sem_init(&fullS, 0, 10);

	statusN = pthread_mutex_init(&mutexN, NULL);

	if(statusN != 0){

		perror("StatusN failed to initalize \n");
		fflush(stdout);
		exit(1);

	}

	statusS = pthread_mutex_init(&mutexS, NULL);

	if(statusS != 0){

		perror("StatusS failed to initalize \n");
		fflush(stdout);
		exit(1);

	}

	if( -1 == pthread_create(&producerN_t_id, NULL, producerN, NULL) ){

		perror("pthread_create");
		return -1;

	}

	if( -1 == pthread_create(&producerS_t_id, NULL, producerS, NULL) ){

		perror("pthread_create");
		return -1;

	}

	if( -1 == pthread_create(&consumer_t_id, NULL, consumer, NULL) ){

		perror("pthread_create");
		return -1;

	}

	while(1){

		printf("Main running\n");
		fflush(stdout);
		pthread_sleep(2);
		printf("Main ending\n");
		fflush(stdout);

		sem_destroy(&emptyN);
		sem_destroy(&emptyS);
		sem_destroy(&fullN);
		sem_destroy(&fullS);

		statusN = pthread_mutex_destroy(&mutexN);

		if(statusN != 0){

			perror("StatusN failed to destroy \n");
			fflush(stdout);
			exit(1);

		}

		statusS = pthread_mutex_destroy(&mutexS);

		if(statusS != 0){

			perror("StatusS failed to destroy \n");
			fflush(stdout);
			exit(1);

		}

		pthread_exit(NULL);
	}
}
