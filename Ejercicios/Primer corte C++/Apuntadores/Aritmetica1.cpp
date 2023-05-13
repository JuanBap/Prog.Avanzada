#include <iostream>
using namespace std;
int main(){
	int i=2;
	int *ptri=&i;
	int *ptriAux=NULL;
	cout<< "Tamano de i: "<<sizeof(i)<<endl;
    cout<< "Tamano de *ptri: "<<sizeof(ptri)<<endl;
	cout<<"int i=2;"<<endl;
	cout<<"int *ptri=&i;"<<endl;
	
	cout <<"ptri:"<<ptri<<endl ;
	ptriAux=ptri;
	ptri=ptri+3;
	cout<<"ptri=ptri+3; /*Esto es equivalente a sumar 12 bytes a la direccion de memoria original"<<endl;
	cout << "12 bytes en decimal corresponde al numero C en hexadecimal"<<endl;	
	cout <<"Operacion aritmetica en memoria: "<< ptriAux<<"+C="<<ptri<<endl;
	cout <<"ptri:"<<ptri<<endl ;
	cout << "*ptri:"<<*ptri<<endl;
	*ptri=45;
	cout << "*ptri:"<<*ptri<<endl;
	getchar();
	
}