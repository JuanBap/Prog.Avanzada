#include <iostream>

using namespace std;
void Fibonacci(int ult, int penult,int cont,int n){ 
    int aux=0;
    if (n==0){
    	cout <<"0";	
	}	
	else
		if (cont<(n-1)){
			 if (penult==0)
			 	cout << "0 1";				 	
			 cont++;
			 cout <<" "<<ult+penult;
			 aux=ult;
			 ult=ult+penult;
			 penult=aux;
			 Fibonacci(ult, penult,cont,n);	
		}
}
int main(){ 
	int valor; 
	system("clear"); 
	cout << "Introduzca numero a calcular: "; 
	cin >> valor; 
	cout << "\nEl Fibonacci de " << valor << " es: \n"; 
	Fibonacci(1,0,0,valor) ;
	return 0; 
} 
