//
// Created by Kriszta Oniga on 12/10/2022.
//

#include "Settlement.h"

Settlement::Settlement(const string &name, const string &county, int population) : name(name), county(county),
                                                                                   population(population) {}

const string &Settlement::getName() const {
    return name;
}

void Settlement::setName(const string &name) {
    Settlement::name = name;
}

const string &Settlement::getCounty() const {
    return county;
}

void Settlement::setCounty(const string &county) {
    Settlement::county = county;
}

int Settlement::getPopulation() const {
    return population;
}

void Settlement::setPopulation(int population) {
    Settlement::population = population;
}

ostream &operator<<(ostream &os, const Settlement &settlement) {
    os << "name: " << settlement.name << " county: " << settlement.county << " population: " << settlement.population;
    return os;
}