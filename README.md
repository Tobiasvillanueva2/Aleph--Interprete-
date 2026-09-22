# Aleph

**Aleph** es un lenguaje de programación experimental diseñado para la manipulación abstracta y las operaciones de teoría de conjuntos. Permite trabajar de forma nativa con conjuntos, listas y elementos, además de soportar funciones definidas por el usuario, estructuras de control de flujo, aritmética, comparaciones lógicas y una implementación de autómatas finitos construida sobre el mismo sistema de tipos del lenguaje.

## Tecnologías utilizadas

| Herramienta | Uso |
|---|---|
| **Flex** | Analizador léxico (`aleph.l`) — reconoce tokens: palabras clave, identificadores, símbolos y literales |
| **Bison** | Analizador sintáctico (`aleph.y`) — define la gramática del lenguaje y construye el Árbol de Sintaxis Abstracta (AST) |
| **C** | Implementación de la tabla de símbolos, el AST y el intérprete (`aleph.c`, `aleph.h`), y de las operaciones de datos (`conjunto.c`/`conjunto.h`, `automata.c`/`automata.h`) |

### Estructura de archivos

```
aleph.l         -> analizador léxico (Flex)
aleph.y         -> gramática (Bison)
aleph.h         -> tabla de símbolos, definición del AST, prototipos
aleph.c         -> constructores del AST y el intérprete (eval())
conjunto.h/.c   -> TAD base: elementos, conjuntos y listas
automata.h/.c   -> TAD de autómatas finitos, construido sobre conjunto
```

### Compilación

```bash
bison -d aleph.y
flex -o lex.yy.c aleph.l
gcc aleph.tab.c lex.yy.c aleph.c conjunto.c automata.c char.c -o aleph
```

### Ejecución

```bash
./aleph < programa.aleph
```

También se puede usar en modo interactivo, ejecutando `./aleph` sin redirección y escribiendo línea por línea.

---

## El tipo de dato unificado: `tset`

Todo valor en Aleph —sin excepción— es del mismo tipo: `tset` (puntero a `struct nodo`, definida en `conjunto.h`). No existen tipos separados para números, strings, conjuntos o listas a nivel de la estructura de datos; en cambio, cada nodo se etiqueta con un campo `type`:

```c
typedef struct nodo
{
    int type; // 1 = STR, 2 = LIST, 3 = SET
    union
    {
        char *str;                  // si type == STR
        struct
        {
            struct nodo *elem;      // elemento actual
            struct nodo *sig;       // siguiente nodo de la cadena
        };                           // si type == LIST o SET
    };
} conjunto;
typedef conjunto *tset;
```

Esto significa que:

- Un **elemento** (`STR`) es un átomo: un texto, un número entero o un número decimal — los tres se representan igual, como una cadena de caracteres (`"hola"`, `"42"`, `"3.14"`). La diferencia entre "es un número" o "es texto" se decide recién en tiempo de evaluación, según el operador que se use sobre él.
- Un **conjunto** (`SET`) y una **lista** (`LIST`) comparten la misma representación interna: una cadena enlazada de nodos, donde cada nodo apunta a un elemento (`elem`) y al siguiente nodo de la colección (`sig`). Lo único que los distingue es el valor de `type`.
- Como `str` y `elem`/`sig` viven en una **unión**, un mismo nodo nunca es a la vez texto y colección — el campo `type` decide cuál de las dos lecturas es válida.

Gracias a este diseño, el intérprete (`eval()`) tiene una única firma de retorno (`tset eval(struct ast *)`) para *cualquier* expresión del lenguaje: una suma, una unión de conjuntos, una comparación booleana o el resultado de analizar un autómata — todos son, en el fondo, el mismo tipo de dato.

### Valores booleanos

Aleph no tiene un tipo booleano dedicado. La verdad se representa por convención:

- **Falso** → un conjunto vacío: `{}`
- **Verdadero** → un conjunto no vacío, típicamente `{verdadero}`

Cualquier condición (`if`, `while`) evalúa esta convención: un elemento de texto no vacío es verdadero, un conjunto o lista con al menos un elemento es verdadero, y `{}`, `[]` o una variable sin definir son falsos.

