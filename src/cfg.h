//
// Created by bart on 6/12/15.
//

#ifndef OSRS_DECOM_CFG_H
#define OSRS_DECOM_CFG_H

#include "instruction.h"
class instruction;

class cfg {
private:
    int instr_count;
    instruction **instructions;
    bool *headers;
public:
    cfg(int num_instr);
    ~cfg();
    void set_instr_at(int pos, instruction instruction);
    void discover_headers();
};


#endif //OSRS_DECOM_CFG_H
