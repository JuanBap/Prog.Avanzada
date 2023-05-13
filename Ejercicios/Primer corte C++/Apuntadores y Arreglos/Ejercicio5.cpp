#include <stdio.h>
#include <iostream>
using namespace std;

typedef struct estudiante{

	char nombre[20];
	char carrera[20];
	float promedio;
};

estudiante *leerEstudiantes (int numero){
	static estudiante estudiantes[10];
	
	for (int i=0; i<numero;i++){
		cout <<"Registro "<<i+1<<endl;
		cout <<"Nombre: ";
		cin.getline(estudiantes[i].nombre,20);
		cout <<"Carrera: ";
		cin.getline(estudiantes[i].carrera,20);
		cout <<"Promedio: ";
		cin >>estudiantes[i].promedio;		
		fflush(stdin);
	}
	
	cout<< "Direccion de estudiantes en la funcion:"<<estudiantes<<endl;
	return estudiantes;
	
	
	
}
int main (){
	
	int nroEstudiantes;
	
	cout << " Numero de estudiantes : ";
	cin >>nroEstudiantes;
	fflush(stdin);
	estudiante *estudiantes;
	estudiante *est;
	estudiantes =leerEstudiantes(nroEstudiantes);
	cout<< "Direccion de fuera de la funcion: "<<estudiantes<<endl;
	
	cout <<" Registros cargados \n\n";
	
	for (int j=0;j<nroEstudiantes;j++){
		cout <<"Registro "<<j+1<<endl;
		cout <<"  Nombre: " <<estudiantes[j].nombre<<endl;
		cout <<"  Carrera: " <<estudiantes[j].carrera<<endl;
		cout <<"  Promedio: " <<(estudiantes+j)->promedio<<endl<<endl;//Tener en cuenta la sintaxis		
	}
	
	
	cout <<"Registro unico"<<endl;
	cout <<"Nombre: ";
	cin.getline(est->nombre,20);
	cout <<"Carrera: ";
	cin.getline(est->carrera,20);
	cout <<"Promedio: ";
	cin >>est->promedio;		
	fflush(stdin);
	
	//Tener en cuenta la sintaxis cuando el apuntador a estructura no es un arreglo
	cout<< "\nInformacion de un registro unico\n";
	cout <<"Nombre:"<<est[0].nombre<<endl;
	cout <<"Carrera:"<<est->carrera<<endl;
	cout <<"Promedio:"<<(*est).promedio<<endl;
}
