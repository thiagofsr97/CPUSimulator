#include <iostream>
#include "Memory.h"
#include "CPU.h"

int main(int argc, char *argv[]) {

   if(argc < 3){
       std::cout << "Missing or wrong argument\n";
        exit(1);
   }

    CPU cpu(argv[1],argv[2]);
    cpu.init();
    std::cout << "The program has finished with " << cpu.getCycles() << " cycles of CPU" << std::endl;



    return cpu.getReturnCode();
}
