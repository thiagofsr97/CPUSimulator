//
// Created by thiagofsr on 31/03/18.
//

#ifndef CPUSIMULATOR_CPU_H
#define CPUSIMULATOR_CPU_H


#include "Memory.h"
#include "Utils.h"
#include "Cache/Cache.h"

class CPU {

private:

    bool flags[7]={false};
    int registers[16]={0};
    Memory* memory;
    Cache *cache;
    Instruction instr;
    Operation op;
    std::string activeOperation;
    int programCounter;
    int returnCode;

    int cycles;
    void compareAndSetFlag(int,int);
    void fetch();
    int fetchOperands(Instruction,int);
    void writeData(Instruction,int, int );
    void compare(int);

    void decode();
    bool execute();
    void deactivate();
public:
    int getCycles();
    int getReturnCode();
    int getNumberOfHits();
    int getNumberOfMisses();


    CPU(std::string, std::string);
    ~CPU();
    int init();


};


#endif //CPUSIMULATOR_CPU_H
