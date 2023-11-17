//Jared Callero
//PA5:hash.h

#include"movie.h"
#include<iostream>
using namespace std;

struct MovieNode{

    long key = 0;
    Movie value;
    MovieNode* next = nullptr;

};

#ifndef HASH_H
#define HASH_H
class Hash{
    public:
        
        Hash();

        Hash(int newSize);

        ~Hash();

        void addToPlaylist(long key, Movie value); //add key-value pair to table

        bool watchMovie(long key);//"watches" a movie and ups the playcount by 1 if it exists on the table

        void removeMovie(long key);//removes the movie from the playlist

        void displayMovie(long key);//prints out the movie if it exists

        void displayAll();//displays all movies on the hash list

        void displayGenre(string genre); // displays the title and the id of al the movies in the genre

        long hashfunt(long key);

        void depopulate(MovieNode* &node);

    private:

        MovieNode* playlist;//array of movies
        int size;

};

#endif // hash.h