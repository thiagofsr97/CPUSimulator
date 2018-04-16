# CPUSimulator

Computer Architecture II Discipline activity. Implementation of a CPU Simulator.
The program simulates the execution of a a Assembly Program ( Designed Assembly, not the usual) by simulating the steps of execution of a CPU, according to small
operations like Fetch, Decode and Execute. The program also gives information like the number of cycles of CPU used in the execution.

# How to use it!
- The compilation of the file is as simple as it follows:
Go straight to the root of the project using the terminal and type the following: <br />
'<b>cmake CMakeLists.txt && make</b>' . (with no quotation marks) 

- Make sure you have cmake pre-installed (Version 3.8 or above). <a href="https://cmake.org/download/">Cmake Download Webpage</a>.
- In order to run the program properly, you must execute it with two support files. The first one is refered to your Assembly Code, whereas the second one
is referred to a file representing numbers in Memory. The execution from the terminal needs the following structure:
   
   ./CPUSimulator [Assembly Code Path] [Memory Representation Path] <br />
- <b>Check on the examples presented in the project in order to have a clear idea of how to design your own Assembly Program.</b>

# Supported Assembly Operations

  - ADD --> Adds two numbers (2 operands needed)
  - SUB --> Subtracts two numbers (2 operands needed)
  - MUL --> Multiplies two numbers (2 or 3 operands needed)
  - DIV --> Divided a number presented in the EAX register and divides by the operand. (1 operand needed)
  - MOV --> Moves a number from the second operand to the first. (2 operandes needed)
  - CMP --> Compares two numbers, setting the flags in CPU (2 operands needed)
  - JMP --> Changes the program counter to the given input (1 operand needed)
  - JZ --> Changes the program counter to the given input if the ZERO flag is set. (1 operand needed)
  - JL --> Changes the program counter to the given input if the LESSER flag is set. (1 operand needed)
  - JG --> Changes the program counter to the given input if the GREATER flag is set. (1 operand needed)
  - JE --> Changes the program counter to the given input if the EQUAL flag is set. (1 operand needed)
  - JGE --> Changes the program counter to the given input if the GREATER or EQUAL flags is set. (1 operand needed)
  - JLE --> Changes the program counter to the given input if the LESSER or EQUAL flag is set. (1 operand needed)
  - JD --> Changes the program counter to the given input if the DIFFERENT flags is set. (1 operand needed)
  - PRINT --> Prints a text from the input to the console. (1 operand needed)
  - RET --> Return call to the system with a number, indicating end of program. (1 operand needed) 
  - READINT --> Reads a integer numbers from the console, storing the result in the operand. (1 operand needed).
  - PRINTV --> Prints a number to console, according to the given operand. (1 operand needed).
  - CLS --> Clears the console. (no operands needed). <br />
  
# Guide to Assembly  
Most of the operation were designed based on the instructions of the Assembly x86. You can check on the operands of each fuction and how to
usem them in the <a href="http://www.cs.virginia.edu/~evans/cs216/guides/x86.html">Guide to x86 Assembly - Computer Science - University of Virginia</a>.
