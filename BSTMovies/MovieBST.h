//
// Created by chari on 3/25/2018.
//

#include <iostream>
#include "MovieNode.h"
using namespace std;

#ifndef BSTMOVIES_MOVIEBST_H
#define BSTMOVIES_MOVIEBST_H


class MovieBST {
protected:
    MovieNode* root;
public:
    MovieBST();
    void insert(MovieNode &node);
    MovieNode* find_successor(MovieNode &node);
    MovieNode* remove(MovieNode &node);
    MovieNode* remove_recur(MovieNode &curr_root, MovieNode &node);
    MovieNode* find(MovieNode &node);
    string* list(MovieNode *node, string &out);

    MovieNode *getRoot() const;
};

#endif //BSTMOVIES_MOVIEBST_H
