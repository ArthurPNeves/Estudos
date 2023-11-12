#include <io.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

bool outro(char x)
{
bool teste = !((x>='a' && x<='z') || (x>='A' && x<='Z') || (x>='0' && x<='9')) ;
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
        
        if (outro(s[y])) 
        {
            
            printf ("%c\n", s[y]);
            
        }
        
     y = y + 1;   
    }

    printf("\nApertar ENTER para terminar.\n");
    getchar();
    return 0;
}