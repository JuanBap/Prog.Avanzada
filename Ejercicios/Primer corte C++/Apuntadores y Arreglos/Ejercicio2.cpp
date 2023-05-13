#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

//char *mayusculas(char s[]){
char * mayusculas(char *s){
	while (*s!='\0'){
		if (*s >='a' && *s<='z'){
			*s-=32;
			
		}
		s++;
	}
	return s;
}


int main()
{
	char cadena[20];
	char *respuesta;
	cout << "Escriba una cadena en minusculas "<<endl;;
	cin.getline(cadena,20);
	respuesta=mayusculas(cadena);
	cout <<"En mayusculas"<<endl;
	cout <<"Cadena:"<<cadena<<endl;
	cout <<"Respuesta:"<<respuesta<<endl;
	
	//Repaso de char
/*	char a='a', b='j';
	char r =a+b;
	int  t=a+b;
	cout<<"r:"<<r<<endl;
	cout<<"t:"<<t<<endl;
	*/
	
	
}

