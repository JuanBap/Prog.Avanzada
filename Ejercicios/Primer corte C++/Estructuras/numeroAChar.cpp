 
#include <iostream>
#include <sstream>
using namespace std;
 
int main() {
    int n=2023; 
   
    //Forma 1
    n=n*2;
    int length = to_string(n).length();//Mas detalle cuando veamos strings    
    char arreglo2[length+1];
    sprintf(arreglo2, "%d", n);    
    cout<<"\nNumero convertido en cadena metodo 1: ";
    cout << arreglo2;
   
    
    //Forma 2
    n=2023;
    stringstream temp_str; //Variable temporal
    temp_str<<n; //pasando el numero al flujo de stream 
    char const *arreglo = temp_str.str().c_str();//convierte el string temporal a cadena de caracteres; 
    cout<<"\nNumero convertido en cadena metodo 2: ";
    cout<<arreglo;
    
   
    
    return 0;
}