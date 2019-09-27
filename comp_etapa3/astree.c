#include "astree.h"

AST *astCreate(int type, HASH_NODE *symbol, AST *s0, AST *s1, AST *s2, AST *s3, AST *s4)
{
    AST *newnode = 0;
    newnode = (AST *)calloc(1, sizeof(AST));
    newnode->type = type;
    newnode->symbol = symbol;
    newnode->son[0] = s0;
    newnode->son[1] = s1;
    newnode->son[2] = s2;
    newnode->son[3] = s3;
    newnode->son[4] = s4;
    return newnode;
}

void astPrint(AST *node, int level)
{
    int i;
    if (!node)
        return;
    for (i = 0; i < level; ++i)
        fprintf(stderr, "  ");
    fprintf(stderr, "AST(");
    switch (node->type)
    {
    default:
        break;
    }
    if (node->symbol)
    {
        fprintf(stderr, ",VALUE: %s", node->symbol->text);
    }
    fprintf(stderr, "\n");
    for (i = 0; i < MAX_SONS; ++i)
        astPrint(node->son[i], level + 1);
}