#include <iostream>
using namespace std;

typedef struct estudiante{
	char nombre [10];
	char carrera[20];
};

int main(){
		
	int *i = nullptr;
	i=new int;
	cout << "Direccion de i: "<<i;
	cout << "\nValor de i antes de asignar: "<<*i;
	*i=20;
	cout << "\nValor de i: "<<*i;
	delete i; //Esto libera la memoria {es decir la deja disponible para el SO}
	i=nullptr;
	cout << "\nDireccion de i: "<<i<<endl;	
	/*	
	Si se intenta mostrar el valor de i despues de asignar nullptr, el programa fallará
	cout << "\nValor de i despues de delete: "<<*i;
	*/
	//cout << "\nValor actual de i: "<<*i;
	
	int j=5;
	int *ptrJ = new int;
	cout <<"Direccion de  ptrj "<<ptrJ<<endl;
	ptrJ=&j;
	cout << "Valor de *ptrJ: "<<*ptrJ<< " ubicado en :"<< ptrJ<<endl;
	
	int *v = new int[j]; /*Declaracion dinamica de un arreglo*/	
	for (int k=0; k<j;k++)
		v[k]=k+3;
	cout <<"\n Arrreglo creado dinamicamente paso 1\n";
	for (int k=0; k<j;k++)
		cout << "  "<< v[k];
	
	v = new int[(j*2)]; /*Redimensionamiento*/	
	for (int k=j; k<10;k++)
		v[k]=k+3;
		
	cout <<"\n Arrreglo redimensionado dinamicamente paso 2\n";
	for (int k=0; k<10;k++)
		cout << "  "<< v[k];
	
	cout <<"\n";
	//delete v;//Esto solo libera la posicion cero del arreglo, no se recomienda utilizar*/
	delete []v; /*Liberar la memoria dinamica de un arreglo*/
	
	cout <<"\n Informacion del arrreglo despues de delete\n";
	for (int k=0; k<10;k++)
		cout << "  "<< v[k];
	
	cout <<"\n";
	
	v=nullptr; //Siempre asignar nullptr despues de realizar delete
	
	cout <<"\n Estructura creado apuntador dinamico\n";
	
	estudiante *est = new estudiante ;
	strcpy(est->nombre,"ramon");
	strcpy(est->carrera,"ingenieria");
	
	
	cout <<"\nnombre :"<<est->nombre;
	cout <<"\ncarrera :"<<est->carrera<<endl;
	
	int registros=3;
	cout <<"\n Estructura creado apuntador dinamico en un arreglo\n";
	estudiante *ests =  new estudiante[3];
	for (int i=0;i<registros;i++){
		cout << "Estudiante "<<i+1<<endl;
		cout <<" Ingrese nombre :";
		cin.getline(ests[i].nombre,10);
		cout <<" Ingrese carrera :";
		cin.getline(ests[i].carrera,20);
	}
	
	for (int i=0;i<(registros);i++){
		cout << "Estudiante "<<i+1<<endl;
		cout << "Nombre: "<< ests[i].nombre<<endl;
		cout << "Carrera: "<< (ests+i)->carrera <<endl;		
		//cout << "Carrera: "<< (*(ests+i)).carrera <<endl;	//Tambien funciona
	}
	
	delete []ests;
	
	/*Errores*/
	
	/*Error 1: Asignar valor a un apuntador dinamico despues de ejecutar delete
		int *k = new int;
		*k=2;
		delete k;
		k=nullptr;
		*k=3;//Aqui hay error
		cout<<" k:"<<*k<<endl;
	/**/
	
}