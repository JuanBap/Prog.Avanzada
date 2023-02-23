/* 
-----TALLER 01 EJERCICIO 1-----

Fecha: 11/04/23
Autor: Juan Pablo Canon Contreras
Tema: Arreglos, numeros aleatorios, funciones

Solucion:
1.- Crear un array con 10 elementos
2.- Crear una funcion para generar números aleatorios entre 0 y 25
3.- Llenar el array con 10 números aleatorios
4.- Crear un puntero
5.- Imprimir el contenido del array usando el puntero
6.- Imprimir las direcciones del contenido del array usando el puntero.

*/

//Incluimos bibliotecas
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <vector>


using namespace std;

//Prototipo de la funcion
void aleatorio(int *arreglo); //2. Funcion de numeros aleatorios


//Inicio del programa principal
int main(){

	int arreglo[10];	//1. Declaramos nuestro arreglo de 10 casillas
	int *ptr;			//4. Declaramos nuestro apuntador de tipo entero
	ptr=arreglo;		//Le indicamos mirar hacia la primera posicion de nuestro arreglo
	

	//Hacemos el llamado de la funcio que va a llenar el arreglo con numeros aleatorios
	aleatorio(arreglo);

	cout<<"Taller 1 - ejercicio 1\nAutor: Juan Pablo Canon\n";


	cout<<"\n1. Imprimios el contenido del arreglo haciendo uso de cout<<arreglo[i]: \n";
	cout<<"\n[ ";
		for(int i=0; i<10; i++){
			cout<<arreglo[i]<<" ";		
		}	
	cout<<"]\n\n";

	cout<<"\n2. Imprimimos las direcciones de memoria de las casillas del arreglo haciendo uso de cout<<&arreglo[i]: \n\n";
		for(int i=0; i<10; i++){
			cout<<&arreglo[i]<<" ";		
		}
	cout<<"\n\n";

	//5. Imprimios el contenido haciendo uso del puntero
	cout<<"\n3. Imprimimos el contenido del arreglo haciendo uso de cout<<*(ptr+i): \n\n";
	cout<<"[";
		for(int i=0; i<10; i++){
			cout<<*(ptr+i)<<" ";
		}
	cout<<"]\n";

	//6. Imprimimos las direcciones de memoria haciendo uso del puntero
	cout<<"\n\n4.Imprimimos las direcciones de memoria de las casillas del arreglo haciendo uso de cout<<ptr+i: \n\n";
		for(int i=0; i<10; i++){
			cout<<ptr+i<<" ";		
		}
	cout<<"\n\n";
	cout<<"\n5. Como podemos observar tanto el valor del vector como sus direcciones de memoria coinciden por lo que podemos\n";
	cout<<"    que hicimos bien nuestro trabajo y aprendimos a usar apuntadores para acceder las variables y sus direcciones.";
	
}
//Finaliza el programa principal

//Funcion de numeros aleatorios
//Como el arreglo es un apuntador lo podemos enviar como parametro de la siguiente manera: int *arreglo
void aleatorio(int *arreglo){ 

//Definimos nuestra funcion de numeros aleatorios

	srand(time(NULL));					//Sintaxis para el uso de srand

		for (int j=0;j<10;j++){			//Hacemos un ciclo que vaya iterando en cada posicion del arreglo
 			arreglo[j]=0+rand() % 25;	//3.Llenar el arreglo con 10 numeros aleatorios
	 	} 	
	//La funcion no devuelve nada porque es void y enviamos el arreglo por referencia
}
