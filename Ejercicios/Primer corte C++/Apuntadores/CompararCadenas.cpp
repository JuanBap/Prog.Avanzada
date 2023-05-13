#include <iostream>
using namespace std;


int longitud  (char *cad){
	int l=0;
	while (*cad!='\0'){
		l++;
		cad++;
	}
	cout <<"largo:"<<l<<endl;
	return l;
}

bool comparar(char *cad1, char *cad2){
	int i=1;
	bool iguales=true;
	
	if (longitud(cad1)!=longitud(cad2)){
		iguales=false;
	}
	else{
		while (*cad1!='\0'  && *cad2!='\0'  ){
			if (*cad1!=*cad2){
				iguales=false;
			}
			cad1++;
			cad2++;
		}
	}
	return iguales;
}



int main(){
	char cadena1[50];
	char cadena2[50];
	cout <<"Ingrese una cadena de caracteres:";
	cin.getline(cadena1,50);
	cout <<"Ingrese otra cadena cadena de caracteres:";
	cin.getline(cadena2,50);
	
	if (comparar(cadena1,cadena2)  )   {
		cout<<"\n Las cadenas son iguales\n";
	}
	else{
		cout<<"\n Las cadenas son diferentes\n";
	}
	return 0;
}