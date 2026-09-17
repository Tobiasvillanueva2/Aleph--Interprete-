#include "aleph.h"

int tipo_dato;

int preguntaType(struct ast *);
int preguntaType2(struct ast *);

struct symbol symtab[9997];

tset retval;
jmp_buf *return_env = NULL;

/* construye un resultado booleano representado como conjunto,
   consistente con esVerdadero(): {} = falso, {verdadero} = verdadero */
static tset newBool(int esCierto)
{
    tset r = newData();
    r->type = SET;
    if (esCierto)
    {
        tset e = newData();
        e->type = STR;
        e->str = strdup("verdadero");
        r->elem = e;
        r->sig = NULL;
    }
    else
    {
        r->elem = NULL;
        r->sig = NULL;
    }
    return r;
}

int esVerdadero(tset v)
{
    if (v == NULL)
        return 0;
    if (v->type == STR)
        return (v->str != NULL && strlen(v->str) > 0);
    return (v->elem != NULL);
}

struct ast *newif(struct ast *cond, struct ast *th, struct ast *el)
{
    struct ifast *a = malloc(sizeof(struct ifast));
    if (!a)
    {
        yyerror("no hay espacio");
        exit(0);
    }
    a->nodetype = IFNODE;
    a->cond = cond;
    a->th = th;
    a->el = el;
    return (struct ast *)a;
}

struct ast *newfunc(struct symbol *s, struct symlist *params, struct ast *body, int esvoid)
{
    struct funcdef *a = malloc(sizeof(struct funcdef));
    if (!a)
    {
        yyerror("no hay espacio");
        exit(0);
    }
    a->nodetype = FUNC_DEF;
    a->s = s;
    a->params = params;
    a->body = body;
    a->esvoid = esvoid;

    s->func = (struct ast *)a;
    s->syms = params;
    s->functype = esvoid ? 2 : 1;

    return (struct ast *)a;
}

struct ast *newcall(struct symbol *s, struct ast *args)
{
    struct funcall *a = malloc(sizeof(struct funcall));
    if (!a)
    {
        yyerror("no hay espacio");
        exit(0);
    }
    a->nodetype = FUNC_CALL;
    a->s = s;
    a->args = args;
    return (struct ast *)a;
}

static unsigned symhash(char *sym)
{
    unsigned int hash = 0;
    unsigned c;

    while (c = *sym++)
        hash = hash * 9 ^ c;

    return hash;
}

struct symbol *lookup(char *sym)
{
    struct symbol *sp = &symtab[symhash(sym) % 9997];
    int scount = NHASH;

    while (--scount >= 0)
    {
        if (sp->name && !strcmp(sp->name, sym))
            return sp;

        if (!sp->name)
        {
            sp->name = strdup(sym);
            sp->value = NULL;
            // sp->func = NULL;
            sp->syms = NULL;
            return sp;
        }

        if (++sp >= symtab + 9997) /* prueba con la siguiente entrada */
            sp = symtab;
    }
    yyerror("la tabla de sÃ­mbolos estÃ¡ agotada\n");
    abort();
}
struct symlist *newsymlist(struct symbol *sym, struct symlist *next)
{
    struct symlist *sl = malloc(sizeof(struct symlist));

    if (!sl)
    {
        yyerror("no hay espacio");
        exit(0);
    }

    sl->sym = sym;
    sl->next = next;
    return sl;
}

struct ast *newref(struct symbol *s)
{
    struct symref *a = malloc(sizeof(struct symref));

    if (!a)
    {
        yyerror("no hay espacio");
        exit(0);
    }

    a->nodetype = REF;
    a->s = s;
    return (struct ast *)a;
}

struct ast *newasgn(struct symbol *s, struct ast *v)
{
    struct symasgn *a = malloc(sizeof(struct symasgn));

    if (!a)
    {
        yyerror("no hay espacio");
        exit(0);
    }

