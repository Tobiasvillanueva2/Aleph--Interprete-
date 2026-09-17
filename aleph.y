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
    struct symlist *sl;
}
%token <v> IDVARIABLE
%token <e> IDCADENA
%token ASIGNACION
%token COMA
%token LLAVE_I LLAVE_D CORCH_I CORCH_D
%token INTE UN DIFC POPA PUSHA
%token FUNC FUNCVOID RETORNA IF ELSE WHILE
%token PERTENECE IGUAL
%token SUMA RESTA MULT DIV
%token MAYOR MENOR IGUALIGUAL DISTINTO
%token AUTOMATA ANALIZA DETERMINIZAR ESAFD
%token PAREN_I PAREN_D
%token EOL

%type <a> list_expr expr lit_list lit_conj sentencia operaciones  op_conj op_list op_num op_rel asignacion list_asig
%type <a> func_def bloque lista_sent ctrl_stmt if_sent while_sent retorna_sent llamada arg_list
%type <sl> param_list

%left UN DIFC
%left INTE
%left PERTENECE IGUAL
%left MAYOR MENOR IGUALIGUAL DISTINTO
%left SUMA RESTA
%left MULT DIV
%left POPA PUSHA

%%
aleph: aleph sentencia EOL {salida=eval($2);if (salida)muestra(salida); printf("\n");}
|sentencia EOL  {salida=eval($1);if (salida)muestra(salida);printf("\n");}
|aleph func_def   {eval($2);}
|func_def         {eval($1);}
|aleph ctrl_stmt  {eval($2);}
|ctrl_stmt        {eval($1);}
;

sentencia: expr
|asignacion
|retorna_sent
;

retorna_sent: RETORNA expr {$$=newast(RETURN,$2,NULL);}
|RETORNA {$$=newast(RETURN,NULL,NULL);}
;

expr:IDCADENA    {$$=newelem($1);}   
|lit_conj          
|lit_list
|operaciones 
|llamada
|PAREN_I expr PAREN_D {$$=$2;}
|AUTOMATA PAREN_I arg_list PAREN_D          {$$=newast(CONSTRUYE_AF,$3,NULL);}
|ANALIZA PAREN_I expr COMA expr PAREN_D     {$$=newast(ANALIZA_AF,$3,$5);}
|DETERMINIZAR PAREN_I expr PAREN_D          {$$=newast(DETERMINIZAR_AF,$3,NULL);}
|ESAFD PAREN_I expr PAREN_D                 {$$=newast(ESAFD_AF,$3,NULL);}
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
|op_num
|op_rel
;

op_num: expr SUMA expr {$$=newast(OP_SUMA,$1,$3);}
|expr RESTA expr       {$$=newast(OP_RESTA,$1,$3);}
|expr MULT expr        {$$=newast(OP_MULT,$1,$3);}
|expr DIV expr         {$$=newast(OP_DIV,$1,$3);}
;

op_rel: expr MAYOR expr      {$$=newast(CMP_MAYOR,$1,$3);}
|expr MENOR expr             {$$=newast(CMP_MENOR,$1,$3);}
|expr IGUALIGUAL expr        {$$=newast(CMP_IGUALIGUAL,$1,$3);}
|expr DISTINTO expr          {$$=newast(CMP_DISTINTO,$1,$3);}
;

op_conj: expr UN expr   {$$=newast(OP_UN,$1,$3);}
| expr INTE expr    {$$=newast(OP_INTE,$1,$3);}
| expr DIFC expr    {$$=newast(OP_DIFC,$1,$3);}
| expr PERTENECE expr {$$=newast(CMP_PERTENECE,$1,$3);}
| expr IGUAL expr     {$$=newast(CMP_IGUAL,$1,$3);}
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

/* ---- NUEVO: bloques y control de flujo ---- */

bloque: LLAVE_I lista_sent LLAVE_D {$$=$2;}
;

lista_sent: sentencia EOL lista_sent {$$=newast(LIST_STMT,$1,$3);}
|sentencia EOL                        {$$=newast(LIST_STMT,$1,NULL);}
|ctrl_stmt lista_sent                 {$$=newast(LIST_STMT,$1,$2);}
|ctrl_stmt                            {$$=newast(LIST_STMT,$1,NULL);}
;

ctrl_stmt: if_sent
|while_sent
;

if_sent: IF PAREN_I expr PAREN_D bloque             {$$=newif($3,$5,NULL);}
|IF PAREN_I expr PAREN_D bloque ELSE bloque         {$$=newif($3,$5,$7);}
;

while_sent: WHILE PAREN_I expr PAREN_D bloque {$$=newast(OP_WHILE,$3,$5);}
;

/* ---- NUEVO: funciones ---- */

func_def: FUNC IDVARIABLE PAREN_I param_list PAREN_D bloque      {$$=newfunc($2,$4,$6,0);}
|FUNC IDVARIABLE PAREN_I PAREN_D bloque                          {$$=newfunc($2,NULL,$5,0);}
|FUNCVOID IDVARIABLE PAREN_I param_list PAREN_D bloque           {$$=newfunc($2,$4,$6,1);}
|FUNCVOID IDVARIABLE PAREN_I PAREN_D bloque                      {$$=newfunc($2,NULL,$5,1);}
;

param_list: IDVARIABLE                  {$$=newsymlist($1,NULL);}
|IDVARIABLE COMA param_list             {$$=newsymlist($1,$3);}
;

llamada: IDVARIABLE PAREN_I arg_list PAREN_D {$$=newcall($1,$3);}
|IDVARIABLE PAREN_I PAREN_D                  {$$=newcall($1,NULL);}
;

arg_list: expr COMA arg_list {$$=newast(LIST_E,$1,$3);}
|expr                        {$$=newast(LIST_E,$1,NULL);}
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
