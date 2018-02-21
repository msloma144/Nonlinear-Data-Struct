//
// Created by chari on 2/6/2018.
//
#include <string>
using namespace std;

#ifndef PRESIDENTS_DATE_H
#define PRESIDENTS_DATE_H


class Date {
public:
    Date();
    Date(string, string, string);
    string getDate() const;

private:
    string month;
    string day;
    string year;
};


#endif //PRESIDENTS_DATE_H
