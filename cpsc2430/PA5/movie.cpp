//Jared Callero
//PA5:movie.cpp

#include"movie.h"
#include<iostream>
using namespace std;

Movie::Movie(){
        data.title = "";
        data.genre = "";
        data.director = "";
        data.tagline = "";
        data.id = 0;
        data.year = 0;
        data.watchCount = 0;
}

Movie::Movie(string newTitle, string newGenre, string newDirector, string newTag, long newID, int newYear, int newWatch){

        data.title = newTitle;
        data.genre = newGenre;
        data.director = newDirector;
        data.tagline = newTag;
        data.id = newID;
        data.year = newYear;
        data.watchCount = newWatch;

}

void Movie::printMovie(){

        cout << endl;
        cout << "ID:" << data.id << endl;
        cout << "Title:" << data.title << endl;
        cout << "Tagline:" << data.tagline << endl;
        cout << "Director:" << data.director << endl;
        cout << "Year:" << data.year << endl;
        cout << "Genre:" << data.genre << endl;
        cout << "WatchCount:" << data.watchCount << endl;
        cout << endl;

}

void Movie::watchMovie(){

        data.watchCount++;

}

void Movie::printMovieBrief(){

        cout << "ID: " << data.id << endl;
        cout << "Title: " << data.title << endl << endl;

}

Movie::~Movie(){

}

MovieData Movie::getData(){

        return data;

}
