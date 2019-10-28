#include <stdio.h>
#include <stdlib.h>
#include "semantic.h"
int semanticError = 0;

int getSemanticError()
{
    return semanticError;
}

void checkAndSetTypes(AST *node)
{
    int i;
    if (!node)
    {
        return;
    }

    if (node->type == AST_DECL || node->type == AST_FUNDEC || node->type == AST_ARRDECL)
    {
        if (node->symbol)
        {
            if (node->symbol->type != SYMBOL_TK_IDENTIFIER)
            {
                fprintf(stderr, "LINE %d - SemanticError: Symbol %s already declared\n", node->lineNumber, node->symbol->text);
                semanticError++;
            }
            if (node->type == AST_DECL)
                node->symbol->type = SYMBOL_SCALAR;
            if (node->type == AST_FUNDEC)
                node->symbol->type = SYMBOL_FUNCTION;
            if (node->type == AST_ARRDECL)
                node->symbol->type = SYMBOL_VECTOR;
            setTypes(node);
        }
    }
    for (i = 0; i < MAX_SONS; ++i)
    {
        checkAndSetTypes(node->son[i]);
    }
}

//We have five types, they are INT, BOOL, FLOAT, LONG and BYTE
void setTypes(AST *node)
{
    if (node && node->son[0] != NULL)
    {
        if (node->son[0]->type == AST_TYPEINT)
        {
            node->son[0]->datatype = AST_DATATYPE_INT;
            node->symbol->datatype = DATATYPE_INT;
            node->datatype = AST_DATATYPE_INT;
        }
        else if (node->son[0]->type == AST_TYPEFLOAT)
        {
            node->son[0]->datatype = AST_DATATYPE_FLOAT;
            node->symbol->datatype = DATATYPE_FLOAT;
            node->datatype = AST_DATATYPE_FLOAT;
        }
        else if (node->son[0]->type == AST_TYPEBYTE)
        {
            node->son[0]->datatype = AST_DATATYPE_BYTE;
            node->symbol->datatype = DATATYPE_BYTE;
            node->datatype = AST_DATATYPE_BYTE;
        }
        else if (node->son[0]->type == AST_TYPELONG)
        {
            node->son[0]->datatype = AST_DATATYPE_LONG;
            node->symbol->datatype = DATATYPE_LONG;
            node->datatype = AST_DATATYPE_LONG;
        }
        else if (node->son[0]->type == AST_TYPEBOOL)
        {
            node->son[0]->datatype = AST_DATATYPE_BOOL;
            node->symbol->datatype = DATATYPE_BOOL;
            node->datatype = AST_DATATYPE_BOOL;
        }
    }
    return;
};

void checkUndeclared(void)
{
    semanticError += hashCheckUndeclared();
};

int getType(AST *node)
{
    int op1, op2;

    switch (node->type)
    {
    case AST_SYMBOL:
    case AST_VECREAD:
    case AST_FUNCALL:
        node->datatype = node->symbol->datatype;
        break;
    case AST_PARENTHESIS:
        node->datatype = getType(node->son[0]);
        break;
    case AST_ADD:
    case AST_SUB:
    case AST_DIV:
    case AST_MUL:
        op1 = getType(node->son[0]);
        op2 = getType(node->son[1]);
        node->datatype = expressionTypes(op1, op2);
        break;
    case AST_LE:
    case AST_GE:
    case AST_EQ:
    case AST_NE:
    case AST_OR:
    case AST_GREATER:
    case AST_LESS:
    case AST_POINT: //TODO: Não sei se isso deve ficar aqui...
        node->datatype = DATATYPE_BOOL;
        break;
    }

    return node->datatype;
}

