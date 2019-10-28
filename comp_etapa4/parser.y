
%{

#include <stdio.h>
#include <stdlib.h>
#include "hash_table.h"
#include "astree.h"
#include "lex.yy.h"
#include "semantic.h"

extern int lineNumber;
int getLineNumber(void);
int yyerror(char*);
AST *root;

%}

%union {
    AST *ast;
    HASH_NODE *symbol;
}

%token KW_BYTE
%token KW_INT
%token KW_LONG
%token KW_FLOAT
%token KW_BOOL
%token KW_IF
%token KW_THEN
%token KW_ELSE
%token KW_WHILE
%token KW_FOR
%token KW_READ
%token KW_PRINT
%token KW_RETURN
%token KW_BREAK

%token OPERATOR_LE
%token OPERATOR_GE
%token OPERATOR_EQ
%token OPERATOR_DIF

%token <symbol> TK_IDENTIFIER
%token <symbol> LIT_INTEGER
%token <symbol> LIT_FLOAT
%token <symbol> LIT_TRUE
%token <symbol> LIT_FALSE
%token <symbol> LIT_CHAR
%token <symbol> LIT_STRING

//%start begin
%type <ast> begin
%type <ast> literal
%type <ast> vartype
%type <ast> programa
%type <ast> decl
%type <ast> vardec
%type <ast> veclist
%type <ast> vecrest
%type <ast> fundec
%type <ast> par
%type <ast> parlist
%type <ast> rest
%type <ast> funcall
%type <ast> funpar
%type <ast> funlist
%type <ast> funrest
%type <ast> cmd
%type <ast> printlist
%type <ast> printrest
%type <ast> expression
%type <ast> block
%type <ast> lcmd
%type <ast> cmdend


%left OPERATOR_DIF OPERATOR_EQ OPERATOR_GE OPERATOR_LE '>' '<'
%left '.' 'v' '~' '&'
%left '+' '-'
%left '*' '/'
%right KW_THEN KW_ELSE 
%right TK_IDENTIFIER '[' '(' // talvez esteja errado

%%

begin: programa {root = $$;
                astDecompile($$);
                astPrint($$,0);
                checkAndSetTypes($1);
                checkUndeclared();
                checkOperands($1);
                fprintf(stderr,"%d Semantic errors\n", getSemanticError());
                /*checkSemantic($$);*/
                };

programa: programa decl {$$=astCreate(AST_PROG, 0,$1,$2,0,0, getLineNumber());} | {$$ = 0;};


decl: vardec { $$ = astCreate (AST_PROG_VARDECL, 0, $1, 0, 0, 0,getLineNumber()); }|
 fundec { $$ = astCreate (AST_PROG_FUNCDECL, 0, $1, 0, 0, 0, getLineNumber()); };

vardec: vartype  TK_IDENTIFIER '=' literal ';' {$$=astCreate(AST_DECL, $2,$1,$4,0,0,getLineNumber());}|
        vartype TK_IDENTIFIER '['LIT_INTEGER']' veclist ';'		{$$=astCreate(AST_ARRDECL,$2,$1,astCreate(AST_VECSIZE, $4, 0, 0, 0, 0,getLineNumber()),$6,0,getLineNumber());}
    ;

vartype: KW_INT {$$=astCreate(AST_TYPEINT,0,0,0,0,0,getLineNumber());} |
KW_BOOL {$$=astCreate(AST_TYPEBOOL,0,0,0,0,0,getLineNumber());} |
KW_BYTE {$$=astCreate(AST_TYPEBYTE,0,0,0,0,0,getLineNumber());} |
KW_LONG {$$=astCreate(AST_TYPELONG,0,0,0,0,0,getLineNumber());} |
KW_FLOAT {$$=astCreate(AST_TYPEFLOAT,0,0,0,0,0,getLineNumber());} ;

literal: LIT_INTEGER {$$=astCreate(AST_SYMBOL,$1,0,0,0,0,getLineNumber());} |
LIT_FLOAT  {$$=astCreate(AST_SYMBOL,$1,0,0,0,0,getLineNumber());} |
LIT_TRUE   {$$=astCreate(AST_SYMBOL,$1,0,0,0,0,getLineNumber());} |
LIT_FALSE  {$$=astCreate(AST_SYMBOL,$1,0,0,0,0,getLineNumber());} |
LIT_CHAR   {$$=astCreate(AST_SYMBOL,$1,0,0,0,0,getLineNumber());} |
LIT_STRING {$$=astCreate(AST_SYMBOL,$1,0,0,0,0,getLineNumber());} ;

veclist: ':' literal vecrest {$$ = astCreate(AST_VECLIST,0,$2,$3,0,0,getLineNumber());} |
         {$$ = 0;};

vecrest: literal vecrest {$$ = astCreate(AST_VECREST,0,$1,$2,0,0,getLineNumber());} |
         {$$ = 0;};

fundec: vartype TK_IDENTIFIER '(' parlist ')' block {$$=astCreate(AST_FUNDEC,$2,$1,$4,$6,0,getLineNumber());} ;

par: vartype TK_IDENTIFIER { $$ = astCreate(AST_PAR, $2, $1, 0, 0, 0,getLineNumber());};

parlist:  par rest { $$ = astCreate(AST_PARLIST, 0, $1, $2, 0, 0,getLineNumber());} |
          {$$ = 0;};

