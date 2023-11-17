//Jared Callero
//PA5:

#include<iostream>
using namespace std;

struct MovieData{

    string title, genre, director, tagline;
    long id;
    int year, watchCount;

};

#ifndef MOVIE_H
#define MOVIE_H
class Movie{
    public:

        Movie();//default constructor

        Movie(string newTitle, string newGenre, string newDirector, string newTag, long newID, int newYear, int newWatch);//parameter constructor

        ~Movie();

        void printMovie();//prints the movie

        void printMovieBrief(); //prints just the ID and Movie

        MovieData getData();//returns the MovieData struct

        void watchMovie();
    private:
        MovieData data;
};
#endif //movie.h