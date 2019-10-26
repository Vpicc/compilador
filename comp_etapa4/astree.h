#ifndef ASTREE_H
#define ASTREE_H
#include <stdio.h>
#include <string.h>
#include "hash_table.h"
#define MAX_SONS 4

#define AST_SYMBOL 1

#define AST_ADD 2
#define AST_MUL 3
#define AST_SUB 4
#define AST_DIV 5

#define AST_DECL 6
#define AST_ASS 7

#define AST_VECREAD 8

#define AST_LCMD 9
#define AST_VARDEC 10
#define AST_FUNDEC 11

#define AST_TYPEINT 12
#define AST_TYPEFLOAT 13
#define AST_TYPEBOOL 14
#define AST_TYPEBYTE 15
#define AST_TYPELONG 16
//#define AST_LDEC 17

#define AST_IF 17
#define AST_IFELSE 18
#define AST_WHILE 19
#define AST_FOR 20

#define AST_LESS 21
#define AST_GREATER 22
#define AST_LE 23
#define AST_GE 24
#define AST_NE 25
#define AST_EQ 26
#define AST_DIFF 27
#define AST_POINT 28 //Não achei pra serve isso
#define AST_OR 29
#define AST_AND 99

#define AST_BLOCK 30
#define AST_PRINT 31
#define AST_RETURN 32
#define AST_ARRDECL 33
#define AST_FUNCALL 34
#define AST_READ 35
#define AST_VECTORASS 36
#define AST_PAR 37
#define AST_PARLIST 38
#define AST_FUNLIST 39
#define AST_FUNLIST_REST 40
#define AST_PROG 41
#define AST_VECLIST 42
#define AST_VECREST 43
#define AST_PRINTLIST 44
#define AST_PRINTLIST_REST 45
#define AST_PROG_VARDECL 46
#define AST_PROG_FUNCDECL 47
#define AST_VECSIZE 48
#define AST_PARENTHESIS 49
#define AST_PARLIST_REST 50
#define AST_CMDEND 51
#define AST_TIL 52 //Não achei pra serve isso
#define AST_BREAK 53

#define AST_DATATYPE_INT 54
#define AST_DATATYPE_BYTE 55
#define AST_DATATYPE_BOOL 56
#define AST_DATATYPE_STRING 57
#define AST_DATATYPE_VET 58
#define AST_DATATYPE_FUN 59
#define AST_DATATYPE_ERROR 60
#define AST_DATATYPE_FLOAT 61
#define AST_DATATYPE_LONG 62

FILE *out;

typedef struct astree_node
{
    int type;
    int datatype;
    int lineNumber;
    HASH_NODE *symbol;
    struct astree_node *son[MAX_SONS];
} AST;

AST *astCreate(int type, HASH_NODE *symbol, AST *s0, AST *s1, AST *s2, AST *s3, int lineNumber);

void astPrint(AST *s0, int level);

void astDecompile(AST *s0);
#endif