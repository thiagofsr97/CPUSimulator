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
    int returnCode;

    int cycles;
    void compareAndSetFlag(int,int);
    void fetch();

    void decode();
    bool execute();
    void deactivate();
public:
    int getCycles();
    int getReturnCode();


    CPU(std::string, std::string);
    ~CPU();
    int init();


};


#endif //CPUSIMULATOR_CPU_H
