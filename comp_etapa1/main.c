#include <stdio.h>
#include "tokens.h"

extern int isRunning(void);
extern void initMe(void);
extern int getLineNumber();

int main()
{
    FILE *file;
    if (!(file = fopen("test.txt", "r")))
    {
        printf("Erro ao abrir arquivo");
    }
    yyin = file;
    initMe();
    while (isRunning())
    {
        switch (yylex())
        {

        case KW_BYTE:
            fprintf(stderr, "keyword byte na linha %d \n", getLineNumber());
            break;
        case KW_INT:
            fprintf(stderr, "keyword int na linha %d \n", getLineNumber());
            break;
        case KW_LONG:
            fprintf(stderr, "keyword long na linha %d \n", getLineNumber());
            break;
        case KW_FLOAT:
            fprintf(stderr, "keyword float na linha %d \n", getLineNumber());
            break;
        case KW_THEN:
            fprintf(stderr, "keyword then na linha %d \n", getLineNumber());
            break;
        case KW_FOR:
            fprintf(stderr, "keyword for na linha %d \n", getLineNumber());
            break;
        case KW_READ:
            fprintf(stderr, "keyword read na linha %d \n", getLineNumber());
            break;
        case KW_BOOL:
            fprintf(stderr, "keyword bool na linha %d \n", getLineNumber());
            break;
        case KW_IF:
            fprintf(stderr, "keyword if na linha %d \n", getLineNumber());
            break;
        case KW_ELSE:
            fprintf(stderr, "keyword else na linha %d \n", getLineNumber());
            break;
        case KW_PRINT:
            fprintf(stderr, "keyword print na linha %d \n", getLineNumber());
            break;
        case KW_WHILE:
            fprintf(stderr, "keyword while na linha %d \n", getLineNumber());
            break;
        case KW_RETURN:
            fprintf(stderr, "keyword return na linha %d \n", getLineNumber());
            break;
        case KW_BREAK:
            fprintf(stderr, "keyword break na linha %d \n", getLineNumber());
            break;
        case TOKEN_ERROR:
            fprintf(stderr, "error |%s| na linha %d \n", yytext, getLineNumber());
            break;
        case TK_IDENTIFIER:
            fprintf(stderr, "identificador |%s| na linha %d \n", yytext, getLineNumber());
            break;
        case LIT_INTEGER:
            fprintf(stderr, "inteiro literal |%s| na linha %d \n", yytext, getLineNumber());
            break;
        case LIT_FLOAT:
            fprintf(stderr, "float literal |%s| na linha %d \n", yytext, getLineNumber());
            break;
        case LIT_CHAR:
            fprintf(stderr, "char literal |%s| na linha %d \n", yytext, getLineNumber());
            break;
        case LIT_STRING:
            fprintf(stderr, "string literal |%s| na linha %d \n", yytext, getLineNumber());
            break;
        case OPERATOR_LE:
            fprintf(stderr, "operador <= na linha %d \n", getLineNumber());
            break;
        case OPERATOR_GE:
            fprintf(stderr, "operador >= na linha %d \n", getLineNumber());
            break;
        case OPERATOR_EQ:
            fprintf(stderr, "operador == na linha %d \n", getLineNumber());
            break;
        case OPERATOR_DIF:
            fprintf(stderr, "operador != na linha %d \n", getLineNumber());
            break;
        case LIT_TRUE:
            fprintf(stderr, "TRUE literal na linha %d \n", getLineNumber());
            break;
        case LIT_FALSE:
            fprintf(stderr, "FALSE literal na linha %d \n", getLineNumber());
            break;
        default:
            fprintf(stderr, "token |%s| na linha %d \n", yytext, getLineNumber());
            break;
        }
    }

    hashPrint();

    return 0;
}
