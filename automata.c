#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "automata.h"

/* tipos de nodo de conjunto.h: 1 = STR, 2 = LIST, 3 = SET */
#define AF_STR 1
#define AF_LIST 2
#define AF_SET 3

/* ==================================================================
   Capa de adaptacion sobre conjunto.c

   conjunto.c tiene convenciones propias que conviene normalizar antes
   de construir el automata encima:
     - isEqual() devuelve 0 cuando son iguales (y explota con NULL)
     - isEmpty() solo mira si el puntero es NULL, no si esta vacio
     - returnElem() es 1-based
     - SIZEL() esta declarada pero no implementada
     - PUSH() no actualiza la lista del llamador
   ================================================================== */

tset nuevoConjAF()
{
    tset n = newData();
    n->type = AF_SET;
    n->elem = NULL;
    n->sig = NULL;
    return n;
}

tset nuevaListaAF()
{
    tset n = newData();
    n->type = AF_LIST;
    n->elem = NULL;
    n->sig = NULL;
    return n;
}

tset nuevoElemAF(char *c)
{
    tset n = newData();
    n->type = AF_STR;
    n->str = strdup(c);
    return n;
}

int esVacioAF(tset d)
{
    if (d == NULL)
        return 1;
    if (d->type == AF_STR)
        return (d->str == NULL || d->str[0] == '\0');
    return (d->elem == NULL);
}

int cantAF(tset d)
{
    int cont = 0;
    if (esVacioAF(d))
        return 0;
    while (d != NULL)
    {
        cont++;
        d = d->sig;
    }
    return cont;
}

tset elemAF(tset d, int pos)
{
    int cont = 0;
    if (d == NULL || pos < 0 || esVacioAF(d))
        return NULL;
    while (d != NULL && cont < pos)
    {
        cont++;
        d = d->sig;
    }
    if (d == NULL)
        return NULL;
    return d->elem;
}

void pushAF(tset *L, tset elem)
{
    tset aux, nue;
    if (L == NULL || elem == NULL)
        return;
    if (*L == NULL)
    {
        *L = nuevaListaAF();
    }
    if ((*L)->elem == NULL)
    {
        (*L)->elem = elem;
        (*L)->sig = NULL;
        return;
    }
    aux = *L;
    while (aux->sig != NULL)
        aux = aux->sig;
    nue = newData();
    nue->type = aux->type;
    nue->elem = elem;
    nue->sig = NULL;
    aux->sig = nue;
}

int igualAF(tset a, tset b)
{
    int va, vb;
    va = esVacioAF(a);
    vb = esVacioAF(b);
    if (va && vb)
        return 1;
    if (va || vb)
        return 0;
    if (a->type != b->type)
        return 0;
    if (a->type == AF_STR)
        return (strcmp(a->str, b->str) == 0);
    /* isEqual() de conjunto.c devuelve 0 cuando son iguales */
    return (isEqual(a, b) == 0);
}

int perteneceAF(tset coleccion, tset x)
{
    int i, n;
    n = cantAF(coleccion);
    for (i = 0; i < n; i++)
    {
        if (igualAF(elemAF(coleccion, i), x))
            return 1;
    }
    return 0;
}

/* agrega una copia de x al SET res si todavia no estaba */
static void agregaSiNoEstaAF(tset res, tset x)
{
    tset aux, nue;
    if (x == NULL || res == NULL)
        return;
    if (perteneceAF(res, x))
        return;
    if (res->elem == NULL)
    {
        res->elem = DeepCopyTset(x);
        res->sig = NULL;
        return;
    }
    aux = res;
    while (aux->sig != NULL)
        aux = aux->sig;
    nue = newData();
    nue->type = res->type;
    nue->elem = DeepCopyTset(x);
    nue->sig = NULL;
    aux->sig = nue;
}

tset unirAF(tset A, tset B)
{
    tset res = nuevoConjAF();
    int i, n;
    n = cantAF(A);
    for (i = 0; i < n; i++)
        agregaSiNoEstaAF(res, elemAF(A, i));
    n = cantAF(B);
    for (i = 0; i < n; i++)
        agregaSiNoEstaAF(res, elemAF(B, i));
    return res;
}

tset interAF(tset A, tset B)
{
    tset res = nuevoConjAF();
    int i, n;
    n = cantAF(A);
    for (i = 0; i < n; i++)
    {
        tset x = elemAF(A, i);
        if (perteneceAF(B, x))
            agregaSiNoEstaAF(res, x);
    }
    return res;
}

/* ==================================================================
   Operaciones del automata
   ================================================================== */

void iniciaAF(tAutomata *AF)
{
    AF->estados = nuevaListaAF();
    AF->alfabeto = nuevaListaAF();
    AF->trans = nuevaListaAF();
    AF->ini = nuevoConjAF();
    AF->fin = nuevoConjAF();
}

int llenoAF(tAutomata af)
{
    if (esVacioAF(af.estados) || esVacioAF(af.alfabeto) || esVacioAF(af.trans) ||
        esVacioAF(af.ini) || esVacioAF(af.fin))
        return 0;
    return 1;
}

void vaciarAF(tAutomata *af)
{
    af->estados = NULL;
    af->alfabeto = NULL;
    af->trans = NULL;
    af->ini = NULL;
    af->fin = NULL;
}

