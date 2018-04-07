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

void CPU::decode() {

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
    else if(instr.operation == "PRINTV")
        op = PRINTV;
    else{

        ErrorOpDecode(instr.operation);
    }

    cycles++;

}


bool CPU::execute() {

    int a,b,c;
    bool toReturn = false;
    switch(op){

        case ADD:
            if(instr.args[0].typeOfAccess == REGISTER && instr.args[1].typeOfAccess == REGISTER && instr.args[2].typeOfAccess == NONE){
                a = registers[instr.args[0].value];
                b = registers[instr.args[1].value];
                a += b;
                registers[instr.args[0].value] = a;

            }else if(instr.args[0].typeOfAccess == MEMORY && instr.args[1].typeOfAccess == REGISTER && instr.args[2].typeOfAccess == NONE){
                a = memory->readData(instr.args[0].value);
                b = registers[instr.args[1].value];
                a += b;
                memory->writeData(instr.args[0].value,a);

            }else if(instr.args[0].typeOfAccess == REGISTER && instr.args[1].typeOfAccess == MEMORY && instr.args[2].typeOfAccess == NONE){
                a = registers[instr.args[0].value];
                b = memory->readData(instr.args[1].value);
                a += b;
                registers[instr.args[0].value] = a;

            }else if(instr.args[0].typeOfAccess == REGISTER && instr.args[1].typeOfAccess == DIRECT && instr.args[2].typeOfAccess == NONE){
                a = registers[instr.args[0].value];
                b = instr.args[1].value;
                a += b;
                registers[instr.args[0].value] = a;


            }else if(instr.args[0].typeOfAccess == MEMORY && instr.args[1].typeOfAccess == DIRECT && instr.args[2].typeOfAccess == NONE){
                a = memory->readData(instr.args[0].value);
                b = instr.args[1].value;
                a += b;
                memory->writeData(instr.args[0].value,a);

            }else
                ErrorOpExecution("ADD");
            break;
        case SUB:
            if(instr.args[0].typeOfAccess == REGISTER && instr.args[1].typeOfAccess == REGISTER && instr.args[2].typeOfAccess == NONE){
                a = registers[instr.args[0].value];
                b = registers[instr.args[1].value];
                a -= b;
                registers[instr.args[0].value] = a;

            }else if(instr.args[0].typeOfAccess == MEMORY && instr.args[1].typeOfAccess == REGISTER && instr.args[2].typeOfAccess == NONE){
                a = memory->readData(instr.args[0].value);
                b = registers[instr.args[1].value];
                a -= b;
                memory->writeData(instr.args[0].value,a);

            }else if(instr.args[0].typeOfAccess == REGISTER && instr.args[1].typeOfAccess == MEMORY && instr.args[2].typeOfAccess == NONE){
                a = registers[instr.args[0].value];
                b = memory->readData(instr.args[1].value);
                a -= b;
                registers[instr.args[0].value] = a;

            }else if(instr.args[0].typeOfAccess == REGISTER && instr.args[1].typeOfAccess == DIRECT && instr.args[2].typeOfAccess == NONE){
                a = registers[instr.args[0].value];
                b = instr.args[1].value;
                a -= b;
                registers[instr.args[0].value] = a;

            }else if(instr.args[0].typeOfAccess == MEMORY && instr.args[1].typeOfAccess == DIRECT && instr.args[2].typeOfAccess == NONE){
                a = memory->readData(instr.args[0].value);
                b = instr.args[1].value;
                a -= b;
                memory->writeData(instr.args[0].value,a);

            }else
                ErrorOpExecution("SUB");
            break;
        case MUL:

            if(instr.args[0].typeOfAccess == REGISTER && instr.args[1].typeOfAccess == REGISTER && instr.args[2].typeOfAccess == NONE){
                a = registers[instr.args[0].value];
                b = registers[instr.args[1].value];
                a *= b;
                registers[instr.args[0].value] = a;

            }else if(instr.args[0].typeOfAccess == MEMORY && instr.args[1].typeOfAccess == REGISTER && instr.args[2].typeOfAccess == NONE){
                a = memory->readData(instr.args[0].value);
                b = registers[instr.args[1].value];
                a *= b;
                memory->writeData(instr.args[0].value,a);

            }else if(instr.args[0].typeOfAccess == REGISTER && instr.args[1].typeOfAccess == MEMORY && instr.args[2].typeOfAccess == NONE){
                a = registers[instr.args[0].value];
                b = memory->readData(instr.args[1].value);
                a *= b;
                registers[instr.args[0].value] = a;

            }else if(instr.args[0].typeOfAccess == REGISTER && instr.args[1].typeOfAccess == DIRECT && instr.args[2].typeOfAccess == NONE){
                a = registers[instr.args[0].value];
                b = instr.args[1].value;
                a *= b;
                registers[instr.args[0].value] = a;

            }else if(instr.args[0].typeOfAccess == REGISTER && instr.args[1].typeOfAccess == REGISTER && instr.args[2].typeOfAccess == DIRECT){
                b = registers[instr.args[1].value];
                c = registers[instr.args[2].value];
                a = b * c;
                registers[instr.args[0].value] = a;

            }else if(instr.args[0].typeOfAccess == REGISTER && instr.args[1].typeOfAccess == MEMORY && instr.args[2].typeOfAccess == DIRECT){
                b = memory->readData(instr.args[1].value);
                c = registers[instr.args[2].value];
                a = b * c;
                registers[instr.args[0].value] = a;

            }
            else
                ErrorOpExecution("MUL");

            break;
        case DIV:
            if(instr.args[0].typeOfAccess == REGISTER && instr.args[1].typeOfAccess == NONE && instr.args[2].typeOfAccess == NONE){
                a = registers[instr.args[0].value];
                c = registers[EAX] % a;
                registers[EAX] /= a; //quotient
                registers[EDX] = c; //remainder
            }else if(instr.args[0].typeOfAccess == MEMORY && instr.args[1].typeOfAccess == NONE && instr.args[2].typeOfAccess == NONE){
                a = memory->readData(instr.args[0].value);
                c = registers[EAX] % a;
                registers[EAX] /= a; //quotient
                registers[EDX] = c; //remainder
            }else
                ErrorOpExecution("DIV");

            break;
        case MOV:
            if(instr.args[0].typeOfAccess == REGISTER && instr.args[1].typeOfAccess == REGISTER && instr.args[2].typeOfAccess == NONE){
                registers[instr.args[0].value] = registers[instr.args[1].value];
            }else if(instr.args[0].typeOfAccess == REGISTER && instr.args[1].typeOfAccess == MEMORY && instr.args[2].typeOfAccess == NONE){
                b = memory->readData(instr.args[1].value);
                registers[instr.args[0].value] = b;
            }else if(instr.args[0].typeOfAccess == MEMORY && instr.args[1].typeOfAccess == REGISTER && instr.args[2].typeOfAccess == NONE){
                memory->writeData(instr.args[0].value,registers[instr.args[1].value]);
            }else if(instr.args[0].typeOfAccess == MEMORY && instr.args[1].typeOfAccess == DIRECT && instr.args[2].typeOfAccess == NONE){
                b = instr.args[1].value;
                memory->writeData(instr.args[0].value,b);
            }else if(instr.args[0].typeOfAccess == REGISTER && instr.args[1].typeOfAccess == DIRECT && instr.args[2].typeOfAccess == NONE){
                b = instr.args[1].value;
                registers[instr.args[0].value] = b;

            }else {
                ErrorOpExecution("MOV");
            }
            break;

        case CMP:
            if(instr.args[0].typeOfAccess == REGISTER && instr.args[1].typeOfAccess == REGISTER && instr.args[2].typeOfAccess == NONE){
                a = registers[instr.args[0].value];
                b = registers[instr.args[1].value];
                compareAndSetFlag(a,b);

            }else if(instr.args[0].typeOfAccess == REGISTER && instr.args[1].typeOfAccess == MEMORY && instr.args[2].typeOfAccess == NONE){
                a = registers[instr.args[0].value];
                b = memory->readData(instr.args[1].value);
                compareAndSetFlag(a,b);
            }else if(instr.args[0].typeOfAccess == MEMORY && instr.args[1].typeOfAccess == REGISTER && instr.args[2].typeOfAccess == NONE){
                a = memory->readData(instr.args[0].value);
                b = registers[instr.args[1].value];
                compareAndSetFlag(a,b);

            }else if(instr.args[0].typeOfAccess == REGISTER && instr.args[1].typeOfAccess == DIRECT && instr.args[2].typeOfAccess == NONE){
                a = registers[instr.args[0].value];
                b = instr.args[1].value;
                compareAndSetFlag(a,b);
            }else
                ErrorOpExecution("CMP");
            break;
        case JMP:
            if(instr.args[0].typeOfAccess == DIRECT && instr.args[1].typeOfAccess == NONE && instr.args[2].typeOfAccess == NONE){
                a = instr.args[0].value;
                programCounter = a;
            }else
                ErrorOpExecution("JMP");
            break;
        case JZ:
            if(instr.args[0].typeOfAccess == DIRECT && instr.args[1].typeOfAccess == NONE && instr.args[2].typeOfAccess == NONE){
                a = instr.args[0].value;
                if(flags[JZ])
                    programCounter = a;
            }
            else
              ErrorOpExecution("JZ");
            break;
        case JL:
            if(instr.args[0].typeOfAccess == DIRECT && instr.args[1].typeOfAccess == NONE && instr.args[2].typeOfAccess == NONE){
                a = instr.args[0].value;
                if(flags[JL])
                    programCounter = a;
            }else
                ErrorOpExecution("JMP");
            break;
        case JG:
            if(instr.args[0].typeOfAccess == DIRECT && instr.args[1].typeOfAccess == NONE && instr.args[2].typeOfAccess == NONE){
                a = instr.args[0].value;
                if(flags[JG])
                    programCounter = a;
            }else
                ErrorOpExecution("JMP");
            break;
        case JE:
            if(instr.args[0].typeOfAccess == DIRECT && instr.args[1].typeOfAccess == NONE && instr.args[2].typeOfAccess == NONE){
                a = instr.args[0].value;
                if(flags[JE])
                    programCounter = a;
            }else
                ErrorOpExecution("JMP");
            break;
        case JGE:
            if(instr.args[0].typeOfAccess == DIRECT && instr.args[1].typeOfAccess == NONE && instr.args[2].typeOfAccess == NONE){
                a = instr.args[0].value;
                if(flags[JGE])
                    programCounter = a;
            }else
                ErrorOpExecution("JMP");
            break;
        case JLE:
            if(instr.args[0].typeOfAccess == DIRECT && instr.args[1].typeOfAccess == NONE && instr.args[2].typeOfAccess == NONE){
                a = instr.args[0].value;
                if(flags[JLE])
                    programCounter = a;
            }else
                ErrorOpExecution("JMP");
            break;
        case JD:
            if(instr.args[0].typeOfAccess == DIRECT && instr.args[1].typeOfAccess == NONE && instr.args[2].typeOfAccess == NONE){
                a = instr.args[0].value;
                if(flags[JD])
                    programCounter = a;
            }else
                ErrorOpExecution("JMP");
            break;
        case PRINT:
            if(instr.args[0].typeOfAccess == DIRECT && instr.args[1].typeOfAccess == NONE && instr.args[2].typeOfAccess == NONE){
                int pos = instr.args[0].textArg.find("\\n");
                if(pos != std::string::npos){
                    std::cout << instr.args[0].textArg.substr(0,pos) << std::endl;
                }else
                    std::cout << instr.args[0].textArg;
            }else
                ErrorOpExecution("PRINT");
            break;
        case PRINTV:
            if(instr.args[0].typeOfAccess == REGISTER && instr.args[1].typeOfAccess == NONE && instr.args[2].typeOfAccess == NONE){
                a = registers[instr.args[0].value];
                std::cout << a << std::endl;
            }else if(instr.args[0].typeOfAccess == MEMORY && instr.args[1].typeOfAccess == NONE && instr.args[2].typeOfAccess == NONE){
                a = memory->readData(instr.args[0].value);
                std::cout << a << std::endl;
            }else if(instr.args[0].typeOfAccess == DIRECT && instr.args[1].typeOfAccess == NONE && instr.args[2].typeOfAccess == NONE){
                a = instr.args[0].value;
                std::cout << a << std::endl;
            }else
                ErrorOpExecution("PRINTV");
            break;
        case RET:
            if(instr.args[0].typeOfAccess == DIRECT && instr.args[1].typeOfAccess == NONE && instr.args[2].typeOfAccess == NONE){
                a = instr.args[0].value;
                returnCode = a;
                toReturn = true;
            }

            break;

    }
    cycles++;

    return toReturn;

}

int CPU::init() {
    bool ret = false;
    memory->LoadInstructions();
    memory->LoadData();

    while((programCounter <= memory->numberOfInstrunctions()) && !ret){

        fetch();
        decode();
        ret =  execute();

    }
    deactivate();
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

void CPU::deactivate() {
    memory->WriteDataFile();

}

int CPU::getCycles() {
    return this->cycles;
}

int CPU::getReturnCode() {
    return returnCode;
}


