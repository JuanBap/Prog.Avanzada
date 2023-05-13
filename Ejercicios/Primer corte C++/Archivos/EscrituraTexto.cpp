#include <fstream> 
#include <iostream>
using namespace std;
int main() 
{ 
	string variable="Escribe un string";
	cout <<"Abre archivo "<<endl;
	ofstream archivo("archivos1.txt",ios::out|ios::app ); 
	cout <<"Inicia llenado del archivo"<<endl;
	archivo << "Juan Perez, 454545, 120.5" << endl; 
	archivo << "Jaime Suarez, 35981, 2000.4" << endl; 
	archivo << "Maria Gomez, 58478, 354.0" << endl; 
	archivo << "Juan Sarmiento, 25874, 134.0" << endl ; 
	archivo << variable<<endl;
	cout <<"Escribe ultima linea del archivo"<<endl;
	
	char cad[100];
	
	cout <<"Lineas manuales, finaliza con 'fin'\n";
	do{
	
		cin.getline(cad,100);
		
		bool res=strcmp(cad,"fin");
		cout<<" Compara: "<<res<<endl;
		
		if (strcmp(cad,"fin")!=0) 
			archivo << cad<<endl;
	}while (strcmp(cad,"fin"));
	
	archivo.close(); 
	cout <<"Archivo cerrado"<<endl;
	printf ("fin");
	getchar();
	return 0;
} 
