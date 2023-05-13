#include <iostream>

using namespace std;

long potencia(int base, int potencia);
string aBinario (int decimal);
int main (){
	
	int decimal ;
	string binario;	
	cout<<"Indique el numero: ";
	cin >> decimal;
	binario=aBinario(decimal);
	cout<<"\nNumero en binario:"<<binario;
	
}

string aBinario (int decimal){
	int residuo=0;
	string binario="Y";
	int cociente=decimal;
	while (cociente!=0){
		residuo=cociente%2;
		binario=to_string(residuo)+binario;
		cociente=cociente/2;		
	} 
	return binario;
}