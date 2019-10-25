#include <stdio.h>
#include <stdlib.h>
#include "semantic.h"

void checkAndSetTypes(AST *node)
{
    return;
};

void checkUndeclared(void)
{
    return;
};

//We have five types, they are INT, BOOL, FLOAT, LONG and BOOL
void setTypes(AST* node)
{
	if(node->son[0] != NULL)
    {
        if(node->son[0]->type == AST_TYPEINT)
        {
            node->son[0]->datatype = AST_DATATYPE_INT;
			node->symbol->datatype = DATATYPE_INT;
			node->datatype = AST_DATATYPE_INT;
			
		} 
        else if(node->son[0]->type == AST_TYPEFLOAT)
        {
            node->son[0]->datatype = AST_DATATYPE_FLOAT;
			node->symbol->datatype = DATATYPE_FLOAT;
			node->datatype = AST_DATATYPE_FLOAT;
		}
		else if(node->son[0]->type == AST_TYPEBYTE)
        {
            node->son[0]->datatype = AST_DATATYPE_BYTE;
			node->symbol->datatype = DATATYPE_BYTE;
			node->datatype = AST_DATATYPE_BYTE;	
		}
        else if(node->son[0]->type == AST_TYPELONG)
        {
            node->son[0]->datatype = AST_DATATYPE_LONG;
			node->symbol->datatype = DATATYPE_LONG;
			node->datatype = AST_DATATYPE_LONG;	
		}  
        else if(node->son[0]->type == AST_TYPEBOOL)
        {
            node->son[0]->datatype = AST_DATATYPE_BOOL;
			node->symbol->datatype = DATATYPE_BOOL;
			node->datatype = AST_DATATYPE_BOOL;	
		}    
	}
};

int getType(AST* node) 
{
    int op1, op2;
    
    switch(node->type) 
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
                node->datatype = expressionTypes(op1,op2); //TODO: EXPRESSION TYPES
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

int expressionTypes(int op1,int op2)
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

int numParamsFunc(AST* node)
{
	if(node == 0) 
        return 0;
	else
		return 1 + numParamsFunc(node->son[1]);
	
	return 0;
};

int checkParams(AST* node)
{
	int countParams = 0;

	int params = node->symbol->numparameters;
	
	countParams = numParamsFunc(node->son[0]);

	if(countParams != params)
	{
		return 0;
	}

    return 1;	
}