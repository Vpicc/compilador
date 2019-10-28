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

        
    if(nodeDeclared==NULL)
		nodeDeclared=node;

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
                fprintf(stderr, "LINE %d - SemanticError: Symbol %s already declared\n", node->lineNumber, node->symbol->text);
                semanticError++;
            }
            if (node->type == AST_DECL)
                node->symbol->type = SYMBOL_SCALAR;
            if (node->type == AST_FUNDEC){
                node->symbol->type = SYMBOL_FUNCTION;
                node->symbol->numparameters = numParamsFunc(node->son[1]);
            }
            if (node->type == AST_ARRDECL)
                node->symbol->type = SYMBOL_VECTOR;

            if (node->type == AST_PAR){
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
    if(nodeDeclared==NULL)
		nodeDeclared=node;
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
                // fprintf(stderr, "SON %d TYPE: %d \n", i, node->son[i]->type);
                // fprintf(stderr, "SON %d SYMBOL TYPE: %d \n", i, node->son[i]->symbol->type);
                // fprintf(stderr, "SON %d DATATYPE: %d \n", i, node->son[i]->symbol->datatype);
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

    case AST_FUNDEC:
        if (validReturn(node, node) == 0)
        {
            fprintf(stderr, "SEMANTIC ERROR in line %d. Invalid return type in function %s.\n", node->lineNumber, node->symbol->text);
            semanticError++;
        }
        break;

    case AST_FUNCALL:
        checkTypeParam(node);
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

int functionValidation(AST *nodeDeclared, AST *node)
{
   
    if (nodeDeclared->type == AST_FUNDEC  && strcmp(nodeDeclared->symbol->text, node->symbol->text) == 0)
    {
        AST *declaration_param = NULL;
        int dec_type, call_type;

        if (nodeDeclared->type == AST_FUNDEC)
            declaration_param = nodeDeclared->son[1];

        AST *funccall_param = node->son[0];

        if (declaration_param == NULL && funccall_param == NULL)
            return 1;
        if (!checkParams(node))
            return 3;

        while (declaration_param != NULL && funccall_param != NULL)
        {
            fprintf(stderr, "DECLARADO: SYMBOL TYPE= %d  TYPE = %d DATAYPE= %d\n", declaration_param->son[0]->symbol->type, declaration_param->son[0]->type, declaration_param->son[0]->datatype);
            switch (declaration_param->son[0]->symbol->type)
            {
            case AST_TYPEINT:
                dec_type = DATATYPE_INT;
                break;

            case AST_TYPEFLOAT:
                dec_type = DATATYPE_FLOAT;
                break;

            case AST_TYPEBYTE:
                dec_type = DATATYPE_BYTE;
                break;

            case AST_TYPEBOOL:
                dec_type = DATATYPE_BOOL;
                break;

            case AST_TYPELONG:
                dec_type = DATATYPE_LONG;
                break;

            default:
                dec_type = DATATYPE_ERROR;
                break;
            }

            call_type = funccall_param->son[0]->symbol->datatype;

            if (dec_type != call_type)
            {
                fprintf(stderr, "Declarado= %d   Call = %d\n", dec_type, call_type);
                if ((dec_type == DATATYPE_BYTE && (call_type == DATATYPE_INT || call_type == DATATYPE_FLOAT || call_type == DATATYPE_LONG)) || 
                    (dec_type == DATATYPE_INT && (call_type == DATATYPE_BYTE || call_type == DATATYPE_FLOAT || call_type == DATATYPE_LONG))||
                    (dec_type == DATATYPE_FLOAT && (call_type == DATATYPE_BYTE || call_type == DATATYPE_INT || call_type == DATATYPE_LONG))||
                    (dec_type == DATATYPE_LONG && (call_type == DATATYPE_BYTE || call_type == DATATYPE_FLOAT || call_type == DATATYPE_INT)))
                    return 1;
                else
                    return 2;
            }
            if (declaration_param->son[1])
                declaration_param = declaration_param->son[1]->son[0];

            else
            {
                declaration_param = NULL;
            }

            if (funccall_param->son[1])
            {
                funccall_param = funccall_param->son[1]->son[0];
            }
            else
            {
                funccall_param = NULL;
            }
        }

       
    }
    else
    {
        int number_sons = 0;

        for (number_sons = 0; number_sons < 4; number_sons++)
        {
            if (nodeDeclared->son[number_sons] != NULL)
            {
                int found;
                found = functionValidation(nodeDeclared->son[number_sons], node);
                if (found != 5)
                    return found;
            }
        }
    }

    return 5;
}

void checkTypeParam(AST* nodecall) 
{
	if(!nodecall) return;
	AST* nodedef;
    int dec_type;
    int call_type;

     if (!checkParams(nodecall)){
        fprintf(stderr, "ERRO: number of arguments wrong at line: %d\n",nodecall->lineNumber );
        semanticError++;
        return;
    }
	if(nodecall->symbol != NULL) nodedef = search(nodeDeclared, nodecall->symbol->text);	

	if(nodecall->son[0] != NULL && nodedef->son[1] != NULL)
	{
		nodecall = nodecall->son[0];	
		nodedef = nodedef->son[1];	
	
		while(nodecall != NULL && nodedef != NULL)
		{	
			if(nodecall->son[0]->symbol != NULL && nodedef->son[0]->symbol != NULL) 
				{
                    dec_type = nodecall->son[0]->symbol->datatype;
                    call_type = nodedef->son[0]->symbol->datatype;
                    //fprintf(stderr, "PRINT NODDECALL  SYMBOL_DATA_TYPE: %d\n", nodecall->son[0]->symbol->datatype);
                    //fprintf(stderr, "PRINT NODEdef SYMBOL_DATA_TYPE: %d\n", nodedef->son[0]->symbol->datatype);
                    if  (
                        (dec_type == DATATYPE_INT && (call_type == DATATYPE_BYTE || call_type == DATATYPE_FLOAT || call_type == DATATYPE_LONG || call_type == DATATYPE_INT))||
                        (dec_type == DATATYPE_FLOAT && (call_type == DATATYPE_BYTE || call_type == DATATYPE_INT || call_type == DATATYPE_LONG || call_type == DATATYPE_FLOAT))||
                        (dec_type == DATATYPE_LONG && (call_type == DATATYPE_BYTE || call_type == DATATYPE_FLOAT || call_type == DATATYPE_INT || call_type == DATATYPE_LONG )) ||
                        (dec_type == DATATYPE_BYTE && (call_type == DATATYPE_BYTE || call_type == DATATYPE_FLOAT || call_type == DATATYPE_INT || call_type == DATATYPE_LONG ))
                        ){
                            //fprintf(stderr, "PRINT NODDECALL  SYMBOL_DATA_TYPE: %d\n", nodecall->son[0]->symbol->datatype);
                            //fprintf(stderr, "PRINT NODEdef SYMBOL_DATA_TYPE: %d\n", nodedef->son[0]->symbol->datatype);
                            //printf("Entrei");
                        }
                    else{
                        // fprintf(stderr, "PRINT NODDECALL  SYMBOL_DATA_TYPE: %d\n", nodecall->son[0]->symbol->datatype);
                        // fprintf(stderr, "PRINT NODEdef SYMBOL_DATA_TYPE: %d\n", nodedef->son[0]->symbol->datatype);
					 	fprintf(stderr, "ERRO: One or more parameters type wrong at line: %d\n", nodecall->lineNumber);
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
	
	if(!node) return 0;

	
		if(node->type == AST_FUNDEC)
			if(node->symbol != NULL)
			{			
				if(strcmp(node->symbol->text, name) == 0)
					return node;
			}

		for(i=0; i < MAX_SONS; i++)
			if(node->son[i] != NULL) 
			{
				fun = search(node->son[i], name);
				if(fun) 
					return fun;
			}
	return 0;
}

