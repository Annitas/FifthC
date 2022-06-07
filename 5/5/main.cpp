//
//  main.cpp
//  5
//
//  Created by Anita Stashevskaya on 02.06.2022.
//
#include "BinaryTree.hpp"
#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
        BinaryTree *firstTree = new BinaryTree();
        firstTree->addElem(10, {});
        firstTree->addElem(7, { 0 });
        firstTree->addElem(12, { 1 });
        firstTree->addElem(9, { 0,1 });
        firstTree->addElem(6, { 0, 0 });
        firstTree->addElem(11, { 1,0 });
        firstTree->addElem(8, { 0 });
        firstTree->addElem(3, { 0, 0, 0});
        firstTree->addElem(4, { 0, 0, 0, 1});
        firstTree->addElem(14, { 1,1 });
        BinaryTree *secondTree = new BinaryTree();
        try {
            secondTree->addElem(3, {1, 0});
        }
        catch (int a) {
            cout << "Дерево еще пустое" << "\n";
        }
        try {
            firstTree->addElem(3, { 5,0,2 });
        }
        catch (int a) {
            cout << "В векторе пути могут быть только 0 или 1"<< "\n";
        }
        secondTree->addElem(3, {});
        secondTree->addElem(-1, {0});
        cout << *firstTree << "\n";
        cout << "Количество чётных чисел = " << firstTree->sumEven() << endl;
        cout << "Все элементы дерева положительные: " << firstTree->positiveElem() << "\n";
        cout << "Все элементы дерева положительные: " << secondTree->positiveElem() << endl;
        cout << "Среднее арифметическое: " << firstTree->average() << "\n";
        vector<int> vector1 = firstTree->findElem(4);
        cout << "Путь элемента: ";
        for (int i = 0; i < vector1.size(); i++) {
            cout << vector1[i] << " ";
        }
        cout << "\n";
        try { vector<int> vector2 = firstTree->findElem(20); }
        catch (int a) { cout << "Такого элемента в дереве нет " << endl; }
        cout << " " << "\n";
        BinaryTree *thirdTree = new BinaryTree();
        thirdTree = firstTree;
        cout << *thirdTree << "\n";

    return 0;
}
