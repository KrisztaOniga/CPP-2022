//
// Created by Kriszta Oniga on 12/14/2022.
//

#include "myifstream.h"

myifstream::myifstream(const string filename) {
    open(filename);
}

myifstream::~myifstream() {
    close();
}

char myifstream::operator[](long index) {
    seekg(index, ios_base::beg);
    return get();
}

long myifstream::filesize() {
    int position = tellg();
    seekg(0,ios_base::end);
    int temp = tellg();
    seekg(position,ios_base::beg);
    return temp;
}
