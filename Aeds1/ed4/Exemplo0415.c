#include <io.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

bool maiusculamenorqK(char x)
{
bool teste = (x>='A' && x<'K') ;
return (teste);
}

bool minusculamenorqK(char x)
{
bool teste = (x>='a' && x<'k') ;
return (teste);
}

int main()
{   
    char s [80];
    int t = 0;
    int c = 0;
    int y =0;
    printf("escrava a palvra:\n");
    scanf("%s", s);
    printf("sua palavra e:%s\n", s);
    t = strlen (s) ;  
    

    while (y<t)
    {
        
        if (maiusculamenorqK(s[y]) || minusculamenorqK(s[y])) 
        {
            
            c = c + 1;
            
        }
        
     y = y + 1;   
    }
    printf (" tem %d letras maiuscula ou minusculas menores k ou K", c);

    printf("\nApertar ENTER para terminar.\n");
    getchar();
    return 0;
}