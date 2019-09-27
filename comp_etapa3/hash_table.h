#ifndef HASH_H
#define HASH_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct hash_node
{
    int type;
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
#endif
