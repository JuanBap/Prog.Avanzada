#include <iostream>
#include <string>
using namespace std;
int main ()
{
  string base="Este texto es un string!!!";
  string str2=" ejemplo de reemplazo";
  string str3="a es una simple frase de muestra";
  
  string str=base;           
  cout <<"1. "<<str<<endl;
  //replace (size_t pos,  size_t len,  const string& str);
  //Reemplaza en str desde la posicion 16, 8 caracteres con el valor de str2
  str.replace(16,8,str2);
            
  cout <<"2. "<<str<<endl;
  str=base;
  str.replace(3,10,str3,0,21);     
  //replace (size_t pos,  size_t len,  const string& str,size_t subpos, size_t sublen);
  //Reemplaza 10 caracteres desde la 3a posicion de str y lo reemplaza con los primeros 21 caracteres de str3
  cout <<"3. "<<str<<endl;

  return 0;
}