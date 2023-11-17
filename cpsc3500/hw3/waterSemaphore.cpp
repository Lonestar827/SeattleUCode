
sem_t oxygen, hydrogen; // two Pthread semaphores

int main(int argc, char* argv[]) {
	//fill in your code to initialize two semaphores using sem_init()
	//hint: a counting semphore’s value represents # of resource instances

	sem_init(oxygen, 0, 0);
	sem_init(hydrogen, 0, 0);	
	
	int num_of_water = atoi(argv[1]); //# of water molecules 
	pthread_t tidox[num_of_water], tidhydro[2*num_of_water];
	//create hydrogen atom threads
	for (int k = 0; k < num_of_water; k++)
		pthread_create(&tidox[k], NULL, Oxygen, NULL);
	//create hydrogen atom threads
	for (int k = 0; k < 2*num_of_water; k++)
		pthread_create(&tidhydro[k], NULL, Hydrogen, NULL);

	for (int k = 0; k < 2*num_of_water; k++)
		pthread_join(tidhydro[k], NULL);
	for (int k = 0; k < num_of_water; k++)
		pthread_join(tidox[k], NULL);
	//fill in your code to destroy semaphores using sem_destroy()

	sem_destroy(oxygen);
	sem_destroy(hydrogen);

	return 0;
} 

void* Oxygen(void* arg) {
	//fill in your synchrooization code
	
	sem_post(oxygen);

	for(int i = 0; i < 2; i++)sem_wait(hydrogen);
	//check to see if theres 2 hydrogens
	pthread_exit(NULL);
	
	//if there are, detatch
} 

void* Hydrogen(void* arg) {
	//fill in your synchronization code
	
	sem_post(hydrogen);

	//check to see if theres an oxygen and one more hydrogen
	//if so, detatch. 
	
	if(hydrogen + 1 >= 2) sem_wait(oxygen);
	pthread_exit(NULL);

} 
