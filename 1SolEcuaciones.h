#include <stdio.h>
#include <math.h>
#include <ctype.h>

//Variables globales
	float x,a,b;
	int datoFun, datoMet;
	
//Declaracion de Funciones
	float ecu1(float x);
	float ecu2(float x);
	float ecu3(float x);
	float ecu4(float x);
	void MenuFun();
	void MenuMet();
	void Biseccion();
	void Secante();
	

void Sol_Ecuaciones(){
	system("CLS");
	printf("\n\t\t SOLUCION DE ECUACIONES");
	char sn1,sn2;
	float fun=0;
	
		do{                                           //Elegir funcion
			MenuFun();	
			do{                                        //Elegir metodo
				MenuMet();
				
				switch(datoMet){
					case 1:   //Biseccion
						switch(datoFun){
							case 1:
								Biseccion(ecu1);				
								break;
							case 2:
								Biseccion(ecu2);
								break;
							case 3:
								Biseccion(ecu3);
								break;
							case 4:
								Biseccion(ecu4);
								break;
							case 5:
								main();
								break;
							default:
								printf("\n Opción no valida.");
								break;
						}
						break;
					case 2:   //Secante 
						switch(datoFun){
							case 1:
								Secante(ecu1);				
								break;
							case 2:
								Secante(ecu2);
								break;
							case 3:
								Secante(ecu3);
								break;
							case 4:
								Secante(ecu4);
								break;
							case 5:
								main();
								break;
							default:
								printf("\n Opción no valida.");
								break;
						}
						break;
					case 3: //Regresar
						Sol_Ecuaciones();
						break;
					case 4: //MenuPrincipal
						main();
						break;
					default:
						printf("\n Opción no valida");
						break;
				}
				printf("\n\nDesea realiar la funcion por otro metodo [s/n]: ");
				fflush(stdin);
				scanf("%c",&sn1);
			}while (sn1=='s'||sn1=='S');
			
			printf("\n\nDesea regresar al menu para elegir otra funcion [s/n]: ");
			fflush(stdin);
			scanf("%c",&sn2);
		}while (sn2=='s'||sn2=='S');
		main();
}

void MenuFun(){
	printf("\n\t Funciones: \n\n");
	printf("1  ->  f(x)=x^2cosx-2x \n");
	printf("2  ->  f(x)=(6-2/x^2)e^(2+x)/4+1 \n");
	printf("3  ->  f(x)=x^3-3senx^2+1\n");
	printf("4  ->  f(x)=x^3+6x^2+9.4x+2.5 \n");
	printf("5  ->  Menu Principal \n");
	
	printf("\nElige la opción de la función a relizar: ");
	fflush(stdin);
	scanf("%d",&datoFun);
}

void MenuMet(){
	printf("\n \tMetodos\n");
	printf("1. Metodo de Biseccion\n");
	printf("2. Metodo de la Secante\n");
	printf("3. Regresar \n");
	printf("4. Menu Principal \n");
	
	printf("\nElige el metodo por el cual quieres realizar la funcion: ");
	fflush(stdin);
	scanf("%d",&datoMet);
}

float ecu1(float x){
	return pow(x,2)*cos(x)-2*x;
}

float ecu2(float x){
	return (6-2/pow(x,2))*exp(2+x)/4+1;
}

float ecu3(float x){
	return pow(x,3)-3*sin(pow(x,2))+1;
}

float ecu4(float x){
	return pow(x,3)+6*pow(x,2)+9.4*x+2.5;
}

void Biseccion(float (*puntero)(float)){
	float tolerancia, e_rel, p, aux;
	int iteraciones, i;
	char otravez;
	
	do{
		printf("\n\n \t Metodo de bisección \n");
		
		printf("Ingrese el intervalo inicial [a,b] \n");
		printf("a= ");
		fflush(stdin);
		scanf("%f",&a);
		printf("b= ");
		fflush(stdin);
		scanf("%f",&b);
		
		printf("Ingrese la tolerancia deseada para error relativo \n");
		fflush(stdin);
		scanf("%f",&tolerancia);
		
		printf("Ingrese el maximo de iteraciones \n");
		fflush(stdin);
		scanf("%d",&iteraciones);
		
		i=0;
		p=0;
		
		if ((puntero(a))*(puntero(b))<=0){
			printf("|\t i |\t a     |\t b     |\t f(a)    |\t f(b)  |\t p     |\t f(p)    |\t e.rel%   | \n");
			
			do{
				x=p;
				p=(a+b)/2;
				
				e_rel=fabs((p-x)/p)*100;
				
				printf("|\t%d|\t%f|\t%f|\t%f|\t%f|\t%f|\t%f|\t%f|\n",i,a,b,puntero(a),puntero(b),p,puntero(p),e_rel);
				i=i+1;
				
				aux=puntero(a)*puntero(p);
				if (aux<0){
					b=p;
				}else if (aux>0){
					a=p;
				}else{
					e_rel=0;
				}
				
			}while(i<iteraciones+1 && e_rel>tolerancia);
			
			if (e_rel<=tolerancia){
				printf("\n \t Raiz encontrada en %f en la iteracion %d con los datos ingresados",x,i-2);
			}else{
				printf("\n \t Raiz encontrada en %f en la iteracion %d con los datos ingresados",p,i-1);
			}
			
			
		}else{
			printf("No existen raices reales en ese intervalo");
		}
		
		printf("Desea intentar con otro intervalo? [s/n] \n");
		fflush(stdin);
		scanf("%c",&otravez); 
	}while(otravez=='s'||otravez=='S');
}

void Secante(float (*puntero)(float)){
	float tolerancia, e_rel, p, aux;
	int iteraciones, i;
	char otravez;
	
	do{
		
		printf("\n\n \t Metodo de Secante \n");
		
		printf("Ingrese el intervalo inicial [x0,x1] \n");
		printf("x0= ");
		fflush(stdin);
		scanf("%f",&a);
		printf("x1= ");
		fflush(stdin);
		scanf("%f",&b);
		
		printf("Ingrese la tolerancia deseada para error relativo porcentual \n");
		fflush(stdin);
		scanf("%f",&tolerancia);
		
		printf("Ingrese el máximo de iteraciones \n");
		fflush(stdin);
		scanf("%d",&iteraciones);
		
		i=0;
		p=0;
		
			printf("|\t i |\t x0     |\t x1     |\t f(x0)    |\t f(x1)  |\t x2     |\t f(x2)    |\t e.rel%   | \n");
			
			do{
				x=p;
				p=((b-puntero(b)*(a-b))/(puntero(a)-puntero(b)));
				
				e_rel=fabs((p-x)/p)*100;
				
				printf("|\t%d|\t%f|\t%f|\t%f|\t%f|\t%f|\t%f|\t%f|\n",i,a,b,puntero(a),puntero(b),p,puntero(p),e_rel);
				i=i+1;
				
				a=b;
				b=p;
				
			}while(i<iteraciones+1 && e_rel>tolerancia);
			
			if (e_rel<=tolerancia){
				printf("\n \t Raiz encontrada en %f en la iteracion %d con los datos ingresados",x,i-2);
			}else{
				printf("\n \t Raiz encontrada en %f en la iteracion %d con los datos ingresados",p,i-1);
			}
		
		printf("\n Desea intentar con otro intervalo? [s/n] \n");
		fflush(stdin);
		scanf("%c",&otravez);
	}while(otravez=='s'||otravez=='S');
}

