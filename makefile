CC=g++
CFLAGS=-I -std=c++11.
DEPS = Utils.h Memory.h CPU.h 
OBJ = Memory.o CPU.o main.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

CPUSimulator: $(OBJ)
	g++ -o $@ $^ $(CFLAGS)
