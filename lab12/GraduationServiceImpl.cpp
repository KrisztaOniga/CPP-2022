//
// Created by Kriszta Oniga on 12/10/2022.
//


#include "GraduationServiceImpl.h"

GraduationServiceImpl::GraduationServiceImpl(GraduationDao *dao) : dao(dao) {}

Student GraduationServiceImpl::findById(int id) const {
    return dao->findById(id);
}

double GraduationServiceImpl::getResultByIdAndSubject(int id, const string &subject) const {
    return dao->findById(id).getGrade(subject);
}
