#ifndef __TACS__
#define __TACS__
#include <stdio.h>
#include <stdlib.h>
#include "hash_table.h"
#include "astree.h"

#define TAC_SYMBOL 501
#define TAC_ADD 502
#define TAC_SUB 503
#define TAC_MULT 504
#define TAC_DIV 505
#define TAC_IFZ 506
#define TAC_IFELSE 507
#define TAC_LABEL 508
#define TAC_JUMP 509
#define TAC_LESS 510
#define TAC_GREATER 511
#define TAC_LE 512
#define TAC_GE 513
#define TAC_EQ 514
#define TAC_DIFF 515
#define TAC_AND 516
#define TAC_OR 517
#define TAC_NOT 518
#define TAC_PRINT 519
#define TAC_MOVE 520
#define TAC_BEGINFUN 521
#define TAC_ENDFUN 522
#define TAC_FUNCALL 523
#define TAC_ARG 524
#define TAC_RETURN 525
#define TAC_READ 526
#define TAC_ARRAY 527
#define TAC_VECTORASS 528
#define TAC_VEC_INDEX 529
#define TAC_VEC_READ 530
#define TAC_PRINT_LIST 531
#define TAC_STACK_PUSH 532
#define TAC_STACK_POP 533
#define TAC_POINT 534
#define TAC_VARDEC 535
#define TAC_BREAK 536
#define TAC_FOR 537
#define TAC_ARRDEC 538
#define TAC_ARRDEC_LIST 539

typedef struct tac_node
{
    int type;
    HASH_NODE *res;
    HASH_NODE *op1;
    HASH_NODE *op2;
    struct tac_node *prev;
    struct tac_node *next;
} TAC;

TAC *tacCreate(int type, HASH_NODE *res, HASH_NODE *op1, HASH_NODE *op2);
void tacPrint(TAC *tac);
void tacPrintAll(TAC *tac);
void tacPrintAllForward(TAC *tac);
TAC *tacJoin(TAC *l1, TAC *l2);

TAC *generateCode(AST *ast, HASH_NODE *label);
#endif