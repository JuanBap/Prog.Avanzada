#include<iostream>
#include<cstdlib>
#include<string.h>
using namespace std;
int mcd(int n1, int n2){
	int r;
	cout<< n1<<" "<< n2<<endl;
	if(n2==0) 
		r=n1;
	else 
		r=mcd(n2,n1%n2);
	return r;
}
int main( void ){
	int n1,n2,r;
	cout<<"Calcula el MCD de dos numeros "<<endl;
	cout<<"Primer numero:";
	cin>>n1;
	cout<<"Segundo numero:";
	cin>>n2;
	if(n1>n2){
		r=mcd(n1,n2);
		cout<<"MDC( "<<n1<<" , "<<n2<<" ) =  "<<r<<endl;
	}
	else{
		r=mcd(n2,n1);
		cout<<endl<<"MDC( "<<n2<<" , "<<n1<<" ) =  "<< r<<endl;
	}
return 0;
}