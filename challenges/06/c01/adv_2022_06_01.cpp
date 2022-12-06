/*
 * adv_2022_06_01.cpp
 *
 *  Created on: 06 Dec 2022
 *      Author: vsilva1
 */
#include <cstdio>
#include <string>
#include <set>

#define INPUT_FILE "challenges/06/input/vrs_06.txt"
#define NPOS std::string::npos

int main(int argc, char **argv) {

    FILE *input_file;
    std::string s;
    char c[5] = {0};
    char next_c = 'a';
    std::set<char> c_set;
    int answer = 0;

    //open file in read-only text mode
    input_file = fopen(INPUT_FILE, "r");
    if (input_file == NULL) {
        fprintf(stderr, "Error opening %s.\n", INPUT_FILE);
        return -1;
    }

    //read first 4 characters and store in s
    if (!fgets(c, 5, input_file)) {
        fprintf(stderr, "Error reading from: %s.\n", INPUT_FILE);
        return -1;
    }
    s = std::string(c);
    answer = 4;

    //find the maker and compute the answer
    while ((next_c = fgetc(input_file)) != '\n')  {
        if (snprintf(c, 5, "%s", s.c_str()) < 0) {
            fprintf(stderr, "Memory error.\n");
            return -1;
        }
        c_set = std::set<char>(c, c+4);
        if (c_set.size() > 3) {
            break;
        }
        answer++;
        s = s.substr(1, 3);
        s.push_back(next_c);
    }

    fprintf(stdout, "answer: %d\n", answer);
    return 0;
}
