#include <fstream>
#include <iostream>
#include <vector>
#include <string.h>
#include <conio.h>

using namespace std;
typedef struct estudiante_t
{
    char nombre [50];
    char codigo [20];
    float notas[3];
};

void adicionarRegistro();
void guardarArchivo(estudiante_t estudiante[],int registros);

int main()
{
	
	adicionarRegistro();
    
	
   	return 0; 
}
void adicionarRegistro(){
	int registros;
	cout << "======================================"<<endl;
	cout << "Indique numero de registros a procesar:" ;
	cin >>registros;
	
	
	fflush(stdin);   //Limpiar el buffer de entrada por consola

	estudiante_t estudiante[registros];  
	for(int f = 0; f < registros; f++){
	  cout <<"\nDatos del estudiante Nro: [" << f+1 <<"]  \n";	
	  cout <<"Ingrese Nombre: ";
	  //cin.getline(estudiante[f].nombre, 50);
	  gets(estudiante[f].nombre);
	  fflush(stdin);   //Limpiar el buffer de entrada por consola
	  cout << "Ingrese Codigo: ";
	  cin >> estudiante[f].codigo;
	  fflush(stdin);   //Limpiar el buffer de entrada por consola
	  for (int i=0;i<3;i++){
	  	cout <<"  Ingrese Nota Nro: [" << i+1 <<"] : ";	
	  	cin >>estudiante[f].notas[i];
	  	fflush(stdin); 
	  }
	  fflush(stdin);   //Limpiar el buffer de entrada por consola 	  
	 }

    guardarArchivo(estudiante,registros);
}



void guardarArchivo(estudiante_t estudiante[],int registros){
	cout <<"guardando datos\n";
	ofstream output_file("estudiantes.dat", ios::binary|ios::app|ios::ate);
	for (int i=0;i<registros;i++){
		output_file.write((char*)&estudiante[i], sizeof(estudiante[i]));//Aqui se envia al archivo un registro a la vez
	}
	output_file.close();	
}

