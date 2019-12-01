#ifndef __TACS__
#define __TACS__
#include <stdio.h>
#include <stdlib.h>
#include "hash_table.h"
#include "astree.h"

#define TAC_SYMBOL 501
#define TAC_ADD 502  //Done
#define TAC_SUB 503  //Done
#define TAC_MULT 504  //Done
#define TAC_DIV 505   //TODO: FIX
#define TAC_IFZ 506   //DONE
#define TAC_IFELSE 507  //DONE
#define TAC_LABEL 508  //DONE
#define TAC_JUMP 509  //DONE
#define TAC_LESS 510  //DONE
#define TAC_GREATER 511  //DONE
#define TAC_LE 512  //DONE
#define TAC_GE 513  //DONE
#define TAC_EQ 514  //DONE
#define TAC_DIFF 515 //DONE
#define TAC_AND 516 
#define TAC_OR 517
#define TAC_NOT 518
#define TAC_PRINT 519   //DONE
#define TAC_MOVE 520   //DONE
#define TAC_BEGINFUN 521   //DONE
#define TAC_ENDFUN 522   //DONE
#define TAC_FUNCALL 523
#define TAC_ARG 524
#define TAC_RETURN 525   //DONE
#define TAC_READ 526
#define TAC_ARRAY 527
#define TAC_VECTORASS 528 //DONE
#define TAC_VEC_INDEX 529
#define TAC_VEC_READ 530  //DONE
#define TAC_PRINT_LIST 531
#define TAC_STACK_PUSH 532
#define TAC_STACK_POP 533
#define TAC_POINT 534
#define TAC_VARDEC 535 //DONE
#define TAC_BREAK 536
#define TAC_FOR 537
#define TAC_ARRDEC 538 //DONE
#define TAC_ARRDEC_LIST 539 //DONE

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
TAC* tacReverse(TAC *last);

TAC *generateCode(AST *ast, HASH_NODE *label);
#endif