#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main (void)
{
printf ("99999999_AED1\n");
double x; // lado
double y;// altura triangulo
printf ("Escreva o valor real do lado do triangulo equilatero:\n");
scanf ("%lf", &x);
printf ("x = %lf\n", x);
x = x/2.0; 
y = pow((x*x) - ((x/2.0)*(x/2.0)),1.0/2.0); 
printf ("Caso dividirmos pela metade o lado do triangulo temos como altura:\n %lf", y);
printf ("\nArea:\n %lf" ,y*x/2);
printf ("\nPerimetro:\n %lf", x*3.0);

printf ("\nApertar ENTER para terminar.\n");
getchar ();
return (0);
}