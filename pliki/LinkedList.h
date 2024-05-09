#ifndef SDIZO_LINKEDLIST_H
#define SDIZO_LINKEDLIST_H
#include <string>

class LinkedList {

private:
    struct Node {
        int value;
        Node* next;
        Node* prev;
        Node(int val, Node* nxt = nullptr, Node* prv = nullptr)
                : value(val), next(nxt), prev(prv) {}
    };

    Node* head;
    Node* tail;
    int size;

public:
    LinkedList();

    void addAtBeginning(int value);
    void addAtEnd(int value);
    void addAtPosition(int value, int position);
    void removeFromBeginning();
    void removeFromEnd();
    void removeFromPosition(int position);
    void displayList();
    bool searchValue(int value);
    void loadFromFile(const std::string& filename);

};

#endif //SDIZO_LINKEDLIST_H
