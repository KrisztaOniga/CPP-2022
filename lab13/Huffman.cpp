//
// Created by Kriszta Oniga on 12/14/2022.
//

#include "Huffman.h"
#include "myifstream.h"

Huffman::Huffman(const string &filename) {
    ifstream fin(filename);
    char c;
    myifstream f("be.txt");
    for (int i = 0; i < f.filesize(); ++i) {
        if(f[i] != 10){
            frequencies[f[i]]++;
        }
    }
    for (auto &it: frequencies) {
        cout << it.first << ": " << it.second << endl;
    }
    createTree();
}


void Huffman::printTree() {
    printNode(priorityQueue.top());
}

void Huffman::printNode(node *node) {
    if (node == nullptr) {
        return;
    }
    cout<< node->data << ": " << node->freq << endl;
    printNode(node->left);
    printNode(node->right);
}

void Huffman::printCodes(node * node, string str) {
    if (node != nullptr){
        if (node->data != '$')
            cout << node->data << ": " << str << endl;

        printCodes(node->left, str+'0');
        printCodes(node->right, str+'1');
    }
}

void Huffman::createTree() {
    for (auto &it: frequencies) {
        priorityQueue.push(new node(it.first, it.second));
    }
    while (priorityQueue.size() > 1) {
        node *temp1 = priorityQueue.top();
        priorityQueue.pop();
        node *temp2 = priorityQueue.top();
        priorityQueue.pop();

        node *newNode = new node('$', temp1->freq + temp2->freq, temp1, temp2);
        priorityQueue.push(newNode);
    }

    cout<<"Root: "<< priorityQueue.top()->freq<<endl;
    cout<<endl;
}



