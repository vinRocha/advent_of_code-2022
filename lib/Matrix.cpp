/*
 * Matrix.cpp
 *
 *  Created on: 27 Nov 2022
 *      Author: vsilva1
 */

#include "Matrix.h"

Matrix::Matrix(int m, int n) {
    this->m = m;
    this->n = n;
    this->msize = m*n;
    this->A = std::vector<int> (msize, 0);
    this->j = 0;
    this->k = 0;
    this->e = 0;
}

Matrix::~Matrix() {
}

int Matrix::size() {
    return msize;
}

int Matrix::rows() {
    return m;
}

int Matrix::collumns() {
    return n;
}

void Matrix::addRow() {
    for (int i = 0; i < n; i++) {
        A.push_back(0);
    }
    m++; msize = A.size();
}

int Matrix::getElement(int j, int k) {
    if (j > m || k > n || j < 0 || k < 0)
        return -1;
    e = A[k-1 + (j-1)*n];
    this->j = j;
    this->k = k;
    return e;
}

int Matrix::getElement(int i) {
    if (i < 0 || i > msize -1 )
        return -1;
    e = A[i];
    return e;
}

bool Matrix::setElement(int j, int k, int x) {
    if (j > m || k > n || j < 0 || k < 0)
        return false;
    A[(j-1)*n + k-1] = x;
    return true;
}

bool Matrix::setElement(int i, int x) {
    if (i < 0 || i > msize -1 )
        return false;
    A[i] = x;
    return true;
}

bool Matrix::hasElement(int x) {
    bool hasE = false;
    j = 1;
    k = 1;
    for (int i = 0; i < msize; i++){
        if (i % n == 0) {
            k = 1;
            j++;
        }
        if (x == A[i]){
            hasE = true;
            break;
        }
        k++;
    }
    if(!hasE){
        j = 0;
        k = 0;
    }
    return hasE;
}
