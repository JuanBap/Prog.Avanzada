#include <iostream>
#include <string>
using namespace std;
int main ()
{
  string str="esa cuestion!";
  string str2=" es la ";
  string str3="ser o no ser ";
  
  cout<<" str: "<<str<<endl;
  cout<<" str2: "<<str2<<endl;
  cout<<" str3: "<<str3<<endl;	

  str.insert(3,str2); 
  //string& insert (size_t pos, const string& str);
  //a partir de la pos 3 insertar str2               
  cout <<"1. " <<str << '\n';
    
  str.insert(0,str3,0,4); 
  // string& insert (size_t pos, const string& str, size_t subpos, size_t sublen);
  //Desde la posicion 0, tomar de la pos 0 de str3, 4 posiciones            
  cout <<"2. "<< str << '\n';
  
  str.insert(4,str3,4); 
  //insert (size_t pos, const char* s, size_t n);
  //Insertar en la posicion 4, la cadena str3 iniciando desde la pos 4
  cout <<"3. "<< str << '\n';
  
  str.insert(str.begin()+12,','); 
  //insert (iterator p, size_t n, char c);
  //en la pos 12 colocar una coma  
  cout <<"4. "<< str << '\n';
 
  str.insert (str.end(),3,'.'); 
  // insert (iterator p, size_t n, char c);
  //Colocar tres puntos al final      
  cout <<"5. "<< str << '\n';
  
  return 0;
}