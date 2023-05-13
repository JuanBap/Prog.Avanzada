#include <iostream>
using namespace std;

void farenheitACentrigrados(float f, float *c){
	*c= (f-32)*5/9;	
	cout<<"Valor de c en la funcion :"<< *c<<endl;
}





int main (){
	float fahrenheit;
	float centigrados=0;
	cout <<"Ingrese grados en fahrenheit: ";
	cin >> fahrenheit;	
	farenheitACentrigrados(fahrenheit, &centigrados);	
	cout <<"Resultado : "<<centigrados;
}