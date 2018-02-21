//
// Created by chari on 2/6/2018.
//
#include <string>
#include "Date.h"
using namespace std;

Date::Date(){
    this->month = "0";
    this->day = "0";
    this->year = "0";
}
Date::Date(string month, string day, string year) {
    this->month = month;
    this->day = day;
    this->year = year;
}
string Date::getDate() const{
    return month + " " + day + ", " + year;
}