//
// Created by Kriszta Oniga on 11/23/2022.
//

#ifndef CPP_2022_ORDEREDLIST_H
#define CPP_2022_ORDEREDLIST_H

#include <functional>
#include <iostream>

using namespace std;

// Class definition
template<class T, class LessComp = less<T>, class Equal = equal_to<T> >
class OrderedList {
private:
    struct Node {
        T value;
        Node *next;

        Node(T t, Node *node) : value(t), next(node) {}
    };

    Node *first{nullptr};
    int numElements{0};
public:
    OrderedList();

    virtual ~OrderedList();

    bool isEmpty();

    void insert(T &);

    void remove(T &);

    int size();

    bool find(T &) const;

    void listItems(ostream &);

};

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
    if (this->isEmpty()) {
        cout<<endl<<"The list is empty"<< endl;
        return;
    }
    Node *p = first;

    for ( Node *x = first; x ; x = x->next) {

        if( (x->value < t) || (x->value == t) || (x->value > t) ) {
            p->next = x->next;
            return;
        }
        p = x;
    }
}

template<class T, class LessComp, class Equal>
bool OrderedList<T, LessComp, Equal>::find(T & t) const {
    Node *temp = this->first;
    while(temp){
        if(temp->value == t) return true;
        temp = temp->next;
    }
    temp = nullptr;
    return false;
}

#endif //CPP_2022_ORDEREDLIST_H
