#include <iostream>
#include <vector>
#include <array>
#include "Task 1/List.h"
#include "Task 2/pickMorphs.h"
#include "Task 1/List_tests.h"
#include "Task 2/pickMorphs_tests.h"

int main() {
    cout << "***** TASK 1: implementacja samoorganizującej się listy ***** \n" << endl;

    /* tworzenie listy, dodawanie elementów, wyświetlanie listy, usuwanie elementów */
    List<int> *myList = new List<int>();

    myList->add(1);
    myList->add(2);
    myList->add(3);
    myList->add(4);
    myList->add(5);

    myList->display();

    /* dostęp/ wyszukiwanie elementów po zawartości */
    for (int i = 0; i < 20; i++) {
        myList->getNodeByData(2);
        if (i % 2 == 0) myList->getNodeByData(4);
        if (i % 3 == 0) myList->getNodeByData(1);
        if (i % 5 == 0) myList->getNodeByData(5);
    }

    /* dostęp/ wyszukiwanie elementów po numerze indeksu (indeks 0 - najczęściej wyszukiwany element) */
    myList->getNodeByIndex(2);
    myList->getNodeByIndex(0);

    myList->remove(3);
    myList->display();

    /* opis testów znajduje się w pliku List_tests.cpp */
    test1(myList);
    test2(myList);
    test3(myList);

    delete myList;

    cout << "***** TASK 2:  implementacja funkcji pickMorphs *****" << endl;

    /* opis testów znajduje się w pliku pickMorphs_tests.cpp */
    test1();
    test2();
    test3();

    return 0;
}