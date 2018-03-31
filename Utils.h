//
// Created by thiagofsr on 31/03/18.
//

#ifndef CPUSIMULATOR_UTILS_H
#define CPUSIMULATOR_UTILS_H
#define CompilationError() std::cout << "Compilation error, please fix your code.\n"; exit(1);
#define ErrorOpFile(file) std::cout << "Error opening " << file << " file.\n"; exit(1);
#define ErrorOpDecode(operation) std::cout << "The operation " << operation << " is not present in set of instructions from this cpu\n"; exit(1);
#define ErrorOpExecution(operation) std::cout << "Error in executing the operation "<< operation << ", please check your code\n"; exit(1);
enum compFlags {ZERO = 0,GREATER = 1, GREATEQUAL = 2,LESSER =3,LESSEQUAL = 4, EQUAL = 5,DIFFERNT = 6};
typedef enum {ADD,SUB,MUL,DIV,LOAD,STORE,COPY,COMP,JUMP,JZ,JL,JG,JE,JGE,JLE,JD,PRINT,RET,READINT} Operation;
enum access {MEMORY, REGISTER,DIRECT,NONE};
enum registers_bits32{ EAX = 0, EBX = 1,ECX = 2, EDX = 3, ESI = 4, EDI = 5};
#endif //CPUSIMULATOR_UTILS_H