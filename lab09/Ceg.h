//
// Created by Kriszta Oniga on 11/17/2022.
//

#ifndef CPP_2022_CEG_H
#define CPP_2022_CEG_H
#include "Manager.h"

class Ceg{
protected:
    string name;
    vector<Alkalmazott *> alkalmazottak;
public:
    explicit Ceg(string name){
        this->name = name;
    }

    void addAlkalmazott(Alkalmazott *alkalmazott);

    void deleteAlkalmazott2(int id);

    static void addAlkalmazottToManager(Alkalmazott *alkalmazott, Manager *manager);

    static void deleteAlkalmazottFromManager(Alkalmazott *alkalmazott,Manager *manager);

    void printAlkalmazottak(ostream &os);

    void printManagers(ostream &os);
};


#endif //CPP_2022_CEG_H
