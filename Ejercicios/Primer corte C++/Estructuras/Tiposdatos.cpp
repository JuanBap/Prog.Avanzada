#include <iostream>    
#include <iomanip> 
using namespace std;

int main(){
	cout<< "Longitud de tipos de datos"<<endl<<endl;
	
	cout <<"Short int       : "<<setw(10)<<sizeof(short int)<<endl;
	cout <<"Entero          : "<<setw(10)<<sizeof(int)<<endl;
	cout <<"Entero largo    : "<<setw(10)<<sizeof(long int)<<endl;
	cout <<"Entero sin signo: "<<setw(10)<<sizeof(unsigned int)<<endl;
	cout <<"Flotante        : "<<setw(10)<<sizeof(float)<<endl;	
	cout <<"Doble           : "<<setw(10)<<sizeof(double)<<endl;	
	cout <<"Doble largo     : "<<setw(10)<<sizeof(long double)<<endl;	
	cout <<"Char            : "<<setw(10)<<sizeof(char)<<endl;	
	cout <<"String          : "<<setw(10)<<sizeof(string)<<endl;	
    cout <<"Boleano         : "<<setw(10)<<sizeof(bool)<<endl;	
    char cadena [20]="hola";
	cout <<"Variable cadena : "<<setw(10)<<sizeof(cadena)<<endl;
	cout <<"Largo cadena    : "<<setw(10)<<strlen(cadena); /*Una tema es el tamaño de la variable,otra la longitud de la cadena*/

}

