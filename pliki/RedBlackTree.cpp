
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include "RedBlackTree.h"

using namespace std;
using std::string;



RedBlackTree::RedBlackTree()
{
    numberOfElements = 0;

    sentinel.color = 'B';
    sentinel.parent = sentinel.leftChild = sentinel.rightChild = root = &sentinel;

    // nr ASCII do wyswietlania calego drzewa
    topCorner = bottomCorner = vertical = "  ";
    topCorner[0] = 218; bottomCorner[1] = 196;
    bottomCorner[0] = 192; bottomCorner[1] = 196;
    vertical[0] = 179;
}

RedBlackTree::~RedBlackTree()
{
    numberOfElements = 0;
    deleteTree(root); // usuwanie drzewa przez metode
}

void RedBlackTree::deleteTree(RedBlackTreeNode *node)
{
    if (node == &sentinel) return;

    deleteTree(node->leftChild);
    deleteTree(node->rightChild);
    delete node;
}

void RedBlackTree::loadFromFile(const std::string& filename){
    std::ifstream file(filename);
    if(!file){
        std::cout<<"Blad otwierania pliku o nazwie "<<filename<<endl;
        system("pause");
        return;
    }
    std::cout<<"Plik otwarto pomyslnie"<<endl;
    system("pause");
    int numberOfValues;
    file>>numberOfValues;

    for(int i = 0; i < numberOfValues; i++){
        int val;
        if(!(file>>val)){
            std::cout<<"blad wczytywania danych"<<i+1<<endl;
            return;
        }
        addNode(val);
    }
    file.close();
}

//void RedBlackTree::loadFromFile(string filename)
//{
//
//    ifstream file(filename);
//    if (file)
//    {
//        cout<<"otwarto plik"<<endl;
//        system("pause");
//
//        string line;
//        getline(file, line); // omit first line
//        int numberOfValues >> getline(file, line);
//        for(int i = 0; i < )
//        while (getline(file, line))
//        {
//            cout<<line<<endl;
//            system("pause");
//            int value = stoi(line);
//            addNode(value);
//        }
//        file.close();
//    }
//    else
//    {
//        cout << "\nCouldn't open " << filename << " to read\n";
//        system("pause");
//    }
//}

void RedBlackTree::printRedBlackTree(string text1, string text2, RedBlackTreeNode *node)
{
    if (root == &sentinel)
        cout << "drezewo jest puste\n";
    else
    {
        string text;

        if (node != &sentinel)
        {
            text = text1;
            if (text2 == topCorner)
                text[text.length() - 2] = ' ';
            printRedBlackTree((text + vertical), topCorner, node->rightChild);

            text = text.substr(0, text1.length() - 2);
            cout << text << text2 << node->color << ":" << node->key << endl;

            text = text1;
            if (text2 == bottomCorner)
                text[text.length() - 2] = ' ';
            printRedBlackTree((text + vertical), bottomCorner, node->leftChild);
        }
    }
}

void RedBlackTree::display()
{
    printRedBlackTree("  ", "  ", root);
}

bool RedBlackTree::search(int value) {
    RedBlackTreeNode* helper = root;
    while (helper != &sentinel && helper->key != value) {
        helper = value < helper->key ? helper->leftChild : helper->rightChild;
    }

    if (helper == &sentinel) {
        return false;
    } else {

        return true;
    }
}

RedBlackTreeNode * RedBlackTree::returnSuccesor(RedBlackTreeNode * node)
{
    if (node->rightChild != &sentinel)
    {
        RedBlackTreeNode * helper = node->rightChild;
        while (helper->leftChild != &sentinel)
        {
            helper = helper->leftChild;
        }
        return helper;
    }
    else
    {
        RedBlackTreeNode * parent = node->parent;
        while (parent != &sentinel && node == parent->rightChild)
        {
            node = parent;
            parent = parent->parent;
        }
        return parent;
    }
}

RedBlackTreeNode* RedBlackTree::createNewNode(int value) {
    RedBlackTreeNode *newNode = new RedBlackTreeNode();
    newNode->leftChild = newNode->rightChild = &sentinel;
    newNode->key = value;
    newNode->color = 'R';
    return newNode;
}

void RedBlackTree::insertNode(RedBlackTreeNode *newNode) {
    RedBlackTreeNode *currentNode = root;
    RedBlackTreeNode *previousNode = &sentinel;

    while (currentNode != &sentinel) {
        previousNode = currentNode;
        currentNode = (newNode->key < currentNode->key) ? currentNode->leftChild : currentNode->rightChild;
    }

    newNode->parent = previousNode;

    if (previousNode == &sentinel) {
        root = newNode;
    } else if (newNode->key < previousNode->key) {
        previousNode->leftChild = newNode;
    } else {
        previousNode->rightChild = newNode;
    }
}

void RedBlackTree::addNode(int value) {
    RedBlackTreeNode *newNode = createNewNode(value);
    newNode->parent = root;
    numberOfElements++;

    if (root == &sentinel) {
        root = newNode;
        newNode->parent = &sentinel;
    } else {
        insertNode(newNode);
        fixAdd(newNode); // sprawdzanie warunkow drzewa czerwono-czarnego
    }
}

RedBlackTreeNode* RedBlackTree::findNodeToDelete(int searchedKey) {
    RedBlackTreeNode *helper = root;
    while (helper != &sentinel && helper->key != searchedKey) {
        helper = (searchedKey < helper->key) ? helper->leftChild : helper->rightChild;
    }
    return helper;
}

