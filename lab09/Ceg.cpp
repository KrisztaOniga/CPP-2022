//
// Created by Kriszta Oniga on 11/17/2022.
//

#include "Ceg.h"

void Ceg::addAlkalmazott(Alkalmazott *alkalmazott) {
    alkalmazottak.emplace_back(alkalmazott);
}

void Ceg::deleteAlkalmazott(int id) {
    int poz;
    for (int i = 0; i < alkalmazottak.size(); ++i) {
        if(alkalmazottak[i]->getID() == id){
            poz = i;
        }
    }
    alkalmazottak.erase(alkalmazottak.begin() + poz);
}

void Ceg::addAlkalmazottToManager(Alkalmazott *alkalmazott) {

}

void Ceg::deleteAlkalmazottToManager(Manager *manager) {

}


void Ceg::printAlkalmazottak() {
    for (auto &alkalmazott : alkalmazottak) {
        cout<<alkalmazott<< " ";
    }
}

void Ceg::printManagers() {
    for (auto &alkalmazott : alkalmazottak) {
        if(alkalmazott->getMunkakor() == "manager")
            cout<<alkalmazott<< " ";
    }
}

Ceg::Ceg(const vector<Alkalmazott *> &alkalmazottak) : alkalmazottak(alkalmazottak) {}





