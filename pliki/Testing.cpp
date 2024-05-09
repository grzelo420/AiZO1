
//
// Created by Jakub Grzegocki on 07.04.2023.
//

#include "DataGenerator.h"
#include "Testing.h"
#include "Table.h"
#include "LinkedList.h"
#include "RedBlackTree.h"

#include <iostream>
#include <chrono>
#include <stdlib.h>
#include <string>


using namespace std;

void Testing::auto_test_all(){

    DataGenerator dataGenerator;
    //1,000 5,000 10,000 20,000 50,000
    int DataSize[7] = {5000, 10000, 20000, 30000, 40000, 50000, 60000};
    int DataSizeInsert[7]={1000,2000,3000,4000,5000, 10000, 15000};
    int testNumber = 10;
    system("cls");

    //cout<<"Dane wygenerowane losowo."<<endl;



    for(int i = 0 ; i < 7 ; i++){

        int n=DataSize[i];
        int ni=DataSizeInsert[i];
        cout<<n<<endl;

        float timesTab[4] ={0, 0, 0, 0};

        for(int j = 0; j < testNumber; j++){
            Table data;
            dataGenerator.generate(&data, n);
            data.quickSort(0,(n*0,6));
            auto start = std::chrono::high_resolution_clock ::now();
            data.quickSortInit();
            auto stop = std::chrono::high_resolution_clock::now();

            auto time = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
            timesTab[0] += time.count();
            cout<<j<<" ";
        }

        cout<<endl;

        for(int j = 0; j < testNumber; j++){
            Table data;
            dataGenerator.generate(&data, n);
            data.quickSort(0,(n*0,6));
            auto start = std::chrono::high_resolution_clock ::now();
            data.heapSort();
            auto stop = std::chrono::high_resolution_clock::now();

            auto time = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
            timesTab[1] += time.count();
            cout<<j<<" ";
        }

        cout<<endl;

        for(int j = 0; j < testNumber; j++){
            Table data;
            dataGenerator.generate(&data, ni);
            data.quickSort(0,(ni*0,6));
            auto start = std::chrono::high_resolution_clock ::now();
            data.insertionSort();
            auto stop = std::chrono::high_resolution_clock::now();

            auto time = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
            timesTab[2] += time.count();
            cout<<j<<" ";
        }


        cout<<endl;

        for(int j = 0; j < testNumber; j++){
            Table data;
            dataGenerator.generate(&data, ni);
            data.quickSort(0,(ni*0,3));
            auto start = std::chrono::high_resolution_clock ::now();
            data.binaryInsertionSort();
            auto stop = std::chrono::high_resolution_clock::now();

            auto time = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
            timesTab[3] += time.count();
            cout<<j<<" ";
        }

        cout<<endl<<"Wyniki" <<endl;
//        system("pause");
        cout<<"quick sort               "<<timesTab[0]/float(testNumber)<<endl;
//        system("pause");
        cout<<"Heap sort                "<<timesTab[1]/float(testNumber)<<endl;
        cout<<"Insertion sort           "<<timesTab[2]/float(testNumber)<<endl;
        cout<<"Binary Insertion sort    "<<timesTab[3]/float(testNumber)<<endl;

    }
//    cout<<"TABLICA"<<endl<<"==============="<<endl;
//    for(int i = 0; i < testNumber; i++){
//        cout<<endl<<"Liczba danych w strukturze: "<<DataSize[i]<<endl;
//        cout<<"             Liczba testow: "<<10<<endl<<endl;
//        auto_test_table(dataGenerator, DataSize, i);
//    }
//    cout<<"LISTA"<<endl<<"==============="<<endl;
//    for(int i = 0; i < testNumber; i++){
//        cout<<endl<<"Liczba danych w strukturze: "<<DataSize[i]<<endl;
//        cout<<"             Liczba testow: "<<10<<endl<<endl;
//        auto_test_list(dataGenerator, DataSize, i);
//    }
//    cout<<"KOPIEC"<<endl<<"==============="<<endl;
//    for(int i = 0; i < testNumber; i++){
//        cout<<endl<<"Liczba danych w strukturze: "<<DataSize[i]<<endl;
//        cout<<"             Liczba testow: "<<10<<endl<<endl;
//        auto_test_heap(dataGenerator, DataSize, i);
//    }
//    cout<<"DRZEWO"<<endl<<"==============="<<endl;
//    for(int i = 0; i < testNumber; i++){
//        cout<<endl<<"Liczba danych w strukturze: "<<DataSize[i]<<endl;
//        cout<<"             Liczba testow: "<<10<<endl<<endl;
//        auto_test_tree(dataGenerator, DataSize, i);
//    }

    system("pause");

}

