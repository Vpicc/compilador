#ifndef __SEMANTIC__
#define __SEMANTIC__
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "astree.h"
#include "hash_table.h"

void checkAndSetTypes(AST *node);
void setTypes(AST *node);
void checkUndeclared(void);
int getSemanticError();
int getType(AST *node);
void checkOperands(AST *node);
int checkVector(AST *node, int datatype);
int validReturn(AST *nodeDec, AST *node);
#endif