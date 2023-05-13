// string::shrink_to_fit
#include <iostream>
#include <string>
using namespace std;
int main ()
{
  string str (50,'x');//Inicializa la variable str con cincuenta X
  //str(numero de caracteres, caracter)
  
  cout <<"str:"<<str<<endl;
  cout << "1. capacidad de str: " << str.capacity() << '\n';

  str.resize(30);
  //resize(nuevo tamaño)
  
  cout <<"str:"<<str<<endl;
  cout << "2. capacidad de str: " << str.capacity() << '\n';

  str.shrink_to_fit();
  cout << "3. capacidad de str: " << str.capacity() << '\n';

  return 0;
}