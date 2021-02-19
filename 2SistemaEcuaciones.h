#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>

//Variables globales
int cont,n;
float matriz[100][100], aux[100][100];
float vector[100], xinic[100]; //vector son los valores independientes y x los iniciales

//Declaracion de funciones
void leerMat();
void imprime();
void modificar();
int EDD(int n, float a[100][100]);
int GS(int n, float a[100][100], float b[100], float x[100]);
void Gauss(float a[100][100], int n, float b[100][100]);
float determinante(float a[100][100], int n);
int Sist_Ecuaciones();

int Sist_Ecuaciones(){
	char corr, sn1, resp;
	int c,s,t,p,d;
	float det;
	
	system("CLS");
	fflush(stdin);
	do{
		leerMat ();
		imprime();
		printf("\n¿Desea corregir algun elemento de la matriz? [s/n] ");
		fflush(stdin);
		scanf("%c",&corr);
		
		while (corr=='s'){
			modificar();
			imprime(); 
			printf("¿Desea corregir algun elemento de la matriz? [s/n] ");
			fflush(stdin);
			scanf("%c",&corr);
		}
	
	Gauss(aux,n,matriz);
	
	//Determiante
	det=determinante(aux,n);
	printf("\n El determinante es= %f",det);
	
	//Sistema sin solucion
	if(det==0){
		printf(", por lo tanto no tiene solución");
	}
	else{
		printf(", por lo tanto el sistema tiene solución\n");
		d= EDD(n, matriz);
		if(d==1){
				printf("El sistema no es EDD, por lo que no se asegura la convergencia\n");
				printf("¿Deseas continuar?[s/n]:");
				fflush(stdin);
				scanf("%c", &resp);
				if(resp=='s'||resp=='S')
				{
					//system("CLS");
					printf("\n\n                       Solución del sistema de ecuaciones\n");
					printf("Ingrese los valores iniciales\n");
					for(cont=0; cont<n; cont++)
					{
						printf("x%d=", cont+1);
						scanf("%f", &xinic[cont]);
					}
					imprime();
					GS(n, matriz, vector, xinic); //b son los valores independientes, x son los valores iniciales
					system("pause");
					exit(1);
				}
				else
				{
					Sist_Ecuaciones();
				}	
			}
			else
			{
				printf("El sistema es EDD\n");
				system("pause");
				//system("CLS");
				printf("\n\n                       Solución del sistema de ecuaciones\n");
				printf("Ingrese los valores iniciales\n");
				for(cont=0; cont<n; cont++)
				{
					printf("x%d=", cont+1);
					scanf("%f", &xinic[cont]);
				}
				imprime();
				GS(n, matriz, vector, xinic);
				system("pause");
				exit(2);
			}
	}
	
	printf("\n\nDesea ingresar una nueva matriz [s/n]: ");
	fflush(stdin);
	scanf("%c",&sn1);
	}while (sn1=='s'||sn1=='S');
}

void leerMat(){
	
	int i,j,k;
	printf("\nLectura de Matriz\n");
	printf("Ingresa la dimensión: n= ");
	scanf("%d",&n);
	
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
        	printf("\t Ingresa el valor de Mat[%d,%d]: ",i+1,j+1);
			scanf("%f", &matriz[i][j]);
        }
    }
    
    for(k=0;k<n;k++){
    	printf("\t Ingresa el valor del Vector independiente Vect[%d]: ",k+1);
		scanf("%f", &vector[k]);
	}
}

void imprime(){
	int i,j,k;
	
	printf("\n\n\t Matriz actual: \n");
    for(i=0; i<n;i++){
        for(j=0;j<n;j++)
            printf("\t%f   ",matriz[i][j]);
    printf("\n");
	}
	
    printf("\n\n\t Vector independiente: \n");
    for(k=0; k<n;k++){
            printf("\t%f   ",vector[k]);
    printf("\n");
}
}

void modificar(){
	int renglon, columna;
	int renvec;
	int modi;
	
	printf("\n\t Editar: \n");
	printf("\t 1. Matriz \n");
	printf("\t 2. Vector independiente \n");
	printf("\t Ingresa opcion: ");
	fflush(stdin);
	scanf("%d",&modi);
	
	switch(modi){
		case 1:
			printf("\n Ingresa la posicion que deseas modificar Mat[renglon,columna]\t");
			printf("\n renglon: ");
			fflush(stdin);
			scanf("%d",&renglon);
			printf("\n columna: ");
			fflush(stdin);
			scanf("%d",&columna);
			
			printf("Ingresa el valor de [%d,%d]: ",renglon,columna);
			scanf("%f",&matriz[renglon-1][columna-1]);
			break;
		case 2:
			printf("\n Ingresa la posicion que deseas modificar Vect[renglon]\t");
			printf("\n renglon: ");
			fflush(stdin);
			scanf("%d",&renvec);
			
			printf("Ingresa el valor de [%d]: ",renvec);
			scanf("%f",&vector[renvec-1]);
	}
	
	
}
//SEGUNDA PARTE, PROGRAMA 3
void Gauss(float a[100][100], int n, float b[100][100]){
	int i, j, k;
	for(j=0; j<n; j++)
	{
		for(i=0; i<n; i++)
		{
			a[j][i]=b[j][i];
		}
	}
	for(k=0; k<n-1; k++)
	{
		for(j=1; j<n; j++)
		{
			for(i=n-1; i>=0; i--)
			{
				a[j+k][i]=(a[k][i]*((-1)*(a[j+k][k]/a[k][k])))+a[j+k][i];
			}
		}
	}
	
}

float determinante(float a[100][100], int n){
	int i, j;
	float det=1;
	for(i=0; i<n; i++)
	{
		det=det*a[i][i];
	}
	return det;
}

int EDD(int n, float a[100][100]){
	int i, j, b;
	float suma=0;
	for(j=0; j<n; j++)
	{
		for(i=0; i<n; i++)
		{
			if(i!=j)
			{
				suma=suma+a[j][i];
			}
		}
		if(abs(suma)>abs(a[j][j]))
		{
			b=1;
		}
		suma=0;
	}
	return b;
}

int GS(int n, float a[100][100], float b[100], float x[100]){
	int ite, t, i, j, r=0, m;
	float norma=0, k, k_1, tol, nor;
	printf("Máximo de iteraciones: ");
	scanf("%d", &ite);
	printf("Tolerancia deseada: ");
	scanf("%f", &tol);
	printf("\n");
	for(m=1; m<=n; m++)
	{
		printf("\t\t\tx%d", m);
	}
	printf("\n0\t\t");
	for(i=0; i<n; i++)
	{
		printf("%f\t\t", x[i]);
	}
	printf("\n\n");
	do
	{
		nor=norma;
		printf("%d\t\t", r+1);
		for(j=0; j<n; j++)
		{
			k=0;
			k_1=0;
			for(i=0; i<j; i++)
			{
				k=k+(a[j][i]*x[i])/a[j][j];	
			}
			for(i=j+1; i<n; i++)
			{
				k_1=k_1+(a[j][i]*x[i])/a[j][j];
			}
			x[j]=(-1)*k-k_1+(b[j]/a[j][j]);
			printf("%f\t\t", x[j]);
		}
		norma=x[0];
		for(i=0; i<n-1; i++)
		{
			if(x[i+1]>x[i])
			{
				norma=x[i+1];
			}
		}
		printf("\t\nLa norma es:\t%f",norma);
		printf("\t\nEl error es:\t%f",fabs(norma-nor));
		printf("\n\n");
		r++;	
	}while(fabs(norma-nor)>=tol&&r<ite);
}

