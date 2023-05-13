#include <iostream>
using namespace std;
void asignar(char variable[]){
	strcpy(variable,"pedro");
}

int main(){	
	char nombre[10];	
	asignar(nombre);
	cout<< "nombre:"<<nombre;	
}