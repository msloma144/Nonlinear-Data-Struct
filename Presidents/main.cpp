#include <iostream>
#include <fstream>
#include <vector>
#include "President.h"

using namespace std;

vector<President> presidents;

void writeNewPresident(string firstName, string middleName, string lastName,
                       string start, string end, string party ,string state){
    string startMonth;
    string startDay;
    string startYear;

    string endMonth;
    string endDay;
    string endYear;

    startMonth = start.substr(0, start.find(" "));
    startDay = start.substr(start.find(" ") + 1, (start.find(",") - start.find(" ") - 1));
    startYear = start.substr(start.find(",") + 1);

    endMonth = end.substr(0, end.find(" "));
    endDay = end.substr(end.find(" ") + 1, (end.find(",") - end.find(" ") - 1));
    endYear = end.substr(end.find(",") + 1);

    presidents.emplace_back(firstName, middleName, lastName,
                            startMonth, startDay, startYear,
                            endMonth, endDay, endYear,
                            party, state);

}
void readFile(){
    ifstream inFile;
    inFile.open("./presidents.txt");
    string inLine;
    unsigned int count = 0;

    if(inFile.good()){
        string firstName;
        string middleName;
        string lastName;
        string start;
        string end;
        string party;
        string state;

        while (inFile && getline(inFile, inLine)){
            if(inLine.find("\r") != string::npos)
                inLine = inLine.substr(0, inLine.length() - 1);
            if(count == 7){
                writeNewPresident(firstName, middleName, lastName, start, end, party , state);

                firstName = "";
                middleName = "";
                lastName = "";
                start = "";
                end = "";
                party = "";
                state = "";
                count = 0;
            }

                switch (count) {
                    case 0:
                        firstName = inLine;
                        break;
                    case 1:
                        middleName = inLine;
                        break;
                    case 2:
                        lastName = inLine;
                        break;
                    case 3:
                        start = inLine;
                        break;
                    case 4:
                        end = inLine;
                        break;
                    case 5:
                        party = inLine;
                        break;
                    case 6:
                        state = inLine;
                        break;
                    default:
                        cout << "BAD BAD" << endl;
                        break;
                };
                count++;
        }
        writeNewPresident(firstName, middleName, lastName, start, end, party , state);
    }
    else{
        cout << "Bad File!";
        exit(EXIT_FAILURE);
    }

    inFile.close();
}

void listAll(){
    for(President person : presidents){
        cout << person.toString();
        cout << endl;
    }
}

void addNew(){
    string firstName;
    string middleName;
    string lastName;

    string startMonth;
    string startDay;
    string startYear;

    string endMonth;
    string endDay;
    string endYear;

    string party;
    string state;


    cout << "  ****NEW PRESIDENT****" << endl;
    cout << "Please enter first name: ";
    getline(std::cin, firstName);
    cout << "Please enter middle name: ";
    getline(std::cin, middleName);
    cout << "Please enter last name: ";
    getline(std::cin, lastName);
    cout << "Please enter start term month: ";
    getline(std::cin, startMonth);
    cout << "Please enter start term day: ";
    getline(std::cin, startDay);
    cout << "Please enter start term year: ";
    getline(std::cin, startYear);
    cout << "Please enter end term month: ";
    getline(std::cin, endMonth);
    cout << "Please enter end term day: ";
    getline(std::cin, endDay);
    cout << "Please enter end term year: ";
    getline(std::cin, endYear);
    cout << "Please enter party: ";
    getline(std::cin, party);
    cout << "Please enter state: ";
    getline(std::cin, state);
    cout << endl;

    presidents.emplace_back(firstName, middleName, lastName,
                            startMonth, startDay, startYear,
                            endMonth, endDay, endYear,
                            party, state);
}

void searchState(string state){
    for(President person : presidents){
        if(person.getState() == state){
            cout << person.toString();
            cout << endl;
        }
    }
}

void findPreceding(){
    string firstName;
    string middleName;
    string lastName;

    cout << "Please enter first name: ";
    getline(std::cin, firstName);
    cout << "Please enter middle name: ";
    getline(std::cin, middleName);
    cout << "Please enter last name: ";
    getline(std::cin, lastName);
    cout << endl;

    unsigned int count = 0;
    bool found;

    for(President person : presidents){
        if(person.getFirstName() == firstName && person.getMiddleName() == middleName &&
                person.getLastName() == lastName){
            found = true;
            break;
        }
        count++;
    }

    if(found && count > 0){
        cout << presidents.at(count - 1).toString();
        cout << endl;
    } else{
        cout << "****NONE FOUND****" << endl;
        cout << endl;
    }
}

void findNext(){
    string firstName;
    string middleName;
    string lastName;

    cout << "Please enter first name: ";
    getline(std::cin, firstName);
    cout << "Please enter middle name: ";
    getline(std::cin, middleName);
    cout << "Please enter last name: ";
    getline(std::cin, lastName);
    cout << endl;

    unsigned int count = 0;
    bool found;

    for(President person : presidents){
        if(person.getFirstName() == firstName && person.getMiddleName() == middleName &&
           person.getLastName() == lastName){
            found = true;
            break;
        }
        count++;
    }

    if(found && count + 1 < presidents.size()){
        cout << presidents.at(count + 1).toString();
        cout << endl;
    } else{
        cout << "****NONE FOUND****" << endl;
        cout << endl;
    }
}

void saveFile(){
    ofstream outFile;
    outFile.open("./presidents2.txt");
    for(President person : presidents){
        outFile << person.toStringFile();
    }
}

void menu(){
    string input;
    string choice;
    string option;

    cout << "********************Main Menu**********************" << endl;
    cout << "L​ - list all the presidents and their information." << endl;
    cout << "A​ - add a president.                              " << endl;
    cout << "F - print all the presidents from the given state." << endl;
    cout << "P - find and print the preceding president.       " << endl;
    cout << "N - find and print next president.                " << endl;
    cout << "Q​ - quit after saving file.                       " << endl;
    cout << "Please enter command: ";
    getline(cin, input);

    choice = input.at(0);
    if(input.length() > 1)
        option = input.substr(2);


    if(choice == "L"){
        listAll();
    }
    else if(choice == "A"){
        addNew();
    }
    else if(choice == "F"){
        searchState(option);
    }
    else if(choice == "P"){
        findPreceding();
    }
    else if(choice == "N"){
        findNext();
    }
    else if(choice == "Q"){
        saveFile();
        exit(EXIT_SUCCESS);
    }
    else{
        cout << endl;
        cout << "Please enter a valid input." << endl;
        cout << endl;
    }
}

int main() {
    readFile();

    while(true){
        menu();
    }
    return 0;
}