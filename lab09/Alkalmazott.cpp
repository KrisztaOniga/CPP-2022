//
// Created by Kriszta Oniga on 11/17/2022.
//

#include "Alkalmazott.h"

int Alkalmazott::counter{0};

Alkalmazott::Alkalmazott(const string &vezetekNev, const string &keresztNev, int szuletesiEv,
                         const string &munkakor): Szemely(vezetekNev,keresztNev,szuletesiEv), munkakor(munkakor) {
    this->id = ++counter;
}

void Alkalmazott::print(ostream &os) {
    Szemely::print(os);
    os<<" " << this->munkakor<< " ";
}

string Alkalmazott::getMunkakor() {
    return munkakor;
}

