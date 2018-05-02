//
// Created by eduardo on 28/04/18.
//

#ifndef ALPHABETICTREE_ALPHATREE_H
#define ALPHABETICTREE_ALPHATREE_H

#include "string"

using string = std::string;

class TreeNode{

private:
    TreeNode* leftchild = NULL;
    TreeNode* rightchild = NULL;

    string data;

    int ind = 0;
public:
    TreeNode(string data);

    TreeNode *getLeftchild() const;

    void setLeftchild(TreeNode *leftchild);

    TreeNode *getRightchild() const;

    void setRightchild(TreeNode *rightchild);

    const std::string &getData() const;

    void setData(const std::string &data);

    int getInd() const;

    void setInd(int ind);
};


class AlphaTree {
private:

    TreeNode* root = nullptr;
    int size = 0;

public:

    void newNode(string data);

    TreeNode* findChild(string data, TreeNode* node);
    TreeNode* findNode(string data);
    bool exists(string data);

};


#endif //ALPHABETICTREE_ALPHATREE_H
