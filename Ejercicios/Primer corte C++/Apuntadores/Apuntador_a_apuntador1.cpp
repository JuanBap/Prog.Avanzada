#include <iostream>
using namespace std;
int main(){
	int x=5;
	int *p;
	
	int **q;
	int ***z;
	p=&x;
	q=&p;
	
	**q=x + *p*2 + **q*3;
	
	cout << "Direccion de q:"<<&q<<" Valor de q:"<<q<<" valor de **q:"<<**q<<endl;
	cout << "Direccion de p:"<<&p<<" Valor de p:"<<p<<" valor de *p="<<*p<<endl;
	cout << "Direccion de x:"<<&x<<" valor de x:"<<x<<endl;
	
	}
