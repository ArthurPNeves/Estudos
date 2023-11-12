#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "io.h"

void _method01a( int x, int a, int b)
{   
    int fib = a + b;
    if (x>0)
    {
        if (fib % 2 == 0)
        {
            printf ("-%d-", fib);
            _method01a(x-1,fib,a);
        }
        else{ _method01a(x,fib,a);}
        
    }
    
}

void method01a( int x)
{   
    _method01a(x,1,1);
}

void method00()
{

}

void method01()
{
    int contador;

    contador = IO_readint("Digite a quatindade de impares depois do 7 que deseja:\n");
     method01a(contador); 

    IO_pause("Apertar ENTER para continuar");
}

int main()
{

    int x = 0;

    do
    {
        IO_printf("\nOpcoes \n");
        IO_printf(" 0 - parar   ");
        IO_printf(" 1 -  Fibonacii pares \n");

        x = IO_readint("Entrar com uma opcao: \n");

        switch (x)
        {
        case 0:
            method00();
            break;
        case 1:
            method01();
            break;
        default:
            IO_printf("ERRO: Valor invalido.");
        }

    } while (x != 0);

    IO_pause("Apertar ENTER para terminar");
    return (0);
}