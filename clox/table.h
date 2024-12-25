#ifndef clox_table_h
#define clox_table_h

#include "common.h"
#include "value.h"

// key-val pair
typedef struct {
    ObjString* key;
    Value value;
} Entry;

// hash table
typedef struct {
    int count; 
    int capacity;
    Entry* entries;
} Table;

void initTable(Table* table);
void freeTable(Table* table);
bool tableGet(Table* table, ObjString* key, Value value);
bool tableSet(Table* table, ObjString* key, Value value);
bool tableDelete(Table* table, ObjString* key);
void tableAddAll(Table* from, Table* to);

#endif