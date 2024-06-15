/*
 * adv_2022_02_02.cpp
 *
 *  Created on: 02 Dec 2022
 *      Author: vsilva1
 */

#include <vector>
#include <string>
#include "file_state.h" //includes iostream / fstream.

const char *file_name = "challenges/02/input/vrs_02.txt";

int play_error(char, char);

int main(int argc, char **argv) {

    std::fstream input_file;
    std::string buffer; //string buffer to read input file
    std::vector<char> player2; //Oponent's play
    std::vector<char> results; //game_result
    std::vector<int> my_score; //my_score
    int answer = 0;
    int rc;

    input_file.open(file_name, std::ios_base::in); //open file in read-only mode;
    rc = file_state(input_file);
    if (rc < FILE_OK) {
        std::cerr << "Error opening " << file_name << "\n";
        input_file.close();
        return rc;
    }

    //store play for each player given by input_file:
    input_file >> buffer;
    rc = file_state(input_file);
    while (rc > FILE_EOF) {
        if (*buffer.c_str() > 'D') {
            results.push_back(*buffer.c_str());
        }
        else if (*buffer.c_str() < 'D') {
            player2.push_back(*buffer.c_str());
        }
        else {
            std::cerr << "Invalid input: " << buffer << "\n";
        }
        input_file >> buffer;
        rc = file_state(input_file);
    }
    input_file.close();

    if (rc < FILE_EOF) {
        return rc;
    }

    if (player2.size() != results.size()){
        std::cerr << "Error in vector sizes.\n";
        return 2;
    }

    //compute scores:
    std::vector<char>::iterator it1 = player2.begin();
    std::vector<char>::iterator it2 = results.begin();
    while (it1 != player2.end()){
        switch (*it1) {
        case 'A':
            if (*it2 == 'X') my_score.push_back(0+3);
            else if (*it2 == 'Y') my_score.push_back(3+1);
            else if (*it2 == 'Z') my_score.push_back(6+2);
            else return play_error(*it1, *it2);
            break;
        case 'B':
            if (*it2 == 'X') my_score.push_back(0+1);
            else if (*it2 == 'Y') my_score.push_back(3+2);
            else if (*it2 == 'Z') my_score.push_back(6+3);
            else return play_error(*it1, *it2);
            break;
        case 'C':
            if (*it2 == 'X') my_score.push_back(0+2);
            else if (*it2 == 'Y') my_score.push_back(3+3);
            else if (*it2 == 'Z') my_score.push_back(6+1);
            else return play_error(*it1, *it2);
            break;
        default:
            return play_error(*it1, *it2);
        }
        it1++; it2++; answer += my_score.back();
    }

    std::cout << "answer: " << answer << std::endl;
    return 0;
}

int play_error(char play1, char play2) {
    std::cerr << "Invalid play: " << play1 << ',' << play2 << "\n";
    return 2;
}