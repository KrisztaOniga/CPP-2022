//
// Created by Kriszta Oniga on 10/6/2022.
//

#ifndef CPP_2022_UTIL_H
#define CPP_2022_UTIL_H

#include "Point.h"
#include <vector>
#include<bits/stdc++.h>

double distance(const Point& a, const Point& b);

int distSq(Point p, Point q);
bool isSquare(const Point& a, const Point& b, const Point& c, const Point& d);

void testIsSquare(const char * filename);

Point* createArray(int numPoints);

void printArray(Point* points, int numPoints);

pair<Point, Point> closestPoints(Point* points, int numPoints);

pair<Point, Point> farthestPoints(Point* points, int numPoints);

bool cmp1(Point a, Point b);
void sortPoints(Point* points, int numPoints);

bool cmp2(const pair<double, Point>& a,
          const pair<double, Point>& b);
Point* farthestPointsFromOrigin(Point* points, int numPoints);

void deletePoints(Point* points);

#endif //CPP_2022_UTIL_H
