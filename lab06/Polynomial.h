//
// Created by Kriszta Oniga on 10/26/2022.
//

#ifndef CPP_2022_POLYNOMIAL_H
#define CPP_2022_POLYNOMIAL_H

#include <iostream>

using namespace std;

class Polynomial {
// Polinom együtthatói
    double *coefficients;
// Polinom együtthatóinak a száma
    int capacity;
public:
    Polynomial(int degree, const double coefficients[]);

    Polynomial(const Polynomial &that);

    Polynomial(Polynomial &&that);

    ~Polynomial();

// Polinom fokszáma
    int degree() const;

// Polinom értéke a megadott pontban
    double evaluate(double x) const;

// Polinom deriváltja
    Polynomial derivative() const;

    double operator[](int index) const;

    // Negalo operator
    friend Polynomial operator-(const Polynomial &a);

    friend Polynomial operator+(const Polynomial &a, const Polynomial &b);

    friend Polynomial operator-(const Polynomial &a, const Polynomial &b);

    friend Polynomial operator*(const Polynomial &a, const Polynomial &b);

    friend ostream &operator<<(ostream &out, const Polynomial &what);

/* copy assignment - mély másolat letiltása értékadásra nézve */
    Polynomial &operator=(const Polynomial &) = delete;

/* move assignment - sekély másolat letiltása értékadásra nézve */
    Polynomial &operator=(Polynomial &&) = delete;
};


#endif //CPP_2022_POLYNOMIAL_H
