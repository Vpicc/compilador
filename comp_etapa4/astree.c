#include "astree.h"

AST *astCreate(int type, HASH_NODE *symbol, AST *s0, AST *s1, AST *s2, AST *s3)
{
    AST *newnode = 0;
    newnode = (AST *)calloc(1, sizeof(AST));
    newnode->type = type;
    newnode->symbol = symbol;
    newnode->son[0] = s0;
    newnode->son[1] = s1;
    newnode->son[2] = s2;
    newnode->son[3] = s3;
    return newnode;
}

void astPrint(AST *node, int level)
{
    int i;
    if (!node)
        return;

    for (i = 0; i < level; ++i)
        fprintf(stderr, "  ");
    fprintf(stderr, "AST(");

    switch (node->type)
    {
    case AST_SYMBOL:
        fprintf(stderr, "AST_SYMBOL,");
        break;
    case AST_ADD:
        fprintf(stderr, "AST_ADD,");
        break;
    case AST_MUL:
        fprintf(stderr, "AST_MUL,");
        break;
    case AST_SUB:
        fprintf(stderr, "AST_SUB,");
        break;
    case AST_DIV:
        fprintf(stderr, "AST_DIV,");
        break;
    case AST_DECL:
        fprintf(stderr, "AST_DECL,");
        break;
    case AST_ASS:
        fprintf(stderr, "AST_ASS,");
        break;
    case AST_VECREAD:
        fprintf(stderr, "AST_VECREAD,");
        break;
    case AST_LCMD:
        fprintf(stderr, "AST_LCMD,");
        break;
    case AST_VARDEC:
        fprintf(stderr, "AST_VARDEC,");
        break;
    case AST_FUNDEC:
        fprintf(stderr, "AST_FUNDEC,");
        break;
    case AST_TYPEINT:
        fprintf(stderr, "AST_TYPEINT,");
        break;
    case AST_TYPEFLOAT:
        fprintf(stderr, "AST_TYPEFLOAT,");
        break;
    case AST_TYPEBOOL:
        fprintf(stderr, "AST_TYPEBOOL,");
        break;
    case AST_TYPEBYTE:
        fprintf(stderr, "AST_TYPEBYTE,");
        break;
    case AST_TYPELONG:
        fprintf(stderr, "AST_TYPELONG,");
        break;
    case AST_IF:
        fprintf(stderr, "AST_IF,");
        break;
    case AST_IFELSE:
        fprintf(stderr, "AST_IFELSE,");
        break;
    case AST_WHILE:
        fprintf(stderr, "AST_WHILE,");
        break;
    case AST_FOR:
        fprintf(stderr, "AST_FOR,");
        break;
    case AST_LESS:
        fprintf(stderr, "AST_LESS,");
        break;
    case AST_GREATER:
        fprintf(stderr, "AST_GREATER,");
        break;
    case AST_LE:
        fprintf(stderr, "AST_LE,");
        break;
    case AST_GE:
        fprintf(stderr, "AST_GE,");
        break;
    case AST_NE:
        fprintf(stderr, "AST_NE,");
        break;
    case AST_EQ:
        fprintf(stderr, "AST_EQ,");
        break;
    case AST_DIFF:
        fprintf(stderr, "AST_DIFF,");
        break;
    case AST_POINT: //Não lembro pra q q era aqle ponto, ai só botei
        fprintf(stderr, "AST_POINT,");
        break;
    case AST_OR:
        fprintf(stderr, "AST_OR,");
        break;
    case AST_PARENTHESIS:
        fprintf(stderr, "AST_PARENTHESIS,");
        break;
    case AST_BLOCK:
        fprintf(stderr, "AST_BLOCK,");
        break;
    case AST_PRINT:
        fprintf(stderr, "AST_PRINT,");
        break;
    case AST_RETURN:
        fprintf(stderr, "AST_RETURN,");
        break;
    case AST_ARRDECL:
        fprintf(stderr, "AST_ARRDECL,");
        break;
    case AST_FUNCALL:
        fprintf(stderr, "AST_FUNCALL,");
        break;
    case AST_READ:
        fprintf(stderr, "AST_READ,");
        break;
    case AST_VECTORASS:
        fprintf(stderr, "AST_VECTORASS,");
        break;
    case AST_PAR:
        fprintf(stderr, "AST_PAR,");
        break;
    case AST_PARLIST:
        fprintf(stderr, "AST_PARLIST,");
        break;
    case AST_FUNLIST:
        fprintf(stderr, "AST_FUNLIST,");
        break;
    case AST_FUNLIST_REST:
        fprintf(stderr, "AST_FUNLIST_REST,");
        break;
    case AST_PROG:
        fprintf(stderr, "AST_PROG,");
        break;
    case AST_VECLIST:
        fprintf(stderr, "AST_VECLIST,");
        break;
    case AST_VECREST:
        fprintf(stderr, "AST_VECREST,");
        break;
    case AST_PRINTLIST:
        fprintf(stderr, "AST_PRINTLIST,");
        break;
    case AST_PRINTLIST_REST:
        fprintf(stderr, "AST_PRINTLIST_REST,");
        break;
    case AST_PROG_VARDECL:
        fprintf(stderr, "AST_PROG_VARDECL,");
        break;
    case AST_PROG_FUNCDECL:
        fprintf(stderr, "AST_PROG_FUNCDECL,");
        break;
    case AST_VECSIZE:
        fprintf(stderr, "AST_VECSIZE,");
        break;
    case AST_PARLIST_REST:
        fprintf(stderr, "AST_PARLIST_REST,");
        break;
    case AST_CMDEND:
        fprintf(stderr, "AST_CMDEND,");
        break;
    case AST_TIL:
        fprintf(stderr, "AST_TIL,");
        break;

    default:
        break;
    }

    if (node->symbol)
    {
        fprintf(stderr, "VALUE: %s", node->symbol->text);
    }

    fprintf(stderr, "\n");

    for (i = 0; i < MAX_SONS; ++i)
        astPrint(node->son[i], level + 1);
}