//void Testing::auto_test_table(DataGenerator dataGenerator, int DataSize[5], int i) {
//    test_tab_add_first(dataGenerator,DataSize[i],10);
//    test_tab_add_last(dataGenerator,DataSize[i],10);
//    test_tab_add_on_pos(dataGenerator,DataSize[i],10);
//    test_tab_remove_first(dataGenerator,DataSize[i],10);
//    test_tab_remove_last(dataGenerator,DataSize[i],10);
//    test_tab_remove_from_pos(dataGenerator,DataSize[i],10);
//    test_tab_search(dataGenerator,DataSize[i],10);
//}
//
//void Testing::auto_test_list(DataGenerator dataGenerator, int *DataSize, int i) {
//    test_list_add_first(dataGenerator,DataSize[i],10);
//    test_list_add_last(dataGenerator,DataSize[i],10);
//    test_list_add_on_pos(dataGenerator,DataSize[i],10);
//    test_list_remove_first(dataGenerator,DataSize[i],10);
//    test_list_remove_last(dataGenerator,DataSize[i],10);
//    test_list_remove_on_pos(dataGenerator,DataSize[i],10);
//    test_list_search(dataGenerator,DataSize[i],10);
//}
//
//void Testing::auto_test_heap(DataGenerator dataGenerator, int *DataSize, int i) {
//    test_heap_add(dataGenerator,DataSize[i],10);
//    test_heap_remove(dataGenerator,DataSize[i],10);
//    test_heap_search(dataGenerator,DataSize[i],10);
//}
//
//void Testing::auto_test_tree(DataGenerator dataGenerator, int *DataSize, int i) {
//    test_tree_add(dataGenerator,DataSize[i],10);
//    test_tree_remove(dataGenerator,DataSize[i],10);
//    test_tree_search(dataGenerator,DataSize[i],10);
//}
//
//void Testing::test_tab_add_last(DataGenerator dataGenerator, int n, const int testNumber) {
//
//    auto totalTime = std::chrono::nanoseconds::zero();
//
//    for(int i = 0; i < testNumber; i++){
//        Table data;
//
//        dataGenerator.generate(&data, n);
//        int num = rand() % 1000;
//        auto start = std::chrono::high_resolution_clock ::now();
//        data.add_last(num);
//        auto stop = std::chrono::high_resolution_clock::now();
//        auto time = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
//        totalTime += time;
//        //delete data;
//    }
//    std::cout << (totalTime.count() / (double) testNumber) <<
//        " nanosekund - dodawanie na koniec" << std::endl;
//}
//
//void Testing::test_tab_add_first(DataGenerator dataGenerator, int n, const int testNumber) {
//
//    auto totalTime = std::chrono::nanoseconds::zero();
//
//    for(int i = 0; i < testNumber; i++){
//        Table data;
//
//        dataGenerator.generate(&data, n);
//        int num = rand() % 1000;
//
//        auto start = std::chrono::high_resolution_clock ::now();
//        data.add_first(num);
//        auto stop = std::chrono::high_resolution_clock::now();
//
//        auto time = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
//        totalTime += time;
//        //delete data;
//    }
//    std::cout << (totalTime.count() / (double) testNumber) <<
//              " nanosekund - dodawanie na poczatek" << std::endl;
//
//}
//
//void Testing::test_tab_add_on_pos(DataGenerator dataGenerator, int n, const int testNumber) {
//    auto totalTime = std::chrono::nanoseconds::zero();
//
//    for(int i = 0; i < testNumber; i++){
//        Table data;
//
//        dataGenerator.generate(&data, n);
//        int num = rand() % 1000;
//        int pos = rand() % n;
//        auto start = std::chrono::high_resolution_clock ::now();
//        data.add_on_pos(num, pos);
//        auto stop = std::chrono::high_resolution_clock::now();
//        auto time = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
//        totalTime += time;
//    }
//    std::cout <<(totalTime.count() / (double) testNumber) <<
//              " nanosekund - dodawanie na losowa pozycje" << std::endl;
//}
//
//void Testing::test_tab_remove_last(DataGenerator dataGenerator, int n, const int testNumber) {
//    auto totalTime = std::chrono::nanoseconds::zero();
//
//    for(int i = 0; i < testNumber; i++){
//        Table data;
//        dataGenerator.generate(&data, n);
//
//        auto start = std::chrono::high_resolution_clock ::now();
//        data.remove_last();
//        auto stop = std::chrono::high_resolution_clock::now();
//
//        auto time = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
//        totalTime += time;
//    }
//    std::cout << (totalTime.count() / (double) testNumber) <<
//              " nanosekund - usuwanie z konca" << std::endl;
//}
//
//void Testing::test_tab_remove_first(DataGenerator dataGenerator, int n, const int testNumber) {
//    auto totalTime = std::chrono::nanoseconds::zero();
//
//    for(int i = 0; i < testNumber; i++){
//        Table data;
//        dataGenerator.generate(&data, n);
//
//        auto start = std::chrono::high_resolution_clock ::now();
//        data.remove_first();
//        auto stop = std::chrono::high_resolution_clock::now();
//
//        auto time = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
//        totalTime += time;
//    }
//    std::cout << (totalTime.count() / (double) testNumber) <<
//              " nanosekund - usuwanie z poczatku" << std::endl;
//}
//
//void Testing::test_tab_remove_from_pos(DataGenerator dataGenerator, int n, const int testNumber) {
//
//    auto totalTime = std::chrono::nanoseconds::zero();
//
//    for(int i = 0; i < testNumber; i++){
//        Table data;
//        dataGenerator.generate(&data, n);
//
//        int pos = rand() % n;
//
//        auto start = std::chrono::high_resolution_clock ::now();
//        data.add_last(pos);
//        auto stop = std::chrono::high_resolution_clock::now();
//
//        auto time = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
//        totalTime += time;
//    }
//    std::cout << (totalTime.count() / (double) testNumber) <<
//              " nanosekund - usuwanie z losowej pozycji" << std::endl;
//}
//
//void Testing::test_tab_search(DataGenerator dataGenerator, int n, const int testNumber) {
//
//    auto totalTime = std::chrono::nanoseconds::zero();
//
//    for(int i = 0; i < testNumber; i++){
//        Table data;
//
//        dataGenerator.generate(&data, n);
//        int num = rand() % 10000;
//        auto start = std::chrono::high_resolution_clock ::now();
//        data.search(num);
//        auto stop = std::chrono::high_resolution_clock::now();
//        auto time = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
//        totalTime += time;
//    }
//    std::cout << (totalTime.count() / (double) testNumber) <<
//              " nanosekund - wyszukiwanie losowej liczby" << std::endl;
//
//}
//
//void Testing::test_list_add_first(DataGenerator dataGenerator, int n, const int testNumber) {
//
//    auto totalTime = std::chrono::nanoseconds::zero();
//
//    for(int i = 0; i < testNumber; i++){
//        LinkedList data;
//
//        dataGenerator.generate(&data, n);
//        int num = rand() % 10000;
//
//        auto start = std::chrono::high_resolution_clock ::now();
//        data.addAtBeginning(num);
//        auto stop = std::chrono::high_resolution_clock::now();
//
//        auto time = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
//        totalTime += time;
//    }
//    std::cout << (totalTime.count() / (double) testNumber) <<
//              " nanosekund - dodawanie na poczatek" << std::endl;
//
//}
//
//void Testing::test_list_add_last(DataGenerator dataGenerator, int n, const int testNumber) {
//
//    auto totalTime = std::chrono::nanoseconds::zero();
//
//    for(int i = 0; i < testNumber; i++){
//        LinkedList data;
//
//        dataGenerator.generate(&data, n);
//        int num = rand() % 10000;
//
//        auto start = std::chrono::high_resolution_clock ::now();
//        data.addAtEnd(num);
//        auto stop = std::chrono::high_resolution_clock::now();
//
//        auto time = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
//        totalTime += time;
//
//    }
//    std::cout << (totalTime.count() / (double) testNumber) <<
//              " nanosekund - dodawanie na koniec" << std::endl;
//
//}
//
//void Testing::test_list_add_on_pos(DataGenerator dataGenerator, int n, const int testNumber) {
//
//    auto totalTime = std::chrono::nanoseconds::zero();
//
//    for(int i = 0; i < testNumber; i++){
//        LinkedList data;
//
//        dataGenerator.generate(&data, n);
//        int num = rand() % 1000;
//        int pos = rand() % n;
//
//        auto start = std::chrono::high_resolution_clock ::now();
//        data.addAtPosition(num, pos);
//        auto stop = std::chrono::high_resolution_clock::now();
//
//        auto time = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
//        totalTime += time;
//    }
//    std::cout << (totalTime.count() / (double) testNumber) <<
//              " nanosekund - dodawanie na losowa pozycje" << std::endl;
//}
//
//void Testing::test_list_remove_first(DataGenerator dataGenerator, int n, const int testNumber) {
//    auto totalTime = std::chrono::nanoseconds::zero();
//
//    for(int i = 0; i < testNumber; i++){
//        LinkedList data;
//        dataGenerator.generate(&data, n);
//
//        auto start = std::chrono::high_resolution_clock ::now();
//        data.removeFromBeginning();
//        auto stop = std::chrono::high_resolution_clock::now();
//
//        auto time = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
//        totalTime += time;
//    }
//    std::cout << (totalTime.count() / (double) testNumber) <<
//              " nanosekund - usuwanie z poczatku" << std::endl;
//}
//
//void Testing::test_list_remove_last(DataGenerator dataGenerator, int n, const int testNumber) {
//    auto totalTime = std::chrono::nanoseconds::zero();
//
//    for(int i = 0; i < testNumber; i++){
//        LinkedList data;
//        dataGenerator.generate(&data, n);
//
//        auto start = std::chrono::high_resolution_clock ::now();
//        data.removeFromEnd();
//        auto stop = std::chrono::high_resolution_clock::now();
//
//        auto time = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
//        totalTime += time;
//    }
//    std::cout << (totalTime.count() / (double) testNumber) <<
//              " nanosekund - usuwanie z konca" << std::endl;
//}
//
//void Testing::test_list_remove_on_pos(DataGenerator dataGenerator, int n, const int testNumber) {
//    auto totalTime = std::chrono::nanoseconds::zero();
//
//    for(int i = 0; i < testNumber; i++){
//        LinkedList data;
//        dataGenerator.generate(&data, n);
//
//        int pos = rand() % n;
//
//        auto start = std::chrono::high_resolution_clock ::now();
//        data.removeFromPosition(pos);
//        auto stop = std::chrono::high_resolution_clock::now();
//
//        auto time = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
//        totalTime += time;
//    }
//    std::cout << (totalTime.count() / (double) testNumber) <<
//              " nanosekund - usuwanie z losowej pozycji" << std::endl;
//}
//
//void Testing::test_list_search(DataGenerator dataGenerator, int n, const int testNumber) {
//    auto totalTime = std::chrono::nanoseconds::zero();
//
//    for(int i = 0; i < testNumber; i++){
//        LinkedList data;
//        dataGenerator.generate(&data, n);
//
//
//        int num = rand() % 10000;
//
//        auto start = std::chrono::high_resolution_clock ::now();
//        data.searchValue(num);
//        auto stop = std::chrono::high_resolution_clock::now();
//
//        auto time = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
//        totalTime += time;
//    }
//    std::cout << (totalTime.count() / (double) testNumber) <<
//              " nanosekund - wyszukiwanie losowej liczby" << std::endl;
//}
//
//void Testing::test_heap_add(DataGenerator dataGenerator, int n, const int testNumber) {
//    auto totalTime = std::chrono::nanoseconds::zero();
//
//    for(int i = 0; i < testNumber; i++){
//        Heap data;
//
//        dataGenerator.generate(&data, n);
//        int num = rand() % 10000;
//
//        auto start = std::chrono::high_resolution_clock ::now();
//        data.add_element(num);
//        auto stop = std::chrono::high_resolution_clock::now();
//
//        auto time = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
//        totalTime += time;
//    }
//    std::cout << (totalTime.count() / (double) testNumber) <<
//              " nanosekund - dodawanie" << std::endl;
//}
//
//void Testing::test_heap_remove(DataGenerator dataGenerator, int n, const int testNumber) {
//    auto totalTime = std::chrono::nanoseconds::zero();
//
//    for(int i = 0; i < testNumber; i++){
//        Heap data;
//
//        dataGenerator.generate(&data, n);
//
//        auto start = std::chrono::high_resolution_clock ::now();
//        data.remove_heap_element();
//        auto stop = std::chrono::high_resolution_clock::now();
//
//        auto time = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
//        totalTime += time;
//    }
//    std::cout << (totalTime.count() / (double) testNumber) <<
//              " nanosekund - usuwanie" << std::endl;
//}
//
//void Testing::test_heap_search(DataGenerator dataGenerator, int n, const int testNumber) {
//    auto totalTime = std::chrono::nanoseconds::zero();
//
//    for(int i = 0; i < testNumber; i++){
//        Heap data;
//
//        dataGenerator.generate(&data, n);
//        int num = rand() % 10000;
//
//        auto start = std::chrono::high_resolution_clock ::now();
//        data.search(num);
//        auto stop = std::chrono::high_resolution_clock::now();
//
//        auto time = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
//        totalTime += time;
//    }
//    std::cout << (totalTime.count() / (double) testNumber) <<
//              " nanosekund - wyszukiwanie losowej wartosci" << std::endl;
//}
//
//void Testing::test_tree_add(DataGenerator dataGenerator, int n, const int testNumber){
//    auto totalTime = std::chrono::nanoseconds::zero();
//
//    for(int i = 0; i < testNumber; i++){
//        RedBlackTree data;
//
//        dataGenerator.generate(&data, n);
//        int num = rand() % 1000;
//
//        auto start = std::chrono::high_resolution_clock ::now();
//        data.addNode(num);
//        auto stop = std::chrono::high_resolution_clock::now();
//
//        auto time = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
//        totalTime += time;
//    }
//    std::cout << (totalTime.count() / (double) testNumber) <<
//              " nanosekund - dodawanie" << std::endl;
//}
//
//void Testing::test_tree_remove(DataGenerator dataGenerator, int n, const int testNumber) {
//    auto totalTime = std::chrono::nanoseconds::zero();
//
//    for(int i = 0; i < testNumber; i++){
//        RedBlackTree data;
//
//        dataGenerator.generate(&data, n);
//        int num = rand() % 1000;
//
//        auto start = std::chrono::high_resolution_clock ::now();
//        data.deleteNode(num);
//        auto stop = std::chrono::high_resolution_clock::now();
//
//        auto time = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
//        totalTime += time;
//    }
//    std::cout << (totalTime.count() / (double) testNumber) <<
//              " nanosekund - usuwanie" << std::endl;
//}
//
//void Testing::test_tree_search(DataGenerator dataGenerator, int n, const int testNumber) {
//    auto totalTime = std::chrono::nanoseconds::zero();
//
//    for(int i = 0; i < testNumber; i++){
//        RedBlackTree data;
//
//        dataGenerator.generate(&data, n);
//        int num = rand() % 10000;
//
//        auto start = std::chrono::high_resolution_clock ::now();
//        data.search(num);
//        auto stop = std::chrono::high_resolution_clock::now();
//
//        auto time = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
//        totalTime += time;
//    }
//    std::cout << (totalTime.count() / (double) testNumber) <<
//              " nanosekund - wyszukiwanie losowej wartosci" << std::endl;
//}
//
//void Testing::test_tree_dialog(){
//    RedBlackTree tree;
//    int c = 20;
//    int value;
//
//    while (c != 0) {
//
//        system("cls");
//        cout << endl << "Wybierz operacje dla kopca: " << endl<< endl;
//        cout << "1) dodaj element" << endl;
//        cout << "2) usun" << endl;
//        cout << "3) wyszukaj wartosc" << endl;
//        cout << "4) wypisz zawartosc" << endl;
//        cout << "5) wczytanie z pliku" << endl;
//        cout << "0) powrot" << endl<< endl;
//        cout << "Twoj wybor: " << endl;
//
//        cin >> c;
//
//        system("cls");
//
//        switch (c) {
//            case 0:
//                return;
//            case 1:
//                cout << "Podaj wartosc: ";
//                cin >> value;
//                tree.addNode(value);
//                break;
//            case 2:
//                cout << "Podaj wartosc do usuniecia: ";
//                cin >> value;
//                tree.deleteNode(value); break;
//            case 3:
//                cout << "Podaj wartosc do wyszukania: ";
//                cin >> value;
//                if(tree.search(value))
//                {cout<<"Znaleziono wartosc"<<endl;}
//                else
//                {cout<<"Nie znaleziono wartosci"<<endl;}
//                system("pause");
//                break;
//                case 4:
//                tree.display(); system("pause"); break;
//            case 5:;
//                tree.loadFromFile("C:/Users/Jakub Grzegocki/CLionProjects/SDIZO/values.txt"); break;
//        }
//    }
//}
//
//void Testing::test_table_dialog() {
//
//    Table tab;
//
//    int c = 20;
//    int value = 0;
//    int pos;
//    string stream;
//
//    while(c!=0) {
//        system("cls");
//        cout << endl << "Wybierz operacje dla tablicy: " << endl<< endl;
//        cout << "1) dodaj na poczatku" << endl;
//        cout << "2) dodaj na koncu" << endl;
//        cout << "3) dodaj na pozycji" << endl;
//        cout << "4) usun z poczatku" << endl;
//        cout << "5) usun z konca" << endl;
//        cout << "6) usun z pozycji" << endl;
//        cout << "7) wyszukaj wartosc" << endl;
//        cout << "8) wypisz zawartosc" << endl;
//        cout << "9) wczytanie z pliku" << endl;
//        cout << "0) powrot" << endl<< endl;
//        cout << "Twoj wybor: " << endl;
//
//        cin>>c;
//
//        system("cls");
//
//        switch(c){
//            case 0: return;
//            case 1: cout<<"Podaj wartosc: "; cin>>value; tab.add_first(value); break;
//            case 2: cout<<"Podaj wartosc: "; cin>>value; tab.add_last(value); break;
//            case 3: cout<<"Podaj wartosc: "; cin>>value; cout<<"Podaj pozycje"; cin>>pos; tab.add_on_pos(value, pos); break;
//            case 4: tab.remove_first(); cout<<"Usunieto z poczatku"; _sleep(1000); break;
//            case 5: tab.remove_last();  cout<<"Usunieto z konca"; _sleep(1000); break;
//            case 6: cout<<"Podaj pozycje: "; cin>>pos; tab.remove_from_pos(pos);  _sleep(1000); break;
//            case 7: cout<<"Podaj wartosc do wyszukania: ";
//                    cin>>value;
//                    if(tab.search(value))
//                    {cout<<"Znaleziono wartosc"<<endl;}
//                    else
//                    {cout<<"Nie znaleziono wartosci"<<endl;}
//                    system("pause");
//                    break;
//            case 8: tab.print_table(); system("pause"); break;
//            case 9: tab.loadTable("C:/Users/Jakub Grzegocki/CLionProjects/SDIZO/values.txt"); break;
//        }
//    }
//}
//
//void Testing::test_heap_dialog() {
//
//    Heap heap;
//    int c = 20;
//
//    int value;
//
//    while (c != 0) {
//
//        system("cls");
//        cout << endl << "Wybierz operacje dla kopca: " << endl << endl;
//        cout << "1) dodaj element" << endl;
//        cout << "2) usun" << endl;
//        cout << "3) wyszukaj wartosc" << endl;
//        cout << "4) wypisz zawartosc" << endl;
//        cout << "5) wczytanie z pliku" << endl;
//        cout << "0) powrot" << endl<<endl;
//        cout << "Twoj wybor: " << endl;
//
//        cin >> c;
//
//        system("cls");
//
//        switch (c) {
//            case 0:
//                return;
//            case 1:
//                cout << "Podaj wartosc: ";
//                cin >> value;
//                heap.add_element(value); break;
//            case 2:
//                heap.remove_heap_element(); break;
//            case 3:
//                cout << "Podaj wartosc: ";
//                cin >> value;
//                if(heap.search(value)){
//                    cout<<"Znaleziono wartosc";
//                } else {
//                    cout<<"Nie znaleziono wartosci";
//                }
//                system("pause");
//                break;
//            case 4:
//                heap.print_heap(); system("pause"); break;
//            case 5:
//                heap.load_heap("C:/Users/Jakub Grzegocki/CLionProjects/SDIZO/values.txt"); break;
//        }
//    }
//}
//
//void Testing::test_list_dialog() {
//
//    LinkedList list;
//
//    int value = 0;
//    int c = 20;
//    int pos = 0;
//    string stream;
//
//    while(c != 0) {
//        system("cls");
//        cout << endl << "Wybierz operacje dla listy: " << endl<< endl;
//        cout << "1) dodaj na poczatku" << endl;
//        cout << "2) dodaj na koncu" << endl;
//        cout << "3) dodaj na pozycji" << endl;
//        cout << "4) usun z poczatku" << endl;
//        cout << "5) usun z konca" << endl;
//        cout << "6) usun z pozycji" << endl;
//        cout << "7) wyszukaj wartosc" << endl;
//        cout << "8) wypisz zawartosc" << endl;
//        cout << "9) wczytanie z pliku" << endl;
//        cout << "0) powrot" << endl<< endl;
//        cout << "Twoj wybor: " << endl;
//
//        cin>>c;
//
//        system("cls");
//
//        switch(c){
//            case 0: return;
//            case 1: cout<<"Podaj wartosc: "; cin>>value; list.addAtBeginning(value); break;
//            case 2: cout<<"Podaj wartosc: "; cin>>value; list.addAtEnd(value); break;
//            case 3: cout<<"Podaj wartosc: "; cin>>value; cout<<"Podaj pozycje: ";
//                    cin>>pos;
//                    list.addAtPosition(value, pos);
//                    break;
//            case 4: list.removeFromBeginning(); cout<<"Usunieto pierwszy element"; _sleep(1000); break;
//            case 5: list.removeFromEnd(); cout<<"Usunieto ostatni element"; _sleep(1000); break;
//            case 6: cout<<"Podaj pozycje: "; cin>>pos; list.removeFromPosition(pos); cout<<"usunieto z pozycji "<<pos; _sleep(1000); break;
//            case 7: cout<<"Podaj wartosc do wyszukania: ";
//            cin>>value;
//            if(list.searchValue(value))
//            {cout<<"Znaleziono wartosc"<<endl;}
//            else
//            {cout<<"Nie znaleziono wartosci"<<endl;}
//            system("pause");
//            break;
//            case 8: list.displayList(); system("pause"); break;
//            case 9: list.loadFromFile("C:/Users/Jakub Grzegocki/CLionProjects/SDIZO/values.txt"); break;
//        }
//    }
//}
