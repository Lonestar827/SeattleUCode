#define MAX_RESOURCES 5
sem_t available_resources = MAX_RESOURCES;

int increase_count(int count){

	if(available_resources - count < 0){

		return -1;
	
	}

	else{
	
		for(int i = 0; i < count; i++)
			sem_post(availaable_resources);
		return 0;
	
	}

}

int decrease_count(int count){

	if(available_resources < count) return -1;
	else{
	
		for(int i = 0; i < count; i++) 
			sem_wait(available_resources);
		return 0;
	
	}

}

