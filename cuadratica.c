#include <stdio.h>
#include <stdlib.h>

void formula();
int menu=0;
float a=0,b=0,c=0,x=0,r=0,z=0;
float x1,bcuadra2,cuatro_ac,suma,x2;
float raiz,dividir,radical,resultado;

int main()
{
	printf("Desea resolver una ecuacion cuadratica de segundo orden? \n1.Si \n2.No\n");
	scanf("%d", &menu);

	if(menu == 1)
	{
		formula();
	}
	if(menu == 2)
	{
		printf("BYE!\n");
	}

return 0;
}

void formula()
{
	printf("digite el valor de a:\n");
	scanf("%f",&a);
	printf("digite el valor de b:\n");
	scanf("%f",&b);
	printf("digite el valor de c:\n");
	scanf("%f",&c);

	bcuadra2= b*b;
	cuatro_ac = 4*a*c;
	radical = bcuadra2 - cuatro_ac;

	while (r*r <= radical) {
	   resultado=r*r;
	   r++;

	}
	raiz=r-1;
	dividir = -b - raiz;
	z=2*a;
	x1=dividir/z;
	printf("El valor de X1  es : x = %f\n",x1);

	suma = -b + raiz;
	x2=suma/z;

	printf("El valor de X2  es : x = %f\n\n",x2);
}
