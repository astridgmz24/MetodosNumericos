/* FACTORIZACIÓN CHOLESKY
Verificar que la matriz sea simétrica, factorizar y solicitar el vector independiente (b),
 obtener el vector solución x y preguntar si se desea introducir otro vector b para obtener otra solución*/

#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>

//Declaracion de Funciones
float** CrearMat(int n);
void LeerMat(float** A,int n);
float** Ig(float** A,int n);
int Cero(float *A,int n);
int Equiv(float* A, float *B,int n);
void Inter(float **B, int r1, int r2);
void suma2(float **A,float esc,int f, int d,int n);
void lib(float **A,int n);
float det2(float** A,int n);
void imp_mat(float** A,int n);
int sub_det(float** A, int n);
int simetrica(float** A, int n);
float** identidad(int n);
float sum_cuad(float** L,int i);
float suma_i_j_esima(float** L, int i, int j);
void diagonal(float** L,float** A,int i,int n);
void elemento_iesimo(float** L, float** A, int i, int n);
void transponer(float** LT, float** L, int n);

  void main()
  {
	float** A;
	float** L;
	float** LT;
	int n;
	int i;
	
	printf("Ingrese la dimension de la matriz nxn: ");
	scanf("%i",&n);
	
	A = CrearMat(n);
	LeerMat(A,n);
	
	if(!sub_det(A,n)){
		printf(" La matriz NO es definida positiva.\n");
		printf(" Por lo tanto, no se puede realizar la Factorizacion de Cholesky.\n\n");
		system("pause");
		system("cls");
		lib(A,n);
	}
	else if(!simetrica(A,n)){
		printf("La matriz Si es definida positiva, pero no es simetrica para este metodo.\n\n");
		system("pause");
		system("cls");
		lib(A,n);
	}
	else{
		L = identidad(n);
		LT = identidad(n);
		
		L[0][0] = sqrt(A[0][0]);
		
		for(i = 1; i < n; i++){
			L[i][0] = A[i][0]/L[0][0];
		}
		
		for(i = 1; i < n; i++){
			diagonal(L,A,i,n);
			elemento_iesimo(L,A,i,n);
		}
		
		transponer(LT,L,n);
		
		system("cls");
		
		printf("     \n\nF a c t o r i z a c i o n   C h o l e s k y");
		
		printf("Matriz Original: \n\n");
		imp_mat(A,n);
		
		printf("Matriz L:\n\n");
		imp_mat(L,n);
		
		printf("Matriz L': \n\n");
		imp_mat(LT,n);
		
		lib(A,n);
		lib(L,n);
		lib(LT,n);
		
		system("pause");
	}
}


//1. Realiza la reserva de la memoria para la matriz
float** CrearMat(int n){
	int i;
	float** A;
	
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

//2. Lee datos de la matriz
void LeerMat(float** A,int n){
	int i,j;
	
	system("cls");
	
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			printf("A[%i][%i] : ",i,j);
			scanf("%f",&A[i][j]);
		}
	}
	
	printf("\n\n");
	
	system("pause");
	system("cls");
}

//3. Iguala dos matrices
float** Ig(float** A,int n){
	float** B;
	int i,j;
	
	do{
		B = (float**)malloc(n*sizeof(float*));
	}while(B == NULL);
	
	for(i = 0; i < n; i++){
		B[i] = (float*)malloc(n*sizeof(float));
	}
	
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			B[i][j] = A[i][j];
		}
	}
	
	return B;
}

//4. Determina si solo existen ceros
int Cero(float *A,int n){
	int cont = 0,i;
	
	for(i = 0; i < n; i++){
		if(A[i] == 0)
			cont++;
	}
	
	if(cont == n)
		return 1; //Existen 0 en el vector
	else
		return 0; //No existen o no todos son 0
}

//5. Determina si dos matrices son iguales
int Equiv(float* A, float *B,int n){
	int flag = 1,i;
	
	for(i = 0; i < n; i++){
		if(A[i] != B[i]){
			flag = 0;
			break;
		}
	}
	
	return flag;
}

