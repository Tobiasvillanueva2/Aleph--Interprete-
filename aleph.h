#include "conjunto.h"

#define STR 1
#define LIST 2
#define SET 3

#define EXPR 4
#define ELE 5
#define LIST_E 6
#define NULO 7
#define OP_POP 8
#define OP_PUSH 9
#define OP_UN 10
#define OP_INTE 11
#define OP_DIFC 12
#define REF 13
#define ASIG 14
#define M_ASIG 15
#define L_IDVAR 16
#define NULOCONJ 17
#define NULOLIST 18

/* Nuevos nodos para funciones y control de flujo */
#define N_DEF 19
#define N_CALL 20
#define N_FUNARGS 21
#define N_BLOCK 22
#define N_IF 23
#define N_WHILE 24
#define N_RETURN 25


extern int yylineno;
void yyerror(char *s);

struct flowast {
    int nodetype;             /* Estrictamente el mismo int de tu struct ast */
    struct ast *cond;         /* Condición a evaluar */
    struct ast *true_branch;  /* Rama principal */
    struct ast *false_branch; /* Rama else (o NULL) */
};


struct ast *newflow(int nodetype, struct ast *cond, struct ast *t_branch, struct ast *f_branch);


struct symbol
{
    char *name;
    tset value;
    struct ast *func;     /* Descomentado para almacenar el AST de la funcion */
    struct symlist *syms; /* Descomentado para la lista de parametros */
};

struct symlist
{
    struct symbol *sym;
    struct symlist *next;
};

#define NHASH 9997

struct symbol *lookup(char *);

struct ast
{
    int nodetype;
    struct ast *l;
    struct ast *r;
};

struct symref
{
    int nodetype; 
    struct symbol *s;
};

struct symasgn
{
    int nodetype; 
    struct symbol *s;
    struct ast *v; 
};

struct elemast
{                 
    int nodetype; 
    char *str;    
};

struct symlist *newsymlist(struct symbol *sym, struct symlist *next);
struct symbol *lookup(char *sym);
struct ast *newast(int nodetype, struct ast *l, struct ast *r);
struct ast *newelem(char *d);
struct ast *newref(struct symbol *s);
struct ast *newasgn(struct symbol *s, struct ast *v);
tset eval(struct ast *); 
struct ast *newastI(int nodetype, struct symbol *l, struct ast *r);
void free_ast(struct ast *a);