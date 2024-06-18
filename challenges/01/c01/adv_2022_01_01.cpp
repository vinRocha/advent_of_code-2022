/*
 * adv_2022_01_01.cpp
 *
 *  Created on: 01 Dec 2022
 *      Author: vsilva1
 */

#include <cstdlib>
#include <vector>
#include "file_handler.h" //includes iostream / fstream.

#define BUFFER_SIZE 81 //amount of characters read per line;
const char *file_name = "challenges/01/input/vrs_01.txt";

int main(int argc, char **argv) {

    char line[BUFFER_SIZE]; //Character buffer for readline;
    std::vector<int> elf_supplies; //amount of calories carried by each elf.
    std::fstream input_file;
    int elf = 0;
    int most_calories = 0;
    int rc = FILE_OK;

    input_file.open(file_name, std::ios_base::in); //open file in read-only mode;
    rc = file_state(input_file);
    if (rc < FILE_OK) {
        std::cerr << "Error opening " << file_name << "\n";
        input_file.close();
        return rc;
    }

    //store supplies for each elf given by input_file:
    elf_supplies.push_back(0);
    while (rc > FILE_EOF) {
        input_file.getline(line, BUFFER_SIZE);
        rc = file_state(input_file);
        if (rc < FILE_EOF){ //badbit || failbit
            input_file.close();
            return rc;
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
