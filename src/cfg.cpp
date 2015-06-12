//
// Created by bart on 6/12/15.
//

#include "cfg.h"
class instruction;

cfg::cfg(int num_instr) {
    this->instr_count = num_instr;
    this->instructions = new instruction*[num_instr]();
    this->headers = new bool[num_instr]();
}

cfg::~cfg() {

}

void cfg::set_instr_at(int pos, instruction ins) {
    if (pos < instr_count) {
        instructions[pos] = new instruction(ins);
        instructions[pos]->addr = pos;
    }
}

void cfg::discover_headers() {
    headers[0] = true;
    headers[instr_count - 1] = true;

    for (int i=0; i<instr_count; i++) {
        if (instructions[i]->isJump()) {
            headers[i + 1] = true; // Fall-through is a header
            headers[i + instructions[i]->i_operand + 1] = true; // Target is header
        }
    }
}
