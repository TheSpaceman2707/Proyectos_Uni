#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

main(){
int iteracion;
float p1,p2,m1,m2,m3,m4,f1,f2,M1,M2,xn,yn,k1,k2;

printf("\t \t Universidad Nacional Autonoma De Mexico\n");
printf("\t \t   Metodo de Neuton Raphson\n");

printf("Ejemplo:\n");
printf("x^2-y^2=1\n");
printf("x^2+y^2+xy=4 \n \n");

printf("ingresa el primer punto:\n");
scanf("%f",&p1);
printf("ingrese el segundo punto: \n");
scanf("%f",&p2);
printf("¿Cuantas iteraciones?\n");
scanf("%d",&iteracion);
printf("\n");

printf("________________________________________________________________________________________________\n");
printf(" n |    xn   | \t       j^-1      \t  |    f1   |       (j^-1)*F \t |   xn+1   |     1    | \n");
printf("   |    vy   | \t       j^-1      \t  |    f2   |       (j^-1)*F \t |   yn+1   |     4    | \n");
printf("________________________________________________________________________________________________\n");
int i;
for( i=0 ;i<iteracion;i++){

m1=(p1+2*p2)/(2*p1*p1+8*p1*p2+2*p2*p2);
m2=((-2*p1-p2)/(2*p1*p1+8*p1*p2+2*p2*p2));
m3= ((2*p2)/(2*p1*p1+8*p1*p2+2*p2*p2));
m4=((2*p1)/(2*p1*p1+8*p1*p2+2*p2*p2));

f1=p1*p1-p2*p2-1;
f2=p1*p1+p2*p2+(p1*p2)-4;

M1=m1*f1+m3*f2;
M2=m2*f1+m4*f2;

xn =p1-M1;
yn =p2-M2;

k1=(xn*xn-yn*yn-1)+1;
k2=(xn*xn+yn*yn+yn*xn-4)+4;

	 	printf(" %d |%2.6f|\t %2.6f\t %2.6f |%2.6f|\t %2.6f\t | %2.6f | %2.6f | \n",i,p1,m1,m3,f1,M1,xn,k1);
        printf("   |%2.6f|\t %2.6f\t %2.6f |%2.6f|\t %2.6f\t | %2.6f | %2.6f | \n",p2,m2,m4,f2,M2,yn,k2);
printf("_________________________________________________________________________________________________\n");
p1=xn;
p2=yn;
	}
/*
p1= punto 1
p2= punto 2

m1 = campo1 de la matriz
m2 = campo2 de la matriz
m3 = campo3 de la matriz
m4 = campo4 de la matriz

f1 =
f2 =

M1 = Resultado de la matriz 1
M2 = Resultado de la matriz 2

xn =
yn =

k1
k2
*/

system("pause");
}

