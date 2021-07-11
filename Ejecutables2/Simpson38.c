/*Programa que aplica el método de Simpson 3/8 a una tabla de valores*/

/*Librerias Empleadas*/
#include <stdio.h>
#include <stdlib.h>

/*Definiciones*/
#define NUMPARAMS 2
#define COLUMNAS 2

/*Funciones empeladas*/
void capturaValores(int* valores);
float **crearTablaDatos(int numero_datos);
void capturarDatos(float **tabla_datos, int numero_datos);
void imprimirTablaDatos(float **tabla_datos, int numero_datos);
void tresoctavos(float **tabla_datos, int numero_datos);
int cleanInput(void);


int main(){
	float **tabla_datos;
	int numero_datos;

	printf("\n\n\n*****METODO SIMPSON 3/8*****\n\n\n");	
	capturaValores(&numero_datos);

	tabla_datos = crearTablaDatos(numero_datos);
	
	capturarDatos(tabla_datos, numero_datos);
	
	printf("\n\nTABLA DE DATOS INGRESADA\n\n");
	imprimirTablaDatos(tabla_datos, numero_datos);
	
	tresoctavos(tabla_datos,numero_datos);	
	system("pause");
	return 0;
}

void capturaValores(int* valores){
	char c;
	printf("\nCantidad de renglones a introducir en la tabla de datos: ");
	while(!(scanf("%d%c", valores, &c) == NUMPARAMS && c == '\n')){
		printf("Debe introducir un valor entero. Intente de nuevo.");
		printf("\nCantidad de renglones a introducir en la tabla de datos: ");
		cleanInput();
	}
}

float **crearTablaDatos(int numero_datos){
    int i = 0;
    float **aux;
    
    aux = (float **)calloc(numero_datos, sizeof(float *));
    if(aux == NULL){
        printf("\nNo se puede asignar memoria.");
        exit(1);
    }
    
    for(i=0; i<numero_datos; i++){
        aux[i] = (float *)calloc(COLUMNAS, sizeof(float));
        if(aux[i] == NULL){
            printf("\nNo se puede asignar memoria.");
            exit(1);
        }
    }
    
    return aux;
}

void capturarDatos(float **tabla_datos, int numero_datos){
	char c;
    int i = 0;
	
	printf("\n\nCAPTURA DE VALORES\n\n");
	
	printf("\tFormato de la tabla\n\n");
	printf("\t[x] | [f(x)]\n");
	printf("\t------------\n");
    for(i=0; i<numero_datos; i++)
		printf("\tx_%i | f(x_%i)\n", i, i);
    
	printf("\n");
	
	for(i=0; i<numero_datos; i++){
		printf("\tIngrese el valor x_%i:    ", i);
		while(!(scanf("%f%c", &tabla_datos[i][0], &c) == NUMPARAMS && c == '\n')){
            		printf("\n\tDebe ingresar un dato valido. Intente de nuevo.\n");
			printf("\tIngrese el valor x_%i: ", i);
            		cleanInput();
        	}
		
		printf("\tIngrese el valor f(x_%i): ", i);
		while(!(scanf("%f%c", &tabla_datos[i][1], &c) == NUMPARAMS && c == '\n')){
           		printf("\n\tDebe ingresar un dato valido. Intente de nuevo.\n");
			printf("\tIngrese el valor f(x_%i): ", i);
            		cleanInput();
        	}
	}
}

void imprimirTablaDatos(float **tabla_datos, int numero_datos){
	int i = 0;
    
	printf("\t[x]    | [f(x)]\n");
	printf("\t----------------\n");
	
    for(i=0; i<numero_datos; i++)
		printf("\t%.4f | %.4f\n", tabla_datos[i][0], tabla_datos[i][1]);
}

void tresoctavos(float **tabla_datos, int numero_datos){
	float sum, area,sum2,h,h3,total;
	int i;

	if(numero_datos == 4){
		h=(tabla_datos[numero_datos-1][0]-tabla_datos[0][0])/3;
		h3=(3*h)/8;
		area=h3*(tabla_datos[0][1]+(3*tabla_datos[1][1])+(3*tabla_datos[2][1])+tabla_datos[numero_datos-1][1]);
		printf("Area aproximada = %.4f\n",area);
	}else if(numero_datos >4 && numero_datos % 3 == 1){
			h=(tabla_datos[numero_datos-1][0]-tabla_datos[0][0])/(numero_datos-1);
			h3=(3*h)/8;
			for( i=3;i<numero_datos-3;i+=3){
				sum+=tabla_datos[i][1];
			}
			for(i=1;i<numero_datos-2;i+=3){
				sum2+=tabla_datos[i][1];
			}
			for(i=2;i<numero_datos-2;i+=3){
				sum2+=tabla_datos[i][1];
			}
			area=h3*(tabla_datos[0][1]+(2*sum)+(3*sum2)+tabla_datos[numero_datos-1][1]);
			printf("Area aproximada = %.4f\n",area);	
	}else{
		printf("Metodo de Simpson 3/8 no puede ser aplicado\n");
		exit(1);
	}

}

int cleanInput(void){
    fflush(stdin);
    return 1;
}
