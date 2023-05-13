
#include <iostream>
void display(double **);          // L3: función auxiliar-1
void borra(double **);            // L4: función auxiliar-2
int fil = 3;                       // L5: Número de filas
int col = 5;                       // L6: Número de columnas
using namespace std;

int main(void) {    // ==========
	double** data;                  // M1:
	data = new double* [fil];     // M3:
	
	for (int i=0;i<3;i++)
		cout<<"Direccion reservada para data["<<i<<"]:"<<(data+i)<<" que contiene :"<<data[i]<<endl;
	
	
    for (int j = 0; j < fil; j++) {    //
    	data[j] = new double [col]; // Fase-2: Establecer columnas iniciales

	}
	cout<<"\n\nDespues de asignar la memoria para las filas\n\n";
	for (int i=0;i<3;i++)
		cout<<"Direccion reservada para data["<<i<<"]:"<<(data+i)<<" que contiene :"<<data[i]<<endl;
	cout<<"\n\n";

    	
  	int k=1;
  	//Aqui se llena a data como si fuera una matriz comun y corriente. Esto se puede porque se definio como apuntador de apuntador
  	for (int i = 0; i < fil; i++)   
  		for (int j = 0; j < col; j++)
			data[i][j] = k++;
	
	cout<<"\n\nMemoria despues de asignar valores\n\n";	
	for (int i = 0; i < fil; i++)   {
  
		for (int j = 0; j < col; j++){
	  
    		cout<<"data["<<i<<"]["<<j<<"]:"<<(*(data+i)+j)<<"="<<*(*(data+i)+j)<<"  ";    	
    		//cout<<"data["<<i<<"]["<<j<<"]:"<<(*(data+i)+j)<<"="<<data[i][j]<<"  ";   //tambien funciona 	
		}
		cout<<endl;
	}	

		
  	cout<<"\n\nMatriz final"<<endl;  
  	display(data);                  // mostrar datos
  	borra(data);                     // borrar datos
  
  	cout <<"\nMostrar arreglo despues de borrado\n";
  	display(data);                  // mostrar datos
  	return 0;                        // terminar Ok.
}

void display(double **data) {     // Función auxiliar-1
	for (int i = 0; i < fil; i++) {
    	for (int j = 0; j < col; j++)
      		cout << data[i][j] << " ";
    	cout << "\n";
  }
}
void borra(double **data) {       // Función auxiliar-2
  for (int i = 0; i < fil; i++)   // A21:
    delete[] data[i];             // A22: Fase-1: Borrar columnas
}
