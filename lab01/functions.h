//
// Created by Kriszta Oniga on 10/6/2022.
//

#ifndef CPP_2022_FUNCTIONS_H
#define CPP_2022_FUNCTIONS_H

#include "cmath"
#include "utility"
#include "string"
#include <sstream>
#include <cstring>
#include <fstream>

using namespace std;

int countBits(int number);
bool setBit(int& number, int order);
double mean(double array[], int numElements);
double stddev(double array[], int numElements);
pair<double, double> max2(double array[], int numElements);
int countWords(string text);

string code(string text);
string decode(string text);

string capitalizeWords(string text);

#endif //CPP_2022_FUNCTIONS_H
