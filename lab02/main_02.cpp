#include <iostream>

using namespace std;

#include "Point.h"
#include "util.h"

int main(int argc, char **argv) {

    Point p1(2, 3);
    cout << "p1( " << p1.getX() << "," << p1.getY() << ")" << endl;

    Point p2(100, 200);
    cout << "p2( " << p2.getX() << "," << p2.getY() << ")" << endl;
    Point *pp1 = new Point(300, 400);
    Point *pp2 = new Point(500, 1000);
    cout << "pp1( " << pp1->getX() << "," << pp1->getY() << ")" << endl;
    cout << "pp2( " << pp2->getX() << "," << pp2->getY() << ")" << endl;

    cout << endl << "Harmadik feladat" << endl;
    p1.print();

    cout << endl << "Negyedik feladat" << endl;
    //cout << distance(*pp1, *pp2);
    cout << endl;

    cout << endl << "Otodik feladat" << endl;
    Point *ppa = new Point(10, 10);
    Point *ppb = new Point(10, 20);
    Point *ppc = new Point(20, 20);
    Point *ppd = new Point(30, 10);

    if (isSquare(*ppa, *ppb, *ppc, *ppd))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    cout << endl << "Hatodik feladat" << endl;
    const char *filename = "points.txt";
    testIsSquare(filename);

    cout << endl << "Hetedik feladat" << endl;
    int n;
    cout << "Pontok szama:";
    cin >> n;
    Point *points = createArray(n);
    printArray(points, n);
    cout << endl;

    cout << "Kilencedik feladat" << endl;
    pair<Point, Point> closest = closestPoints(points, n);
    cout << "(" << closest.first.getX() << "," << closest.first.getY() << ")";
    cout << "(" << closest.second.getX() << ", " << closest.second.getY() << ")";
    cout << endl;

    cout << "Tizedik feladat" << endl;
    pair<Point, Point> farthest = farthestPoints(points, n);
    cout << "(" << farthest.first.getX() << "," << farthest.first.getY() << ")";
    cout << "(" << farthest.second.getX() << "," << farthest.second.getY() << ")";
    cout << endl;

    cout <<endl<< "Tizenegyedik feladat" << endl;
    sortPoints(points, n);
    printArray(points, n);
    cout<<endl;

    cout <<endl<< "Tizenkettedik feladat" << endl;
    Point *tomb = farthestPointsFromOrigin(points, n);
    printArray(tomb, 10);
    cout<<endl;

    deletePoints(points);
    delete pp1;
    delete pp2;

    delete ppa;
    delete ppb;
    delete ppc;
    delete ppd;
    return 0;
}