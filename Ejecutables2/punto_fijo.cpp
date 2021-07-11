#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<locale.h>


int main()
{
	setlocale(LC_CTYPE, "Spanish");
	printf("\n \t \t Universidad Nacional Autónoma de México");
	printf("\n \t \t \tMétodos Numericos II");
	printf("\n \t \t \tMétodo del punto fijo\n");
	int iteracion,n;
	float x,y,a,b;
	printf("\n Sistema de ecuaciones no lineales \n");
	printf("\n Ingrese el valor inicial para  la entrada x: \n");
	scanf("%f",&x);
	printf("Ingrese el valor inicial para la entrada y: \n");
	scanf("%f",&y);
	printf("¿Cuantas iteraciones?\n");
	scanf("%d",&iteracion);
	
	printf("\n\n\n n\t\t |\t x \t\t|\t y");
	printf("\n---------------------------------------------------------");
	 a=(x*x+y*y+8)/10;
	 b=(x*(y*y)+x+8)/10;
    
	 for(int i=0 ;i<iteracion;i++){
	 	a=(x*x+y*y+8)/10;
	    b=(x*(y*y)+x+8)/10;
	 	n=n+1;
	 	
       printf("\n %d\t\t |\t %2.6f \t|\t %2.6f ",i+1,a,b);
       printf("\n---------------------------------------------------------");
	   x=a;
       y=b;
	}
	printf("\n\n Notamos que al igual que la gráfica ambas ecuaciones se intersectan en (1,1).\n");
	system("pause");
}