int expressionTypes(int op1, int op2)
{
    switch (op1)
    {
    case DATATYPE_BOOL:
        switch (op2)
        {
        case DATATYPE_BOOL:
            return DATATYPE_BOOL;

        default:
            return DATATYPE_ERROR;
        }

    case DATATYPE_BYTE:
        switch (op2)
        {
        case DATATYPE_BYTE:
        case DATATYPE_INT:
        case DATATYPE_CHAR:
            return DATATYPE_INT;

        case DATATYPE_FLOAT:
            return DATATYPE_FLOAT;

        default:
            return DATATYPE_ERROR;
        }

    case DATATYPE_INT:
        switch (op2)
        {
        case DATATYPE_BYTE:
        case DATATYPE_INT:
        case DATATYPE_CHAR:
            return DATATYPE_INT;

        case DATATYPE_FLOAT:
            return DATATYPE_FLOAT;
        case DATATYPE_LONG:
            return DATATYPE_LONG;

        default:
            return DATATYPE_ERROR;
        }

    case DATATYPE_CHAR:
        switch (op2)
        {
        case DATATYPE_BYTE:
        case DATATYPE_INT:
            return DATATYPE_INT;

        case DATATYPE_LONG:
            return DATATYPE_LONG;

        case DATATYPE_CHAR:
            return DATATYPE_CHAR;

        case DATATYPE_FLOAT:
            return DATATYPE_FLOAT;

        default:
            return DATATYPE_ERROR;
        }

    case DATATYPE_FLOAT:
        switch (op2)
        {
        case DATATYPE_BOOL:
            return DATATYPE_ERROR;

        case DATATYPE_ERROR:
            return DATATYPE_ERROR;

        case DATATYPE_LONG:
            return DATATYPE_LONG;

        default:
            return DATATYPE_FLOAT;
        }
    case DATATYPE_LONG:
        switch (op2)
        {
        case DATATYPE_BOOL:
            return DATATYPE_ERROR;

        case DATATYPE_ERROR:
            return DATATYPE_ERROR;

        default:
            return DATATYPE_LONG;
        }

    default:
        return DATATYPE_ERROR;
    }
}

int numParamsFunc(AST *node)
{
    if (node == 0)
        return 0;
    else
        return 1 + numParamsFunc(node->son[1]);

    return 0;
};

int checkParams(AST *node)
{
    int countParams = 0;

    int params = node->symbol->numparameters;

    countParams = numParamsFunc(node->son[0]);

    if (countParams != params)
    {
        return 0;
    }

    return 1;
}

