//
// Created by Jakub Grzegocki on 23.03.2023.
//

#ifndef SDIZO_TABLE_H
#define SDIZO_TABLE_H
#include <string>

class Table {

public:

    int size;
    int* point;

    Table();
    ~Table();

    bool search(int value);
    bool exist();
    void add_first(int value);
    void add_last(int value);
    void add_on_pos(int value, int pos);
    void remove_first();
    void remove_last();
    void remove_from_pos(int post);
    void print_table();
    void loadTable(const std::string& filename);
    void quickSort(int low, int high);
    void quickSortInit();
    void binaryInsertionSort();
    void insertionSort();
    void heapify(int n, int i);
    void heapSort();
    int getSize();
    int partition(int low, int high);
    int binarySearchForInsertion(int item, int low, int high);
};

#endif //SDIZO_TABLE_H