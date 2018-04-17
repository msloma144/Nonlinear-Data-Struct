//
// Created by chari on 3/26/2018.
//
#include <iostream>
#include <sstream>

using namespace std;

#ifndef BSTMOVIES_MOVIE_H
#define BSTMOVIES_MOVIE_H


class Movie {
protected:
    string title;
    int year;
    string rating;
    string length;
    string url;

public:
    Movie();
    Movie(string title, int year, string rating, string length, string url);
    ~Movie();

    bool operator ==(Movie &movie)const;
    bool operator <(Movie &movie)const;

    friend stringstream &operator<<(stringstream &os, const Movie &movie);
    string toString();
};


#endif //BSTMOVIES_MOVIE_H
