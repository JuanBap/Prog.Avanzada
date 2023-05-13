// string::empty
#include <iostream>
#include <string>
using namespace std;
int main ()
{
  string content;
  string line;
  cout << "Por favor introduzca un texto. Enter con linea vacia para terminar:\n";
  do {
    getline(cin,line);
    content += line + '\n';
  } while (!line.empty());
  cout << "El texto escrito es:\n" << content;
  return 0;
}