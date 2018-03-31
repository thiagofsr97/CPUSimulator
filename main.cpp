#include <iostream>
#include "Memory.h"

int main(int argc, char *argv[]) {

    if(argc < 3){
        std::cout << "Missing or wrong argument\n";
        exit(1);
    }

    Memory memory(argv[1],argv[2]);
    memory.LoadData();
    memory.LoadInstructions();
    Instruction instr;

    for(int i = 0; i<memory.numberOfInstrunctions();i++){
        memory.readInstruction(i,instr);
        std::cout << "Instruction " << i + 1 << ":\n";
        std::cout << "Operation: " << instr.operation;
        std::cout <<  " First Arg: " << instr.argument1.index;
        std::cout << "(";
        std::string type;
        switch(instr.argument1.typeOfAccess){
            case REGISTER:
                type = "Registro";
                break;
            case DIRECT:
                type = "Direto";
                break;
            case MEMORY:
                type = "Memory";
                break;
            case NONE:
                type = "None";
                break;
        }
        std::cout << type << ") ";

        std::cout <<  " Second Arg: " << instr.argument2.index;
        std::cout << "(";
        switch(instr.argument2.typeOfAccess){
            case REGISTER:
                type = "Registro";
                break;
            case DIRECT:
                type = "Direto";
                break;
            case MEMORY:
                type = "Memory";
                break;
            case NONE:
                type = "None";
                break;
        }
        std::cout << type << ") \n";


    }

    return 0;
}