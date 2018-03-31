//
// Created by thiagofsr on 31/03/18.
//

#ifndef CPUSIMULATOR_CPU_H
#define CPUSIMULATOR_CPU_H


#include "Memory.h"
#include "Utils.h"

class CPU {

private:

    bool flags[7]={false};
    int registers[16]={0};
    Memory* memory;

    Instruction instr;
    Operation op;
    int programCounter;

    int cycles;
    void fetch();

    bool decode();
    void execute();
public:


    CPU(std::string, std::string);
    ~CPU();
    void init();

};


#endif //CPUSIMULATOR_CPU_H
