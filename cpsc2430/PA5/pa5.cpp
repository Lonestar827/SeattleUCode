//Jared Callero
//PA5:

#include"hash.h"
#include<fstream>
#include<iostream>
using namespace std;

void quickTest();

int main(){

    cout << endl << endl << endl;

    cout << "Welcome to the PA5 Program by Jared Callero:" << endl << endl;

    int fileSize = 100; //Will change for testing purposes
    
    ifstream file;
    file.open("movies.csv");

    Hash playlist = Hash(fileSize);

    string newID, newTitle, newGenre,newYear, newDirector,newRating, newTag;

    long realID;
    
    int realYear;

    Movie* newMovie = new Movie();

    getline(file,newID);

    while(getline(file,newID,',')){

        getline(file,newTitle,',');
        getline(file,newGenre,',');
        getline(file,newYear,',');
        getline(file,newDirector,',');
        getline(file,newRating,',');
        getline(file,newTag);
        
        realID = stol(newID);
        realYear = stoi(newYear);

        newMovie = new Movie(newTitle,newGenre,newDirector,newTag,realID,realYear,0);

        //addToPlaylist() test
        playlist.addToPlaylist(realID,(*newMovie));

    }

    file.close();

    bool userDone = false;

    string userInput;

    long playlistInput;

    while(!userDone){

      cout << "1. Browse all movies 2.Browse all movies of a selected Genre 3.Watch a movie 4.display the info of a movie 5.remove a movie from the list" << endl;
      cout << endl << "6. Quicktest: quickly tests every function using a smaller set of movies " << endl;
      cout << "0. end the program" << endl;
      cin>> userInput;

        if(userInput == "0"){

            userDone = true;

        }else if(userInput == "1"){

            playlist.displayAll();
            cout << endl;


        }else if(userInput == "2"){

            cout << "What Genre do you want to browse? (Case Sensitive)" << endl;
            cin >> userInput;
            playlist.displayGenre(userInput);

        }else if(userInput == "3"){

          cout << "What movie do you want to watch? Use the movie id: "<<endl;
            cin >> userInput;
            playlistInput = stol(userInput);
            if(playlist.watchMovie(playlistInput)){

                cout << "Movie Watched!" << endl;

            }else{

                cout << "Movie Not Found" << endl;

            }

        }else if(userInput == "4"){

        cout << "What movie to do you want info on?"<<endl;
        cin >> userInput;
            playlistInput = stol(userInput);
            playlist.displayMovie(playlistInput);

        }else if(userInput == "5"){

        cout << "What movie do you want to remove" << endl;
        cin >> userInput;
            playlistInput = stol(userInput);
            playlist.removeMovie(playlistInput);

        }else if(userInput == "6"){

            quickTest();

        }

    }

    cout << "Thank you for using the PA5 program! I hope you had a fun time teaching this quarter" << endl;

    cout << endl << endl << endl;

    return 0;

}

void quickTest(){

    cout << "Beginning Quicktest using 'movies-sample.csv" << endl;
    
    int fileSize = 12; //Will change for testing purposes

    ifstream file;
    file.open("movies-sample.csv");

    Hash playlist = Hash(fileSize);

    string newID, newTitle, newGenre,newYear, newDirector,newRating, newTag;

    long realID;
    
    int realYear;

    Movie* newMovie = new Movie();

    getline(file,newID);

    while(getline(file,newID,',')){

        getline(file,newTitle,',');
        getline(file,newGenre,',');
        getline(file,newYear,',');
        getline(file,newDirector,',');
        getline(file,newRating,',');
        getline(file,newTag);
        
        realID = stol(newID);
        realYear = stoi(newYear);

        newMovie = new Movie(newTitle,newGenre,newDirector,newTag,realID,realYear,0);

        //addToPlaylist() test
        playlist.addToPlaylist(realID,(*newMovie));

    }

    file.close();

    //displayAll() test
    cout << "displayAll() test:"<< endl;
    playlist.displayAll();

    //watchMovie() test, should return true

    cout<< "Attempting to watch Forest Gump (ID: 109830)" << endl;

    if(playlist.watchMovie(109830)){

        cout<< "Movie watched!" << endl;

    }else{

        cout << "Movie not found" << endl;

    }

    cout << endl;

    //watchMovie() test, should return false

    cout << "Attempting to watch Psycho (ID: 155975)" << endl;

    //155975

    if(playlist.watchMovie(155975)){

        cout<< "Movie watched!" << endl;

    }else{

        cout << "Movie not found" << endl;

    }

    cout << endl;

    //displayMovie() test, should print out movie

    cout << "Displaying movie with ID 68646" << endl;

    playlist.displayMovie(68646);

    cout << endl;

    
    //removeMovie() test

    cout << "Removing movie with ID 68646" << endl;

    playlist.removeMovie(68646);


    //displayMovie() w/ same id from removeMovie(), should print a rejection

    cout << "Attempting to display movie with ID 68646 again" << endl;

    playlist.displayMovie(68646);

    //displayGenre() test;

    cout << "Attempting to display all Crime genre movies" << endl;

    playlist.displayGenre("Crime");

    cout<< "Quicktest Over" << endl;

    cout << endl << endl << endl;

}
