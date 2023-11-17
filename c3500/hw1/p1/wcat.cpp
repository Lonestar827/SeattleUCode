/**Author: Jared Callero
* Program:
 *Purpose:
*/

#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char** argv){
    if(argc == 1) {
        printf("wcat file [file...]\n");
        return 1;
    }

    //Initialize Values
    char* fileName;
    fstream file;
    char toPrint;

    //open file specified
    for(int i = 1; i < argc; i++) {
        fileName = argv[i];
        file.open(fileName);
        if (file.is_open()) {

            while (file.get(toPrint)) {

                cout << toPrint;

            }

            cout << endl;
            file.close();

        } else {
            file.close();
            printf("wcat: cannot open file\n");
            return 1;
        }
    }

    return 0;
}

/*Devnotes:
 * Reccomended System Calls: Open(), get(), close()
 */