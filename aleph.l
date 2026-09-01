%{
    #include "aleph.tab.h"
    #include "aleph.h"
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
%}

%option noyywrap

%%
"if" {return IF;}
"while" {return WHILE;}
"def" {return DEF;}
"return" {return RETURN;}
"=" {return ASIGNACION;}
"pop" {return POPA;}
"push" {return PUSHA;}
"difc" {return DIFC;}
"inter" {return INTE;}
"un" {return UN;} 
"(" {return PAREN_I;}
")" {return PAREN_D;}
"{" {return LLAVE_I;}
"}" {return LLAVE_D;}
"[" {return CORCH_I;}
"]" {return CORCH_D;}
"," {return COMA;}
";" {return EOL;}
[ \t \n] {}
[A-Z][A-Z0-9]* {yylval.v=lookup(yytext);return IDVARIABLE;}
[a-zA-Z0-9]+ {yylval.e=strdup(yytext);return IDCADENA;}
. {printf("error");}
%%