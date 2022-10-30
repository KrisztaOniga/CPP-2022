//
// Created by Kriszta Oniga on 10/12/2022.
//

#ifndef CPP_2022_POINT_H
#define CPP_2022_POINT_H

#include <iostream>
#include <cmath>

#define M 2000

using namespace std;

class Point {
private:
    int x, y;
    static int counter;

public:
    Point(int x = 0, int y = 0);

    int getX() const;

    int getY() const;

    double distanceTo(const Point& point) const;

    void print() const;

    Point(const Point&);
    ~Point();
    static int getCounter();
};


#endif //CPP_2022_POINT_H
