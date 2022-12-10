//
// Created by Kriszta Oniga on 12/7/2022.
//

#include "Index.h"
#include <iostream>
#include <fstream>
#include <sstream>

void toUpper(string &word) {
    for (int i = 0; i < word.length(); i++) {
        if (word[i] >= 'a' && word[i] <= 'z') {
            word[i] -= 32;
        }
    }
}

void toLower(string &word) {
    for (int i = 0; i < word.length(); i++) {
        if (word[i] >= 'A' && word[i] <= 'Z') {
            word[i] += 32;
        }
    }
}

Index::Index(const string &filename) {
    ifstream fin;
    fin.open(filename);

    if (!fin) {
        cout << "File not found" << endl;
        exit(-1);
    }

    string line;
    int counter = 1;

    while (getline(fin, line)) {
        if (line.empty()) {
            break;
        }
        index[line] = vector<int>();
//        index.insert({line, vector<int>()});
    }
    for (auto &[key, value]: index) {
        cout << key << endl;
    }

    while (getline(fin, line)) {
        cout << line << endl;

        istringstream iss(line);
        string word;
        while (iss >> word) {
            toLower(word);
            auto it = index.find(word);
            if (it != index.end()) {
                if (index[word].size() != 0) {
                    if (index[word].at(index[word].size() - 1) != counter) {
                        index[word].push_back(counter);
                    }
                } else {
                    index[word].push_back(counter);
                }
            }
        }
        counter++;
    }

    fin.close();
}

void Index::printIndex(std::ostream &out) const {
    for (auto it = index.begin(); it != index.end(); it++) {
        string word = it->first;
        toUpper(word);
        out << word << ": ";
        int size = it->second.size();
        for (int i = 0; i < size; i++) {
            if (i == size - 1) {
                out << it->second[i] << " ";
            } else {
                if (i < size - 1 && it->second[i] == it->second[i + 1] - 1) {
                    out << it->second[i] << "-";
                } else {
                    out << it->second[i] << ", ";
                }
            }
        }
        out << endl;
    }


}

void Index::printIndexWords(std::ostream &out) const {
    for (auto it = index.begin(); it != index.end(); it++) {
        string word = it->first;
        toUpper(word);
        out << word << " ";
        out << endl;
    }
}

const vector<int> &Index::getWordOccurencies(const string &key) {
    return this->index[key];
}