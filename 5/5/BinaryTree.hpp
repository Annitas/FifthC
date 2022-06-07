//
//  BinaryTree.hpp
//  5
//
//  Created by Anita Stashevskaya on 02.06.2022.
//

#ifndef BinaryTree_hpp
#define BinaryTree_hpp

#include <stdio.h>

#endif /* BinaryTree_hpp */
#pragma once

#include "iostream"
#include "vector"
#include "climits"

using namespace std;

struct TreeElem {
    int data;
    TreeElem *left;
    TreeElem *right;
    TreeElem(int data, TreeElem *left = nullptr, TreeElem *rigth = nullptr);
};
class BinaryTree
{private:
    TreeElem *root;
    int size;
public:
    BinaryTree();
    BinaryTree(const BinaryTree &copy);
    BinaryTree(BinaryTree &&copy);
    BinaryTree& operator= (const BinaryTree &copy);
    BinaryTree& operator= (BinaryTree &&copy);
    ~BinaryTree();
    void addElem(int elem, vector<int> vector);
    friend ostream& operator<<(ostream & stream, BinaryTree &tree);
    int sumEven(TreeElem *root);
    bool positiveElem(TreeElem *root);
    void deleteLeaves(TreeElem *root);
    double average(TreeElem *root);
    bool checkFindElem(int x, TreeElem *root, vector<int> &res);
    vector<int> findElem(int x);
    void deleteTree(TreeElem *root);
    void copyTree(TreeElem *root, TreeElem *copy);
    void printDown(ostream & os, TreeElem *root);
    int sumEven();
    bool positiveElem();
    double average();
    void deleteLeaves();
};
