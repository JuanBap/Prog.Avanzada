// appending to string
#include <iostream>
#include <string>
using namespace std;
int main ()
{
  
  
  string str;
  
  str="Estoy ";
  string str2="Escribiendo";
  string str3="las historias de mas accion !!";
  
  cout<<"  tam str "<<sizeof(str)<<endl;
  cout<<"  tam str2 "<<sizeof(str2)<<endl;
  cout<<"  tam str3 "<<sizeof(str3)<<endl;

  str.append(str2); 
  //append (const string& str);
  //Concatena la cadena str con str2  
  cout <<"1. "<< str << '\n';              
  
  str.append(str3,3,10); 
  //append (const string& str, size_t subpos, size_t sublen);
  //Obtiene de la cadena str 10 caracteres a partir de la posicion 3         
  cout <<"2. "<< str << '\n';
  
  str.append(" de policias, ladrones y otros mas",12);  
  //append (const char* s, size_t n);
  //Concatena la cadena str con los 12 primeros caracteres de la cadena pasada como parametro
  cout <<"3. "<< str << '\n';
  
  str.append(" y corruptos ");    
  //append (const string& str);       
  //concatena str con la cadena enviada como parametro
  cout <<"4. "<< str << '\n';
  
  str.append(str3.begin()+14,str3.end()-3); 
  //append (InputIterator first, InputIterator last);
  //toma de str desde el inicio + 14 posiciones hasta el final menos  posiciones y lo concatena a str 
  cout <<"5. "<< str << "\n\n";
 
  
  string base="La tortuga gana a la liebre por dormida!!";
  str.assign(base);  
  //assign (const string& str);
  //Reemplaza el contenido de str con el valor de base	
  cout <<"1. " << str << '\n';

  str.assign(base,3,7);
  //assign (const string& str, size_t subpos, size_t sublen);
  //Reemplaza el contenido de str con el substring de base, tomando el 3er caracter y tomando 7 caracteres a la derecha  
  cout <<"2. "  << str << '\n';         


  str.assign("Los crucigramas son faciles",15);
  //assign (const char* s, size_t n);
  //Reemplaza el contenidod de str con los primeros 15 caracteres de la cadena
  cout  <<"3. " << str << '\n';         

  str.assign("c-string");
  //assign (const string& str);
  //Reemplaza el contenido de str con el valor de base	
  cout <<"4." << str << '\n';         

  str.assign(5,'*');
  //string& assign (size_t n, char c);
  //asigna a str el valor de 5 asteriscos
  cout <<"5. "  << str << '\n';         

  
  str.assign(base.begin()+11,base.end()-14);
  //string& assign (size_t n, char c);
  //asigna a str substring entre la posicion 11 y la posicion -14 de base  
  cout <<"6. " << str << '\n';         
	
	
  return 0;
}