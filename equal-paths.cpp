#ifndef RECCHECK
//if you want to add any #includes like <iostream> you must do them here (before the next endif)

#endif

#include "equal-paths.h"
using namespace std;


// You may add any prototypes of helper functions here
int checkHeight(Node* root);

// Returns height of subtree if all leaf paths are equal length, -1 otherwise
int checkHeight(Node* root) {
    if (root == nullptr) 
        return 0;

    // Leaf node
    if (root->left == nullptr && root->right == nullptr) 
        return 1;

    // Only left child 
    if (root->right == nullptr) {
        int lh = checkHeight(root->left);
        if (lh == -1) {
            return -1;
        } 
        else {
            return lh + 1;
        }
    }

    // Only right child 
    if (root->left == nullptr) {
        int rh = checkHeight(root->right);
        if (rh == -1) {
            return -1;
        } 
        else {
            return rh + 1;
        }
    }

    // Both children heights must match
    int lh = checkHeight(root->left);
    int rh = checkHeight(root->right);

    if (lh == -1 || rh == -1) 
        return -1;
    if (lh != rh) 
        return -1;
    return lh + 1;
}

bool equalPaths(Node* root)
{
    // Add your code below
    if (root == nullptr) 
        return true;
    return checkHeight(root) != -1;
}