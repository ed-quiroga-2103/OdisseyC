#include <iostream>
#include "AVLTree.h"
#include "string"

using string = std::string;

int main()
{
    AVLTree *root = NULL;

    /* Constructing tree given in the above figure */
    root = root->insert(root, "a");



    /* The constructed AVL Tree would be
              30
             /  \
           20   40
          /  \     \
         10  25    50
    */

    printf("Preorder traversal of the constructed AVL"
                   " tree is \n");
    std::cout << root->preOrder(root, "g");

    return 0;
}