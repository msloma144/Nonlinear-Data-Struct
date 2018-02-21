//
// Created by chari on 2/6/2018.
//
#include <string>
#include <iostream>
#include "President.h"

using namespace std;

President::President(string firstName, string middleName, string lastName,
                     string startMonth, string startDay, string startYear,
                     string endMonth, string endDay, string endYear,
                     string party, string state) {

    this->firstName = firstName;
    this->middleName = middleName;
    this->lastName = lastName;
    this->startDate = *(new Date(startMonth, startDay, startYear));
    this->endDate = *(new Date(endMonth, endDay, endYear));
    this->party = party;
    this->state = state;
}

const string &President::getFirstName() const {
    return firstName;
}

const string &President::getMiddleName() const {
    return middleName;
}

const string &President::getLastName() const {
    return lastName;
}

const Date &President::getStartDate() const {
    return startDate;
}

string President::getStartDateString() const {
    string date = startDate.getDate();
    return date;
}

const Date &President::getEndDate() const {
    return endDate;
}

string President::getEndDateString() const{
    return endDate.getDate();
}

const string &President::getParty() const {
    return party;
}

void President::setFirstName(const string &firstName) {
    President::firstName = firstName;
}

void President::setMiddleName(const string &middleName) {
    President::middleName = middleName;
}

void President::setLastName(const string &lastName) {
    President::lastName = lastName;
}

void President::setStartDate(const Date &date) {
    President::startDate = date;
}

void President::setEndDate(const Date &date) {
    President::endDate = date;
}

void President::setParty(const string &party) {
    President::party = party;
}

const string &President::getState() const {
    return state;
}

void President::setState(const string &state) {
    President::state = state;
}

string President::toString() const{
    string output = "First name: " + firstName + "\n"
            "Middle name: " + middleName + "\n"
            "Last name: " + lastName + "\n"
            "Start Term: " + startDate.getDate() + "\n"
            "End Term: " + endDate.getDate() + "\n"
            "Party: " + party + "\n"
            "State: " + state + "\n";
    return output;
}

string President::toStringFile() const{
    string output = firstName + "\n" +
            middleName + "\n" +
            lastName + "\n" +
            startDate.getDate() + "\n" +
            endDate.getDate() + "\n" +
            party + "\n" +
            state + "\n";
    return output;
}