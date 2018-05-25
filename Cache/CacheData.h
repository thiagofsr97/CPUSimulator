//
// Created by thiagofsr on 24/05/18.
//

#ifndef CPUSIMULATOR_CACHEDATA_H
#define CPUSIMULATOR_CACHEDATA_H



#include "../Memory.h"
#include "Utils.h"

class CacheData{
private:
    Instruction instruction;
    int value;
    data_type tag;

public:
    CacheData(Instruction instr);
    CacheData(int value);
    Instruction readInstruction();
    int readValue();
};


#endif //CPUSIMULATOR_CACHEDATA_H
