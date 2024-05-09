//
// Created by Jakub Grzegocki on 04.04.2023.
//

#include "Heap.h"
#include <fstream>
#include <iostream>
#include <sstream>

Heap::Heap() : point(nullptr), maxSize(100000000), size(0) {}

Heap::~Heap() {
    delete[] point;
}

int Heap::parent(int i) {
    return (i - 1) / 2;
}

void Heap::add_element(int value) {
    if (size < maxSize) {
        int* new_point = new int[size + 1];
        for (int i = 0; i < size; ++i) {
            new_point[i] = point[i];
        }
        delete[] point;
        point = new_point;
        point[size] = value;

        int i = size;
        size++;

        while (i != 0 && point[parent(i)] < point[i]) {
            swap(&point[i], &point[parent(i)]);
            i = parent(i);
        }
    } else {
        std::cerr << "\nPrzekroczono limit wielkości kopca." << std::endl;
    }
}

void Heap::remove_heap_element() {
    if(size > 0){
        point[0] = point[size - 1];
        int* new_point = new int[size - 1];
        for(int i = 0; i < size - 1; i++){
            new_point[i] = point[i];
        }
        delete[] point;
        point = new_point;
        size--;
        heapify(0);
    }
    else
        std::cerr<<std::endl<<"Brak elementów do usunięcia."<<std::endl;
}

void Heap::print_heap() {

    int pow = 1;
    int sum = 1;

    for (int i = 0; i < size; i++) {
        if(i == sum){
            std::cout<<std::endl;
            pow *= 2;
            sum += pow;
        }
        std::cout << point[i] << " ";

    }
    std::cout << std::endl;
}

void Heap::load_heap(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        getline(file, line);
        int fileSize = std::stoi(line);

        if (fileSize > 0) {
            point = new int[maxSize];
            int value;
            for (int i = 0; i < fileSize; i++) {
                getline(file, line);
                value = std::stoi(line);
                add_element(value);
            }
        }
        file.close();
    } else {
        std::cerr << "\nNie można otworzyć pliku." << std::endl;
    }
}

bool Heap::search(int value) {
    for (int i = 0; i < size; i++) {
        if (point[i] == value) {
            return true;
        }
    }
    return false;
}

void Heap::heapify(int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && point[left] > point[largest]) {
        largest = left;
    }

    if (right < size && point[right] > point[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(&point[i], &point[largest]);
        heapify(largest);
    }
}

void Heap::swap(int* u, int* d) {
    int temp = *u;
    *u = *d;
    *d = temp;
}