#ifndef ASTREE
#define ASTREE
#include <stdio.h>
#include <string.h>
#include "hash_table.h"
#define MAX_SONS 5

typedef struct astree_node
{
    int type;
    HASH_NODE *symbol;
    struct astree_node *son[MAX_SONS];
} AST;

AST *astCreate(int type, HASH_NODE *symbol, AST *s0, AST *s1, AST *s2, AST *s3, AST *s4);

void astPrint(AST *s0, int level);

void astDecompile(AST *s0);
#endif