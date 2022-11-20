//
// Created by Kriszta Oniga on 11/17/2022.
//

#include "Szemely.h"

void Szemely::print(ostream &os) {
    os<<this->vezetekNev<<" " <<this->keresztNev << " " <<this->szuletesiEv;
}

ostream &operator<<(ostream &os,Szemely &szemely){
    szemely.print(os);
    return os;
}
