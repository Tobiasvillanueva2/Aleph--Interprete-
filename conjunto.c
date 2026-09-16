#include "char.h"
#include "conjunto.h"
void RecConA(tset *);
void RecListA(tset *);
void muestra2(tset);
int BusquedaConjunto(conjunto, tset);
tset depuracion(tset ori)
{
    tset ant;
    ant = NULL;
    tset aux, aux2; 
    aux = ori;
    aux2 = aux->sig;

    while (aux2 != NULL)
    {
        if (BusquedaEle(*aux->elem, aux2) == 0)
        {
            if (ant)
            {
                ant->sig = aux->sig;
            }
            else
            {
                ori = ori->sig;
            }
            aux->elem = NULL;
            aux->sig = NULL;
        }
        else
        {
            ant = aux;
        }
        aux = aux2;
        aux2 = aux2->sig;
    }

    return ori;
}
tset CargaConj(tset auxD, char *c1)
{
    auxD->type = 3;
    auxD->elem = fillSetA(c1);
    auxD->elem->type = 3;
    auxD->sig = (conjunto *)malloc(sizeof(conjunto));
    auxD = auxD->sig;
    return auxD;
}
tset CargaConjELSE(tset auxD, char *c1)
{
    auxD->type = 3;
    auxD->elem = fillSetA(c1);
    auxD->elem->type = 3;
    auxD->sig = NULL;
    return auxD;
}
tset getNodoElemnto(tset aux)
{
    return aux->elem;
}
tset getNexNodo(tset kk)
{
    return kk->sig;
}

tset CambiaElemento(tset kk, tset aux)
{
    kk->elem = aux;
    return kk;
}
tset CambiaType(tset kk, int n)
{
    kk->type = n;
    return kk;
}
tset Carga_NodoConju_List(int n, tset aux)
{
    tset copia;
    copia = (conjunto *)malloc(sizeof(conjunto));
    copia->sig = NULL;
    copia->type = n;
    if (aux->type == 1)
    {
        copia->elem = aux;
        copia->elem->type = aux->type;
    }
    else
    {
        copia->elem = aux;
        copia->elem->type = aux->type;
    }
    return copia;
}
tset returncopyElem(tset d, int pos)
{
    tset nue;
    int cont = 1;
    if (pos > 0)
    {
        while (d != NULL && cont < pos)
        {
            cont++;
            d = d->sig;
        }
        if (cont == pos)
        {
            nue = (conjunto *)malloc(sizeof(conjunto));
            if (d->elem->type == 1)
            { // para los casos de copia de elementos type 1
                nue->type = d->type;
                nue->sig = NULL;
                nue->elem = (conjunto *)malloc(sizeof(conjunto));
                nue->elem->type = d->elem->type;
                nue->elem->str = d->elem->str;
            }
            else
            { // para los casos de copia de elementos type 2 y 3
                nue->type = d->type;
                nue->sig = NULL;
                nue->elem = (conjunto *)malloc(sizeof(conjunto));
                tset aux;
                aux = nue->elem;
                d = d->elem;
                while (d != NULL)
                {
                    aux->type = d->type;
                    aux->elem = (conjunto *)malloc(sizeof(conjunto));
                    aux->elem->type = d->elem->type;
                    aux->elem->str = d->elem->str;
                    if (d->sig != NULL)
                    {
                        aux->sig = (conjunto *)malloc(sizeof(conjunto));
                        aux = aux->sig;
                    }
                    else
                    {
                        aux->sig = NULL;
                    }
                    d = d->sig;
                }
            }
            return nue;
        }
        else
        {
            printf("\n Error posicion exede al tamanio ");
            return d; // devuelve d en caso de error
        }
    }
    else
    {
        printf("\n Posicion invalida  ");
        return d; // devuelve d en caso de error
    }
}
tset newData()
{
    tset nue;
    nue = (conjunto *)malloc(sizeof(conjunto));
    nue->sig = NULL;
    nue->elem = NULL; 
    nue->str = NULL;  

    nue->type = 0; 
    

    return nue;
}
/* copia profunda real de un tset: a diferencia de Copy_Tset() (que solo
   hace "nue = A", un alias del mismo puntero), esta funcion reserva
   memoria nueva para cada nodo del arbol (contenedores y hojas STR) */
