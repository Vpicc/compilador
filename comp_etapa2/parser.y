
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

fundec: vartype TK_IDENTIFIER '(' parlist ')' body ;

par: KW_INT TK_IDENTIFIER;

parlist:  par rest   |   ;

rest: ',' par rest  |   ;

body: cmd body   |   ;

funcall: TK_IDENTIFIER '(' funlist ')';

funpar: TK_IDENTIFIER | literal;

funlist: funpar funrest | ;

funrest: ',' funpar funrest | ;

cmd:  TK_IDENTIFIER '=' literal | 
    TK_IDENTIFIER '[' vecindex ']' '=' literal |
    KW_PRINT printlist |
    KW_READ TK_IDENTIFIER |
    KW_WHILE '(' expression ')' cmd |  
    TK_IDENTIFIER '=' funcall |
    KW_FOR '(' ')' cmd |
    block |
    ;

printlist: expression printrest;

printrest: expression printrest | ;

expression: TK_IDENTIFIER '[' vecindex ']' | 
    TK_IDENTIFIER |
    literal |
    expression '<' expression |
;

vecindex:
    TK_IDENTIFIER | LIT_INTEGER;

block:  '{' lcmd '}'
    ;

lcmd:  lcmd cmd ';'
    |
    ;

%%

int yyerror(char *msg) {
    fprintf(stderr, "Erro de sintaxe na linha %d!\n", lineNumber);
    exit(3); //codigo de erro sintatico padrao
}