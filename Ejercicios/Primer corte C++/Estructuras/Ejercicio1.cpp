//Ejercicio 1
#include <iostream>
using namespace std;

int suma(int x, int y);

int main(int arg, char *args[]){

   string estudiantes[] = {"pedro","juan","miguel","sara"};
   int limite =(sizeof(estudiantes)/sizeof(estudiantes[0]));
	for (int i = 0; i < limite; i++)
	  {
	  	cout<<estudiantes[i]<<"\n";
	   }
	float x=3.8f;	   
	int res=suma(x,2);   
	cout << "suma "<<res;
}
int suma(int a, int b){
	return a+b;
}

