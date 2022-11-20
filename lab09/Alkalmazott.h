//
// Created by Kriszta Oniga on 11/17/2022.
//

#ifndef CPP_2022_ALKALMAZOTT_H
#define CPP_2022_ALKALMAZOTT_H

#include "Szemely.h"

class Alkalmazott : public Szemely {
protected:
    int id;
    string munkakor;
    static int counter; // segédváltozó id generáláshoz
public:
    Alkalmazott( const string &vezetekNev, const string &keresztNev, int szuletesiEv, const string &munkakor);
    virtual void print(ostream &os);
    int getID() const {return this->id;};
    string getMunkakor();

};


#endif //CPP_2022_ALKALMAZOTT_H