tset DeepCopyTset(tset A)
{
    tset nue;
    if (A == NULL)
        return NULL;
    nue = (conjunto *)malloc(sizeof(conjunto));
    nue->type = A->type;
    if (A->type == 1) /* STR: nodo hoja */
    {
        nue->str = A->str ? strdup(A->str) : NULL;
    }
    else /* SET o LIST: nodo contenedor */
    {
        nue->elem = DeepCopyTset(A->elem);
        nue->sig = DeepCopyTset(A->sig);
    }
    return nue;
}
tset QuitaVacio(tset cab)
{
    conjunto aux;
    aux.type = 1;
    aux.str = "-";
    tset prev, aux2;
    if (BusquedaEle(aux, returnElem(cab, 1)) == 0)
    {
        cab = cab->sig;
    }
    else
    {
        prev = cab;
        aux2 = cab->sig;
        while (aux2 != NULL && BusquedaEle(aux, returnElem(aux2, 1)) != 0)
        {
            prev = prev->sig;
            aux2 = aux2->sig;
        }
        if (aux2 != NULL)
        {
            prev->sig = aux2->sig;
        }
        else
        {
            prev->sig = NULL;
        }
    }
    return cab;
}
char *toStr(tset A, int t)
{
    int cont = 1;
    if (t > 0)
    {
        while (A != NULL && cont < t)
        {
            cont++;
            A = A->sig;
        }
        if (cont == t)
        {
            if (A->type == 1)
            {
                return A->str;
            }
            if (A->elem->type == 1)
            {
                return A->elem->str;
            }
            else
            {
                printf("\n se ingreso un typo incorrecto la funcion no devuelve a "
                       "string un conjunto o lista ");
                return NULL;
            }
        }
        else
        {
            printf("\n Error posicion exede al tamanio ");
            return NULL;
        }
    }
    else
    {
        printf("\n Posicion invalida  ");
        return NULL;
    }
}
tset newNestedData(tset d, int t)
{
    tset nue;
    int cont = 1;
    if (t > 0)
    {
        nue = d;
        while (nue != NULL && cont < t)
        {
            cont++;
            nue = nue->sig;
        }
        if (cont == t)
        {
            nue->sig = NULL;
            return d;
        }
        else
        {
            printf("\n Error posicion exede al tamanio ");
            return d; // devuelve d en caso de error
        }
    }
    else
    {
        printf("\n Posicion invalida  ");
        return d; // devuelve d en caso de error
    }
}
tset returnElem(tset d, int pos)
{
    tset nue;
    int cont = 1;
    if (pos > 0)
    {
        while (d != NULL && cont < pos)
        {
            cont++;
            d = d->sig;
        }
        if (cont == pos)
        {
            nue = (conjunto *)malloc(sizeof(conjunto));
            nue->type = d->type;
            nue->sig = NULL;
            nue->elem = d->elem;
            return nue;
        }
        else
        {
            printf("\n Error posicion exede al tamanio ");
            return d; // devuelve d en caso de error
        }
    }
    else
    {
        printf("\n Posicion invalida  ");
        return d; // devuelve d en caso de error
    }
}
tset Carga_Cola(tset cabeza, tset nue)
{
    /* "nue" puede llegar de dos formas distintas segun quien llame:
       - un elemento crudo (STR), como hace el operador push
       - un nodo contenedor de un solo elemento (como devuelve returnElem),
         usado por U(). En ese caso hay que desenvolverlo una vez. */
    tset elemento = (nue->type == 1) ? nue : nue->elem; /* 1 = STR */
    tset aux;
    if (cabeza == NULL)
    {
        cabeza = (conjunto *)malloc(sizeof(conjunto));
        cabeza->type = nue->type;
        cabeza->elem = elemento;
        cabeza->sig = NULL;
    }
    else
    {
        aux = cabeza;
        while (aux->sig != NULL)
        {
            aux = aux->sig;
        }
        aux->sig = (conjunto *)malloc(sizeof(conjunto));
        aux->sig->type = aux->type;
        aux = aux->sig;
        aux->sig = NULL;
        aux->elem = elemento;
    }
    return cabeza;
}
int comparaLista(tset Bus, tset Ori)
{
    while (Bus != NULL && Ori != NULL)
    {
        if (Bus->elem->type == Ori->elem->type)
        {
            if (Bus->elem->type == 1)
            {
                if (strcmp(Bus->elem->str, Ori->elem->str) != 0)
                {
                    return -1;
                }
                else
                {
                    Bus = Bus->sig;
                    Ori = Ori->sig;
                }
            }
            else if (Bus->elem->type == 2)
            { // para lista
                if (comparaLista(Bus->elem, Ori->elem) !=
                    0)
                { // sale porsi la lista no es igual
                    return -1;
                }
                else
                {
                    Bus = Bus->sig;
                    Ori = Ori->sig;
                }
            }
            else
            { // para conjunto
                int res = 0;
                tset auxbus;
                auxbus = Bus->elem;
                while (auxbus != NULL && res == 0)
                {
                    res = BusquedaEle(*auxbus->elem, Ori->elem);
                    auxbus = auxbus->sig;
                }
                if (res != 0)
                {
                    return res;
                }
                else
                {
                    Bus = Bus->sig;
                    Ori = Ori->sig;
                }
            }
        }
        else
            return -1; // sale por diferencia de type en misma posicion
    }
    if (Bus == NULL && Ori == NULL)
    {
        return 0;
    }
    else
    { // en caso de q alguno sea NULL
        printf("\nuno de los elementos esta vacio  ");
        return -1;
    }
}
// necesaio busqueda mas potente q incluya leer conjuntos o listas
int BusquedaEle(conjunto bus, tset cabeza)
{
    if (bus.type == 1)
    { // para el caso de string !!andaï¿½ï¿½
        while (cabeza != NULL)
        {
            if (cabeza->elem->type == 1)
            {
                if (strcmp(cabeza->elem->str, bus.str) == 0)
                {
                    return 0;
                }
            }
            cabeza = cabeza->sig;
        }
        if (cabeza == NULL)
            return -1;
    }
    else if (bus.type == 3)
    { // para conjunto
        int res = BusquedaConjunto(bus, cabeza);
        return res;
    }
    else
    { // para lista
        while (cabeza != NULL)
        {
            if (cabeza->elem->type == 2)
            {
                if (comparaLista(&bus, cabeza->elem) == 0)
                {
                    return 0;
                }
            }
            cabeza = cabeza->sig;
        }
        return -1;
    }
    printf("Error buscado sin tipo   ");
    return -1;
}
int BusquedaConjunto(
    conjunto bus,
    tset cab)
{ 
    tset auxbus;
    int res = -1;
    auxbus = &bus;
    while (res != 0 && cab != NULL)
    {
        if (cab->elem->type == 3)
        {
            res = 0;
            while (auxbus != NULL && res == 0)
            {
                res = BusquedaEle(*auxbus->elem, cab->elem);
                auxbus = auxbus->sig;
            }
            auxbus = &bus;
        }
        cab = cab->sig;
    }
    return res;
}
tset Crea_Nodo(char *c)
{
    tset a;
    a = (conjunto *)malloc(sizeof(conjunto));
    a->type = 1;
    a->str = c;
    return a;
}
tset Crea_NodoSig(tset nue, char *aux)
{
    tset nue2;
    nue2 = (conjunto *)malloc(sizeof(conjunto));
    nue2->type = nue->type;
    nue2->elem = Crea_Nodo(aux);
    return nue2;
}
void RecConA(tset *A)
{
    char *aux;
    char *s;
    tset nue;
    nue = *A;
    printf("\n ingrese los elementos del conjunto sin llaves:  ");
    fflush(stdin);
    s = Leecad();
    aux = strtok(s, ",");
    if (strcmp(aux, "{}") != 0 && strcmp(aux, "[]") != 0)
    {
        nue->elem = Crea_Nodo(aux); // el primero q entra
        // por si es el unico elemento ingresado
        if ((aux = strtok(NULL, ",")) != NULL)
        {
            nue->sig = (conjunto *)malloc(sizeof(conjunto));
            nue = nue->sig;
        }
        else
        {
            nue->sig = NULL;
        }
    }
    else if (strcmp(aux, "{}") == 0)
    {
        nue->elem = (conjunto *)malloc(sizeof(conjunto)); //
        nue->sig = NULL;
        nue->elem->sig = NULL;
        RecConA(&nue->elem);
        printf("\n ingrese los siguientes elementos del conj:  ");
        fflush(stdin);
        s = Leecad();
        aux = strtok(s, ",");
        if (aux != NULL)
        {
            nue->sig = (conjunto *)malloc(sizeof(conjunto));
            nue = nue->sig;
            nue->type = 3;
        }
        else
        {
            nue->sig = NULL;
        }
    }
    else
    {
        nue->elem = (conjunto *)malloc(sizeof(conjunto)); //
        nue->sig = NULL;
        nue->elem->sig = NULL;
        RecListA(&nue->elem);
        printf("\n ingrese los siguientes elementos del conj:  ");
        fflush(stdin);
        s = Leecad();
        aux = strtok(s, ",");
        if (aux != NULL)
        {
            nue->sig = (conjunto *)malloc(sizeof(conjunto));
            nue = nue->sig;
            nue->type = 2;
        }
        else
        {
            nue->sig = NULL;
        }
    }
    while (aux != NULL)
    { // si hay mas elementos
        if (strcmp(aux, "{}") != 0 && strcmp(aux, "[]") != 0)
        {                                                    // si es un conjunto
            nue->elem = Crea_Nodo(aux);                      // el primero q entra
            nue->sig = (conjunto *)malloc(sizeof(conjunto)); // el segundo q entra
            aux = strtok(NULL, ",");                         // por si hay mas elementos
            if (aux != NULL)
            {
                nue = nue->sig;
            }
            else
            {
                nue->sig = NULL;
            }
        }
        else if (strcmp(aux, "{}") == 0)
        {                                                     // si es un conjunto
            nue->elem = (conjunto *)malloc(sizeof(conjunto)); //
            nue->sig = NULL;
            nue->type = 3;
            nue->elem->type = 3;
            nue->elem->sig = NULL;
            RecConA(&nue->elem);
            printf("\n ingrese los siguientes elementos del conj:  ");
            fflush(stdin);
            s = Leecad();
            aux = strtok(s, ",");
            if (aux != NULL)
            {
                nue->sig = (conjunto *)malloc(sizeof(conjunto));
                nue = nue->sig;
                nue->type = 3;
            }
            else
            {
                nue->sig = NULL;
            }
        }
        else
        {
            nue->elem = (conjunto *)malloc(sizeof(conjunto)); //
            nue->sig = NULL;
            nue->type = 2;
            nue->elem->type = 2;
            nue->elem->sig = NULL;
            RecListA(&nue->elem);
            printf("\n ingrese los siguientes elementos del conj:  ");
            fflush(stdin);
            s = Leecad();
            aux = strtok(s, ",");
            if (aux != NULL)
            {
                nue->sig = (conjunto *)malloc(sizeof(conjunto));
                nue = nue->sig;
                nue->type = 2;
            }
            else
            {
                nue->sig = NULL;
            }
        }
    }
}