---

## Sintaxis y explicación de cada token

### Reglas generales de escritura

| Regla | Detalle |
|---|---|
| Identificadores (variables, funciones, parámetros) | Solo mayúsculas y dígitos, sin guion bajo: `X`, `CONJ1`, `TIENEELEMENTO` |
| Elementos de texto/número | Se escriben **sin comillas**: `rojo`, `42`, `3.14` |
| Fin de sentencia | `;` — obligatorio para toda instrucción simple |
| Bloques (`func`, `if`, `while`) | Se delimitan con `{ }` y **no** llevan `;` después de la llave de cierre |
| Comentarios | No están soportados actualmente |

### Literales y tipos de dato

| Sintaxis | Significado | Ejemplo |
|---|---|---|
| `palabra` | Elemento de texto | `rojo` |
| `42` | Elemento numérico entero | `42` |
| `3.14` | Elemento numérico decimal | `3.14` |
| `{a,b,c}` | Conjunto | `{rojo,verde,azul}` |
| `{}` | Conjunto vacío | `{}` |
| `[a,b,c]` | Lista (ordenada, permite repetidos) | `[uno,dos,tres]` |
| `[]` | Lista vacía | `[]` |

### Asignación

| Token | Símbolo | Ejemplo |
|---|---|---|
| `ASIGNACION` | `=` | `X = {rojo,verde};` |

También soporta asignación múltiple:
```
X, Y = 5, 10;
```

### Operaciones de conjuntos y listas

| Token | Palabra clave | Qué hace | Ejemplo |
|---|---|---|---|
| `UN` | `un` | Unión de dos conjuntos | `A un B` |
| `INTE` | `inter` | Intersección de dos conjuntos | `A inter B` |
| `DIFC` | `difc` | Diferencia de conjuntos (A - B) | `A difc B` |
| `PUSHA` | `push` | Agrega un elemento al final de una lista | `L push nuevo` |
| `POPA` | `pop` | Extrae el último elemento de una lista | `pop L` |

```
A = {rojo,verde};
B = {azul};
A un B;          -> {rojo,verde,azul}
```

### Comparación

| Token | Palabra clave / símbolo | Qué compara | Ejemplo |
|---|---|---|---|
| `PERTENECE` | `pertenece` | ¿Un elemento está en un conjunto? | `tres pertenece A` |
| `IGUAL` | `igual` | ¿Dos conjuntos o listas tienen los mismos elementos? | `A igual B` |
| `MAYOR` | `>` | Mayor que (numérico) | `X > 5` |
| `MENOR` | `<` | Menor que (numérico) | `X < 5` |
| `IGUALIGUAL` | `==` | Igualdad numérica (o estructural si no son números) | `X == 5` |
| `DISTINTO` | `!=` | Distinto | `X != 5` |

Toda comparación devuelve `{verdadero}` o `{}`, así que se puede usar directo en un `if`/`while`.

```
A = {uno,dos,tres};
tres pertenece A;     -> {verdadero}
5 > 3;                 -> {verdadero}
```

### Aritmética

| Token | Símbolo | Ejemplo |
|---|---|---|
| `SUMA` | `+` | `X + Y` |
| `RESTA` | `-` (binario y unario) | `X - Y`, `-X` |
| `MULT` | `*` | `X * Y` |
| `DIV` | `/` | `X / Y` |

Respeta la precedencia matemática estándar (`*`/`/` antes que `+`/`-`) y permite agrupar con paréntesis:

```
2 + 3 * 4;        -> 14
(2 + 3) * 4;      -> 20
```

Funciona tanto con enteros como con decimales (si cualquiera de los dos operandos tiene punto decimal, el resultado se calcula en punto flotante).

### Estructuras de control

| Token | Palabra clave | Sintaxis |
|---|---|---|
| `IF` / `ELSE` | `if` / `else` | `if (condicion) { ... } else { ... }` |
| `WHILE` | `while` | `while (condicion) { ... }` |

