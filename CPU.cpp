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

int CPU::fetchOperands(Instruction instr,int argIndex) {
    switch(instr.args[argIndex].typeOfAccess){
        case MEMORY:
            cycles++;
            return memory->readData(instr.args[argIndex].value);
        case DIRECT:
            return instr.args[argIndex].value;
        case REGISTER:
            return registers[instr.args[argIndex].value];
        default:
        ErrorOpExecution(activeOperation);
    }
}

void CPU::writeData(Instruction instr,int argIndex, int value) {

    switch(instr.args[argIndex].typeOfAccess){
        case MEMORY:
            if(argIndex == 0 && instr.args[1].typeOfAccess == MEMORY){
                ErrorOpExecution(activeOperation);
            }
            memory->writeData(instr.args[argIndex].value,value);
            cycles++;
            break;
        case REGISTER:
            registers[instr.args[argIndex].value] = value;
            break;
        default:
        ErrorOpExecution(activeOperation);
    }
}

void CPU::compare(int flag) {
    int a;
    if(instr.args[0].typeOfAccess == DIRECT && instr.args[1].typeOfAccess == NONE && instr.args[2].typeOfAccess == NONE){
        a = fetchOperands(instr,0);
        if(flags[flag])
            programCounter = a;
    }else {
        ErrorOpExecution(activeOperation);
    }
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
    else if(instr.operation == "MOV")
        op = MOV;
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
    else if(instr.operation == "CLS")
        op = CLS;
    else{

        ErrorOpDecode(instr.operation);
    }

    cycles++;

}


bool CPU::execute() {

    int a,b,c;
    bool toReturn = false;
    compFlags flag;
    switch(op){
        case ADD:
            activeOperation = "ADD";
            if(instr.args[2].typeOfAccess == NONE) {
                a = fetchOperands(instr,0);
                b = fetchOperands(instr,1);
                a+=b;

            }
            else {
                ErrorOpExecution(activeOperation);
            }

            writeData(instr,0,a);

            break;
        case SUB:
            activeOperation = "SUB";
            if(instr.args[2].typeOfAccess == NONE){
                a = fetchOperands(instr,0);
                b = fetchOperands(instr,1);
                a-=b;

            }
            else{
                ErrorOpExecution(activeOperation);
            }

            writeData(instr,0,a);
            break;
        case MUL:
            activeOperation = "MUL";
            if(instr.args[2].typeOfAccess == NONE){
                a = fetchOperands(instr,0);
                b = fetchOperands(instr,1);
                a*=b;
            }else if(instr.args[2].typeOfAccess == DIRECT ){
                b = fetchOperands(instr,1);
                c = fetchOperands(instr,2);
                a = b * c;

            }
            else{
                ErrorOpExecution(activeOperation);
            }
            writeData(instr,0,a);
            break;
        case DIV:
            activeOperation = "DIV";
            if(instr.args[1].typeOfAccess == NONE && instr.args[2].typeOfAccess == NONE){
                a = fetchOperands(instr,0);
                c = registers[EAX] % a;
                registers[EAX] /= a; ///quotient
                registers[EDX] = c; ///remainder
            }
            else {
                ErrorOpExecution(activeOperation);
            }

            break;
        case MOV:

            activeOperation = "MOV";
            if(instr.args[2].typeOfAccess == NONE){
                a = fetchOperands(instr,1);
                writeData(instr,0,a);
            } else {
                ErrorOpExecution(activeOperation);
            }
            break;

        case CMP:
            activeOperation = "CMP";
            if(instr.args[2].typeOfAccess == NONE){
                a = fetchOperands(instr,0);
                b = fetchOperands(instr,1);
                compareAndSetFlag(a,b);
            }
            else {
                ErrorOpExecution(activeOperation);
            }
            break;
        case JMP:
            activeOperation = "JMP";
            if(instr.args[0].typeOfAccess == DIRECT && instr.args[1].typeOfAccess == NONE && instr.args[2].typeOfAccess == NONE){
                a = fetchOperands(instr,0);
                programCounter = a;
            }else {
                ErrorOpExecution(activeOperation);
            }
            break;

        case PRINT:
            activeOperation = "PRINT";
            if(instr.args[0].typeOfAccess == DIRECT && instr.args[1].typeOfAccess == NONE && instr.args[2].typeOfAccess == NONE){
                int pos = instr.args[0].textArg.find("\\n");
                if(pos != std::string::npos){
                    std::cout << instr.args[0].textArg.substr(0,pos) << std::endl;
                }else
                    std::cout << instr.args[0].textArg;
            }else {
                ErrorOpExecution(activeOperation);
            }
            break;
        case PRINTV:
            activeOperation = "PRINTV";
            if(instr.args[1].typeOfAccess == NONE && instr.args[2].typeOfAccess == NONE){
                a = fetchOperands(instr,0);
                std::cout << a;
            }
            else {
                ErrorOpExecution(activeOperation);
            }
            break;
        case RET:
            if(instr.args[0].typeOfAccess == DIRECT && instr.args[1].typeOfAccess == NONE && instr.args[2].typeOfAccess == NONE){
                a = fetchOperands(instr,0);
                returnCode = a;
                toReturn = true;
            }
            break;
        case READINT:
            activeOperation = "READINT";
            if(instr.args[0].typeOfAccess == REGISTER && instr.args[1].typeOfAccess == NONE && instr.args[2].typeOfAccess    == NONE){
                std::cin >> a;
                writeData(instr,0,a);
            }
            else{
                ErrorOpExecution(activeOperation);
            }
            break;

        case JZ:
            activeOperation = "JZ";
            flag = ZERO;
            compare(flag);
            break;
        case JL:
            activeOperation = "JL";
            flag = LESSER;
            compare(flag);
            break;
        case JG:
            activeOperation = "JG";
            flag = GREATER;
            compare(flag);
            break;
        case JE:
            activeOperation = "JE";
            flag = EQUAL;
            compare(flag);
            break;
        case JGE:
            activeOperation = "JGE";
            flag = GREATEQUAL;
            compare(flag);
            break;
        case JLE:
            activeOperation = "JLE";
            flag = LESSEQUAL;
            compare(flag);
            break;
        case JD:
            activeOperation = "JD";
            flag = DIFFERNT;
            compare(flag);
            break;
        case CLS:
            activeOperation = "CLS";
            if(instr.args[0].typeOfAccess == NONE && instr.args[1].typeOfAccess == NONE && instr.args[2].typeOfAccess == NONE) {
                int n;
                for (n = 0; n < 10; n++)
                    printf("\n\n\n\n\n\n\n\n\n\n");

            }else{
                ErrorOpExecution(activeOperation);
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


