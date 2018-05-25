//
// Created by thiagofsr on 24/05/18.
//

#include "CacheData.h"

CacheData::CacheData(Instruction instr) {
    this->tag = INSTR_DATA;
    this->instruction = instr;
}
CacheData::CacheData(int value) {
    this->tag = VALUE_DATA;
    this->value = value;
}

Instruction CacheData::readInstruction() {
    if(this->tag == INSTR_DATA)
        return this->instruction;
}

int CacheData::readValue() {
    if(this->tag == VALUE_DATA)
        return this->value;
}

