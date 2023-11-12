#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "io.h"
bool logico(char s[])
{
    bool teste =  (s == '&' || s == '|' || s == '!');
    return (teste);
}

bool artimetico(char s[])
{
    bool teste =  (s == '+' || s == '-' || s == '*' || s == '/' || s == '%');
    return (teste);
}

bool relacional(char s[])
{
    bool teste =  (s == '>' || s == '<' || s == '=');
    return (teste);
}

bool separador(char s[])
{
    bool teste =  (s == ' ' || s == '.' || s == ',' || s == ';' || s == ':' || s == '_');
    return (teste);
}




void funcao(char s[])
{
    int x = 0;
    x = strlen(s);
    int y = 0;
    while (y <= x)
    {
        if (logico(s[y]))
        {
            printf ("%c e logico\n", s[y]);
        }
        else if (artimetico(s[y]))
        {
            printf ("%c e artimetico\n", s[y]);
        }
        else if (relacional(s[y]))
        {
            printf ("%c e relacional\n", s[y]);
        }
        else if (separador(s[y]))
        {
            printf ("%c e separador\n", s[y]);
        }
        else {
            printf ("%c e outro qualquer\n", s[y]);
        }

        y = y + 1;
    }
}
int main()
{
    char s[80];
    printf("Insira S:\n");
    scanf("%s", &s);
    funcao(s);
    IO_pause("Apertar ENTER para continuar");
    return (0);
}