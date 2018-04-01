//
// Created by thiagofsr on 30/03/18.
//

#include <cstring>
#include "Memory.h"


void decodeArguments(Instruction& instr,std::string firstArgument, std::string secondArgument){
    int value;
    instr.argument1.textArg = firstArgument;
    instr.argument2.textArg = "none";

    if(std::toupper(firstArgument.at(0)) == 'R') {
        instr.argument1.typeOfAccess = REGISTER;
        value = (int)std::strtol(firstArgument.substr(2,firstArgument.size()).c_str(), nullptr,10);
    }
    else if(std::toupper(firstArgument.at(0)) == 'M') {
        instr.argument1.typeOfAccess = MEMORY;
        value = (int)std::strtol(firstArgument.substr(2,firstArgument.size()).c_str(), nullptr,10);

    }else if(firstArgument.at(0) == '\''){
        instr.argument1.typeOfAccess = DIRECT;
        int pos = firstArgument.find_last_of('\'');

        instr.argument1.textArg = firstArgument.substr(1,pos-1);

    }else if(firstArgument == "EAX"){
        instr.argument1.typeOfAccess = REGISTER;
        value = EAX;

    }
    else if(firstArgument == "EBX"){
        instr.argument1.typeOfAccess = REGISTER;
        value = EBX;
    }
    else if(firstArgument == "ECX"){
        instr.argument1.typeOfAccess = REGISTER;
        value = ECX;
    }
    else if(firstArgument == "EDX"){
        instr.argument1.typeOfAccess = REGISTER;
        value = EDX;
    }
    else if(firstArgument == "ESI"){
        instr.argument1.typeOfAccess = REGISTER;
        value = ESI;
    }
    else if(firstArgument == "EDI"){
        instr.argument1.typeOfAccess = REGISTER;
        value = EDI;
    }
    else{
        instr.argument1.typeOfAccess = DIRECT;
        value = (int)std::strtol(firstArgument.c_str(), nullptr,10);
    }

    instr.argument1.index = value;

    if(!secondArgument.empty()){

        if(std::toupper(secondArgument.at(0)) == 'R') {
            instr.argument2.typeOfAccess = REGISTER;
            value = (int)std::strtol(secondArgument.substr(2,secondArgument.size()).c_str(), nullptr,10);
        }
        else if (std::toupper(secondArgument.at(0)) == 'M') {
            instr.argument2.typeOfAccess = MEMORY;
            value = (int)std::strtol(secondArgument.substr(2,secondArgument.size()).c_str(), nullptr,10);
        }else if(firstArgument.at(0) == '\''){
            instr.argument2.typeOfAccess = DIRECT;
            int pos = secondArgument.find_last_of('\'');

            instr.argument1.textArg = secondArgument.substr(1,pos-1);

        }else if(firstArgument == "EAX"){
            instr.argument1.typeOfAccess = REGISTER;
            value = EAX;

        }
        else if(firstArgument == "EBX"){
            instr.argument1.typeOfAccess = REGISTER;
            value = EBX;
        }
        else if(firstArgument == "ECX"){
            instr.argument1.typeOfAccess = REGISTER;
            value = ECX;
        }
        else if(firstArgument == "EDX"){
            instr.argument1.typeOfAccess = REGISTER;
            value = EDX;
        }
        else if(firstArgument == "ESI"){
            instr.argument1.typeOfAccess = REGISTER;
            value = ESI;
        }
        else if(firstArgument == "EDI"){
            instr.argument1.typeOfAccess = REGISTER;
            value = EDI;
        }
        else{
            instr.argument2.typeOfAccess = DIRECT;

            value = (int)std::strtol(secondArgument.c_str(), nullptr,10);
        }
        instr.argument2.index = value;

    }else{

        instr.argument2.index = -1;
        instr.argument2.typeOfAccess = NONE;
    }



}

Memory::Memory(std::string instructionPath, std::string dataPath) {
    instructionFile.open(instructionPath,std::ios_base::in);
    if(!instructionFile.is_open()){
        ErrorOpFile("instruction");
    }
    dataFile.open(dataPath,std::ios_base::in |std::ios_base::out);
    if(!dataFile.is_open()){
        ErrorOpFile("data");
    }

}


Memory::~Memory() {
    instructionFile.close();
    dataFile.close();

}

void Memory::LoadData() {
    std::string line;
    while(!dataFile.eof()){
        getline(dataFile,line);
        data.push_back(line);
    }

}

void Memory::LoadInstructions() {
    std::string line;
    int i = 0;
    while(!instructionFile.eof()){
        getline(instructionFile,line);
        if(!line.empty())
            instructions.push_back(line);
    }

}

int Memory::readData(int index) {

    if(index > data.size() || index < 0){
        return rand() % 100000;
    }
    std::string::size_type size;

    return stoi(data.at(index),&size);

}

void Memory::readInstruction(int index, Instruction& instr) {
    std::string fullInstruction = (std::string)instructions.at(index);
    std::string op, firstArgument,secondArgument;
    int spacePosition,commaPosition;
    spacePosition = (int)fullInstruction.find(" ");
    if(spacePosition == std::string::npos){
        CompilationError();
    }
    op = instructions.at(index).substr(0,spacePosition);
    instr.operation = op;

    commaPosition = fullInstruction.find(",",spacePosition);
    if(commaPosition == std::string::npos){
        if((fullInstruction.size() - spacePosition) > 0){
            firstArgument = fullInstruction.substr(spacePosition + 1,fullInstruction.size());
            decodeArguments(instr,firstArgument,"");


        }
        else {
            CompilationError();
        }
    }else {
        firstArgument = fullInstruction.substr(spacePosition + 1, commaPosition - 1);
        secondArgument = fullInstruction.substr(commaPosition + 1, fullInstruction.size());
        decodeArguments(instr,firstArgument,secondArgument);

    }
}

void Memory::WriteDataFile() {

    for(std::string i:data){
        dataFile << i;
    }


}

void Memory::writeData(int index, int value) {
    if(index > data.size() || index < 0 )
        return;
    data.at(index) = std::to_string(value);

}

int Memory::numberOfInstrunctions() {
    return instructions.size();
}

int Memory::numberOfData() {
    return data.size();
}







