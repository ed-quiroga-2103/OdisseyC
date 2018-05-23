//
// Created by eduardo on 13/05/18.
//

#ifndef AVLTREE_AVLTRWW_H
#define AVLTREE_AVLTRWW_H

// C program to insert a Node in AVL tree
// Obtained from https://www.geeksforgeeks.org/avl-tree-set-1-insertion/

#include<stdio.h>
#include<stdlib.h>
#include "string"

using string = std::string;

// An AVL tree AVLTree
class AVLTree {
    string key;
    AVLTree *left;
    AVLTree *right;
    int height;

public:
// A utility function to get height of the tree
    int getHeight(AVLTree *N) {
        if (N == NULL)
            return 0;
        return N->height;
    }

// A utility function to get maximum of two integers
    int max(int a, int b) {
        return (a > b) ? a : b;
    }

/* Helper function that allocates a new AVLTree with the given key and
    NULL left and right pointers. */
    AVLTree *newAVLTree(string key) {
        struct AVLTree *AVLTree = (struct AVLTree *)
                malloc(sizeof(struct AVLTree));
        AVLTree->key = key;
        AVLTree->left = NULL;
        AVLTree->right = NULL;
        AVLTree->height = 1;  // new AVLTree is initially added at leaf
        return (AVLTree);
    }

// A utility function to right rotate subtree rooted with y
// See the diagram given above.
    AVLTree *rightRotate(AVLTree *y) {
        AVLTree *x = y->left;
        AVLTree *T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        // Return new root
        return x;
    }

// A utility function to left rotate subtree rooted with x
// See the diagram given above.
    AVLTree *leftRotate(AVLTree *x) {
        AVLTree *y = x->right;
        AVLTree *T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        //  Update heights
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        // Return new root
        return y;
    }

// Get Balance factor of AVLTree N
    int getBalance(AVLTree *N) {
        if (N == NULL)
            return 0;
        return getHeight(N->left) - getHeight(N->right);
    }

// Recursive function to insert key in subtree rooted
// with AVLTree and returns new root of subtree.
    AVLTree *insert(AVLTree* root, string key) {
        /* 1.  Perform the normal BST insertion */
        if (root == NULL)
            return (newAVLTree(key));

        if (key < root->key)
            root->left = insert(root->left, key);
        else if (key > root->key)
            root->right = insert(root->right, key);
        else // Equal keys are not allowed in BST
            return root;

        /* 2. Update height of this ancestor AVLTree */
        root->height = 1 + max(getHeight(root->left),
                                  getHeight(root->right));

        /* 3. Get the balance factor of this ancestor
              AVLTree to check whether this AVLTree became
              unbalanced */
        int balance = getBalance(root);

        // If this AVLTree becomes unbalanced, then
        // there are 4 cases

        // Left Left Case
        if (balance > 1 && key < root->left->key)
            return rightRotate(root);

        // Right Right Case
        if (balance < -1 && key > root->right->key)
            return leftRotate(root);

        // Left Right Case
        if (balance > 1 && key > root->left->key) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        // Right Left Case
        if (balance < -1 && key < root->right->key) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        /* return the (unchanged) AVLTree pointer */
        return root;
    }

// A utility function to print preorder traversal
// of the tree.
// The function also prints height of every AVLTree
    bool preOrder(struct AVLTree *root, string data) {
        if (root != NULL) {
            if (data == root->key) {

                return true;

            } else {
                //printf("%d ", root->key);
                return preOrder(root->left, data) || preOrder(root->right, data);

            }
        }
        return false;
    }

};

#endif //AVLTREE_AVLTRWW_H
