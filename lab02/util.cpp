//
// Created by Kriszta Oniga on 10/6/2022.
//

#include "util.h"

double distance(const Point &a, const Point &b) {
    return sqrt(pow(b.getX() - a.getX(), 2) + pow(b.getY() - a.getY(), 2));
}

int distSq(Point p, Point q) {
    return (p.getX() - q.getX()) * (p.getX() - q.getX()) + (p.getY() - q.getY()) * (p.getY() - q.getY());
}

bool isSquare(const Point &a, const Point &b, const Point &c, const Point &d) {
    int d2 = distSq(a, b);
    int d3 = distSq(a, c);
    int d4 = distSq(a, d);

    if (d2 == 0 || d3 == 0 || d4 == 0)
        return false;


    if (d3 == d4 && 2 * d3 == d2
        && 2 * distSq(c, b) == distSq(c, d)) {
        return true;
    }

    if (d2 == d4 && 2 * d2 == d3
        && 2 * distSq(b, c) == distSq(b, d)) {
        return true;
    }

    return false;
}

void testIsSquare(const char *filename) {

    ifstream fin("points.txt");

    if (!fin) {
        cout << "Error opening output file" << endl;
    }

    int t[8];
    bool negyzet = true;

    while (!fin.eof()) {
        for (int i = 0; i < 8; i += 2)
            fin >> t[i] >> t[i + 1];
        negyzet = isSquare(Point(t[0], t[1]), Point(t[2], t[3]), Point(t[4], t[5]), Point(t[6], t[7]));
        if (negyzet == 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        negyzet = false;
    }

    fin.close();
}

Point *createArray(int numPoints) {

    int rX, rY;
    Point *points = new Point[numPoints];

    srand(time(NULL));

    for (int i = 0; i < numPoints; i++) {
        rX = rand() % 2000;
        rY = rand() % 2000;
        points[i].setData(rX, rY);
    }

    return &(*points);
}

void printArray(Point *points, int numPoints) {
    for (int i = 0; i < numPoints; i++) {
        cout << points[i].getX() << " " << points[i].getY() << endl;
    }
}

pair<Point, Point> closestPoints(Point *points, int numPoints) {
    int minDistance = INT_MAX;
    Point min1;
    Point min2;

    for (int i = 0; i < numPoints - 1; i++) {
        for (int j = i + 1; j < numPoints; j++) {
            if (distance(points[i], points[j]) < minDistance) {
                minDistance = distance(points[i], points[j]);
                min1.setData(points[i].getX(), points[i].getY());
                min2.setData(points[j].getX(), points[j].getY());
            }
        }
    }
    cout << endl << "A tavolag: " << distance(min1, min2) << endl;
    return make_pair(min1, min2);
}

pair<Point, Point> farthestPoints(Point *points, int numPoints) {
    int maxDistance = INT_MIN;
    Point max1;
    Point max2;

    for (int i = 0; i < numPoints - 1; i++) {
        for (int j = i + 1; j < numPoints; j++) {
            if (distance(points[i], points[j]) > maxDistance) {
                maxDistance = distance(points[i], points[j]);
                max1.setData(points[i].getX(), points[i].getY());
                max2.setData(points[j].getX(), points[j].getY());
            }
        }
    }
    cout << endl << "A tavolag: " << distance(max1, max2) << endl;
    return make_pair(max1, max2);
}

bool cmp1(Point a, Point b){
    if(a.getX() < b.getX())
        return 1;
    else
        return 0;
}

void sortPoints(Point *points, int numPoints) {
    sort(points, points + numPoints, cmp1);
}


bool cmp2(const pair<double, Point>& a,
          const pair<double, Point>& b){
    if (a.first < b.first)
        return 0;
    else
        return 1;
}

Point *farthestPointsFromOrigin(Point *points, int numPoints) {

    vector<pair<double, Point>> vekt;

    Point origin(0, 0);

    for (int i = 0; i < numPoints; ++i) {
        vekt.push_back(make_pair(distance(points[i], origin), points[i]));
    }

    for (int i = 0; i < numPoints; ++i) {
        cout << vekt[i].first << " " << "---";
        cout << "(" << vekt[i].second.getX() << "," << vekt[i].second.getY() << ")" << endl;
    }

    sort(vekt.begin(), vekt.end(), cmp2);

    cout<<endl<<"Tavolsag szerint csokkeno sorrend: "<<endl;
    for (int i = 0; i < numPoints; ++i) {
        cout << vekt[i].first << " " << "---";
        cout << "(" << vekt[i].second.getX() << "," << vekt[i].second.getY() << ")" << endl;
    }

    cout<<endl;

    int i = 10;
    int j = 0;

    Point *farthestPoints = new Point[i];


    for(int i = 0; i < 10; ++i){
        farthestPoints[i] = vekt[i].second;
    }

    cout<<endl<<"A 10 legtavolibb pont:"<<endl;
    return farthestPoints;
}

void deletePoints(Point *points) {
    free(points);
}