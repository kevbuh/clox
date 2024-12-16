#ifndef clox_chunk_h
#define clox_chunk_h

#include "common.h"
#include "value.h"
 
typedef enum {
    OP_CONSTANT, // 00: 2 bytes, [opcode, constant index]
    OP_RETURN,   // 01: 1 byte opcode
} OpCode;

typedef struct {
    int count;
    int capacity;
    uint8_t* code; // array of bytes
    ValueArray constants;
} Chunk; // Bytecode is a series of instructions

void initChunk(Chunk* chunk);
void freeChunk(Chunk* chunk);
void writeChunk(Chunk* chunk, uint8_t byte);
int addConstant(Chunk* chunk, Value value);

#endif