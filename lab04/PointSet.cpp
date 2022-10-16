//
// Created by Kriszta Oniga on 10/12/2022.
//

#include "PointSet.h"

PointSet::PointSet(int n) {
    this->n = n;
    for (int i = 0; i < n; ++i) {
        points.emplace_back( Point(rand() % MAX, rand() % MAX) );
    }
    computeDistances();
}

void PointSet::computeDistances() {
    for (int i = 0; i < n-1; ++i) {
        for (int j = i+1; j < n; ++j) {
            distances.emplace_back(points.at(i).distanceTo(points.at(j)));
        }
    }
}

double PointSet::maxDistance() const {
    return *max_element(distances.begin(), distances.end());
}

double PointSet::minDistance() const {
    return *min_element(distances.begin(), distances.end());
}

int PointSet::numDistances() const {
    return distances.size();
}

void PointSet::printPoints() const {
    for (Point point : points) {
        point.print();
    }
}

void PointSet::printDistances() const {
    for(double dist : distances){
        std::cout << dist << std::endl;
    }
}

void PointSet::sortPointsX() {
    sort(points.begin(), points.end(), compareX);
}

void PointSet::sortDistances() {
    sort(distances.begin(), distances.end());
}

bool PointSet::compareX(Point a, Point b) {
    return a.getX() < b.getX();
}

void PointSet::sortPointsY() {
    sort(points.begin(), points.end(), compareY);
}

bool PointSet::compareY(Point a, Point b) {
    return a.getY() < b.getY();
}

int PointSet::numDistinctDistances() {
    return (int)*unique(distances.begin(), distances.end());
}






