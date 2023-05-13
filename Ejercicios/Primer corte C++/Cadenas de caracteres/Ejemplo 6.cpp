// string::front
#include <iostream>
#include <string>
using namespace std;
int main ()
{
	
  string str ="prueba de texto";
  str.front() = 'P';
  cout << str << '\n';
  
  str ="hola mundo.";
  str.back() = '!';
  cout << str << '\n';
  
  
  return 0;
}