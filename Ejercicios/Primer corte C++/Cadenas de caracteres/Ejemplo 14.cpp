
#include <iostream>
#include <string>
using namespace std;
int main (){
	cout <<"Leer strings"<<endl;
	
	string pnombre;
	string nombrecompleto;
	string direccion;
	
	cout<< "escriba el primer nombre :"<<endl;
	cin >> pnombre;
	cout <<"Te llamas :" << pnombre<<endl;
	fflush(stdin);
	cout<< "\nEscribe tu nombre completo:"<<endl;
	getline (cin,nombrecompleto);
	cout <<" Tu nombre completo es :" << nombrecompleto;
	
}