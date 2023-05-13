#include <iostream>
using namespace std;
void asignar(int *valor){
	*valor=*valor*2;
	cout <<"Variable valor en la funcion:"<<*valor<<endl;
}

int main(){	
	int  valor=5;	
	cout <<"valor:"<<valor<<endl;
	asignar(&valor);
	cout <<"valor al final:"<<valor<<endl;
	
}