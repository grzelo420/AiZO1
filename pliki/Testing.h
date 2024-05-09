
#ifndef SDIZO_TESTING_H
#define SDIZO_TESTING_H
#include <chrono>
#include <iostream>
#include <fstream>
#include <string>
#include "DataGenerator.h"

class Testing {

public:

    static void auto_test_all();
    void auto_test_heap(DataGenerator dataGenerator, int DataSize[5], int i);
    void auto_test_list(DataGenerator dataGenerator, int DataSize[5], int i);
    void auto_test_table(DataGenerator dataGenerator, int DataSize[5], int i);
    void auto_test_tree(DataGenerator dataGenerator, int DataSize[5], int i);

    void test_table_dialog();
    void test_heap_dialog();
    void test_list_dialog();
    void test_tree_dialog();

    void test_tab_add_last(DataGenerator dataGenerator, int n, const int testNumber);
    void test_tab_add_first(DataGenerator dataGenerator, int n, const int testNumber);
    void test_tab_add_on_pos(DataGenerator dataGenerator, int n, const int testNumber);
    void test_tab_remove_last(DataGenerator dataGenerator, int n, const int testNumber);
    void test_tab_remove_first(DataGenerator dataGenerator, int n, const int testNumber);
    void test_tab_remove_from_pos(DataGenerator dataGenerator, int n, const int testNumber);
    void test_tab_search(DataGenerator dataGenerator, int n, const int testNumber);

    void test_list_add_first(DataGenerator dataGenerator, int n, const int testNumber);
    void test_list_add_last(DataGenerator dataGenerator, int n, const int testNumber);
    void test_list_add_on_pos(DataGenerator dataGenerator, int n, const int testNumber);
    void test_list_remove_first(DataGenerator dataGenerator, int n, const int testNumber);
    void test_list_remove_last(DataGenerator dataGenerator, int n, const int testNumber);
    void test_list_remove_on_pos(DataGenerator dataGenerator, int n, const int testNumber);
    void test_list_search(DataGenerator dataGenerator, int n, const int testNumber);

    void test_heap_add(DataGenerator dataGenerator, int n, const int testNumber);
    void test_heap_remove(DataGenerator dataGenerator, int n, const int testNumber);
    void test_heap_search(DataGenerator dataGenerator, int n, const int testNumber);

    void test_tree_add(DataGenerator dataGenerator, int n, const int testNumber);
    void test_tree_remove(DataGenerator dataGenerator, int n, const int testNumber);
    void test_tree_search(DataGenerator dataGenerator, int n, const int testNumber);
};


#endif //SDIZO_TESTING_H
