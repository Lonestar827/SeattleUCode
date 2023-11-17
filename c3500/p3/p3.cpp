/*Author: Jared Callero
 * Program: p3.cpp
 * Purpose: to facilitate Conways Game of Life through the provided class, signals, and threads
 */

#include "p3.h"

int main(int argc, char **argv) {

    //signal Registering
    signal(SIGTSTP, signalHandler);//^Z
    signal(SIGINT, signalHandler);//^C

    //argument check

    if ((argc == 1) || (argc > 2)) { //if the number of arguments is 0 or greater then 2:

        printf("usage: p3 file1\n");
        return 1;

    }

    //initalize values
    fstream file;
    int gridHeight, gridWidth, threadCheck;

    //check file provided in argument
    file.open(argv[1]);

    if (file.is_open()) {//if file are valid,

        //make grids based off of file
        workGrid = new Grid(argv[1]);
        displayGrid = new Grid(workGrid->get_width(), workGrid->get_height());

        file.close();
    } else {//else send error

        file.close();
        printf("Invalid file, aborting game\n");
        return 1;

    }


    //set up threads for simulating and displaying

    threadCheck = pthread_create(&simID, NULL, simThread, NULL);
    if (threadCheck < 0) {

        printf("Thread Creation Failed, aborting!\n");
        return (1);

    }


    threadCheck = pthread_create(&outputID, NULL, outputThread, NULL);
    if (threadCheck < 0) {

        printf("Thread Creation Failed, aborting!\n");
        return (1);

    }

    //wait for threads to be over
    pthread_join(simID, NULL);
    pthread_join(outputID, NULL);

    //cleanup
    delete displayGrid;
    delete workGrid;
    delete threadArray;

    return 0;

}

void *outputThread(void *args) {
    while (isRunning) {
        pthread_mutex_lock(&swapMutex);

        pthread_mutex_lock(&consoleMutex);

        displayGrid->print();

        pthread_mutex_unlock(&consoleMutex);

        pthread_mutex_unlock(&swapMutex);

        sleep(1 / displayRate);
    }
    return 0;
}

void *simThread(void *args) {

    //initalize variables

    int gridHeight = displayGrid->get_height();

    threadArray = new pthread_t(displayGrid->get_height());
    while (isRunning) {

        //create a thread for each row
        for (int i = 0; i < gridHeight; i++) {

            pthread_create(&threadArray[i], NULL, rowUpdater, &i);

        }

        //wait for each thread to finish
        for (int i = 0; i < gridHeight; i++) {

            pthread_join(threadArray[i], NULL);

        }

        pthread_mutex_lock(&swapMutex);

        swap(workGrid, displayGrid);

        pthread_mutex_unlock(&swapMutex);

        sleep(1 / simRate);

    }

    return 0;
}

void *pauseScreen(void *args) {

    //initialize values
    string userInput; //user's input
    bool pauseLoop = true;

    printf("\nPAUSE BUTTON\n");


    pthread_mutex_lock(&consoleMutex);

    for (int i = 0; i < 6; i++) cout << pauseMenu[i];

    pthread_mutex_unlock(&consoleMutex);

    while (pauseLoop) {

        //print menu
        pthread_mutex_lock(&consoleMutex);

        cin >> userInput;

        pthread_mutex_unlock(&consoleMutex);

        if (userInput == "Q") {

            //quit program
            isRunning = false;

            //kill the two threads
            pthread_kill(simID, 0);
            pthread_kill(outputID, 0);

            pauseLoop = false;

        } else if (userInput == "R") {

            //resumes simulation
            pauseLoop = false;

        } else if (userInput == "S+") {

            simRate++;

            pthread_mutex_lock(&consoleMutex);

            cout << "Simrate: " << simRate << endl;

            pthread_mutex_unlock(&consoleMutex);

        } else if (userInput == "S-") {
            if(simRate == 1){
                pthread_mutex_lock(&consoleMutex);

                cout << "Cannot go lower, Simrate must be higher then 0" << endl;

                pthread_mutex_unlock(&consoleMutex);
            }
            else {
                simRate--;

                pthread_mutex_lock(&consoleMutex);

                cout << "Simrate: " << simRate << endl;

                pthread_mutex_unlock(&consoleMutex);
            }
        } else if (userInput == "D+") {

            displayRate++;

            pthread_mutex_lock(&consoleMutex);

            cout << "displayRate: " << displayRate << endl;

            pthread_mutex_unlock(&consoleMutex);

        } else if (userInput == "D-") {
            if(displayRate == 1){
                pthread_mutex_lock(&consoleMutex);

                cout << "Cannot go lower, displayRate must be higher then 0" << endl;

                pthread_mutex_unlock(&consoleMutex);
            }else {
                displayRate--;

                pthread_mutex_lock(&consoleMutex);

                cout << "displayRate: " << displayRate << endl;

                pthread_mutex_unlock(&consoleMutex);
            }
        } else {

            pthread_mutex_lock(&consoleMutex);

            for (int i = 0; i < 6; i++) cout << pauseMenu[i];

            pthread_mutex_unlock(&consoleMutex);

        }
    }

    return 0;
}

void signalHandler(int signum) {

    if (signum == SIGTSTP) {//if interrupt signal is recieved:

        pthread_t rc;

        //turn on mutex for grids
        pthread_mutex_lock(&swapMutex);
        //run pause menu thread
        pthread_create(&rc, NULL, pauseScreen, NULL);
        //wait for pause menu thread
        pthread_join(rc, NULL);

        pthread_mutex_unlock(&swapMutex);


    }

    if (signum == SIGINT) {//if terminating signal is recieved

        isRunning = false;

        pthread_mutex_lock(&consoleMutex);
        printf("\nTerminating Signal Recieved, exiting immediately\n");
        pthread_mutex_unlock(&consoleMutex);

        pthread_join(simID, NULL);
        pthread_join(outputID, NULL);

        //deallocate all dynamically assigned memory
        delete workGrid;
        delete displayGrid;
        delete threadArray;
        //exit with code 2
        exit(2);

    }

}

void *rowUpdater(void *args) {

    int *row = (int *) args;

    int gridWidth = displayGrid->get_width();

    for (int i = 0; i < gridWidth; i++) {

        workGrid->update_tile(*displayGrid, i, *row);
    }
    return 0;
}

