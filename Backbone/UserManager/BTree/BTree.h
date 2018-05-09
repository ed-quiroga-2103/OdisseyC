//
// Created by Eduardo on 05/05/18.
// Implementation taken from https://www.geeksforgeeks.org/b-tree-set-1-insert-2/
//

#ifndef USERMANAGER_BTREE_H
#define USERMANAGER_BTREE_H
// C++ program for B-Tree insertion
#include<iostream>
#include "string"

using namespace std;

using string = std::string;

// A BTree node

class BTreeNode
{

    string *keys;  // An array of keys
    int t;      // Minimum degree (defines the range for number of keys)
    BTreeNode **C; // An array of child pointers
    int n;     // Current number of keys
    bool leaf; // Is true when node is leaf. Otherwise false
public:
    int ind = 0;

    BTreeNode *get(string k);

    BTreeNode(int _t, bool _leaf, int ind);   // Constructor

    // A utility function to insert a new key in the subtree rooted with
    // this node. The assumption is, the node must be non-full when this
    // function is called
    void insertNonFull(string k);

    // A utility function to split the child y of this node. i is index of y in
    // child array C[].  The Child y must be full when this function is called
    void splitChild(int i, BTreeNode *y);

    // A function to traverse all nodes in a subtree rooted with this node
    void traverse();

    // A function to search a key in subtree rooted with this node.
    bool search(string k);   // returns NULL if k is not present.

// Make BTree friend of this so that we can access private members of this
// class in BTree functions
    friend class BTree;
};

// A BTree
class BTree
{
    int size = 0;
    BTreeNode *root; // Pointer to root node
    int t;  // Minimum degree
public:
    // Constructor (Initializes tree as empty)
    BTree(int _t)
    {  root = NULL;  t = _t; }

    // function to traverse the tree
    void traverse()
    {  if (root != NULL) root->traverse(); }

    // function to search a key in this tree
    bool search(string k)
    {  return (root == NULL)? false : root->search(k); }

    // The main function that inserts a new key in this B-Tree
    void insert(string k);

    BTreeNode* get(string k)
    {  return (root == NULL)? NULL : root->get(k); }

};



#endif //USERMANAGER_BTREE_H
