
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

char *mayusculasError1 (char *s);
char *mayusculasError2 (char *s);

int main()
{
	char cadena[20];
	char *respuesta;
	cout << "Escriba una cadena en minusculas "<<endl;;
	cin.getline(cadena,20);
	cout <<"Llamado a funcion Error 1"<<endl;
	respuesta=mayusculasError1(cadena);
	cout <<"Salida de Error1: "<<respuesta<<endl;
	cout <<"Llamado a funcion Error 2:"<<endl;
	respuesta=mayusculasError2(cadena);
	cout <<"Salida de Error2:"<<respuesta<<endl;
	
	
}


char *mayusculasError1(char *s){
	
	char cad[20]={};
	char *p;
	int i=0;
	while (*s!='\0'){
		if (*s >='a' && *s<='z'){
			cad[i]=*s-32;
			i++;
		}
		s++;
	}
	p=cad ;
	cout<<"Cad dentro de MayusculasError1: "<<cad<<endl;
	return p;	
	
}


char *mayusculasError2(char *s){
	
	/*static*/ char cad[20]={};
	int i=0;
	while (*s!='\0'){
		if (*s >='a' && *s<='z'){
			cad[i]=*s-32;
			i++;
		}
		s++;
	}
	cout<<"Cad dentro de MayusculasError2: "<<cad<<endl;
	return cad;	
}