void checkOperands(AST *node)
{
    int i;
    if (!node)
        return;

    switch (node->type)
    {

    case AST_SYMBOL:
        switch (node->symbol->type)
        {
        case SYMBOL_SCALAR:
            if (node->symbol->datatype == DATATYPE_INT)
            {
                node->datatype = AST_DATATYPE_INT;
            }
            else if (node->symbol->datatype == DATATYPE_BYTE)
            {
                node->datatype = AST_DATATYPE_BYTE;
            }
            else if (node->symbol->datatype == DATATYPE_FLOAT)
            {
                node->datatype = AST_DATATYPE_FLOAT;
            }
            else if (node->symbol->datatype == DATATYPE_LONG)
            {
                node->datatype = AST_DATATYPE_LONG;
            }
            else if (node->symbol->datatype == DATATYPE_BOOL)
            {
                node->datatype = AST_DATATYPE_BOOL;
            }
            break;

        case SYMBOL_VECTOR:
            node->datatype = AST_DATATYPE_VET;
            break;
        case SYMBOL_FUNCTION:
            node->datatype = AST_DATATYPE_FUN;
        //Literals
        case SYMBOL_LIT_INT:
            node->datatype = AST_DATATYPE_INT;
            break;
        case SYMBOL_LIT_FLOAT:
            node->datatype = AST_DATATYPE_FLOAT;
            break;
        case SYMBOL_LIT_CHAR:
            node->datatype = AST_DATATYPE_BYTE;
            break;
        case SYMBOL_LIT_STRING:
            node->datatype = AST_DATATYPE_STRING;
            break;
        case SYMBOL_LIT_BOOL:
            node->datatype = AST_DATATYPE_BOOL;
            break;

        default:
            break;
        }
        break;

    case AST_DECL:
        if (node->son[1]->symbol != NULL)
        {
            if ((node->symbol->datatype == DATATYPE_INT || node->symbol->datatype == DATATYPE_BYTE) &&
                (node->son[1]->symbol->datatype != DATATYPE_INT && node->son[1]->symbol->datatype != DATATYPE_BYTE))
            {
                fprintf(stderr, "SEMANTIC ERROR in line %d. | Variable %s must recieve int or byte.\n", node->lineNumber, node->symbol->text);
                semanticError++;
            }
            else if (node->symbol->datatype == DATATYPE_FLOAT && node->son[1]->symbol->datatype != DATATYPE_FLOAT)
            {
                fprintf(stderr, "SEMANTIC ERROR in line %d. | Variable %s must recieve float.\n", node->lineNumber, node->symbol->text);
                semanticError++;
            }
            else if (node->symbol->datatype == DATATYPE_BOOL && node->son[1]->symbol->datatype != DATATYPE_BOOL)
            {
                fprintf(stderr, "SEMANTIC ERROR in line %d. | Variable %s must recieve bool.\n", node->lineNumber, node->symbol->text);
                //fprintf(stderr,"DATATYPE RECEIVED %d.\n", node->son[1]->symbol->datatype);

                semanticError++;
            }
            else if (node->symbol->datatype == DATATYPE_LONG && (node->son[1]->symbol->datatype != DATATYPE_LONG && node->son[1]->symbol->datatype != DATATYPE_FLOAT && node->son[1]->symbol->datatype != DATATYPE_INT))
            {
                fprintf(stderr, "SEMANTIC ERROR in line %d. | Variable %s must recieve long.\n", node->lineNumber, node->symbol->text);
                semanticError++;
            }
        }
        break;

    case AST_ARRDECL:
        if (checkVector(node->son[2], node->symbol->datatype) == 0)
        {
            fprintf(stderr, "SEMANTIC ERROR in line %d. Invalid types in vector declaration\n", node->lineNumber);
            semanticError++;
        }
        break;

    case AST_FUNDEC:
        if (validReturn(node, node) == 0)
        {
            fprintf(stderr, "SEMANTIC ERROR in line %d. Invalid return type in function %s.\n", node->lineNumber, node->symbol->text);
            semanticError++;
        }

        break;
    case AST_VECREAD:
        if (node->symbol->datatype == DATATYPE_INT)
        {
            node->datatype = AST_DATATYPE_INT;
        }
        else if (node->symbol->datatype == DATATYPE_BYTE)
        {
            node->datatype = AST_DATATYPE_BYTE;
        }
        else if (node->symbol->datatype == DATATYPE_FLOAT)
        {
            node->datatype = AST_DATATYPE_FLOAT;
        }

        if (node->symbol->type != SYMBOL_VECTOR)
        {
            fprintf(stderr, "SEMANTIC ERROR in line %d. Identifier %s is not a vector.\n", node->lineNumber, node->symbol->text);
            semanticError++;
        }

        //fprintf(stderr, "INDEX TYPE: %d \n", node->son[0]->symbol->datatype);
        if (node->son[0] && node->son[0]->symbol && node->son[0]->symbol->datatype)
            if (node->son[0]->symbol->datatype != DATATYPE_INT && node->son[0]->symbol->datatype != DATATYPE_BYTE && node->son[0]->symbol->datatype != DATATYPE_LONG)
            {
                // Poderia ser qualquer tipo desde que seja numero
                fprintf(stderr, "SEMANTIC ERROR in line %d. Invalid index type in array, must be byte or int.\n", node->lineNumber);
                semanticError++;
            }
        break;
    case AST_VECTORASS:
        if (node->symbol->type != SYMBOL_VECTOR)
        {
            fprintf(stderr, "SEMANTIC ERROR in line %d. Identifier %s is not a vector.\n", node->lineNumber, node->symbol->text);
            semanticError++;
        }
        if (node->son[0] && node->son[0]->symbol && node->son[0]->symbol->datatype)
            if (node->son[0]->symbol->datatype != DATATYPE_INT && node->son[0]->symbol->datatype != DATATYPE_BYTE && node->son[0]->symbol->datatype != DATATYPE_LONG)
            {
                // Poderia ser qualquer tipo desde que seja numero
                fprintf(stderr, "SEMANTIC ERROR in line %d. Invalid index type in assignment, must be byte or int.\n", node->lineNumber);
                semanticError++;
            }

        if (node->symbol->datatype == DATATYPE_INT || node->symbol->datatype == DATATYPE_BYTE)
        {
            if (node->son[1] != NULL)
            {
                if (node->son[1] && node->son[1]->symbol && node->son[1]->symbol->datatype)
                    if (node->son[1]->symbol->datatype != DATATYPE_INT && node->son[1]->symbol->datatype != DATATYPE_BYTE)
                    {
                        fprintf(stderr, "SEMANTIC ERROR in line %d. Identifier %s must be assigned to byte or int.\n", node->lineNumber, node->symbol->text);
                        semanticError++;
                    }
            }
        }
        else if (node->symbol->datatype == DATATYPE_FLOAT)
        {
            if (node->son[1] != NULL)
            {
                if (node->son[1]->symbol->datatype != DATATYPE_FLOAT)
                {
                    fprintf(stderr, "SEMANTIC ERROR in line %d. Identifier %s must be assigned to float.\n", node->lineNumber, node->symbol->text);
                    semanticError++;
                }
            }
        }
        break;
    case AST_ASS:
        if (node && node->symbol && node->symbol->datatype && node->symbol->type)
        {
            if (node->symbol->type != SYMBOL_SCALAR)
            {
                fprintf(stderr, "SEMANTIC ERROR in line %d. Symbol %s must be scalar.\n", node->lineNumber, node->symbol->text);
                semanticError++;
            }
            if (node->symbol->datatype == DATATYPE_INT || node->symbol->datatype == DATATYPE_BYTE || node->symbol->datatype == DATATYPE_FLOAT || node->symbol->datatype == DATATYPE_LONG)
            {
                if (node->son[0] != NULL)
                {
                    if (node->son[0]->symbol && node->son[0]->symbol->datatype)
                        if (node->son[0]->symbol->datatype != DATATYPE_INT && node->son[0]->symbol->datatype != DATATYPE_BYTE && node->son[0]->symbol->datatype != DATATYPE_FLOAT && node->son[0]->symbol->datatype != DATATYPE_LONG)
                        {
                            fprintf(stderr, "SEMANTIC ERROR in line %d. Identifier %s must be assigned to byte or int.\n", node->lineNumber, node->symbol->text);
                            semanticError++;
                        }
                }
            }
            else if (node->symbol->datatype == DATATYPE_BOOL)
            {
                if (node->son[0] != NULL)
                {
                    if (node->son[0]->symbol && node->son[0]->symbol->datatype)
                        if (node->son[0]->symbol->datatype != DATATYPE_BOOL)
                        {
                            fprintf(stderr, "SEMANTIC ERROR in line %d. Identifier %s must be assigned to float.\n", node->lineNumber, node->symbol->text);
                            semanticError++;
                        }
                }
            }
        }
        break;
    case AST_ADD:
    case AST_SUB:
    case AST_MUL:
    case AST_DIV:
    case AST_POINT:
        // Check correctness
        for (i = 0; i < 2; ++i)
        {
            if (
                node->son[i]->type == AST_ADD ||
                node->son[i]->type == AST_SUB ||
                node->son[i]->type == AST_MUL ||
                node->son[i]->type == AST_DIV ||
                node->son[i]->type == AST_POINT ||
                ((node->son[i]->type == AST_SYMBOL) &&
                 ((node->son[i]->symbol->type == SYMBOL_SCALAR) &&
                  node->son[i]->symbol->datatype != DATATYPE_BOOL && node->son[i]->symbol->datatype != DATATYPE_STRING)) ||
                ((node->son[i]->type == AST_SYMBOL) &&
                 (node->son[i]->type == AST_SYMBOL &&
                      node->son[i]->symbol->type == SYMBOL_LIT_INT ||
                  node->son[i]->symbol->type == SYMBOL_LIT_FLOAT ||
                  node->son[i]->symbol->type == SYMBOL_LIT_CHAR)) ||
                ((node->son[i]->type == AST_VECREAD) &&
                 ((node->son[i]->symbol->type == SYMBOL_VECTOR) &&
                  node->son[i]->symbol->datatype != DATATYPE_BOOL && node->son[i]->symbol->datatype != DATATYPE_STRING)) ||
                ((node->son[i]->type == AST_FUNCALL) &&
                 ((node->son[i]->symbol->type == SYMBOL_FUNCTION) &&
                  node->son[i]->symbol->datatype != DATATYPE_BOOL && node->son[i]->symbol->datatype != DATATYPE_STRING)))
            {

                fprintf(stderr, "LINE %d - SON %d - CORRECT \n", node->lineNumber, i);
            }
            else
            {
                fprintf(stderr, "SON %d TYPE: %d \n", i, node->son[i]->type);
                fprintf(stderr, "SON %d SYMBOL TYPE: %d \n", i, node->son[i]->symbol->type);
                fprintf(stderr, "SON %d DATATYPE: %d \n", i, node->son[i]->symbol->datatype);
                fprintf(stderr, "LINE %d - SON %d - SemanticError: Operands not compatible \n", node->lineNumber, i);
                semanticError++;
            }
        }
        break;
    case AST_LESS:
    case AST_GREATER:
    case AST_LE:
    case AST_GE:
    case AST_EQ:
    case AST_NE:
        if (node->son[0]->symbol && node->son[0]->symbol->datatype && node->son[1]->symbol && node->son[1]->symbol->datatype)
            if (node->son[0] != NULL && node->son[1] != NULL)
            {
                node->datatype = DATATYPE_BOOL;
                if ((node->son[0]->symbol->datatype != DATATYPE_INT && node->son[0]->symbol->datatype != DATATYPE_BYTE && node->son[0]->symbol->datatype != DATATYPE_FLOAT && node->son[0]->symbol->datatype != DATATYPE_LONG) ||
                    (node->son[1]->symbol->datatype != DATATYPE_INT && node->son[1]->symbol->datatype != DATATYPE_BYTE && node->son[1]->symbol->datatype != DATATYPE_FLOAT && node->son[0]->symbol->datatype != DATATYPE_LONG))
                {
                    fprintf(stderr, "SEMANTIC ERROR in line %d. Operators must be int, byte, float or long. \n", node->lineNumber);
                    semanticError++;
                }
            }
        break;
    case AST_AND:
    case AST_OR:
        if (node->son[0]->symbol && node->son[0]->symbol->datatype && node->son[1]->symbol && node->son[1]->symbol->datatype)
            if (node->son[0] != NULL && node->son[1] != NULL)
            {
                node->datatype = DATATYPE_BOOL;
                if (node->son[0]->symbol->datatype != DATATYPE_BOOL || node->son[1]->symbol->datatype != DATATYPE_BOOL)
                {
                    fprintf(stderr, "SEMANTIC ERROR in line %d. Operators must be bool.\n", node->lineNumber);
                    semanticError++;
                    node->datatype = DATATYPE_ERROR;
                }
            }
        break;
    case AST_TIL:
        if (node->son[0] != NULL)
        {
            node->datatype = DATATYPE_BOOL;
            if (node->son[0]->symbol && node->son[0]->symbol->datatype)
                if (node->son[0]->symbol->datatype != DATATYPE_BOOL)
                {
                    fprintf(stderr, "SEMANTIC ERROR in line %d. Operators must be bool.\n", node->lineNumber);
                    semanticError++;
                }
        }
        break;
    case AST_READ:
        if (node->symbol->type != SYMBOL_SCALAR)
        {
            fprintf(stderr, "SEMANTIC ERROR in line %d. Symbol %s must be scalar\n", node->lineNumber, node->symbol->text);
            semanticError++;
        }
        break;
    case AST_PRINT:
        if (node->son[0] != NULL)
        {
            if (node->son[0]->type != AST_PRINTLIST)
            {
                fprintf(stderr, "PRINT SON TYPE: %d\n", node->son[0]->type);
                fprintf(stderr, "SEMANTIC ERROR in line %d. Not a print list\n", node->lineNumber);
                semanticError++;
            }
            else if (checkPrint(node->son[0]))
            {
                fprintf(stderr, "SEMANTIC ERROR in line %d. Incompatible type found in print\n", node->lineNumber);
                semanticError++;
            }
        }
        break;
    default:
        break;
    }

    for (i = 0; i < MAX_SONS; ++i)
        checkOperands(node->son[i]);
}

