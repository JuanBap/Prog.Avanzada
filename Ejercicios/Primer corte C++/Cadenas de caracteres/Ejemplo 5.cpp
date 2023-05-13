// string::at
#include <iostream>
#include <string>

using namespace std;
int main ()
{
  string cadena ("Esto es una prueba");
  char c;
  for (unsigned i=0; i<cadena.length(); ++i)
  {
  	
  	c=toupper(cadena.at(i));
  	//toupper funcion que convierte un caracter a mayuscula
    cout << c<< " ";
    c=toupper(cadena[i]);
    cout <<c;
  }
  return 0;
}