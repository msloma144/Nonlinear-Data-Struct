//
// Created by chari on 3/25/2018.
//

#include <iostream>
#include "Movie.h"
using namespace std;

#ifndef BSTMOVIES_MOVIENODE_H
#define BSTMOVIES_MOVIENODE_H

class MovieNode {
protected:
    Movie* movie;

    MovieNode* left;
    MovieNode* right;
    MovieNode* parent;

public:
    MovieNode();
    MovieNode(Movie &movie);
    ~MovieNode();

    void copy_vals(MovieNode &node);

    MovieNode *getLeft() const;
    void setLeft(MovieNode *left);
    MovieNode *getRight() const;
    void setRight(MovieNode *right);
    MovieNode *getParent() const;
    void setParent(MovieNode *parent);

    Movie *getMovie() const;
    void setMovie(Movie *movie);
};


#endif //BSTMOVIES_MOVIENODE_H
