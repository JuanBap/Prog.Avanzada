#include <iostream>
using namespace std;
void asignar(int valor){
	valor=10;
	cout <<"Dir Mem Variable valor en la funcion:"<<&valor<<endl;
	cout <<"Variable valor en la funcion:"<<valor<<endl;
}

int main(){	
	int  valor=5;	
	cout <<"valor:"<<valor<<endl;
	cout <<"Dir Mem valor en el main :"<<&valor<<endl;
	asignar(valor);
	cout <<"valor:"<<valor<<endl;
	
}