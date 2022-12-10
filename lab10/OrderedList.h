//
// Created by Kriszta Oniga on 11/23/2022.
//

#ifndef CPP_2022_ORDEREDLIST_H
#define CPP_2022_ORDEREDLIST_H

#include <functional>
#include <iostream>
using namespace std;

// Class declaration
template< class T, class LessComp=less<T>, class Equal=equal_to<T> >
class Iterator;

// Class definition
template<class T, class LessComp = less<T>, class Equal = equal_to<T> >
class OrderedList {
private:
    struct Node {
        T value;
        Node *next;

        Node(T t, Node *node) : value(t), next(node) {}
    };

    friend class Iterator<T, LessComp, Equal>;

    Node *first{nullptr};
    int numElements{0};

public:
    OrderedList();

    virtual ~OrderedList();

    bool isEmpty();

    void insert(T &);

    void remove(T &);

    int size();

    void listItems(ostream &);

    bool find(const T &what);
};

// Class definition
template<class T, class LessComp, class Equal>
class Iterator {
private:
    OrderedList<T, LessComp, Equal> &list;
    typename OrderedList<T, LessComp, Equal>::Node *act;

public:
    Iterator(OrderedList<T, LessComp, Equal> &orderedList);

    bool hasNext();

    T next();

};

template<class T, class LessComp, class Equal>
Iterator<T, LessComp, Equal>::Iterator(OrderedList<T, LessComp, Equal> &orderedList) :list(orderedList), act(orderedList.first) {}

template<class T, class LessComp, class Equal>
bool Iterator<T, LessComp, Equal>::hasNext() {
    if ( act->next == nullptr ) {
        return false;
    }
    return true;
}

template<class T, class LessComp, class Equal>
T Iterator<T, LessComp, Equal>::next() {
    act = act->next;
    return act->value;
}
template<class T, class LessComp, class Equal>
OrderedList<T, LessComp, Equal>::OrderedList() {
    this->first = nullptr;
    this->numElements = 0;
}

template<class T, class LessComp, class Equal>
OrderedList<T, LessComp, Equal>::~OrderedList() {
    Node *temp = this->first;
    while (temp) {
        temp = first->next;
        delete this->first;
        this->first = temp;
    }
    temp = nullptr;
    this->first = nullptr;
}

template<class T, class LessComp, class Equal>
bool OrderedList<T, LessComp, Equal>::isEmpty() {
    return 0 == this->numElements;
}

template<class T, class LessComp, class Equal>
int OrderedList<T, LessComp, Equal>::size() {
    return this->numElements;
}

template<class T, class LessComp, class Equal>
void OrderedList<T, LessComp, Equal>::listItems(ostream &os) {
    Node *temp = this->first;
    while (temp) {
        os << temp->value << " ";
        temp = temp->next;
    }
    temp = nullptr;
    os << endl;
}

template<class T, class LessComp, class Equal>
void OrderedList<T, LessComp, Equal>::insert(T &t) {
    Node *newNode = new Node(t, nullptr);

    //ures lista
    if (this->isEmpty()) {
        this->first = newNode;
        ++this->numElements;
        return;
    } else if (LessComp()(t, this->first->value)) {
//        Node *temp = this->first;
//        this->first = newNode;
//        this->first->next = temp;
//lista elejere
        newNode->next = this->first;
        this->first = newNode;
        ++this->numElements;
        return;
    }

    Node *tempFirst = this->first;
    Node *tempSecond = this->first->next;

    while (tempSecond && LessComp()(tempSecond->value, t)) {
        tempFirst = tempSecond;
        tempSecond = tempSecond->next;
    }

    tempFirst->next = newNode;
    if (tempSecond) {
        newNode->next = tempSecond;
    }
    ++this->numElements;

    tempFirst = nullptr;
    tempSecond = nullptr;

//    Node* newElement = new Node(what, nullptr);
//    //ures lista
//    if( first == nullptr ){
//        first = newElement;
//        ++numElements;
//        return;
//    }
//
//    Node *prev = nullptr;
//    Node *act = first;
//
//    while( act != nullptr && LessComp()(act->value, what)){
//        prev = act;
//        act = act->next;
//    }
//
//    //Listafej ele
//    if( prev == nullptr ){
//        newElement->next = first;
//        first = newElement;
//        ++numElements;
//        return;
//    }
//
//    prev->next = newElement;
//    newElement->next = act;
//    ++numElements;
//}
}

template<class T, class LessComp, class Equal>
void OrderedList<T, LessComp, Equal>::remove(T &t) {
    Node *previous = first;
    Node *act = first;

    while( act != nullptr ){
        if( act->value == t && act == first ) {
            first = act->next;
            delete act;
            act = first;
            continue;
        }

        if ( act->value == t ) {
            previous->next = act->next;
            delete act;
            act = previous->next;
            continue;
        }

        previous = act;
        act = act->next;
    }
    previous = nullptr;
}

template<class T, class LessComp, class Equal>
bool OrderedList<T, LessComp, Equal>::find(const T &what) {
    Node *act = this->first;

    while ( act != nullptr ) {
        if ( Equal()(act->value, what)){
            return true;
        }
        act  = act->next;
    }

    return false;

}

#endif //CPP_2022_ORDEREDLIST_H
