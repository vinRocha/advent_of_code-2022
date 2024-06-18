/*
 * adv_2022_03_01.cpp
 *
 *  Created on: 03 Dec 2022
 *      Author: vsilva1
 */
#include <cstdlib>
#include <vector>
#include "file_handler.h" //includes iostream / fstream.

#define BUFFER_SIZE 81 //amount of characters read per line;
#define NPOS std::string::npos //return value for substring not found

const char *file_name = "challenges/03/input/vrs_03.txt";

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

    //compute answer
    for (std::vector<char*>::iterator it1 = lines.begin();
            it1 != lines.end(); it1++){

        std::string *s = new std::string(*it1);
        std::string *s1 = new std::string(s->substr(0, s->length()/2));
        std::string *s2 = new std::string(s->substr(s->length()/2, s->length()/2));
        size_t pos = NPOS;
        for (std::string::iterator it2 = s1->begin();
                (it2 != s1->end() && pos == NPOS); it2++){
            pos = s2->find(*it2);
        }

        if (pos == NPOS) continue;
        islower((*s2)[pos]) ? answer += ((*s2)[pos] - 96) : answer += ((*s2)[pos] - 64 + 26);
        delete s;
        delete s1;
        delete s2;
    }

    std::cout << "answer: " << answer << std::endl;
    return 0;
}
