CC=g++
CFLAGS=-I -std=c++11.
DEPS = Memory.h 
OBJ = Memory.o main.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

CPUSimulator: $(OBJ)
	g++ -o $@ $^ $(CFLAGS)
