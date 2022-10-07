//
// Created by Kriszta Oniga on 10/6/2022.
//

#include "functions.h"

int countBits(int number){
    int counter = 0;
    while(number) {
        if ((number & 1) == 1) {
            counter++;
        }
        number >>= 1;
    }
    return counter;
}
bool setBit(int& number, int order){
    if(order < 0 || order > 31){
        return false;
    }
    number|= 1 << order;
    return true;
}

double mean(double array[], int numElements){
    double atlag = 0;
    if(numElements == 0)
        return NAN;
    for(int i = 0; i < numElements; ++i){
        atlag += array[i];
    }
    return (double)(atlag/numElements);
}

double stddev(double array[], int numElements){
    double e = 0;
    for(int i = 0 ;i < numElements; ++i){
        e += pow(array[i] - mean(array, numElements), 2);
    }
    e = e/numElements;
    e = sqrt(e);
    return e;
}

pair<double, double> max2(double array[], int numElements){
    int firstMax = array[0], secondMax = array[0];

    if(numElements == 0){
        firstMax = NAN;
        secondMax = NAN;
    }
    else if(numElements == 1){
        firstMax = secondMax;
    }
    else
        for(int i = 0; i < numElements; ++i){
            if(array[i] > firstMax){
                secondMax = firstMax;
                firstMax = array[i];
            }
            else if(array[i] > secondMax){
                secondMax = array[i];
            }
        }

    return {firstMax, secondMax};
}


int countWords(string text) {
    int count = 1;
    for (int i = 0; i < text.size(); i++) {
        if (text[i] == ' ' || text[i] == '\t' || text[i] == '\n') {
            bool repeat = true;
            int j = 1;
            while (j < (text.size() - i) && repeat) {
                if (text[i + j] != ' ' && text[i + j] != '\t' && text[i + j] != '\n') {
                    repeat = false;
                    i = i + j;
                    count++;
                }
                else
                    j++;
            }
        }
    }
    return count;
}

string code(string text){
    for (int i = 0; i < text.size(); i++) {
        if(islower(text[i]))
            text[i] = text[i] + 1;
        if(isupper(text[i]))
            text[i] = text[i] + 1;
    }
    return text;
}

string decode(string text){
    for (int i = 0; i < text.size(); i++) {
        if(islower(text[i]))
            text[i] = text[i] - 1;
        if(isupper(text[i]))
            text[i] = text[i] - 1;
    }
    return text;

}

string capitalizeWords(string text){
    for (int i = 0; i < text.length(); i++){
        if (i == 0){
            text[i] = toupper(text[i]);
        }
        else if (text[i - 1] == ' '){
            text[i] = toupper(text[i]);
        }
        else
            text[i] = tolower(text[i]);
    }

    return text;
}