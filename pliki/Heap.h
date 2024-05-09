//
// Created by Jakub Grzegocki on 04.04.2023.
//

#ifndef SDIZO_HEAP_H
#define SDIZO_HEAP_H
#include <string>

class Heap {
public:
    Heap();
    ~Heap();

    void add_element(int value);
    void remove_heap_element();
    void print_heap();
    void load_heap(const std::string& filename);
    bool search(int value);

private:
    int* point;
    int size;
    int maxSize;

    int parent(int i);
    void heapify(int i);
    void swap(int* u, int* d);
};


#endif //SDIZO_HEAP_H
