#include <iostream>
#include <sstream>
#include "myifstream.h"
#include "Huffman.h"

int main() {

//    myifstream f("be.txt");
//    for( int i=0; i <f.filesize(); ++i){
//        cout << f[i] << endl;
//    }
//   cout<<f[16];
//    cout << endl;

    Huffman huff("be.txt");
    huff.printTree();
    cout << endl;
    huff.printCodes(huff.priorityQueue.top(), " ");
    return 0;
}