// string::find
#include <iostream>       // std::cout
#include <string>         // std::string
using namespace std;
int main ()
{
  	string str ="hay una aguja en este pajar de agujas.";
  	string str2 ("aguja");

  
	int  found = str.find(str2);
	//find (const string& str)
	//Encuentra la posicion de str2 en str
	cout << "primera aguja encontrada en pos: " << found << '\n';

  found=str.find("agujas grandes",found+1,6);
  //find (const char* s, size_t pos, size_t n)
  //Encuentra los primeros 6 caracteres de la cadena "agujas grandes" en la cadena str a partir de la posicion 9
  cout << "Found: " << found << '\n';
  
  if (found!=	-1)
    	cout << "segunda 'aguja' encontrada en pos: " << found << '\n';

  found=str.find("pajar");
  //find (const string& str)
  //Encuentra la posicion de "pajar" en str
	
  if (found!=	-1)
    	cout << "'pajar encontrado en pos: " << found << '\n';

  found=str.find("casa");
	//find (const string& str)
   //Encuentra la posicion de casa" en str, como no lo encuentra devuelve -1
  
  if (found==	-1)
    	cout << "No era una casa\n";

  return 0;
}