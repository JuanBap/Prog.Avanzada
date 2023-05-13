#include <stdio.h>
#include <iostream>
using namespace std;

int * tablas (int numero){
	static int aux[10];
	
	for (int i=0;i<10; i++){
		aux[i]=numero * (i+1);
		
	}
	return aux;
}
int main (){
	int numero;
	int *t;
	
	cout << "Ingrese el numero para las tablas de multiplicar. finalice con 0 :"<<endl;
	cin >> numero;
	while (numero!=0){
		t=tablas(numero);
		
		cout << "Esta es la tabla del :"<<numero<<endl;
		for (int i=0;i<10; i++){
			cout <<numero<< " * "<< i+1<<" = "<<t[i]<<endl;			
		}
		cout << "Ingrese el numero para las tablas de multiplicar. finalice con 0 :";
		cin >> numero;
	}
}

