#ifndef clox_vm_h
#define clox_vm_h

#include "chunk.h"
#include "value.h"
#include "compiler.h"
#include "table.h"

#define STACK_MAX 256
typedef struct {
    Chunk* chunk;
    uint8_t* ip; // instruction pointer
    Value stack[STACK_MAX]; // bytecode stack
    Value* stackTop; // points to where the next value to be pushed will go
    Table globals; // global variables
    Table strings; // string table for string interning
    Obj* objects; // point to head of list for garbage collection
} VM;

typedef enum {
    INTERPRET_OK,
    INTERPRET_COMPILE_ERROR,
    INTERPRET_RUNTIME_ERROR
} InterpretResult;

extern VM vm;

void initVM();
void freeVM();
InterpretResult interpret(const char* source);
void push(Value value);
Value pop();

#endif
