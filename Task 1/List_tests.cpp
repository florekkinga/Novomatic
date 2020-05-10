#include "List_tests.h"
#include "List.h"

/* TEST CASE 1
* dodanie elementu, który już jest w liście -> powoduje zwiększenie licznika wyszukiwań tego elementu o 1
* */

void test1(List<int> *myList) {
    cout << "----- TEST 1 -----" << endl;
    myList->add(2);
    myList->display();
}


/* TEST CASE 2
 * dostęp/ wyszukanie elementu w liście, który nie istnieje -> funkcja zwraca nullptr
 * */

void test2(List<int> *myList) {
    cout << "----- TEST 2 -----" << endl;
    Node<int> *x = myList->getNodeByData(893324);
    if (x == nullptr) cout << "OK\n" << endl;
}

/* TEST CASE 3
* usuwanie nieistniejącego w liście elementu
* */

void test3(List<int> *myList) {
    cout << "----- TEST 3 -----" << endl;
    myList->remove(10);
}