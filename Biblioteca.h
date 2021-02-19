#include <locale.h> 

//Decaracion de funciones
int ConfiguraIdioma();
int Portada();

//Definicion de funciones
int ConfiguraIdioma(){
	//Cambia al idioma Español   
	struct lconv *lcPtr;
	setlocale(LC_ALL, "spanish");
	lcPtr = localeconv();

	//Configura cantidades para México
	lcPtr->decimal_point = ".";
	lcPtr->thousands_sep = ",";
	lcPtr->grouping = "3";		
}

int Portada(){
	printf("\n				Universidad Nacional Autónoma de México \n");
	printf("				Facultad de Estudos Superiores Acatlan \n");
	printf("				Lic. Matemáticas Aplicadas y Computación\n\n");
	
	printf("						Métodos Numéricos \n");
	
		printf(" 					Gómez González Astrid Yoatziry \n");
		printf(" 					Navarro Ramos Karen Lizbeth \n");
		printf(" 					Rodriguez Nuñez Luisa Fernanda \n");

	system ("Pause"); 
}
