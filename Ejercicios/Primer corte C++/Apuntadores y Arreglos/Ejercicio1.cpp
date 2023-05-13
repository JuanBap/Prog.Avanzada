#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
	int tabla[10],i,x,*pt,*ptr;
	cout << "Arreglo sin inicializar: ";
	for (i=0; i <10; i++)
		cout << " - "<<tabla[i];
	cout <<endl;
	
    pt = &tabla[0];
    cout << "pt = &tabla[0]-> Direccion: "<<pt<<endl;
    pt = tabla;
    cout << "pt = tabla-> Direccion: "<<pt<<endl;
    for (i=0; i <10; i++)
		//Aqui hacemos la asignacion usando la variable po
		*(pt+i) = rand() % 100;
	
	//A x, le asignamos el valor de la segunda posicion de pt	
	x = *(pt+1);
	cout<<" x: "<<x<<endl;
	
		
	//Aqui asignamos a ptr, la direccion de la primera posicion de tabla
	ptr = tabla;
	
	printf ( "Desplegando Arreglo: %d %d %d.......\n",3,2,1);
	
	for (i=0; i <10; i++)
    	printf("[%d - %d]",*(ptr+i),tabla[i]);
}