```
X = 0;
while (X < 5) {
X = X + 1;
}
X;                -> 5
```

```
if (A > B) {
retorna mayor;
} else {
retorna menoroigual;
}
```

### Funciones

| Token | Palabra clave | Qué define |
|---|---|---|
| `FUNC` | `func` | Función que devuelve un valor |
| `FUNCVOID` | `funcvoid` | Función sin valor de retorno |
| `RETORNA` | `retorna` | Corta la ejecución y (opcionalmente) devuelve un valor |

```
func SUMADOS(A, B) {
retorna A + B;
}

R = SUMADOS(15, 27);
R;                -> 42
```

Las funciones soportan recursión (incluida la recursión directa de una función sobre sí misma), y los parámetros se ligan de forma segura en cada llamada, sin pisar las variables de llamadas anidadas.

```
func REC(A) {
if (A) {
retorna REC({});
} else {
retorna final;
}
}
```

### Autómatas finitos

Aleph incluye un TAD de autómatas finitos construido sobre el mismo tipo `tset`: un autómata se representa como una lista de 5 elementos `[estados, alfabeto, transiciones, inicial, final]`.

| Token | Palabra clave | Qué hace | Ejemplo |
|---|---|---|---|
| `AUTOMATA` | `automata` | Construye un autómata a partir de sus 5 partes | `automata(ESTADOS, ALFABETO, TRANS, INI, FIN)` |
| `ANALIZA` | `analiza` | ¿La cadena es aceptada por el autómata? | `analiza(AF, cadena)` |
| `DETERMINIZAR` | `determinizar` | Convierte un AFND en un AFD equivalente (construcción por subconjuntos) | `determinizar(AF)` |
| `ESAFD` | `esafd` | ¿El autómata es determinista? | `esafd(AF)` |

```
ESTADOS = [];
ALFABETO = [a,b];
TRANS = [[q0,a,{q0,q1}],[q0,b,{q0}]];
INI = {q0};
FIN = {q1};

AF = automata(ESTADOS, ALFABETO, TRANS, INI, FIN);

esafd(AF);              -> {}            (es AFND: (q0,a) tiene 2 destinos)
analiza(AF, abba);       -> {verdadero}   (termina en 'a')

AFD = determinizar(AF);
esafd(AFD);              -> {verdadero}
```

Todo AFD es, por definición, un AFND válido (un AFD es simplemente un AFND cuyas transiciones nunca tienen más de un destino) — por eso no existe una conversión en sentido inverso, solo `determinizar()`.

### Otros símbolos de la gramática

| Token | Símbolo | Uso |
|---|---|---|
| `LLAVE_I` / `LLAVE_D` | `{` `}` | Delimitan conjuntos y también los bloques de `func`/`if`/`while` |
| `CORCH_I` / `CORCH_D` | `[` `]` | Delimitan listas |
| `PAREN_I` / `PAREN_D` | `(` `)` | Condiciones, parámetros, llamadas a función y agrupación aritmética |
| `COMA` | `,` | Separador de elementos, parámetros y argumentos |
| `EOL` | `;` | Fin de sentencia |

### Palabras reservadas

No pueden usarse como valor de texto suelto ni como nombre de variable/función:

```
un, inter, difc, pop, push, pertenece, igual,
func, funcvoid, retorna, if, else, while,
automata, analiza, determinizar, esafd
```

---

## Ejemplo completo

```
func TIENEELEMENTO(CONJ, ELEM) {
if (ELEM pertenece CONJ) {
retorna encontrado;
} else {
retorna noencontrado;
}
}

func COMPARA(A, B) {
if (A > B) {
retorna esmayor;
} else {
if (A == B) {
retorna esigual;
} else {
retorna esmenor;
}
}
}

A = {manzana,pera,uva};
TIENEELEMENTO(A, pera);      -> encontrado
TIENEELEMENTO(A, sandia);    -> noencontrado

COMPARA(10, 4);               -> esmayor
COMPARA(4, 10);                -> esmenor
COMPARA(7, 7);                  -> esigual

X = 0;
while (X < 5) {
X = X + 1;
}
X;                              -> 5
```
