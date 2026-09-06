%{
    #include "aleph.tab.h"
    #include "aleph.h"
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
%}

%option noyywrap

%%
"=" {return ASIGNACION;}
"func" {return FUNC;}
"funcvoid" {return FUNCVOID;}
"retorna" {return RETORNA;}
"if" {return IF;}          /* antes: "si" -> SI */
"else" {return ELSE;}      /* antes: "sino" -> SINO */
"while" {return WHILE;}
"(" {return PAREN_I;}
")" {return PAREN_D;}
"pop" {return POPA;}
"push" {return PUSHA;}
"difc" {return DIFC;}
"inter" {return INTE;}
"un" {return UN;} 
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
