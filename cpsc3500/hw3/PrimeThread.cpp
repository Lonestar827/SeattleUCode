/**Author: Jared Callero
 *Program: PrimeThread.cpp (HW3-P6)
 */

#include <stdio.h>
#include <pthread>
using namespace std

struct args_t{

	int input;

}

bool isPrime(int number){
/*returns true if the number is a prime number
 *
 */

	if(number % 2 == 0) return false;
	else return true;

}

void *primeThread(void *arg){
/*Thread Function to find prime numbers
 *
 */

	args_t myargs = (args_t *) arg;

	int max = arg.input;
	//find prime number up to arg
	
	for(int i = 0; i < max; i++){
	
		if(isPrime(i)){
		
			cout << i << " "; 
		
		}
	
	}
	
	return NULL;


}

int main(int argc, char* argv[]){

	args_t input;
	pthread_t p;

	input.input = argsv[0];

	int rc = pthread_create(&p, NULL, primeThread, &input);

	return 0;

}
