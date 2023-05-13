#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <conio.h>
using namespace std;
int main(){
	char nombre[100];
	char apellido[100];
	cout << "Nombre:\n";
	//cin >>nombre; Asi no!!!
	cin.getline (nombre,100);

	cout << "Apellido:\n";
	cin.getline (apellido,100);

	
	cout<< "El nombre es: "<<nombre<<" - "<<apellido;
}