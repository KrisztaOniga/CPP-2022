#include <iostream>
using namespace std;

#include "List.h"

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

list->remove(7, List::DeleteFlag::EQUAL);
cout<<endl;
list->print();

    return 0;
}