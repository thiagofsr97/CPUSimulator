//
// Created by thiagofsr on 30/03/18.
//

#ifndef CPUSIMULATOR_MEMORY_H
#define CPUSIMULATOR_MEMORY_H


#include <vector>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include "Utils.h"


struct argument{
    int value;
    std::string textArg;
    access typeOfAccess;
};

struct Instruction{
    std::string operation;
    argument args[3];
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
