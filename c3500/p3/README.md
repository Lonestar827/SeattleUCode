# Conway's Game of Life Player
## Coded by Jared Callero

# Files That should be included:
* p3.h and p3.cpp
* grid.h and grid.cpp
* Makefile with regular, debug, and clean build functions

# Testing
* Each thread has been tested well, with a few bugs listed down below

# Known Bugs
* The display thread sometimes prints out one more before exiting the program
  * Most likely something to do with the threads not immediately being killed by the pause menu.
* When running the project through valgrind,  pausing will sometimes lead to an uninteractive state where i have to shutdown the terminal being unable to even send the terminate signal
  * this is true for both the debug version and the regular version when ran through valgrind with the commmand 
  ```Bash
  valgrind -s -leak-check=full ./p3 [file]
  ```
  * No idea how that even works, maybe valgrind messes with signal stuff?