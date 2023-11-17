/**Author: Jared Callero
* Program:
 *Purpose:
*/

#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char **argv) {

    if (argc == 1) {
        printf("wzip file1 [file2...]\n");
        return 1;
    }

    int charCount = 0;
    char currentChar, fileChar;
    char *fileName;
    fstream file;

    //open file specified
    for (int i = 1; i < argc; i++) {

        fileName = argv[i];
        file.open(fileName);
        if (file.is_open()) {

            file.get(currentChar);
            charCount++;

            while (file.get(fileChar)) {

                if (fileChar != currentChar) {
                    cout.write((char *) &charCount, sizeof(int));
                    cout.write(&currentChar, sizeof(char));
                    currentChar = fileChar;
                    charCount = 1;

                } else charCount++;

            }
            cout.write((char *) &charCount, sizeof(int));
            cout.write(&fileChar, sizeof(char));
            file.close();

        } else {
            file.close();
            printf("wzip: cannot open file\n");
            return 1;

        }

    }
    return 0;
}

/*Devnotes:
 * Reccomended System Calls: Open(), get(), close()
 *
 *use stdout for file
 */