void RecListA(tset *A)
{
    char *aux;
    char *s;
    tset nue;
    nue = *A;
    printf("\n ingrese los elementos del conjunto sin corchetes:  ");
    fflush(stdin);
    s = Leecad();
    aux = strtok(s, ",");
    if (strcmp(aux, "{}") != 0 && strcmp(aux, "[]") != 0)
    {
        nue->elem = Crea_Nodo(aux); // el primero q entra
        // por si es el unico elemento ingresado
        if ((aux = strtok(NULL, ",")) != NULL)
        {
            nue->sig = (conjunto *)malloc(sizeof(conjunto));
            nue = nue->sig;
        }
        else
        {
            nue->sig = NULL;
        }
    }
    else if (strcmp(aux, "{}") == 0)
    {
        nue->elem = (conjunto *)malloc(sizeof(conjunto)); //
        nue->sig = NULL;
        nue->elem->sig = NULL;
        RecConA(&nue->elem);
        printf("\n ingrese los siguientes elementos de la lista:  ");
        fflush(stdin);
        s = Leecad();
        aux = strtok(s, ",");
        if (aux != NULL)
        {
            nue->sig = (conjunto *)malloc(sizeof(conjunto));
            nue = nue->sig;
            nue->type = 3;
        }
        else
        {
            nue->sig = NULL;
        }
    }
    else
    {
        nue->elem = (conjunto *)malloc(sizeof(conjunto)); //
        nue->sig = NULL;
        nue->elem->type = 2;
        nue->elem->sig = NULL;
        RecListA(&nue->elem);
        printf("\n ingrese los siguientes elementos de la lista:  ");
        fflush(stdin);
        s = Leecad();
        aux = strtok(s, ",");
        if (aux != NULL)
        {
            nue->sig = (conjunto *)malloc(sizeof(conjunto));
            nue = nue->sig;
            nue->type = 2;
        }
        else
        {
            nue->sig = NULL;
        }
    }
    while (aux != NULL)
    { // si hay mas elementos
        if (strcmp(aux, "{}") != 0 && strcmp(aux, "[]") != 0)
        {                                                    // si es un conjunto
            nue->elem = Crea_Nodo(aux);                      // el primero q entra
            nue->sig = (conjunto *)malloc(sizeof(conjunto)); // el segundo q entra
            aux = strtok(NULL, ",");                         // por si hay mas elementos
            if (aux != NULL)
            {
                nue = nue->sig;
            }
            else
            {
                nue->sig = NULL;
            }
        }
        else if (strcmp(aux, "{}") == 0)
        {                                                     // si es un conjunto
            nue->elem = (conjunto *)malloc(sizeof(conjunto)); //
            nue->sig = NULL;
            nue->type = 3;
            nue->elem->type = 3;
            nue->elem->sig = NULL;
            RecConA(&nue->elem);
            printf("\n ingrese los siguientes elementos de la lista:  ");
            fflush(stdin);
            s = Leecad();
            aux = strtok(s, ",");
            if (aux != NULL)
            {
                nue->sig = (conjunto *)malloc(sizeof(conjunto));
                nue = nue->sig;
                nue->type = 3;
            }
            else
            {
                nue->sig = NULL;
            }
        }
        else
        {
            nue->elem = (conjunto *)malloc(sizeof(conjunto)); //
            nue->sig = NULL;
            nue->type = 2;
            nue->elem->type = 2;
            nue->elem->sig = NULL;
            RecListA(&nue->elem);
            printf("\n ingrese los siguientes elementos de la lista:  ");
            fflush(stdin);
            s = Leecad();
            aux = strtok(s, ",");
            if (aux != NULL)
            {
                nue->sig = (conjunto *)malloc(sizeof(conjunto));
                nue = nue->sig;
                nue->type = 2;
            }
            else
            {
                nue->sig = NULL;
            }
        }
    }
}
tset fillSetA(char *s)
{
    tset nue; // el usuario solo ingresa [] o {}
    nue = (conjunto *)malloc(sizeof(conjunto));
    if (strcmp(s, "{}") == 0)
    {
        // no se puede modularizar "prof dario"
        // funcion recursiva de crea conjunto
        nue->type = 3;
        nue->sig = NULL;
        RecConA(&nue); // por si es el unico elemento ingresado
    }
    else if (strcmp(s, "[]") == 0)
    { //
        // funcion recursiva de crea lista
        nue->type = 2;
        nue->sig = NULL;
        RecListA(&nue);
    }
    return nue;
}
void muestra2(tset A)
{
    if (A->elem==NULL)
    {
        return;
    }
    
    while (A->sig != NULL)
    {
        if (A->elem->type == 1)
        {
            printf("%s,", A->elem->str);
        }
        else
        {
            muestra(A->elem);
            printf(",");
        }
        A = A->sig;
    }
    if (A->elem->type == 1)
    {
        printf("%s", A->elem->str);
    }
    else if (A->elem->type == 2 || A->elem->type == 3)
    {
        muestra(A->elem);
    }
}
void muestra(tset A)
{
    if (A == NULL)
    {
        printf("\nError vacio");
    }
    else
    {
        if (A->type == 2)
        {
            printf("[");
            muestra2(A);
            printf("]");
        }
        else if (A->type == 3)
        {
            printf("{");
            muestra2(A);
            printf("}");
        }
        else if (A->type == 1)
        {
            printf("%s", A->str);
        }
    }
}
tset U(tset a, tset b)
{ // listo
    if (a->elem == NULL && b->elem != NULL)
    {
        return b;
    }
    else if (a->elem != NULL && b->elem == NULL)
    {
        return a;
    }
    else if (b->elem == NULL && a->elem == NULL)
    {
        printf("\nError ambos en NULL");
        return NULL;
    }
    else if (a->type == 3 && b->type == 3)
    {
        tset nue;
        nue = DeepCopyTset(a); /* antes: nue = a; (alias, mutaba A en el lugar) */
        while (b != NULL)
        {
            if (BusquedaEle(*b->elem, a) != 0)
            {
                nue = Carga_Cola(nue, DeepCopyTset(returnElem(b, 1)));
            }
            b = b->sig;
        }
        nue = QuitaVacio(nue);
        return nue;
    }
    else
    {
        printf("\nError tipos diferentes  ");
        return NULL;
    }
}
tset I(tset A, tset B)
{
    tset nue;
    nue = NULL;
    if (A->type == B->type)
    {
        while (A != NULL)
        {
            if (BusquedaEle(*A->elem, B) == 0)
            {
                nue = Carga_Cola(nue, A);
            }
            A = A->sig;
        }
        return nue;
    }
    else
    {
        printf("Error tipos diferentes ");
        return NULL;
    }
}
tset D(tset A, tset B)
{
    tset nue;
    nue = NULL;
    while (A != NULL)
    {
        if (BusquedaEle(*A->elem, B) == -1)
        {
            nue = Carga_Cola(nue, A);
        }
        A = A->sig;
    }
    return nue;
}
int card(tset A)
{
    int cont = 0;
    while (A != NULL)
    {
        cont++;
        A = A->sig;
    }
    return cont;
}
int In(tset A, char *c)
{ /*si un elemento esta en a*/
    tset e = Crea_Nodo(c);
    return BusquedaEle(*e, A);
}
int Include(tset A, tset B)
{ /*si a esta en b*/
    int i = 0;
    if (card(A) != card(B))
    {
        while (A != NULL && i == 0)
        {
            if (BusquedaEle(*A->elem, B) == -1)
                i = -1;
            A = A->sig;
        }
    }
    else
        i = -1;
    return i;
}
int IncludeE(tset A, tset B)
{
    int cantA, cantB, i;
    i = 0;
    cantA = card(A);
    cantB = card(B);
    if (A->type != 1 && B->type != 1)
    {
        if (cantA == cantB)
        {
            while (A != NULL && i == 0)
            {
                if (BusquedaEle(*A->elem, B) == -1)
                    i = -1;
                A = A->sig;
            }
        }
        else
        {
            i = -1; // Include(A,B);
        }
    }
    else
    {
        if (strcmp(A->str, B->str) != 0)
        {
            i = -1;
        }
    }
    return i;
}
void EraseSet(tset *A) { A = NULL; }
int Return_Type(tset A) { return A->type; }
tset Copy_Tset(tset A)
{
    tset nue;
    return nue = A;
}

