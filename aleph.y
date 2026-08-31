%{
#include <stdio.h>
#include "aleph.h"
void yyerror(char *s);
extern int yylex();
tset salida;
%}
%union{
    struct symbol* v;
    struct ast *a;
    char* e;
}
%token <v> IDVARIABLE
%token <e> IDCADENA
%token ASIGNACION
%token COMA
%token LLAVE_I LLAVE_D CORCH_I CORCH_D
%token INTE UN DIFC POPA PUSHA
%token EOL

%type <a> list_expr expr lit_list lit_conj sentencia operaciones  op_conj op_list asignacion list_asig

%left UN DIFC
%left INTE
%left POPA PUSHA

%%
aleph: aleph sentencia EOL {salida=eval($2);if (salida)muestra(salida); printf("\n");}
|sentencia EOL  {salida=eval($1);if (salida)muestra(salida);printf("\n");}
;

sentencia: expr
|asignacion
;

expr:IDCADENA    {$$=newelem($1);}   
|lit_conj          
|lit_list
|operaciones 
|IDVARIABLE          {$$=newref($1);}
;


asignacion:
    list_asig ASIGNACION list_expr {$$=newast(M_ASIG,$1,$3);}
//!hay problema con el list_expr por ast

list_asig: 
    IDVARIABLE   {$$=newast(L_IDVAR,newref($1),NULL);}
    | IDVARIABLE COMA list_asig     {$$=newast(L_IDVAR,newref($1),$3);}

operaciones: op_conj
|op_list
;

op_conj: expr UN expr   {$$=newast(OP_UN,$1,$3);}
| expr INTE expr    {$$=newast(OP_INTE,$1,$3);}
| expr DIFC expr    {$$=newast(OP_DIFC,$1,$3);}
;

op_list: POPA expr {$$=newast(OP_POP,$2,NULL);}
|expr PUSHA expr   {$$=newast(OP_PUSH,$1,$3);}
;

lit_conj:LLAVE_I list_expr LLAVE_D      {$$=newast(SET,$2,NULL);}
|LLAVE_I LLAVE_D        {$$=newast(NULOCONJ,NULL,NULL);}
;

lit_list:CORCH_I list_expr CORCH_D      {$$=newast(LIST,$2,NULL);}
|CORCH_I CORCH_D        {$$=newast(NULOLIST,NULL,NULL);}
;

list_expr: expr COMA list_expr {$$=newast(LIST_E,$1,$3);}
|expr {$$=newast(LIST_E,$1,NULL);}
;

    ;
%%
int main(int argc, char **argv)
{
    yyparse();
}
void yyerror(char *s)
{
    fprintf(stderr, "error: %s\n", s);
}
