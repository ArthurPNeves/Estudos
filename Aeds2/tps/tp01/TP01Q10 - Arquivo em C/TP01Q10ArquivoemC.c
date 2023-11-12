#include <stdio.h>   // para entradas e saidas
#include <stddef.h>  // para definicoes basicas
#include <stdlib.h>  // para a biblioteca padrao
#include <string.h>  // para cadeias de caracteres
#include <stdbool.h> // para definicoes logicas
#include <math.h>    // para definicoes matematicas

int main()
{
// iniciar variaveis
int x =0;
scanf("%d", &x);
double array[x];
double array2[x];
char c[50];
FILE *arquivo = fopen("DADOS.TXT", "wt");
// fazendo primeiro array e colocando dados no arquivo
for (int i = 0; i < x; i++)
{
    
    scanf("%lf", &array[i]);
    fprintf(arquivo, "%lf\n", array[i]);
}
fclose(arquivo);
// passar arquivo ao contrario para array2

FILE *arq = fopen("DADOS.TXT", "rt");

    for (int i = 0; i < x; i++)
    {

        fscanf(arq, "%lf", &array2[x -i -1]);
        
    }
    
    fclose(arq);

    for (int j = 0; j < x; j++)
    {
        snprintf(c, 50, "%lf", array2[j]);
        while (c[strlen(c)-1] == '0')
        {
            c[strlen(c)-1] = '\0';
        }
        if (c[strlen(c)-1] == '.')
        {
            c[strlen(c)-1] = '\0';
        }
        
        
        printf("%s\n", c);
    }
    

    return 0;
}