    a->nodetype = ASIG;
    a->s = s;
    a->v = v;
    return (struct ast *)a;
}

struct ast *newast(int nodetype, struct ast *l, struct ast *r)
{
    struct ast *a = malloc(sizeof(struct ast));

    if (!a)
    {
        yyerror("no hay espacio");
        exit(0);
    }

    a->nodetype = nodetype;
    a->l = l;
    a->r = r;
    return a;
}

struct ast *newelem(char *d)
{
    tset a = malloc(sizeof(conjunto));
    char *aux;
    aux = (char *)malloc(sizeof(char) * 255);
    if (!a)
    {
        yyerror("no hay espacio");
        exit(0);
    }

    a->type = ELE;
    strcpy(aux, d);
    a->str = aux;
    return (struct ast *)a;
}

tset eval(struct ast *a)
{ // crear caso SET y caso LIST para ello la variable global
    tset v;
    if (!a)
    {
        yyerror("error interno, evaluacion nula");
        return NULL;
    }
    switch (a->nodetype)
    {
        break;

    case SET:
        tipo_dato = SET;
        v = eval(a->l);
        v = depuracion(v);
        break;

    case LIST:
        tipo_dato = LIST;
        v = eval(a->l);
        break;

    case LIST_E:
        v = newData();
        v->type = tipo_dato;
        v->elem = eval(a->l);
        if (a->r)
        {
            v->sig = eval(a->r);
        }
        break;

    case ELE:
        v = newData();
        v->type = STR;
        v->str = ((struct elemast *)a)->str;
        break;
    case NULOCONJ:
        v = newData();
        v->type = SET;
        v->elem = NULL;
        break;
    case NULOLIST:
        v = newData();
        v->type = LIST;
        v->elem = NULL;
        break;

    case OP_SUMA:
    case OP_RESTA:
    case OP_MULT:
    case OP_DIV:
    {
        tset izq = eval(a->l);
        tset der = eval(a->r);
        int ok = 1;

        if (izq == NULL || der == NULL || izq->type != STR || der->type != STR)
        {
            yyerror("operacion aritmetica: ambos operandos deben ser elementos numericos");
            ok = 0;
            v = NULL;
        }
        else if (strchr(izq->str, '.') != NULL || strchr(der->str, '.') != NULL)
        {
            /* ---- camino NUEVO: al menos un operando tiene '.', se opera en double ---- */
            char *fin1, *fin2;
            double n1, n2, res = 0.0;

            n1 = strtod(izq->str, &fin1);
            n2 = strtod(der->str, &fin2);

            if (*fin1 != '\0' || *fin2 != '\0')
            {
                yyerror("operacion aritmetica: el operando no es un numero valido");
                ok = 0;
            }
            else if (a->nodetype == OP_DIV && n2 == 0.0)
            {
                yyerror("division por cero");
                ok = 0;
            }
            else
            {
                switch (a->nodetype)
                {
                case OP_SUMA: res = n1 + n2; break;
                case OP_RESTA: res = n1 - n2; break;
                case OP_MULT: res = n1 * n2; break;
                case OP_DIV: res = n1 / n2; break;
                }
            }

            if (ok)
            {
                char buf[64];
                sprintf(buf, "%g", res);
                v = newData();
                v->type = STR;
                v->str = strdup(buf);
            }
            else
            {
                v = NULL;
            }
        }
        else
        {
            /* ---- camino EXISTENTE (enteros), sin cambios ---- */
            char *fin1, *fin2;
            long n1 = 0, n2 = 0, res = 0;

            n1 = strtol(izq->str, &fin1, 10);
            n2 = strtol(der->str, &fin2, 10);
            if (*fin1 != '\0' || *fin2 != '\0')
            {
                yyerror("operacion aritmetica: el operando no es un numero entero valido");
                ok = 0;
            }
            else if (a->nodetype == OP_DIV && n2 == 0)
            {
                yyerror("division por cero");
                ok = 0;
            }
            else
            {
                switch (a->nodetype)
                {
                case OP_SUMA: res = n1 + n2; break;
                case OP_RESTA: res = n1 - n2; break;
                case OP_MULT: res = n1 * n2; break;
                case OP_DIV: res = n1 / n2; break;
                }
            }

            if (ok)
            {
                char buf[32];
                sprintf(buf, "%ld", res);
                v = newData();
                v->type = STR;
                v->str = strdup(buf);
            }
            else
            {
                v = NULL;
            }
        }
    }
    break;

    case OP_NEG:
    {
        tset operando = eval(a->l);

        if (operando == NULL || operando->type != STR)
        {
            yyerror("negacion: el operando debe ser un elemento numerico");
            v = NULL;
            break;
        }

        if (strchr(operando->str, '.') != NULL)
        {
            char *fin;
            double n = strtod(operando->str, &fin);
            if (*fin != '\0')
            {
                yyerror("negacion: el operando no es un numero valido");
                v = NULL;
                break;
            }
            char buf[64];
            sprintf(buf, "%g", -n);
            v = newData();
            v->type = STR;
            v->str = strdup(buf);
            break;
        }

        char *fin;
        long n = strtol(operando->str, &fin, 10);
        if (*fin != '\0')
        {
            yyerror("negacion: el operando no es un numero entero valido");
            v = NULL;
            break;
        }
        {
            char buf[32];
            sprintf(buf, "%ld", -n);
            v = newData();
            v->type = STR;
            v->str = strdup(buf);
        }
    }
    break;

    case CONSTRUYE_AF:
    {
        /* a->l es la cadena LIST_E de argumentos: estados,alfabeto,trans,ini,fin */
        struct ast *args = a->l;
        tset partes[5];
        int i = 0;
        while (args != NULL && i < 5)
        {
            partes[i] = eval(args->l);
            args = args->r;
            i++;
        }
        if (i != 5 || args != NULL)
        {
            yyerror("automata: se esperan exactamente 5 argumentos (estados,alfabeto,trans,ini,fin)");
            v = NULL;
        }
        else
        {
            tAutomata af = creaAF(partes[0], partes[1], partes[2], partes[3], partes[4]);
            v = empaquetarAF(af);
        }
    }
    break;

    case ANALIZA_AF:
    {
        tset afTset = eval(a->l);
        tset cadTset = eval(a->r);
        if (afTset == NULL || cadTset == NULL || cadTset->type != STR)
        {
            yyerror("analiza: argumentos invalidos (se espera un automata y un elemento)");
            v = newBool(0);
        }
        else
        {
            tAutomata af = desempaquetarAF(afTset);
            int acepta = analizaCadAF(af, af.ini, cadTset->str);
            v = newBool(acepta);
        }
    }
    break;

    case DETERMINIZAR_AF:
    {
        tset afTset = eval(a->l);
        if (afTset == NULL)
        {
            yyerror("determinizar: automata invalido");
            v = NULL;
        }
        else
        {
            tAutomata af = desempaquetarAF(afTset);
            tAutomata afd = transformarAFND(af);
            v = empaquetarAF(afd);
        }
    }
    break;

    case ESAFD_AF:
    {
        tset afTset = eval(a->l);
        if (afTset == NULL)
        {
            yyerror("esafd: automata invalido");
            v = newBool(0);
        }
        else
        {
            tAutomata af = desempaquetarAF(afTset);
            int tipo = comoEsAF(af);
            v = newBool(tipo == 0);
        }
    }
    break;

    case CMP_MAYOR:
    case CMP_MENOR:
    {
        tset izq = eval(a->l);
        tset der = eval(a->r);
        char *fin1, *fin2;
        double n1, n2;

        if (izq == NULL || der == NULL || izq->type != STR || der->type != STR)
        {
            yyerror("comparacion: ambos operandos deben ser elementos numericos");
            v = newBool(0);
            break;
        }
        n1 = strtod(izq->str, &fin1);
        n2 = strtod(der->str, &fin2);
        if (*fin1 != '\0' || *fin2 != '\0')
        {
            yyerror("comparacion: el operando no es un numero valido");
            v = newBool(0);
            break;
        }
        v = newBool(a->nodetype == CMP_MAYOR ? (n1 > n2) : (n1 < n2));
    }
    break;

    case CMP_IGUALIGUAL:
    case CMP_DISTINTO:
    {
        tset izq = eval(a->l);
        tset der = eval(a->r);
        int iguales;
        int esNumerico = (izq != NULL && der != NULL && izq->type == STR && der->type == STR);

        if (esNumerico)
        {
            char *fin1, *fin2;
            double n1 = strtod(izq->str, &fin1);
            double n2 = strtod(der->str, &fin2);
            if (*fin1 == '\0' && *fin2 == '\0')
            {
                iguales = (n1 == n2);
            }
            else
            {
                /* alguno no era un numero valido: comparar como string/estructura */
                iguales = (izq == NULL || der == NULL) ? (izq == der) : (isEqual(izq, der) == 0);
            }
        }
        else
        {
            iguales = (izq == NULL || der == NULL) ? (izq == der) : (isEqual(izq, der) == 0);
        }
        v = newBool(a->nodetype == CMP_IGUALIGUAL ? iguales : !iguales);
    }
    break;

    case CMP_PERTENECE:
    {
        tset elem = eval(a->l);
        tset cont = eval(a->r);
        if (elem == NULL || elem->type != STR)
        {
            yyerror("pertenece: el operando izquierdo debe ser un elemento (string)");
            v = newBool(0);
        }
        else
        {
            int encontrado = In(cont, elem->str);
            v = newBool(encontrado == 0);
        }
    }
    break;

    case CMP_IGUAL:
    {
        tset izq = eval(a->l);
        tset der = eval(a->r);
        int iguales = (izq == NULL || der == NULL) ? (izq == der) : (isEqual(izq, der) == 0);
        v = newBool(iguales);
    }
    break;

    case LIST_STMT:
        v = eval(a->l);
        if (a->r)
            v = eval(a->r);
        break;

    case IFNODE:
    {
        struct ifast *ifa = (struct ifast *)a;
        tset condv = eval(ifa->cond);
        if (esVerdadero(condv))
            v = ifa->th ? eval(ifa->th) : NULL;
        else
            v = ifa->el ? eval(ifa->el) : NULL;
    }
    break;

    case OP_WHILE:
        v = NULL;
        while (esVerdadero(eval(a->l)))
        {
            v = eval(a->r);
        }
        break;

    case RETURN:
        retval = a->l ? eval(a->l) : NULL;
        if (return_env)
            longjmp(*return_env, 1);
        else
            yyerror("retorna fuera de una funcion");
        break;

    case FUNC_DEF:
        v = NULL;
        break;

    case FUNC_CALL:
    {
        struct funcall *fc = (struct funcall *)a;
        struct symbol *fs = fc->s;

        if (fs->func == NULL)
        {
            yyerror("funcion no definida");
            v = NULL;
            break;
        }

        struct funcdef *fd = (struct funcdef *)fs->func;
        struct symlist *sl = fd->params;
        struct ast *argexpr = fc->args;

#define MAX_PARAMS 32
        struct symbol *psyms[MAX_PARAMS];
        tset poldval[MAX_PARAMS];
        int nparams = 0;

        while (sl != NULL)
        {
            tset argv = NULL;
            if (argexpr != NULL)
            {
                argv = eval(argexpr->l);
                argexpr = argexpr->r;
            }
            else
            {
                yyerror("faltan argumentos en la llamada");
            }
            psyms[nparams] = sl->sym;
            poldval[nparams] = sl->sym->value;
            sl->sym->value = argv;
            nparams++;
            sl = sl->next;
        }

        if (argexpr != NULL)
        {
            yyerror("demasiados argumentos en la llamada");
        }

        jmp_buf aqui;
        jmp_buf *anterior_env = return_env;
        return_env = &aqui;

        if (setjmp(aqui) == 0)
        {
            v = eval(fd->body);
        }
        else
        {
            v = retval;
        }

        return_env = anterior_env;

        for (int i = 0; i < nparams; i++)
        {
            psyms[i]->value = poldval[i];
        }

        if (fd->esvoid)
            v = NULL;
    }
    break;

    /*operaciones de listas*/
    case OP_POP:
        tset aux;

        aux = eval(a->l);

        if (aux != NULL && aux->type == LIST)
        {
            // 2. Si la evaluación fue exitosa y el tipo es LIST

            //printf("  Lista antes de POP: ");
            //printData(aux);
            //printf("\n");

            // 3. Ejecuta la operación
            v = POP(&aux);

            // 4. Imprime el resultado


        }
        else
        {
            v = NULL;
        }

        fflush(stdout);
        break;


    case OP_PUSH:

        tset listap = eval(a->l);
        tset elemento = eval(a->r);
        if (listap != NULL && listap->type == 2 && elemento != NULL){
            v = Carga_Cola(listap, elemento);
        }
        else
            {
                printf("\n error valores incorrectos \n");
                v = NULL;
            }

        break;

    /* operacionies conjunto */
    case OP_UN:
        //printf("Union\n");

        tset izq = eval(a->l);
        tset der = eval(a->r);
        if (izq != NULL && der != NULL && izq->type == SET && der->type == SET)
        {
            //printf("Primer conjunto\n");
            //printData(izq);

            //printf("\nSegundo Conjunto\n");
            //printData(der);

            // 3. REALIZAR LA OPERACIÓN
            v = U(izq, der); // Usar U, no UNION
            //printf("\nResultado\n");
            //printData(v);
        }
        // Si falla el chequeo de tipos (o si eval devolvió NULL):
        else
        {
            printf("\n error valores incorrectos (Tipos incompatibles o nulos) \n");
            v = NULL;
        }

        break;

    case OP_INTE:
        {
        //printf("Inteseccion");
        tset izq = eval(a->l);
        tset der = eval(a->r);
        if (izq != NULL && der != NULL && izq->type == SET && der->type == SET)
        {
            // 3. REALIZAR LA OPERACIÓN
            v = INTER(izq, der);

            if (v == NULL)
            {
                // Crea un nuevo contenedor para el conjunto vacío
                v = newData();
                v->type = SET; // Asumo que 3 es SET, pero si no, usa el tipo correcto
                v->elem = NULL;
            }
        }
        else // Si falla el chequeo de tipos/punteros nulos:
        {
            printf("\n error valores incorrectos (Tipos incompatibles o nulos) \n");
            v = NULL;
        }
        }   

        break;

    case OP_DIFC:
        {
        //printf("Diferencia");

        tset izq = eval(a->l);
        tset der = eval(a->r);
        if (izq != NULL && der != NULL && izq->type == SET && der->type == SET)
        {
            // 3. REALIZAR LA OPERACIÓN
            v = DIFF(izq, der);

            if (v == NULL)
            {
                // Crea un nuevo contenedor para el conjunto vacío
                v = newData();
                v->type = SET;
                v->elem = NULL;
            }
        }
        else // Si falla el chequeo de tipos/punteros nulos:
        {
            printf("\n error valores incorrectos (Tipos incompatibles o nulos) \n");
            v = NULL;
        }
        }

        break;

    /* expresiones */
    case REF:
        struct symbol *aux2;
        aux2 = ((struct symref *)a)->s;
        v = aux2->value;
        break;

    case ASIG:
        //printf("Usando AS");
        struct symbol *aux3;
        aux3 = ((struct symasgn *)a)->s;
        v = aux3->value = eval(((struct symasgn *)a)->v);
        break;

    case M_ASIG:
        //printf("Usando AM");
        struct ast *LIDENT;
        struct ast *LEXPR;
        struct symbol *aux4;
        tset kk;
        LIDENT = a->l;
        LEXPR = a->r;
        v = NULL;
        while (LIDENT != NULL && LEXPR != NULL)
        {
            tset resultado;
            aux4 = ((struct symref *)LIDENT->l)->s;
            resultado = eval(LEXPR->l);
            aux4->value=resultado;
            //v = resultado;
            LIDENT = LIDENT->r;
            LEXPR = LEXPR->r;
        }
        break;

    }
    return v;
}