void RedBlackTree::fixRemove(RedBlackTreeNode *node) {
    RedBlackTreeNode *w;

    while (node != root && node->color == 'B') {
        if (node == node->parent->leftChild) {
            w = node->parent->rightChild;
            // I
            if (w->color == 'R') {
                w->color = 'B';
                node->parent->color = 'R';
                rotateLeft(node->parent);
                w = node->parent->rightChild;
            }
            // II
            if (w->leftChild->color == 'B' && w->rightChild->color == 'B') {
                w->color = 'R';
                node = node->parent;
            } else {
                // III
                if (w->rightChild->color == 'B') {
                    w->leftChild->color = 'B';
                    w->color = 'R';
                    rotateRight(w);
                    w = node->parent->rightChild;
                }
                // IV
                w->color = node->parent->color;
                node->parent->color = 'B';
                w->rightChild->color = 'B';
                rotateLeft(node->parent);
                node = root;
            }
        } else {
            w = node->parent->leftChild;
            // tutaj podobna sprawa tylko dla prawego syna
            // I
            if (w->color == 'R') {
                w->color = 'B';
                node->parent->color = 'R';
                rotateRight(node->parent);
                w = node->parent->leftChild;
            }
            // II
            if (w->rightChild->color == 'B' && w->leftChild->color == 'B') {
                w->color = 'R';
                node = node->parent;
            } else {
                // III
                if (w -> leftChild->color == 'B') {
                    w -> rightChild->color = 'B';
                    w -> color = 'R';
                    rotateLeft(w);
                    w = node -> parent -> leftChild;
                }
                // IV
                w -> color = node->parent -> color;
                node -> parent -> color = 'B';
                w -> leftChild -> color = 'B';
                rotateRight(node->parent);
                node = root;
            }
        }
    }
    node->color = 'B';
}

void RedBlackTree::deleteNode(int searchedKey) {

//  3 opcje podczas usuwania
//  1) wezel jest lisciem
//  2) wezel ma dziecko lewe --> lewe dziecko wchodzi za wezel i przekolorowujemy w razie potrzeby
//  3) wezel ma lewe i prawe poddrzewo wtedy na miejsce wierzcholka usuwanego wchodzi najmniejszy wezel z prawego podrzewa od danego wezla

    if (root == &sentinel) {
        cout << "Drzewo jest puste\n";
        return;
    }

    RedBlackTreeNode *nodeToDelete = findNodeToDelete(searchedKey);

    if (nodeToDelete == &sentinel) {
        return;
    }

    RedBlackTreeNode *y = &sentinel;
    RedBlackTreeNode *x = &sentinel;

    if (nodeToDelete->leftChild == &sentinel || nodeToDelete->rightChild == &sentinel) {
        y = nodeToDelete;
    } else {
        y = returnSuccesor(nodeToDelete);
    }

    if (y->leftChild != &sentinel) {
        x = y->leftChild;
    } else {
        x = y->rightChild;
    }

    x->parent = y->parent;

    if (y->parent == &sentinel) {
        root = x;
    } else if (y == y->parent->leftChild) {
        y->parent->leftChild = x;
    } else {
        y->parent->rightChild = x;
    }

    if (y != nodeToDelete) {
        nodeToDelete->key = y->key;
    }

    if (y->color == 'B') {
        fixRemove(x);
    }

    delete y;
}

void RedBlackTree::fixAdd(RedBlackTreeNode *node) {
    if (node == root) {
        node->color = 'B';
        return;
    }

    while (node->parent != &sentinel && node->parent->color == 'R') {
        RedBlackTreeNode *grandpa = node->parent->parent;
        bool isLeftChild = node->parent == grandpa->leftChild;

        RedBlackTreeNode *uncle = isLeftChild ? grandpa->rightChild : grandpa->leftChild;

        if (uncle != &sentinel && uncle->color == 'R') {
            node->parent->color = 'B';
            uncle->color = 'B';
            grandpa->color = 'R';
            node = grandpa;
        } else {
            if (isLeftChild) {
                if (node->parent->rightChild == node) {
                    node = node->parent;
                    rotateLeft(node);
                }
                node->parent->color = 'B';
                grandpa->color = 'R';
                rotateRight(grandpa);
            } else {
                if (node->parent->leftChild == node) {
                    node = node->parent;
                    rotateRight(node);
                }
                node->parent->color = 'B';
                grandpa->color = 'R';
                rotateLeft(grandpa);
            }
        }
    }

    root->color = 'B'; // fixing root
}

void RedBlackTree::rotateLeft(RedBlackTreeNode * node)
{
    RedBlackTreeNode * B, *p;

    B = node->rightChild;
    if (B != &sentinel)
    {
        p = node->parent;
        node->rightChild = B->leftChild;
        if (node->rightChild != &sentinel) node->rightChild->parent = node;

        B->leftChild = node;
        B->parent = p;
        node->parent = B;

        if (p != &sentinel)
        {
            if (p->leftChild == node) p->leftChild = B; else p->rightChild = B;
        }
        else root = B;
    }

}

void RedBlackTree::rotateRight(RedBlackTreeNode * node)
{
    RedBlackTreeNode * B, *p;

    B = node->leftChild;
    if (B != &sentinel)
    {
        p = node->parent;
        node->leftChild = B->rightChild;
        if (node->leftChild != &sentinel) node->leftChild->parent = node;

        B->rightChild = node;
        B->parent = p;
        node->parent = B;

        if (p != &sentinel)
        {
            if (p->rightChild == node) p->rightChild = B; else p->leftChild = B;
        }
        else root = B;
    }

}