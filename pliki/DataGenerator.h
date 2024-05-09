#ifndef SDIZO_DATAGENERATOR_H
#define SDIZO_DATAGENERATOR_H
#include "Table.h"
#include "Heap.h"
#include "LinkedList.h"
#include "RedBlackTree.h"

class DataGenerator {

public:

    void generate(Table* table, int n);
    //void generate(DoublyLinkedList* list, int n);
    void generate(Heap* heap, int n);

    void generate(LinkedList* list, int n);

    void generate(RedBlackTree* tree, int n);
};


#endif //SDIZO_DATAGENERATOR_H
