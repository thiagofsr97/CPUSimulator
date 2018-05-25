//
// Created by thiagofsr on 24/05/18.
//

#include "Cache.h"


Cache::Cache(int size, Memory *memory) {
    this->size = size;
    this->current_size = 0;
    this->associative_memory = new type_index[size];
    for(int i = 0; i < size;++i){
        this->associative_memory[i] = type_index(NO_DATA,0);
    }
    this->memory = memory;
    this->number_of_hits = 0;
    this->number_of_misses = 0;
    this->fifo = 0;
}

Cache::~Cache() {
    delete []this->associative_memory;
    for(auto c:cache)
        delete c;
    cache.clear();

}


void Cache::read(Instruction *instruction, int *value, int index) {
    data_type dataType;
    int pos;
    if(instruction != nullptr && value == nullptr)
        dataType = INSTR_DATA;
    else
        dataType = VALUE_DATA;

    bool found = false;
    //searching for data/instr in cache
    for(int i = 0; i < current_size;++i){
        if(associative_memory[i].second == index && associative_memory[i].first == dataType){
            found = true;
            number_of_hits++;
            if(dataType == INSTR_DATA){
                *instruction = cache[i]->readInstruction();
            }
            else{
                *value = cache[i]->readValue();
            }
            break;

        }
    }
    if(!found){
        number_of_misses++;
        pos = setAssociative(index,dataType);
        if(dataType == INSTR_DATA)
            *instruction = cache[pos]->readInstruction();
        else
            *value = cache[pos]->readValue();
    }

}

int Cache::setAssociative(int index, data_type dataType) {
    CacheData *cacheData;
    if(dataType == INSTR_DATA){
        Instruction instruction;
        memory->readInstruction(index,instruction);
        cacheData = new CacheData(instruction);
    }else{
        cacheData = new CacheData(memory->readData(index));
    }

    if(current_size == 0){
        this->associative_memory[0] = type_index(dataType,index);
        this->cache.push_back(cacheData);
        current_size++;
        return 0;
    }else if(current_size < size){
        this->associative_memory[current_size] = type_index(dataType,index);
        this->cache.push_back(cacheData);
        current_size++;
        return current_size-1;
    }else{
        // at this point the replacement politic must be put in work: FIFO
        this->associative_memory[fifo] = type_index(dataType,index);
        this->cache[fifo] = cacheData;
        this->fifo = (++fifo)%size;
        if(fifo == 0)
            return size-1;
        else
            return fifo-1;
    }


}

int Cache::get_number_of_hits() {
    return this->number_of_hits;
}

int Cache::get_number_of_misses() {
    return this->number_of_misses;
}


