//Ejercicio 2
#include <iostream>
using namespace std; 
int main(int arg, char *args[]){

   int tabla2 [2][3] = { {50,51,52},{53,54,55}};   
   int e;
   
	for (int n=0;n<2;n++){
		for (int m=0;m<3;m++){
			cout << " ["<<n<<","<< m <<"]:"<<tabla2[n][m];		
        }
        cout << endl;
	}
	
   	int x[e]; //Esto no se debe hacer, e no esta inicializada   
   	cout <<"Valor de e sin inicializar:"<<e<<endl;
   	x[0]=10;
	cout <<"Valor de X[0]:"<<x[0]<<endl;
	
	cout <<"\nIndique Elementos: ";
	cin >> e;
	int numeros[e];//Se puede declarar el tamaño de un arreglo con una variable
	for (int i=0;i<e;i++){
		numeros[i]=rand()%10000;
	}
	for (int i=0;i<e;i++){
		cout <<"Numero aleatorio "<<(i+1)<<":"<<numeros[i]<<endl;
	}
	
}
