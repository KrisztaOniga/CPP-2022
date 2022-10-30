#include "Polynomial.h"

int main() {

    Polynomial a(3, new double [4]{1, 2,6,9});
    cout <<"a = " << a;

    Polynomial b(2, new double [3]{2, 3,6});
    cout <<"b = " <<  b;


    cout<<"a + b = " << a+b;
    cout<<"a - b = " << a-b;
    cout<<"b - a = " << b-a;
    cout<<"a * b = " << a*b;

    cout<<"Horner :"<< a.evaluate(2);

    //atteszi b-be c- t es b-t torli
//    Polynomial c(move(b));
//    cout <<"c = " <<  c;

    return 0;
}