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
void checkOperands(AST *node);
int checkVector(AST *node, int datatype);
int validReturn(AST *nodeDec, AST *node);
int checkPrint(AST *node);
int functionValidation(AST *nodeDeclared, AST *node);
void checkTypeParam(AST *nodecall);
int numParamsFunc(AST *node);
int checkParams(AST *node);
int addExpressionTypes(int type1, int type2);
int getType(AST *node);
AST *search(AST *node, char *name);
int validExpression(AST *nodeSon);
#endif