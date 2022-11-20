//
// Created by Kriszta Oniga on 11/17/2022.
//

#ifndef CPP_2022_CEG_H
#define CPP_2022_CEG_H
#include "Manager.h"

class Ceg{
protected:
    vector<Alkalmazott *> alkalmazottak;
public:
    explicit Ceg(const vector<Alkalmazott *> &alkalmazottak);

    void addAlkalmazott(Alkalmazott *alkalmazott);

    void deleteAlkalmazott(int id);

    void addAlkalmazottToManager(Alkalmazott *alkalmazott);

    void deleteAlkalmazottToManager(Manager *manager);

    void printAlkalmazottak();

    void printManagers();
};


#endif //CPP_2022_CEG_H