int checkPrint(AST *node)
{
    if (node != NULL)
    {
        if (node->son[0] != NULL)
        {

            // fprintf(stderr, "PRINT SON TYPE: %d\n", node->son[0]->type);
            // fprintf(stderr, "PRINT SON SYMBOL TYPE: %d\n", node->son[0]->symbol->type);
            // fprintf(stderr, "PRINT SON DATATYPE: %d\n", node->son[0]->symbol->datatype);
            if (node->son[0]->symbol)
            {
                if (
                    ((node->son[0]->type == AST_SYMBOL) &&
                     ((node->son[0]->symbol->type == SYMBOL_SCALAR) &&
                      node->son[0]->symbol->datatype != DATATYPE_BOOL)) ||
                    ((node->son[0]->type == AST_SYMBOL) &&
                     (node->son[0]->type == AST_SYMBOL &&
                          node->son[0]->symbol->type == SYMBOL_LIT_INT ||
                      node->son[0]->symbol->type == SYMBOL_LIT_FLOAT ||
                      node->son[0]->symbol->type == SYMBOL_LIT_CHAR)) ||
                    ((node->son[0]->type == AST_VECREAD) &&
                     ((node->son[0]->symbol->type == SYMBOL_VECTOR) &&
                      node->son[0]->symbol->datatype != DATATYPE_BOOL)) ||
                    ((node->son[0]->type == AST_FUNCALL) &&
                     ((node->son[0]->symbol->type == SYMBOL_FUNCTION) &&
                      node->son[0]->symbol->datatype != DATATYPE_BOOL)) ||
                    node->son[0]->symbol->datatype == DATATYPE_STRING)
                {
                    fprintf(stderr, "PRINT SON DATATYPE: %d\n", node->son[0]->symbol->datatype);

                    if (node->son[1])
                        return checkPrint(node->son[1]);
                    else
                    {
                        return 0;
                    }
                }
            }
            else if (node->son[0]->type == AST_ADD ||
                     node->son[0]->type == AST_SUB ||
                     node->son[0]->type == AST_MUL ||
                     node->son[0]->type == AST_DIV ||
                     node->son[0]->type == AST_POINT)
            {
                if (node->son[1])
                    return checkPrint(node->son[1]);
                else
                {
                    return 0;
                }
            }
        }
    }

    return 1;
}

