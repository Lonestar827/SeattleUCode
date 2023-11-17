/**Author: Jared Callero
* Program:
 *Purpose:
*/

#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
using namespace std;

int main(int argc, char** argv){

    if (argc == 1) {
        printf("wunzip file1 [file2...]\n");
        return 1;
    }
    //Initialize Values

    int realCount = 0;
    char currentChar;
    char* fileName = argv[1];
    fstream file;
    ofstream newFile;

    file.open(fileName);
    if(file.is_open()){
        while(file.read((char*)&realCount, sizeof(int))) {
            file.read( &currentChar, sizeof(char));
            for (int i = 0; i < realCount; i++)cout.write(&currentChar, sizeof(char));
        }
        file.close();
        return 0;
    }else{
        file.close();
        printf("wunzip: cannot open file\n");
        return 1;

    }

}

/*Devnotes:
 * Reccomended System Calls: Open(), get(), close()
 */