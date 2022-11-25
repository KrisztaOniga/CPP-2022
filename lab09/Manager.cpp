//
// Created by Kriszta Oniga on 11/17/2022.
//

#include "Manager.h"

Manager::Manager(const string &vezetekNev, const string &keresztNev, int szuletesiEv1, const string &munkakor)
        : Alkalmazott(vezetekNev, keresztNev, szuletesiEv1, munkakor) {
}

void Manager::addAlkalmazott(Alkalmazott *alkalmazott) {
    beosztottjai.emplace_back(alkalmazott);
}

void Manager::deleteAlkalmazott(Alkalmazott *alkalmazott) {
    int poz;
    for (int i = 0; i < beosztottjai.size(); ++i) {
        if(beosztottjai[i]== alkalmazott){
            poz = i;
        }
    }
    beosztottjai.erase(beosztottjai.begin() + poz);
}

void Manager::deleteAlkalmazottbyID(int id) {
    int poz;
    for (int i = 0; i < beosztottjai.size(); ++i) {
        if(beosztottjai[i]->getID() == id){
            poz = i;
        }
    }
    beosztottjai.erase(beosztottjai.begin() + poz);
}



int Manager::beosztottakSzama() const {
    return beosztottjai.size();
}

void Manager::print(ostream &os) {
    os << "Manager " << this->id << " " << this->vezetekNev
       << " " << this->keresztNev << " beosztottjai:\n";
    for (auto &alk: beosztottjai) {
        os <<"\tAlkalmazott "<< alk->getID() <<" "<< *alk <<  endl;
    }
}

const string Manager::MANAGER_MUNKAKOR = "manager";
