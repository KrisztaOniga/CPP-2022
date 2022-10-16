//
// Created by Kriszta Oniga on 10/6/2022.
//

#include "List.h"

List::List() {
    this->first = nullptr;
}

List::~List() {
    Node *temp = first;
    while (temp) {
        temp = first->next;
        delete first;
        first = temp;
    }
    temp = nullptr;
    nodeCounter = 0;
}

bool List::exists(int d) const {
    Node *temp = this->first;
    while(temp){
        if(temp->value == d) return true;
        temp = temp->next;
    }
    temp = nullptr;
    return false;
}

int List::size() const {
    return this->nodeCounter;
}

bool List::empty() const {
    return this->nodeCounter == 0;
}

void List::insertFirst(int d) {
    Node *newNode = new Node(d, this->first);
    this->first = newNode;
    ++nodeCounter;
}

int List::removeFirst() {
    if (this->empty()) {
        throw std::invalid_argument("Empty list\n");
    }
    else if(nodeCounter == 1){
        int tempValue = this->first->value;
        delete this->first;
        this->first = nullptr;
        --nodeCounter;
        return tempValue;
    }
    Node *tempNode = this->first->next;
    int tempValue = this->first->value;
    delete this->first;
    this->first = tempNode;
    tempNode = nullptr;
    --nodeCounter;
    return tempValue;
}

void List::remove(int d, DeleteFlag df){
    switch (df) {
        case DeleteFlag::LESS:{
            Node *temp = this->first;

            while(temp){
                if(temp->value < d){
                    //torles
                }
                temp = temp->next;
            }
            temp = nullptr;
            break;
        }
        case DeleteFlag::EQUAL:{
            Node *temp = this->first;

            while(temp){
                if(temp->value == d){
                    //torles
                }
                temp = temp->next;
            }
            temp = nullptr;
            break;
        }
        case DeleteFlag::GREATER:{
            Node *temp = this->first;

            while(temp){
                if(temp->value > d){
                    //torles
                }
                temp = temp->next;
            }
            temp = nullptr;
            break;
        }
        default:{
            break;
        }
    }
}


//void List::remove(int d, List::DeleteFlag df) {
//    Node *temp = nullptr, *temp1 = first, *temp2 = temp1->next;
//
//    while (temp1) {
//        temp2 = temp1->next;
//        if (df == DeleteFlag::LESS) {
//            if (temp1->value < d) {
//                if (temp == nullptr) {
//                    temp = temp1;
//                    delete temp;
//                    nodeCounter--;
//                    if(temp2 != nullptr && temp2->next != nullptr){
//                        temp1 = temp1->next;
//                        temp2 = temp2->next;
//                        temp = nullptr;
//                    }
//                    temp = nullptr;
//
//                } else if (temp2 == nullptr) {
//                    temp->next = nullptr;
//                    delete temp1;
//                    nodeCounter--;
//                    temp1 = temp;
//                } else {
//                    temp->next = temp2;
//                    delete temp1;
//                    nodeCounter--;
//                    temp1 = temp2;
//                    temp2 = temp2->next;
//                }
//                temp = temp1;
//                if (temp1) {
//                    temp1 = temp1->next;
//                    if (temp2) {
//                        temp2 = temp2->next;
//                    }
//                }
//            }
//        } else if (df == DeleteFlag::GREATER) {
//            if (temp1->value > d) {
//                if (temp == nullptr) {
//                    temp = temp1;
//                    delete temp;
//                    nodeCounter--;
//                    if(temp2 != nullptr && temp2->next != nullptr){
//                        temp1 = temp1->next;
//                        temp2 = temp2->next;
//                        temp = nullptr;
//                    }
//
//                } else if (temp2 == nullptr) {
//                    temp->next = nullptr;
//                    delete temp1;
//                    nodeCounter--;
//                    temp1 = temp;
//                } else {
//                    temp->next = temp2;
//                    delete temp1;
//                    nodeCounter--;
//                    temp1 = temp2;
//                    temp2 = temp2->next;
//                }
//            }
//            temp = temp1;
//            if (temp1) {
//                temp1 = temp1->next;
//                if (temp2) {
//                    temp2 = temp2->next;
//                }
//            }
//        }
//        else if (df == DeleteFlag::EQUAL) {
//            if (temp1->value == d) {
//                if (temp == nullptr) {
//                    temp = temp1;
//                    delete temp;
//                    nodeCounter--;
//                    if(temp2 != nullptr && temp2->next != nullptr){
//                        temp1 = temp1->next;
//                        temp2 = temp2->next;
//                        temp = nullptr;
//                    }
//
//                } else if (temp2 == nullptr) {
//                    temp->next = nullptr;
//                    delete temp1;
//                    nodeCounter--;
//                    temp1 = temp;
//                } else {
//                    temp->next = temp2;
//                    delete temp1;
//                    nodeCounter--;
//                    temp1 = temp2;
//                    temp2 = temp2->next;
//                }
//            }
//            temp = temp1;
//            if (temp1) {
//                temp1 = temp1->next;
//                if (temp2) {
//                    temp2 = temp2->next;
//                }
//            }
//        }
//    }
//}


void List::print() const {
    Node *tempNode = this->first;
    while (tempNode) {
        cout << tempNode->value << " ";
        tempNode = tempNode->next;
    }
    tempNode = nullptr;
}