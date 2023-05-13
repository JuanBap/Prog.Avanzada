#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <conio.h>
using namespace std;

struct StrEstudiante{
 	char nombre[100];
 	char apellidos[100];
 	char nro_id[20]; 
 	short edad;
 };




StrEstudiante estudiantes[100];

void datosEstudiantes(int registros);
void mostrarDatos( StrEstudiante vEstudiantes[] , int est) ;

 
int main(){

 int est;	
 cout << "\t\t PROGRAMA DE CARGA DE DATOS ESTUDIANTES";
 cout << "\n\t\t ====================================";
 
 cout <<"\nIngrese numero de estudiantes (numero menor que 100): ";
 cin >> est;
 fflush(stdin);
 datosEstudiantes(est);
 mostrarDatos(estudiantes,est);
 
 
 return 0;
}

void datosEstudiantes(int est){ 
 int f;
 
 for(f = 0; f < est; f++){
   
  cout <<"\nDatos del estudiante Nro: [" << f+1 <<"]  ";	
   	
  cout <<"\nIngrese Nombre: ";
  cin.getline (estudiantes[f].nombre,100);
  /*Si la variable a leer fuera tipo string, se debe usar
  	getline(cin,nombreVariable);
  	*/
  
  
  
  cout << "Ingrese Apellidos: ";
  cin.getline (estudiantes[f].apellidos,100);
  cout << "Ingrese Nro. Id: ";
  cin.getline (estudiantes[f].nro_id,20);
  cout << "Ingrese Edad: ";
  cin >> estudiantes[f].edad;
  fflush(stdin); //Utilizar este comando despues de leer numeros, si la siguiente lectura es un string o char[]
 }
 

}

void mostrarDatos( StrEstudiante vEstudiantes[] , int est) {
 system("cls");
 cout << "\t\t REPORTE DE CARGA DE DATOS ESTUDIANTES";
 cout << "\n\t\t ====================================="<<endl<<endl;
 for(int f = 0; f < est; f++){
  cout <<" Nombre: "<< vEstudiantes[f].nombre <<" ";
  cout <<" Apellidos: "<< vEstudiantes[f].apellidos <<" ";
  cout <<" Nro. Id: "<< vEstudiantes[f].nro_id <<" ";
  cout <<" Edad: "<< vEstudiantes[f].edad <<" ";
  cout << endl;  
 }
 //getchar();
}

