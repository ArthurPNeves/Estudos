#include <stdio.h>     
#include <stdlib.h>    
#include <string.h>    
#include <stdbool.h>  

bool palindromo(char palavra[200])
{
    // iniciando variaveis locais
    bool result = true;
    int esq;
    int x = 0;
    x = strlen(palavra);
    int dir = x;
        // Verificar se é ou não palindramo, verficando da esquerda para a direita se os caracteres sao iguais
    for (esq = 0; esq < x/2; esq++)
    {
        if ( palavra[esq] != palavra[dir-1] )
        {
            result = false;
        }
        dir--;
    }
    
    return result;
}
int main()
{
    // inciando variaveis
    char palavra[200];
    
    //Lendo todas as saidas, imprindo Sim e Nao e parando quando Fim for achado (Ultilizando Funcao isFim)
do
{
    fgets(palavra, 200, stdin);
    
    palavra[strlen(palavra)-1] = '\0';

        if (palindromo(palavra))
    {
        printf("SIM\n");
    }
    else{
        printf("NAO\n");
    }
    
} while (strcmp(palavra, "FIM") != 0 );

    
return 0;
}