int preguntaType(struct ast *a)
{
    int v;
    switch (a->l->nodetype)
    {
    case LIST:
        switch (a->r->nodetype)
        {
        case LIST: // a->l->LIST && a->r->LISt
            v = 1;
            break;

        case REF: // a->l->LIST && a->r>REF
            if (((struct symref *)a->r)->s->value != NULL)
            {
                if (((struct symref *)a->r)->s->value->type == LIST)
                {
                    v = 1;
                }
                else
                {
                    // printf("\n Error la 2da expresion no es lista");
                    v = 0;
                }
            }
            else
            {
                // printf("\n Error la 2da expresion es NULL");
                v = 0;
            }
            break;

        case OP_POP:
        case OP_PUSH:
            tset interior2;
            interior2 = eval(a->r);
            if (interior2->type == LIST)
            {
                v = 1;
            }
            else
            {
                v = 0;
            }
            break;

        default:
            // printf("\n Error la 2da expresion es cualqueir cosa");
            v = 0;
            break;
        }
        break;

    case REF:
        if (((struct symref *)a->l)->s->value != NULL)
        {
            if (((struct symref *)a->l)->s->value->type == LIST)
            {
                switch (a->r->nodetype)
                {
                case LIST: // a->l->REF && a->r->LISt
                    v = 1;
                    break;

                case REF: // a->l->REF && a->r>REF
                    if (((struct symref *)a->r)->s->value != NULL)
                    {
                        if (((struct symref *)a->r)->s->value->type == LIST)
                        {
                            v = 1;
                        }
                        else
                        {
                            // printf("\n Error la 2da expresion no es lista");
                            v = 0;
                        }
                    }
                    else
                    {
                        // printf("\n Error la 2da expresion es NULL");
                        v = 0;
                    }
                    break;

                case OP_POP:
                case OP_PUSH:
                    tset interior2;
                    interior2 = eval(a->r);
                    if (interior2->type == LIST)
                    {
                        v = 1;
                    }
                    else
                    {
                        v = 0;
                    }
                    break;

                default:
                    // printf("\n Error la 2da expresion es cualqueir cosa");
                    v = 0;
                    break;
                }
            }
            else
            {
                // printf("\n Error la 1ra expresion es un conjunto");
                v = 0;
            }
        }
        else
        {
            // printf("\n Error la 1ra expresion es NULL");
            v = 0;
        }
        break;
    case OP_POP:
    case OP_PUSH:
        tset interior;
        interior = eval(a->l);
        if (interior->type == LIST)
        {
            switch (a->r->nodetype)
            {
            case LIST: // a->l->LIST && a->r->LISt
                v = 1;
                break;

            case REF: // a->l->LIST && a->r>REF
                if (((struct symref *)a->r)->s->value != NULL)
                {
                    if (((struct symref *)a->r)->s->value->type == LIST)
                    {
                        v = 1;
                    }
                    else
                    {
                        // printf("\n Error la 2da expresion no es lista");
                        v = 0;
                    }
                }
                else
                {
                    // printf("\n Error la 2da expresion es NULL");
                    v = 0;
                }
                break;
            case OP_POP:
            case OP_PUSH:
                tset interior2;
                interior2 = eval(a->r);
                if (interior2->type == LIST)
                {
                    v = 1;
                }
                else
                {
                    v = 0;
                }
                break;
            default:
                // printf("\n Error la 2da expresion es cualqueir cosa");
                v = 0;
                break;
            }
        }
        else
        {
            v = 0;
        }
        break;
    default:
        // printf("\n Error la 1ra exprecion es %d",a->l->nodetype);
        v = 0;
        break;
    }
    return v;
}
int preguntaType2(struct ast *a)
{
    int v;
    switch (a->l->nodetype)
    {
    case SET:
        switch (a->r->nodetype)
        {
        case SET: // a->l->LIST && a->r->LISt
            v = 1;
            break;

        case REF: // a->l->LIST && a->r>REF
            if (((struct symref *)a->r)->s->value != NULL)
            {
                if (((struct symref *)a->r)->s->value->type == SET)
                {
                    v = 1;
                }
                else
                {
                    // printf("\n Error la 2da expresion no es lista");
                    v = 0;
                }
            }
            else
            {
                // printf("\n Error la 2da expresion es NULL");
                v = 0;
            }
            break;
        case OP_DIFC:

        case OP_INTE:

        case OP_UN:
            tset interior2;
            interior2 = eval(a->r);
            if (interior2->type == SET)
            {
                v = 1;
            }
            else
            {
                v = 0;
            }
            break;
        default:
            // printf("\n Error la 2da expresion es cualqueir cosa");
            v = 0;
            break;
        }
        break;

    case REF:
        if (((struct symref *)a->l)->s->value != NULL)
        {
            if (((struct symref *)a->l)->s->value->type == SET)
            {
                switch (a->r->nodetype)
                {
                case SET:
                    v = 1;
                    break;

                case REF:
                    if (((struct symref *)a->r)->s->value != NULL)
                    {
                        if (((struct symref *)a->r)->s->value->type == SET)
                        {
                            v = 1;
                        }
                        else
                        {
                            v = 0;
                        }
                    }
                    else
                    {
                        v = 0;
                    }
                    break;
                case OP_DIFC:

                case OP_INTE:

                case OP_UN:
                    tset interior2;
                    interior2 = eval(a->r);
                    if (interior2->type == SET)
                    {
                        v = 1;
                    }
                    else
                    {
                        v = 0;
                    }
                    break;
                default:
                    v = 0;
                    break;
                }
            }
            else
            {
                v = 0;
            }
        }
        else
        {
            v = 0;
        }
        break;
    case OP_DIFC:

    case OP_INTE:

    case OP_UN:
        tset interior;
        interior = eval(a->l);
        if (interior->type == SET)
        {
            switch (a->r->nodetype)
            {
            case SET: // a->l->LIST && a->r->LISt
                v = 1;
                break;

            case REF: // a->l->LIST && a->r>REF
                if (((struct symref *)a->r)->s->value != NULL)
                {
                    if (((struct symref *)a->r)->s->value->type == SET)
                    {
                        v = 1;
                    }
                    else
                    {
                        // printf("\n Error la 2da expresion no es lista");
                        v = 0;
                    }
                }
                else
                {
                    // printf("\n Error la 2da expresion es NULL");
                    v = 0;
                }
                break;
            case OP_DIFC:

            case OP_INTE:

            case OP_UN:
                tset interior2;
                interior2 = eval(a->r);
                if (interior2->type == SET)
                {
                    v = 1;
                }
                else
                {
                    v = 0;
                }
                break;
            default:
                // printf("\n Error la 2da expresion es cualqueir cosa");
                v = 0;
                break;
            }
        }
        else
        {
            v = 0;
        }
        break;
    default:
        v = 0;
        break;
    }
    return v;
}