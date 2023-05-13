 #include <iostream>
 #include <math.h>
using namespace std;

int longitud  (char *cad){
	int l=0;
	while (*cad!='\0'){
		l++;
		cad++;
	}
	return l;
}


int traerDigito(char digito){
	int valor;
	
	switch (digito){
		
		case '0': valor=0;break;
		case '1': valor=1;break;
		case '2': valor=2;break;
		case '3': valor=3;break;
		case '4': valor=4;break;
		case '5': valor=5;break;
		case '6': valor=6;break;
		case '7': valor=7;break;
		case '8': valor=8;break;
		case '9': valor=9;break;		
	}
	return valor;
	
}

void convertir(char *cad, int *num){
	int l =longitud(cad);
	int aux;
	*num=0;
	int digito;
	int decimales=1;
	for (int j=1;j<l;j++)
		decimales*=10;
		
	while (*cad!='\0'){
		digito=traerDigito(*cad);
		*num+= digito*decimales;
		aux=*num;
		decimales/=10;
		cad++;						
	}

}

int main(){
	char cNum[10];
	int numero;
	cout <<" Escriba una cadena de caracteres formada de solo numeros:";
	cin.getline(cNum,10);
	convertir(cNum,&numero);
	cout <<"El numero convertido es :"<<numero<<endl;	
	cout <<"El numero convertido al cuadradro es :"<<  pow(numero,2) ;
	
}