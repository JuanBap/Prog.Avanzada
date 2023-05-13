
#include <stdio.h>
#include <iostream>
using namespace std;

int main(){

	void *ptr; // puntero vacío 
	int i = 1; // 
	double d = 2.0; // double 
	ptr = &i; // funciona para un entero
	
	//Para poder leer o modificar el valor, hay que hacer un cast del tipo de apuntador
	*(int *)ptr=4;
	cout <<" ptr con entero:"<<*(int *)ptr << " en la direccion " <<(int *)&ptr << endl;
	ptr = &d; // funciona para un double
	*(double *)ptr=9;
	cout <<" ptr con doble:"<<*(double *)ptr<< " en la direccion " <<(double *)&ptr <<endl;
	

}