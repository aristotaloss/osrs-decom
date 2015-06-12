//
// Created by bart on 6/12/15.
//

#ifndef OSRS_DECOM_INSTRUCTION_H
#define OSRS_DECOM_INSTRUCTION_H


#include <string>

class instruction {
public:
    int addr;
    int opcode;
    int i_operand;
    std::string s_operand;
    instruction(int opcode, int i_operand, std::string string) {
        this->opcode = opcode;
        this->i_operand = i_operand;
        this->s_operand = s_operand;
    }

    bool isJump();
};


#endif //OSRS_DECOM_INSTRUCTION_H
