#ifndef automata_h
#define automata_h
#include "conjunto.h"

/* ------------------------------------------------------------------
   TAD Automata Finito, construido sobre el TAD conjunto/lista (tset).
   La dependencia va en un solo sentido: automata conoce a conjunto,
   pero conjunto no sabe nada de automatas.

   Representacion:
     estados   -> LIST de SET   [ {q0}, {q1,q2}, ... ]
     alfabeto  -> LIST de STR   [ a, b ]
     trans     -> LIST de LIST  [ [q0,a,{q1}], [q0,b,{q2}] ]
     ini       -> SET de SET    { {q0} }
     fin       -> SET de SET    { {q2} }
   ------------------------------------------------------------------ */

typedef struct
{
    tset estados;
    tset alfabeto;
    tset trans;
    tset ini;
    tset fin;
} tAutomata;

/* --- constructores auxiliares sobre tset --- */
tset nuevoConjAF();                    /* SET vacio */
tset nuevaListaAF();                   /* LIST vacia */
tset nuevoElemAF(char *c);             /* STR */
int esVacioAF(tset d);                 /* 1 si es NULL o no tiene elementos */
int cantAF(tset d);                    /* cantidad de elementos (0 si vacio) */
tset elemAF(tset d, int pos);          /* elemento en pos, 0-based; NULL si no hay */
void pushAF(tset *L, tset elem);       /* agrega al final, actualiza al llamador */
int igualAF(tset a, tset b);           /* 1 si son iguales (tolera NULL/vacios) */
int perteneceAF(tset coleccion, tset x); /* 1 si x esta en coleccion */
tset unirAF(tset A, tset B);           /* union sin duplicados, siempre nuevo */
tset interAF(tset A, tset B);          /* interseccion, siempre nuevo */

/* --- operaciones del automata --- */
void iniciaAF(tAutomata *);
int llenoAF(tAutomata);
void vaciarAF(tAutomata *);
void mostrarAF(tAutomata);
tAutomata creaAF(tset estados, tset alfabeto, tset trans, tset ini, tset fin);
tset creaTransAF(tset partidaS, tset sim, tset llegadaS);
int comoEsAF(tAutomata);               /* 0 = AFD, 1 = AFND, -1 = sin transiciones */
tset transicionAF(tset deltaL, tset qSet, char alf);
int analizaCadAF(tAutomata AF, tset qSet, char *cad);
tAutomata transformarAFND(tAutomata);

#endif