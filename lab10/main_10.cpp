#include <iostream>

using namespace std;

#include "OrderedList.h"

#include <iostream>
#include "OrderedList.h"

using namespace std;

struct Person {
    string fname;
    string lname;

    Person(string fname = "", string lname = "") : fname(fname), lname(lname) {}
};

ostream &operator<<(ostream &os, const Person &p) {
    os << p.fname << " " << p.lname << " ";
    return os;
}

struct PersonLess {
    bool operator()(const Person &p1, const Person &p2) {
        if (p1.fname == p2.fname)
            return p1.lname < p2.lname;
        return p1.fname < p2.fname;
    }
};

struct PersonEqual {
    bool operator()(const Person &p1, const Person &p2) {
        return (p1.fname == p2.fname) && (p1.lname == p2.lname);
    }
};

int main() {
    // T → int
    OrderedList<int> l;
    for (int i = 0; i < 30; ++i) {
        int v = rand() % 10;
        l.insert(v);
    }

    l.listItems(cout);
    cout << endl;

//    int v = 8;
//    if(l.find( v ) == true){
//        cout<<"Megvan";
//    }
//    else {
//        cout<<"Nincs meg";
//    }
//    l.remove(v);
//    cout<<endl<<"A lista torles utan: ";
//    l.listItems(cout);
//    cout << endl;
//
//    Iterator<int> it(l);
//
//    while (it.hasNext()) {
//        cout << it.next() << "\t";
//    }
//    cout << endl;
//    for (int i = 0; i < 10; ++i) {
//        int t = rand() % 10;
//        cout << "\nTorlendo: " << t << endl;
//        l.remove(t);
//        l.listItems(cout);
//    }

    // T → Person
    OrderedList<Person, PersonLess, PersonEqual> pl;
    pl.insert(*(new Person("Balazs", "Istvan")));
    pl.insert(*(new Person("Andras", "Eva")));
    pl.insert(*(new Person("Balazs", "Emoke")));
    pl.insert(*(new Person("Petres", "Andras")));
    cout << "Persons: ";
    pl.listItems(cout);
    cout << endl;
    cout << "Persons using iterator: ";
    Iterator<Person, PersonLess, PersonEqual> it(pl);
    while (it.hasNext()) {
        cout << it.next() << "\t";
    }
    cout << endl;
    Person person("Andras", "Eva");
    auto result = pl.find(person);
    cout << "Does " << person << " exist? " << (result ? "YES" : "NO") << endl;
    person.fname = "Szanto";
    result = pl.find(person);
    cout << "Does " << person << " exist? " << (result ? "YES" : "NO") << endl;


    return 0;
}