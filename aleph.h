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

extern int yylineno;
void yyerror(char *s);

struct symbol
{
    char *name;
    tset value;
    // struct ast *func;
    struct symlist *syms;
};
struct symlist
{
    struct symbol *sym;
    struct symlist *next;
};

#define NHASH 9997;

struct symbol *lookup(char *);

struct ast
{
    int nodetype;
    struct ast *l;
    struct ast *r;
};
struct symref
{
    int nodetype; /* tipo N */
    struct symbol *s;
};

struct symasgn
{
    int nodetype; /* tipo = */
    struct symbol *s;
    struct ast *v; /* valor */
};

struct elemast
{                 // numval cambiado
    int nodetype; /* tipo K */
    char *str;    /*esto se modifico de un doble a un char* */
};

struct symlist *newsymlist(struct symbol *sym, struct symlist *next);

struct symbol *lookup(char *sym);
struct ast *newast(int nodetype, struct ast *l, struct ast *r);
struct ast *newelem(char *d);
struct ast *newref(struct symbol *s);
struct ast *newasgn(struct symbol *s, struct ast *v);
tset eval(struct ast *); /*se cambio de un dobule*/

struct ast *newastI(int nodetype, struct symbol *l, struct ast *r);
