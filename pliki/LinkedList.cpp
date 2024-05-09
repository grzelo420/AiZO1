//
// Created by Jakub Grzegocki on 14.04.2023.
//

#include "LinkedList.h"
#include <iostream>
#include <fstream>
#include <string>

LinkedList::LinkedList() : head(nullptr), tail(nullptr), size(0) {}

void LinkedList::addAtBeginning(int value) {

    Node* newNode = new Node(value, head);
    if (head != nullptr) {
        head->prev = newNode;
    }
    head = newNode;
    if (tail == nullptr) {
        tail = newNode;
    }
    size++;
}

void LinkedList::addAtEnd(int value) {
    if(size<1){
        addAtBeginning(value);
    }else{
    Node* newNode = new Node(value, nullptr, tail);
    if (tail != nullptr) {
        tail->next = newNode;
    }
    tail = newNode;
    if (head == nullptr) {
        head = newNode;
    }
    size++;}
}

void LinkedList::addAtPosition(int value, int position) {
    if (position < 0 || position > size) {
        std::cerr << "Brak pozycji\n";
        return;
    }
    if (position == 0) {
        addAtBeginning(value);
        return;
    }
    if (position == size) {
        addAtEnd(value);
        return;
    }

    Node* current = head;
    for (int i = 0; i < position; i++) {
        current = current->next;
    }

    Node* newNode = new Node(value, current, current->prev);
    current->prev->next = newNode;
    current->prev = newNode;
    size++;
}

void LinkedList::removeFromBeginning() {
    if(size>0){
    if (head == nullptr) {
        return;
    }
    Node* nodeToDelete = head;
    head = head->next;
    if (head != nullptr) {
        head->prev = nullptr;
    }
    delete nodeToDelete;
    size--;}
}

void LinkedList::removeFromEnd() {
    if(size>0){
    if (tail == nullptr) {
        return;
    }
    Node* nodeToDelete = tail;
    tail = tail->prev;
    if (tail != nullptr) {
        tail->next = nullptr;
    }
    delete nodeToDelete;
    size--;}
}

void LinkedList::removeFromPosition(int position) {
    if(size > 0){
    if (position < 0 || position >= size) {
        std::cerr << "Brak pozycji\n";
        return;
    }
    if (position == 0) {
        removeFromBeginning();
        return;
    }
    if (position == size - 1) {
        removeFromEnd();
        return;
    }

    Node* current = head;
    for (int i = 0; i < position; i++) {
        current = current->next;
    }

    current->prev->next = current->next;
    current->next->prev = current->prev;
    delete current;
    size--;}
}

void LinkedList::displayList() {
    if(size>0){
    Node* current = head;
    int i = 1;
    while (current != nullptr) {

        std::cout << i << ") " << current->value << std::endl;
        current = current->next;
        i++;
    }
    std::cout << "\n";
    }else {
        std::cout << "Brak listy!"<<std::endl;
    }
}

bool LinkedList::searchValue(int value) {
    Node* current = head;
    while (current != nullptr) {
        if (current->value == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

void LinkedList::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cout << "Nie otwarto pliku: " << filename << "\n";
        system("pause");
        return;
    }
    std::cout<<"Otwarto plik"<<std::endl;
    system("pause");
    int numOfValues;
    file >> numOfValues;

    for (int i = 0; i < numOfValues; i++) {
        int value;
        if (!(file >> value)) {
            std::cout << "Blad wczytywania" << (i + 1) << "\n";
            return;
        }
        addAtEnd(value);
    }
}