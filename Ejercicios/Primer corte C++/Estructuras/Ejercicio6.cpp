//Ejercicio 6
#include <iostream>
using namespace std;
int main(int arg, char *args[]){
	/*Tanaño de numeros*/
	
	cout<<"Entero: "<<sizeof(int)<<endl;
	cout<<"Long: "<<sizeof(long)<<endl;
	cout<<"Flotante: "<<sizeof(float)<<endl;
	cout<<"Double: "<<sizeof(double)<<endl;
	cout<<"Char: "<<sizeof(char)<<endl;
	cout<<"Unsigned int: "<<sizeof(unsigned int)<<endl;
	cout<<"Unsigned long: "<<sizeof(unsigned long)<<endl;
	cout<<"String: "<<sizeof(string)<<endl;
	cout<<"Bool: "<<sizeof(bool)<<endl;
	char cadena [20]="hola";
	cout<<"Variable cadena: "<<sizeof(cadena)<<endl;
	cout<< strlen(cadena); /*Una cosa es el tamaño de la variable,otra la longitud de la cadena*/
}