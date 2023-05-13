#include <iostream>
#define largo 10
 void llenarArreglo1(int numeros[]);
 void llenarArreglo2(int *num);
 using namespace std;
 int main (){
 	int numeros[largo];
 	llenarArreglo1(numeros); 	 	
 	cout <<"Resultado Llenado tipo 1"<<endl;
 	for (int i=0;i<largo;i++){
 		cout <<" dato [" << i <<"]:"<<numeros[i]<< endl;
	 } 	
 	llenarArreglo2(numeros); 	 	
 	cout << "\nResultado Llenado tipo 2" <<endl;
	cout <<"Direcion del arreglo: "<<numeros<<endl;	 	
 	for (int i=0;i<largo;i++){
 		cout <<" dato [" << i <<"]:"<<numeros[i]<< endl;
	}
	cout <<"Ultima direccion del arreglo: "<<&numeros[10]<<endl;	 	 
	 
 } 
 void llenarArreglo1(int num[]){ 	
 	for (int j=0;j<largo;j++){
 		num[j]=rand() % 100;
	 } 	
 } 
 void llenarArreglo2(int *num){ 	
 	int *temp=num;
 	cout<<"Llenado 2\n";
 	cout <<"\nantes del for: num: "<<num<<" temp:"<<temp<<endl;
 	for (int j=0;j<largo;j++){
 		//num[j]=rand() % 100; //Tambien funciona de esta manera
 		*temp++=rand() % 100;
 		//*num++=rand() % 100; 
 		
	} 
	cout <<"\ndespues del for: num: "<<num<<" temp:"<<temp<<endl;	
	 
 }