/*Programa que aplica el método del trapecio a una tabla de valores*/

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
void trapezoidal(float **tabla_datos, int numero_datos);
int cleanInput(void);


int main(){
	float **tabla_datos;
	int numero_datos;

	printf("\n\n\n*****METODO TRAPEZOIDAL*****\n\n\n");	
	capturaValores(&numero_datos);

	tabla_datos = crearTablaDatos(numero_datos);
	
	capturarDatos(tabla_datos, numero_datos);
	
	printf("\n\nTABLA DE DATOS INGRESADA\n\n");
	imprimirTablaDatos(tabla_datos, numero_datos);
	
	trapezoidal(tabla_datos,numero_datos);	
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

void trapezoidal(float **tabla_datos, int numero_datos){
	int i;
	float sum, h[numero_datos-1], area,sum2,h2;
	
	/*for(int i=0; i<numero_datos-1; i++){
		h[i] = (tabla_datos[i+1][0]-tabla_datos[i][0])/numero_datos;
	}
	for(int i=0; i<numero_datos-2; i++){
		if (h[i] != h[i+1]){
			printf("\nERROR!!!\nDistancia en un intervalo [x_0,x_k] y [x_k,x_n] no es equidistante\n");
			exit (1);
		}	
	}*/

	for(i = 1; i<numero_datos-1; i++){
		sum += tabla_datos[i][1];
	}
	printf("%.4f\n",sum);

	sum2=2*sum;
	
	h2=(tabla_datos[numero_datos-1][0]-tabla_datos[0][0])/(numero_datos-1);
	printf("%.4f\n",h2);

	area = (h2/2)*(tabla_datos[0][1]+sum2+tabla_datos[numero_datos-1][1]);

	printf("Area aproximada = %.4f\n\n\n",area);
}

int cleanInput(void){
    fflush(stdin);
    return 1;
}
