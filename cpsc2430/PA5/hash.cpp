//Jared Callero
//PA5:

#include "hash.h"

Hash::Hash()
{

    playlist = new MovieNode[70];
    size = 0;
}

Hash::Hash(int newSize)
{

    size = newSize/0.7;
    playlist = new MovieNode[size];
    
}

Hash::~Hash(){

    //MovieNode* tmp;
    
    //for(int i = 0; i < size; i++){

        //if(playlist[i].key != 0){

            //tmp = &playlist[i];

            //depopulate(tmp);

        //}

    //}

}

void Hash::depopulate(MovieNode* &node){

    if(node->next != nullptr){

        depopulate(node->next);

    }
    delete node;

}

void Hash::addToPlaylist(long key, Movie value)
{

    long newHash;

    int chainCount = 0;

    MovieNode *newNode = new MovieNode();
    newNode->key = key;
    newNode->value = value;

    //use the key to make a hash

    newHash = hashfunt(key);

    //check the playlist to see if its empty, full, or tombstoned

    //if its empty or tombstoned:
    if (playlist[newHash].key == 0)
    {

        //set the key and value of the MovieNode to the current node
        playlist[newHash] = (*newNode);
    }
    //if the slot is full:
    else
    {

        //cycle through the slot until an empty spot is found with a traversal node
        MovieNode *tmp = &playlist[newHash];

        while (tmp->next != nullptr)
        {

            tmp = tmp->next;
            chainCount++;
        }

        tmp->next = newNode;
    }
}

bool Hash::watchMovie(long key)
{

    long newHash;

    //use the key to make a hash

    newHash = hashfunt(key);

    //if the slot at the hash is empty, return false and tell use it does not exist.
    if (playlist[newHash].key == 0)
    {
        cout << "Movie does not exist" << endl;
        return false;
    }
    else
    {
        //iterate through the spot using a traversal node
        MovieNode *tmp = &playlist[newHash];

        while (tmp != nullptr)
        {
            if (tmp->key == key)
            {
                //up watchcount by 1
                tmp->value.watchMovie();
                return true;
            }
            tmp = tmp->next;
        }

        return false;
    }
}

void Hash::removeMovie(long key)
{

    long newHash;
    bool isFound = false;

    //use the key to make a hash

    newHash = hashfunt(key);

    //if the spot is full,
    if (playlist[newHash].key != 0)
    {
        //iterate through the list using a traversal node

        MovieNode *tmp = &playlist[newHash];
        //check to see if the first slot is the search

        if (tmp->key == key)
        {
            playlist[newHash] = (*playlist[newHash].next);
            isFound = true;
            
        }
        //then check the rest
        while (tmp->next != nullptr && !isFound)
        {

            if (tmp->next->key == key)
            {
                //mark the next node
                MovieNode *victim = tmp->next;

                cout << "Victim set" << endl;

                isFound = true;

                //set the next of the current node to the one two ahead
                tmp->next = tmp->next->next;
                if(victim != nullptr){
                    delete victim;
                }

            }
            tmp = tmp->next;
        }
        //if the entire list is iterated through, tell user movie does not exist
        if (isFound)
        {
            cout << "Movie was deleted" << endl;
        }
        else
        {

            cout << "Movie was not found" << endl;
        }
    }
}
void Hash::displayMovie(long key)
{

    long newHash;
    bool movieFound = false;

    //use the key to make a hash

    newHash = hashfunt(key);

    //if the spot is empty
    if (playlist[newHash].key == 0)
    {

        //tell user movie does not exist
        cout << "Movie does not exist" << endl;
    }
    else
    {
        //iterate through the list using a traversal node

        MovieNode *tmp = &playlist[newHash];

        while (tmp != nullptr && !movieFound)
        {

            if (tmp->key == key)
            {
                movieFound = true;
            }
            else
            {
                tmp = tmp->next;
            }
        }
        if (movieFound)
        {
            tmp->value.printMovie();
        }
        else{

            cout << "Movie was not found" << endl;

        }
    }
}

void Hash::displayAll()
{

    MovieNode *tmp;

    for (long i = 0; i < size; i++)
    {

        if (playlist[i].key != 0)
        {
            tmp = &playlist[i];

            while (tmp != nullptr)
            {
                tmp->value.printMovieBrief();
                tmp = tmp->next;
            }
        }
    }
}

void Hash::displayGenre(string genre)
{

    MovieNode *tmp;

    for (int i = 0; i < size; i++)
    {

        if (playlist[i].key != 0)
        {
            tmp = &playlist[i];

            while (tmp != nullptr)
            {
                if (tmp->value.getData().genre == genre)
                {
                    tmp->value.printMovieBrief();
                }
                tmp = tmp->next;
            }
        }
    }
}

long Hash::hashfunt(long key)
{

    return key % size;
}