rest: ',' par rest  { $$ = astCreate(AST_PARLIST_REST, 0, $2, $3, 0, 0,getLineNumber());} |
         {$$ = 0;};

funcall: TK_IDENTIFIER '(' funlist ')' {$$ = astCreate(AST_FUNCALL,$1,$3,0,0,0,getLineNumber());} ;

funpar: expression {$$ = $1;};

funlist: funpar funrest {$$ = astCreate(AST_FUNLIST, 0,$1,$2,0,0,getLineNumber());} |
         {$$ = 0;};

funrest: ',' funpar funrest { $$ = astCreate(AST_FUNLIST_REST, 0, $2, $3, 0, 0,getLineNumber()); } |
         {$$ = 0;};

cmd:  TK_IDENTIFIER '=' expression {$$=astCreate(AST_ASS,$1,$3,0,0,0,getLineNumber());}| 
    TK_IDENTIFIER '[' expression ']' '=' expression {$$=astCreate(AST_VECTORASS,$1,$3,$6,0,0,getLineNumber());}|
    KW_PRINT printlist {$$=astCreate(AST_PRINT,0,$2,0,0,0,getLineNumber());}|
    KW_READ TK_IDENTIFIER  { $$ = astCreate(AST_READ, $2, 0, 0, 0, 0,getLineNumber()); }|
    KW_WHILE '(' expression ')' cmd {$$=astCreate(AST_WHILE,0,$3,$5,0,0,getLineNumber());}|  
    KW_FOR '(' TK_IDENTIFIER ':' expression ',' expression ',' expression ')' cmd {$$=astCreate(AST_FOR,$3,$5,$7,$9,$11,getLineNumber());}|
    KW_IF '(' expression ')' KW_THEN cmd {$$=astCreate(AST_IF,0,$3,$6,0,0,getLineNumber());} |
    KW_IF '(' expression ')' KW_THEN cmd KW_ELSE cmd {$$=astCreate(AST_IFELSE,0,$3,$6,$8,0,getLineNumber());} |
    KW_BREAK {$$=astCreate(AST_BREAK,0,0,0,0,0,getLineNumber());}|
    block {$$ = $1;} |
    KW_RETURN expression {$$=astCreate(AST_RETURN,0,$2,0,0,0,getLineNumber());} | {$$ = 0;};
    ;


printlist: expression printrest {$$=astCreate(AST_PRINTLIST,0,$1,$2,0,0,getLineNumber());} ;

printrest: expression printrest {$$=astCreate(AST_PRINTLIST_REST,0,$1,$2,0,0,getLineNumber());} | {$$ = 0; } ;

expression: TK_IDENTIFIER '[' expression ']' { $$ = astCreate(AST_VECREAD, $1, $3, 0, 0, 0,getLineNumber());}  | 
    TK_IDENTIFIER {$$=astCreate(AST_SYMBOL,$1,0,0,0,0,getLineNumber());}|
    literal {$$=$1;}|
    expression OPERATOR_EQ expression {$$=astCreate(AST_EQ,0,$1,$3,0,0,getLineNumber());}|
    expression OPERATOR_DIF expression {$$=astCreate(AST_DIFF,0,$1,$3,0,0,getLineNumber());}|
    expression OPERATOR_GE expression {$$=astCreate(AST_GE,0,$1,$3,0,0,getLineNumber());}|
    expression OPERATOR_LE expression {$$=astCreate(AST_LE,0,$1,$3,0,0,getLineNumber());}|
    expression '+' expression {$$=astCreate(AST_ADD,0,$1,$3,0,0,getLineNumber());}|
    expression '-' expression {$$=astCreate(AST_SUB,0,$1,$3,0,0,getLineNumber());}|
    expression '*' expression {$$=astCreate(AST_MUL,0,$1,$3,0,0,getLineNumber());}|
    expression '/' expression {$$=astCreate(AST_DIV,0,$1,$3,0,0,getLineNumber());}|
    expression '<' expression {$$=astCreate(AST_LESS,0,$1,$3,0,0,getLineNumber());}|
    expression '>' expression {$$=astCreate(AST_GREATER,0,$1,$3,0,0,getLineNumber());}|
    expression '.' expression {$$=astCreate(AST_POINT,0,$1,$3,0,0,getLineNumber());}|
    expression 'v' expression {$$=astCreate(AST_OR,0,$1,$3,0,0,getLineNumber());}|
    expression '&' expression {$$=astCreate(AST_AND,0,$1,$3,0,0,getLineNumber());}|
    '~' expression {$$=astCreate(AST_TIL,0,$2,0,0,0,getLineNumber());}|
    '(' expression ')'        {$$=astCreate(AST_PARENTHESIS,0,$2,0,0,0,getLineNumber());}|
    funcall {$$ = $1;};

block:  '{' lcmd '}' {$$=astCreate(AST_BLOCK,0,$2,0,0,0,getLineNumber());}
    ;

lcmd:  cmd cmdend {$$=astCreate(AST_LCMD,0,$1,$2,0,0,getLineNumber());};

cmdend: ';' cmd cmdend {$$=astCreate(AST_CMDEND,0,$2,$3,0,0,getLineNumber());} | {$$ = 0;};

%%

int yyerror(char *msg) {
    fprintf(stderr, "Erro de sintaxe na linha %d!\n", getLineNumber());
    exit(3); //codigo de erro sintatico padrao
}
