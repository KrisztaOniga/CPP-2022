//
// Created by Kriszta Oniga on 10/7/2022.
//

#include "Stack.h"

Stack::~Stack() {
    cout << "Stack Destruktor" << endl;
    while (top != 0) {
        pop();
    }

}

int Stack::pop() {
    if (top <= 0) {
        throw std::invalid_argument("Empty list\n");
    } else {
        top = top - 1;
        return top;
    }

}

void Stack::push(int e) {
    stack[top].insertFirst(e);
    top++;
}

bool Stack::isEmpty() const {
    if (top == 0) {
        return true;
    }
    return false;
}

void Stack::print() const {
    for (int i = 0; i < top; i++) {
        stack[i].print();
    }
}


//
//Stack::Stack(int size){
//    arr = new int[size];
//    capacity = size;
//    top = -1;
//}
//
//Stack::~Stack() {
//    delete[] arr;
//}
//
////kivesz egy elemet a verembol
//int Stack::pop() {
//    if (isEmpty()){
//        throw std::invalid_argument("The list is empty\n");
//    }
//
//    cout << "Torolve " << peek() << endl;
//
//    return arr[top--];
//
//}
//
////Visszateriti a legfelso elemet
//int Stack::peek(){
//    if (!isEmpty()) {
//        return arr[top];
//    }
//    else {
//        throw std::invalid_argument("The list is empty\n");
//    }
//}
//
////hozzaadja x-et a veremhez
//void Stack::push(int x) {
//    if (isFull()){
//        throw std::invalid_argument("The list is full\n");
//    }
//    cout << "Hozzaadva " << x << endl;
//    arr[++top] = x;
//}
//
//int Stack::size() {
//    return top + 1;
//}
//
//bool Stack::isEmpty() const {
//    return top == -1;
//}
//
//bool Stack::isFull() const {
//    return top == capacity - 1;
//}