tAutomata creaAF(tset estados, tset alfabeto, tset trans, tset ini, tset fin)
{
    tAutomata nvo;
    nvo.estados = estados;
    nvo.alfabeto = alfabeto;
    nvo.trans = trans;
    nvo.ini = ini;
    nvo.fin = fin;
    return nvo;
}

void mostrarAF(tAutomata a)
{
    printf("\nAUTOMATA\n");
    printf("Estados: ");
    muestra(a.estados);
    printf("\nAlfabeto: ");
    muestra(a.alfabeto);
    printf("\nTransiciones: ");
    muestra(a.trans);
    printf("\nInicial: ");
    muestra(a.ini);
    printf("\nAceptacion: ");
    muestra(a.fin);
    printf("\n");
}

tset creaTransAF(tset partidaS, tset sim, tset llegadaS)
{
    tset upla = nuevaListaAF();
    pushAF(&upla, partidaS);
    pushAF(&upla, sim);
    pushAF(&upla, llegadaS);
    return upla;
}

int comoEsAF(tAutomata a)
{
    int j, n, b = 0;
    if (esVacioAF(a.trans))
        return -1;
    n = cantAF(a.trans);
    for (j = 0; j < n && b == 0; j++)
    {
        tset upla = elemAF(a.trans, j);
        tset destino;
        if (upla == NULL)
            continue;
        destino = elemAF(upla, 2);
        if (destino == NULL || esVacioAF(destino))
            b = 1;
        else if (cantAF(destino) > 1)
            b = 1;
    }
    return b;
}

tset transicionAF(tset deltaL, tset qSet, char alf)
{
    tset destino = nuevoConjAF();
    int i, j, nq, nt;

    if (esVacioAF(deltaL) || esVacioAF(qSet))
        return destino;

    nq = cantAF(qSet);
    nt = cantAF(deltaL);
    for (j = 0; j < nq; j++)
    {
        tset estadoAct = elemAF(qSet, j);
        if (estadoAct == NULL)
            continue;
        for (i = 0; i < nt; i++)
        {
            tset upla = elemAF(deltaL, i);
            tset partida, sim, llegada, tmp;
            if (upla == NULL)
                continue;
            partida = elemAF(upla, 0);
            sim = elemAF(upla, 1);
            llegada = elemAF(upla, 2);
            if (partida == NULL || sim == NULL || llegada == NULL)
                continue;
            if (sim->type != AF_STR)
                continue;
            /* igualAF() permite que un estado sea un atomo (AFND) o un
               conjunto de atomos (AFD determinizado), de forma uniforme */
            if (igualAF(partida, estadoAct) && sim->str[0] == alf)
            {
                tmp = unirAF(destino, llegada);
                destino = tmp;
            }
        }
    }
    return destino;
}

int analizaCadAF(tAutomata AF, tset qSet, char *cad)
{
    tset actual;
    char *p;

    if (cad == NULL)
        return 0;
    actual = DeepCopyTset(qSet);
    p = cad;
    while (*p != '\0')
    {
        actual = transicionAF(AF.trans, actual, *p);
        if (esVacioAF(actual))
            return 0; /* se murio la ejecucion, no hay estado alcanzable */
        p++;
    }
    return esVacioAF(interAF(actual, AF.fin)) ? 0 : 1;
}

tAutomata transformarAFND(tAutomata AFND)
{
    tAutomata AF;
    int i, j;

    AF.alfabeto = DeepCopyTset(AFND.alfabeto);
    AF.estados = nuevaListaAF();
    AF.trans = nuevaListaAF();
    AF.fin = nuevoConjAF();

    /* el estado inicial del AFD es el conjunto inicial del AFND */
    pushAF(&AF.estados, DeepCopyTset(AFND.ini));
    AF.ini = nuevoConjAF();
    AF.ini->elem = DeepCopyTset(AFND.ini);
    AF.ini->sig = NULL;

    i = 0;
    while (i < cantAF(AF.estados))
    {
        int nalf = cantAF(AF.alfabeto);
        for (j = 0; j < nalf; j++)
        {
            tset simbolo = elemAF(AF.alfabeto, j);
            tset origen = elemAF(AF.estados, i);
            tset destino, upla, destinoEnvuelto;
            char c;

            if (simbolo == NULL || simbolo->type != AF_STR || origen == NULL)
                continue;
            c = simbolo->str[0];
            destino = transicionAF(AFND.trans, origen, c);

            /* en el AFD, el destino es UN estado (que a su vez es un
               conjunto), asi que se envuelve en un conjunto-de-estados.
               Sin esto, comoEsAF() lo contaria como no-determinista y
               transicionAF() no podria ejecutar el AFD resultante. */
            destinoEnvuelto = nuevoConjAF();
            if (!esVacioAF(destino))
            {
                destinoEnvuelto->elem = DeepCopyTset(destino);
                destinoEnvuelto->sig = NULL;
            }

            upla = creaTransAF(DeepCopyTset(origen),
                               DeepCopyTset(simbolo),
                               destinoEnvuelto);
            pushAF(&AF.trans, upla);

            if (!esVacioAF(destino) && !perteneceAF(AF.estados, destino))
            {
                pushAF(&AF.estados, DeepCopyTset(destino));
                if (!esVacioAF(interAF(destino, AFND.fin)))
                    agregaSiNoEstaAF(AF.fin, destino);
            }
        }
        i++;
    }
    return AF;
}