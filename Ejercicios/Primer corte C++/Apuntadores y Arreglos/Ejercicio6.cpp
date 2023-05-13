 #include <stdio.h>
 #include <iostream>
 
 using namespace std;
 
 int main (){
 	
 	int *notas[3]; /*Esto es un arreglo de apuntadores, quiere decir que lo que hay en cada posicion es una direccion de 
 	memoria no un numero*/
	int *p;
  	int a,b,c;
	a=1;
	b=2;
	c=3;

	notas[0]=&a;
	*(notas+1)=&b;
	*p=c;
	notas[2]=p;
	
	for (int i=0;i<3;i++){
		cout <<"Notas Dir pos["<<i<<"]:"<<notas[i]<<" valor:"<<*notas[i]<<endl;		
	}
	
	cout <<"&a "<<&a<<endl;
	cout <<"&b "<<&b<<endl;
	cout <<"&c "<<&c<<endl;
	cout <<"p "<<p<<endl;
	

	
	//Reasignacion valores
	notas[0]=notas[1];
	b=12;
	cout <<"Reasignacion pos 0 con pos 1\n";
	for (int i=0;i<3;i++){
		cout <<"Notas Dir pos["<<i<<"]:"<<notas[i]<<" valor:"<<*notas[i]<<endl;		
	}
	
 }