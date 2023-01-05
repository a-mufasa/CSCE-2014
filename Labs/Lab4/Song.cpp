#include <iostream>
#include "Song.h"

//defualt constructor
Song::Song()
{
    mTitle = "Viva la Vida";
    mComposer = "Coldplay";
    mArtist = "Coldplay";
    mPath = "/home/music/song101";
    mAlbum = "Viva la Vida or Death and All His Friends";
    mYear = 2008;
    mGenre = ROCK;
    mFormat = WMA;
}

//8 argument constructor
Song::Song(const string& title, const string& composer, const string& artist, const string& path, 
            const string& album, const unsigned int year, const Genre genre, const Format format)
{
    mTitle = title;
    mComposer = composer;
    mArtist = artist;
    mPath = path;
    mAlbum = album;
    mYear = year; 
    mGenre = genre;
    mFormat = format;
}

//Setter methods
void Song::setTitle(const string& title)
{
    mTitle = title;
}
void Song::setComposer(const string& composer)
{
    mComposer = composer;
}
void Song::setArtist(const string& artist)
{
    mArtist = artist;
}
void Song::setPath(const string& path)
{
    mPath = path;
}
void Song::setAlbum(const string& album)
{
    mAlbum = album;
}
void Song::setYear(const unsigned int year)
{
    mYear = year;
}
void Song::setGenre(const Genre genre)
{
    mGenre = genre;
}
void Song::setFormat(const Format format)
{
    mFormat = format;
}

//Getter methods
string Song::getTitle() const
{
    return mTitle;
}
string Song::getComposer() const
{
    return mComposer;
}
string Song::getArtist() const
{
    return mArtist;
}
string Song::getPath() const
{
    return mPath;
}
string Song::getAlbum() const
{
    return mAlbum;
}
unsigned int Song::getYear() const
{
    return mYear;
}
Genre Song::getGenre() const
{
    return mGenre;
}
Format Song::getFormat() const
{
    return mFormat;
}