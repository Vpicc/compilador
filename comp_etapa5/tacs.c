
#include "tacs.h"

TAC *makeBinOp(int type, TAC *code0, TAC *code1);
TAC *makeIfThenElse(TAC *code0, TAC *code1, TAC *code2);
TAC *makeWhile(TAC *code0, TAC *code1, TAC *code2);
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
        fprintf(stderr, "TAC_GREATER");
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
    case TAC_POINT:
        fprintf(stderr, "TAC_POINT");
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

    fprintf(stderr, "*****DEBUG**** AST_TYPE: %d\n", ast->type);
    if (ast->symbol && ast->symbol->type)
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
    case AST_MUL:
        return makeBinOp(TAC_MULT, code[0], code[1]);
    case AST_DIV:
        return makeBinOp(TAC_MULT, code[0], code[1]);
    case AST_POINT:
        return makeBinOp(TAC_POINT, code[0], code[1]);
    case AST_IF:
    case AST_IFELSE:
        return makeIfThenElse(code[0], code[1], code[2]);
    case AST_LESS:
        return makeBinOp(TAC_LESS, code[0], code[1]);
    case AST_GREATER:
        return makeBinOp(TAC_GREATER, code[0], code[1]);
    case AST_LE:
        return makeBinOp(TAC_LE, code[0], code[1]);
    case AST_GE:
        return makeBinOp(TAC_GE, code[0], code[1]);
    case AST_EQ:
        return makeBinOp(TAC_EQ, code[0], code[1]);
    case AST_DIFF:
        return makeBinOp(TAC_DIFF, code[0], code[1]);
    case AST_AND:
        return makeBinOp(TAC_AND, code[0], code[1]);
    case AST_OR:
        return makeBinOp(TAC_OR, code[0], code[1]);
    case AST_TIL:
        return makeBinOp(TAC_NOT, code[0], code[1]);
    case AST_READ:
        return tacCreate(TAC_READ, ast->symbol, 0, 0);
    case AST_RETURN:
        return tacJoin(code[0], tacCreate(TAC_RETURN, code[0] ? code[0]->res : 0, 0, 0));
    case AST_DECL:
        return tacJoin(code[0], code[1]);
    case AST_PRINTLIST:
        return tacJoin(tacCreate(TAC_PRINT, code[0] ? code[0]->res : 0, 0, 0), code[1]);
    case AST_PRINTLIST_REST:
        return tacJoin(tacCreate(TAC_PRINT, code[0] ? code[0]->res : 0, 0, 0), code[1]);
    case AST_VECTORASS:
        return tacJoin(tacJoin(code[0], code[1]), tacCreate(TAC_VECTORASS, ast->symbol, code[0] ? code[0]->res : 0, code[1] ? code[1]->res : 0));
    case AST_VECREAD:
        return tacJoin(code[0], tacCreate(TAC_VEC_READ, makeTemp(), ast->symbol, code[0] ? code[0]->res : 0));
    case AST_WHILE:
        return makeWhile(code[0], code[1], code[2]);
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

void tacPrintAllForward(TAC *tac) //print Forwards
{
    if (tac)
    {
        tacPrintAllForward(tac->prev);
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

TAC *makeIfThenElse(TAC *code0, TAC *code1, TAC *code2)
{
    HASH_NODE *labelIf = 0;
    TAC *tacIf = 0;
    TAC *tacLabelIf = 0;
    HASH_NODE *labelElse = 0;
    TAC *tacElse = 0;
    TAC *tacLabelElse = 0;

    labelIf = makeLabel();
    tacIf = tacJoin(code0, tacCreate(TAC_IFZ, labelIf, code0 ? code0->res : 0, 0));
    tacLabelIf = tacCreate(TAC_LABEL, labelIf, 0, 0);

    if (code2) // tem else
    {
        labelElse = makeLabel();
        tacLabelElse = tacCreate(TAC_LABEL, labelElse, 0, 0);
        tacElse = tacCreate(TAC_JUMP, labelElse, 0, 0);
        return tacJoin(tacJoin(tacJoin(tacJoin(tacJoin(tacIf, code1), tacElse), tacLabelIf), code2), tacLabelElse);
    }
    return tacJoin(tacJoin(tacIf, code1), tacLabelIf);
}

TAC *makeWhile(TAC *code0, TAC *code1, TAC *code2)
{
    HASH_NODE *labelConditionJump = 0;
    HASH_NODE *labelConditionFalse = 0;
    TAC *tacLabelConditionJump = 0;
    TAC *tacLabelConditionFalse = 0;
    TAC *whileConditionIf = 0;
    TAC *whileConditionJump = 0;

    labelConditionJump = makeLabel();
    labelConditionFalse = makeLabel();
    tacLabelConditionJump = tacCreate(TAC_LABEL, labelConditionJump, 0, 0);
    tacLabelConditionFalse = tacCreate(TAC_LABEL, labelConditionFalse, 0, 0);
    whileConditionIf = tacCreate(TAC_IFZ, labelConditionFalse, code0 ? code0->res : 0, 0);
    whileConditionJump = tacCreate(TAC_JUMP, labelConditionJump, code0 ? code0->res : 0, 0);

    return tacJoin(tacJoin(tacJoin(tacJoin(tacJoin(tacLabelConditionJump, code0), whileConditionIf), code1), whileConditionJump), tacLabelConditionFalse);
}