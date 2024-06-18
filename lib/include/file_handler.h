/*
 * file_handler.h
 *
 *  Created on: 15 Jun 2024
 *      Author: vsilva1
 */
#ifndef LIB_INCLUDE_FILEHANDLER_H_
#define LIB_INCLUDE_FILEHANDLER_H_

#include <iostream>
#include <fstream>

enum {
    FILE_BAD = -3,
    FILE_FAIL,
    FILE_EOF,
    FILE_OK
};

int file_state(std::fstream &input_file);
int read_line(std::fstream &input_file, char *line, size_t size);

#endif /* LIB_INCLUDE_FILEHANDLER_H_ */