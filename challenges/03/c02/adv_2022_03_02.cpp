/*
 * adv_2022_03_02.cpp
 *
 *  Created on: 03 Dec 2022
 *      Author: vsilva1
 */

#include <cstdlib>
#include <vector>
#include <string>
#include "file_handler.h" //includes iostream / fstream.

#define BUFFER_SIZE 81 //amount of characters read per line;
#define NPOS std::string::npos //return value for substring not found

const char *file_name = "challenges/03/input/vrs_03.txt";

size_t find_next_common_c(std::string &s1, std::string &s2, size_t &pos1) {
    if (pos1 > 0) pos1++;
    size_t pos2 = NPOS;
    while (pos1 < s1.size() && pos2 == NPOS){
        pos2 = s2.find(s1[pos1++]);
    }
    if (pos2 == NPOS) return s1.size();
    return pos1 - 1;
}

int main(int argc, char **argv) {

    std::fstream input_file;
    std::vector<char*> lines;
    int answer = 0; int rc;

    input_file.open(file_name, std::ios_base::in); //open file in read-only mode;
    rc = file_state(input_file);
    if (rc < FILE_OK) {
        std::cerr << "Error opening " << file_name << "\n";
        input_file.close();
        return rc;
    }

    //store rucksacks contents:
    do {
        lines.push_back(new char[BUFFER_SIZE]);
        input_file.getline(lines.back(), BUFFER_SIZE);
        rc = file_state(input_file);
        if (rc < FILE_EOF) { //badbit || failbit
            input_file.close();
            return rc;
        }
    } while (rc > FILE_EOF);
    lines.pop_back(); //remove last element because it will be empty;

    if (lines.size() % 3) {
        std::cerr << "#lines not divisable by 3. Check input file: " << file_name << "\n";
        return 2;
    }

    //compute answer
    for (std::vector<char*>::iterator itl = lines.begin();
            itl != lines.end();){

        std::string s1 = std::string(*(itl++));
        std::string s2 = std::string(*(itl++));
        std::string s3 = std::string(*(itl++));

        size_t pos1 = 0;
        size_t pos2 = NPOS;
        do {
            pos1 = find_next_common_c(s1, s2, pos1);
            if (pos1 == s1.size()) {
                std::cerr << "Could not find common item.\n";
                return -1;
            }
            pos2 = s3.find(s1[pos1]);
        } while (pos2 == NPOS);
        islower(s1[pos1]) ? answer += (s1[pos1] - 96) : answer += (s1[pos1] - 64 + 26);
    }

    std::cout << "answer: " << answer << std::endl;
    return 0;
}
