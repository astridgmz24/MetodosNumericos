#include <locale.h> 

//Decaracion de funciones
int ConfiguraIdioma();
int Portada();

//Definicion de funciones
int ConfiguraIdioma(){
	//Cambia al idioma Espa�ol   
	struct lconv *lcPtr;
	setlocale(LC_ALL, "spanish");
	lcPtr = localeconv();

	//Configura cantidades para M�xico
	lcPtr->decimal_point = ".";
	lcPtr->thousands_sep = ",";
	lcPtr->grouping = "3";		
}

int Portada(){
	printf("\n				Universidad Nacional Aut�noma de M�xico \n");
	printf("				Facultad de Estudos Superiores Acatlan \n");
	printf("				Lic. Matem�ticas Aplicadas y Computaci�n\n\n");
	
	printf("						M�todos Num�ricos \n");
	
		printf(" 					G�mez Gonz�lez Astrid Yoatziry \n");
		printf(" 					Navarro Ramos Karen Lizbeth \n");
		printf(" 					Rodriguez Nu�ez Luisa Fernanda \n");

	system ("Pause"); 
}
