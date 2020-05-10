#include <iostream>
#include <array>
#include "pickMorphs_tests.h"
#include "pickMorphs.h"

/* TEST CASE 1
 * wektor weights zawiera mniej niż 4 elementy -> funkcja zwraca {-1,-1,-1,-1}
 * jeżeli źle zrozumiałam treść i funkcja powinna najpierw zwrócić indeksy elementów, a potem -1
 * (np. {2, 0, 1, -1}) to wystarczy usunąć pierwszego if'a
 * */
void test1() {
    cout << "----- TEST 1 -----" << endl;
    array<int, 4> test1 = pickMorphs({0.9, 0.7, 0.99});
    for (int i : test1) cout << i << " ";
    cout << "\n" << endl;
}

/* TEST CASE 2
 * wektor weights zawiera wszystkie elementy o takiej samej wartości -> funkcja zwraca indeksy czterech ostatnich
 * */
void test2() {
    cout << "----- TEST 2 -----" << endl;
    array<int, 4> test2 = pickMorphs({0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9});
    for (int i : test2) cout << i << " ";
    cout << "\n" << endl;
}

/* TEST CASE 3
 * wektor weights zawiera różne elementy -> funkcja zwraca indeksy elementów zaczynając od największej wagi
 * */
void test3() {
    cout << "----- TEST 3 -----" << endl;
    array<int, 4> test3 = pickMorphs({0.7, 0.2, 0.6, 0.4, 0.9, 0.4, 0.5});
    for (int i : test3) cout << i << " ";
    cout << "\n" << endl;
}