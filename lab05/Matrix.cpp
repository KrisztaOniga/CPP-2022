//
// Created by Kriszta Oniga on 10/20/2022.
//
#include "Matrix.h"

#include <iostream>
#include "Matrix.h"

// Default constructor
Matrix::Matrix(int mRows, int mCols) {
    this->mRows = mRows;
    this->mCols = mCols;
    this->mElements = new double *[mRows];

    for (int i = 0; i < mRows; ++i) {
        mElements[i] = new double[mCols];
    }
}

// Copy constructor
Matrix::Matrix(const Matrix &what) {
    this->mCols = what.mCols;
    this->mRows = what.mRows;
    this->mElements = new double *[mRows];

    for (int i = 0; i < mRows; ++i) {
        mElements[i] = new double[mCols];
        for (int j = 0; j < mCols; ++j) {
            mElements[i][j] = what.mElements[i][j];
        }
    }
}

// Move constructor
Matrix::Matrix(Matrix &&what) {
    this->mCols = what.mCols;
    this->mRows = what.mRows;
    this->mElements = what.mElements;

    what.mElements = nullptr;
    what.mCols = 0;
    what.mRows = 0;
}

// Destructor
Matrix::~Matrix() {
    for (int i = 0; i < mRows; ++i) {
        delete[] mElements[i];
    }
    delete[] mElements;
    this->mRows = 0;
    this->mCols = 0;
}

void Matrix::fillMatrix(double value) {
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            this->mElements[i][j] = value;
        }
    }
}

void Matrix::randomMatrix(int a, int b) {
    srand(time(NULL));
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            this->mElements[i][j] = a + rand() % (b - a);
        }
    }
}

void Matrix::printMatrix(ostream &os) const {
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            os << mElements[i][j] << " ";
        }
        os << endl;
    }
}

bool Matrix::isSquare() const {
    if (mRows == mCols) {
        return true;
    }
    return false;
}

Matrix operator+(const Matrix &x, const Matrix &y) {
    Matrix temp(x.mRows, x.mCols);

    if (x.mRows == y.mRows && x.mCols == y.mCols) {
        for (int i = 0; i < x.mRows; ++i) {
            for (int j = 0; j < x.mCols; ++j) {
                temp.mElements[i][j] = x.mElements[i][j] + y.mElements[i][j];
            }
        }
    } else
        throw out_of_range("Matrix dimension does not coresspond");
    return temp;
}

// operation is permitted on matrices having proper dimensions
// otherwise throws an out_of_range exception!!

Matrix operator*(const Matrix &x, const Matrix &y) {
    Matrix temp(x.mRows, y.mCols);
    if (x.mRows != y.mCols) {
        throw out_of_range("Can't multiply matrices!");
    } else {
        for (int i = 0; i < temp.mRows; ++i) {
            for (int j = 0; j < temp.mCols; ++j) {
                temp.mElements[i][j] = x.mElements[i][j % (x.mCols - 1)] *
                                       y.mElements[i % (y.mRows - 1)][j] +
                                       x.mElements[i][(j + 1) % (x.mCols - 1)] *
                                       y.mElements[(i + 1) % (y.mRows - 1)][j] +
                                       x.mElements[i][(j + 2) % (x.mCols - 1)] *
                                       y.mElements[(i + 2) % (y.mRows - 1)][j];

            }
        }
    }
    return temp;
}

istream &operator>>(istream &is, Matrix &mat) {

    for (int i = 0; i < mat.mRows; ++i) {
        for (int j = 0; j < mat.mCols; ++j) {
            is >> mat.mElements[i][j];
        }
    }
    return is;
}

ostream &operator<<(ostream &os, const Matrix &mat) {
    for (int i = 0; i < mat.mRows; ++i) {
        for (int j = 0; j < mat.mCols; ++j) {
            os << mat.mElements[i][j] << " ";
        }
        os << endl;
    }
    // mat.printMatrix(os);
    return os;
}

// index operator
double *Matrix::operator[](int index) {
    return mElements[index];
}

// index operator that works on constant matrices!
double *Matrix::operator[](int index) const {
    return mElements[index];
}

// Copy assignment
// operation is permitted between matrices having the same dimensions
// otherwise throws an exception (out_of_range)
Matrix &Matrix::operator=(const Matrix &mat) {
    if (mat.mRows == this->mRows && mat.mCols == this->mCols) {
        for (int i = 0; i < mRows; ++i) {
            for (int j = 0; j < mCols; ++j) {
                this->mElements[i][j] = mat.mElements[i][j];
            }
        }
    } else
        throw out_of_range("Matrix dimension does not coresspond");

    return *this;
}

// Move assignment
Matrix &Matrix::operator=(Matrix &&mat) {
    for (int i = 0; i < mRows; ++i) {
        delete[] mElements[i];
    }
    delete[] mElements;
    this->mRows = 0;
    this->mCols = 0;

    this->mCols = mat.mCols;
    this->mRows = mat.mRows;
    this->mElements = mat.mElements;

    mat.mElements = nullptr;
    mat.mCols = 0;
    mat.mRows = 0;

    return *this;
}
















