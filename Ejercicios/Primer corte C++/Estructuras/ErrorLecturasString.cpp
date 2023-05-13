#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <conio.h>
#include <string>
using namespace std;
int main(){
	string nombre;
	string apellido;
	cout << "Nombre:\n";
	//cin >>nombre; //Asi no!!!
	getline(cin,nombre);

	cout << "Apellido:\n";
	//cin >>apellido;
	getline(cin,apellido);
	cout<< "El nombre es: "<<nombre<<" - "<<apellido;
}