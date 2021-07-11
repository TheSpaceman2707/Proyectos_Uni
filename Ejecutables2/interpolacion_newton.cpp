/* PROGRAMA QUE REALIZA UNA INTERPOLACION POLINOMICA DE NEWTON MEDIANTE DIFERENCIAS DIVIDIDAS */

/* Compilado con GCC [gcc (MinGW.org GCC-8.2.0-5) 8.2.0] */
/* Comando usado en terminal: gcc -o4 -pedantic -Wall -std=c99 proyecto_interpolacion_newton.c -o interpolacion_newton -lm */

/* LIBRERIAS */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* DEFINICIONES */
#define NUMPARAMS 2
#define COLUMNAS 2

/* FUNCIONES */
void defineNumeroDatos(int *numero_datos);
float **crearTablaDatos(int numero_datos);
void capturarDatos(float **tabla_datos, int numero_datos);
void imprimirTablaDatos(float **tabla_datos, int numero_datos);
void interpolacionNewton(float **tabla_datos, int numero_datos);
int cleanInput(void);

int main(){
	float **tabla_datos;
	int numero_datos = 0;
	
	printf("\n\n\n***INTERPOLACION POLINOMICA DE NEWTON DIFERENCIAS DIVIDIDAS***\n");
	
	defineNumeroDatos(&numero_datos);
	tabla_datos = crearTablaDatos(numero_datos);
	
	capturarDatos(tabla_datos, numero_datos);
	
	printf("\n\nTABLA DE DATOS INGRESADA\n\n");
	imprimirTablaDatos(tabla_datos, numero_datos);
	
	interpolacionNewton(tabla_datos, numero_datos);
	
	system("pause");
	//return 0;
}

void defineNumeroDatos(int *numero_datos){
    char c;
    printf("\nCantidad de renglones a introducir en la tabla de datos: ");
    while(!(scanf("%d%c", numero_datos, &c) == NUMPARAMS && c == '\n')){
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

void interpolacionNewton(float **tabla_datos, int numero_datos){
	int i = 0, j = 0;
	float coeficientes_p[numero_datos], coeficientes_r[numero_datos];
	char aux_2[13], aux_1[13], aux_3[2000] = "";
	
	for(i=0; i<numero_datos; i++)
		coeficientes_p[i] = tabla_datos[i][1];
	
	coeficientes_r[0] = tabla_datos[numero_datos-1][1];
	
	for(i=1; i<=numero_datos-1; i++){
		for(j=numero_datos-1; j>=i; j--)
			coeficientes_p[j] = ((coeficientes_p[j] - coeficientes_p[j-1])/(tabla_datos[j][0] - tabla_datos[j-i][0]));
		
		coeficientes_r[i] = coeficientes_p[numero_datos-1];
	}
	
	printf("\n\nCOEFICIENTES GENERADOS");
	
	printf("\n\n\tPROGRESIVOS");
	for(i=0; i<numero_datos; i++)
		printf("\n\tc_%i = %.4f", i, coeficientes_p[i]);
	
	printf("\n\n\tREGRESIVOS");
	for(i=0; i<numero_datos; i++)
		printf("\n\tc_%i = %.4f", i, coeficientes_r[i]);
	
	printf("\n\n\nPOLINOMIOS DE GRADO %i GENERADOS TOMANDO EN CUENTA LOS PUNTOS DE CONTACTO P_%i(x_i) = f(x_i)", numero_datos-1, numero_datos-1);
	
	printf("\n\n\tPROGRESIVO\n\t");
	for(i=0; i<numero_datos; i++){
		strcpy(aux_3, "");
		for(j=0; j<i; j++){
			sprintf(aux_1, "(x - %.4f)", tabla_datos[j][0]);
			strcpy(aux_2, aux_1);
			if(i==1)
				strcpy(aux_3, aux_2);
			else
				strcat(aux_3, aux_2);
		}
		if(i<numero_datos-1)
			printf("(%.4f)%s + ", coeficientes_p[i], aux_3);
		else
			printf("(%.4f)%s", coeficientes_p[i], aux_3);
	}
	
	printf("\n\n\tREGRESIVO\n\t");
	for(i=0; i<numero_datos; i++){
		strcpy(aux_3, "");
		for(j=0; j<i; j++){
			sprintf(aux_1, "(x - %.4f)", tabla_datos[numero_datos-1-j][0]);
			strcpy(aux_2, aux_1);
			if(i==1)
				strcpy(aux_3, aux_2);
			else
				strcat(aux_3, aux_2);
		}
		if(i<numero_datos-1)
			printf("(%.4f)%s + ", coeficientes_r[i], aux_3);
		else
			printf("(%.4f)%s", coeficientes_r[i], aux_3);
	}
	
	
	printf("\n\n");
}

int cleanInput(void){
    fflush(stdin);
    return 1;
}
