#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <conio.h>
#include <math.h>
#include<locale.h>
#include <iomanip>


#define Filas 30

using namespace std;

void llenaTabla(int n, float tabla[Filas][2])
{
	int i;
	cout<<"Ingrese los valores de la tabla..."<<endl;
	cout<<"Recuerde que uno de los requisitos de este método "<<endl;
	cout<<"es que los punto x_n deben ser equidistantes entre sí "<<endl;
	for(int i=0;i<n; i++)
	{
		cout<<"Ingrese el valor x_"<<i<<endl;
		cin>>tabla[i][0];
	}
	for(i=0;i<n; i++)
	{
		cout<<"Ingrese el valor f(x_"<<i<<")"<<endl;
		cin>>tabla[i][1];
	}
	cout<<"\tFormato de la tabla\n\n";
	cout<<"\t| x_n \t\t| f(x)_n \n";
	cout<<"\t--------------------------------\n";
    for(i=0; i<n; i++)
    {
		cout<<"\t| x_"<<i<<"="<<tabla[i][0]<<" \t| f(x_"<<i<<")="<<tabla[i][1]<<" "<<endl;
		cout<<"\t--------------------------------\n"; 
	}
	
}


int verifica(float tabla[Filas][2],int n)
{
	int i, j,sentinela=0, aux;
	float vect[Filas], dif[Filas];
	for(i=0;i<n-2;i++)
	{
		vect[i]=tabla[i+1][0]-tabla[i][0];
		dif[i]=vect[i+1]-vect[i];
	}
	for(i=0;i<2;i++){
	
		if(dif[i]==dif[0])
		{
			cout<<"h="<<vect[i]<<endl;
			cout<<"Los valores ingresados si estan igualmente espaciados...\n\n Presione una tecla para continuar..."<<endl;
 			getch();
 			aux=0;
 			//return aux;
		}else{
			cout<<"Error, los puntos tienen que ser equidistantes.\n"<<endl;
			//cout<<"Los valores ingresados no estan igualmente espaciados..."<<endl;
			cout<<"Vuelva a intentar ingresar valores para x_n que cumpla con esta condición del método.\n\n"<<endl;
			aux++;
			//return aux;
			//sentinela++;
		}
	}
	return aux;
}

void simpson13(float tabla[Filas][2],int n)
{
	float inte;
	float sigma1=0, sigma2=0;
	float SIGMA1=0,SIGMA2=0;
	cout<<"Ahora calcularemos la integral por el método de Simpson 1/3:"<<endl;
	int i=1;
	do
	{
		sigma1=sigma2+tabla[i][1];
		sigma2=sigma1;
		i=i+2;
	}while(i<n-1);
	cout<<"La suma de 2 en 2 de los f(x_(2n-1)) <impares> es: "<<sigma2<<endl;
	i=2;
	do
	{
		SIGMA1=SIGMA2+tabla[i][1];
		SIGMA2=SIGMA1;
		i=i+2;
	}while(i<n-1);
	cout<<"La suma de 2 en 2 de los f(x_(2n)) <pares> es: "<<SIGMA1<<endl;

	inte=(((tabla[n-1][0]-tabla[0][0])/(n-1))/3)*(tabla[0][1]+tabla[n-1][1]+4*sigma1+2*SIGMA1);
	cout<<"La aproximación de la integral es: I="<<fixed<<setprecision(4)<<inte<<endl;
}

main()
{
	int n, sent;
	setlocale(LC_CTYPE, "Spanish");
	cout<<"\n \t \t Universidad Nacional Autónoma de México"<<endl;
	cout<<"\n \t \t \tMétodos Numericos II"<<endl;
	cout<<"\n \t \t \tMétodo de Simpson 1/3 \n";
	float tabla_datos[Filas][2];
	cout<<"Especifique el número de valores que ingresara en la tabla:"<<endl;
	cin>>n;
	while(n<0 || n>Filas)
	{
		cout<<"Número de datos invalido. \n Intente ingresar otro nuevo valor: "<<endl;
		cin>>n;
	}
	llenaTabla(n,tabla_datos);
	sent=verifica(tabla_datos,n);
	if(sent>0)
	{
		cout<<"No todos los valores estan igualmente espaciados, por favor"<<endl;
		cout<<"vuelva a ejecutar el programa para volver a ingresar los valores...\n\n Presione una tecla para salir..."<<endl;
		getch();
		return 0;
	}
	simpson13(tabla_datos,n);
	cout<<"\n\n Gracias por utilizar este programa, vuelva pronto :)\n..."<<endl;
	system("pause");
		
}
