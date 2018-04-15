//
// Created by thiagofsr on 30/03/18.
//


#include "Memory.h"


void decodeArguments(Instruction& instr,std::string argument,int argIndex){
    int value;

    if(std::toupper(argument.at(0)) == 'R') {
        instr.args[argIndex].typeOfAccess = REGISTER;
        value = (int)std::strtol(argument.substr(2,argument.size()).c_str(), nullptr,10);
    }
    else if(std::toupper(argument.at(0)) == 'M') {
        instr.args[argIndex].typeOfAccess = MEMORY;
        value = (int)std::strtol(argument.substr(2,argument.size()).c_str(), nullptr,10);

    }else if(argument.at(0) == '\''){
        instr.args[argIndex].typeOfAccess = DIRECT;
        int pos = argument.find_last_of('\'');

        instr.args[argIndex].textArg = argument.substr(1,pos-1);

    }else if(argument == "EAX"){
        instr.args[argIndex].typeOfAccess = REGISTER;
        value = EAX;

    }
    else if(argument == "EBX"){
        instr.args[argIndex].typeOfAccess = REGISTER;
        value = EBX;
    }
    else if(argument == "ECX"){
        instr.args[argIndex].typeOfAccess = REGISTER;
        value = ECX;
    }
    else if(argument == "EDX"){
        instr.args[argIndex].typeOfAccess = REGISTER;
        value = EDX;
    }
    else if(argument == "ESI"){
        instr.args[argIndex].typeOfAccess = REGISTER;
        value = ESI;
    }
    else if(argument == "EDI"){
        instr.args[argIndex].typeOfAccess = REGISTER;
        value = EDI;
    }
    else{
        instr.args[argIndex].typeOfAccess = DIRECT;
        value = (int)std::strtol(argument.c_str(), nullptr,10);
    }

    instr.args[argIndex].value = value;


}

Memory::Memory(std::string instructionPath, std::string dataPath) {
    instructionFile.open(instructionPath.c_str(),std::ios_base::in);
    if(!instructionFile.is_open()){
        ErrorOpFile("instruction");
    }
    dataFile.open(dataPath.c_str(),std::ios_base::in | std::ios::out);
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
        if(!line.empty()) {
            if(line.at(0) != '#')
                instructions.push_back(line);
        }
    }

}

int Memory::readData(int index) {

    if(index > data.size() || index < 0){
        ErrorOpExecution("ReadData");
    }
    std::string::size_type size;

    return stoi(data.at(index),&size);

}


void Memory::readInstruction(int index, Instruction& instr) {
    if(index > instructions.size() || index < 0){
        ErrorOpExecution("ReadInstrunction");
    }
    std::string fullInstruction = (std::string)instructions.at(index);
    std::string op;
    char * writable = new char[fullInstruction.size() + 1];
    std::copy(fullInstruction.begin(), fullInstruction.end(), writable);
    writable[fullInstruction.size()] = '\0';

    char *temp = strtok(writable," ");

    op = temp;
    instr.operation = op;
    int i = 0;
    temp = strtok(NULL,",");

    while(temp!= NULL){
        decodeArguments(instr,temp,i++);
        temp = strtok(NULL, ",");
    }

    for(;i<3;i++){
        instr.args[i].typeOfAccess = NONE;
        instr.args[i].value = -1;
        instr.args[i].textArg = "empty";
    }

    delete[]writable;
}


void Memory::WriteDataFile() {
    dataFile.clear();
    dataFile.seekg(0,std::ios::beg);
    for(std::string i:data){

        dataFile << i;
        dataFile << '\n';

    }


}

void Memory::writeData(int index, int value) {
    if(index > data.size() || index < 0 ) {
        ErrorOpExecution("WriteData")

    }
    data.at(index) = std::to_string(value);

}

int Memory::numberOfInstrunctions() {
    return instructions.size();
}

int Memory::numberOfData() {
    return data.size();
}







