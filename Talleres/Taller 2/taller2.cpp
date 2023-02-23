/* 
Fecha: 15/04/23
Autor: Juan Pablo Ca��n Contreras
Tema: Arreglos, Clase vector, aleatoriedad, funciones

Crear una forma para generar un conjunto de n�meros aleatorios, tal que, se pueda contar la frecuencia y poder fraficar tipo histograma.

Se recomienda usar funciones, arrays y la clase vector de STL.

*/

//Incluimos las bibliotecas
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <iomanip>


using namespace std;


//Declaramos las estructuras
struct Frecuencia{

  int numero;
  int frecuencia;

};

struct Conjunto{
	int tamano;
	int numeros[];
	int max;
	
}espacio;

//Prototipos funciones
void randoms();
void histo();

//Inicia el programa principal
int main(){
	//Conjunto numeros; //Se crea para almacenar los n�meros que necesitamos
	int opcion;

	do{
	
	cout << "Taller 02 - Ejercicio 1\n\nAutor: Juan Pablo Canon\n";	
	cout << "\n-- Menu Principal -- \n" << endl;
	cout << "0. Salir" << endl; 
	cout << "1. Generar conjunto de valores aleatorios" << endl;
	cout << "2. Generar histograma del conjunto de valores aleatorios\n\n" << endl;
	cout << "Digite su opcion: ";
	cin >> opcion;
	

	//Caso switch para el menu
	switch (opcion){
	  
	    case 1:{          
				randoms();	//Llena el arreglo con numeros aleatorios
	            break;
	        }
	        case 0:	
	        {
	            cout << "Saliendo..." << endl;	//Sale del programa
	            exit (1);
	            break;
	        }
	        
	        case 2:	histo(); break; //Imprime el histograma
	
	        default:
	        {
	          break;
	        }
	        }    
	}while (opcion != 0);
    
    return 0;
}


//Funcion aleatorios
void randoms(){

	system("cls");
	int aux=0;

	srand(time(NULL));
	

	//Llenando el vector
	cout<<"Llenando el vector...\n\n";

	cout<<"Ingrese el tamaño que desea del vector entre 10 y 20: ";
	cin>>espacio.tamano;
	
	cout<<"\nSu arreglo de numeros aleatorios es: \n\n[";

	//Imprimimos el arreglo para que el usuario pueda visualizar los numeros

	for(int i=0; i<espacio.tamano; i++){
		espacio.numeros[i]= 0+rand ()% 21;
		cout<<" "<<espacio.numeros[i]<<" ";
	}

	cout<<"]"<<endl; 

	int temporal[espacio.tamano];
	for(int i=0; i<espacio.tamano; i++){
		temporal[i]=espacio.numeros[i];
		//cout<<" "<<temporal[i]<<" ";
	}
	
	cout<<"\nCapacidad del arreglo:  "<<espacio.tamano<<endl;
	fflush(stdin);

	for(int i=0; i<espacio.tamano; i++){				
		if(temporal[i]>aux)
			aux=temporal[i];
	}
	fflush(stdin);
	espacio.max=aux;
	cout<<"\nEl numero mayor en el arreglo: "<<espacio.max<<endl;
	
	espacio.numeros[0]=temporal[0];	//Se puteaba en la posici�n [0]
	

	getch();
	system("cls");
}



void histo(){

	system("cls");


	bool aparece[21] = { false };
    int sizeResultado = 0;
	int arrResultado[21] = {0};

    for (int i = 0; i < espacio.tamano ; i++) {

        if (!aparece[espacio.numeros[i]]) {
        
		    aparece[espacio.numeros[i]] = true;
        
		    arrResultado[sizeResultado] = espacio.numeros[i];
        
		    sizeResultado++;
        }
    }

	cout<<"[ ";

	for(int i = 0; i < espacio.tamano; i++){

		cout<<espacio.numeros[i]<<" ";
	}

	cout<<" ]\n\n";

	cout<<"El arreglo sin repetir los numeros queda: \n\n"<<"[ ";


	for (int i = 0; i < sizeResultado; i++) {
        cout << arrResultado[i] << " ";
    }
	cout<<"]";
	cout<<endl; 
	int temp; 
	for (int i = 0; i<sizeResultado-1;i++){
		for(int j = 0; j<sizeResultado-i-1;j++){
			if(arrResultado[j]>arrResultado[j+1]){
				temp = arrResultado[j]; 
				arrResultado[j] = arrResultado[j+1];
				arrResultado[j+1] = temp;  
			}
		}
	}

	

	cout<<"\n\nEl arreglo ordenado de mayor a menor es: \n\n[ ";

	for (int i = 0; i < sizeResultado; i++) {
        cout << arrResultado[i] << " ";
    }
	cout<<"]\n\n";
	
	Frecuencia final [sizeResultado];
	int reps = 0;
	
	for (int i = 0; i < sizeResultado; i++)
	{
		reps = 0;
		for (int j = 0; j < sizeResultado; j++)
		{
		
			if(arrResultado[i]==espacio.numeros[j]){

				reps++;

				if(reps == 0);




			}

			final[i].numero = arrResultado[i];
			final[i].frecuencia = reps;
		}
		
	}

	for (int i = 0; i < sizeResultado; i++)
	{
		if(final[i].frecuencia == 0)

			final[i].frecuencia = final[i].frecuencia + 1;
	}
	

	cout<<endl;

	cout<<"Su histograma es.....\n\n";

	cout<<setw(10)<<"Index"<<setw(10)<<"Valor"<<""<<setw(10)<<"\tHistograma\n"<<endl;
	
	for (int i = 0; i < sizeResultado; i++)
	{
			
			cout<<setw(10)<<i<<setw(10)<<final[i].numero<<setw(10);

			for (int j = 0; j < final[i].frecuencia; j++)
			{
				cout<<"* ";
			}
			
			cout<<endl;

	
		}


	getch();
	system("cls");


}
