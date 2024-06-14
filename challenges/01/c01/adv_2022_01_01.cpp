/*
 * adv_2022_01_01.cpp
 *
 *  Created on: 01 Dec 2022
 *      Author: vsilva1
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

#define BUFFER_SIZE 81 //amount of characters read per line;
#define INPUT_FILE "challenges/01/input/vrs_01.txt"

enum {
    READ_OK,
    READ_EOF,
    READ_FAIL,
    READ_BAD
};

int read_status(std::fstream &input_file) {
    if (input_file.eof()) {
        std::cerr << "EOF: "<< INPUT_FILE << "\n";
        return READ_EOF;
    }
    else if (input_file.bad()) {
        std::cerr << "Error reading from " << INPUT_FILE << "\n";
        return READ_BAD;
    }
    else if (input_file.fail()) {
        std::cerr << "Fail to read input to variable." << "\n";
        return READ_FAIL;
    }
    return READ_OK;
}

int main(int argc, char **argv) {

    char line[BUFFER_SIZE]; //Character buffer for readline;
    std::vector<int> elf_supplies; //amount of calories carried by each elf.
    std::fstream input_file;
    int elf = 0;
    int most_calories = 0;
    int rc = READ_OK;

    input_file.open(INPUT_FILE, std::ios_base::in); //open file in read-only mode;
    rc = read_status(input_file);
    if (rc > READ_OK) {
        std::cerr << "Error opening " << INPUT_FILE << "\n";
        input_file.close();
        return -rc;
    }

    //store supplies for each elf given by input_file:
    elf_supplies.push_back(0);
    while (rc < READ_EOF) {
        input_file.getline(line, BUFFER_SIZE);
        rc = read_status(input_file);
        if (rc > READ_EOF){ //badbit || failbit
            input_file.close();
            return -rc;
        } else if (*line){
            elf_supplies[elf] += atoi(line);
        } else {
            elf_supplies.push_back(0);
            elf++;
        }
    }

    for (std::vector<int>::iterator it = elf_supplies.begin();
            it != elf_supplies.end(); it++){
        if (most_calories < *it) most_calories = *it;
    }

    std::cout << "answer: " << most_calories << std::endl;
    return 0;

}
