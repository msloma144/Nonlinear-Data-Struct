//
// Created by chari on 3/25/2018.
//

#include "MovieNode.h"

MovieNode::MovieNode() {
    this->movie = new Movie();

    this->parent = nullptr;
    this->left = nullptr;
    this->right = nullptr;
}

MovieNode::MovieNode(Movie &movie) {
    this->movie = &movie;

    this->parent = nullptr;
    this->left = nullptr;
    this->right = nullptr;
}

MovieNode::~MovieNode() {
    this->movie = nullptr;

    this->parent = nullptr;
    this->left = nullptr;
    this->right = nullptr;
}

void MovieNode::copy_vals(MovieNode &node) {
    this->movie = node.movie;
}

MovieNode *MovieNode::getLeft() const {
    return left;
}

void MovieNode::setLeft(MovieNode *left) {
    MovieNode::left = left;
}

MovieNode *MovieNode::getRight() const {
    return right;
}

void MovieNode::setRight(MovieNode *right) {
    MovieNode::right = right;
}

MovieNode *MovieNode::getParent() const {
    return parent;
}

void MovieNode::setParent(MovieNode *parent) {
    MovieNode::parent = parent;
}

Movie *MovieNode::getMovie() const {
    return movie;
}

void MovieNode::setMovie(Movie *movie) {
    MovieNode::movie = movie;
}


