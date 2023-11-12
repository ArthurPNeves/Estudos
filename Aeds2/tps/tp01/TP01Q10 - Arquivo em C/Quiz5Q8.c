#include <stdio.h>   // para entradas e saidas
#include <stddef.h>  // para definicoes basicas
#include <stdlib.h>  // para a biblioteca padrao
#include <string.h>  // para cadeias de caracteres
#include <stdbool.h> // para definicoes logicas
#include <math.h>    // para definicoes matematicas

int somatorioPA(double a, double b, int n){
    int somatorio = 0;
    for (int i = 0; i < n; i++)
    {
        somatorio = somatorio + a + b*i;
    }
    
    return somatorio;
}
int main()
{
    
    return 0;
}
