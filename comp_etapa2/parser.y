
%{

#include <stdio.h>
#include <stdlib.h>

extern int lineNumber;

%}

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
%token TK_IDENTIFIER 
%token LIT_INTEGER   
%token LIT_FLOAT     
%token LIT_TRUE      
%token LIT_FALSE     
%token LIT_CHAR
%token LIT_STRING


%%

programa: programa decl  |   ;

decl: vardec | fundec;

vardec: vartype  TK_IDENTIFIER '=' literal ';' |
    vartype TK_IDENTIFIER '[' LIT_INTEGER ']' veclist ';'
    ;

vartype: KW_INT | KW_BOOL | KW_BYTE | KW_LONG | KW_FLOAT;

literal: LIT_INTEGER |
LIT_FLOAT  |
LIT_TRUE   |
LIT_FALSE  |
LIT_CHAR   |
LIT_STRING ;

veclist: ':' literal vecrest | ;

vecrest: literal vecrest | ;

fundec: vartype TK_IDENTIFIER '(' parlist ')' block ;

par: vartype TK_IDENTIFIER;

parlist:  par rest   |   ;

rest: ',' par rest  |   ;

funcall: TK_IDENTIFIER '(' funlist ')';

funpar: expression;

funlist: funpar funrest | ;

funrest: ',' funpar funrest | ;

cmd:  TK_IDENTIFIER '=' expression | 
    TK_IDENTIFIER '[' expression ']' '=' expression |
    KW_PRINT printlist |
    KW_READ TK_IDENTIFIER |
    KW_WHILE '(' expression ')' cmd |  
    KW_FOR '(' forlist ')' cmd |
    KW_IF '(' expression ')' KW_THEN cmd else |
    KW_BREAK |
    block |
    KW_RETURN expression |
    ;

else: KW_ELSE cmd |
    ;

forlist: forfirst ',' forsecond ',' forthird;

forfirst: TK_IDENTIFIER ':' expression;

forsecond: expression;

forthird: expression;

printlist: expression printrest;

printrest: expression printrest | ;

expression: TK_IDENTIFIER '[' expression ']' | 
    TK_IDENTIFIER |
    literal |
    expression OPERATOR_EQ expression |
    expression OPERATOR_DIF expression |
    expression OPERATOR_GE expression |
    expression OPERATOR_LE expression |
    expression '+' expression |
    expression '-' expression |
    expression '*' expression |
    expression '/' expression |
    expression '<' expression |
    expression '>' expression |
    expression '.' expression |
    expression 'v' expression |
    expression '~' expression |
    '(' expression ')'        |
    funcall;

block:  '{' lcmd '}'
    ;

lcmd:  cmd cmdend;

cmdend: ';' cmd cmdend | ;

%%

int yyerror(char *msg) {
    fprintf(stderr, "Erro de sintaxe na linha %d!\n", lineNumber);
    exit(3); //codigo de erro sintatico padrao
}
