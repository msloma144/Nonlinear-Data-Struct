//
// Created by chari on 3/25/2018.
//

#include <iostream>
#include "MovieBST.h"
#include <fstream>
#include <sstream>

using namespace std;

MovieBST tree1;

void readFile(string fileName){
    ifstream inFile;
    inFile.open(fileName);
    string inLine;
    unsigned int count = 0;

    if(inFile.good()){
        string title;
        int year;
        string rating;
        string time;
        string url;

        while (inFile && getline(inFile, inLine)){
            if(inLine.find("\r") != string::npos)
                inLine = inLine.substr(0, inLine.length() - 1);
            if(count == 5){
                tree1.insert(*new MovieNode(*new Movie(title, year, rating, time, url)));

                title = "";
                year = 0000;
                rating = "";
                time = "";
                url = "";

                count = 0;
            }

            stringstream str1(inLine);
            switch (count) {
                case 0:
                    title = inLine;
                    break;
                case 1:
                    str1 >> year;
                    break;
                case 2:
                    rating = inLine;
                    break;
                case 3:
                    time = inLine;
                    break;
                case 4:
                    url = inLine;
                    break;
                default:
                    cout << "BAD BAD" << endl;
                    break;
            };
            count++;
        }
        tree1.insert(*new MovieNode(*new Movie(title, year, rating, time, url)));
    }
    else{
        cout << "Bad File!";
        exit(EXIT_FAILURE);
    }

    inFile.close();
}

void addNew(){
    string title;
    int year;
    string rating;
    string length;
    string url;

    cout << "  ****NEW MOVIE****" << endl;
    cout << "Please enter title: ";
    getline(std::cin, title);
    cout << "Please enter year: ";
    string str_year;
    getline(std::cin, str_year);
    stringstream str1(str_year);
    str1 >> year;
    cout << "Please enter rating: ";
    getline(std::cin, rating);
    cout << "Please enter length: ";
    getline(std::cin, length);
    cout << "Please enter url: ";
    getline(std::cin, url);
    cout << endl;

    tree1.insert(*new MovieNode(*new Movie(title, year, rating, length, url)));
}

void listAll(){
    string save = *new string();
    tree1.list(tree1.getRoot(), save);
    cout << save << endl;
}

void saveFile(){
    ofstream outFile;
    outFile.open("./movies2.txt");
    string save = *new string();
    tree1.list(tree1.getRoot(), save);
    outFile << save;
    outFile.close();
}

void searchTree(){
    string title;
    int year;

    cout << "  ****SEARCH MOVIE****" << endl;
    cout << "Please enter title: ";
    getline(std::cin, title);
    cout << "Please enter year: ";
    string str_year;
    getline(std::cin, str_year);
    stringstream str1(str_year);
    str1 >> year;

    MovieNode* found = tree1.find(*new MovieNode(*new Movie(title, year, "", "", "")));

    if(*found->getMovie() == *new Movie()){
        cout << "No movie found!" << endl;
    }
    else {
        cout << found->getMovie()->toString() << endl;
    }
}

void remove_node(){
    string title;
    int year;

    cout << "  ****DELETE MOVIE****" << endl;
    cout << "Please enter title: ";
    getline(std::cin, title);
    cout << "Please enter year: ";
    string str_year;
    getline(std::cin, str_year);
    stringstream str1(str_year);
    str1 >> year;

    tree1.remove(*new MovieNode(*new Movie(title, year, "", "", "")));
}

void menu(){
    string input;
    string choice;
    string option;
    cout << "********************Main Menu**********************" << endl;
    cout << "L​ - list all the movies and their information.     " << endl;
    cout << "I​ - add a movie.                                   " << endl;
    cout << "S - search for a movie.                            " << endl;
    cout << "D - delete a movie                                 " << endl;
    cout << "Q​ - quit after saving file.                        " << endl;
    cout << "Please enter command: ";
    getline(cin, input);
    choice = input.at(0);
    if(input.length() > 1)
        option = input.substr(2);
    if(choice == "L"){
        listAll();
    }
    else if(choice == "I"){
        addNew();
    }
    else if(choice == "S"){
        searchTree();
    }
    else if(choice == "D"){
        remove_node();
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

int main(){
    tree1 = *new MovieBST();
    readFile("./movies.txt");

    while(true){
        menu();
    }
}