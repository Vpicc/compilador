#include <stdio.h>
#include <stdlib.h>
#include "semantic.h"
int semanticError = 0;
AST *nodeDeclared;

int getSemanticError()
{
    return semanticError;
}

void checkAndSetTypes(AST *node)
{
    int i;

    if (nodeDeclared == NULL)
        nodeDeclared = node;

    if (!node)
    {
        return;
    }

    if (node->type == AST_DECL || node->type == AST_FUNDEC || node->type == AST_ARRDECL || node->type == AST_PAR)
    {
        if (node->symbol)
        {
            if (node->symbol->type != SYMBOL_TK_IDENTIFIER)
            {
                fprintf(stderr, "Erro de semantica na linha %d: Variavel %s ja declarada\n", node->lineNumber, node->symbol->text);
                semanticError++;
            }
            if (node->type == AST_DECL)
                node->symbol->type = SYMBOL_SCALAR;
            if (node->type == AST_FUNDEC)
            {
                node->symbol->type = SYMBOL_FUNCTION;
                node->symbol->numparameters = numParamsFunc(node->son[1]);
            }
            if (node->type == AST_ARRDECL)
                node->symbol->type = SYMBOL_VECTOR;

            if (node->type == AST_PAR)
            {
                //printf("Entrei aqui\n");
                //stderr, "Node type = %d\n", node->son[0]->type);
                node->symbol->type = SYMBOL_SCALAR;
            }

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
    if (nodeDeclared == NULL)
        nodeDeclared = node;
    if (node && node->son[0] != NULL)
    {
        if (node->son[0]->type == AST_TYPEINT)
        {
            //printf("2-Etrei aqui2\n");
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
    int op1;
    int op2;
    int exp;
    int exp1 = 0;
    int exp2 = 0;
    int exp3 = 0;
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
                fprintf(stderr, "Erro de semantica na linha %d. Variavel %s deve receber int, byte\n", node->lineNumber, node->symbol->text);
                semanticError++;
            }
            else if (node->symbol->datatype == DATATYPE_FLOAT && node->son[1]->symbol->datatype != DATATYPE_FLOAT)
            {
                fprintf(stderr, "Erro de semantica na linha %d. Variavel %s deve receber float\n", node->lineNumber, node->symbol->text);
                semanticError++;
            }
            else if (node->symbol->datatype == DATATYPE_BOOL && node->son[1]->symbol->datatype != DATATYPE_BOOL)
            {
                fprintf(stderr, "Erro de semantica na linha %d. Variavel %s deve receber bool\n", node->lineNumber, node->symbol->text);
                //fprintf(stderr,"DATATYPE RECEIVED %d.\n", node->son[1]->symbol->datatype);

                semanticError++;
            }
            else if (node->symbol->datatype == DATATYPE_LONG && (node->son[1]->symbol->datatype != DATATYPE_LONG && node->son[1]->symbol->datatype != DATATYPE_FLOAT && node->son[1]->symbol->datatype != DATATYPE_INT))
            {
                fprintf(stderr, "Erro de semantica na linha %d. Variavel %s deve receber long\n", node->lineNumber, node->symbol->text);
                semanticError++;
            }
        }
        break;

    case AST_ARRDECL:
        if (checkVector(node->son[2], node->symbol->datatype) == 0)
        {
            fprintf(stderr, "Erro de semantica na linha %d. Um ou mais tipos declarados no vetor está errado\n", node->lineNumber);
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
            fprintf(stderr, "Erro de semantica na linha %d. %s não é um vetor\n", node->lineNumber, node->symbol->text);
            semanticError++;
        }

        //fprintf(stderr, "INDEX TYPE: %d \n", node->son[0]->symbol->datatype);
        exp = validExpression(node->son[0]);
        if ((exp != DATATYPE_INT && exp != DATATYPE_BYTE && exp != DATATYPE_LONG) || exp == DATATYPE_ERROR)
        {
            fprintf(stderr, "Erro de semantica na linha %d. Um ou mais tipo errado, devem ser byte, int, long ou float.\n", node->lineNumber);
            semanticError++;
        }
        break;
    case AST_VECTORASS:
        if (node->symbol->type != SYMBOL_VECTOR)
        {
            fprintf(stderr, "Erro de semantica na linha %d. %s não é um vetor.\n", node->lineNumber,node->symbol->text);
            semanticError++;
        }
        if (node->son[0] && node->son[0]->symbol && node->son[0]->symbol->datatype)
            if (node->son[0]->symbol->datatype != DATATYPE_INT && node->son[0]->symbol->datatype != DATATYPE_BYTE && node->son[0]->symbol->datatype != DATATYPE_LONG)
            {
                fprintf(stderr, "Erro de semantica na linha %d. Tipo invalido na atribuição, o tipo deve ser byte, int, long ou float.\n", node->lineNumber);
                semanticError++;
            }

        exp = validExpression(node->son[1]);
        if (node->symbol->datatype == DATATYPE_INT || node->symbol->datatype == DATATYPE_BYTE || node->symbol->datatype == DATATYPE_FLOAT || node->symbol->datatype == DATATYPE_LONG)
        {
            if (exp == DATATYPE_BOOL || exp == DATATYPE_ERROR)
            {
                fprintf(stderr, "Erro de semantica na linha %d. Tipo invalido na atribuição, o idetificador (%s) deve ser atribuido aos tipos byte, int, long ou float.\n", node->lineNumber, node->symbol->text);
                semanticError++;
            }
        }
        else if (node->symbol->datatype == DATATYPE_BOOL)
        {
            if (exp != DATATYPE_BOOL || exp == DATATYPE_ERROR)
            {
                fprintf(stderr, "Erro de semantica na linha %d. Tipo invalido na atribuição, o idetificador (%s) deve ser atribuido ao tipo booleano.\n", node->lineNumber, node->symbol->text);
                semanticError++;
            }
        }
        break;
    case AST_ASS:
        if (node)
        {
            if (node->symbol->type != SYMBOL_SCALAR)
            {
                fprintf(stderr, "Erro de semantica na linha %d. O simbolo (%s) deve ser um escalar.\n", node->lineNumber, node->symbol->text);
                semanticError++;
            }

            exp = validExpression(node->son[0]);

            if (node->symbol->datatype == DATATYPE_INT || node->symbol->datatype == DATATYPE_BYTE || node->symbol->datatype == DATATYPE_FLOAT || node->symbol->datatype == DATATYPE_LONG)
            {
                if (exp == DATATYPE_BOOL || exp == DATATYPE_ERROR)
                {
                    fprintf(stderr, "Erro de semantica na linha %d. Tipo invalido na atribuição, o idetificador (%s) deve ser atribuido aos tipos byte, int, long ou float.\n", node->lineNumber, node->symbol->text);
                    semanticError++;
                }
            }
            else if (node->symbol->datatype == DATATYPE_BOOL)
            {
                if (exp != DATATYPE_BOOL || exp == DATATYPE_ERROR)
                {
                    fprintf(stderr, "Erro de semantica na linha %d. Tipo invalido na atribuição, o idetificador (%s) deve ser atribuido ao tipo booleano.\n", node->lineNumber, node->symbol->text);
                    semanticError++;
                }
            }
        }
        break;

        /*NOVA PARTE*/
    case AST_ADD:
    case AST_SUB:
    case AST_MUL:
    case AST_DIV:
    case AST_POINT:
        op1 = getType(node->son[0]);
        op2 = getType(node->son[1]);
        if (addExpressionTypes(op1, op2) == DATATYPE_ERROR)
        {
            fprintf(stderr, "Erro de semantica na linha %d. Os operadores devem ser int, byte, long ou float.\n", node->lineNumber);
            semanticError++;
        };
        break;
        /*FIM DA NOVA PARTE*/
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
                    fprintf(stderr, "Erro de semantica na linha %d. Os operadores devem ser int, byte, long ou float.\n", node->lineNumber);
                    semanticError++;
                }
            }
        break;
    case AST_AND:
    case AST_OR:
        exp = validExpression(node);
        node->datatype = DATATYPE_BOOL;
        if (exp != DATATYPE_BOOL || exp == DATATYPE_ERROR)
        {
            fprintf(stderr, "Erro de semantica na linha %d. Os operadores devem ser do tipo booleano\n", node->lineNumber);
            semanticError++;
        };
        break;
    case AST_TIL:
        if (node->son[0] != NULL)
        {
            node->datatype = DATATYPE_BOOL;
            if (node->son[0]->symbol && node->son[0]->symbol->datatype)
                if (node->son[0]->symbol->datatype != DATATYPE_BOOL)
                {
                    fprintf(stderr, "Erro de semantica na linha %d. Os operadores devem ser do tipo booleano\n", node->lineNumber);
                    semanticError++;
                }
        }
        break;
    case AST_READ:
        if (node->symbol->type != SYMBOL_SCALAR)
        {
            fprintf(stderr, "Erro de semantica na linha %d. O simbolo (%s) devem ser escalar.\n", node->lineNumber, node->symbol->text);
            semanticError++;
        }
        break;
    case AST_PRINT:
        if (node->son[0] != NULL)
        {
            if (node->son[0]->type != AST_PRINTLIST)
            {
                //fprintf(stderr, "PRINT SON TYPE: %d\n", node->son[0]->type);
                fprintf(stderr, "Erro de semantica na linha %d. Not a print list.\n", node->lineNumber);
                semanticError++;
            }
            else if (checkPrint(node->son[0]))
            {
                fprintf(stderr, "Erro de semantica na linha %d. Tipos incompativeis encontrados no print\n", node->lineNumber);
                semanticError++;
            }
        }
        break;

    case AST_FUNDEC:
        if (validReturn(node, node) == 0)
        {
            fprintf(stderr, "Erro de semantica na linha %d. Tipo de retorno invalido %s\n", node->lineNumber, node->symbol->text);
            semanticError++;
        }
        break;

    case AST_FUNCALL:
        checkTypeParam(node);
        break;

    case AST_IF:
    case AST_IFELSE:
    case AST_WHILE:
        if (node->son[0] != NULL)
        {
            exp = validExpression(node->son[0]);
            if (exp != DATATYPE_BOOL || exp == DATATYPE_ERROR)
            {
                fprintf(stderr, "Erro de semantica na linha %d. Os operadores devem ser booleanos\n", node->lineNumber);
                semanticError++;
            }
        }
        break;
    case AST_FOR:

        if (node->son[0])
            exp1 = validExpression(node->son[0]);
        if (node->son[1])
            exp2 = validExpression(node->son[1]);
        if (node->son[2])
            exp3 = validExpression(node->son[2]);
        fprintf(stderr, "FOR: 0 ******* %d\n", exp1);
        fprintf(stderr, "FOR: 1 ******* %d\n", exp2);
        fprintf(stderr, "FOR: 2 ******* %d\n", exp3);
        if (exp1 == DATATYPE_BOOL || exp1 == DATATYPE_ERROR)
        {
            fprintf(stderr, "Erro de semantica na linha %d. A primeira expressao do for deve ser byte, int, long ou float\n", node->lineNumber);
            semanticError++;
        }
        if (exp2 != DATATYPE_BOOL || exp2 == DATATYPE_ERROR)
        {
            fprintf(stderr, "Erro de semantica na linha %d. A segunda expressao do for deve ser booleana\n", node->lineNumber);
            semanticError++;
        }
        if (exp3 == DATATYPE_BOOL || exp3 == DATATYPE_ERROR)
        {
            fprintf(stderr, "Erro de semantica na linha %d. A terceira expressao do for deve ser byte, int, long ou float\n", node->lineNumber);
            semanticError++;
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
                    //fprintf(stderr, "PRINT SON DATATYPE: %d\n", node->son[0]->symbol->datatype);

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

        if (node->son[0])
        {
            returnType = validExpression(node->son[0]);
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

void checkTypeParam(AST *nodecall)
{
    if (!nodecall)
        return;
    AST *nodedef;
    int dec_type;
    int call_type;

    if (!checkParams(nodecall))
    {
        fprintf(stderr, "Erro de semantica na linha %d. Numero de argumentos errados.\n", nodecall->lineNumber);
        semanticError++;
        return;
    }
    if (nodecall->symbol != NULL)
        nodedef = search(nodeDeclared, nodecall->symbol->text);

    if (nodecall->son[0] != NULL && nodedef->son[1] != NULL)
    {
        nodecall = nodecall->son[0];
        nodedef = nodedef->son[1];

        while (nodecall != NULL && nodedef != NULL)
        {
            if (nodecall->son[0]->symbol != NULL && nodedef->son[0]->symbol != NULL)
            {
                dec_type = nodecall->son[0]->symbol->datatype;
                call_type = nodedef->son[0]->symbol->datatype;
                //fprintf(stderr, "PRINT NODDECALL  SYMBOL_DATA_TYPE: %d\n", nodecall->son[0]->symbol->datatype);
                //fprintf(stderr, "PRINT NODEdef SYMBOL_DATA_TYPE: %d\n", nodedef->son[0]->symbol->datatype);
                if (
                    (dec_type == DATATYPE_INT && (call_type == DATATYPE_BYTE || call_type == DATATYPE_FLOAT || call_type == DATATYPE_LONG || call_type == DATATYPE_INT)) ||
                    (dec_type == DATATYPE_FLOAT && (call_type == DATATYPE_BYTE || call_type == DATATYPE_INT || call_type == DATATYPE_LONG || call_type == DATATYPE_FLOAT)) ||
                    (dec_type == DATATYPE_LONG && (call_type == DATATYPE_BYTE || call_type == DATATYPE_FLOAT || call_type == DATATYPE_INT || call_type == DATATYPE_LONG)) ||
                    (dec_type == DATATYPE_BYTE && (call_type == DATATYPE_BYTE || call_type == DATATYPE_FLOAT || call_type == DATATYPE_INT || call_type == DATATYPE_LONG)) ||
                    (dec_type == DATATYPE_BOOL && call_type == DATATYPE_BOOL))
                {
                    //fprintf(stderr, "PRINT NODDECALL  SYMBOL_DATA_TYPE: %d\n", nodecall->son[0]->symbol->datatype);
                    //fprintf(stderr, "PRINT NODEdef SYMBOL_DATA_TYPE: %d\n", nodedef->son[0]->symbol->datatype);
                    //printf("Entrei");
                }
                else
                {
                    //fprintf(stderr, "PRINT NODDECALL  SYMBOL_DATA_TYPE: %d\n", nodecall->son[0]->symbol->datatype);
                    //fprintf(stderr, "PRINT NODEdef SYMBOL_DATA_TYPE: %d\n", nodedef->son[0]->symbol->datatype);
                    fprintf(stderr, "Erro de semantica na linha %d. Um ou mais parametros com o tipo errado.\n", nodecall->lineNumber);
                    semanticError++;
                }
            }
            nodecall = nodecall->son[1];
            nodedef = nodedef->son[1];
        }
    }
}

AST *search(AST *node, char *name)
{
    int i;
    AST *fun;

    if (!node)
        return 0;

    if (node->type == AST_FUNDEC)
        if (node->symbol != NULL)
        {
            if (strcmp(node->symbol->text, name) == 0)
                return node;
        }

    for (i = 0; i < MAX_SONS; i++)
        if (node->son[i] != NULL)
        {
            fun = search(node->son[i], name);
            if (fun)
                return fun;
        }
    return 0;
}

int getType(AST *node)
{
    int op1, op2;

    if (!node)
        return DATATYPE_ERROR;

    switch (node->type)
    {
    case AST_SYMBOL:

        if (node->symbol->type == SYMBOL_VECTOR)
        {
            return DATATYPE_ERROR;
        }
        if (node->symbol->type == SYMBOL_FUNCTION)
        {
            return DATATYPE_ERROR;
        }
        return node->symbol->datatype;
    case AST_VECREAD:
        return node->symbol->datatype;
    case AST_FUNCALL:
        return node->symbol->datatype;
    case AST_ADD:
    case AST_SUB:
    case AST_DIV:
    case AST_MUL:
    case AST_POINT:
        op1 = getType(node->son[0]);
        op2 = getType(node->son[1]);
        return addExpressionTypes(op1, op2);
    case AST_GE:
    case AST_EQ:
    case AST_NE:
    case AST_AND:
    case AST_OR:
    case AST_GREATER:
    case AST_LESS:
    case AST_LE:
    case AST_TIL:
        return DATATYPE_BOOL;
    case AST_PARENTHESIS:
        return validExpression(node->son[0]);
    default:
        return 0;
    }
}

int addExpressionTypes(int type1, int type2)
{
    switch (type1)
    {
    case DATATYPE_BOOL:
        switch (type2)
        {
        case DATATYPE_BOOL:
            return DATATYPE_BOOL;
        default:
            return DATATYPE_ERROR;
        }
        //break;
    case DATATYPE_INT:
        switch (type2)
        {
        case DATATYPE_INT:
            return DATATYPE_INT;
        case DATATYPE_BYTE:
            return DATATYPE_BYTE;
        case DATATYPE_FLOAT:
            return DATATYPE_FLOAT;
        case DATATYPE_LONG:
            return DATATYPE_LONG;
        default:
            return DATATYPE_ERROR;
        }
        //break;
    case DATATYPE_BYTE:
        switch (type2)
        {
        case DATATYPE_INT:
            return DATATYPE_INT;
        case DATATYPE_BYTE:
            return DATATYPE_BYTE;
        case DATATYPE_FLOAT:
            return DATATYPE_FLOAT;
        case DATATYPE_LONG:
            return DATATYPE_LONG;
        default:
            return DATATYPE_ERROR;
        }
        //break;
    case DATATYPE_FLOAT:
        switch (type2)
        {
        case DATATYPE_INT:
            return DATATYPE_INT;
        case DATATYPE_BYTE:
            return DATATYPE_BYTE;
        case DATATYPE_FLOAT:
            return DATATYPE_FLOAT;
        case DATATYPE_LONG:
            return DATATYPE_LONG;
        default:
            return DATATYPE_ERROR;
        }
        //break;
    case DATATYPE_LONG:
        switch (type2)
        {
        case DATATYPE_INT:
            return DATATYPE_INT;
        case DATATYPE_BYTE:
            return DATATYPE_BYTE;
        case DATATYPE_FLOAT:
            return DATATYPE_FLOAT;
        case DATATYPE_LONG:
            return DATATYPE_LONG;
        default:
            return DATATYPE_ERROR;
        }
    //break;
    default:
        return DATATYPE_ERROR;
    }
}

int validExpression(AST *nodeSon)
{
    int op1, op2;
    if (!nodeSon)
    {
        return DATATYPE_ERROR;
    }

    switch (nodeSon->type)
    {
    case AST_SYMBOL:
        if (nodeSon->symbol->type == SYMBOL_VECTOR)
        {
            return DATATYPE_ERROR;
        }
        if (nodeSon->symbol->type == SYMBOL_FUNCTION)
        {
            return DATATYPE_ERROR;
        }
        return nodeSon->symbol->datatype;
    case AST_VECREAD:
        return nodeSon->symbol->datatype;
    case AST_FUNCALL:
        return nodeSon->symbol->datatype;
    case AST_ADD:
    case AST_SUB:
    case AST_DIV:
    case AST_MUL:
    case AST_POINT:
        op1 = validExpression(nodeSon->son[0]);
        op2 = validExpression(nodeSon->son[1]);
        return addExpressionTypes(op1, op2);
    case AST_GE:
    case AST_EQ:
    case AST_NE:
    case AST_LESS:
    case AST_LE:
    case AST_GREATER:
        op1 = validExpression(nodeSon->son[0]);
        op2 = validExpression(nodeSon->son[1]);
        if ((op1 != DATATYPE_BOOL || op1 != DATATYPE_STRING) && op1 != DATATYPE_ERROR && (op2 != DATATYPE_BOOL || op2 != DATATYPE_STRING) && op2 != DATATYPE_ERROR)
        {
            return DATATYPE_BOOL;
        }
        else
        {
            return DATATYPE_ERROR;
        }
    case AST_OR:
    case AST_AND:
        op1 = validExpression(nodeSon->son[0]);
        op2 = validExpression(nodeSon->son[1]);
        return addExpressionTypes(op1, op2);
    case AST_TIL:
        op1 = validExpression(nodeSon->son[0]);
        if (op1 == DATATYPE_BOOL)
        {
            return DATATYPE_BOOL;
        }
        else
        {
            return DATATYPE_ERROR;
        }

    case AST_PARENTHESIS:
        return validExpression(nodeSon->son[0]);
    default:
        return 0;
    }
}
