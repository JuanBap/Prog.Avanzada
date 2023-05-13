#include <iostream>
#include <fstream>      
using namespace std;
int main () {
  ifstream infile ("test.txt",ios::binary);
  ofstream outfile ("nuevo.txt",ios::binary);
  cout<<"Inicia copia del archivo\n";	
  // Obtiene tamaño del archivo
  infile.seekg (0,infile.end);//cuantas posiciones a moverse desde el fin del archivo
  long size = infile.tellg();
  infile.seekg (0,ios::beg);//cuantas posiciones a moverse desde el principio del archivo es igual que infile.seekg (0)
  infile.seekg (0,infile.beg);//Estas dos lineas hacen lo mismos
  cout<<"El numero de caracteres del archivo es: "<<size<<endl;
  //Los saltos de linea se cuentan por dos (chr 13 y chr 10)

  char* buffer = new char[size];

  // Lee el contenido del archivo
  infile.read (buffer,size);
  cout<< "Que tiene la variable buffer:"<<endl;
  cout<< buffer<<endl;

  // Escribe en el archivo de salida
  outfile.write (buffer,size);
  outfile.close();
  infile.close();
  cout<<"Finaliza copia del archivo\n";	
  
  return 0;
}
