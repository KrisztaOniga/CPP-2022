//
// Created by Kriszta Oniga on 10/12/2022.
//

#include "Point.h"

Point::Point(int x, int y) {
    if ((x >= 0 && x <= M) && (y >= 0 && y <= M)) {
        this->x = x;
        this->y = y;
    } else {
        this->x = 0;
        this->y = 0;
    }
}

int Point::getX() const {
    return x;
}

int Point::getY() const {
    return y;
}

double Point::distanceTo(const Point &point) const {
    return sqrt(pow(this->x - point.getX(), 2) + pow(this->y - point.getY(), 2));
}

void Point::print() const {
    std::cout << "( " << getX() << "," << getY() << " )" << std::endl;
}

//move contructor
Point::Point(const Point &point) {
    this->x = point.x;
    this->y = point.y;
    ++this->counter;
}

Point::~Point() {
    --this->counter;
}

int Point::getCounter() {
    return counter;
}

int Point::counter{0};
