/**Author: Jared Callero
* Program:
 *Purpose:
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char **argv) {
    //TODO: Implement looping cat stuff
    if (argc == 1) {
        printf("wgrep: searchterm [file...]\n");
        return 1;
    }

    //Initialize Values
    char *fileName;
    char *wordToFind = argv[1];
    ifstream file;
    string toPrint;

    if (argc == 2) {

        while (true) {

            cin >> toPrint;
            if (toPrint.find(wordToFind) != string::npos) {
                cout << toPrint << endl;
                toPrint.clear();
            }

        }

    } else {
        for (int i = 2; i < argc; i++) {

            fileName = argv[i];
            file.open(fileName);

            if (file.is_open()) {

                while (getline(file, toPrint)) {

                    if (toPrint.find(wordToFind) != string::npos) {
                        cout << toPrint << endl;
                        toPrint.clear();
                    }
                }

                cout << endl;
                file.close();

            } else {
                file.close();
                printf("wgrep: cannot open file\n");
                return 1;
            }
        }
    }
}

/*Devnotes:
 * Reccomended System Calls: open(), getline(), close()
 */