#include <iostream>

using namespace std;

#include "List.h"
#include "Stack.h"

int main() {

    List *list = new List();

    list->insertFirst(4);
    list->insertFirst(2);
    list->insertFirst(7);
    list->insertFirst(1);

    list->print();

//    try{
//        list->removeFirst();
//        list->removeFirst();
//        list->removeFirst();
//        list->removeFirst();
//        list->removeFirst();
//
//    }catch (std::invalid_argument error){
//        cout<<endl<< error.what();
//    }

    list->remove(1, List::DeleteFlag::EQUAL);
    cout << endl;
    list->print();

    cout << endl;

    Stack myStack;
    int e;
    cout << "Enter number of elements in stack:";
    cin >> e;
    for ( int i = 0; i < e; i++) {
        myStack.push(i);
    }

    cout << "Is the stack empty? ";
    cout << myStack.isEmpty() << endl;

    for(int i = 0; i < e; i++) {
        cout << myStack.pop() << endl;
    }
    cout << "Is the stack empty? ";
    cout << myStack.isEmpty() << endl;

    return 0;
}
