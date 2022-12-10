//
// Created by Kriszta Oniga on 12/7/2022.
//

#ifndef CPP_2022_INDEX_H
#define CPP_2022_INDEX_H

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Index {

    map<string, vector<int>> index;

public:

    Index(const string &filename);

    void printIndex(ostream &out = cout) const;

    void printIndexWords(ostream &out = cout) const;

    const vector<int> &getWordOccurencies(const string &key);
};

#endif //CPP_2022_INDEX_H
