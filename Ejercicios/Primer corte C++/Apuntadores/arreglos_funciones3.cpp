#include <iostream>
#define largo 10
 int * llenarArreglo1(int n);
 using namespace std;
 int main (){
 	int n;
 	int *arreglo;
 	int arreglo1[100];
 	cout <<"Cuantos numeros quiere llenar:";
 	cin>>n;
 	fflush(stdin);
 	
 	arreglo=llenarArreglo1(n); 	 	
    
 	
	for (int j=0;j<n;j++){
 		 cout<<"arreglo:"<<arreglo[j]<<endl;
		 //cout<<"ptr:"<<*(arreglo++)<<endl;
		
	 } 	
	 
 } 
 int * llenarArreglo1(int n){
 	int p=10;
    static int num[100];
    /*
    C++ no permite devolver la dirección de una variable local fuera de la función, 
	por lo que se debe definir la variable local como variable estática
	
	El valor de una variable estatica no se pierde aunque ya no se encuentre dentro del alcance, 
	es decir, cuando el programa haya salido de la función en que la variable fue definida. 
	Esto diferencia una variable estática de una variable no estática, 
	cuyo valor se pierde al final de la función.

	Debido a esta diferencia aunque no sean accesibles durante toda la ejecución del programa, 
	las variables estáticas existen durante toda la ejecución del programa.	
    */
 	for (int j=0;j<n;j++){
 		num[j]=rand() % 100*2;
	 } 	
	 return num;
 } 
 
 
 