#include "Ceg.h"

int main() {
    Ceg ceg1("Microsoft");

    Alkalmazott alkalmazott1("Nagy", "Pisti", 1991, "MobileDev");
    Alkalmazott alkalmazott2("Kiss", "Anna", 1992, "WebDev");
    Manager alkalmazott3("Incze", "Zsolt", 1993, "info");
    Alkalmazott alkalmazott4("Kacso", "Robert", 1994, "WebDev");
    Alkalmazott alkalmazott5("Balint", "Norbert", 1995, "info");
    Manager alkalmazott6("Fuzi", "Janos", 1996, "info");
    Alkalmazott alkalmazott7("Horvath", "Hunor", 1997, "MobileDev");
    Alkalmazott alkalmazott8("Bagoly", "Janos", 1998, "info");
    Manager alkalmazott9("Gabos", "Norbert", 1999, "MobileDev");
    Alkalmazott alkalmazott10("Burszan", "Hunor", 1990, "WebDev");

    ceg1.addAlkalmazott(&alkalmazott1);
    ceg1.addAlkalmazott(&alkalmazott2);
    ceg1.addAlkalmazott(&alkalmazott3);
    ceg1.addAlkalmazott(&alkalmazott4);
    ceg1.addAlkalmazott(&alkalmazott5);
    ceg1.addAlkalmazott(&alkalmazott6);
    ceg1.addAlkalmazott(&alkalmazott7);
    ceg1.addAlkalmazott(&alkalmazott8);
    ceg1.addAlkalmazott(&alkalmazott9);
    ceg1.addAlkalmazott(&alkalmazott10);

    ceg1.printAlkalmazottak(cout);

//    ceg1.deleteAlkalmazott2(1);
//    cout<<endl<<"TORLES UTAN:"<<endl;
//    ceg1.printAlkalmazottak(cout);

    ceg1.printManagers(cout);

    ceg1.addAlkalmazottToManager(&(alkalmazott1), &alkalmazott3);
    ceg1.addAlkalmazottToManager(&alkalmazott2, &alkalmazott3);
    ceg1.addAlkalmazottToManager(&alkalmazott4, &alkalmazott6);
    ceg1.addAlkalmazottToManager(&alkalmazott5, &alkalmazott6);
    ceg1.addAlkalmazottToManager(&alkalmazott7, &alkalmazott6);
    ceg1.addAlkalmazottToManager(&alkalmazott8, &alkalmazott9);
    ceg1.addAlkalmazottToManager(&alkalmazott10, &alkalmazott9);

    ceg1.printManagers(cout);

//    ceg1.deleteAlkalmazottFromManager(&alkalmazott5, &alkalmazott6);
//    ceg1.printManagers(cout);

    ceg1.addAlkalmazottToManager(&alkalmazott7, &alkalmazott3);
    ceg1.deleteAlkalmazottFromManager(&alkalmazott7, &alkalmazott6);
    ceg1.printManagers(cout);

    return 0;
}