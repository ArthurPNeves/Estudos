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
x = x*2;
y = y*2;
z = x*y;
printf ("Logo caso o valor dos lados x e y sejam dobrados, a area do retangulo formado pelos dois lado sera de =\n %lf\ne seu perimetro = %d", z, x*2 + y*2 );


printf ("\nApertar ENTER para terminar.\n");
getchar ();
return (0);


}