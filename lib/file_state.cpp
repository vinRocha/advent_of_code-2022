/*
 * file_state.cpp
 *
 *  Created on: 15 Jun 2024
 *      Author: vsilva1
 */

#include "file_state.h"

extern const char* file_name;

int file_state(std::fstream &input_file) {
    if (input_file.eof()) {
        std::cerr << "EOF: "<< file_name << "\n";
        return FILE_EOF;
    }
    else if (input_file.bad()) {
        std::cerr << "IO error from: " << file_name << "\n";
        return FILE_BAD;
    }
    else if (input_file.fail()) {
        std::cerr << "IO failure from: " << file_name << "\n";
        return FILE_FAIL;
    }
    return FILE_OK;
}