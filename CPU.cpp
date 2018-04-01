//
// Created by thiagofsr on 31/03/18.
//

#include "CPU.h"



CPU::CPU(std::string instructionsPath, std::string dataPath) {
    programCounter = 0;
    cycles = 0;
    returnCode = 0;
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
    else if(instr.operation == "MOV")
        op = MOV;
    else if(instr.operation == "COPY")
        op = COPY;
    else if(instr.operation == "CMP")
        op = CMP;
    else if(instr.operation == "JMP")
        op = JMP;
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
    else if(instr.operation == "RET")
        op = RET;
    else if(instr.operation == "READINT")
        op = READINT;
    else{

        ErrorOpDecode(instr.operation);
    }

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
        case MOV:
            if(instr.argument1.typeOfAccess == REGISTER && instr.argument2.typeOfAccess == REGISTER){
                registers[instr.argument1.index] = registers[instr.argument2.index];
            }else if(instr.argument1.typeOfAccess == REGISTER && instr.argument2.typeOfAccess == MEMORY){
                b = memory->readData(instr.argument2.index);
                registers[instr.argument1.index] = b;
            }else if(instr.argument1.typeOfAccess == MEMORY && instr.argument2.typeOfAccess == REGISTER){
                memory->writeData(instr.argument1.index,registers[instr.argument2.index]);
            }else if(instr.argument1.typeOfAccess == MEMORY && instr.argument2.typeOfAccess == DIRECT){
                b = instr.argument2.index;
                memory->writeData(instr.argument1.index,b);
            }else if(instr.argument1.typeOfAccess == REGISTER && instr.argument2.typeOfAccess == DIRECT){
                b = instr.argument2.index;
                registers[instr.argument1.index] = b;

            }else {
                ErrorOpExecution("MOV");
            }
            break;

        case CMP:
            if(instr.argument1.typeOfAccess == REGISTER && instr.argument2.typeOfAccess == REGISTER){
                a = registers[instr.argument1.index];
                b = registers[instr.argument2.index];
                compareAndSetFlag(a,b);

            }else if(instr.argument1.typeOfAccess == REGISTER && instr.argument2.typeOfAccess == MEMORY){
                a = registers[instr.argument1.index];
                b = memory->readData(instr.argument2.index);
                compareAndSetFlag(a,b);
            }else if(instr.argument1.typeOfAccess == MEMORY && instr.argument2.typeOfAccess == REGISTER){
                a = memory->readData(instr.argument1.index);
                b = registers[instr.argument2.index];
                compareAndSetFlag(a,b);

            }else if(instr.argument1.typeOfAccess == REGISTER && instr.argument2.typeOfAccess == DIRECT){
                a = registers[instr.argument1.index];
                b = instr.argument2.index;
                compareAndSetFlag(a,b);
            }else
                ErrorOpExecution("CMP");
            break;
        case JMP:
            if(instr.argument1.typeOfAccess == DIRECT && instr.argument2.typeOfAccess == NONE){
                a = instr.argument1.index;
                programCounter = a;
            }else
                ErrorOpExecution("JMP");
            break;
        case JZ:
            if(instr.argument1.typeOfAccess == DIRECT && instr.argument2.typeOfAccess == NONE){
                a = instr.argument1.index;
                if(flags[JZ])
                    programCounter = a;
            }
            else
              ErrorOpExecution("JZ");
            break;
        case JL:
            if(instr.argument1.typeOfAccess == DIRECT && instr.argument2.typeOfAccess == NONE){
                a = instr.argument1.index;
                if(flags[JL])
                    programCounter = a;
            }else
                ErrorOpExecution("JMP");
            break;
        case JG:
            if(instr.argument1.typeOfAccess == DIRECT && instr.argument2.typeOfAccess == NONE){
                a = instr.argument1.index;
                if(flags[JG])
                    programCounter = a;
            }else
                ErrorOpExecution("JMP");
            break;
        case JE:
            if(instr.argument1.typeOfAccess == DIRECT && instr.argument2.typeOfAccess == NONE){
                a = instr.argument1.index;
                if(flags[JE])
                    programCounter = a;
            }else
                ErrorOpExecution("JMP");
            break;
        case JGE:
            if(instr.argument1.typeOfAccess == DIRECT && instr.argument2.typeOfAccess == NONE){
                a = instr.argument1.index;
                if(flags[JGE])
                    programCounter = a;
            }else
                ErrorOpExecution("JMP");
            break;
        case JLE:
            if(instr.argument1.typeOfAccess == DIRECT && instr.argument2.typeOfAccess == NONE){
                a = instr.argument1.index;
                if(flags[JLE])
                    programCounter = a;
            }else
                ErrorOpExecution("JMP");
            break;
        case JD:
            if(instr.argument1.typeOfAccess == DIRECT && instr.argument2.typeOfAccess == NONE){
                a = instr.argument1.index;
                if(flags[JD])
                    programCounter = a;
            }else
                ErrorOpExecution("JMP");
            break;
        case PRINT:
            if(instr.argument1.typeOfAccess == DIRECT && instr.argument2.typeOfAccess == NONE){
                std::cout << instr.argument1.textArg << std::endl;
            }else
                ErrorOpExecution("PRINT");
            break;
        case RET:
            if(instr.argument1.typeOfAccess == DIRECT && instr.argument2.typeOfAccess == NONE){
                a = instr.argument1.index;
                returnCode = a;
            }

            break;
    }
    cycles++;



}

int CPU::init() {
    bool ret = false;
    memory->LoadInstructions();
    memory->LoadData();

    std::cout << "N of instructions: " << memory->numberOfInstrunctions() << "\n";

    while((programCounter <= memory->numberOfInstrunctions()) && !ret){

        fetch();
        ret = decode();
        execute();

    }
    return returnCode;
}

void CPU::compareAndSetFlag(int a, int b) {
    for(int i = 0;i<7;i++){
        flags[i] = false;
    }
    if(a == 0) flags[ZERO] = true;
    if(a > b) flags[GREATER] = true;
    if(a >= b) flags[GREATEQUAL] = true;
    if(a < b) flags[LESSER] = true;
    if(a <= b) flags[LESSEQUAL] = true;
    if(a == b) flags[EQUAL] = true;
    if(a != b) flags[DIFFERNT] = true;


}