int checkVector(AST *node, int datatype)
{
    if (node != NULL)
    {
        // fprintf(stderr, "DATATYPE - %d\n", datatype);
        // fprintf(stderr, "SON DATATYPE - %d\n", node->son[0]->symbol->datatype);
        if (((node->son[0]->symbol->datatype != datatype) &&
             ((datatype == DATATYPE_INT || datatype == DATATYPE_BYTE || datatype == DATATYPE_FLOAT || datatype == DATATYPE_LONG) &&
              (node->son[0]->symbol->datatype == DATATYPE_BOOL || node->son[0]->symbol->datatype != DATATYPE_STRING))) ||
            (datatype == DATATYPE_BOOL && node->son[0]->symbol->datatype != DATATYPE_BOOL))
            return 0;
        if (node->son[1] != NULL)
            return checkVector(node->son[1], datatype);
    }

    return 1;
}

int validReturn(AST *nodeDec, AST *node)
{
    int decType = nodeDec->symbol->datatype;
    //fprintf(stderr, "DECLARATION TYPE : %d\n", nodeDec->symbol->datatype);
    int returnType;
    if (node->type == AST_RETURN)
    {
        if (node->son[0]->symbol)
        {
            returnType = node->son[0]->symbol->datatype;
            //fprintf(stderr, "RETURN TYPE : %d\n", node->son[0]->symbol->datatype);
            if ((decType != returnType) &&
                (((decType == DATATYPE_INT || decType == DATATYPE_BYTE || decType == DATATYPE_FLOAT || decType == DATATYPE_LONG) &&
                  (returnType == DATATYPE_BOOL || returnType == DATATYPE_STRING)) ||
                 (((returnType == DATATYPE_INT || returnType == DATATYPE_BYTE || returnType == DATATYPE_FLOAT || returnType == DATATYPE_LONG) &&
                   (decType == DATATYPE_BOOL || decType == DATATYPE_STRING)))))
                return 0;
            else
                return 1;
        }
    }
    else
    {
        int i = 0;

        for (i = 0; i < MAX_SONS; i++)
        {
            if (node->son[i] != NULL)
            {
                int found;
                found = validReturn(nodeDec, node->son[i]);
                if (found != 999)
                    return found;
            }
        }
    }

    return 999;
}
