//
// Created by thiagofsr on 31/03/18.
//

#include "CPU.h"

CPU::CPU(std::string instructionsPath, std::string dataPath) {
    programCounter = 0;
    cycles = 0;
    memory = new Memory(instructionsPath,dataPath);

}

CPU::~CPU() {
    delete memory;

}

void CPU::fetch() {
    memory->readInstruction(programCounter,instr);
    programCounter++;
    cycles++;

}

bool CPU::decode() {
    if(instr.operation == "ADD")
        op = ADD;
    else if(instr.operation == "SUB")
        op = SUB;
    else if(instr.operation == "MUL")
        op = MUL;
    else if(instr.operation =="DIV")
        op = DIV;
    else if(instr.operation =="LOAD")
        op = LOAD;
    else if(instr.operation == "STORE")
        op = STORE;
    else if(instr.operation == "COPY")
        op = COPY;
    else if(instr.operation == "COMP")
        op = COMP;
    else if(instr.operation == "JUMP")
        op = JUMP;
    else if(instr.operation == "JZ")
        op = JZ;
    else if(instr.operation == "JL")
        op = JL;
    else if(instr.operation == "JG")
        op = JG;
    else if(instr.operation == "JE")
        op = JE;
    else if(instr.operation == "JGE")
        op = JGE;
    else if(instr.operation == "JLE")
        op = JLE;
    else if(instr.operation == "JD")
        op = JD;
    else if(instr.operation == "PRINT")
        op = PRINT;
    else if(instr.operation == "RET") {
        op = RET;
    }
    else if(instr.operation == "READINT")
        op = READINT;
    else
        ErrorOpDecode(instr.operation);
    cycles++;
    return op == RET? true:false;

}


void CPU::execute() {

    int a,b,c;
    switch(op){
        case ADD:
            if(instr.argument1.typeOfAccess == REGISTER && instr.argument2.typeOfAccess == REGISTER){
                a = registers[instr.argument1.index];
                b = registers[instr.argument2.index];
                a += b;
                registers[instr.argument1.index] = a;

            }else if(instr.argument1.typeOfAccess == MEMORY && instr.argument2.typeOfAccess == REGISTER){
                a = memory->readData(instr.argument1.index);
                b = registers[instr.argument2.index];
                a += b;
                memory->writeData(instr.argument1.index,a);

            }else if(instr.argument1.typeOfAccess == REGISTER && instr.argument2.typeOfAccess == MEMORY){
                a = registers[instr.argument1.index];
                b = memory->readData(instr.argument2.index);
                a += b;
                registers[instr.argument1.index] = a;

            }else if(instr.argument1.typeOfAccess == REGISTER && instr.argument2.typeOfAccess == DIRECT){
                a = registers[instr.argument1.index];
                b = instr.argument2.index;
                a += b;
                registers[instr.argument1.index] = a;

            }else if(instr.argument1.typeOfAccess == MEMORY && instr.argument2.typeOfAccess == DIRECT){
                a = memory->readData(instr.argument1.index);
                b = instr.argument2.index;
                a += b;
                memory->writeData(instr.argument1.index,a);

            }else
                ErrorOpExecution("ADD");
            break;
        case SUB:
            if(instr.argument1.typeOfAccess == REGISTER && instr.argument2.typeOfAccess == REGISTER){
                a = registers[instr.argument1.index];
                b = registers[instr.argument2.index];
                a -= b;
                registers[instr.argument1.index] = a;

            }else if(instr.argument1.typeOfAccess == MEMORY && instr.argument2.typeOfAccess == REGISTER){
                a = memory->readData(instr.argument1.index);
                b = registers[instr.argument2.index];
                a -= b;
                memory->writeData(instr.argument1.index,a);

            }else if(instr.argument1.typeOfAccess == REGISTER && instr.argument2.typeOfAccess == MEMORY){
                a = registers[instr.argument1.index];
                b = memory->readData(instr.argument2.index);
                a -= b;
                registers[instr.argument1.index] = a;

            }else if(instr.argument1.typeOfAccess == REGISTER && instr.argument2.typeOfAccess == DIRECT){
                a = registers[instr.argument1.index];
                b = instr.argument2.index;
                a -= b;
                registers[instr.argument1.index] = a;

            }else if(instr.argument1.typeOfAccess == MEMORY && instr.argument2.typeOfAccess == DIRECT){
                a = memory->readData(instr.argument1.index);
                b = instr.argument2.index;
                a -= b;
                memory->writeData(instr.argument1.index,a);

            }else
            ErrorOpExecution("SUB");
            break;
        case MUL:
            if(instr.argument1.typeOfAccess == REGISTER && instr.argument2.typeOfAccess == REGISTER){
                a = registers[instr.argument1.index];
                b = registers[instr.argument2.index];
                a *= b;
                registers[instr.argument1.index] = a;

            }else if(instr.argument1.typeOfAccess == MEMORY && instr.argument2.typeOfAccess == REGISTER){
                a = memory->readData(instr.argument1.index);
                b = registers[instr.argument2.index];
                a *= b;
                memory->writeData(instr.argument1.index,a);

            }else if(instr.argument1.typeOfAccess == REGISTER && instr.argument2.typeOfAccess == MEMORY){
                a = registers[instr.argument1.index];
                b = memory->readData(instr.argument2.index);
                a *= b;
                registers[instr.argument1.index] = a;

            }else if(instr.argument1.typeOfAccess == REGISTER && instr.argument2.typeOfAccess == DIRECT){
                a = registers[instr.argument1.index];
                b = instr.argument2.index;
                a *= b;
                registers[instr.argument1.index] = a;

            }else if(instr.argument1.typeOfAccess == MEMORY && instr.argument2.typeOfAccess == DIRECT){
                a = memory->readData(instr.argument1.index);
                b = instr.argument2.index;
                a *= b;
                memory->writeData(instr.argument1.index,a);

            }else
        ErrorOpExecution("MUL");

            break;
        case DIV:
            if(instr.argument1.typeOfAccess == REGISTER && instr.argument2.typeOfAccess == NONE){
                a = registers[instr.argument1.index];
                c = registers[EAX] % a;
                registers[EAX] /= a; //quotient
                registers[EDX] = c; //remainder
                registers[instr.argument1.index] = a;

            }else if(instr.argument1.typeOfAccess == MEMORY && instr.argument2.typeOfAccess == NONE){
                a = memory->readData(instr.argument1.index);
                c = registers[EAX] % a;
                registers[EAX] /= a; //quotient
                registers[EDX] = c; //remainder
                memory->writeData(instr.argument1.index,a);
            }else
                ErrorOpExecution("DIV");

            break;
        case LOAD:
            break;
        case STORE:
            break;
        case COPY:
            break;
        case COMP:
            break;
        case JUMP:
            break;
        case JZ:
            break;
        case JL:
            break;
        case JG:
            break;
        case JE:
            break;
        case JGE:
            break;
        case JLE:
            break;
        case JD:
            break;
        case PRINT:
            break;
        case RET:
            break;
    }









}

void CPU::init() {
    bool ret = false;
    memory->LoadInstructions();
    memory->LoadData();

    while(programCounter <= memory->numberOfInstrunctions() && ret == false){
        fetch();
        ret = decode();
        execute();

    }
}


