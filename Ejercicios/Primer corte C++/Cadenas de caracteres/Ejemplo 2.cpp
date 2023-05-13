// string::begin/end
#include <iostream>
#include <string>
using namespace std;
int main ()
{
  string str ("Test string");
  for ( string::iterator it=str.begin(); it!=str.end(); it++)
  {
    cout << *it <<" ";
	if (*it ==' '){
		cout <<" espacio ";
	}
  }

  cout << '\n';

  string str1 ="hola mundo";
  for (string::reverse_iterator rit=str1.rbegin(); rit!=str1.rend(); rit++)
    cout << *rit<<" ";
  cout <<endl;  
  
  cout << "Longitud:" <<str1.size()<<endl;  
  cout << "Longitud:" <<str1.length()<<endl;  
  cout << "Max. Longitud:" <<str1.max_size()<<endl;
  cout << "Capacidad:" <<str1.capacity()<<endl;
  str1.clear();
  cout << "str1:" <<str1<<endl;
  cout << "str1.clear:" <<str1.size()<<endl;
  cout << "Capacidad:" <<str1.capacity()<<endl;
   


  return 0;
}