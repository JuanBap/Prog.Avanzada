// comparing apples with apples
#include <iostream>
#include <string>
using namespace std;
int main ()
{
  string str1 ("una manzana verde");
  string str2 ("una manzana roja");

   string s1="hola";
   string s2="hola";

  
  if (str1.compare(str2) != 0)
  	//find (const string& str)
  	//No encuentra comparacion correcta
    cout <<str1 << " no es " << str2 << '\n';

  if (str1.compare(4,7,"manzana") == 0)
    //(size_t pos, size_t n, const char* s)
    //Compara el substring desde la posicion 4 tomando 7 caracteres, con la palabra manzana
    cout << "pero, " << str1 << " es una manzana\n";

  if (str2.compare(str2.size()-12,7,"manzana") == 0)
    //(size_t pos, size_t n, const char* s)
    //Compara el substring desde el ultimo caracter -12 tomando 7 caracteres, con la palabra manzana
    cout << "y " << str2 << " es tambien una manzana\n";

  if (str1.compare(4,7,str2,4,7) == 0)
    //(size_t pos, size_t n, const char* s,size_t pos, size_t n)
  	//Compara el substring de str1 desde la posicion 4 tomando 7 caracteres, 
	//con el substring de str2 desde la posicion 4 tomando 7 caracteres
    cout << "entonces ambas son "<< str1.substr(4,7)<<"s" << endl;

  if (str1.compare(4,7,"pera") != 0)
  		cout << "y definitivamente no son peras!!" << endl;


  return 0;
}