#ifndef conjunto_h
#define conjunto_h
#include "char.h"
typedef struct nodo
{
    int type; // SET 3,LIST 2,STR 1
    union
    {
        char *str;
        struct
        {
            struct nodo *elem;
            struct nodo *sig;
        };
    };
} conjunto;
typedef conjunto *tset; /*representa al tdata*/
// opercaciones generales
tset fillSetA(char *);             // rellena nodo/*es el new data listo*/
void muestra(tset);                /*es el printDara listo*/
void EraseSet(tset *A);            /*este es el dataFree listo*/
tset newNestedData(tset d, int t); // listo
int Return_Type(tset);             // listo
char *toStr(tset, int);            // solo sirve para los type 1 o los type 3 con poscion
tset Copy_Tset(tset);              // listo
tset newData();
void setElem(tset, int); // pedir la posicion y el elemento
tset inicializa();       // espacio de memoria type para modificar
// Operaciones de Conjuntos y Listas
// Retorna elemento en posiciï¿½n pos dentro del SLData

tset returnElem(tset d, int pos); // listo
// Es vacï¿½o
int isEmpty(tset d); // listo
// Son iguales
int IncludeE(tset A, tset B); // representa el modulo isEqual
// Retorna elemento en posiciï¿½n pos dentro del SLData

// Operaciones de Lista
tset Carga_Cola(tset cabeza, tset nue); /*representa el push*/
// elimina el ï¿½ltimo elemento de la lista y lo devuelve como salida
tset POP(tset *L); // listo
// retorna el tamaï¿½o de la lista
int SIZEL(tset L); /*representa al sizel*/

// operaciones de Conjunto

int card(tset);         /*listo*/
int In(tset A, char *); /*listo*/
tset U(tset, tset);     /*listo*/
tset I(tset, tset);     /*listo*/
tset D(tset, tset);     /*listo*/

// estos capas se usen internamente
int Include(tset A, tset B);
// void eliminarElemento(tset , char*);
int BusquedaEle(conjunto, tset);
int comparaLista(tset, tset);


/*operaciones generales*/

// a partir de una cadena dada por el usuario, crea un nuevo dato (ATM, SET o LIST)
tset newData();
// a partir de un tData crea uno nuevo anidando (nest) el tData recibido como hijo derecho
tset newNestedData(tset, int); // listo
// elimina un dataSL
void dataFree(tset *); // listo
// imprime un dato por pantalla
void printData(tset);
// retorna tipo de dato
int returnType(tset); // listo
// convierte tData a cadena
char *toStr(tset, int); // listo
// copia un tData en otro tData
tset copyData(tset); // listo

/*operaciones con SET y LIST*/
/*Retorna elemento en posiciï¿½n pos dentro del SLData*/
tset returnElem(tset, int); // listo
tset returncopyElem(tset, int);
// Es vacï¿½o
int isEmpty(tset); // listo
// Son iguales
int isEqual(tset, tset);

/*operaciones con LIST*/
// agrega un elemento a la lista por el final
void PUSH(tset, tset); // listo
// elimina el ï¿½ltimo elemento de la lista y lo devuelve como salida
tset POP(tset *); // listo
// retorna el tamaï¿½o de la lista
int SIZEL(tset); // Listo

// Se pueden agregar operaciones de ordenamiento y bï¿½squeda
// Se puede agregar operaciï¿½n de inserciï¿½n y eliminaciï¿½n

/*operaciones con SET*/
// calcula la cantidad de elementos de un conjunto
int CARDINAL(tset);
// determina si un elemento pertenece a un conjunto
int IN(tset, tset);
// genera un nuevo conjunto que resulta de la uniï¿½n de dos conjuntos
tset UNION(tset, tset);
// genera un nuevo conjunto que resulta de la intersecciï¿½n de dos conjuntos
tset INTER(tset, tset);
// genera un nuevo conjunto que resulta de la diferencia de dos conjuntos
tset DIFF(tset, tset);

// Se puede agregar opecaciï¿½n complemento, conjunto de partes (ver tema representaciï¿½n)
tset CargaVacio();
tset Carga_NodoConju_List(int, tset);

tset CambiaType(tset, int);
tset CambiaElemento(tset, tset);
tset Crea_Nodo(char *);
tset getNexNodo(tset);
tset getNodoElemnto(tset);

tset CargaConjELSE(tset, char *);
tset CargaConj(tset, char *);

tset depuracion(tset);

#endif
