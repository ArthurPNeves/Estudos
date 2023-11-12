#include "io.h"
struct s_ac
{
    int a; char c;
};

const int MAX_SIZE = 100;
void questao1()
{
    int array[] = {0,1,2,3,4,5,6,7,8,9};
    int x = 0, y = 0, z =0;
    for (x = 3; x < 7; x++)
    {
        z = array[x];
        for (y = x; y < 10; y++)
        {
            array[y] = array[y + 1];
        }
        array[y -1] = z;
    }

    for (x = 0; x < 10; x++)
    {
        printf("%d", array[x]);
    }
    printf("\n");
}

void questao2()
{
    int array [][3] = {{0,1,2},{3,4,5},{6,7,8}};
    int x =0, y =0, z=0;
    for (x = 0; x < 3; x++)
    {
        z = array[2-x][2-x];
        for (y = 2; y >= 0; y = y - 1 )
        {
            array[y][x] = array[x][y];
            if (x == y)
            {
                array[x][y] = z;
            }
            
        }
        
    }
    for (x = 0; x < 3; x++)
    {
        for (y = 0; y < 3; y++)
        {
            printf("%d\t", array[x][y]);
        }
        printf("\n");
    }
    
}
void questao3(int start, int end, char *source)
{
    char *destiny = NULL;
    int x = 0, y = 0;
    destiny = malloc (strlen(source)*sizeof(char));
    destiny[y] = "\0";
    for (x = start; x<end ; x++)
    {
        destiny[y] = source[x]; y++;
    }
    for ( int i = 0; i < y; i++)
    {
        printf("%c", destiny[i]);
    }
    
}

int questao4(int x, char *s)
{
    int result =0;
    if (0 <=x && x<strlen(s))
    {
        result = (s[x] == '0' || s[x] == '1') && questao4(x + 1, s);
    }
    else
    {
        result = 1;
    }
    return (result);
}

int questao5(char *s1, char *s2)
{
    int result = 0;
    int x = 0, y = 0, z = 0;
    for (x = 0; x < strlen(s2); x++)
    {
        for ( y  = 1; y< strlen(s2); y++)
        {
            if (s1[x] == s2[y])
            {
                z++;
                y = strlen(s2);
            }
            
        }
        
    }
    result = (z == strlen(s1));
    return result;
}

void questao6()
{
    struct s_ac s[5]; int x =0, y =0;
    for (x = 0; x < 5; x++)
    {
        s[x].a=x;  s[x].c=(char)('A'+x); 
    }
    while (x>0)
    {
    y = 5;
    while (y>0)
    {
        if (x -1 == s[y-1].a)
        {
            printf("%d%c",s[y-1].a, s[y-1].c); y=0;
        }
        y = y-2;
    }
    x = x-1;
    }
}

int questao7(char *s)
{
    int achar = 0; int x = 0, y = 0, z = 0;
    for(x = 0; x<strlen(s); x++)
    {
        if (s[x]  == '-')
        {
            if (0<= x && x<strlen(s) && ((s[x-1] == s[x + 1] && s[x+1] == 'r') || (s [x - 1] == 'i') ))
            {
                achar = 1;
            }
            
        }
        
    }

    return achar;
}

void questao8( double array[])
{
    FILE *arquivo = fopen("DADOS.TXT", "rt");
    int contador = 0;
    int i = 0; double soma = 0.0;
    while (!feof(arquivo))
    {
        fscanf(arquivo, "%lf", &array[i] );
        i++;
        contador++;
    }
    fclose(arquivo);

    if (contador %2 != 0)
    {
        soma = (array[0] + array[i - 1] + array[((i-2)/2) + 1] )/3.0;
        FILE *arquivo = fopen("DADOS.TXT", "a");
        fprintf(arquivo, "\n");
        fprintf(arquivo, "%lf", soma);
        fclose(arquivo);
    }
    
}

double questao9(int rows, int columns, int matrix[][MAX_SIZE])
{
    double resultado = 0;
    double soma1 = 0;
    double soma2 = 0;
    for (int x = 0; x < rows; x++)
    {
        for (int y = 0; y < columns; y++)
        {
            matrix[x][y] = rand()%10;
            if (y >= columns -1)
            {
                soma1 = matrix[x][y] + soma1;
            }
            
            if (y > x)
            {
                soma2 = matrix[x][y] + soma2;
            }
            
        } 
        
    }
    
    resultado = soma1/(soma2 -1);
    return resultado;
}
void questao10(int*menor, int*maior)
{
    int trocador = 0;
    maior = malloc(sizeof(int));
    menor = malloc(sizeof(int));
    if (*menor > *maior)
    {
        trocador = *maior;
        *maior = *menor;
        *menor = trocador;
    }
    
}
int main ()
{
    int MAX_SIZE = 100;
  printf("questao 1: \n"); questao1();
  printf("\n");
  printf("questao 2: \n"); questao2();
  printf("\n");
  printf("\n");
  printf("questao 3: \n"); questao3(4,6,"abcde");
  printf("\n");
  printf("\n");
  printf("Questao 4: \n%d", questao4(3, "01|O"));
  printf("\n");
  printf("\n");
  printf("Questao 5: \n%d", questao5("aroma", "amora"));
  printf("\n");
  printf("\n");
  printf("questao 6: \n"); questao6();
  printf("\n");
  printf("\n");
  printf("Questao 7: \n%d", questao7("super-homem"));
  printf("\n");
  printf("\n");
  double array[MAX_SIZE];
  questao8(array);
  printf("\n");
  printf("\n");
  int matriz [ MAX_SIZE ][ MAX_SIZE ];
  printf("questao9: %lf", questao9(3, 3, matriz ));
 

   return 0; 
}