//6. Intercambia renglones
void Inter(float **B, int r1, int r2){
	float *aux;
	
	aux = B[r1];
	B[r2] = B[r1];
	B[r1] = aux;
	
	
}

//7. Suma dos renglones
void suma2(float **A,float esc,int f, int d,int n){
	float *C;
	int i;
	
	C = (float*)malloc(n*sizeof(float));
	
	for(i = 0; i < n; i++){
		C[i] = A[f][i];
		C[i] *= esc;
	}
	for(i = 0; i < n; i++){
		A[d][i] += C[i];
	}
	
	
	free(C);
}

//8. Libera la memoria de la matriz
void lib(float **A,int n){
	int i;
	
	for(i = 0; i < n; i++){
		free(A[i]);
	}
	
	free(A);
}

//9. Retorna el determinante de la matriz
float det2(float** A,int n){
	float **B;
	float d = 1;
	float alfa;
	int j,i;
	
	B = Ig(A,n);
	
	for(j = 0; j < n-1; j++){
		if(Cero(B[j],n) || Equiv(B[j],B[j+1],n)){
			d = 0;
			break;
		}
		else if(B[j][j] == 0){
			d *= -1;
			Inter(B,j,j+1);
			j--;
		}
		else{
			for(i = j; i < n; i++){
				if(i != j){
					alfa = (-1)*(B[i][j])/B[j][j];
					suma2(B,alfa,j,i,n);
				}
			}
			d *= B[j][j];
		}
	}
	d*= B[n-1][n-1];
	lib(B,n);
	
	return d;
}

//10. Imprimir la matriz
void imp_mat(float** A,int n){
	int i,j;

	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			printf("[%.6f] ",A[i][j]);
		}
		printf("\n");
	}
	
	printf("\n\n");

}

//11. Det. si la matriz es definida positiva
int sub_det(float** A, int n){
	int i,k,l,flag = 1;
	float** C;
	
	for(i = 0; i < n && flag; i++){
		C = CrearMat(i+1);
		for(k = 0; k < i+1; k++){
			for(l = 0; l < i+1; l++){
				C[k][l] = A[k][l];
			}
		}
		if(det2(C,i+1) <= 0)
			flag = 0;
		lib(C,i+1);
	}
	
	return flag;
}

//12. Det. si la matriz es simetrica
int simetrica(float** A, int n){
	int i,j;
	int flag = 1;
	
	for(i = 0; i < n && flag; i++){
		for(j = i; j < n; j++){
			if(j != i){
				if(A[i][j] != A[j][i])
					flag = 0;
			}
		}
	}
		
	return flag;
}

//13. Se asigna a una matriz la identidad de nxn
float** identidad(int n){
	int i,j;
	float** I;
	
	do{
		I = (float**)malloc(n*sizeof(float*));
	}while(I == NULL);
	
	for(i = 0; i < n; i++){
		do{
			I[i] = (float*)calloc(n,sizeof(float));
		}while(I[i] == NULL);
		I[i][i] = 1;
	}
	
	return I;
}

//14. Retorna la suma de los cuadrados necesaria para los valores de L
float sum_cuad(float** L,int i){
	float r = 0;
	int j;
	
	for(j = 0; j<= i-1; j++){
		r += pow(L[i][j],2);
	}
	
	return r;
}

//15. Suma necesaria para los valores de L
float suma_i_j_esima(float** L, int i, int j){
	float r = 0;
	int k;

	for(k = 0; k <= i-1; k++){
		r += L[i][k]*L[j][k];
	}
	return r;	
}

//16. Elemento de la diagonal del renglon deseado
void diagonal(float** L,float** A,int i,int n){
	L[i][i] = sqrt(A[i][i]-sum_cuad(L,i));
}

//17. Elemento iesimo de L
void elemento_iesimo(float** L, float** A, int i, int n){
	int j;
	
	for(j = i+1; j < n; j++){
		L[j][i] = (1/L[i][i])*(A[j][i] - suma_i_j_esima(L,j,i));
	}
}

//18. Se asgina a una matriz la transpuesta de otra
void transponer(float** LT, float** L, int n){
	int i,j;
	
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			LT[i][j] = L[j][i];
		}
	}
	
}

