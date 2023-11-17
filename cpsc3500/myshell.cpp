/*
Author:Jared Callero
Program: myshell.cpp

*/

#include <iostream>
#include <string>
#include<cstring>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include<sys/wait.h>
using namespace std;

int main(){

	//const char pipeDelim = '|';
	const char commandDelim = ' ';

	string userInput;
	char* cstringInput;
	//vector<string<string>> buf;
	

	int commandCount = 0;

	//present user with shell command "myshell$" and await input.

	cout << "myshell$";
	getline(cin, userInput);
	
	//get number of commands
	
	for(int i = 0; i < userInput.size(); i++){
	
		if(userInput[i] == ' ') commandCount++;
	
	}

	if(commandCount == 0) commandCount = 1;

	//convert the string to a list of arguments

	cstringInput = new char [userInput.length()+1];
	strcpy(cstringInput, userInput.c_str());

	char* args[commandCount+1]; 
	char* token = strtok(cstringInput, " ");
	int index = 0;
	
	while(token!=0){
	
		args[index] = token;
		index++;
		token = strtok(NULL, " ");
	
	}

	args[commandCount+1] = NULL;

	//begin forking

	pid_t pid = fork();
	
	if(pid < 0){
		//failed fork
		cout << "Fork Failed, please retry" << endl;
		return 1;
	
	}
	else if(pid == 0){
		//child process
		execvp(args[0], args);
	
	}else{
		//parent process
		int returnCode;

		waitpid(pid, &returnCode,0 );
		cout << "Process " << pid << " exits with " << returnCode <<  endl;	
	
	}
	
	return 0;
}
