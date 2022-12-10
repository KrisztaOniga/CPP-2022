//
// Created by Kriszta Oniga on 12/10/2022.
//


#include "SettlementStatisticsImpl.h"
#include <sstream>
#include <fstream>
#include <unordered_set>
#include <algorithm>

SettlementStatisticsImpl::SettlementStatisticsImpl(const string &fileName) {
    ifstream ifs(fileName);
    if (!ifs) {
        cerr << "File open error" << endl;
        exit(1);
    }
    string line;
    // skip header
    getline(ifs, line);
    while (getline(ifs, line)) {
        string name, county;
        int population;
        stringstream ss(line);
        getline(ss, name, ',');
        getline(ss, county, ',');
        ss >> population;
        data.insert({county, Settlement(name, county, population)});
    }
}


int SettlementStatisticsImpl::numSettlements() const{
    return data.size();
}

int SettlementStatisticsImpl::numCounties() const {
    unordered_set<string> counties;
    for(auto & d : data){
        counties.insert(d.first);
    }
    return counties.size();
}

int SettlementStatisticsImpl::numSettlementsByCounty(const string &county) const {
    int counter = 0;
    for(auto & d : data){
        if(d.first == county) {
            counter++;
        }
    }
    return counter;
}

vector<Settlement> SettlementStatisticsImpl::findSettlementsByCounty(const string &county) const {
    vector<Settlement> toBeFound;
    for(auto & d : data){
        if(d.first == county) {
            toBeFound.emplace_back(d.second);
        }
    }
    return toBeFound;
}

Settlement SettlementStatisticsImpl::findSettlementsByNameAndCounty(const string &name, const string &county) const {
    for(auto  & d : data ) {
        if (d.first == county) {
            if (d.second.getName() == name) {
                return d.second;
            }
        }
    }
}

Settlement SettlementStatisticsImpl::maxPopulationDensity() const {
    vector<Settlement> settlements;

    for(auto & d : data){
        settlements.emplace_back(d.second);
    }

    sort(settlements.begin(), settlements.end(), [](const Settlement &s1, const Settlement &s2){
        return s1.getPopulation() > s2.getPopulation();
    });

    return settlements[0];


}

Settlement SettlementStatisticsImpl::minPopulationDensity() const {
    vector<Settlement> settlements;

    for(auto & d : data){
        settlements.emplace_back(d.second);
    }

    sort(settlements.begin(), settlements.end(), [](const Settlement &s1, const Settlement &s2){
        return s1.getPopulation() < s2.getPopulation();
    });

    return settlements[0];

}

vector<Settlement> SettlementStatisticsImpl::findSettlementsByName(const string &name) {
    vector<Settlement> toBeFound;
    for(auto & d : data){
        if(d.second.getName() == name) {
            toBeFound.emplace_back(d.second);
        }
    }
    return toBeFound;
}
