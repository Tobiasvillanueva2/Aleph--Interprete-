#include "char.h"
char *Leecad()
{
    char *c;
    c = NULL;
    void *b;
    b = NULL;
    char a;
    int t;
    t = 0;
    c = (char *)malloc(sizeof(char));
    if (c != NULL)
    {
        a = getchar();
        while (a != EOF && a != '\n')
        {
            t = t + 1;
            b = realloc(c, sizeof(char) * t);
            if (b != NULL)
            {
                c = (char *)b;
                c[t - 1] = a;
            }
            else
                break;
            a = getchar();
        }
        b = realloc(c, sizeof(char) * t + 1);
        if (b != NULL)
        {
            c = (char *)b;
            c[t] = '\0';
        }
        else
        {
            c[t - 1] = '\0';
        }
    }
    return c;
}
int ComparaCadena(char *A, char *bus)
{
    return strcmp(A, bus);
}
char *DevGuion(void)
{
    char *c;
    c = (char *)malloc(sizeof(char));
    c = "-";
    return c;
}

