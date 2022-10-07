//
// Created by Kriszta Oniga on 10/6/2022.
//

#ifndef CPP_2022_POINT_H
#define CPP_2022_POINT_H

#include <iostream>
#include <math.h>
#include <fstream>
#include <random>
#include <time.h>
#include <algorithm>

using namespace std;

class Point{
private:
    int x, y;
public:
    Point(int x=0, int y=0);

    int getX() const;

    int getY() const;

    void setData(int, int);

    void print() const;

};

#endif //CPP_2022_POINT_H
