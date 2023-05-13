#include <iostream>
using namespace std;

int busquedaBinaria(int arreglo[],int inicio, int fin,int valor){
	int r=-1;	
	int mitad;
	if (inicio==fin){
		if (arreglo[inicio]==valor)
			r=inicio;
		else
			r=-1;
		cout <<"rango final:"<<"["<<inicio<<"]:"<< arreglo[inicio]<<" - ["<<fin<<"]:"<<arreglo[fin] <<" valor:"<<valor<<endl;
	}
	else{
		if ( (fin-inicio)==1)
			mitad=fin;
		else
			mitad=inicio +(fin-inicio)/2;	
		cout <<"rango:"<<"["<<inicio<<"]:"<< arreglo[inicio]<<" - ["<<fin<<"]:"<<arreglo[fin] <<" mitad:"<<mitad <<   "  valor:"<<valor<<endl;
		if (valor<arreglo[mitad])
			r=busquedaBinaria(arreglo,inicio,mitad-1,valor);
		else
			r=busquedaBinaria(arreglo,mitad,fin,valor);
	}
	return r;
}

int main(){
	int arreglo[]={2,4,6,8,11,13,15,19,23,34,43,52,60,62,63,67,71,79,81,100,150,200,201,205,206,207,209,210,211,212,213,214,215};
	int posiciones =sizeof(arreglo)/sizeof(int)-1;
	int lugar=0;
	int buscar =212;
	for (int i=0;i<=posiciones;i++){
		cout <<"["<<i<<"]:"<<arreglo[i]<< endl;
	}
	cout <<endl;
	lugar=busquedaBinaria(arreglo,0,posiciones,buscar);
	cout <<"Valor buscado:"<<buscar <<" Lugar :"<<lugar<<endl;
}