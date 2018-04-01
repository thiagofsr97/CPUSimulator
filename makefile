CC=g++
CFLAGS=-I -std=c++11.
DEPS = Memory.h CPU.h Utils.h
OBJ = Memory.o CPU.o main.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

CPUSimulator: $(OBJ)
	g++ -o $@ $^ $(CFLAGS)
