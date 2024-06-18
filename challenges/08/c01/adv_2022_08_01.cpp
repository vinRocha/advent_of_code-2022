/*
 * adv_2022_08_01.cpp
 *
 *  Created on: 15 Jun 2024
 *      Author: vsilva1
 */

#include <cstdlib>
#include <cstring>
#include <cstdio>
#include "file_handler.h" //includes iostream / fstream.
#include "Matrix.h" //Matrix class.

#define BUFFER_SIZE 101 //must be at least 1 + number of char / line in input file.
const char *file_name = "challenges/08/input/vrs_08.txt";

int main(int argc, char **argv) {

    std::fstream input_file;
    char line[BUFFER_SIZE];
    int answer = 0; int rc;
    int rows = 1;
    int collumns = 1;

    input_file.open(file_name, std::ios_base::in); //open file in read-only mode;
    rc = file_state(input_file);

    // Parse input file and populate matrix;
    rc = read_line(input_file, line, BUFFER_SIZE);
    collumns = strlen(line);
    Matrix Trees(rows, collumns);
    Matrix Flag(rows, collumns); //to flag a tree as counted.
    for (int i = 0; i < collumns; i++) {
        Trees.setElement(i, line[i] - 48); //48 is the decimal value for char '0' in ASCII.
    }
    rc = read_line(input_file, line, BUFFER_SIZE);
    while (rc > FILE_EOF) {
        Trees.addRow();
        Flag.addRow();
        rows++;
        for (int i = 0; i < collumns; i++) {
            Trees.setElement(rows, i+1, line[i] - 48);
        }
        rc = read_line(input_file, line, BUFFER_SIZE);
    }

    int north[2][collumns]; //tree,row,collumn
    int south[2][collumns]; //tree,row,collumn
    int west[2][rows]; //tree,collumn,row
    int east[2][rows]; //tree,collumn,row
    memset(north, -1, sizeof(north));
    memset(south, -1, sizeof(south));
    memset(west, -1, sizeof(west));
    memset(east, -1, sizeof(east));

    //count observable trees...
    //north and west
    for (int m = 0; m < rows; m++) {
        for (int n = 0; n < collumns; n++) {
            bool add_one = false;
            if (north[0][n] < Trees.getElement(m+1, n+1)) {
                north[0][n] = Trees.getElement(m+1, n+1);
                north[1][n] = m+1;
                if (!Flag.getElement(m+1, n+1)) {
                    add_one = true;
                    Flag.setElement(m+1, n+1, 1);
                    //fprintf(stdout, "m: %d, n: %d, e: %d\n", m, n, Trees.e);
                }
            }
            if (west[0][m] < Trees.getElement(m+1, n+1)) {
                west[0][m] = Trees.getElement(m+1, n+1);
                west[1][m] = n+1;
                if (!Flag.getElement(m+1, n+1)) {
                    add_one = true;
                    Flag.setElement(m+1, n+1, 1);
                    //fprintf(stdout, "m: %d, n: %d, e: %d\n", m, n, Trees.e);
                }
            }
            if (add_one) answer++;
        }
    }
    //south and east
    for (int m = rows; m > 0; m--) {
        for (int n = collumns; n > 0; n--) {
            bool add_one = false;
            if (south[0][n-1] < Trees.getElement(m, n)) {
                south[0][n-1] = Trees.getElement(m, n);
                south[1][n-1] = m;
                if (!Flag.getElement(m, n)) {
                    add_one = true;
                    Flag.setElement(m, n, 1);
                    //fprintf(stdout, "m: %d, n: %d, e: %d\n", m, n, Trees.e);
                }
            }
            if (east[0][m-1] < Trees.getElement(m, n)) {
                east[0][m-1] = Trees.getElement(m, n);
                east[1][m-1] = n;
                if (!Flag.getElement(m, n)) {
                    add_one = true;
                    Flag.setElement(m, n, 1);
                    //fprintf(stdout, "m: %d, n: %d, e: %d\n", m, n, Trees.e);
                }
            }
            if (add_one) answer++;
        }
    }

    std::cout << "answer: " << answer << std::endl;
    return 0;
}
