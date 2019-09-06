
%{
int lineNumber = 1;
int running = 1;

#include "y.tab.h"
#include "hash_table.c"
//#include "tokens.h"


void initMed(void);
int getLineNumber();
int isRunning();

%}

%x COMMENT

DIGIT [0-9]

%%
byte        return KW_BYTE;
int         return KW_INT;
long        return KW_LONG;
float       return KW_FLOAT; 
bool        return KW_BOOL;
if          return KW_IF;
then        return KW_THEN;
else        return KW_ELSE;
while       return KW_WHILE; 
for         return KW_FOR;
read        return KW_READ;
print       return KW_PRINT;
return      return KW_RETURN;
break       return KW_BREAK;

"<="        return OPERATOR_LE;
">="        return OPERATOR_GE;
"=="        return OPERATOR_EQ;
"!="        return OPERATOR_DIF;

TRUE        { hashInsert(yytext, LIT_TRUE); return LIT_TRUE; }
FALSE       { hashInsert(yytext, LIT_FALSE); return LIT_FALSE; }
\'(.|\\.)\'       { hashInsert(yytext, LIT_CHAR); return LIT_CHAR; }
\"(\\.|[^\\"])*\"     { hashInsert(yytext, LIT_STRING); return LIT_STRING; }

","|";"|":"|"("|")"|"["|"]"|"{"|"}"|"+"|"-"|"*"|"/"|"<"|">"|"="|"v"|"."|"~"|"&"|"$"|"#" return yytext[0];


[A-Za-z_][A-Za-z_0-9]*  { hashInsert(yytext, TK_IDENTIFIER);  return TK_IDENTIFIER;}
{DIGIT}+                { hashInsert(yytext, LIT_INTEGER);    return LIT_INTEGER;}
{DIGIT}+"."{DIGIT}+|{DIGIT}+"."|"."{DIGIT}+     { hashInsert(yytext, LIT_FLOAT);      return LIT_FLOAT;}


"//".*                  {  }
[ \t]                   {  }
"\r"                    {  }
"\n"                    {   ++lineNumber;  }

"###"    BEGIN(COMMENT);
<COMMENT>"###"     BEGIN(INITIAL);
<COMMENT>"\n"     ++lineNumber;
<COMMENT>"\t"
<COMMENT>.  

.
%%

#include "main.c"
#include "y.tab.c"

int yywrap()
{
    running = 0;
    return 1;
}

int isRunning(void){
    return running;
}

int getLineNumber(void){
    return lineNumber;
}

void initMe(void){
    hashInit();
}