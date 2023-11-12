#include <stdio.h>     
#include <stdlib.h>    
#include <string.h>    
#include <stdbool.h>  
bool palindromo(char palavra[200], int esq, int dir)
    {
        
        
        // Verificar se é ou não palindramo, verficando da esquerda para a direita se os caracteres sao iguais

        if ( palavra[esq] != palavra[dir] )
        {
            return false;
        }
        else
        {
            if (strlen(palavra)/2 == esq ) {
                return true;
            }
            return palindromo(palavra, esq + 1, dir -1);

        }
        

         
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

        if (palindromo(palavra, 0 , strlen(palavra)-1))
    {
        printf("SIM\n");
    }
    else{
        printf("NAO\n");
    }
    
} while (strcmp(palavra, "FIM") != 0 );

    
return 0;
}