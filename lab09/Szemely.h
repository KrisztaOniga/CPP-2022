//
// Created by Kriszta Oniga on 11/17/2022.
//

#ifndef CPP_2022_SZEMELY_H
#define CPP_2022_SZEMELY_H
#include <iostream>
using namespace std;

class Szemely {
protected:
    string vezetekNev;
    string keresztNev;
    int szuletesiEv;
public:
    Szemely(const string& vezetekNev, const string& keresztNev, const int szuletesiEv):vezetekNev(vezetekNev), keresztNev(keresztNev), szuletesiEv(szuletesiEv){}

    virtual void print(ostream &os);

};
ostream &operator<<(ostream &os,Szemely &szemely);




#endif //CPP_2022_SZEMELY_H
