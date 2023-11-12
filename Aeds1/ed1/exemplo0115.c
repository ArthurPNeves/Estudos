#include <stdio.h>
#include <stdlib.h>
int main (void)
{
printf ("99999999_AED1\n");
double x; //base
double y;// altura
double z;// area triangulo
printf ("Escreva o valor inteiro da base do triangulo, logo apos a altura:\n");
scanf ("%lf\n %lf", &x, &y);
printf ("x = %lf\ny = %lf\n", x,y);
y = y/5.0;
z = x*y/2.0;

printf ("Caso a altura seja um quinto do valor de y, a area do triangulo feito pelos lados x e y/5 =\n %lf", z);





printf ("\nApertar ENTER para terminar.\n");
getchar ();
return (0);


}