int isEmpty(tset d)
{
    if (d == NULL)
    {
        return 0;
    }
    else
        return -1;
}
void dataFree(tset *d)
{
    EraseSet(d);
}
void printData(tset d)
{
    muestra(d);
}
tset copyData(tset d)
{
    return Copy_Tset(d);
}
int isEqual(tset d1, tset d2)
{
    return IncludeE(d1, d2);
}
void PUSH(tset L, tset elem)
{
    L = Carga_Cola(L, elem);
}
tset POP(tset *L)
{
    tset a = *L;          // 'a' comienza apuntando a la CABEZA de la lista de elementos
    tset b = NULL;        // 'b' será el nodo que vamos a DEVOLVER (el elemento sacado)
    tset anterior = NULL; // Nuevo puntero para seguir al nodo anterior

    // 1. Manejo de errores inicial (Lista nula)
    if (a == NULL)
    {
        return NULL; // La lista está vacía, no hay nada que sacar.
    }

    // 2. Recorrer hasta el penúltimo nodo
    // El bucle encuentra al penúltimo ('anterior') y al último ('a')
    while (a->sig != NULL)
    {
        anterior = a; // 'anterior' rastrea el nodo antes del actual
        a = a->sig;   // 'a' avanza hasta el último nodo
    }

    // Al salir del bucle:
    // - Si la lista tenía UN solo elemento: 'anterior' es NULL, 'a' es la cabeza.
    // - Si la lista tenía MÁS de un elemento: 'anterior' es el penúltimo, 'a' es el último.

    // 'a' es el nodo que vamos a sacar y devolver (ej. el nodo que contiene '3')
    b = a;

    // 3. Modificación de la lista (Desconexión)
    if (anterior == NULL)
    {
        // Caso de UN solo elemento:
        // La lista queda vacía. (*L es la CABEZA de la lista de elementos)
        *L = NULL;
    }
    else
    {
        // Caso de MÁS de un elemento:
        // El penúltimo nodo ahora apunta a NULL.
        anterior->sig = NULL;
    }

    // 4. Devolver el elemento extraído
    // El nodo 'b' (que era 'a') contiene el elemento y su tipo.
    return b;
}
int CARDINAL(tset S)
{
    return card(S);
}
int IN(tset S, tset elem)
{
    return Include(S, elem);
}
tset UNION(tset A, tset B)
{
    return U(A, B);
}

tset INTER(tset A, tset B)
{
    return I(A, B);
}
tset DIFF(tset A, tset B)
{
    return D(A, B);
}