void astDecompile(AST *s0)
{
    if (s0 != NULL)
    {
        switch (s0->type)
        {
        //OK
        case AST_SYMBOL:
            fprintf(out, "%s", s0->symbol->text);
            break;
        //OK
        case AST_ADD:
            astDecompile(s0->son[0]);
            fprintf(out, " + ");
            astDecompile(s0->son[1]);
            break;
        //OK
        case AST_MUL:
            astDecompile(s0->son[0]);
            fprintf(out, " * ");
            astDecompile(s0->son[1]);
            break;
        //OK
        case AST_SUB:
            astDecompile(s0->son[0]);
            fprintf(out, " - ");
            astDecompile(s0->son[1]);
            break;
        //OK
        case AST_DIV:
            astDecompile(s0->son[0]);
            fprintf(out, "/ ");
            astDecompile(s0->son[1]);
            break;
        //OK
        case AST_DECL:
            astDecompile(s0->son[0]);
            fprintf(out, " ");
            fprintf(out, "%s", s0->symbol->text);
            fprintf(out, " = ");
            astDecompile(s0->son[1]);
            fprintf(out, ";");
            astDecompile(s0->son[2]);
            break;
        //OK
        case AST_ASS:
            fprintf(out, "%s", s0->symbol->text);
            fprintf(out, " = ");
            astDecompile(s0->son[0]);
            break;
        //OK
        case AST_VECREAD:
            fprintf(out, "%s", s0->symbol->text);
            fprintf(out, "[");
            astDecompile(s0->son[0]);
            fprintf(out, "]");
            astDecompile(s0->son[1]);

            if (s0->son[2] != NULL)
                astDecompile(s0->son[2]);

            break;
        //ACHO q ta certo
        case AST_LCMD:
            if (s0->son[1] != NULL)
            {
                if (s0->son[0] != NULL)
                {
                    astDecompile(s0->son[0]);
                    fprintf(out, ";\n");
                    astDecompile(s0->son[1]);
                }
            }
            else if (s0->son[0] != NULL)
                astDecompile(s0->son[0]);
            break;
        //ACHO Q TA CERTO
        case AST_CMDEND:
            if (s0->son[1] != NULL)
            {
                if (s0->son[0] != NULL)
                {
                    astDecompile(s0->son[0]);
                    fprintf(out, ";\n");
                    astDecompile(s0->son[1]);
                }
            }
            else if (s0->son[0] != NULL)
                astDecompile(s0->son[0]);
            break;
        //ACHO Q TA CERTO
        case AST_FUNDEC:
            astDecompile(s0->son[0]);
            fprintf(out, " ");
            fprintf(out, "%s", s0->symbol->text);
            fprintf(out, "(");
            astDecompile(s0->son[1]);
            fprintf(out, ")");
            astDecompile(s0->son[2]);
            break;
        //OK
        case AST_TYPEINT:
            fprintf(out, "int");
            break;
        //OK
        case AST_TYPEFLOAT:
            fprintf(out, "float");
            break;
        //OK
        case AST_TYPEBOOL:
            fprintf(out, "bool");
            break;
        //OK
        case AST_TYPEBYTE:
            fprintf(out, "byte");
            break;
        //OK
        case AST_TYPELONG:
            fprintf(out, "long");
            break;
        //OK
        case AST_IF:
            fprintf(out, "if(");
            astDecompile(s0->son[0]);
            fprintf(out, ") then ");
            fprintf(out, " \n");
            astDecompile(s0->son[1]);
            break;
        //OK
        case AST_IFELSE:
            fprintf(out, "if(");
            astDecompile(s0->son[0]);
            fprintf(out, ") then ");
            astDecompile(s0->son[1]);
            fprintf(out, " ");
            fprintf(out, "else ");
            astDecompile(s0->son[2]);
            break;
        //OK
        case AST_WHILE:
            fprintf(out, "while(");
            astDecompile(s0->son[0]);
            fprintf(out, ")");
            astDecompile(s0->son[1]);
            break;
        //ACHO Q TA CERTO
        case AST_FOR:
            fprintf(out, "for (%s:", s0->symbol->text);
            astDecompile(s0->son[0]);
            fprintf(out, ",");
            astDecompile(s0->son[1]);
            fprintf(out, ",");
            astDecompile(s0->son[2]);
            fprintf(out, ") \n");
            astDecompile(s0->son[3]);
            break;
        //OK
        case AST_LESS:
            astDecompile(s0->son[0]);
            fprintf(out, " < ");
            astDecompile(s0->son[1]);
            break;
        //OK
        case AST_GREATER:
            astDecompile(s0->son[0]);
            fprintf(out, " > ");
            astDecompile(s0->son[1]);
            break;
        //OK
        case AST_LE:
            astDecompile(s0->son[0]);
            fprintf(out, " <= ");
            astDecompile(s0->son[1]);
            break;
        //OK
        case AST_GE:
            astDecompile(s0->son[0]);
            fprintf(out, " >= ");
            astDecompile(s0->son[1]);
            break;
        //OK
        case AST_EQ:
            astDecompile(s0->son[0]);
            fprintf(out, " == ");
            astDecompile(s0->son[1]);
            ;
            break;
        //OK
        case AST_DIFF:
            astDecompile(s0->son[0]);
            fprintf(out, " != ");
            astDecompile(s0->son[1]);
            break;
        case AST_BREAK:
            fprintf(out, "break");
            break;
        case AST_POINT: //TODO: Nem ideia do q colocar aqui
            astDecompile(s0->son[0]);
            fprintf(out, " . ");
            astDecompile(s0->son[1]);
            ;
            break;
        case AST_TIL: //TODO: Nem ideia do q colocar aqui
            astDecompile(s0->son[0]);
            fprintf(out, " ~ ");
            astDecompile(s0->son[1]);
            ;
            break;
        //OK
        case AST_OR:
            astDecompile(s0->son[0]);
            fprintf(out, " v ");
            astDecompile(s0->son[1]);
            break;
        //OK
        case AST_PARENTHESIS:
            fprintf(out, "(");
            astDecompile(s0->son[0]);
            fprintf(out, ")");
            break;
        //OK
        case AST_BLOCK:
            fprintf(out, "\n{\n");
            astDecompile(s0->son[0]);
            fprintf(out, "}");
            break;
        //OK
        case AST_PRINT:
            fprintf(out, "print ");
            astDecompile(s0->son[0]);
            break;
        //OK
        case AST_RETURN:
            fprintf(out, "return ");
            astDecompile(s0->son[0]);
            break;
        //OK
        case AST_ARRDECL:
            astDecompile(s0->son[0]);
            fprintf(out, " %s", s0->symbol->text);
            fprintf(out, "[");
            astDecompile(s0->son[1]);
            fprintf(out, "]");

            if (s0->son[2] != NULL)
            {
                fprintf(out, ": ");
                astDecompile(s0->son[2]);
            }

            fprintf(out, ";");
            break;
        //ACHO Q TA CERTO
        case AST_FUNCALL:
            fprintf(out, "%s", s0->symbol->text);
            fprintf(out, "(");
            astDecompile(s0->son[0]);
            fprintf(out, ")");
            break;
        //OK
        case AST_READ:
            fprintf(out, "read ");
            fprintf(out, "%s", s0->symbol->text);
            break;
        //OK
        case AST_VECTORASS:
            fprintf(out, "%s", s0->symbol->text);
            fprintf(out, "[");
            astDecompile(s0->son[0]);
            fprintf(out, "]");
            fprintf(out, " = ");
            astDecompile(s0->son[1]);
            break;
        //OK
        case AST_PAR:
            astDecompile(s0->son[0]);
            fprintf(out, " ");
            fprintf(out, "%s", s0->symbol->text);
            break;
        //ACHO Q TA CERTO
        case AST_PARLIST:
            if (s0->son[1] != NULL)
            {
                if (s0->son[0] != NULL)
                {
                    astDecompile(s0->son[0]);
                    fprintf(out, ",");
                    astDecompile(s0->son[1]);
                }
            }
            else
            {
                if (s0->son[0] != NULL)
                    astDecompile(s0->son[0]);
            }
            break;
        //ACHO Q TA CERTO
        case AST_PARLIST_REST:
            if (s0->son[1] != NULL)
            {
                if (s0->son[0] != NULL)
                {
                    astDecompile(s0->son[0]);
                    fprintf(out, ",");
                    astDecompile(s0->son[1]);
                }
            }
            else
            {
                if (s0->son[0] != NULL)
                    astDecompile(s0->son[0]);
            }
            break;
        //ACHO Q TA CERTO
        case AST_FUNLIST:
            if (s0->son[1] != NULL)
            {
                if (s0->son[0] != NULL)
                {
                    astDecompile(s0->son[0]);
                    fprintf(out, ",");
                    astDecompile(s0->son[1]);
                }
            }
            else
            {
                if (s0->son[0] != NULL)
                    astDecompile(s0->son[0]);
            }
            break;
        //ACHO Q TA CERTO
        case AST_FUNLIST_REST:
            if (s0->son[1] != NULL)
            {
                if (s0->son[0] != NULL)
                {
                    astDecompile(s0->son[0]);
                    fprintf(out, ",");
                    astDecompile(s0->son[1]);
                }
            }
            else
            {
                if (s0->son[0] != NULL)
                    astDecompile(s0->son[0]);
            }
            break;
        //ACHO Q TA CERTO
        case AST_PROG:
            if (s0->son[1] != NULL)
            {
                astDecompile(s0->son[0]);
                fprintf(out, " \n");
                astDecompile(s0->son[1]);
            }
            else
                astDecompile(s0->son[0]);
            break;
        //OK
        case AST_VECLIST:
            astDecompile(s0->son[0]);
            if (s0->son[1] != NULL)
            {
                fprintf(out, " ");
                astDecompile(s0->son[1]);
            }
            break;
        //OK
        case AST_VECREST:
            astDecompile(s0->son[0]);
            if (s0->son[1] != NULL)
            {
                fprintf(out, " ");
                astDecompile(s0->son[1]);
            }
            break;
        //ACHO Q TA CERTO
        case AST_PRINTLIST:
            if (s0->son[1] != NULL)
            {
                astDecompile(s0->son[0]);
                //fprintf(out,",");
                astDecompile(s0->son[1]);
            }
            else
                astDecompile(s0->son[0]);
            break;
        //ACHO Q TA CERTO
        case AST_PRINTLIST_REST:
            if (s0->son[1] != NULL)
            {
                astDecompile(s0->son[0]);
                //fprintf(out,",");
                astDecompile(s0->son[1]);
            }
            else
                astDecompile(s0->son[0]);
            break;
        case AST_PROG_VARDECL:
            fprintf(out, " \n");
            astDecompile(s0->son[0]);
            break;
        case AST_PROG_FUNCDECL:
            fprintf(out, " \n");
            astDecompile(s0->son[0]);
            break;
        case AST_VECSIZE:
            fprintf(out, "%s", s0->symbol->text);
            break;

        default:
            break;
        }
    }
}