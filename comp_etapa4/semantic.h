#ifndef __SEMANTIC__
#define __SEMANTIC__
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "astree.h"
#include "hash_table.h"

void checkAndSetTypes(AST *node);
void checkUndeclared(void);
#endif