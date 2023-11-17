/*Author: Jared Callero
 *Program: p2.h
 */


//Imports

#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
#include<queue>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//global variables

sem_t emptyN, emptyS, fullS, fullN;
pthread_mutex_t mutexN, mutexS;

//Threads

/*ProducerN(void *args)
 *Producer thread for the North lane. 
* Will have an 80 percecnt chance to spawn a car one after the other. On fail will wait 20 units.
 */
void *producerN(void *arg);

/*ProducerS()
 *Producer thread for the south lane. 
*Will have an 80 percecnt chance to spawn a car one after the other. On fail will wait 20 units.
 */
void *producerS(void *arg);

/**consumer()
 *Look to the north or south for cars. If there are cars to let them through
 if there are no cars, gol to sleep. 
 *
 */
void *consumer(void *arg);

/*void *car()
*Thread for the car, will record time of creation, time it starts moving, and time when it passes
*/
void *car(void *arg);

/*makes the thread wait for x seconds
*@param seconds - how many seconds you need it to wait
*/
int pthread_sleep(int seconds);

/*takes in a number for number of cars to pass before terminating
*/
int main(int argc, char** argv);
