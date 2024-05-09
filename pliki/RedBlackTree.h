#ifndef SDIZO_TREE_H
#define SDIZO_TREE_H

using namespace std;

class RedBlackTreeNode {

public:
    RedBlackTreeNode *parent, *leftChild, *rightChild;
    int key;
    char color;
};


class RedBlackTree {

private:

    char black;
    char red;
    RedBlackTreeNode *root;
    int numberOfElements;
    RedBlackTreeNode sentinel; //wartownik
    string topCorner, bottomCorner, vertical;                               //gornmy rog dolny rog i pion

    void fixRemove(RedBlackTreeNode *node);                                     //naprawa drzewa po usunieciu elementu (przywracanie wlasnosci RB drzewa)
    void fixAdd(RedBlackTreeNode *node);                                        //naprawa drzewa po dodaniu elementu
    void rotateLeft(RedBlackTreeNode *node);
    void rotateRight(RedBlackTreeNode *node);                                   //rotacje prawa lewa
    RedBlackTreeNode* returnSuccesor(RedBlackTreeNode *node);                   //zwracanie poprzednika
    void printRedBlackTree(string text1, string text2, RedBlackTreeNode *node); //drukowanie drzewa (z githuba)
    void handleBlackNodeDeletion(RedBlackTreeNode *node, bool isLeftChild);     //przywracanie wlasciwosci po usunieciu czarnego wezla
    RedBlackTreeNode *findNodeToDelete(int searchedKey);                        //wyszukiwanie po kluczu do usuniecia
    void deleteNodeWithOneChild(RedBlackTreeNode *node, bool hasLeftChild);     //usuwanie kiedy jedno dziecko

    RedBlackTreeNode *createNewNode(int enteredValue);

    void deleteTree(RedBlackTreeNode *node);                                    //metoda zwalniajaca pamiec drzewa
    void insertNode(RedBlackTreeNode *newNode);                                 //wstawianie wezla

public:

    RedBlackTree();
    ~RedBlackTree();        //konstruktor destruktor

    void loadFromFile(const std::string& filename);

    bool search(int enteredValue);
    void addNode(int enteredValue);
    void deleteNode(int searchedKey);

    void display();

};


#endif //SDIZO_TREE_H
