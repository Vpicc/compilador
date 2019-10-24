#ifndef HASH_H
#define HASH_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SYMBOL_TK_IDENTIFIER 901
#define SYMBOL_LIT_INT 902
#define SYMBOL_LIT_FLOAT 903
#define SYMBOL_LIT_BOOL 904
#define SYMBOL_LIT_CHAR 905
#define SYMBOL_LIT_STRING 906

#define SYMBOL_SCALAR 907
#define SYMBOL_VECTOR 908
#define SYMBOL_FUNCTION 909

#define DATATYPE_INT 801
#define DATATYPE_FLOAT 802
#define DATATYPE_BOOL 803
#define DATATYPE_BYTE 804
#define DATATYPE_LONG 805

typedef struct hash_node
{
    int type;
    int datatype;
    char *text;
    struct hash_node *next;
} HASH_NODE;

#define HASH_SIZE 997

HASH_NODE *Table[HASH_SIZE]; //declaration

void hashInit(void);
int hashAddres(char *text);
HASH_NODE *hashFind(char *text);
HASH_NODE *hashInsert(char *text, int type);
void hashPrint(void);
void hashCheckUndeclared(void);
#endif
