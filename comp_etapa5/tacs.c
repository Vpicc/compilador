
#include "tacs.h"

TAC *makeBinOp(int type, TAC *code0, TAC *code1);
//TAC* makeIfThenElse(TAC* result[]);
//TAC* makeFunc(TAC* symbol, TAC* params, TAC* code);
//TAC* makeLoop(TAC* result[], NODE* loopLabel);
//TAC* makeLeap(TAC* result[], NODE* currentLabel);

TAC *tacCreate(int type, HASH_NODE *res, HASH_NODE *op1, HASH_NODE *op2)
{
    TAC *tac = (TAC *)calloc(1, sizeof(TAC));

    tac->type = type;
    tac->res = res;
    tac->op1 = op1;
    tac->op2 = op2;
    tac->prev = 0;
    tac->next = 0;

    return tac;
}

void tacPrint(TAC *tac)
{
    if (tac == NULL)
        return;

    if (tac->type == TAC_SYMBOL)
        return;
    fprintf(stderr, "TAC(");

    switch (tac->type)
    {
    case TAC_ADD:
        fprintf(stderr, "TAC_ADD");
        break;
    case TAC_SUB:
        fprintf(stderr, "TAC_SUB");
        break;
    case TAC_MULT:
        fprintf(stderr, "TAC_MULT");
        break;
    case TAC_DIV:
        fprintf(stderr, "TAC_DIV");
        break;
    case TAC_IFZ:
        fprintf(stderr, "TAC_IFZ");
        break;
    case TAC_IFELSE:
        fprintf(stderr, "TAC_IFELSE");
        break;
    case TAC_LABEL:
        fprintf(stderr, "TAC_LABEL");
        break;
    case TAC_JUMP:
        fprintf(stderr, "TAC_JUMP");
        break;
    case TAC_LESS:
        fprintf(stderr, "TAC_LESS");
        break;
    case TAC_GREATER:
        fprintf(stderr, "TAC_GREAT");
        break;
    case TAC_LE:
        fprintf(stderr, "TAC_LE");
        break;
    case TAC_GE:
        fprintf(stderr, "TAC_GE");
        break;
    case TAC_EQ:
        fprintf(stderr, "TAC_EQ");
        break;
    case TAC_DIFF:
        fprintf(stderr, "TAC_DIFF");
        break;
    case TAC_AND:
        fprintf(stderr, "TAC_AND");
        break;
    case TAC_OR:
        fprintf(stderr, "TAC_OR");
        break;
    case TAC_NOT:
        fprintf(stderr, "TAC_NOT");
        break;
    case TAC_PRINT:
        fprintf(stderr, "TAC_PRINT");
        break;
    case TAC_MOVE:
        fprintf(stderr, "TAC_MOVE");
        break;
    case TAC_BEGINFUN:
        fprintf(stderr, "TAC_BEGINFUN");
        break;
    case TAC_ENDFUN:
        fprintf(stderr, "TAC_ENDFUN");
        break;
    case TAC_FUNCALL:
        fprintf(stderr, "TAC_FUNCALL");
        break;
    case TAC_ARG:
        fprintf(stderr, "TAC_ARG");
        break;
    case TAC_RETURN:
        fprintf(stderr, "TAC_RETURN");
        break;
    case TAC_READ:
        fprintf(stderr, "TAC_READ");
        break;
    case TAC_ARRAY:
        fprintf(stderr, "TAC_ARRAY");
        break;
    case TAC_VECTORASS:
        fprintf(stderr, "TAC_VECTORASS");
        break;
    case TAC_VEC_INDEX:
        fprintf(stderr, "TAC_VEC_INDEX");
        break;
    case TAC_VEC_READ:
        fprintf(stderr, "TAC_VEC_READ");
        break;
    case TAC_PRINT_LIST:
        fprintf(stderr, "TAC_PRINT_LIST");
        break;
    case TAC_STACK_PUSH:
        fprintf(stderr, "TAC_STACK_PUSH");
        break;
    case TAC_STACK_POP:
        fprintf(stderr, "TAC_STACK_POP");
        break;
    default:
        fprintf(stderr, "UNKNOWN_TAC_TYPE");
        break;
    }

    if (tac->res == 0)
    {
        fprintf(stderr, ", 0_TEXT");
    }
    else
    {
        fprintf(stderr, ", %s", tac->res->text);
    }

    if (tac->op1 == 0)
    {
        fprintf(stderr, ", 0_OP1");
    }
    else
    {
        fprintf(stderr, ", %s", tac->op1->text);
    }

    if (tac->op2 == 0)
    {
        fprintf(stderr, ", 0_OP2");
    }
    else
    {
        fprintf(stderr, ", %s", tac->op2->text);
    }

    fprintf(stderr, ")\n");
}

TAC *generateCode(AST *ast, HASH_NODE *label)
{
    int i;
    TAC *code[MAX_SONS];
    if (!ast)
        return 0;

    // talvez tenhamos que fazer com ast->symbol->type ao inves de ast->type
    fprintf(stderr, "*****DEBUG**** AST_TYPE: %d\n", ast->type);
    fprintf(stderr, "*****DEBUG**** AST_SYMBOL_TYPE: %d\n", ast->symbol->type);
    if (ast->type == AST_WHILE || ast->type == AST_FOR)
    {
        label = makeLabel();
    }
    // começa de baixo para cima
    for (i = 0; i < MAX_SONS; i++)
    {
        code[i] = generateCode(ast->son[i], label);
    }

    switch (ast->type)
    {
    case AST_SYMBOL:
        return tacCreate(TAC_SYMBOL, ast->symbol, 0, 0);
    case AST_ASS:
        return tacJoin(code[0], tacCreate(TAC_MOVE, ast->symbol, code[0] ? code[0]->res : 0, 0));
    case AST_ADD:
        return makeBinOp(TAC_ADD, code[0], code[1]);
    default:
        return tacJoin(tacJoin(tacJoin(code[0], code[1]), code[2]), code[3]);
    }
}

void tacPrintAll(TAC *tac) //print backwards
{
    if (tac)
    {
        for (; tac; tac = tac->prev)
            tacPrint(tac);
    }
}

TAC *tacJoin(TAC *l1, TAC *l2)
{
    TAC *tac;

    if (!l1)
        return l2;
    if (!l2)
        return l1;

    for (tac = l2; tac->prev; tac = tac->prev)
        ;
    tac->prev = l1;

    return l2;
}

TAC *makeBinOp(int type, TAC *code0, TAC *code1)
{
    TAC *list = 0;
    TAC *newTac = 0;
    newTac = tacCreate(type, makeTemp(), code0 ? code0->res : 0, code1 ? code1->res : 0);
    list = tacJoin(code0, code1);
    newTac->prev = list;
    return newTac;
}
