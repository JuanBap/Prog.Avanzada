#include <iostream>
using namespace std;
int main(){
	double datos[3]={20,30,40};	
	double *ptr;
	ptr=datos;
	cout <<"-----------------------------------"<<endl;
	cout << "double datos[3]={20,30,40}" <<endl;
	cout << "double *ptr=datos" <<endl;	
	cout <<"-----------------------------------"<<endl;
	cout <<"Direccion ptr : "<<ptr <<endl;	
	cout <<"Direccion de datos "<< datos <<endl;
	cout <<"datos[0]: "<<datos[0] <<endl;		
	cout <<"Valor *ptr: "<<*ptr <<endl;	
	
	cout <<"-----------------------------------"<<endl;
	cout <<"datos[1]: "<<datos[1] <<endl;
	cout <<"Valor *(++ptr): "<<*(++ptr) <<endl;
	cout <<"Direccion ptr: "<<ptr <<endl;
	cout <<"Direccion datos[1]:: "<<&datos[1]  <<endl;
	cout <<"-----------------------------------"<<endl;
	cout <<"datos[2]: "<<datos[2] <<endl;
	cout <<"Valor *(++ptr): "<<*(++ptr) <<endl;
	cout <<"Direccion ptr: "<<ptr <<endl;
	cout <<"Direccion datos[2]:: "<<&datos[2]  <<endl;
	
	/*int i=4;
	
	cout <<++i<<endl;
	cout <<i<<endl;
	
	cout <<i++<<endl;
	cout <<i+1<<endl;
	*/
	getchar();

	
}