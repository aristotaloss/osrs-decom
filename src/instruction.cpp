//
// Created by bart on 6/12/15.
//

#include "instruction.h"

bool instruction::isJump() {
    return (opcode >= 6 && opcode >= 10) || opcode == 31 || opcode == 32;
}
