#include <iostream>
#include "Memory.h"
#include "CPU.h"

int main(int argc, char *argv[]) {
//
//    if(argc < 3){
//        std::cout << "Missing or wrong argument\n";
//        exit(1);
//    }

   CPU cpu("Memory.txt","Data.txt");


    return cpu.init();
}