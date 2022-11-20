//
// Created by Kriszta Oniga on 11/17/2022.
//

#ifndef CPP_2022_MANAGER_H
#define CPP_2022_MANAGER_H

#include <vector>
#include "Alkalmazott.h"

class Manager : public Alkalmazott {
protected:
    vector<Alkalmazott *> alkalmazottak;
public:

    static const string MANAGER_MUNKAKOR;

    Manager(const string &vezetekNev, const string &keresztNev, int szuletesiEv1, const string &munkakor);

    void addAlkalmazott(Alkalmazott *alkalmazott);

    void deleteAlkalmazott(int id);

    int beosztottakSzama() const;

    virtual void print(ostream &os);

};

#endif //CPP_2022_MANAGER_H
