/*Author: Jared Callero
 * Program: p3.cpp
 * Purpose: to facilitate Conways Game of Life through the provided class, signals, and threads
 */

#ifndef P3_P3_H
#define P3_P3_H

#include <iostream>
#include "grid.h"
#include <pthread.h>
#include <string>
#include <sys/signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <vector>
#include <string>

using namespace std;

//definitions and consts

const vector<string> pauseMenu = {"Q - Quit Program\n",
                                  "R - Resume Program\n",
                                  "S+ - Increase Simulation Rate by 1\n",
                                  "S- - Decrease Simulation rate by 1\n",
                                  "D+ - Increase Display Rate by 1\n",
                                  "D- - Decrease Display Rate by 1\n"};


//global variables

int simRate = 10;                                                    //the frame rate of the simulation, used for displaying at a specific speed
int displayRate = 10;                                               //the rate of the simulation, used to run the instance in the background

bool isRunning = true;

pthread_t simID;
pthread_t outputID;

pthread_mutex_t consoleMutex = PTHREAD_MUTEX_INITIALIZER;   //mutex for the console
pthread_mutex_t swapMutex = PTHREAD_MUTEX_INITIALIZER;      //mutex for the grid

//Dynamic Memory

Grid *workGrid;                                             //THe background grid
Grid *displayGrid;                                          //The display grid

pthread_t *threadArray;

//functions

/**
 *
 * @param signum can be SIGTSTP or SIGINT
 */
void signalHandler(int signum);

/**Advances through the game and updates the working grid
 *
 * @param args
 * @return
 */
void *simThread(void *args);

/**Updates the row assigned via args according to the rules of the game
 * @param args TO be cast into an int*
 */
void *rowUpdater(void *args);

/**Thread used to run and display The Game of Life
 *  Will loop the game until interrupted or stopped
 *
 *  @param args none
 */
void *outputThread(void *args);

/**Screen to bring up when the game is paused
 *
 * @param args
 */
void *pauseScreen(void *args);

/**Starting point of the program, used to set up threads
 * @param argc (argument count):needs to be two entries, otherwise will return 1
 * @param argv (argument vector): needs to be two accessable text files, otherwise will return 1
 * @return errorCode: will return 0 if there are no errors,\n
 * will return 1 for errors regarding arguments (Files, argument count)
 */
int main(int argc, char **argv);

#endif //P3_P3_H
