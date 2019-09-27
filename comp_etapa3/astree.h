#ifndef ASTREE_H
#define ASTREE_H
#include <stdio.h>
#include <string.h>
#include "hash_table.h"
#define MAX_SONS 5

#define AST_SYMBOL 1
#define AST_ADD 2
#define AST_MUL 3
#define AST_SUB 4
#define AST_DIV 5
#define AST_VECREAD 6
#define AST_ASS 7
#define AST_LCMD 8
#define AST_VARDEC 9
#define AST_FUNDEC 10
#define AST_TYPEINT 11
#define AST_TYPEFLOAT 12
#define AST_TYPEBOOL 13
#define AST_TYPECHAR 14
#define AST_TYPESTRING 15
#define AST_LDEC 16

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