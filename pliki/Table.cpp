//
// Created by Jakub Grzegocki on 23.03.2023.
//

#include "Table.h"

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

Table::Table() {
    point = nullptr;
    size = 0;
}

Table::~Table() {
    delete[] point;
    point = nullptr;
}

void Table::loadTable(const std::string& stream){
////TODO: poprawic aby dalo sie usuwac wszystkie elementy z tablicy
    std::ifstream file(stream);
    if (!file) {
        std::cout << "Unable to open file: " << stream << "\n";
        system("pause");
        return;
    }
    std::cout<<"Otwarto plik"<<std::endl;
    system("pause");
    int numOfValues;
    file >> numOfValues;

    for (int i = 0; i < numOfValues; i++) {
        int value;
        file >> value;
//        if (!(file >> value)) {
//            std::cout << "Error reading value #" << (i + 1) << "\n";
//            return;
//        }
        add_first(value);
    }
}

void Table::add_first(int value) {
    int* temp_point = new int[size + 1];
    temp_point[0] = value;

    for(int i = 0; i < size; i++){
        temp_point[i+1] = point[i];
    }

    delete[] point;
    point = temp_point;
    temp_point = nullptr;
    delete[] temp_point;
    size++;
}

void Table::add_last(int value) {
    int* temp_point = new int[size+1];
    for(int i = 0; i < size; i++){
        temp_point[i] = point[i];
    }

    temp_point[size] = value;
    delete[] point;
    point = temp_point;
    temp_point = nullptr;
    delete[] temp_point;
    size++;
}

void Table::add_on_pos(int value, int pos) {
    if(pos == 0){
        add_first(value);
    } else if(pos == size - 1){
        add_last(value);
    } else if(pos > 0 && pos < size){

        int* temp_point = new int[size + 1];

        for(int i = 0; i < pos; i++){
            temp_point[i] = point[i];
        }

        temp_point[pos] = value;

        for(int i = pos + 1; i < size + 1; i++){
            temp_point[i] = point[i - 1];
        }

        delete[] point;
        point = temp_point;
        temp_point = nullptr;
        delete[] temp_point;
        size++;
    }
    else std::cerr << std::endl << "brak podanej pozycji" << std::endl;
}

void Table::remove_first() {
    if(size > 0){
        size--;
        int* temp_point = new int[size];
        for(int i = 0; i < size; i++){
            temp_point[i] = point[i + 1];
        }

        delete[] point;
        point = temp_point;
        temp_point = nullptr;
        delete[] temp_point;
    }
    else std::cerr << std::endl << "tablica nie istnieje" << std::endl;

}

void Table::remove_last() {
    if(size > 0){
        size--;
        int* temp_point = new int[size];
        for(int i = 0; i < size; i++){
            temp_point[i] = point[i];
        }

        delete[] point;
        point = temp_point;
        temp_point = nullptr;
        delete[] temp_point;
    }
    else std::cerr << std::endl <<"nie ma tablicy" << std::endl;
}


void Table::remove_from_pos(int pos) {

    if(pos == 0){
        remove_first();
    } else if(pos == size - 1){
        remove_last();
    } else if(pos > 0 && pos < size){
        int* temp_point = new int[size - 1];

        for(int i = 0; i < size; i++){
            if(i < pos){
                temp_point[i] = point[i];

            } else if( i > pos ){
                temp_point[i-1] = point[i];
            }
        }
        delete[] point;
        point = temp_point;
        temp_point = nullptr;
        delete[] temp_point;
        size--;
        std::cout<<"Usunieto z pocyji: "<<pos;
    }
    else std::cerr<<std::endl<<"nie ma pozycji w tablicy"<<std::endl;
}

void Table::print_table() {
    if(exist()){
        for(int i = 0; i < size; i++){
            std::cout<<i<<") "<< point[i] << std::endl;
        }
    } else std::cout << std::endl << " tablica nie istnieje "<< std::endl;
}

bool Table::exist() {
    return point != nullptr;
}

bool Table::search(int value) {

    for(int i = 0; i < size; i++){
        if(point[i] == value){
            return true;
        }
    }
    return false;
}

//sortowanie przez wstawianie zwykle
void Table::insertionSort() {
    int key, j;
    for (int i = 1; i < size; i++) {
        key = point[i];
        j = i - 1;

        while (j >= 0 && point[j] > key) {
            point[j + 1] = point[j];
            j = j - 1;
        }
        point[j + 1] = key;
    }
}

//sortowanie przez wstawianie binarne
int Table::binarySearchForInsertion(int item, int low, int high) {
    if (high <= low)
        return (item > point[low]) ? (low + 1) : low;

    int mid = (low + high) / 2;

    if (item == point[mid])
        return mid + 1;

    if (item > point[mid])
        return binarySearchForInsertion(item, mid + 1, high);
    else
        return binarySearchForInsertion(item, low, mid - 1);
}

//sortowanie przez kopcowanie
void Table::binaryInsertionSort() {
    int i, loc, j, k, selected;

    for (i = 1; i < size; ++i) {
        j = i - 1;
        selected = point[i];

        loc = binarySearchForInsertion(selected, 0, j);

        while (j >= loc) {
            point[j + 1] = point[j];
            j--;
        }
        point[j + 1] = selected;
    }
}

//sortowanie szybkie
void Table::quickSort(int low, int high) {
    if (low < high) {
        // pi to indeks partycjonowania, point[pi] jest już na odpowiednim miejscu
        int pi = partition(low, high);

        // Osobno sortujemy elementy przed
        // i po partycjonowaniu
        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}

int Table::partition(int low, int high) {
    int pivot = point[high]; // pivot
    int i = (low - 1); // Indeks mniejszego elementu

    for (int j = low; j <= high - 1; j++) {
        // Jeśli bieżący element jest mniejszy lub równy pivotowi
        if (point[j] <= pivot) {
            i++; // inkrementacja indeksu mniejszego elementu
            std::swap(point[i], point[j]);
        }
    }
    std::swap(point[i + 1], point[high]);
    return (i + 1);
}

// Metoda do wywoływania szybkiego sortowania
void Table::quickSortInit() {
    quickSort(0, size - 1);
}


int Table::getSize(){
    return size;
}

void Table::heapSort() {
    // Budowanie kopca (przekształcanie tablicy).
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(size, i);

    // Jeden po drugim wyodrębniamy elementy z kopca.
    for (int i = size - 1; i >= 0; i--) {
        // Przenoszenie obecnego korzenia na koniec.
        std::swap(point[0], point[i]);

        // Wywołanie procedury kopcowania na zmniejszonym kopcu.
        heapify(i, 0);
    }
}

// Funkcja do kopcowania poddrzewa z korzeniem w danym indeksie.
void Table::heapify(int n, int i) {
    int largest = i; // Inicjalizacja największego jako korzeń.
    int l = 2 * i + 1; // lewy = 2*i + 1.
    int r = 2 * i + 2; // prawy = 2*i + 2.

    // Jeśli lewy potomek jest większy niż korzeń.
    if (l < n && point[l] > point[largest])
        largest = l;

    // Jeśli prawey potomek jest większy niż największy dotychczas.
    if (r < n && point[r] > point[largest])
        largest = r;

    // Jeśli największy potomek nie jest korzeniem.
    if (largest != i) {
        std::swap(point[i], point[largest]);

        // Rekursywnie kopcowanie dotkniętego poddrzewa.
        heapify(n, largest);
    }
}