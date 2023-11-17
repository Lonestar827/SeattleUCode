//
// Created by Matthew Thayer on 1/13/22.
//

/*
 @file: pthreads_p2.cpp

 @author: student Jared Callero, jcallero@seattleu.edu
 @description: A program that demonstrates processes.
 @course: CPSC 3500
 @assignment: in-class activity [n]
 */

#include <pthread.h>
#include <iostream>
#include <cstring>

using namespace std;

int* input = new int(10);

/*prints the number of negatives within the provided argument
 * @param arg should be a void pointer that can be cast into an int array
 *
 */
void *countNegatives(void *arg)
{
    // TODO: Add code that implements
    //       the thread's functionality
    int totalNegs = 0;

    for(int i = 0; i <= 10; i++){

        if(input[i] < 0) totalNegs++;

    }

    cout << "Total negatives is " << totalNegs << endl;

    return 0;
}

/*prints out what the average value of the argument provided
 * @param arg should be a void pointer that can be cast into an int array
 */
void *average(void *arg)
{
    // TODO: Add code that implements
    //       the thread's functionality
    int total = 0;

    for(int i  = 0; i < 10; i++)total += input[i];

    total = total/10;

    cout << "The average is " << total << endl;
    return 0;
}

/*prints out the numbers in the argument in reverse order
 * @param arg should be a void pointer that can be cast into an int array
 */
void *reverse(void *arg)
{
    // TODO: Add code that implements
    //       the thread's functionality

    for(int i = 9; i >= 0; i--){

        cout << input[i] << endl;

    }
    return 0;
}

int main()
{
    // id is used to store a unique thread identifier,
    // returned by the call to create a new POSIX thread
    pthread_t negativeID;
    pthread_t averageID;
    pthread_t reverseID;
    
    memset(input, 0, 10);

    for(int i = 0; i < 10; i++){
        
        cin >> input[i];

    }

    for (int count = 0; count < 100000; count++);

    int rc;

    // Create thread(s)
    rc = pthread_create(&negativeID, NULL, countNegatives, NULL);

    if (rc){
        cout << "ERROR; return code from pthread_create() is " << rc << endl;
        return -1;
    }

    for (int count = 0; count < 100000; count++);

    rc = pthread_create(&averageID, NULL, average, NULL);

    if (rc){
        cout << "ERROR; return code from pthread_create() is " << rc << endl;
        return -1;
    }

    for (int count = 0; count < 100000; count++);

    rc = pthread_create(&reverseID, NULL, reverse, NULL);

    if (rc){
        cout << "ERROR; return code from pthread_create() is " << rc << endl;
        return -1;
    }

    for (int count = 0; count < 100000; count++);

    // NOTE: Using exit here will immediately end execution of all threads
    pthread_exit(0);
}


