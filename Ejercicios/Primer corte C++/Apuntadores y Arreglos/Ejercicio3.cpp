
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;
char  *mayusculas(char *s);

int main()
{
	char cadena[20];
	char *respuesta;
	cout << "Escriba cadena en minusculas "<<endl;;
	cin.getline(cadena,20);
	cout <<"En mayusculas"<<endl;
	respuesta=mayusculas(cadena);
	cout <<respuesta<<endl;
}


char *mayusculas(char *s){
	
	static char cad[20]={};
	int i=0;
	while (*s!='\0'){
		if (*s >='a' && *s<='z'){
			cad[i]=*s-32;
			i++;
		}
		else if (*s==' ')
			cad[i++]=' ';		
		s++;
	}
	return cad;	
}

