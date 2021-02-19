#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>

float** CrearMat(int n);
float* Multi(float** A,float* b, int n);
void imp_vect(float* b,int n);
void lib(float** M,int n);
float ABS(float x);
void esc(float* b,float a, int n);
float max_vect(float* b,int n);

void Met_Potencias(){
	
	float** A;
	float** C;
	float** M;
	int n,b,x,a;
	
	printf("Ingrese la dimension de la matriz nxn: \n\n");
	scanf("%i",&n);
	
	A = CrearMat(n);
	LeerMat(A,n);
	
	C = Multi(A,b,n);
	printf("El vector es: \n");
	imp_vect(b, n);
	
	lib(M,n);
	ABS(x);
	esc(b,a,n);
	
	printf("\nMaximo:");
	max_vect(b,n);
}

float** CrearMat(int n){
	float** A;
	int i;
	
	do{
		A = (float**)malloc(n*sizeof(float*));
	}while(A == NULL);
	
	for(i = 0; i < n; i++){
		do{
			A[i] = (float*)calloc(n,sizeof(float));
		}while(A[i] == NULL);
	}
	
	return A;
}

float* Multiplicacion(float** A,float* b, int n){
	float* C;
	int i,j;
	float sum = 0;
	
	do{
		C = (float*)calloc(n,sizeof(float));
	}while(C == NULL);
	
	for(i = 0; i < n;i++){
		for(j = 0; j < n; j++){
			sum += A[i][j]*b[j];
		}
		C[i] = sum;
		sum = 0;
	}
	
	return C;
	
}

void imp_vect(float* b,int n){
	int i;
	
	for(i = 0; i < n; i++){
		printf("[%.3f]\n",b[i]);
	}
	system("\n\n");
}

void lib(float** M,int n){
	int i;
	
	for(i = 0; i < n; i++){
		free(M[i]);
	}
	
	free(M);
}

float ABS(float x){
	if(x < 0)
		return -1*x;
	else
		return x;
}

void esc(float* b,float a, int n){
	int i;
	
	for(i = 0; i < n; i++){
		b[i] *= a;
	}
}

float max_vect(float* b,int n){
	float r;
	int i;
	
	r = b[0];
	
	for(i = 1; i < n; i++){
		if(ABS(r) < ABS(b[i]))
			r = b[i];
	}
	
	return r;
}




