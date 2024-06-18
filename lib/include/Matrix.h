/*
 * Matrix.h
 *
 *  Created on: 27 Nov 2022
 *      Author: vsilva1
 */

#ifndef LIB_INCLUDE_MATRIX_H_
#define LIB_INCLUDE_MATRIX_H_

#include <vector>

class Matrix {
private:
    std::vector<int> A;//matrix (array);
    int m; //# rows
    int n; //# columns
    int msize;
public:
    int j; //row location for hasElement call.
    int k; //collumn location for hasElement call.
    int e; //for getElement calls.
    Matrix(int m, int n);
    ~Matrix();
    int size();
    int rows();
    int collumns();
    void addRow();
    int getElement(int j, int k);
    int getElement(int i);
    bool setElement(int j, int k, int x);
    bool setElement(int i, int x);
    bool hasElement(int x);
};

#endif /* LIB_INCLUDE_MATRIX_H_ */
