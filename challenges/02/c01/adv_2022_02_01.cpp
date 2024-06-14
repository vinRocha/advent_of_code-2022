/*
 * adv_2022_02_01.cpp
 *
 *  Created on: 02 Dec 2022
 *      Author: vsilva1
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#define INPUT_FILE "challenges/02/input/vrs_02.txt"

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

int play_error(char, char);

int main(int argc, char **argv) {

    std::fstream input_file;
    std::string buffer; //string buffer to read input file
    std::vector<char> player1; //my play
    std::vector<char> player2; //opponents' play
    std::vector<int> my_score; //my_score
    int answer = 0;
    int rc;

    input_file.open(INPUT_FILE, std::ios_base::in); //open file in read-only mode;
    rc = read_status(input_file);
    if (rc > READ_OK) {
        std::cerr << "Error opening " << INPUT_FILE << "\n";
        input_file.close();
        return -rc;
    }

    //store play for each player given by input_file:
    input_file >> buffer;
    rc = read_status(input_file);
    while (rc < READ_EOF) {
        if (*buffer.c_str() > 'D') {
            player1.push_back(*buffer.c_str());
        }
        else if (*buffer.c_str() < 'D') {
            player2.push_back(*buffer.c_str());
        }
        else {
            std::cerr << "Invalid input: " << buffer << "\n";
        }
        input_file >> buffer;
        rc = read_status(input_file);
    }
    input_file.close();

    if (rc > READ_EOF) {
        return -rc;
    }

    if (player1.size() != player2.size()){
        std::cerr << "Error in vector sizes.\n";
        return 2;
    }

    //compute scores:
    std::vector<char>::iterator it1 = player1.begin();
    std::vector<char>::iterator it2 = player2.begin();
    while (it1 != player1.end()){
        switch (*it1) {
        case 'X':
            if (*it2 == 'A') my_score.push_back(4);
            else if (*it2 == 'B') my_score.push_back(1);
            else if (*it2 == 'C')my_score.push_back(7);
            else return play_error(*it2, *it1);
            break;
        case 'Y':
            if (*it2 == 'B') my_score.push_back(5);
            else if (*it2 == 'C') my_score.push_back(2);
            else if (*it2 == 'A') my_score.push_back(8);
            else return play_error(*it2, *it1);
            break;
        case 'Z':
            if (*it2 == 'C') my_score.push_back(6);
            else if (*it2 == 'A') my_score.push_back(3);
            else if (*it2 == 'B') my_score.push_back(9);
            else return play_error(*it2, *it1);
            break;
        default:
            return play_error(*it2, *it1);
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
