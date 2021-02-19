#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include "Biblioteca.h"
#include "1SolEcuaciones.h"
#include "2SistemaEcuaciones.h"
#include "3Cholesky.h"
#include "4Potencias.h"



//Declaracion de funciones
void Salida();
void main();

void main(){
	system("CLS");
	ConfiguraIdioma();
	Portada();
	system("CLS");

	int princ;
	
	printf("\n\t**** METODOS NUMERICOS *****\n\n");
	printf("\t 1.Solución de Ecuaciones \n");
	printf("\t 2.Solución de Sistema de Ecuaciones \n");
	printf("\t 3. Factorizacion Cholesky \n");
	printf("\t 4. Valores propios. Metodo de potencias \n");
	printf("\t 5. Salir \n");
	
	printf("Ingresa una opcion: ");
	fflush(stdin);
	scanf("%d",&princ);
	
		switch(princ){
			case 1:
				Sol_Ecuaciones();
				break;
			case 2:
				Sist_Ecuaciones();
				break;
			case 3:
				Fact_Cholesky();
				break;
			case 4:
				Met_Potencias();	
				break;
			case 5:
				Salida();
			default:
				printf("\n Opción no valida.");
				break;
		}
}

void Salida(){
	printf("\n");
}
