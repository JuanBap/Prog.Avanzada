// string::substr
#include <iostream>
#include <string>
using namespace std;
int main ()
{
  string str="Pensamos en generalidades, pero vivimos de los detalles.";

  string str2 = str.substr (12,13);    
  //substr (size_t pos = 0, size_t len = npos)
  //Extrae a partir de la posicion 12 13 caracteres
  
  
  cout <<"1. " << str2 << '\n';
  int pos = str.find("vivimos");    


  string str3 = str.substr (pos);   
  //substr (size_t pos = 0)
  //Extrae todo partir de la posicion 'pos'
  cout <<"2. "<<  str3 << '\n';
  
  return 0;
}