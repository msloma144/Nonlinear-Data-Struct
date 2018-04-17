//
// Created by chari on 3/26/2018.
//

#include "Movie.h"

Movie::Movie() {
    this->title = "NONE";
    this->year = 0000;
    this->rating = "NONE";
    this->length = "NONE";
    this->url = "NONE";
}

Movie::Movie(string title, int year, string rating, string length, string url) {
    this->title = title;
    this->year = year;
    this->rating = rating;
    this->length = length;
    this->url = url;
}

Movie::~Movie() {
    this->title = "NONE";
    this->year = -1;
    this->rating = "NONE";
    this->length = "NONE";
    this->url = "NONE";
}

bool Movie::operator==(Movie &movie) const {
    if(this->title == movie.title){
        if(this->year == movie.year){
            return true;
        }
    }
    return false;
}

bool Movie::operator<(Movie &movie) const {
    if(this->title == movie.title){
        return this->year < movie.year;;
    }
    else{
        int val = this->title.compare(movie.title);
        return val < 0;
    }
}

stringstream &operator<<(stringstream &os, const Movie &movie) {
    os << movie.title
       << "\n" << movie.year
       << "\n" << movie.rating
       << "\n" << movie.length
       << "\n" << movie.url << "\n";
    return os;
}

string Movie::toString() {
    string out = this->title
       + "\n" + to_string(this->year)
       + "\n" + this->rating
       + "\n" + this->length
       + "\n" + this->url + "\n";
    return out;
}
