#include <iostream>
#include "MusicLibrary.h"
using namespace std;

//default constructor
MusicLibrary::MusicLibrary()
{
    mOwner = "nobody";
    mFilename = "";
}

//add method: return true and insert Song if Song s title is not in mLibrary; false if title is a duplicate
bool MusicLibrary::add(Song s)
{
    size_t library_size = mLibrary.size();
    bool unique = false;
    
    for (int i = 0; i < library_size; i++){
        if (s.getTitle() != mLibrary[i].getTitle()){
            unique = true;
        }
    }
    if (unique = true){
        mLibrary.push_back(s);
    }
    return unique;
}

//remove method: return true and erase Song if the Song index is within the bounds (0-mLibrary.size()); false if index is out of bounds
bool MusicLibrary::remove(int index)
{ 
    size_t library_size = mLibrary.size();
    
    if (index >= 0 && index < library_size){
        mLibrary.erase(mLibrary.begin() + index);
        return true;
    }
    else{
        return false;
    }
}

//print method: output all the songs in mLibrary
void MusicLibrary::print() const
{
    size_t library_size = mLibrary.size();
    
    for (int index = 0; index < library_size; index++){
        cout << mLibrary[index] << endl;
    }
}