#include <iostream>
int global=42;
using namespace std;

int numero (int *&p){//La variable apuntador se pasa por valor
	cout <<" dentro de la funcion numero p:"<<*p<<" en la direccion: "<< p <<endl;	
	*p=8;
	p=&global;
	//p= new int; o asignarle memoria dinamica
	cout <<" despues de cambiar p por la direccion de global:"<<*p<<" en la direccion: "<< p <<endl;	
}
using namespace std;
int main (){
	int j=10;	
	
	cout<< "Direccion de la variable global en main:"<<&global<<endl;
	
	int *pj = &j;	
	cout <<" pj:"<<*pj<<" en la direccion "<<pj<< endl;
	numero (pj);	
	cout <<" Retornado de numero  pj:"<<*pj<<" en la direccion "<<pj<< endl;
	
	cout <<" j:"<<j<<endl;
}