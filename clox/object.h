#ifndef clox_object_h
#define clox_object_h

#include "common.h"
#include "value.h"

// extract the object type tag from given value
#define OBJ_TYPE(value)  (AS_OBJ(value)->type)
#define IS_STRING(value) isObjType(value, OBJ_STRING)
#define AS_STRING(value) ((ObjString*)AS_OBJ(value))
#define AS_CSTRING(value) (((ObjString*)AS_OBJ(value))->chars)

typedef enum {
    OBJ_STRING,
} ObjType;

struct Obj {
    ObjType type;
    struct Obj* next;
};

// strings are immutable
struct ObjString {
    // C struct fields are arranged in memory in the order that they are declared
    Obj obj; 
    int length; // number of bytes
    char* chars; // array of characters
    uint32_t hash; // O(n)
};

ObjString* takeString(char* chars, int length);
ObjString* copyString(const char* chars, int length);
void printObject(Value value);

static inline bool isObjType(Value value, ObjType type) {
    return IS_OBJ(value) && AS_OBJ(value)->type == type;
}

#endif