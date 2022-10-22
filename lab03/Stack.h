//
// Created by Kriszta Oniga on 10/7/2022.
//

#ifndef CPP_2022_STACK_H
#define CPP_2022_STACK_H

#include <iostream>
#include "List.h"

using namespace std;

#define max 100


#define MAX 1000

class Stack {
private:
    List data;
public:
    Stack() {};
    void push(int e);
    int pop();
    bool isEmpty() const;
};


//class Stack {
//    int top;
//
//public:
//    Stack() {
//        cout << "Stack Konstruktor" << endl;
//        top = 0;
//    }
//
//    ~Stack();
//
//    void push(int e);
//
//    int pop();
//
//    bool isEmpty() const;
//
//    void print() const;
//
//
//private:
//    List stack[max];
//};

//
//class Stack {
//    List *stack;
//
//public:
//    Stack(int size = max);
//
//    ~Stack();
//
//    void push(int e);
//
//    int pop();
//
//    int peek();
//
//    int size();
//
//    bool isEmpty() const;
//    bool isFull() const;
//
//private:
//    int *arr;
//    int top;
//    int capacity;
//
//};



#endif //CPP_2022_STACK_H
