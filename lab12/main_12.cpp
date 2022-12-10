//
// Created by Kriszta Oniga on 12/10/2022.
//
#include "GraduationDaoImpl.h"
#include "GraduationServiceImpl.h"
#include <algorithm>
#include "SettlementStatisticsImpl.h"

string subjects[]{"maths", "romanian", "hungarian"};
int numSubjects = sizeof(subjects) / sizeof(subjects[0]);

int main() {
     //ADMIN
    GraduationDao *dao = new GraduationDaoImpl();
    dao->enrollStudents("names.txt");
    cout << "Number of enrolled students: " << dao->numEnrolled() << endl;

    for (int i = 0; i < numSubjects; ++i) {
        dao->saveGradesForSubject(subjects[i], subjects[i] + ".txt");
    }
    dao->computeAverage();

    cout << "Subject's averages: " << endl;
    try {
        for (int i = 0; i < numSubjects; ++i) {
            cout << "\taverage(" << subjects[i] << "): " << dao->getAverageBySubject(subjects[i]) << endl;
        }
    }catch( domain_error& e){
        cerr << e.what() << endl;
    }

    cout << "Individual results: " << endl;
    int id = 0;
    GraduationService* service = new GraduationServiceImpl(dao);
    while (id != -1) {
        cout << "Enter ID (-1 for EXIT): ";
        cin >> id;
        if (id == -1) {
            break;
        }
        try {
            auto results = service->findById(id);
            cout << "Student id=" << id << " results: " << endl;
            for_each(results.getGrades().begin(), results.getGrades().end(), [](const pair<string, double> &e) {
                cout << "\t" << e.first << " : " << e.second << endl;
            });
        } catch (out_of_range &e) {
            cerr << "ID not found:" << id << endl;
        }
    }
    delete service;
    delete dao;

    cout<<endl<<endl<<endl;
    SettlementStatistics* stat = new SettlementStatisticsImpl("telepulesek.csv");
    cout << "Num settlements: " << stat->numSettlements() << endl;
    cout << "Num counties: " << stat->numCounties() << endl;
    cout << "Num settlements in MS: " << stat->numSettlementsByCounty("MS") << endl;
    cout << endl << "Settlements in MS: " << endl;
    vector<Settlement> result = stat->findSettlementsByCounty("MS");
    for(auto & r : result) {
        cout << r << endl;
    }
    cout << endl << "Settlements with the name Filpisu Mic: " << endl;
    vector<Settlement> result2 = stat->findSettlementsByName("Filpisu Mic");
    for(auto & r : result2) {
        cout << r << endl;
    }

    cout<<endl<<endl;
    cout<< "Settlement by name and county : " << stat->findSettlementsByNameAndCounty("Brancovenesti" , "MS")<<endl;
    cout << "Max density : " << stat->maxPopulationDensity() << endl;
    cout << "Min density : " << stat->minPopulationDensity() << endl;


    delete stat;

}