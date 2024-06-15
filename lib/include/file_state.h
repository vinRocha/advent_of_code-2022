/*
 * file_status.h
 *
 *  Created on: 15 Jun 2024
 *      Author: vsilva1
 */
#ifndef LIB_INCLUDE_FILESTATE_H_
#define LIB_INCLUDE_FILESTATE_H_

#include <iostream>
#include <fstream>

enum {
    FILE_BAD = -3,
    FILE_FAIL,
    FILE_EOF,
    FILE_OK
};

int file_state(std::fstream &input_file);

#endif /* LIB_INCLUDE_FILESTATE_H_ */