#ifndef NOVOMATIC_LIST_H
#define NOVOMATIC_LIST_H

/* Zdecydowałam się na implementację dwukierunkowej listy, która w swoich węzłach oprócz obiektów i wskaźników na
 * poprzedni/następny węzeł przechowuje ilość wyszukiwań/ dostępu do danego obiektu. Licznik ten zwiększam przy każdym
 * użyciu metod getNodeByData lub getNodeByIndex. Dodatkowo, jeżeli dodamy do listy obiekt, który już się w niej
 * znajduje licznik użycia również jest zwiększany. Za zwiększanie licznika odpowiada prywatna metoda update, która
 * oprócz tego zajmuje się zamianą miejsc elementów w liście (jeżeli, któryś element w danym momencie przekroczy
 * ilość wyszukiwań innego elementu) przy pomocy metody swapNodes. Prywatna metoda getNode to pomocnicza funkcja
 * używana przez metody klasy List do wyszukiwania obiektu po zawartości. Od metody getNodeByData (używanej przez
 * użytkownika) różni się tym, że nie korzysta z funkcji update.
 *
 * k-popularny element, to taki który został update'owany k razy. Zauważam, że zachodzi niezmiennik: czas dostępu do
 * elementu k-popularnego wynosi O(k). Jak to w przypadku list, złożoność dostępu do elementu pesymistycznie wynosi
 * O(n), gdzie n to ilość elementów obecnych w liście.
 */

#include <iostream>

using namespace std;

template<class T>
struct Node {
    T data;
    int counter = 0;
    struct Node *prev = nullptr;
    struct Node *next = nullptr;

    Node(T data) : data(data) {}
};

template<class T>
class List {
    Node<T> *head = nullptr;
    Node<T> *tail = nullptr;

    Node<T> *getNode(T target);

    void update(Node<T> *curr);

    void swapNodes(Node<T> *prev, Node<T> *curr);

public:
    List() = default;

    void add(T x);

    void remove(T x);

    void display();

    Node<T> *getNodeByData(T data);

    Node<T> *getNodeByIndex(int index);

    ~List();
};


template<class T>
void List<T>::add(T x) {
    Node<T> *node = getNode(x);
    if (node != nullptr) {
        cout << "This element already exists in your list. \nThe usage counter has been increased by one.\n" << endl;
        update(node);
    } else {
        Node<T> *newNode = new Node<T>(x);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
}

template<class T>
void List<T>::remove(T x) {
    Node<T> *tmp = getNode(x);
    if (tmp == nullptr) {
        cout << "This element does not exist in your list.\nNothing has been removed.\n" << endl;
        return;
    } else if (tmp == head && tmp == tail) {
        head = nullptr;
        tail = nullptr;
    } else if (tmp == head) {
        tmp->next->prev = nullptr;
        head = tmp->next;
    } else if (tmp == tail) {
        tmp->prev->next = nullptr;
        tail = tmp->prev;
    } else {
        Node<T> *prev = tmp->prev;
        Node<T> *next = tmp->next;
        prev->next = next;
        next->prev = prev;
    }
    delete tmp;
}

template<class T>
void List<T>::display() {
    cout << "Your list:" << endl;
    if (!head) cout << "Your list is empty" << endl;
    else {
        Node<T> *tmp = head;
        int i = 0;
        while (tmp != nullptr) {
            cout << "Element no. " << i << "\t Data: " << tmp->data << "\t Times used: " << tmp->counter << endl;
            tmp = tmp->next;
            i++;
        }
        cout << endl;
    }
}

template<class T>
Node<T> *List<T>::getNodeByData(T data) {
    Node<T> *tmp = getNode(data);
    if (tmp == nullptr) return nullptr;
    update(tmp);
    return tmp;
}

template<class T>
Node<T> *List<T>::getNodeByIndex(int index) {
    Node<T> *tmp = head;
    for (int i = 0; i <= index; i++) {
        if (tmp == nullptr) return nullptr;
        if (i == index) {
            update(tmp);
            return tmp;
        }
        tmp = tmp->next;
    }
}

template<class T>
List<T>::~List() {
    if (head == nullptr) return;
    Node<T> *prev;
    Node<T> *curr = head;
    while (curr) {
        prev = curr;
        curr = curr->next;
        delete prev;
    }
}

template<class T>
Node<T> *List<T>::getNode(T target) {
    Node<T> *tmp = head;
    while (tmp) {
        if (tmp->data == target) return tmp;
        tmp = tmp->next;
    }
    return nullptr;
}

template<class T>
void List<T>::update(Node<T> *curr) {
    curr->counter++;
    while (curr->prev && (curr->prev->counter < curr->counter))
        swapNodes(curr->prev, curr);
}

template<class T>
void List<T>::swapNodes(Node<T> *prev, Node<T> *curr) {
    Node<T> *tmp = curr->next;
    curr->prev = prev->prev;
    curr->next = prev;
    prev->prev = curr;
    prev->next = tmp;
    if (tmp) tmp->prev = prev;
    else tail = prev;
    if (curr->prev) curr->prev->next = curr;
    else head = curr;
}

#endif
