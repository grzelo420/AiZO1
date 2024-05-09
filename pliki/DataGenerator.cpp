//
// Created by Jakub Grzegocki on 07.05.2023.
//

#include "DataGenerator.h"
#include <iostream>
#include <time.h>
#include <random>

void DataGenerator::generate(Heap* heap, int n) {

    for(int i = 0; i < n; i++){
        int value = rand() % 1000;
        heap -> add_element(value);
    }
}

void DataGenerator::generate(Table* table, int n) {

    for(int i = 0; i < n; i++){
        int value = rand() % 1000;
        table -> add_first(value);
    }
}

void DataGenerator::generate(LinkedList* list, int n) {

    for(int i = 0; i < n; i++){
       int value = rand() % 1000;
       list -> addAtBeginning(value);
    }
}

void DataGenerator::generate(RedBlackTree* tree, int n){
    for(int i = 0; i < n; i++){
        int value = rand() % 1000;
        tree -> addNode(value);
    }
}