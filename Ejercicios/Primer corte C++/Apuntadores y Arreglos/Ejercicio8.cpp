#include <stdio.h>
#include <iostream>
#define filas 3
#define columnas 5
using namespace std;


void recorrer1 (int matriz[][columnas], int f, int c){
	cout<<"\nRecorrido de la matriz desde la funcion 'recorrer1\n\n";
	
	cout << "1. Recorrido con apuntadores\n"<<endl;
	for (int i=0;i<f;i++){
 		for (int j=0;j<c;j++){
 			cout<<  *(*(matriz+i)+j)<<" ";
	}
	cout<<endl;		 
	}	
	
	cout << "\n\n2. Recorrido con indices de la matriz\n"<<endl;
	for (int i=0;i<f;i++){
 		for (int j=0;j<c;j++){
 			cout<<  matriz[i][j]<<" ";
	}
	cout<<endl;		 
	}	
	
	
	
}
void recorrer2 (int *matriz[], int f, int c){
	cout<<"\nRecorrido de la matriz desde la funcion 'recorrer2\n\n";
	
	cout << "1. Recorrido con apuntadores\n"<<endl;
	for (int i=0;i<f;i++){
 		for (int j=0;j<c;j++){
 			cout<<  *(*(matriz+i)+j)<<" ";
	}
	cout<<endl;		 
	}	
	
	cout << "\n\n2. Recorrido con indices de la matriz\n"<<endl;
	for (int i=0;i<f;i++){
 		for (int j=0;j<c;j++){
 			cout<<  matriz[i][j]<<" ";
	}
	cout<<endl;		 
	}	
	
	
	
}
void recorrer3 (int **matriz, int f, int c){
	cout<<"\nRecorrido de la matriz desde la funcion 'recorrer3'\n\n";
	
	cout << "1. Recorrido con apuntadores\n"<<endl;
	for (int i=0;i<f;i++){
 		for (int j=0;j<c;j++){
 			cout<<  *(*(matriz+i)+j)<<" ";
	}
	cout<<endl;		 
	}	
	
	cout << "\n\n2. Recorrido con indices de la matriz\n"<<endl;
	for (int i=0;i<f;i++){
 		for (int j=0;j<c;j++){
 			cout<<  matriz[i][j]<<" ";
	}
	cout<<endl;		 
	}
}

int main(){
	
	
	int m[3][5]={ {110,210,310,410,220},{510,610,710,810,180},{910,1100,1110,120,43}   };
	int *ptrM[filas];
	
	cout <<"M:"<<m<<" *m:"<<*m<<" **m:"<<**m<<*(*(m+1)+1)<<endl;
	cout <<"M+1:"<<m+1<<" *m+1:"<<*(m+1)<<" **m+1:"<<**m+1<<endl;
	
	for (int i=0; i<filas;i++ ){
		ptrM[i]=m[i];
	}

	cout << "\n\nDatos de las filas\n Matriz"<<m<<endl;
	for (int i=0;i<filas;i++){
 			cout<< "("<< i<<" - "<<&m[i]<<") ->( "<<m<<"+"<<i<<"):"<< *(m+i)<<endl;
 			//Aqui el valor que se suma a la direccion de m es la longitud de cada fila * la posicion
 			//Ejemplo para i=2:
 			//Longitud de una fila = 5 posiciones de 4bytes = 20bytes, posicion 2
			//resultado=20*2=40, 40 en bytes = 28, es decir a la direccion de M,se suman 28 en hexadecimal	
			 
	}
	cout<<endl;		 
	


	cout << "\n\nDatos de la matriz original\n"<<endl;
	for (int i=0;i<filas;i++){
 		for (int j=0;j<columnas;j++){
 			cout<< "("<< m[i][j]<<" - "<<&m[i][j]<<")";
		}
		cout<<endl;		 
	}
	
	cout << "\n\nDatos de la matriz original v2\n"<<endl;
	
	for (int i=0;i<filas;i++){
 		for (int j=0;j<columnas;j++){
 			cout<< "("<< *(*(m+i)+j)<<" - "<<&m[i][j]<<")";
		}
		cout<<endl;		 
	}
		
	
	
	system("pause");
	recorrer1(m,filas,columnas);
	system("pause");
	recorrer2(ptrM,filas,columnas);
	system("pause");
	recorrer3(ptrM,filas,columnas);
	
}



