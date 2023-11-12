#include <io.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

bool digitopar(char x)
{
bool teste = ((x>='0' && x<='9') && (x % 2 == 0)) ;
return (teste);
}


int main()
{   
    char s[80];
    int t = 0;
    int c = 0;
    int y =0;
    printf("escrava a palvra:\n");
    scanf("%s", s);
    printf("sua palavra e:%s\n", s);
    t = strlen (s) ;  
    

    while (y<t)
    {
        
        if (digitopar(s[y])) 
        {
            
            c = c +1; 
            
        }
        
     y = y + 1;   
    }
    printf (" tem %d digitos pares", c);

    printf("\nApertar ENTER para terminar.\n");
    getchar();
    return 0;
}