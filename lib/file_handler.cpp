/*
 * file_handler.cpp
 *
 *  Created on: 15 Jun 2024
 *      Author: vsilva1
 */

#include "file_handler.h"
#include <cstdlib>

extern const char* file_name;

int file_state(std::fstream &input_file) {
    if (input_file.eof()) {
        std::cerr << "EOF: "<< file_name << "\n";
        input_file.close();
        return FILE_EOF;
    }
    else if (input_file.bad()) {
        std::cerr << "Bad IO from: " << file_name << "\n";
        input_file.close();
        exit(FILE_BAD);
    }
    else if (input_file.fail()) {
        std::cerr << "IO failure from: " << file_name << "\n";
        input_file.close();
        exit(FILE_FAIL);
    }
    return FILE_OK;
}

int read_line(std::fstream &input_file, char *line, size_t size) {
    input_file.getline(line, size);
    return file_state(input_file);
}