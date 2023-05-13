#include<iostream>
#include<cstdlib>
using namespace std;
int binario(int n){
	if(n>0)      
		binario(n/2);
	cout<<n%2;
}
int main(){
	int nro;
	cout<<"Convertir a binario un numero decimal "<<endl;
	cout<<" Ingrese el numero: ";
	cin>>nro;
	cout<<"\nNumero:"<<nro<<endl;
	cout<<"Binario:";
	binario(nro);
	return 0;
}