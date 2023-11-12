#include <io.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
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

bool letra(char x)
{
bool teste = (x>='a' && x<='z') || (x>='A' && x<='Z')  ;
return (teste);
}

bool letra_digito(char x)
{
bool teste = (x>='a' && x<='z') || (x>='A' && x<='Z') || (x>='0' && x<='9')  ;
return (teste);
}

bool outro(char x)
{
bool teste = !((x>='a' && x<='z') || (x>='A' && x<='Z') || (x>='0' && x<='9')) ;
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
        
        if (s[y]>='A' && s[y]<'K') 
        {
            
            printf ("%c\n", s[y]);
            c = c + 1;
        }
        
     y = y + 1;   
    }
    printf (" tem %d letras maiuscula", c);

    printf("\nApertar ENTER para terminar.\n");
    getchar();
    return 0;
}