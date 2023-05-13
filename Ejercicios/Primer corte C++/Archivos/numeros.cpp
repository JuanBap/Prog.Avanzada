#include <iostream>
#include <conio.h>
#include<fstream>
#include <math.h>
using namespace std;

int binarioADecimal(string binario);
string decimalABinario(long decimal);

int arreglo [][3]={ {0,1},{1,0},{2,1} };


int main(){
	
	ofstream archivo ("numeros.txt");
	string binario="1110";
	long decimal=binarioADecimal(binario);
	cout<<"binario:"<<binario<< " decimal:"<<decimal<<endl;
	
	archivo <<binario <<","<<decimal<<endl;
	decimal=1500;
	binario=decimalABinario(decimal);
	archivo <<decimal <<","<<binario<<endl;
	archivo.close();
}

string decimalABinario(long decimal){
	string aux="";
	int cociente=decimal;
	int residuo=0;
	while(cociente>0){
		residuo=cociente%2;
		cociente=cociente/2;
		//cout << cociente<<endl;
		aux=to_string(residuo)+aux;
		//cout << residuo<<" - "<<cociente <<endl;		
	}	
	cout <<"aux:"<<aux<<endl;
	return aux;	
}

int binarioADecimal(string binario){
	long aux=0;
	int j=0;
	for (int i=(binario.length()-1); i>=0; i--){
		if (binario[i]=='1'){
		
		
	   //if (binario.at(i)=='1'){
	   	aux+= pow (2,j);
	   	cout<<aux<<" "<<j<<endl;
	   }
	   j++;
	}
	return aux;
}