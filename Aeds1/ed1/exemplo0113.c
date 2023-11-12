#include <stdio.h>
#include <stdlib.h>
int main (void)
{
printf ("99999999_AED1\n");
int x; //lado1
int y;// lado2
double z;// area retangulo
printf ("Escreva o valor inteiro de um lado do retangulo, logo apos o outro lado:\n");
scanf ("%d\n %d", &x, &y);
printf ("x = %d\ny = %d\n", x,y);
z = x*y;
printf ("Logo um terco da area do retangulo, feito pelos lados x e y =\n %lf", z/3);





printf ("\nApertar ENTER para terminar.\n");
getchar ();
return (0);


}