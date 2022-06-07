//
//  BinaryTree.cpp
//  5
//
//  Created by Anita Stashevskaya on 02.06.2022.
//

#include "BinaryTree.hpp"

void BinaryTree::deleteTree(TreeElem *root){
    if (!root) return; // нечего
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}
void BinaryTree::copyTree(TreeElem *root, TreeElem *copy){
    if (!copy) {
        return;
    }
    root = new TreeElem(copy->data);
    copyTree(root->left, copy->left);
    copyTree(root->right, copy->right);
}

void BinaryTree::printDown(ostream &out, TreeElem *root){
    if (!root) {
        return;
    }
    out << root->data << " "; // текущий
    printDown(out, root->left); // левое
    printDown(out, root->right); // правое
}


TreeElem::TreeElem(int data, TreeElem *left, TreeElem *right) {
    this->data = data;
    this->left = left;
    this->right = right;
}
BinaryTree::BinaryTree(){
    root = nullptr;
    size = 0;
}

BinaryTree::BinaryTree(const BinaryTree &copy) {
    if (!copy.root) {
        return;
    }
    size = copy.size;
    copyTree(root, copy.root);
}

BinaryTree::BinaryTree(BinaryTree &&copy){
    swap(root, copy.root);
    size = copy.size;
}


BinaryTree::~BinaryTree(){
    deleteTree(root);
}

BinaryTree & BinaryTree::operator=(const BinaryTree & obj)
{
    if (this == &obj) { return *this; }
    this->deleteTree(root);
    root = new TreeElem(obj.root->data);
    copyTree(root, obj.root);
    return *this;
}

BinaryTree & BinaryTree::operator=(BinaryTree && obj){
    swap(root, obj.root);
    size = obj.size;
    return *this;
}

void BinaryTree::addElem(int elem, vector<int> vector) {
    TreeElem *temp = root;
    if (!root && vector.size() > 0) {
        throw - 1;
    }
    if (!root && vector.size() == 0) {
        root = new TreeElem(elem);
        size++;
        return;
    }
    if (vector.size() == 0) {
        root->data = elem;
        return;
    }
    for (int i = 0; i < (vector.size() - 1); i++) {
        if (vector[i] == 0) {
            temp = temp->left;
        }
        if (vector[i] == 1) {
            temp = temp->right;
        }
        if (vector[i] != 1 && vector[i] != 0) {
            throw - 1;
        }
    }
    if (!temp || (vector.back() != 1 && vector.back() != 0)) {
        throw - 1;
    }
    if (vector.back() == 0) {
        if (!temp->left) {
            temp->left = new TreeElem(elem);
            size++;
        }
        else {
            temp->left->data = elem;
        }
    }
    if (vector.back() == 1) {
        if (!temp->right) {
            temp->right = new TreeElem(elem);
            size++;
        }
        else {
            temp->right->data = elem;
        }
    }
}
ostream & operator<<(ostream & out, BinaryTree &obj) {
    obj.printDown(out, obj.root);
    return out;
}
int BinaryTree::sumEven(TreeElem *root) {
    if (!root) { return 0; }
    if (root->data % 2 == 0) {
        return (1 + sumEven(root->left) + sumEven(root->right));
    }
    return (sumEven(root->left) + sumEven(root->right));
}
bool BinaryTree::positiveElem(TreeElem *root) {
    if (!root) {
        return true;
    }
    if (root->data <= 0) {
        return false;
    }
    if (!positiveElem(root->left)) {
        return false;
    }
    if (!positiveElem(root->right)) {
        return false;
    }
    return true;
}
void BinaryTree::deleteLeaves(TreeElem *root) {
    if (!root) { return; }
    if (!root->left && !root->right) {
        delete root;
        root = nullptr;
    }
    else {
        deleteLeaves(root->left);
        deleteLeaves(root->right);
    }
}
double BinaryTree::average(TreeElem *root) {//средний
    if (!root) { return 0; }
    return (root->data + average(root->left) + average(root->right));
}
bool BinaryTree::checkFindElem(int x, TreeElem *root, vector<int> &res) {
    if (!root) { return false; }
    if (root->data == x) { return true; }
    res.push_back(0);//0 в конец и в лево
    if (checkFindElem(x, root->left, res)) {
        return true;
    }
    res.pop_back();//выкинуть
    res.push_back(1);//вправо
    if (checkFindElem(x, root->right, res)) {
        return true;
    }
    res.pop_back();
    return false;
}
vector<int> BinaryTree::findElem(int x) {
    std::vector<int> res = {};
    if (checkFindElem(x, root, res)) {
        return res;
    }
    throw - 1;
}
//четных
int BinaryTree::sumEven() {
    return sumEven(root);
}
//положительных
bool BinaryTree::positiveElem(){
    return positiveElem(root);
}

double BinaryTree::average() {
    return average(root)/ size;
}
void BinaryTree::deleteLeaves() {
    return deleteLeaves(root);
}
