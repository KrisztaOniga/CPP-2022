//
// Created by Kriszta Oniga on 11/17/2022.
//

#include "Manager.h"

Manager::Manager(const string &vezetekNev, const string &keresztNev, int szuletesiEv1, const string &munkakor)
        : Alkalmazott(vezetekNev, keresztNev, szuletesiEv1, munkakor) {
}

void Manager::addAlkalmazott(Alkalmazott *alkalmazott) {
    alkalmazottak.emplace_back(alkalmazott);
}

void Manager::deleteAlkalmazott(int id) {
    int poz;
    for (int i = 0; i < alkalmazottak.size(); ++i) {
        if(alkalmazottak[i]->getID() == id){
            poz = i;
        }
    }
    alkalmazottak.erase(alkalmazottak.begin() + poz);
}

int Manager::beosztottakSzama() const {
    return alkalmazottak.size();
}

void Manager::print(ostream &os) {
    Alkalmazott::print(os);
}

const string Manager::MANAGER_MUNKAKOR = "manager";
