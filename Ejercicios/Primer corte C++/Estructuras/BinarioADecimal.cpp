#include <iostream>

using namespace std;

long potencia(int base, int potencia);
long aDecimal (char binario[50]);
int main (){
	
	long decimal ;
	char binario[50];	
	cout<<"Indique el numero binario: ";
	cin >> binario;
	decimal=aDecimal(binario);
	cout<<"\n Numero en binario:"<<decimal;
	
}

long potencia (int base, int potencia){
	int resultado=base;
	
	if (potencia==0)
		resultado=1;
	else		
		for (int i=2; i<=potencia;i++){
			resultado*=base;
		}
	return resultado;
}



long aDecimal (char binario[50]){
	 int l = strlen(binario);	 
	 int p=0;
	 int resultado=0;
	 int digito=0;
	 long decimal=0;
	 for (int i=l-1; i>=0;i--){
	 	digito= int(binario[i])-48;
	 	resultado=potencia(2,p++);
	 	decimal+= resultado*digito;
	 }
	 return decimal;
	 	
}