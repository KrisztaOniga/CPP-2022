//
// Created by Kriszta Oniga on 11/17/2022.
//

#include <algorithm>
#include "Ceg.h"

void Ceg::addAlkalmazott(Alkalmazott *alkalmazott) {
    alkalmazottak.emplace_back(alkalmazott);
}

void Ceg::deleteAlkalmazott2(int id) {
    int poz;
    for (int i = 0; i < alkalmazottak.size(); ++i) {
        if (alkalmazottak[i]->getID() == id) {
            poz = i;
        }
    }
    alkalmazottak.erase(alkalmazottak.begin() + poz);
}

void Ceg::addAlkalmazottToManager(Alkalmazott *alkalmazott, Manager *manager) {
    manager->addAlkalmazott(alkalmazott);
}

void Ceg::deleteAlkalmazottFromManager(Alkalmazott *alkalmazott, Manager *manager) {
    for (int i = 0; i < manager->beosztottakSzama(); ++i) {
        if(manager->beosztottjai[i] == alkalmazott)
            manager->deleteAlkalmazott(alkalmazott);
    }
}

void Ceg::printAlkalmazottak(ostream &os) {
    for (auto &alkalmazott: alkalmazottak) {
        alkalmazott->print(os);
    }
}

void Ceg::printManagers(ostream &os) {
    os << "Managers:" << endl;
    for_each(alkalmazottak.begin(), alkalmazottak.end(), [&os](Alkalmazott *alkalmazott) {
        Manager *tempManager;
        tempManager = dynamic_cast<Manager *>(alkalmazott);
        if (tempManager != nullptr) {
            tempManager->print(os);
        }
    });
}




