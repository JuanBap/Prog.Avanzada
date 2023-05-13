
#include <iostream>
#include <string>
using namespace std;
int main ()
{
  string str ("Esta es una cadena de ejemplo");
  cout <<"0. "<< str << '\n';
                                           
  str.erase (12,7); 
  //erase (size_t pos = 0, size_t len = npos);
  //Borra desde la pos 12, 7 caracteres                        
  cout <<"1. "<< str << '\n';
  
  str ="Esta es una cadena de ejemplo";                                           
  str.erase (str.begin()+11);//Borra el caracter 11
  //erase (iterator p);
  cout <<"2. "<<  str << '\n';

  str ="Esta es una cadena de ejemplo";                                           	

  str.erase (str.begin()+4, str.end()-18); 
  //erase (iterator first, iterator last);
  //borra desde la pos 4 hasta  las pos -18 (contando desde el final)
  cout <<"3. "<< str << '\n';

  return 0;
}