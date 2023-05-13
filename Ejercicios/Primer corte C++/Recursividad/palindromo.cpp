#include <iostream>
#include <string>
using namespace std;
string quitarEspacios(string cadena){
	string aux="";
	for (int i=0;i<cadena.size();i++){
		if (cadena[i]!=' ')
			aux+=cadena[i];
	}
	return aux;
	
	
}
bool esPalindromo(string cadena,int izq, int der ){
	bool r=false;
	if ( izq<=der  )
		if  (cadena[izq]==cadena[der] )   {
				r=esPalindromo (cadena,izq+1,der-1);
		}
		else{
			r=false;			
		}
	else
		r=true;	
	return r;
	
}
int main(){
	bool r;
	string cadena;
	cout <<" ingrese cadena ";
	getline (cin,cadena);
	cadena=quitarEspacios(cadena);
	r=esPalindromo (cadena,0,cadena.size()-1);
	
if (r){
	cout<<"La frase es un palindromo"<<endl;
}
else{
	cout<<"La frase NO es palindromo"<<endl;
}
	
	
	
	
}