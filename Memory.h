//
// Created by thiagofsr on 30/03/18.
//

#ifndef CPUSIMULATOR_MEMORY_H
#define CPUSIMULATOR_MEMORY_H


#include <vector>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Utils.h"



typedef struct argument{
    int index;
    access typeOfAccess;
};

typedef struct Instruction{
    std::string operation;
    argument argument1;
    argument argument2;
};

class Memory {
private:
    std::vector<std::string> instructions;
    std::vector<std::string> data;
    std::fstream instructionFile;
    std::fstream dataFile;

public:
    int numberOfInstrunctions();
    int numberOfData();
    Memory(std::string instructionPath, std::string dataPath);
    ~Memory();
    int readData(int);
    void writeData(int,int);
    void readInstruction(int,Instruction&);
    void LoadInstructions();
    void LoadData();
    void WriteDataFile();

};


#endif //CPUSIMULATOR_MEMORY_H
