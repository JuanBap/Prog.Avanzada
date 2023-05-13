#include <stdio.h>
#include <iostream>
using namespace std;
int main(){
	int *p;
	int *q;
	int a;
	a=1;
	p=&a;
	cout <<"Variable a:   "<< a<< endl;
	cout <<"Direccion de memoria de a:   "<< &a<< endl;
	cout <<"Variable p:   "<< p<< endl;
	cout <<"*p:   "<< *p<< endl;
	cout << "Asignacion a otra variable apuntador :  q=p"<<endl;
	q=p;
	cout <<"Variable q:  "<< q<< endl;
	cout <<"*q:  "<< *q<< endl;
	cout << "Modificamos valor de a :  a=7"<<endl;
	a=7;
	cout <<"Variable a:   "<< a<< endl;
	cout <<"Variable p:   "<< p<< endl;
	cout <<"*p:  "<< *p<< endl;
	cout <<"*q:  "<< *q<< endl;
	cout << "Modificar valor de a por intermedio del apuntador q :  (*q)++"<<endl;
	(*q)++; 
	cout <<"Variable a:   "<< a<< endl;
	cout <<"*p:  "<< *p<< endl;
	cout <<"*q:  "<< *q<< endl;
	
	int x=5;
	int *prt;
	prt=x;
getchar();
	

	
}
