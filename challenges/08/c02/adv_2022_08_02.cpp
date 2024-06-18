/*
 * adv_2022_08_02.cpp
 *
 *  Created on: 18 Jun 2024
 *      Author: vsilva1
 */

#include <cstdlib>
#include <cstring>
#include <cstdio>
#include "file_handler.h" //includes iostream / fstream.
#include "Matrix.h" //Matrix class.

#define BUFFER_SIZE 101 //must be at least 1 + number of char / line in input file.
const char *file_name = "challenges/08/input/vrs_08.txt";

int count_trees(Matrix A, int j, int k, bool at_row, bool forward);

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
    for (int i = 0; i < collumns; i++) {
        Trees.setElement(i, line[i] - 48); //48 is the decimal value for char '0' in ASCII.
    }
    rc = read_line(input_file, line, BUFFER_SIZE);
    while (rc > FILE_EOF) {
        Trees.addRow();
        rows++;
        for (int i = 0; i < collumns; i++) {
            Trees.setElement(rows, i+1, line[i] - 48);
        }
        rc = read_line(input_file, line, BUFFER_SIZE);
    }

    for (int j = 2; j <= rows-1; j++) {
        for (int k = 2; k <= collumns-1; k++) {
            int score = 1;
            //up
            score *= count_trees(Trees, j, k, false, false);
            //down
            score *= count_trees(Trees, j, k, false, true);
            //left
            score *= count_trees(Trees, j, k, true, false);
            //right
            score *= count_trees(Trees, j, k, true, true);
            answer = answer < score ? score : answer;
        }
    }

    std::cout << "answer: " << answer << std::endl;
    return 0;
}

int count_trees(Matrix A, int j, int k, bool at_row, bool forward) {
    int count = 0;
    int hight = A.getElement(j,k);
    if (at_row) {
        for (int z = forward?k+1:k-1; ((forward && z <= A.collumns()) || (!forward && z >= 1)); forward?z++:z--) {
            count++;
            if (hight <= A.getElement(j, z)) {
                break;
            }
        }
    }
    else {
        for (int z = forward?j+1:j-1; ((forward && z <= A.rows()) || (!forward && z >= 1)); forward?z++:z--) {
            count++;
            if (hight <= A.getElement(z, k)) {
                break;
            }
        }
    }
    return count;
}
