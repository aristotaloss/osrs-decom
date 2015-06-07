//
// Created by bart on 6/7/15.
//

#ifndef OSRS_DECOM_CS2FILE_H
#define OSRS_DECOM_CS2FILE_H


#include <vector>
#include <iostream>

class cs2file {

public:
    int num_instr;
    int num_int_params;
    int num_string_params;
    int num_int_locals;
    int num_string_locals;
    std::vector<int> instructions;
    std::vector<int> int_operands;
    std::vector<std::string> string_operands;

    cs2file(std::vector<char> data);
    std::string disassemble();

};


#endif //OSRS_DECOM_CS2FILE_H
