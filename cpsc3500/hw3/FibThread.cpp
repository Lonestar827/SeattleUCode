/*
 *
 */

#include<vector>
#include<stdio.h>
#include<pthread.h>
using namespace std;

struct args_t_input{

	int size;

}

struct args_t_output{

	vector<int> array;

}

void *fibSequence(void *args){

	int result;
	args_t_input input = (*args_t_input) args;
	args_t_output *output = malloc(sizeof(args_t_output));

	output->array = new vector<int>();

	if(input->size == 0){
		output->array.pushback(1);
		return (void *) output;
	}else{

		output ->array.pushback(1);
		output ->array.pushback(1);

		for(int i < 2; i < input->size; i++){

			result  = output->array[i-2] + output->array[i-1];
			output->array.pushback(result);

		}

	}
	return (void *) output;	

}

int main(int argc, char *argv[]){

	args_t_input args;
	args_t_output *output;
	pthread_t p;

	args.size = argv[0];

	pthread_create(&p, NULL, fibSequence, &args);
	pthread_join(p, (void**) &output);

	int vSize = output->array.size();

	for(int i = 0; i < vSize; i++){

		cout << output->array[i];

	}

	return 0;

}
