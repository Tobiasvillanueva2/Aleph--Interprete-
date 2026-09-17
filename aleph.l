%{
    #include "aleph.tab.h"
    #include "aleph.h"
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
%}

%option noyywrap

%%
"==" {return IGUALIGUAL;}
"!=" {return DISTINTO;}
"=" {return ASIGNACION;}
">" {return MAYOR;}
"<" {return MENOR;}
"pop" {return POPA;}
"push" {return PUSHA;}
"difc" {return DIFC;}
"inter" {return INTE;}
"un" {return UN;} 
"+" {return SUMA;}
"-" {return RESTA;}
"*" {return MULT;}
"/" {return DIV;}
"automata" {return AUTOMATA;}
"analiza" {return ANALIZA;}
"determinizar" {return DETERMINIZAR;}
"esafd" {return ESAFD;}
"pertenece" {return PERTENECE;}
"igual" {return IGUAL;}
"func" {return FUNC;}
"funcvoid" {return FUNCVOID;}
"retorna" {return RETORNA;}
"if" {return IF;}
"else" {return ELSE;}
"while" {return WHILE;}
"{" {return LLAVE_I;}
"}" {return LLAVE_D;}
"[" {return CORCH_I;}
"]" {return CORCH_D;}
"(" {return PAREN_I;}
")" {return PAREN_D;}
"," {return COMA;}
";" {return EOL;}
[ \t\r\n] {}
[0-9]+"."[0-9]+ {yylval.e=strdup(yytext);return IDCADENA;}
[A-Z][A-Z0-9]* {yylval.v=lookup(yytext);return IDVARIABLE;}
[a-zA-Z0-9]+ {yylval.e=strdup(yytext);return IDCADENA;}
. {printf("error");}
%%
