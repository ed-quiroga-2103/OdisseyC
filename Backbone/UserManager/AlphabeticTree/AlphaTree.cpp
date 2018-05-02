//
// Created by eduardo on 28/04/18.
//

#include "AlphaTree.h"

TreeNode::TreeNode(string data) {

    this->data = data;

}

TreeNode *TreeNode::getLeftchild() const {
    return leftchild;
}

void TreeNode::setLeftchild(TreeNode *leftchild) {
    TreeNode::leftchild = leftchild;
}

TreeNode *TreeNode::getRightchild() const {
    return rightchild;
}

void TreeNode::setRightchild(TreeNode *rightchild) {
    TreeNode::rightchild = rightchild;
}

const std::string &TreeNode::getData() const {
    return data;
}

void TreeNode::setData(const std::string &data) {
    TreeNode::data = data;
}

int TreeNode::getInd() const {
    return ind;
}

void TreeNode::setInd(int ind) {
    TreeNode::ind = ind;
}

//------------------------------------------------------------------------------------------------------

void AlphaTree::newNode(string data) {

    if(root == NULL){

        root = new TreeNode(data);
        root->setInd(size);
        size++;
        return;
    }
    else{

        TreeNode* parent = findChild(data, root);

        if(data > parent->getData()){

            TreeNode* child = new TreeNode(data);
            child->setInd(size);
            parent->setRightchild(child);

        }
        else if(data < parent->getData()){

            TreeNode* child = new TreeNode(data);
            child->setInd(size);
            parent->setLeftchild(child);

        }

        size++;
        return;
    }

}

TreeNode* AlphaTree::findChild(string data, TreeNode* node) {

    TreeNode* current = node;

    if(data < current->getData() && current->getLeftchild() == NULL){

        return current;

    }
    else if(data > current->getData() && current->getRightchild() == NULL){

        return current;

    }
    else if(data < current->getData()){

        return findChild(data, current->getLeftchild());

    }
    else if(data > current->getData()) {

        return findChild(data, current->getRightchild());
    }

}

TreeNode *AlphaTree::findNode(string data) {

    TreeNode* current = root;

    while(current->getData() != data){

        if(data < current->getData()){

            current = current->getLeftchild();

        }
        else if(data < current->getData()) {

            current = current->getRightchild();
        }
    }

    return current;
}

bool AlphaTree::exists(string data) {

    TreeNode* current = root;

    while(current != NULL){

        if(current->getData() == data){
            return true;
        }

        else if(current->getData() < data){
            current = current->getRightchild();
        }
        else if(current->getData() > data){
            current = current->getLeftchild();
        }

    }

    return false;

}
