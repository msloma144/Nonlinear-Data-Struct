//
// Created by chari on 2/6/2018.
//

#include <string>
#include "Date.h"
using namespace std;

#ifndef PRESIDENTS_PRESIDENT_H
#define PRESIDENTS_PRESIDENT_H


class President {
public:
    President(string, string, string, string, string, string, string, string, string, string, string);

    const string &getFirstName() const;

    const string &getMiddleName() const;

    const string &getLastName() const;

    const Date &getStartDate() const;

    string getStartDateString() const;

    const Date &getEndDate() const;

    string getEndDateString() const;

    const string &getParty() const;

    const string &getState() const;

    void setFirstName(const string &firstName);

    void setMiddleName(const string &middleName);

    void setLastName(const string &lastName);

    void setStartDate(const Date &date);

    void setEndDate(const Date &date);

    void setParty(const string &party);

    void setState(const string &state);

    string toString() const;

    string toStringFile() const;

private:
    string firstName;
    string middleName;
    string lastName;
    Date startDate;
    Date endDate;
    string party;
    string state;
};


#endif //PRESIDENTS_PRESIDENT_H
