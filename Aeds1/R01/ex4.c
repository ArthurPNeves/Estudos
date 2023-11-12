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

bool minuscula(char x)
{
bool teste = (x>='a' && x<='z') ;
return (teste);
}

bool maiuscula(char x)
{
bool teste = (x>='A' && x<='Z') ;
return (teste);
}

bool digito(char x)
{
bool teste = (x>='0' && x<='9') ;
return (teste);
}


void funcao(char s[])
{
    int operadores = 0;
    int separadores = 0;
    int maisculas = 0;
    int minusculas = 0;
    int digitos = 0;
    int x = 0;
    x = strlen(s);
    int y = 0;
    while (y <= x)
    {
        if (logico(s[y]))
        {
            operadores = operadores + 1;
        }
        else if (artimetico(s[y]))
        {
            operadores = operadores + 1;
        }
        else if (relacional(s[y]))
        {
            operadores = operadores + 1;
        }
        else if (separador(s[y]))
        {
            separadores = separadores + 1;
        }
        else if (maiuscula(s[y]))
        {
            maisculas = maisculas + 1;
        }
        else if (minuscula(s[y]))
        {
            minusculas = minusculas + 1;
        }
        else if (digito(s[y]))
        {
            digitos = digitos + 1;
        }
        
        y = y + 1;
    }
    printf ("\nseparadores = %d", separadores);
    printf ("\noperadores = %d", operadores);
    printf ("\nmaisculuas = %d", maisculas);
    printf ("\nminusculas = %d", minusculas);
    printf ("\ndigitos = %d", digitos);
    
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