#include <iostream>
//#include <stdlib.h>
#include <chrono>
#include <cstdlib>
#include "Testing.h"
#include <fstream>
#include "DataGenerator.h"
#include "Table.h"

using namespace std;

void goodbye();


void performSort(Table& table, int sortType, int low = 0, int high = -1) {
    if (high == -1) high = table.getSize() - 1; // Jeśli nie określono, sortuj całą tablicę
    auto start = std::chrono::high_resolution_clock::now();

    switch (sortType) {
        case 1:
            table.insertionSort(); // Sortowanie przez wstawianie
            break;
        case 2:
            table.binaryInsertionSort(); // Sortowanie przez wstawianie binarne
            break;
        case 3:
            table.heapSort(); // Sortowanie przez kopcowanie
            break;
        case 4:
            if (low != 0 || high != table.getSize() - 1) {
                table.quickSort(low, high); // Sortowanie szybkie na fragmencie
            } else {
                table.quickSortInit(); // Sortowanie szybkie na całej tablicy
            }
            break;
        default:
            std::cout << "Nieznany typ sortowania.\n";
            return;
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Czas sortowania: " << elapsed.count() << "s\n";
}

int main() {

    Table table;
    DataGenerator generator;
    int choice, sortType, low, high;
    std::string filename;

    while (true) {
        std::cout << "\n=== MENU ===\n";
        std::cout << "1. Wczytaj tablice z pliku\n";
        std::cout << "2. Generuj dane do tablicy\n";
        std::cout << "3. Wybierz i wykonaj sortowanie na całej tablicy\n";
        std::cout << "4. Wybierz i wykonaj sortowanie na fragmencie tablicy\n";
        std::cout << "5. Wyswietl tablice\n";
        std::cout << "6. Test\n";
        std::cout << "7. Wyjdz\n";
        std::cout << "Wybor: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Podaj nazwe pliku: ";
                std::cin >> filename;
                table.loadTable(filename);
                break;
            case 2:
                std::cout << "Podaj ilosc elementow do wygenerowania: ";
                std::cin >> low; // Zmienna 'low' używana tymczasowo dla ilości
                generator.generate(&table, low)  ; // Zakładamy, że jest taka funkcja
                break;
            case 3:
                std::cout << "Wybierz sortowanie: 1-Insertion, 2-Binary Insertion, 3-Heap, 4-Quick: ";
                std::cin >> sortType;
                performSort(table, sortType);
                break;
            case 4:
                std::cout << "Podaj dolny zakres: ";
                std::cin >> low;
                std::cout << "Podaj gorny zakres: ";
                std::cin >> high;
                std::cout << "Wybierz sortowanie: 1-Insertion, 2-Binary Insertion, 3-Heap, 4-Quick: ";
                std::cin >> sortType;
                if (low < high && low >= 0 && high <= table.getSize()) {
                    performSort(table, sortType, low, high);
                } else {
                    std::cout << "Nieprawidlowy zakres.\n";
                }
                break;
            case 5:
                table.print_table();
                break;
            case 6:
                Testing test;
                test.auto_test_all();
                break;
            case 7:
                return 0;
            default:
                std::cout << "Nieznane polecenie.\n";
        }
    }


//    Testing test;
//
//    char choice = ' ';
//    while(choice != 'e') {
//
//        system("cls");
//        cout << "projekt SDIZO - struktury danych" << endl;
//        cout << "dostepne struktury:" << endl;
//        cout << endl;
//        cout << "1) Lista dwukierunkowa wiazana" << endl;
//        cout << "2) Tablica dynamiczna" << endl;
//        cout << "3) Kopiec binarny typu maksymalnego" << endl;
//        cout << "4) Drzewo czerwono-czarne" << endl;
//        cout << "5) Automatyczny test wszystkich struktur" << endl;
//        cout << "e) Exit"<<endl<<endl;
//        cout << "Twoj wybor: ";
//
//        cin >> choice;
//
//        switch(choice){
//            case 'e':  goodbye(); return 0;
//            case '1':  test.test_list_dialog(); break;
//            case '2':  test.test_table_dialog(); break;
//            case '3':  test.test_heap_dialog(); break;
//            case '4':  test.test_tree_dialog(); break;
//            case '5':  test.auto_test_all(); break;
//        }
//    }


    goodbye();
    return 0;
}

void goodbye(){

    char goodbye[10] = {'D','o','w','i','d','z','e','n','i','a'};
    system("cls");
    for(int i = 0; i < 10; i++){
        _sleep(10*i);
        cout<<goodbye[i];
    }
    _sleep(1000);

}