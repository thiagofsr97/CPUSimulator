//
// Created by thiagofsr on 24/05/18.
//

#ifndef CPUSIMULATOR_CACHE_H
#define CPUSIMULATOR_CACHE_H


#include "CacheData.h"
#include "Utils.h"

class Cache {
private:
    typedef std::pair<data_type,int> type_index;
    int size;
    int current_size;
    std::vector<CacheData*>cache;
    type_index *associative_memory;
    int number_of_hits;
    int number_of_misses;
    int fifo;
    Memory *memory;
public:
    Cache(int size, Memory *memory);
    ~Cache();
    void read(Instruction *instruction,int *value, int index);
    int setAssociative(int index,data_type dataType);
    int get_number_of_hits();
    int get_number_of_misses();
};


#endif //CPUSIMULATOR_CACHE_H
