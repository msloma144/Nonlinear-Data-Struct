//
// Created by chari on 3/25/2018.
//

#include "MovieBST.h"

using namespace std;

MovieBST::MovieBST() {
    this->root = nullptr;
}

void MovieBST::insert(MovieNode &node) {
    if(this->root == nullptr){
        this->root = &node;
    }
    else{
        MovieNode* curr_node = this->root;

        while (curr_node != nullptr) {
            if (*node.getMovie() < *curr_node->getMovie()) {
                if (curr_node->getLeft() == nullptr) {
                    curr_node->setLeft(&node);
                    node.setParent(curr_node);
                    curr_node = nullptr;
                }
                else {
                    curr_node = curr_node->getLeft();
                }
            }
            else {
                if (curr_node->getRight() == nullptr) {
                    curr_node->setRight(&node);
                    node.setParent(curr_node);
                    curr_node = nullptr;
                }
                else {
                    curr_node = curr_node->getRight();
                }
            }
        }
    }
}

MovieNode* MovieBST::find(MovieNode &node){
    MovieNode* curr_node = this->root;

    while (curr_node != nullptr) {
        if(*curr_node->getMovie() == *node.getMovie()){
            return curr_node;
        }
        else if (*node.getMovie() < *curr_node->getMovie()) {
            if (curr_node->getLeft() == nullptr) {
                curr_node = nullptr;
            }
            else {
                curr_node = curr_node->getLeft();
            }
        }
        else {
            if (curr_node->getRight() == nullptr) {
                curr_node = nullptr;
            }
            else {
                curr_node = curr_node->getRight();
            }
        }
    }
    return new MovieNode();
}

MovieNode* MovieBST::find_successor(MovieNode &node) {
    MovieNode* curr_node = node.getRight();

    while (curr_node != nullptr) {
        if (curr_node->getLeft() == nullptr) {
            return curr_node;
        }
        else {
            curr_node = curr_node->getLeft();
        }
    }
}

MovieNode* MovieBST::remove_recur(MovieNode &curr_root, MovieNode &node) {
    if(&curr_root == nullptr) return &curr_root;

    //if the node is the one we are looking for
    if(*curr_root.getMovie() == *node.getMovie()){
            if(curr_root.getLeft() == nullptr){
                MovieNode* tmp = curr_root.getRight();
                delete(&curr_root);
                return tmp;
            }
            else if(curr_root.getRight() == nullptr){
                MovieNode* tmp = curr_root.getLeft();
                delete(&curr_root);
                return tmp;
            }

            MovieNode* successor = find_successor(curr_root);

            curr_root.copy_vals(*successor);
            this->root->setRight(remove_recur(*curr_root.getRight(), *successor));
        }
        else if(*node.getMovie() < *curr_root.getMovie()){
            curr_root.setLeft(remove_recur(*curr_root.getLeft(), node));
        }
        else{
            curr_root.setRight(remove_recur(*curr_root.getRight(), node));
        }
}

MovieNode* MovieBST::remove(MovieNode &node){
    MovieNode* found_node = this->find(node);

    if(*found_node->getMovie() == *(new MovieNode())->getMovie()){
        cout << "Could not find movie to remove..." << endl;
        delete(found_node);
    }
    else {
        remove_recur(*this->root, node);
        cout << "Removed" << endl;
    }
}

string* MovieBST::list(MovieNode *node, string &out) {
    if (node == nullptr)
        return &out;

    // first recur on left child
    list(node->getLeft(), out);

    // then print the data of node
    out += node->getMovie()->toString();

    // now recur on right child
    list(node->getRight(), out);
}

MovieNode *MovieBST::getRoot() const {
    return root;
}